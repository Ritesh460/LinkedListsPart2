#include <iostream>
#include <cstring>
#include "Student.h"
Student::Student(char* first_input, char* last_input, int ID_input, float GPA_input) {
  first = first_input;
  strcpy(first, first_input);
  last = last_input;
  strcpy(last, last_input);
  ID = ID_input;
  GPA = GPA_input;
}

char* Student::getFirstName() {
  return first;
}

void Student::setFirstName(char* firstname_New) {
  first = firstname_New
}

char* Student::getLastName() {
  return last;
}

void Student::setLastName(char* lastname_New) {
  last = lastname_New;
}

int Student::getID() {
  return ID;
}

void Student::setID(int ID_New) {
  ID = ID_New;
}

float Student::getGPA() {
  return GPA;
}

void Student::setGPA(float GPA_New) {
  GPA = GPA_New;
}

Student::~Student() {
  delete Student;
}

void Student::print() {
  cout << "Name: " << first << " " << last << ", ID: " << ID << ", GPA: " << GPA << endl;
}
