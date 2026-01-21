#include <iostream>
#include <iomanip>
#include <cstring>
#include "Node.h"
#include "Student.h"
using namespace std;
//function prototypes
void ADD(Node*& head, Student* newStudent);
void PRINT(Node* current);
Node* DELETE(Node* current, int id);
float AVERAGE(Node* current, int& count);
void CLEAR(Node* current); //memory remember to do that this time

int main() {
    //head, command input, running true statement
    Node* head = nullptr;
    char command[20];
    bool running = true;
    while (running) {
	//different command selection
        cout << "Enter command (ADD, PRINT, DELETE, AVERAGE, QUIT): ";
        cin >> command;
        if (strcmp(command, "ADD") == 0) {
            char first[50], last[50];
            int ID;
            float GPA;

            cout << "First name: ";
            cin >> first;
            cout << "Last name: ";
            cin >> last;
            cout << "Student ID: ";
            cin >> ID;
            cout << "GPA: ";
            cin >> GPA;

            Student* s = new Student(first, last, ID, GPA);
            ADD(head, s);
        }
        else if (strcmp(command, "PRINT") == 0) {
            if (!head) {
                cout << "No students in the list." << endl;
            } else {
                PRINT(head);
            }
        }
        else if (strcmp(command, "DELETE") == 0) {
            int ID;
            cout << "Enter student ID to delete: ";
            cin >> ID;
            head = DELETE(head, ID);
        }
        else if (strcmp(command, "AVERAGE") == 0) {
            int count = 0;
            float total = AVERAGE(head, count);
            if (count == 0) {
                cout << "No students in the list." << endl;
            } else {
                cout << fixed << setprecision(2);
                cout << "Average GPA: " << total / count << endl;
            }
        }
        else if (strcmp(command, "QUIT") == 0) {
            CLEAR(head);
            running = false; //false to stop program
        }
        else {
            cout << "Invalid command." << endl;
        }
    }

    return 0;
}
//ADD function
void ADD(Node* &head, Student* newStudent) {
    if (!head || newStudent->getID() < head->getStudent()->getID()) {
        Node* newNode = new Node(newStudent);
        newNode->setNext(head);
        head = newNode;
        return;
    }

    Node* next = head->getNext();
    ADD(next, newStudent);
    head->setNext(next);
}
//PRINT function
void PRINT(Node* current) {
    if (!current) {
    	return;
    }
    Student* s = current->getStudent();
    cout << s->getFirstName() << " " << s->getLastName()
         << ", " << s->getID() << ", "
         << fixed << setprecision(2) << s->getGPA() << endl;

    PRINT(current->getNext());
}
//DELETE function
Node* DELETE(Node* current, int ID) {
    if (!current) {
    	return nullptr;
    }

    if (current->getStudent()->getID() == ID) {
        Node* nextNode = current->getNext();
        delete current;  
        return nextNode;
    }

    current->setNext(DELETE(current->getNext(), ID));
    return current;
}
//AVERAGE function
float AVERAGE(Node* current, int &count) {
    if (!current) {
    	return 0;
    }
    count++;
    return current->getStudent()->getGPA() + AVERAGE(current->getNext(), count);
}
//CLEAR functionm
void CLEAR(Node* current) {
    if (!current) return;

    CLEAR(current->getNext());
    delete current;
}
