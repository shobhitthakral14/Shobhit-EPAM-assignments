//A friend class can access private and protected members of other classes in which it is declared as a friend.
//It is sometimes useful to allow a particular class to access private and protected members of other classes.
//Remember one thing, Friendship is not mutual.If class A is a friend of B, then B doesn’t become a friend of A automatically.
//We can declare a friend class in C++ by using the friend keyword.
//This breaks encapsulation intentionally to allow tightly coupled classes to interact.


#include<iostream>
class demo {
private:
	int private_variable;
protected:
	int protected_variable;
public:
	demo() {
		private_variable = 10;
		protected_variable = 99;
	}
	friend class test;
};

class test {
public:
	void display(demo& d) {
		std::cout << "The value of Private Variable = "
			<< d.private_variable << std::endl;
		std::cout << "The value of Protected Variable = "
			<< d.protected_variable;
	}
};

int main() {
	demo d;
	test t;
	t.display(d);
	return 0;
}


// we can make only the specific function of other class as friend 
// class A {
//     friend void B::specificFunc();
// };



// difference between inheritance and friend 

// Friendship grants access without changing the class hierarchy. 
// Inheritance is an "is-a" relationship and allows reuse of implementation.






#include <iostream>

class complex {
private:
   int real, img;
public:
   complex() {}
   complex(int r, int i) : real(r), img(i) {}

   void display() {
       std::cout << "Complex number is: " << real << " +i" << img << std::endl;
   }

   // Grant access to ComplexHelper class
   friend class ComplexHelper;
};

// Helper class to operate on complex numbers
class ComplexHelper {
public:
//  if we not make the function static then we have to declare the complexhelper object also to perform the operation 
//  A non-static method must be called using an object.
   static complex sumComplex(complex& c1, complex& c2) {
       complex result;
       result.real = c1.real + c2.real;
       result.img = c1.img + c2.img;
       return result;
   }
};

int main() {
   complex c1(2, 3);
   c1.display();

   complex c2(3, 2);
   c2.display();

   complex c3 = ComplexHelper::sumComplex(c1, c2);
   c3.display();

   return 0;
}
