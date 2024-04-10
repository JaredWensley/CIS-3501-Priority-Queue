#pragma once


#include <array>
#include<vector>
#include<math.h>
#include<string>
using namespace std;

struct priorityData {
	string dataValue;
	int priorityValue;


};

class minHeap {
protected:
	void addElement(priorityData value);
	void expandHeap();
	void contractHeap();
	void Init(priorityData a[], int startSize, int arraySize);

	priorityData removeMin();

	public:
		minHeap();				// Constructor
		~minHeap();				// Destructor that deletes the heap
		minHeap(int capacity);	// j


	



};


