#include "Header.h"

// Function that inserts initial elements into heap
void minHeap::Init(string Title, ofstream& output)
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
            // c is the index of the smaller child after this line executes
            if (c < currentSize && heap[c].priorityValue > heap[c + 1].priorityValue) c++;

            // y is compared with the smaller child for minheap
            if (y.priorityValue <= heap[c].priorityValue) break;

            heap[c / 2] = heap[c]; // move child up
            c = c * 2;               // move down a level
            counters[1]++; // Total numer of heap-downs for initialization
        }
        heap[c / 2] = y;
    }



    heapString = toString(Title);
    printHeap(heapString, output);
    output << endl;
    cout << endl;

    if (currentSize == 0) {
        cout << endl << "PRIORITY QUEUE IS EMPTY" << endl;
        output << endl << "PRIORITY QUEUE IS EMPTY" << endl;
    }

}

// Prints the heap in string format
string minHeap::toString(string title)  const
{

    ostringstream oss;
    oss << "["; // Start with opening bracket and newline

    for (int i = 1; i <= currentSize; i++) {
        // Include a semicolon and newline after each element except the last
        oss << "(" << "\"" << heap[i].dataValue << "\", " << heap[i].priorityValue << ")";
        if (i != currentSize) {
            oss << ";\n";
        }
    }

    oss << "]"; // Close with a newline and closing bracket
    return oss.str();

}

//
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
        counters[0]++;  //Total number of inserts increased by 1; 
        currentSize++;

        // Checks if the array is full and double size if so
        expandHeap();
    }

    insertfile.close();		//Close input file stream

    Init(title, outputfile);
}

//
void minHeap::printOperations(ofstream& outputfile) {

    // Index 6 is the number of user actions, add all other user requested counters together
    counters[6] = counters[7] + counters[8];

    // Output operations to user 
    cout << endl << "User Actions interface Complete" << endl << endl;

    cout << left << setw(50) << "Total number of Initialization Inserts " << setw(10) << counters[0] << endl;
    cout << left << setw(50) << "Total number of heap-down Initialization actions " << setw(10) << counters[1] << endl;
    cout << left << setw(50) << "Total number of user requested Inserts " << setw(10) << counters[2] << endl;
    cout << left << setw(50) << "Total number of user requested Removes " << setw(10) << counters[3] << endl;
    cout << left << setw(50) << "Total number of user requested Return top " << setw(10) << counters[4] << endl;
    cout << left << setw(50) << "Total number of user requested Print " << setw(10) << counters[5] << endl;
    cout << left << setw(50) << "Total number of heap actions for user actions " << setw(10) << counters[6] << endl;
    cout << left << setw(50) << "Total number of heap-up actions " << setw(10) << counters[7] << endl;
    cout << left << setw(50) << "Total number of heap-down actions " << setw(10) << counters[8] << endl;


    // outputting to file
    outputfile << endl << "User Actions interface Complete" << endl << endl;

    outputfile << left << setw(50) << "Total number of Inserts ? Initialization " << setw(10) << counters[0] << endl;
    outputfile << left << setw(50) << "Total number of heap-down actions ? Initialization " << setw(10) << counters[1] << endl;
    outputfile << left << setw(50) << "Total number of user requested Inserts" << setw(10) << counters[2] << endl;
    outputfile << left << setw(50) << "Total number of user requested Removes" << setw(10) << counters[3] << endl;
    outputfile << left << setw(50) << "Total number of user requested Return top" << setw(10) << counters[4] << endl;
    outputfile << left << setw(50) << "Total number of user requested Print" << setw(10) << counters[5] << endl;
    outputfile << left << setw(50) << "Total number of heap actions for user actions " << setw(10) << counters[6] << endl;
}

//
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
        cout << "PriorityQueue max size doubled to " << Capacity << endl;
    }
}

//
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
        cout << "PriorityQueue max halfed to " << Capacity << endl;
    
    }
    if (currentSize == 0) {
        cout << "Heap is empty, Can not remove any more elements" << endl;
        return;
    }
}

//
void minHeap::printHeap(string heapString, ofstream& output)
{
    cout << heapString << endl << endl;
    output << heapString << endl << endl;

    
}

//
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
    contractHeap(); // Check if the heap needed to be decreased.
    if (currentSize > 0) {
        heapDown();
    }
    return data;

}

//
void minHeap::heapDown()
{
   

    // temp value that holds root value that is replaced
    priorityData temp = heap[1];

    int c = 2;  // c is the first child of i
    while (c <= currentSize)
    {
        // c is the index of the smaller child after this line executes
        if (c < currentSize && heap[c].priorityValue > heap[c + 1].priorityValue) c++;

        // y is compared with the smaller child for minheap
        if (temp.priorityValue <= heap[c].priorityValue) break;

        heap[c / 2] = heap[c]; // move child up
        c = c * 2;               // move down a level
        counters[8]++; // Total number of heap-down actions
    }
    heap[c / 2] = temp;

}

//
void minHeap::addElement(priorityData element)
{
    expandHeap();
    currentSize++;
    heap[currentSize] = element;


    heapUp();
}

//
void minHeap::heapUp()
{
    

    // Same algorithm as in the intilization EXCEPT divide by 2 instead of i--, 
    // the heap is already "sorted" only need one path up. not the whole heap
    for (int i = currentSize / 2; i >= 1; i = i / 2) {


        priorityData temp = heap[i];
        int c = 2 * i;
        while (c <= currentSize)
        {
            // c is the index of the smaller child after this line executes
            if (c < currentSize && heap[c].priorityValue > heap[c + 1].priorityValue) c++;

            // y is compared with the smaller child for minheap
            if (temp.priorityValue <= heap[c].priorityValue) return;

            heap[c / 2] = heap[c]; // move child up
            c = c * 2;               // move down a level
            counters[7]++; // Total number of heap-down actionws
        }
        heap[c / 2] = temp;
    }
}

//
priorityData minHeap::returnMin()
{
    return heap[1];
}

//
minHeap::minHeap() : Capacity(10), currentSize(0)
{
    // Allocate array to deafult size + 1 (not using index 0)

    heap = new priorityData[Capacity + 1];
}

//
minHeap::minHeap(int heapSize) : Capacity(heapSize), currentSize(0) {

    // Allocate array to custom size + 1 (not using index 0)

    heap = new priorityData[Capacity + 1];
}

//
minHeap::~minHeap()
{
    delete[] heap;
}





