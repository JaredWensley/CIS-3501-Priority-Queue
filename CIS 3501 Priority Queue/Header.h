#pragma once
#include <stdexcept>
#include <numeric>
#include <sstream>
#include <array>
#include<vector>
#include<math.h>
#include<string>
#include<iostream>
#include<fstream>

using namespace std;

struct priorityData 
{
	string dataValue;
	int priorityValue;
};

class minHeap {
public:
	minHeap();				// 
	~minHeap();				// 
	minHeap(int capacity);	// 
	void ProcessInsertFile(string filename, ofstream& output, string title);
	
protected:
	string Title;
	priorityData* heap;
	int Capacity;
	int currentSize;
	int count[9] = { 0 };	// array - Keeps track of operations

	priorityData removeMin();
	priorityData returnMin();
	string toString(string) const;
	void addElement(priorityData value);
	void expandHeap();
	void contractHeap();
	void Init(string title, ofstream& outputfile);
	void printHeap(string );
	void heapDown();
	void heapUp();
};


