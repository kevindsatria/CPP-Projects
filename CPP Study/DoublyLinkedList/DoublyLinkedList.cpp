#include <iostream>

using namespace std;

template <typename T>
struct Node{
    T data;
    Node* next;
    Node* prev;
};

template <typename T>
class DoublyLinkedList{
    
    public:
        DoublyLinkedList<T>();
        ~DoublyLinkedList<T>();
        bool isEmpty();
        int getSize();
        void addFront(T data);
        void addBack(T data);
        void addIndex(T data, int index);
        void removeFront();
        void removeBack();
        void removeIndex(int index);
        T getFront();
        T getBack();
        T getIndex(int index);
        void printList();
        
    private: 
        int size;
        Node<T>* header;
        Node<T>* tail;
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(): size(0), header(NULL), tail(NULL){}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    while(!isEmpty()){
        removeFront();
    }
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty(){
    return size == 0;
}

template <typename T>
int DoublyLinkedList<T>::getSize(){
    return size;
}

template <typename T>
void DoublyLinkedList<T>::addFront(T data){
    
    Node<T>* temp = new Node<T>;
    temp->data = data;
    
    if (isEmpty()){
        temp->next = NULL;
        temp->prev = NULL;
        header = temp;
        tail = temp;
    } else if(!isEmpty()){
        temp->next = header;
        temp->prev = NULL;
        header->prev = temp;
        header=temp;
    }
    size++;
}

template <typename T>
void DoublyLinkedList<T>::addBack(T data){
    
    if (isEmpty()){
        addFront(data);
    } else{
        Node<T>* temp = new Node<T>;
        temp->next = NULL;
        temp->data = data;
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
        size++;
    }
}

template <typename T>
void DoublyLinkedList<T>::addIndex(T data, int index){
    Node<T>* temp = new Node<T>;
    temp->data = data;
    
    Node<T>* dummy = header;
    
    for(int i = 0; i < index; i++){
        dummy = dummy->next;
    }
    
    temp->next = dummy;
    temp->prev = dummy->prev;
    
    dummy->prev->next = temp;
    dummy->prev = temp;
    
    size++;
}

template <typename T>
void DoublyLinkedList<T>::removeFront(){
    if (!isEmpty()){
        Node<T>* temp = header;
        header = header->next;
        
        header->prev = NULL;
        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
        temp = NULL;
        size--;
    }
}

template <typename T>
void DoublyLinkedList<T>::removeBack(){
    if (!isEmpty()){
        Node<T>* temp = tail;
        tail = tail->prev;
        
        tail->next = NULL;
        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
        temp = NULL;
        size--;
    }
}

template <typename T>
void DoublyLinkedList<T>::removeIndex(int index){
    Node<T>* temp = header;
    
    for(int i = 0; i < index; i++)
        temp = temp->next;
        
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    
    temp->next = NULL;
    temp->prev = NULL;
    delete temp;
    temp = NULL;
    size--;
}

template <typename T>
T DoublyLinkedList<T>::getFront(){
    return header->data;
}

template <typename T>
T DoublyLinkedList<T>::getBack(){
    return tail->data;
}

template <typename T>
T DoublyLinkedList<T>::getIndex(int index){
    Node<T>* temp = header;
    
    for(int i = 0; i < index; i++)
        temp = temp->next;
    
    return temp->data;
}

template <typename T>
void DoublyLinkedList<T>::printList(){
    Node<T>* temp = header;
    
    for(int i = 0; i < size; i++){
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{
    DoublyLinkedList<int> test;
    test.addFront(1);
    test.addFront(2);
    test.addFront(3);
    test.addBack(100);
    test.addIndex(55,2);
    
    test.printList();
    
    cout << endl;
    test.removeBack();
    test.printList();
    

    return 0;
}