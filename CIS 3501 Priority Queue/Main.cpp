#include "Header.h"

int main() 
{
	int heapSize;
	string heapSizeType;
	string title;
	string insertFileName;
	string actionFileName; 
	string outputFileName;
	minHeap* A = nullptr;
	string blank;



	cout << "Default heap size is (10) or write in a custom number. Type (d)efault or (c)ustom: ";
	getline(cin, heapSizeType); cout << endl;

	while (heapSizeType != "D" && heapSizeType != "d" && heapSizeType != "C" && heapSizeType != "c") {
		cerr << "Incorrect character, type D for default or C for custom: " << endl;
		getline(cin, heapSizeType); // Get the input again
		cout << endl;
	}

		
	if (heapSizeType == "D" || heapSizeType == "d") {
			A = new minHeap();
	}
	else if(heapSizeType == "C" || heapSizeType == "c") {
			cout << "Enter the size of heap: ";
			cin >> heapSize;
			cout << endl;
			A = new minHeap(heapSize);

			getline(cin, blank);
	}
	
		
	



	//
	if(A != nullptr) {
		cout << "Enter test title: ";
		getline(cin, title); 	cout << endl;

		//
		cout << "Enter insert file name: ";
		getline(cin, insertFileName); 	cout << endl;
		insertFileName = insertFileName + ".txt";

		//
		cout << "Note, file can not be made if the file name contains: / \\ : ? * \" < > |" << endl;
		cout << "Enter outputfile name: ";
		getline(cin, outputFileName); 	cout << endl;
		outputFileName = outputFileName + ".txt";
		ofstream output(outputFileName);

		A->ProcessInsertFile(insertFileName, output, title);

		A->performActions(output, title);


		delete A;
	} 
	return 0;

}