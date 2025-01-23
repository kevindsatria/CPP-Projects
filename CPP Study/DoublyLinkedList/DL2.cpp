#include <iostream>
#include <vector>
#include <random>

using namespace std;

template <typename T>
struct Node{
    T data;
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;
};

template <typename T>
class DoubleLinkedList{
    private: 
        int _size;
        Node<T>* head;
        Node<T>* tail;
        
    public:
        DoubleLinkedList();
        ~DoubleLinkedList();
        bool empty();
        int size();
        int push_front(T data);
        int push_back(T data);
        int push_at(int index, T data);
        int pop_front();
        int pop_back();
        int pop_at(int index);
        T front();
        T back();
        T index(int index);
        void print_list();
};

int main(){
    
    DoubleLinkedList<int> test;
   
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(1,100);
    
    for(int i = 0; i < 5; i++)
        test.push_front(distr(gen));
        
    int count = 5;
    for(int i = 0; i < 5; i++)
        test.push_back(count--);
    
    test.print_list();
    
    return 0;
}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(): _size(0), head(nullptr), tail(nullptr){};

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList(){
    while(!empty())
        pop_front();
}

template <typename T>
bool DoubleLinkedList<T>::empty(){ return _size == 0; }

template <typename T>
int DoubleLinkedList<T>::size(){ return _size; }

template <typename T>
int DoubleLinkedList<T>::push_front(T data){
    Node<T>* temp = new Node<T>;
    temp->data = data;
    
    if(empty()){
        head = temp;
        tail = temp;
    } else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    _size++;
    return data;
}

template <typename T>
int DoubleLinkedList<T>::push_back(T data){
    Node<T>* temp = new Node<T>;
    temp->data = data;
    
    if(empty()){
        head = temp;
        tail = temp;
    } else {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
    _size++;
    return data;
}

template <typename T>
int DoubleLinkedList<T>::push_at(int index, T data){
    if(index == 0)
        return push_front(data);
    else if(index == _size)
        return push_back(data);
    else if(index < 0 || index > _size){
        cout << "Index out of bounds!" << endl;
        return -1;
    }
    else {
        Node<T>* temp = new Node<T>;
        temp->data = data;
        
        Node<T>* iterator = head;
        for(int i = 0; i < index; i++)
            iterator = iterator->next;
            
        temp->next = iterator;
        temp->prev = iterator->prev;
        
        iterator->prev->next = temp;
        iterator->prev = temp;
        _size++;
    }
    return data;
}

template <typename T>
int DoubleLinkedList<T>::pop_front(){
    T data = T();
    if(empty()){
        cout << "List is empty" << endl;
        return T();
    } else if(_size == 1){
        Node<T>* temp = head;
        data = temp->data;
        head = nullptr;
        tail = nullptr;
        temp->next = nullptr;
        temp->prev = nullptr;
        
        delete temp;
        _size--;
    } else {
        Node<T>* temp = head;
        data = temp->data;
        head = head->next;
        temp->next = nullptr;
        head->prev = nullptr;
        
        delete temp;
        _size--;
    }
    return data;
}

template <typename T>
int DoubleLinkedList<T>::pop_back(){
    T data = T();
    if(empty()){
        cout << "List is empty" << endl;
        return T();
    } else if(_size == 1){
        Node<T>* temp = head;
        data = temp->data;
        head = nullptr;
        tail = nullptr;
        temp->next = nullptr;
        temp->prev = nullptr;
        
        delete temp;
        _size--;
    } else {
        Node<T>* temp = tail;
        data = temp->data;
        tail = tail->prev;
        temp->prev = nullptr;
        tail->next = nullptr;
        
        delete temp;
        _size--;
    }
    return data;
}

template <typename T>
int DoubleLinkedList<T>::pop_at(int index){
    T data = T();
    if(index == 0)
        return pop_front();
    else if(index == _size-1)
        return pop_back();
    else if(index < 0 || index >= _size){
        cout << "Index input is negative or exceeds list size" << endl;
        return T();
    } else {
        Node<T>* temp = head;
        for(int i = 0; i < index; i++)
            temp = temp->next;
            
        data = temp->data;
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        temp->next = nullptr;
        temp->prev = nullptr;
        
        delete temp;
        _size--;
    }
    return data;
}

template <typename T>
T DoubleLinkedList<T>::front(){
    if(empty()){
        cout << "List is empty" << endl;
        return T();
    } else
        return head->data;
}

template <typename T>
T DoubleLinkedList<T>::back(){
    if(empty()){
        cout << "List is empty" << endl;
        return T();
    } else
        return tail->data;
}

template <typename T>
T DoubleLinkedList<T>::index(int index){
    if(empty()){
        cout << "List is empty" << endl;
        return T();
    } else {
        Node<T>* temp = head;
        for(int i = 0; i < index; i++)
            temp = temp->next;
            
        return temp->data;
    }
}

template <typename T>
void DoubleLinkedList<T>::print_list(){
    if(empty())
        cout << "List is empty" << endl;
    else{
        Node<T>* temp = head;
        for(int i = 0; i < _size; i++){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}

