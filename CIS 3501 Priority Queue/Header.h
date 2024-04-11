#pragma once


#include <array>
#include<vector>
#include<math.h>
#include<string>
#include<iostream>
#include<fstream>
// add include sfor files in and out

using namespace std;

struct priorityData {
	string dataValue;
	int priorityValue;
};

class minHeap {
public:
	minHeap();				// Constructor
	~minHeap();				// Destructor that deletes the heap
	minHeap(int capacity);	// 
	void ProcessInsertFile(string filename);

protected:
	priorityData* heap;
	int Capacity = 0;
	int current_size;
	int count[9] = { 0 };	// array - Keeps track of operations

	priorityData removeMin();
	priorityData returnMin();
	string toString() const;
	void addElement(priorityData value);
	void expandHeap();
	void contractHeap();
	void Init(priorityData a[], int startSize, int arraySize);
	void printOperations();

};


