#include <iostream>
#include <iomanip>
#include <cstdlib>  
#include <windows.h>  
using namespace std;

// Function prototypes
void gotoxy(short, short);
void display();
void add();
void search();
void sortArray();
void del();
void modify();


int arr[5];
int n = 0;

// Main function
int main() {
    char ch1;
    while (true) {
        system("cls");

        cout << setw(25) << "-------------" << endl
            << setw(25) << "| MAIN MENU |" << endl
            << setw(25) << "-------------" << endl << endl
            << setw(52) << "Please choose one of the options below: " << endl
            << setw(71) << "--------------------------------------------------------------" << endl << endl
            << setw(25) << "( A ) Add element" << endl
            << setw(24) << "( O ) Sort array" << endl
            << setw(35) << "( S ) Search for an element" << endl
            << setw(30) << "( D ) Display an array" << endl
            << setw(28) << "( T ) Delete element" << endl
            << setw(28) << "( M ) Modify element" << endl
            << setw(18) << "( Q ) Quit" << endl << endl
            << setw(30) << "Enter Option: [ ]" << endl;

        gotoxy(28, 21);
        cin >> ch1;

        switch (ch1) {
        case 'a':
        case 'A': add(); break;
        case 'd':
        case 'D': display(); break;
        case 's':
        case 'S': search(); break;
        case 't':
        case 'T': del(); break;
        case 'o':
        case 'O': sortArray(); break;
        case 'm':
        case 'M': modify(); break;
        case 'q':
        case 'Q':
            cout << setw(30) << " Program quit" << endl;
            exit(0);
        default:
            cout << "\nEnter only from the selection listed!";
            cin.ignore();
            cin.get();
        }
    }
    return 0;
}

// Display function
void display() {
    system("cls");
    cout << "In DISPLAY function\n";
    cout << setw(10) << "Elements are:" << setw(20) << endl;
    cout << setw(10) << "-------" << setw(20) << endl;



    for (int i = 0; i < n; i++) {
        cout << setw(10) << arr[i] << endl;
    }

    cout << "Press Enter to go back to the main menu...";
    cin.ignore();
    cin.get();
}

// Add function
void add() {
    char ch;
    do {
        system("cls");
        cout << "\nIn ADD function\n";

        if (n >= 5) {
            cout << "Array is already full!\n";
            cin.ignore();
            cin.get();
            return;
        }

        int element;
        cout << "Enter element: ";
        cin >> element;
        arr[n] = element;
        n++;

        cout << "Do you want to add more records? [y/n]: ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

// Search function
void search() {
    system("cls");
    cout << "In SEARCH function\n";

    int element;
    cout << "enter the element which u want to search from your array" << endl;
    cin >> element;
    int index;
    bool flag = false;
    for (int i = 0;i < n;i++) {
        if (element == arr[i]) {
            flag = true;
            index = i;
            break;
        }
    }
    if (flag == true) {
        cout << element << " found at " << index << endl;
    }
    else {
        cout << element << " not found " << endl;
    }
    cout << "Press Enter to go back...";
    cin.ignore();
    cin.get();
}

// Sorting function
void sortArray() {
    system("cls");
    if (n == 0) {
        cout << "Array is empty, nothing to sort!\n";
    }
    else {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        cout << "Array sorted successfully!\n";
    }

    cout << "Press Enter to go back...";
    cin.ignore();
    cin.get();
}

// Delete function
void del() {
    system("cls");
    cout << "In DELETE function\n";

    if (n == 0) {
        cout << "Array is empty, nothing to delete!\n";
        cin.ignore();
        cin.get();
        return;
    }

    int element;
    int index = -1;
    cout << "enter the element which u want to delete from array" << endl;
    cin >> element;
    bool flag = false;
    for (int i = 0;i < n;i++) {
        if (element == arr[i]) {
            flag = true;
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int j = index; j < n - 1; j++) {
            arr[j] = arr[j + 1];
        }

        n--;
        cout << "Element deleted successfully.\n";
    }
    else {
        cout << "Element not found.\n";
    }


    cout << "Press Enter to go back...";
    cin.ignore();
    cin.get();
}

// Modify function
void modify() {
    system("cls");
    cout << "In MODIFY function\n";

    if (n == 0) {
        cout << "Array is empty, nothing to modify!\n";
        cin.ignore();
        cin.get();
        return;
    }

    int num, index = -1, new_value;
    cout << "Enter element at which u want to modify: " << endl;
    cin >> num;

    for (int i = 0; i < n; i++) {
        if (arr[i] == num) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        cout << "Enter new value: ";
        cin >> new_value;
        arr[index] = new_value;
        cout << "Element updated successfully!\n";
    }
    else {
        cout << "Element not found!\n";
    }



    cout << "Press Enter to go back...";
    cin.ignore();
    cin.get();
}

// Gotoxy function for setting cursor position
void gotoxy(short x, short y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
