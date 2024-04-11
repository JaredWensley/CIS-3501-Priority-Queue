#include "Header.h"

// Function that inserts initial elements into heap
void minHeap::Init(priorityData a[], int startSize, int arraySize)hj
{
    // Initialize the minHeap to array a
    
    delete[] heap;
    heap = a;
	currentSize = startSize; // Current size
    Capacity = arraySize;    // Capacity
    // Start heapify process from the last parent node up to the root node
    for (int i = currentSize / 2; i >= 1; i--)
    {
        priorityData y = heap[i];  // root of subtree to heapify
        int c = 2 * i;  // c is the first child of i
        while (c <= currentSize) // Change this from c < size to c <= size
        {
            // c should be the smaller child, not the larger child
            if (c < currentSize && heap[c] > heap[c + 1]) c++;
            // The item y is no longer compared to larger child but to the smaller child for minHeap
            if (y <= heap[c]) break;
            heap[c / 2] = heap[c]; // move child up
            c *= 2;               // move down a level
        }
        heap[c / 2] = y;
    }
    
   // return *this;/ Ensure the method returns a reference to the current object
}


void minHeap::ProcessInsertFile(string filename, ofstream& outputfile) {



	ifstream insertfile(filename);	//Input file stream
	string line;					// String to hold each line of input
	int lineNumber = 0;				// Track line numbers for error messages

	// Check if the file can open
	if (!insertfile.is_open()) {
		cerr << "Error opening file: " + filename << endl;
		outputfile << "Error opening file: " + filename << endl;
		return; // Stop the operation
	}

	// Check if the file is empty
	if (insertfile.peek() == ifstream::traits_type::eof()) {
		cerr << "Error: The file " + filename + " is empty, please enter a different file" << endl;
		outputfile << "Error: The file " + filename + " is empty, please enter a different file" << endl;
		return; // Stop the operation
	}

	char C = 'C';
	// Read from the file line by line
	while (getline(insertfile, line)) {
		lineNumber++; // Increment line number

		// Use a stringstream to read from the line
		stringstream ss(line);

		// Attempt to read a number from the line
		int num; //temp storage
		if (!(ss >> num)) {
			// If extraction fails, report an error and continue to the next line
			cerr << "Error: Non-integer data found on line " << lineNumber << " in the InsertFile " << filename << ". Skipping line." << endl;
			outputfile << "Error: Non-integer data found on line " << lineNumber << " in the InsertFile " << filename << ". Skipping line." << endl;
			continue;
		}

		// Check if there's anything else on the line after the integer
		string extra;
		if (ss >> extra) {
			// If extra data is found after the integer, report an error and continue to the next line
			cerr << "Error: More than one token found on line " << lineNumber << " in the Insertfile " << filename << ". Skipping line." << endl;
			outputfile << "Error: More than one token found on line " << lineNumber << " in the Insertfile " << filename << ". Skipping line." << endl;
			continue;
		}

		// No errors encountered; insert the number into the binary search tree and print each iteration
		opCount.creations++;
		InsertItem(num);
		outputfile << "Insert: " << num << endl << endl;
		cout << "Insert: " << num << endl << endl;
		PrintTree(outputfile, C);
	}

	insertfile.close();		//Close input file stream
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


minHeap::minHeap() : Capacity(10), currentSize(0)
{
	// Allocate array to deafult size + 1 (not using index 0)
	heap = new priorityData[Capacity + 1]; 
}


minHeap::minHeap(int heapSize) : Capacity(heapSize), currentSize(0){

	// Allocate array to custom size + 1 (not using index 0)
	heap = new priorityData[Capacity + 1];
}


minHeap::~minHeap() 
{
    delete[] heap;
}

