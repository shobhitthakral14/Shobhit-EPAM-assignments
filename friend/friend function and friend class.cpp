#include<iostream>
using namespace std;

// A friend function or class can access private and protected members of a class, even though they are normally restricted.
// It is sometimes useful to allow a particular class to access private and protected members of other classes. 

// Friendship is not mutual in programming.

// Friendship is not inherited.

// We can declare friend class or function anywhere in the base class body whether its private, protected or public block.

// A friend function can be: A global function , A member function of another class

// A class can have multiple friend functions 

// friend is not present in java 

class Animal
{
    private:
    int age;

    protected:
    int weight;

    public:
    Animal()
    {
        age=25;
        weight=50;
    }
    Animal(int Age , int Weight)
    {
        age=Age;
        weight=Weight;
    }

    // friend function a global function
    friend void find(Animal &ani);

    // friend class
    friend class Dog;

};


void find(Animal &an)
{
    if(an.age>an.weight)
    {
        cout<<"Age is greater "<<endl;
    }
    else if(an.age==an.weight)
    {
        cout<<"Age and Weight are same"<<endl;
    }
    else
    {
        cout<<"Weight is greater "<<endl;
    }
}

class Dog {
    public:
    void display(Animal &t)
    {
        cout<<"Age : "<<t.age<<endl;
        cout<<"Weight : "<<t.weight<<endl; 
    }
};

int main()
{
    Animal A(10,40);
    Dog D;
    // as it is declared inside the friend class
    D.display(A);
    // as it is declared globally 
    find(A);
    return -1;
}