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

void addStudent(vector<Student*>& students, char* fname, char* lname, int id, double gpa) {
    Student* student = new Student;
    strcpy(student->fname, fname);
    strcpy(student->lname, lname);
    student->id = id;
    student->gpa = gpa;
    students.push_back(student);
}

void displayStudents(vector<Student*>& students) {
    for (Student* student : students) {
      cout << student->fname << " " << student->lname << ", " << student->id << ", " << setprecision(2) << student->gpa;
    }
}

int main() {
    vector<Student*> students;
    char input[6];
    while (strcmp(input, "QUIT") != 0){
      cin.get(input, 5);
      cin.get();
      if (strcmp(input, "ADD") == 0){
	char fname[10];
	char lname[10];
	int id;
	double gpa;
	cout << "First name: " << endl;
	cin.get(fname, 9);
	cin.get();
	cout << "Last name: " << endl;
	cin.get(lname, 9);
	cin.get();
	cout << "ID" << endl;
	cin >> id;
	cout << "GPA" << endl;
	cin >> gpa;
	addStudent(students, fname, lname, id, gpa); 
      }
      if(strcmp(input, "PRINT") == 0){
	displayStudents(students);
      }
    }

    

    return 0;
}
