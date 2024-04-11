#include "Header.h"

// Function that inserts initial elements into heap
void minHeap::Init( string Title)
{
    string heapString;

    // Start heapify process from the last parent node up to the root node
    for (int i = currentSize / 2; i >= 1; i--)
    {
        priorityData y = heap[i];  // root of subtree to heapify
        int c = 2 * i;  // c is the first child of i
        while (c <= currentSize) 
        {
            // c is the smaller child
            if (c < currentSize && heap[c].priorityValue > heap[c + 1].priorityValue) c++;

            // y is compared with the smaller child for minheap
            if (y.priorityValue <= heap[c].priorityValue) break;

            heap[c / 2] = heap[c]; // move child up
            c = c * 2;               // move down a level
        }
        heap[c / 2] = y;
    }

    heapString = toString(Title);
    printHeap(heapString);
}

// Prints the heap in string format
string minHeap::toString(string title)  const
{
    string str = "[";

    cout << "Test Name: " << title << endl;

    for (int i = 1; i <= currentSize; i++) {
        str = str + "(" + heap[i].dataValue + " ," + to_string(heap[i].priorityValue) + "); ";
    }

    str = str + "]";
    return str;

}

void minHeap::ProcessInsertFile(string filename, ofstream& outputfile, string title) 
{
    ifstream insertfile(filename);	//Input file stream
    string line;					// String to hold each line of input
    int lineNumber = 0;				// Track line numbers for error messages

    // Assume file is formatted correctly
    int index = 1; // Start at 1 to maintain 1-indexing of heap
    while (getline(insertfile, line)) {
        stringstream ss(line);
        int priority;
        string data;

        // Since we are assuming the file is formatted correctly,
        // a failed read implies an end to the data input.
        if (!(ss >> data >> priority)) {
            break;
        }

        // Insert data into the dataArray
        heap[index++] = { data, priority };
        currentSize++;

        // Checks if the array is full and double size if so
        expandHeap();  
    }

    insertfile.close();		//Close input file stream

    Init(title);
}



void minHeap::addElement(priorityData element) {
    
}


void minHeap::expandHeap() 
{
    if (currentSize == Capacity) {
        priorityData* tempHeap = new priorityData[Capacity * 2 + 1];
        for (int i = 1; i <= currentSize; i++) {
            tempHeap[i] = heap[i];
        }
        Capacity = Capacity * 2;
        delete[] heap;
        heap = tempHeap;
    }
}


void minHeap::contractHeap() 
{
    if (currentSize <= (Capacity / 2)) {
        priorityData* tempHeap = new priorityData[Capacity / 2 + 1];
        for (int i = 1; i <= currentSize; i++) {
            tempHeap[i] = heap[i];
        }
        Capacity = Capacity / 2;
        delete[] heap;
        heap = tempHeap;
    }
    if (currentSize == 0) {
        cout << "Heap is empty, Can not remove any more elements" << endl;
        return;
    }
}


bool minHeap::isFull()
{
    if (currentSize == Capacity) {
        return true;
    }
    else {
        return false;
    }
}


void minHeap::printHeap(string heapString) 
{


    cout << heapString << endl;
    

}


//priorityData minHeap::removeMin() {}


//priorityData minHeap::returnMin() {}


minHeap::minHeap() : Capacity(10), currentSize(0)
{
    // Allocate array to deafult size + 1 (not using index 0)
    //delete[] heap;
    heap = new priorityData[Capacity + 1];
}


minHeap::minHeap(int heapSize) : Capacity(heapSize), currentSize(0) {

    // Allocate array to custom size + 1 (not using index 0)
   // delete[] heap;
    heap = new priorityData[Capacity + 1];
}


minHeap::~minHeap()
{
    delete[] heap;
}




