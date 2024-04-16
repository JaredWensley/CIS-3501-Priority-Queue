#include "Header.h"

// Function that inserts initial elements into heap
void minHeap::Init( string Title, ofstream& output)
{
    string heapString;
    priorityData minValue;
    // Start heapify process from the last parent node up to the root node
    for (int i = currentSize / 2; i >= 1; i--)
    {
        priorityData y = heap[i];  // root of subtree to heapify
        int c = 2 * i;  // c is the first child of i
        while (c <= currentSize) 
        {
            // c is the index of the smaller child after this line executes
            if (c < currentSize && heap[c].priorityValue > heap[c + 1].priorityValue) c++;

            // y is compared with the smaller child for minheap
            if (y.priorityValue <= heap[c].priorityValue) break;

            heap[c / 2] = heap[c]; // move child up
            c = c * 2;               // move down a level
            counters[1]++; // Total numer of heap-downs for initialization
        }
        heap[c / 2] = y;
    }

    
    
    heapString = toString(Title);
    printHeap(heapString, output);
    output << endl;
    cout << endl;

    /*
    minValue = removeMin();
    cout << "This Minimun Item was removed--> [(" << minValue.dataValue << "," << minValue.priorityValue << ")]. ";
    cout << "Printing the heap again: " << endl;
    output << "This Minimun Item was removed--> [(" << minValue.dataValue << "," << minValue.priorityValue << ")]. ";
    output << "Printing the heap again: " << endl;
    
    heapString = toString(Title);
    cout << "Test Name: " << Title << endl;
    output << "Test Name: " << Title << endl;
    printHeap(heapString, output); 
    cout << endl << endl;
    output << endl << endl;

   
    // Testing out AddElement function
   
    heapString = toString(Title);
    cout << "Test Name: " << Title << endl;
    output << "Test Name: " << Title << endl;
    printHeap(heapString, output);
    */

}

// Prints the heap in string format
string minHeap::toString(string title)  const
{
    string str = "[";

    for (int i = 1; i <= currentSize; i++) {
        str = str + "(" + heap[i].dataValue + " ," + to_string(heap[i].priorityValue) + "); ";
    }

    str = str + "]";
    return str;

}

//
void minHeap::ProcessInsertFile(string filename, ofstream& outputfile, string title) 
{
    ifstream insertfile(filename);	//Input file stream
    string line;					// String to hold each line of input
    int lineNumber = 0;				// Track line numbers for error messages

    // Assume file is formatted correctly
    int index = 1; // Start at 1 to maintain 1-indexing of heap
    while (getline(insertfile, line)) {
        stringstream ss(line);
        int priority;
        string data;

        // Since we are assuming the file is formatted correctly,
        // a failed read implies an end to the data input.
        if (!(ss >> data >> priority)) {
            break;
        }

        // Insert data into the dataArray
        heap[index++] = { data, priority };
        counters[0]++;  //Total number of inserts increased by 1; 
        currentSize++;

        // Checks if the array is full and double size if so
       expandHeap();  
    }

    insertfile.close();		//Close input file stream

    Init(title, outputfile);
}

//
void minHeap::ProcessActionFile(string actionfilename, ofstream& outputfile, string title) 
{
    priorityData minItem;
    priorityData newElement;
    

    string heapstring;
    bool found;
    ifstream actionfile(actionfilename);
    string line;
    int lineNumber = 0;

    // Checks if the file can open
    if (!actionfile.is_open()) {
        cerr << "Error opening file: " + actionfilename << ": Please check your filename" << endl;
        outputfile << "Error opening file: " + actionfilename << ": Please check your filename" << endl;
        return;
    }

    // Check if the file is empty
    if (actionfile.peek() == ifstream::traits_type::eof()) {
        cerr << "Error: The file " + actionfilename + " is empty, please enter a different file" << endl;
        outputfile << "Error: The file " + actionfilename + " is empty, please enter a different file" << endl;
        return;
    }

    string insertData;
    int insertPriority;
    // Calls functions and handles errors for each line in the action file
    while (getline(actionfile, line)) {
        lineNumber++; // Increment line number

        //Handle Error: Line is empty
        if (line.empty()) continue;


        // Handle Error: if the first character is not a letter
        if (!isalpha(line[0])) {
            cerr << "Error on line " << lineNumber << ": First character is not a letter, skipping line" << endl;
            cerr << "Error on line " << lineNumber << ": First character is not a letter, skipping line" << endl;
            ;
        }

        //Changes each lines first character to lower case letter
        char action = tolower(line[0]);

        stringstream ss(line.substr(1)); // To read from the rest of the line
        int num;
        char extra;

      
        // Handle Error: Extra character found after number,
        if (ss >> extra) {
        
        }

        // Continue to call insert, delte or search functions
        else {

           
            switch (action) {
            case 'i':

              

                if (!(ss >> insertData >> insertPriority)) {
                    cerr << "Error on line " << lineNumber << ": Could not read insert data and priority. Skipping line." << endl;
                    outputfile << "Error on line " << lineNumber << ": Could not read insert data and priority. Skipping line." << endl;
                    continue;
                }

                outputfile << "Insert: (" << insertData << ", " << insertPriority << ")" << endl << endl;
                cout << "Insert: (" << insertData << ", " << insertPriority << ")" << endl << endl;

                newElement = { insertData, insertPriority };
                heap[currentSize + 1] = newElement;

                addElement(heap[currentSize + 1]);

              //  heap[currentSize + 1] = { "funny", 1 };
                cout << "This item was added to the heap--> [(" << heap[currentSize + 1].dataValue << "," << heap[currentSize + 1].priorityValue << ")]. ";
                //addElement(heap[currentSize + 1]);
                cout << "Printing the heap again:" << endl;

               // heapstring = toString(title);
               // printHeap(heapstring, outputfile);

                counters[2]++; // Increase number of requested inserts;


                break;

            case 'r':

                // Call delete function
               
                minItem = removeMin();
              
                outputfile << "Remove: " << minItem.dataValue << ", " << minItem.priorityValue << endl << endl;
                cout << "Remove: " << minItem.dataValue << ", " << minItem.priorityValue << endl << endl;

                counters[3]++; // Number of user requested removes

              // heapstring = toString(title);
               //printHeap(heapstring, outputfile);

                break;

            case 's':   // See top element

              

                minItem = returnMin();
               // counters[4]++; // Number of user requested return top

                outputfile << "Return top Element: " << minItem.dataValue << ", " << minItem.priorityValue << endl << endl;
                cout << "Return top Element: " << minItem.dataValue << ", " << minItem.priorityValue << endl << endl;

                // If the number was not found in the Binary Search Tree
                if (minItem.dataValue == "" && minItem.priorityValue == 0) {
                    outputfile << "Heap is Empty" << endl;
                    cout << "Heap is Empty" << endl;
                }

                break;
            case 'a':

                cout << "Printing heap: " << endl << endl;
                outputfile << "Printing heap: " << endl << endl;

                heapstring = toString(title);
                printHeap(heapstring, outputfile);

                break;


            default:
                cerr << "Error: No functions were called" << endl;
                outputfile << "Error: No functions were called" << endl;
                return;
            }
        }

    }
    cout << "All actions from file complete, printing heap: " << endl;
    outputfile << "All actions from file complete, printing heap: " << endl;
    heapstring = toString(title);
    printHeap(heapstring, outputfile);
}

//
void minHeap::printOperations(ofstream& outputfile) {

    // Index 6 is the number of user actions, add all other user requested counters together
    counters[6] = counters[2] + counters[3] + counters[4] + counters[5]; 
  
    // Output operations to user 
    cout << endl << "User Actions interface Complete" << endl << endl;

    cout << left << setw(50) << "Total number of Initialization Inserts " << setw(10) << counters[0] << endl;
    cout << left << setw(50) << "Total number of heap-down Initialization actions " << setw(10) << counters[1] << endl;
    cout << left << setw(50) << "Total number of user requested Inserts " << setw(10) << counters[2] << endl;
    cout << left << setw(50) << "Total number of user requested Removes " << setw(10) << counters[3] << endl;
    cout << left << setw(50) << "Total number of user requested Return top " << setw(10) << counters[4] << endl;
    cout << left << setw(50) << "Total number of user requested Print " << setw(10) << counters[5] << endl;
    cout << left << setw(50) << "Total number of heap actions for user actions " << setw(10) << counters[6] << endl;
    cout << left << setw(50) << "Total number of heap-up actions " << setw(10) << counters[7] << endl;
    cout << left << setw(50) << "Total number of heap-down actions " << setw(10) << counters[8] << endl;


    // outputting to file
    outputfile << endl << "User Actions interface Complete" << endl << endl;

    outputfile << left << setw(50) << "Total number of Inserts – Initialization " << setw(10) << counters[0] << endl;
    outputfile << left << setw(50) << "Total number of heap-down actions – Initialization " << setw(10) << counters[1] << endl;
    outputfile << left << setw(50) << "Total number of user requested Inserts" << setw(10) << counters[2] << endl;
    outputfile << left << setw(50) << "Total number of user requested Removes" << setw(10) << counters[3] << endl;
    outputfile << left << setw(50) << "Total number of user requested Return top" << setw(10) << counters[4] << endl;
    outputfile << left << setw(50) << "Total number of user requested Print" << setw(10) << counters[5] << endl;
    outputfile << left << setw(50) << "Total number of heap actions for user actions " << setw(10) << counters[6] << endl;
    outputfile << left << setw(50) << "Total number of heap-up actions" << setw(10) << counters[7] << endl;
    outputfile << left << setw(50) << "Total number of heap-down actions" << setw(10) << counters[8] << endl;
}

//
void minHeap::performActions(ofstream& outputfile, string title)
{
    priorityData minItem;
    priorityData newElement;
    priorityData temp;
    string actionFileName;
    char perform;
    char ActionType;
    char Type;

    string heapstring;
    string insertData;
    int insertPriority;
    cout << endl;
    cout << "After the initial inserts occur," << endl;
    cout << "do you wish to perform actions from a (f)ile or (u)ser entered or (b)oth: ";
    cin >> perform;

    //
    if (perform == 'f' || perform == 'b' || perform == 'F' || perform == 'B') 
    {
    cout << "Enter action file name: ";
    cin >> actionFileName; 	cout << endl;
    actionFileName = actionFileName + ".txt";

        ProcessActionFile(actionFileName, outputfile, title);
        cout << "Action File is complete" << endl;
    }

    //
    if (perform == 'u' || perform == 'b' || perform == 'U' || perform == 'B')
    {
        cout << "Enter Action: " << endl;
        cout << "I(nsert)" << endl;
        cout << "R(emove)" << endl;
        cout << "S(ee top element)" << endl;
        cout << "A(ll items in string)" << endl;
        cout << "Type Any other letter  to quit" << endl;

        outputfile << "Enter Action: " << endl;
        outputfile << "I(nsert)" << endl;
        outputfile << "R(emove)" << endl;
        outputfile << "S(ee top element)" << endl;
        outputfile << "A(ll items in string)" << endl;
        outputfile << "Type Any other letter  to quit" << endl;

        cin >> Type;

        while (Type == 'i' || Type == 'r' || Type == 's' || Type == 'a' || Type == 'I' || Type == 'R' || Type == 'S' || Type == 'A') {

            ActionType = tolower(Type);

            switch (ActionType) {
            case 'i':



                cout << "New Element: Enter a string to add: ";
                outputfile << "New Element: Enter a string to add: " << endl;;
                cin >> insertData; cout << endl;

                cout << "New Elemnet: Enter a integer to add: ";
                outputfile << "New Elemnet: Enter a integer to add: " << endl;
                cin >> insertPriority;

                outputfile << "Insert: " << insertData << ", " << insertPriority << endl << endl;
                cout << "Insert: " << insertData << ", " << insertPriority << endl << endl;

                newElement = { insertData, insertPriority };
                addElement(newElement);

                counters[2]++; // Increase number of requested inserts;

                break;

            case 'r':

                if (currentSize > 0) {
                    temp = removeMin();

                    outputfile << "Remove: " << temp.dataValue << ", " << temp.priorityValue << endl << endl;
                    cout << "Remove: " << temp.dataValue << ", " << temp.priorityValue << endl << endl;
                    counters[3]++; // Number of user requested removes

                    break;
                }
                else {
                    cout << "Heap is empty, can not remove an element" << endl;
                }

            case 's':   // See top element



                minItem = returnMin();
                counters[4]++; // Number of user requested return top

                outputfile << "Return top Element: " << minItem.dataValue << ", " << minItem.priorityValue << endl << endl;
                cout << "Return top Element: " << minItem.dataValue << ", " << minItem.priorityValue << endl << endl;

                // If the number was not found in the Binary Search Tree
                if (minItem.dataValue == "" && minItem.priorityValue == 0) {
                    outputfile << "Heap is Empty" << endl;
                    cout << "Heap is Empty" << endl;
                }

                break;

            case 'a':

                cout << "Printing heap: " << endl << endl;
                outputfile << "Printing heap: " << endl << endl;

                if (currentSize == 0) {
                    cout << endl << "HEAP IS EMPTY" << endl;
                }

                heapstring = toString(title);
                printHeap(heapstring, outputfile);
                counters[5]++; // number of user requested print
                break;


            default:
                cerr << "Error: No functions were called" << endl;
                outputfile << "Error: No functions were called" << endl;
                return;
            }
            cout << "Enter Next Action: ";
            cin >> Type; cout << endl;
        }
    }
}

//
void minHeap::expandHeap() 
{
    
    if (currentSize >= Capacity) {
        cout << "expandHeap was called" << endl;
        priorityData* tempHeap = new priorityData[Capacity * 2 + 1];
        for (int i = 1; i <= currentSize; i++) {
            tempHeap[i] = heap[i];
        }
        Capacity = Capacity * 2;
        delete[] heap;
        heap = tempHeap;
    }
}

//
void minHeap::contractHeap() 
{
  
    if (currentSize <= (Capacity / 2)) {
        cout << "ContractHeap was called" << endl;
        priorityData* tempHeap = new priorityData[Capacity / 2 + 1];
        for (int i = 1; i <= currentSize; i++) {
            tempHeap[i] = heap[i];
        }
        Capacity = Capacity / 2;
        delete[] heap;
        heap = tempHeap;
    }
    if (currentSize == 0) {
        cout << "Heap is empty, Can not remove any more elements" << endl;
        return;
    }
}

//
void minHeap::printHeap(string heapString, ofstream& output) 
{
    cout << heapString << endl;
    output << heapString << endl;
}

//
priorityData minHeap::removeMin() 
{
    priorityData data = heap[1];

    // Replace the root with highest index leaf node
    heap[1] = heap[currentSize];

    // Remove the data from the leaf node.
    heap[currentSize].dataValue = "";
    heap[currentSize].priorityValue = 0;

    // Decrease the size of the heap
    currentSize = currentSize - 1;
    contractHeap(); // Check if the heap needed to be decreased.
    if (currentSize > 0) {
        heapDown();
    }
    return data;

}

//
void minHeap::heapDown() 
{
    counters[8]++; // Total number of heap-down actions

    // temp value that holds root value that is replaced
    priorityData temp = heap[1];

    int c = 2;  // c is the first child of i
    while (c <= currentSize)
    {
        // c is the index of the smaller child after this line executes
        if (c < currentSize && heap[c].priorityValue > heap[c + 1].priorityValue) c++;

        // y is compared with the smaller child for minheap
        if (temp.priorityValue <= heap[c].priorityValue) break;

        heap[c / 2] = heap[c]; // move child up
        c = c * 2;               // move down a level
    }
    heap[c / 2] = temp;

}

//
void minHeap::addElement(priorityData element)
{
    expandHeap();
    currentSize++;
    heap[currentSize] = element;
    

    heapUp();
}

//
void minHeap::heapUp() 
{
    counters[7]++; // Total number of heap-down actionws

    // Same algorithm as in the intilization EXCEPT divide by 2 instead of i--, 
    // the heap is already "sorted" only need one path up. not the whole heap
    for (int i = currentSize / 2; i >= 1; i = i /2) {

        
        priorityData temp = heap[i];
        int c = 2 * i;
        while (c <= currentSize)
        {
            // c is the index of the smaller child after this line executes
            if (c < currentSize && heap[c].priorityValue > heap[c + 1].priorityValue) c++;

            // y is compared with the smaller child for minheap
            if (temp.priorityValue <= heap[c].priorityValue) return;

            heap[c / 2] = heap[c]; // move child up
            c = c * 2;               // move down a level
        }
        heap[c / 2] = temp;
    }
}

//
priorityData minHeap::returnMin() 
{
    return heap[1];
}

//
minHeap::minHeap() : Capacity(10), currentSize(0)
{
    // Allocate array to deafult size + 1 (not using index 0)
   
    heap = new priorityData[Capacity + 1];
}

//
minHeap::minHeap(int heapSize) : Capacity(heapSize), currentSize(0) {

    // Allocate array to custom size + 1 (not using index 0)
 
    heap = new priorityData[Capacity + 1];
}

//
minHeap::~minHeap()
{
    delete[] heap;
}




