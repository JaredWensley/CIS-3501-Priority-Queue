#include "Header.h"


int main() 
{
	int heapSize;
	string heapSizeType;
	string title;
	string insertFileName;
	string actionFileName; 
	string outputFileName;
	minHeap A;

	cout << "Default heap size is (10) or write in a custom number. Type (d)efault or (c)ustom: ";
	getline(cin, heapSizeType); cout << endl;
	if(heapSizeType == "D" || heapSizeType == "d") {
		new minHeap();
	}
	else if (heapSizeType == "C" || heapSizeType == "c") {
		cout << "Enter the size of heap: ";
		cin >> heapSize;
		cout << endl;
		new minHeap(heapSize);
	}

	//
	cout << "Enter test title: ";
	getline(cin, title); 	cout << endl;

	//
	cout << "Enter insert file name: ";
	getline(cin, insertFileName); 	cout << endl;
	insertFileName = insertFileName + ".txt";

	// Dont have action file logic in program yet
	/*cout << "Enter action file name: ";
	getline(cin, actionFileName); 	cout << endl;
	actionFileName = actionFileName + ".txt";*/

	//
	cout << "Note, file can not be made if the file name contains: / \\ : ? * \" < > |" << endl;
	cout << "Enter outputfile name: ";
	getline(cin, outputFileName); 	cout << endl;
	outputFileName = outputFileName + ".txt"; 
	ofstream output(outputFileName);

	A.ProcessInsertFile(insertFileName, output, title);



}