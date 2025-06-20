// A friend function is a function that is not a member of a class but is allowed to access private and protected members of the class.
// A friend function is declared inside the body of the class using friend keyword 
// Use class as parameter when you need to access non-static private members.
// For static members, class object isn't necessary.
// You can pass reference (MyClass&) or pointer (MyClass*) instead of full object for efficiency.
// Passing by reference or pointer improves efficiency mainly due to avoiding object copying.
// We can declare friend class or function anywhere in the base class body whether its private, protected or public block.
// A friend function can be: A global function , A member function of another class
// A class can have multiple friend functions 
// friend is not present in java 
// Friendship is not mutual in programming.
// Friendship is not inherited.
// You can define a friend function inside the class body, and it becomes inline implicitly.

#include<iostream>
class MyClass 
{
private:
    int data;
public:
    MyClass() : data(10) {}
    friend void showData(MyClass obj);  // Declaration      
                                    //Creates a copy of the object.
                                    // For large classes or classes with dynamic memory (e.g., vectors, strings), this can be slow and memory-consuming.
                                    // Also calls the copy constructor (or move constructor), which adds overhead.
};

void showData(MyClass obj) {
    std::cout << obj.data;  // Accessing private data
}



#include<iostream>
class Distance {
   int meter;
public:
   Distance():meter(0){}
   friend int addFive(Distance& d);   // if we addd const in the parameter it will ensure the function doesn’t accidentally modify the object.
};
int addFive(Distance& d) {
   d.meter += 5;
   return d.meter;
}
int main() {
   Distance d;
   std::cout << addFive(d)<<std::endl;
   std::cout << addFive(d) << std::endl;
   return 0;
}

void printData(const MyClass* obj);  // Pass by pointer
// in this use -> instead if . to access the members of the class 



// Always prefer const MyClass& for read-only access to avoid copying and ensure safety.
// Use pointers when you need to handle optional/null objects. 



// ANOTHER GOOD EXAMPLE 

#include<iostream>
class complex {
	int real, img;
public:
	 complex(){}
	 complex(int r,int i):real(r),img(i){}
	 void display() {
		 std::cout << "Complex number is: " << real <<img << "i"<<std::endl;
	 }
	 friend complex sumcomplex(complex& c1, complex& c2);
};
complex sumcomplex(complex& c1, complex& c2) {
	complex ans;
	ans.real = c1.real + c2.real;
	ans.img = c1.img + c2.img;
	return ans;
}
int main() {
	complex c1(2, 3);
	c1.display();
	complex c2(3, 2);
	c2.display();

	complex c3 = sumcomplex(c1, c2);
	c3.display();
	return 0;
}

// Two classes must work closely and require tight coupling friend is used
// Tight coupling in programming means that two or more classes, modules, or components are highly dependent on each other’s internal details. 
// If one changes, the other is likely to break or need updating.