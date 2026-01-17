#include <iostream> 
#include <cstring>
class Student{
  public:
   Student(char* first_input, char* last_input, int ID_input, float GPA_input);
   char* getFirstName();
   void setFirstName(char* firstname_New);
   char* getLastName();
   void setLastName(char* lastname_New);
   int getID();
   void setID(int ID_New);
   float getGPA();
   void setGPA(float GPA_New);
   ~Student();
   void print();
  private: 
   float GPA;
   int ID;
   char* first[100];
   char* last[100];   
};
