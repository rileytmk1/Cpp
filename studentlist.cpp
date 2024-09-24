#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Student {
    char name[100];
    int age;
    double grade;
};

void addStudent(vector<Student*>& students, char* name, int age, double grade) {
    Student* student = new Student;
    strcpy(student->name, name);  
    student->age = age;
    student->grade = grade;
    students.push_back(student);
}

void displayStudents(vector<Student*>& students) {
    for (Student* student : students) {
        cout << "Name: " << student->name
             << ", Age: " << student->age
             << ", Grade: " << student->grade << endl;
    }
}

int main() {
    vector<Student*> students;

    char name1[] = "Shyam";
    char name2[] = "sehaj";
    
    addStudent(students, name1, 20, 85.5);
    addStudent(students, name2, 21, 90.3);

    displayStudents(students);

    return 0;
}
