#ifndef CIRCULAR_LINKED_LIST_HPP
#define CIRCULAR_LINKED_LIST_HPP

#include <cstddef>

template <class T>
struct Node {
    T data;
    Node* next;
    Node(T d);
};

template <class T>
class CircularLinkedList {
public:
    CircularLinkedList<T>();
    void append(const T& n);
    Node<T>* getHead();
    int getLength();
private:
    Node<T>* head;
    int length;
};

template <class T>
Node<T>::Node(T d) :
    data(d),
    next(NULL)
{}

template <class T>
CircularLinkedList<T>::CircularLinkedList() :
    head(NULL),
    length(0)
{}

template <class T>
void CircularLinkedList<T>::append(const T& n) {
    Node<T>* newNode = new Node<T>(n);
    length++;
    if (head == NULL) {
        head = newNode;
        head->next = newNode;
        return;
    }

    Node<T>* current = head;
    while (current->next != head) {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = head;
}

template <class T>
Node<T>* CircularLinkedList<T>::getHead() {
    return head;
}

template <class T>
int CircularLinkedList<T>::getLength() {
    return length;
}

#endif
