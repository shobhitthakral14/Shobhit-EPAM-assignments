#include <iostream>
using namespace std;


//Encapsulation means hiding the internal details of how an object works and only exposing the necessary functionalities. It ensures that an object's state can only be modified in a controlled way.
//It restricts direct access to an object's data and allows modification only through well-defined methods.
//It protects data from accidental modification.
//It promotes modularity and improves code maintainability.

class Student {
private:
    string name;
    int age;
    float marks;

public:
    // Constructor to initialize values
    Student(string studentName, int studentAge, float studentMarks) {
        name = studentName;
        age = studentAge;
        marks = studentMarks;
    }

    // Getter Methods
    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    float getMarks() {
        return marks;
    }

    // Setter Methods
    void setName(string newName) {
        name = newName;
    }

    void setAge(int newAge) {
        if (newAge > 0) {
            age = newAge;
        } else {
            cout << "Invalid age!" << endl;
        }
    }

    void setMarks(float newMarks) {
        if (newMarks >= 0 && newMarks <= 100) {
            marks = newMarks;
        } else {
            cout << "Invalid marks!" << endl;
        }
    }
};

int main() {

    Student student1("Alice", 20, 85.5);

    cout << "Name: " << student1.getName() << endl;
    cout << "Age: " << student1.getAge() << endl;
    cout << "Marks: " << student1.getMarks() << endl;

    student1.setName("Bob");
    student1.setAge(22);
    student1.setMarks(90.0);

    cout << "\nAfter Modifications:" << endl;
    cout << "Name: " << student1.getName() << endl;
    cout << "Age: " << student1.getAge() << endl;
    cout << "Marks: " << student1.getMarks() << endl;

    return 0;
}
