#include "Header.h"

int main() 
{
	int heapSize;
	string heapSizeType;
	string title;
	string insertFileName;
	string actionFileName; 
	string outputFileName;
	minHeap* A;
	string blank;



	cout << "Default heap size is (10) or write in a custom number. Type (d)efault or (c)ustom: ";
	getline(cin, heapSizeType); cout << endl;

	while (heapSizeType != "D" && heapSizeType != "d" && heapSizeType != "C" && heapSizeType != "c") {
		if (heapSizeType == "D" || heapSizeType == "d") {
			A = new minHeap();
		}
		else if (heapSizeType == "C" || heapSizeType == "c") {
			cout << "Enter the size of heap: ";
			cin >> heapSize;
			cout << endl;
			A = new minHeap(heapSize);

			getline(cin, blank);
		}
		else {
			cout << "incorrect character, type D for default or C for custom: " << endl;
		}
	}



	//
	cout << "Enter test title: ";
	getline(cin, title); 	cout << endl;

	//
	cout << "Enter insert file name: ";
	getline(cin, insertFileName); 	cout << endl;
	insertFileName = insertFileName + ".txt";


	//void performActions();
	//cout << "After the initial inserts occur," << endl;
	//cout << "do you wish to perform actions from a (f)ile or (u)ser entered or (b)oth: ";


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

	A->ProcessInsertFile(insertFileName, output, title);

	delete A;

}