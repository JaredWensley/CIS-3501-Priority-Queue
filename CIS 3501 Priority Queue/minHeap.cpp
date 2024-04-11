#include "Header.h"

// Function that inserts initial elements into heap
void minHeap::Init(priorityData a[], int startSize, int arraySize)
{
    // Initialize the minHeap to array a
    
    delete[] heap;
    heap = a;
    current_size = startSize; // Current size
    Capacity = arraySize;    // Capacity
    // Start heapify process from the last parent node up to the root node
    for (int i = current_size / 2; i >= 1; i--)
    {
        priorityData y = heap[i];  // root of subtree to heapify
        int c = 2 * i;  // c is the first child of i
        while (c <= current_size) // Change this from c < size to c <= size
        {
            // c should be the smaller child, not the larger child
            if (c < current_size && heap[c] > heap[c + 1]) c++;
            // The item y is no longer compared to larger child but to the smaller child for minHeap
            if (y <= heap[c]) break;
            heap[c / 2] = heap[c]; // move child up
            c *= 2;               // move down a level
        }
        heap[c / 2] = y;
    }
    
   // return *this;/ Ensure the method returns a reference to the current object
}


void minHeap::ProcessInsertFile(string filename) {

}


void minHeap::addElement(priorityData element) {

}


void minHeap::expandHeap() {

}


void minHeap::contractHeap() {

}


void minHeap::printOperations() {

}


string minHeap::toString() const {

}


priorityData minHeap::removeMin() {

}


priorityData minHeap::returnMin() {

}


minHeap::minHeap() 
{
    Capacity = 11; 
    //set heap size equal to 11
}


minHeap::minHeap(int Capacity)
{
    // set the array heaps size equal to capacity
}


minHeap::~minHeap() 
{
    delete[] heap;
}

