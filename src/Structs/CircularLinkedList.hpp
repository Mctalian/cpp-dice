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
private:
    Node<T>* head;
};

template <class T>
Node<T>::Node(T d) :
    data(d),
    next(NULL)
{}

template <class T>
CircularLinkedList<T>::CircularLinkedList() :
    head(NULL)
{}

template <class T>
void CircularLinkedList<T>::append(const T& n) {
    Node<T>* newNode = new Node<T>(n);
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

#endif
