//
//  main.cpp
//  Linked List ADT
//
//  Created by Tom Nuss on 2017-11-30.
//  Copyright © 2017 Tomas Gonzalez. All rights reserved.
//

#include "LinkedList.h"
#include <iostream>
using namespace std;

template<typename T>
LinkedList<T>::LinkedList() {
    head = NULL;
    tail = NULL;
}
/**
 Inserts an element into the linked list
 @param index the place in where you wanna set this element
 @newElement the actual element you want to insert
 */
template<typename T>
void LinkedList<T>::insertAt(int index, T newElement) throw (runtime_error) {
    if(tail == nullptr)
        throw runtime_error("Error List is actually full");
        Node<T> *pre = new Node<T>;
        Node<T> *current = new Node<T>;
        Node<T> *temp = new Node<T>;
        current = head;
        for(int i = 1; i < index; i++) {
            pre = current;
            current = current->next;
        }
    temp->data = newElement;
    pre->next = temp;
    temp->next = current;
}

/**
 Deletes an element in a particular position
 @param index the position of the element you intend to remove
 */
template<typename T>
T LinkedList<T>::removeFrom(int index) throw (runtime_error) {
    Node<T> *current = new Node<T>;
    Node<T> *previous = new Node<T>;
    current = head;
    for(int i = 1; i < index; i++) {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
}

/**
 Deletes an element in a particular position
 @param value the position of the element you intend to remove
 */
template<typename T>
void LinkedList<T>::removeAll(T value) throw (runtime_error) {
    Node<T> *current = new Node<T>;
    Node<T> *previous = new Node<T>;
    current = head;
    if(current == nullptr) {
        throw runtime_error("Error: there is nothing to delete");
    }
    else if(value.compareTo(current->data) == 0) {
        if (previous == nullptr) {
            head = current->next; // is the head
        }
        else {
            previous->next = current->next; //is not the head
        }
        current = current->next;
        removeAll(value); // previous doesn't change
    }
    else {
        removeAll(value);
    }
}

/**
 Checks if the List is empty or not
 @return true if the list is empty
 */
template<typename T>
bool const LinkedList<T>::isEmpty() {
    return (head == NULL);
}

/**
 Prints the contents of the list
 */
template<typename T>
void const LinkedList<T>::print() {
    Node<T> *temp = new Node<T>;
    temp = head;
    while(temp != NULL) {
        cout << temp->data << "\t";
        //temp = temp->next;
        print();
    }
}

/**
 Destroys the Linked List
 */
template<typename T>
LinkedList<T>::~LinkedList() {
    while (head) {
        delete head;
        head = head->next;
    }
}

