// queue.cpp
#include "data_structures.h"

// Use the standard namespace
using namespace std;

// Queue constructor to initialize an empty queue
Queue::Queue() : front(nullptr), rear(nullptr) {}

// Enqueue method to add an element to the rear of the queue
void Queue::enqueue(int data) 
{
    Node* newNode = new Node(data); // Create a new node with the given data

    // Link the new node to the current rear if the queue is not empty
    if (rear != nullptr) 
    {
        rear->next = newNode;   // Set the next pointer of current rear to new node
        newNode->prev = rear;   // Set the previous pointer of new node to current rear
    }
    else 
    {
        front = newNode;        // If the queue was empty, set front to the new node
    }

    rear = newNode;             // Update rear pointer to the new node
}

// Dequeue method to remove and return the front element of the queue
int Queue::dequeue() 
{
    if (front == nullptr) 
    {
        throw runtime_error("Queue underflow - cannot dequeue from an empty queue.");
    }

    int data = front->data;     // Retrieve data from the front node
    Node* temp = front;         // Temporarily store the front node
    front = front->next;        // Move front pointer to the next node

    // If the queue is not empty after dequeue, update the previous pointer of new front
    if (front != nullptr) 
    {
        front->prev = nullptr;
    }
    else 
    {
        rear = nullptr;         // If the queue is now empty, set rear to nullptr
    }

    delete temp;                // Deallocate memory of the old front node
    return data;                // Return the dequeued data
}

// Method to display the contents of the queue
void Queue::print() 
{
    Node* current = front;      // Start from the front node

    // Traverse the queue and print each node's data
    while (current != nullptr) 
    {
        cout << current->data << " ";
        current = current->next;    // Move to the next node
    }

    cout << endl;               // Newline after printing all elements
}

// Destructor to clean up memory when the queue is destroyed
Queue::~Queue() 
{
    // Continuously dequeue elements until the queue is empty
    while (front != nullptr) 
    {
        dequeue();
    }
}
