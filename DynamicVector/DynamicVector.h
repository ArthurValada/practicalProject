//
// Created by arthur on 17/10/23.
//

#ifndef PRACTICALPROJECT_DYNAMICVECTOR_H
#define PRACTICALPROJECT_DYNAMICVECTOR_H

#include <cstdlib>
#include <initializer_list>
#include <iterator>
#include <functional>
#include <utility>

/// Classe responsável por fazer o gerenciamento de alocação dinâmica

/// Tipo genérico, usado para que qualquer tipo possa ser utilizado junto à classe.
template<class T>

/// Declaração da classe que encapsula a idea de alocação dinâmica.
class DynamicVector {
    ///Declaração dos atributos privados.
private:
    ///Ponteiro para os dados alocados dinamicamente
    T *_data;

    ///Variável usada para guardar o tamanho ocupado do vetor alocado dinamicamente
    std::size_t _size;

    ///Variável usada para armazenar a capacidade do vetor alocado.
    std::size_t _capacity;


    ///Função usada para dobrar o tamanho, aumentar, do vetor alocado dinamicamente
    ///Um novo vetor com o dobro da capacidade é criado, os dados são copiados e o vetor
    ///_data passa a apontar para o novo vetor alocado dinamicamente.
    void _grow() {
        std::size_t newCapacity;
        if(_capacity!=0){
            newCapacity = _capacity * 2;
        }
        else{
            newCapacity = 2;
        }
        T *newData = new T[newCapacity];

        if(_capacity!=0){
            if(_size!=0){
                for (auto i = 0; i <= _size; i++) {
                    newData[i] = _data[i];
                }
            }
            delete[] _data;
        }

        _data = newData;
        _capacity=newCapacity;
    }


    ///Função responsável por encolher o vetor até o mínimo necessário, isto é, o seu tamanho ocupado.
    void _shrink() {
        _capacity = _size;

        T *newData = new T[_size];

        for (auto i = 0; i < _size; i++) {
            newData[i] = _data[i];
        }

        delete[] _data;

        _data = newData;
    }

    [[maybe_unused]] std::size_t _lomutoPartitioning(std::function<bool(const T& first, const T& second)> function,std::size_t begin, std::size_t end){
        T pivot = this->operator[](end);
        std::size_t j = begin;

        T aux;

        for(auto i = begin;i<end; i++){
            if(function(_data[i],pivot)){
                aux = _data[j];
                _data[j] = _data[i];
                _data[i] = aux;

                j++;
            }
        }

        aux = _data[j];
        _data[j] = _data[end];
        _data[end] = aux;
        return j;
    }

public:

    ///Declaraçãon do struct auxiliar para que a classe DynamicVector seja iterável.
    struct Iterator {

        ///Consstrutor
        explicit Iterator(T *ptr) : m_ptr(ptr) {}

        ///Operador de desreferenciação.
        T &operator*() const { return *m_ptr; }

        ///OPerador de acesso.
        T *operator->() { return m_ptr; }

        ///Operador de incremento.
        Iterator &operator++() {
            m_ptr++;
            return *this;
        }


        ///Operador de incremento com argumento.
        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }


        ///Definição do operador de comparação como um método amigo, a fim de comparar duas instâncias do struct.
        friend bool operator==(const Iterator &a, const Iterator &b) { return a.m_ptr == b.m_ptr; };

        ///Definição do operador de diferenciação como um método amigo, a fim de comparar duas instâncias do struct.
        friend bool operator!=(const Iterator &a, const Iterator &b) { return a.m_ptr != b.m_ptr; };

    ///Declaração das variáveis privadas.
    private:
        ///Declaração do ponteiro de uso interno.
        T *m_ptr;
    };

    ///Declaração do construtor padrão que inicializa as variáveis.
    DynamicVector() : _data(nullptr), _size(0), _capacity(0) {}


    ///Declaração do construtor que recebe como argumento a capacidade do vetor a ser alocado dinamicamente.
    explicit DynamicVector(std::size_t capacity) : _data(new T[capacity]), _size(capacity), _capacity(capacity) {}


    ///Contrutor da classe que recebe um ponteiro como argumento e o tamanho ocupado.
    DynamicVector(T* data, std::size_t size):_data(data), _size(size),_capacity(size){}


    ///Contrutor que recebe uma lista inicializada como argumento, aloca um vetor do tamanho da lista e copia os elementos.
    DynamicVector(const std::initializer_list<T> &data) : _size(data.size()), _capacity(data.size()),_data{} {

        _data = new T[_size];

        int _currentIndex = 0;

        for (const auto &element: data) {
            _data[_currentIndex] = element;
            _currentIndex++;
        }
    }

    ///Método get para obter a capacidade do vetor alocado dinamicamente.
    [[nodiscard]] std::size_t getCapacity() {
        return this->_capacity;
    }


    ///Método get para obter a capacidade do vetor alocado dinamicamente.É um método constante,
    ///não altera o valor da variável. Direta ou indiretamente.
    [[nodiscard]] const std::size_t &getCapacity() const {
        return this->_capacity;
    }

    ///Método get para obter o tamanho do vetor alocado dinamicamente.
    [[nodiscard]] std::size_t getSize() {
        return this->_size;
    }

    ///Método get para obter o tamanho do vetor alocado dinamicamente. É um método constante,
    ///não altera o valor da variável. Direta ou indiretamente.
    [[nodiscard]] const std::size_t &getSize() const {
        return this->_size;
    }


    ///Adiciona um elemento no final do vetor alocado dinamicamente, antes verifica se o vetor
    ///comporta o elemento com a sua atual capacidade.
    void push_back(T value) {
        if (_size + 1 == _capacity or _size == _capacity) {
            _grow();
        }

        _data[_size] = value;
        _size++;
    }

    /// Adiciona um elemento no início do vetor alocado dinamicamente, antes verifica se a
    ///capacidade comporta o elemento.
    void push(T value){
        if(_size>=_capacity){
            _grow();
        }

        for(auto i = _size;i>0;i--){
            _data[i] = _data[i-1];
        }

        _data[0] = value;

        _size++;
    }

    ///Remove um elemento na posição informada.
    void remove_at(std::size_t index){
        for(auto i = index;i<_size-1;i++){
            _data[i]=_data[i+1];
        }
        _size--;
        _shrink();
    }

    ///Getter para o ponteiro alocado dinamicamente. Retorna o ponteiro constante,
    ///de modo que o valor não possa ser alterado externamente,
    T* getData() const {
        return this->_data;
    }

    ///Define o iterator begin da classe a fim de que ela seja iterável.
    Iterator begin() {
        return Iterator(&_data[0]);
    }

    ///Define o iterator begin constante da classe a fim de que ela seja iterável mas não alterável.
    Iterator begin() const {
        return Iterator(&_data[0]);
    }

    ///Define o iterator end da classe a fim de que ela seja iterável.
    Iterator end() {
        return Iterator(&_data[_size]);
    }

    ///Define o iterator end constante da classe a fim de que ela seja iterável mas não alterável.
    Iterator end() const {
        return Iterator(&_data[_size]);
    }

/// COMENTARIOS APÓS A ADIÇÃO DO ARTHUR

    ///Este operador de indexação permite acessar um elemento específico do vetor por meio de seu índice. 
    ///O operador retorna uma referência ao elemento, permitindo a modificação direta do valor do elemento.
    T& operator[](std::size_t index) const {
        return *(this->_data+index*sizeof(T));
    }

    ///Esta função implementa o algoritmo de ordenação QuickSort de forma recursiva. 
    ///Ela utiliza uma função de comparação para determinar a ordem dos elementos e uma função de partição para dividir o vetor em subvetores menores. 
    ///A função chama a si mesma recursivamente para ordenar os subvetores até que todos os elementos estejam ordenados.
    [[maybe_unused]] void sort(const std::function<bool(const T& first, const T& second)>& function, std::size_t pivotPosition, std::size_t end){

        std::size_t newPivotPosition;

        if(pivotPosition<_size){
            newPivotPosition = _lomutoPartitioning(function,pivotPosition,end);
            sort(function,pivotPosition, newPivotPosition-1);
            sort(function,newPivotPosition+1,end);
        }

    }

    ///Esta função permite ao usuário obter o índice de um elemento do vetor dado o seu ponteiro. 
    ///Ela verifica se o ponteiro está dentro dos limites do vetor e, se estiver, calcula e retorna o índice correspondente.
    [[maybe_unused]] std::size_t getPositionWithPointer(const T* pointer) const noexcept {
        if(_data<pointer and pointer<_data+_size* sizeof(T)){
            return pointer-_data;
        }

        return -1;
    }

    ///Esta função é semelhante à função getPositionWithPointer, mas lança uma exceção std::invalid_argument se o ponteiro
    /// não apontar para um elemento válido dentro do vetor.
    [[maybe_unused]] std::size_t getPositionWithPointerException(const T* pointer) const {
        if(_data<pointer and pointer<_data+_size* sizeof(T)){
            return pointer-_data;
        }

        throw std::invalid_argument("The pointer passed as an argument does not point to an element belonging to the vector.");
    }
};

#endif //PRACTICALPROJECT_DYNAMICVECTOR_H