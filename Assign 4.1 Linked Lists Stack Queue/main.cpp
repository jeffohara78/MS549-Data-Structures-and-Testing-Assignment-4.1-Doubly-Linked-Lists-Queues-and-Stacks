// Libraries and header file
#include "data_structures.h"
#include <vector>       // For using the vector container
#include <random>       // For random number generation
#include <chrono>       // For measuring time

using namespace std;

int main() 
{
    Stack stack;            // Create an instance of Stack
    Queue queue;            // Create an instance of Queue

    // Set the vector for the test
    vector<int> sizes = { 100, 1000, 10000 };  // Test data sizes

    // Random number generator setup
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 1000000);

    // Output header for insertion times
    cout << "Insertion Times (microseconds):\nSize\tStack\tQueue\n";

    // Measure insertion times for each data size
    for (int size : sizes) 
    {
        vector<int> data(size);

        // Generate random data
        for (int& num : data) 
        {
            num = distrib(gen);
        }

        // Measure Stack Push Time
        auto start = chrono::high_resolution_clock::now();
        for (int num : data) 
        {
            stack.push(num);
        }
        auto end = chrono::high_resolution_clock::now();
        auto stackPushTime = chrono::duration_cast<chrono::microseconds>(end - start).count();

        // Measure Queue Enqueue Time
        start = chrono::high_resolution_clock::now();
        for (int num : data) 
        {
            queue.enqueue(num);
        }
        end = chrono::high_resolution_clock::now();
        auto queueEnqueueTime = chrono::duration_cast<chrono::microseconds>(end - start).count();

        // Output the times
        cout << size << "\t" << stackPushTime << "\t" << queueEnqueueTime << endl;

        // Clear data structures for next iteration
        stack = Stack();     // Reinitialize the stack
        queue = Queue();     // Reinitialize the queue
    }

    // Output header for deletion times
    cout << "\nDeletion Times (microseconds):\nSize\tStack\tQueue\n";

    // Measure deletion times for each data size
    for (int size : sizes) 
    {
        vector<int> data(size);

        // Generate random data and populate data structures
        for (int& num : data) 
        {
            num = distrib(gen);
            stack.push(num);
            queue.enqueue(num);
        }

        // Measure Stack Pop Time
        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < size; ++i) 
        {
            stack.pop();
        }
        auto end = chrono::high_resolution_clock::now();
        auto stackPopTime = chrono::duration_cast<chrono::microseconds>(end - start).count();

        // Measure Queue Dequeue Time
        start = chrono::high_resolution_clock::now();
        for (int i = 0; i < size; ++i) 
        {
            queue.dequeue();
        }
        end = chrono::high_resolution_clock::now();
        auto queueDequeueTime = chrono::duration_cast<chrono::microseconds>(end - start).count();

        // Output the times
        cout << size << "\t" << stackPopTime << "\t" << queueDequeueTime << endl;
    }

    return 0;
}
