#include "Header.h"


void PriorityQueue::insert(priorityData element) {
	addElement(element);
}

priorityData PriorityQueue::remove() {
	return removeMin();
}

priorityData PriorityQueue::returnTop() {
	return returnMin();
}

string PriorityQueue::toString(string title)  {
	return minHeap::toString(title);
}