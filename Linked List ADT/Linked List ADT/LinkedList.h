//
//  LinkedList.h
//  Linked List ADT
//
//  Created by Tom Nuss on 2017-11-30.
//  Copyright © 2017 Tomas Gonzalez. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h
#include <stdio.h>
#include <stdexcept>
using namespace std;

template<typename T>
struct Node {
    int data;
    Node<T> *next;
};

template<typename T>
class LinkedList {
    
private:
    Node<T> *head, *tail;
    
public:
    LinkedList();
    void insertAt(int index, T newElement) throw (runtime_error);
    T removeFrom(int index) throw (runtime_error);
    void removeAll(T value) throw (runtime_error);
    bool const isEmpty();
    void const print();
    ~LinkedList();
};

#endif /* LinkedList_h */
