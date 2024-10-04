#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip> 

using namespace std;

struct Student {
  char fname[100];
  char lname[100];
  int id;
  double gpa;
};

// Add structs to vector of struct pointers
// Pass by reference so we can modify the vector
void add(vector<Student*>& students, char* fname, char* lname, int id, double gpa) {
    Student* student = new Student;
    strcpy(student->fname, fname);
    strcpy(student->lname, lname);
    student->id = id;
    student->gpa = gpa;
    students.push_back(student);
}

void print(vector<Student*>& students) {
    for (Student* student : students) {
      cout << student->fname << " " << student->lname << ", " << student->id << ", " << fixed << setprecision(2) << student->gpa << endl; //set gpa to 2 decimal points
    }
}

void del(vector<Student*>& students, int check_id){
  for (auto it = students.begin(); it != students.end(); it++){
    if((*it)->id == check_id){
      delete *it; //deallocate memory for the pointer
      students.erase(it); //remove from vector
      break;
    }
  }
}



int main() {
    vector<Student*> students;
    char input[7];
    while (strcmp(input, "QUIT") != 0){ // continute until QUIT command
      cout << "Enter, ADD, PRINT, DELETE, or QUIT" << endl;
      cin.get(input, 7);
      cin.get();

      if (strcmp(input, "ADD") == 0){
	char fname[100];
	char lname[100];
	int id;
	double gpa;
	
	cout << "First name: ";
	cin.get(fname, 99);
	cin.get();
	
	cout << "Last name: ";
	cin.get(lname, 99);
	cin.get();
	
	cout << "ID: ";
	cin >> id;
	cin.ignore();
	
	cout << "GPA: ";
	cin >> gpa;
	cin.ignore();
	
	add(students, fname, lname, id, gpa); 
      }
      else if(strcmp(input, "PRINT") == 0){
	print(students);
      }
      else if(strcmp(input, "DELETE") == 0){
	int check_id;
	cout << "ID: ";
	cin >> check_id;
	cin.ignore();
	del(students, check_id);
      }
      
    }

    return 0;
}
