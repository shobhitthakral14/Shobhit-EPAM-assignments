#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Student {
public:
    string name;
    int age;

    Student(string n, int a) : name(n), age(a) {
        cout << "Student Created: " << name << endl;
    }

    ~Student() {
        cout << "Student Destroyed: " << name << endl;
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    // Step 1: Create a unique_ptr to manage a Student object
    unique_ptr<Student> student1 = make_unique<Student>("Alice", 20);  

    // Step 2: Display student details
    student1->display();  // Use -> instead of .

    // Step 3: Transfer ownership to a new unique_ptr using std::move
    unique_ptr<Student> student2 = move(student1);  

    // Step 4: Try accessing student1 (it should be null now)
    if (!student1) {
        cout << "student1 is empty after transfer!" << endl;
    }

    // Display the student from student2
    student2->display();  

    return 0;  // Memory is automatically freed
}
