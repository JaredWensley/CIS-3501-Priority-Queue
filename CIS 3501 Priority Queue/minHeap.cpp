#include "Header.h"

// Function that inserts initial elements into heap
void minHeap::Init( string Title, ofstream& output)
{
    string heapString;
    priorityData minValue;
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
    printHeap(heapString, output);
    output << endl;
    cout << endl;

    minValue = removeMin();
    cout << "This Minimun Item was removed--> [(" << minValue.dataValue << "," << minValue.priorityValue << ")]. ";
    cout << "Printing the heap again: " << endl;
    output << "This Minimun Item was removed--> [(" << minValue.dataValue << "," << minValue.priorityValue << ")]. ";
    output << "Printing the heap again: " << endl;
    
    heapString = toString(Title);
    cout << "Test Name: " << Title << endl;
    output << "Test Name: " << Title << endl;
    printHeap(heapString, output); 
    cout << endl << endl;
    output << endl << endl;

   
    // Testing out AddElement function
    heap[currentSize + 1] = { "funny", 1 };
    addElement(heap[currentSize + 1]);
    cout << "This item was added to the heap--> [(" << heap[currentSize].dataValue << "," << heap[currentSize].priorityValue << ")]. ";
    cout << "Printing the heap again:" << endl;
    output << "This item was added to the heap--> [(" << heap[currentSize].dataValue << "," << heap[currentSize].priorityValue << ")]. ";
    output << "Printing the heap again:" << endl;
    heapString = toString(Title);
    cout << "Test Name: " << Title << endl;
    output << "Test Name: " << Title << endl;
    printHeap(heapString, output);

}

// Prints the heap in string format
string minHeap::toString(string title)  const
{
    string str = "[";

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

    Init(title, outputfile);
}



void minHeap::expandHeap() 
{
    
    if (currentSize >= Capacity) {
        cout << "expandHeap was called" << endl;
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
        cout << "ContractHeap was called" << endl;
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





void minHeap::printHeap(string heapString, ofstream& output) 
{
    cout << heapString << endl;
    output << heapString << endl;
}


priorityData minHeap::removeMin() 
{
    priorityData data = heap[1];

    // Replace the root with highest index leaf node
    heap[1] = heap[currentSize];

    // Remove the data from the leaf node.
    heap[currentSize].dataValue = "";
    heap[currentSize].priorityValue = 0;

    // Decrease the size of the heap
    currentSize = currentSize - 1;

    heapDown();

    return data;

}

void minHeap::heapDown() 
{
    // increase heapDown counter

    // temp value that holds root value that is replaced
    priorityData temp = heap[1];

    int c = 2;  // c is the first child of i
    while (c <= currentSize)
    {
        // c is the smaller child
        if (c < currentSize && heap[c].priorityValue > heap[c + 1].priorityValue) c++;

        // y is compared with the smaller child for minheap
        if (temp.priorityValue <= heap[c].priorityValue) break;

        heap[c / 2] = heap[c]; // move child up
        c = c * 2;               // move down a level
    }
    heap[c / 2] = temp;

}


void minHeap::addElement(priorityData element)
{
    currentSize++;
    heap[currentSize] = element;

    heapUp();
}

void minHeap::heapUp() 
{
    // Finds the parent of the inserted item

    for (int i = currentSize / 2; i >= 1; i--) {

        
        priorityData temp = heap[i];
        int c = 2 * i;
        while (c <= currentSize)
        {
            // c is the smaller child
            if (c < currentSize && heap[c].priorityValue > heap[c + 1].priorityValue) c++;

            // y is compared with the smaller child for minheap
            if (temp.priorityValue <= heap[c].priorityValue) break;

            heap[c / 2] = heap[c]; // move child up
            c = c * 2;               // move down a level
        }
        heap[c / 2] = temp;
    }
}


priorityData minHeap::returnMin() 
{
    return heap[1];
}


minHeap::minHeap() : Capacity(10), currentSize(0)
{
    // Allocate array to deafult size + 1 (not using index 0)
   
    heap = new priorityData[Capacity + 1];
}


minHeap::minHeap(int heapSize) : Capacity(heapSize), currentSize(0) {

    // Allocate array to custom size + 1 (not using index 0)
 
    heap = new priorityData[Capacity + 1];
}


minHeap::~minHeap()
{
    delete[] heap;
}




