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
	void printOperations(ofstream& outputfile);
	

protected:
	string Title;
	priorityData* heap;
	int Capacity;
	int currentSize;

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

	// OPERATIONS TRACKER
	int counters[9] = { 0 };	
	// Index 0 -- Total Number of Inserts (initialization)				
	// Index 1 -- Total Number of heap-down actions - Initialization	
	// Index 2 -- Number of user requested Inserts						
	// Index 3 -- Number of user requested removes						
	// Index 4 -- Number of user requested return top					
	// Index 5 -- Number of user requested print						
	// Index 6 -- Number of heap actions for user actions				
	// Index 7 -- Total number of heap-up actions								
	// Index 8 -- Total number of heap-down actions						
};

class PriorityQueue : public minHeap {
public:
	PriorityQueue() : minHeap() {}  // Initialize with default size
	PriorityQueue(int capacity) : minHeap(capacity) {}  // Initialize with specified capacity
	void insert(priorityData element);
	void ProcessActionFile(string filename, ofstream& output, string title);
	void performActions(ofstream& outputfile, string title);

	priorityData removeHighestPriority();
	priorityData returnHighestPriority();
	string PQtoString(string title);
};

