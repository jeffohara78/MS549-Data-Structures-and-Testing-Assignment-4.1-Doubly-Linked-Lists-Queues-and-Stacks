#pragma once

// data_structures.h
#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <iostream>

using namespace std;

// Definition of the Node structure for the doubly-linked list
struct Node 
{
    int data;       // The data stored in the node
    Node* prev;     // Pointer to the previous node
    Node* next;     // Pointer to the next node

    // Constructor to initialize a node with a given value
    inline Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

// Class definition for the Stack data structure implemented using a doubly-linked list
class Stack 
{
private:
    Node* top;      // Pointer to the top node of the stack

public:
    Stack();                // Constructor to initialize the stack
    void push(int data);    // Push method to add an element to the top
    int pop();              // Pop method to remove and return the top element
    void print();           // Method to display the stack contents
    ~Stack();               // Destructor to clean up memory
};

// Class definition for the Queue data structure implemented using a doubly-linked list
class Queue 
{
private:
    Node* front;    // Pointer to the front node of the queue
    Node* rear;     // Pointer to the rear node of the queue

public:
    Queue();                    // Constructor to initialize the queue
    void enqueue(int data);     // Enqueue method to add an element to the rear
    int dequeue();              // Dequeue method to remove and return the front element
    void print();               // Method to display the queue contents
    ~Queue();                   // Destructor to clean up memory
};

#endif 

