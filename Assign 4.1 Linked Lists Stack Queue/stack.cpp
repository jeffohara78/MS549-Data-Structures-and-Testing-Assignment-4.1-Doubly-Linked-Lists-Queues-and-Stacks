// stack.cpp
#include "data_structures.h"

using namespace std;

// Stack constructor to initialize an empty stack
Stack::Stack() : top(nullptr) {}

// Push method to add an element to the top of the stack
void Stack::push(int data) 
{
    Node* newNode = new Node(data); // Create a new node with the given data

    // Link the new node to the current top if the stack is not empty
    if (top != nullptr) 
    {
        newNode->prev = top;    // Set the previous pointer of new node to current top
        top->next = newNode;     // Set the next pointer of current top to new node
    }

    top = newNode;              // Update top pointer to the new node
}

// Pop method to remove and return the top element of the stack
int Stack::pop() 
{
    if (top == nullptr) 
    {
        throw runtime_error("Stack underflow - cannot pop from an empty stack.");
    }

    int data = top->data;       // Retrieve data from the top node
    Node* temp = top;           // Temporarily store the top node
    top = top->prev;            // Move top pointer to the previous node

    // If the stack is not empty after pop, update the next pointer of new top
    if (top != nullptr) 
    {
        top->next = nullptr;
    }

    delete temp;                // Deallocate memory of the old top node
    return data;                // Return the popped data
}

// Method to display the contents of the stack
void Stack::print() 
{
    Node* current = top;        // Start from the top node

    // Traverse the stack and print each node's data
    while (current != nullptr) 
    {
        cout << current->data << " ";
        current = current->prev;    // Move to the previous node
    }

    cout << endl;               // Newline after printing all elements
}

// Destructor to clean up memory when the stack is destroyed
Stack::~Stack() 
{
    // Continuously pop elements until the stack is empty
    while (top != nullptr) 
    {
        pop();
    }
}
