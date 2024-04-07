#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int NUM_LINES = 4;
const int NUM_COLUMNS = 3;
const int COLUMN_WIDTH = 20;

void PrintTableHeader() {
    for (int column = 0; column < NUM_COLUMNS - 1; ++column) {
        for (int k = 0; k < COLUMN_WIDTH; ++k)
            cout << '-';
        cout << "-+-";
    }

    // print last line
    for (int k = 0; k < COLUMN_WIDTH; ++k)
        cout << '-';

    cout << endl;
}

void PrintTableHeader1() {
    for (int column = 0; column < NUM_COLUMNS - 1; ++column) {
        // prints out COLUMN_WIDTH dashes in a row, then
        // uses setfill(' ') to undo the changes we made to cout
        cout << setfill('-') << setw(COLUMN_WIDTH) << "" << "-+-";
    }
    cout << setw(COLUMN_WIDTH) << "" << setfill(' ') << endl;
}

void PrintTableBody() {
    ifstream input("StreamsII/table-data.txt");
    if (!input.is_open())
        cerr << "Couldn't open the file" << endl;
    
    for (int k = 0; k < NUM_LINES; ++k) {
        int int_value;
        double double_value;
        input >> int_value >> double_value;

        cout << setw(COLUMN_WIDTH) << (k + 1) << " | ";
        cout << setw(COLUMN_WIDTH) << int_value << " | ";
        cout << setw(COLUMN_WIDTH) << double_value << endl;
    }
}

// read all content
void PrintTableBody1() {
    ifstream input("StreamsII/table-data.txt");

    int row_number = 0;
    while (true) { //don't use while (!input.fail())
        int int_value;
        double double_value;
        input >> int_value >> double_value;

        if (input.fail()) break;

        cout << setw(COLUMN_WIDTH) << (row_number + 1) << " | ";
        cout << setw(COLUMN_WIDTH) << int_value << " | ";
        cout << setw(COLUMN_WIDTH) << double_value << endl;

        row_number++;
    }
}

int main() {
    PrintTableHeader();
    PrintTableBody();
    PrintTableHeader1();
    PrintTableBody1();
    return 0;
}
