// ✅Tuple is a fixed - size collection of heterogeneous values, similar to a container that can store elements of different types.
// They are particularly useful for grouping heterogeneous data into a single object.

// present in <tuple> header file 


// Syntax:
// std::tuple<data_type1, data_type2, ...> tuple_name;

// ✅Common Member Functions of std::tuple
// 1. Creation of a Tuple
// Tuples can be created using std::make_tuple or the tuple constructor.

// std::tuple<int, char, double> myTuple(1, 'a', 3.14); // direct initialization ,it invokes the tuple's constructor with the arguments provided. 
// std::tuple<int, char, double> myTuple = { 1, 'a', 3.14 }; // list initialization

// std::tuple<int, char, double> myTuple = { 1, 'a', 3.14 };
// auto myTuple2 = std::make_tuple(1, 'b', 2.71);       // Using make_tuple


// ✅2.Accessing tuple elements
// Tuple elements can be accessed using std::get<index>(tuple) :

// std::cout << std::get<0>(myTuple); // Access the first element
// std::cout << std::get<1>(myTuple); // Access the second element
// std::cout << std::get<2>(myTuple); // Access the third element


// ✅3.Modifying tuple elements
// You can modify the value of elements using std::get<index>(tuple) :

// std::get<0>(myTuple) = 42;         // Modify the value of the first element
// std::get<1>(myTuple) = 'z';        // Modify the value of the second element


// ✅4.Tuple Size
// To get the number of elements in a tuple :
// Use std::tuple_size, which is a compile - time constant.

// std::cout << std::tuple_size<decltype(myTuple)>::value; // Output: 3
// //you would get a compilation error, because myTuple is a variable or object, not a type. std::tuple_size expects a type, not an object. 


// ✅5.Tuple Element Type
// To determine the type of elements in a tuple, use std::tuple_element at compile time :

// // Get the type of the first element (index 0)
// using FirstElementType = std::tuple_element<0, decltype(myTuple)>::type;
// // Using typedef to extract the type of the first element of the tuple
// typedef std::tuple_element<0, decltype(myTuple)>::type FirstElementType;

// // Create a variable of type `FirstElementType` (which is `int`)
// FirstElementType x = 42;
// cout << x; // x=42
// std::cout << "Type of first element: " << typeid(FirstElementType).name() << '\n';// int

// /* explore 'typedef' and 'using' ??
// The using keyword is used to create a type alias (FirstElementType) similar to typedef.
// typedef std::vector<int> IntVector1; //  Traditional typedef
// using IntVector2 = std::vector<int>; //  Modern equivalent using `using`

// int main() {
//     // Declare variables using the aliases
//     IntVector1 vec1 = {1, 2, 3, 4};
//     IntVector2 vec2 = {5, 6, 7, 8};

//     for (int num : vec1) std::cout << num << " "; // Outputs: 1 2 3 4
//     std::cout << std::endl;
//     for (int num : vec2) std::cout << num << " "; // Outputs: 5 6 7 8

//     return 0;
// }
//     */

// ✅6.Comparison Operations
// Tuples are compared element - by - element in order(left - to - right).
// The first pair of elements that differ determines the result of the comparison.
// If all elements are equal, the tuples are considered equal.

// std::tuple<int, double, char> tuple1(42, 3.14, 'a');
// std::tuple<int, double, char> tuple2(42, 2.71, 'b');
// std::tuple<int, double, char> tuple3(42, 3.14, 'a');

// //bool flag1 = true;
// //bool flag2 = false;
// //cout << flag1 << "," << flag2; // 1,2
// //
// //std::cout << std::boolalpha; //will print textual representation i.e  true/false
// //cout << flag1 << "," << flag2; // true,false

// // Compare the tuples
// std::cout << "tuple1 == tuple2: " << (tuple1 == tuple2) << '\n'; // False
// std::cout << "tuple1 != tuple2: " << (tuple1 != tuple2) << '\n'; // True
// std::cout << "tuple1 < tuple2: " << (tuple1 < tuple2) << '\n'; // False
// std::cout << "tuple1 <= tuple2: " << (tuple1 <= tuple2) << '\n'; // False
// std::cout << "tuple1 > tuple2: " << (tuple1 > tuple2) << '\n'; // True
// std::cout << "tuple1 >= tuple2: " << (tuple1 >= tuple2) << '\n'; // True

// std::cout << "tuple1 == tuple3: " << (tuple1 == tuple3) << '\n'; // True
// std::cout << "tuple1 != tuple3: " << (tuple1 != tuple3) << '\n'; // False

// return 0;
// }


// ✅7.Tuple Concatenation
// You can use std::tuple_cat to concatenate tuples.

// std::tuple<int, char> t1(5, 'x');
// std::tuple<int, char> t2(4, 'x');
// std::tuple<double, std::string> t3(3.14, "hello");

// auto t4 = std::tuple_cat(t1, t2, t3, ------ - t); // Result: (5, 'x',4,'x', 3.14, "hello")

// ✅8.Tie Function
// You can unpack or decompose tuple elements using std::tie into separate variables.
// If you don’t need an element, you can use std::ignore.

// std::tuple<int, char, double> t{ 42, 'A', 3.14 };
// int num;
// char letter;
// double value;

// // Use std::tie to unpack tuple into variables
// std::tie(num, letter, value) = t;
// std::cout << "Number: " << num << ", Letter: " << letter << ", Value: " << value << '\n';

// std::cout << "Original Tuple: ";
// std::cout << "Number: " << std::get<0>(t) << ", Letter: " << std::get<1>(t) << ", Value: " << std::get<2>(t) << '\n';


// ✅If you don’t need an element, you can use std::ignore.

// std::tuple<int, char, double> t{ 42, 'A', 3.14 };
// int num;
// double value;
// // Skip the second element using std::ignore
// std::tie(num, std::ignore, value) = t;
// std::cout << "Number: " << num << ", Value: " << value << '\n';

// ✅9.Swapping Tuples
// Tuples can be swapped using the swap function.

// std::swap(myTuple, myTuple2);


// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ✅✅✅Applications / Scenarios of Using std::tuple in C++

// 1.Return Multiple Values from a Function.
// Tuples are highly useful when returning multiple values of different types from a function.

// std::tuple<int, double, std::string> large_Tuple() {
//     return std::make_tuple(42, 3.14, "Hello");
// }

// auto largeTuple = large_Tuple();
// // Access elements one by one (not scalable for many elements)
// int id = std::get<0>(largeTuple);
// double value = std::get<1>(largeTuple);
// std::string text = std::get<2>(largeTuple);
// char ch = std::get<3>(largeTuple);
// bool flag = std::get<4>(largeTuple);
// float temp = std::get<5>(largeTuple);

// 2.Pass Multiple Parameters into a Function.

// void processTuple(const std::tuple<int, double, std::string>&t) {
//     std::cout << std::get<0>(t) << ", " << std::get<1>(t) << ", " << std::get<2>(t);
// }
// std::tuple<int, double, std::string> myTuple(42, 3.14, "Hello");
// processTuple(myTuple);


// it is implemented using variadic template and recursive inheritance

// if acess out of bound elements it will give compile time error 

// size is fixed at compile time cannot be used as vector for dynamic 


// auto tup=std:: make_tuple(1,1.323,"hello");

// std::apply([](int a double b , std::string c){ cout<<a << b<<c ;},tup);