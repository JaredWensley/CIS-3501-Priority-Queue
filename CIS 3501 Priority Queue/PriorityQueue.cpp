#include "Header.h"


//
void PriorityQueue::insert(priorityData element) {
	addElement(element);
}

//
priorityData PriorityQueue::removeHighestPriority() {
	return removeMin();
}

//
priorityData PriorityQueue::returnHighestPriority() {
	return returnMin();
}

//
string PriorityQueue::PQtoString(string title)  {
	return toString(title);
}

//
void PriorityQueue::performActions(ofstream& outputfile, string title)
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

                insert(newElement); // Calls the priorityQueue insert function


                counters[2]++; // Increase number of requested inserts;

                break;

            case 'r':

                if (currentSize != 0) {
                    temp = removeHighestPriority();

                    outputfile << "Remove: " << temp.dataValue << ", " << temp.priorityValue << endl << endl;
                    cout << "Remove: " << temp.dataValue << ", " << temp.priorityValue << endl << endl;
                    counters[3]++; // Number of user requested removes

                    break;
                }
                else {
                    cout << "PriorityQueue is empty, can not remove an element" << endl;
                }

            case 's':   // See top element

                minItem = returnHighestPriority();
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

                heapstring = PQtoString(title);
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
void PriorityQueue::ProcessActionFile(string actionfilename, ofstream& outputfile, string title)
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

                addElement(newElement);




                break;

            case 'r':


                if (currentSize != 0) {
                    minItem = removeMin();

                    outputfile << "Remove: " << minItem.dataValue << ", " << minItem.priorityValue << endl << endl;
                    cout << "Remove: " << minItem.dataValue << ", " << minItem.priorityValue << endl << endl;

                    break;
                }
                else {
                    cout << "PriorityQueue is empty, can not remove an element" << endl;
                }



                break;

            case 's':   // See top element

                minItem = returnMin();

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

                if (currentSize == 0) {
                    cout << endl << "HEAP IS EMPTY" << endl;
                    outputfile << endl << "HEAP IS EMPTY" << endl;
                }
                printHeap(heapstring, outputfile);
                cout << endl;
                outputfile << endl;
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