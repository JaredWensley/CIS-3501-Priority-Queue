#pragma once
#include <stdexcept>
#include <numeric>
#include <sstream>
#include <array>
#include<vector>
#include<math.h>
#include<string>
#include<iostream>
#include <iomanip>
#include<fstream>

using namespace std;

struct priorityData 
{
	string dataValue = "";
	int priorityValue = 0;
};

class minHeap {
public:
	minHeap();				
	~minHeap();				 
	minHeap(int capacity);	 
	void ProcessInsertFile(string filename, ofstream& output, string title);
	void ProcessActionFile(string filename, ofstream& output, string title);
	void performActions(ofstream& outputfile, string title);
	void printOperations(ofstream& outputfile);

protected:
	string Title;
	priorityData* heap;
	int Capacity;
	int currentSize;
	int counters[9] = { 0 };	// array - Keeps track of operations

	// Index 0 -- Total Number of Inserts (initialization)				GOOD
	// Index 1 -- Total Number of heap-down actions - Initialization	GOOD
	// Index 2 -- Number of user requested Inserts						GOOD
	// Index 3 -- Number of user requested removes						GOOD
	// Index 4 -- Number of user requested return top					GOOD
	// Index 5 -- Number of user requested print						GOOD
	// Index 6 -- Number of heap actions for user actions				GOOD
	// Index 7 -- Total number of heap-up actions						GOOD		
	// Index 8 -- Total number of heap-down actions						GOOD

	priorityData removeMin();
	priorityData returnMin();
	string toString(string) const;
	void addElement(priorityData value);
	void expandHeap();
	void contractHeap();
	void Init(string title, ofstream& outputfile);
	void printHeap(string heapstring, ofstream& output);
	void heapDown();
	void heapUp();
};


