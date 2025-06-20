// Control flow statements direct the order of execution of instructions in a C++ program, based on conditions or repetitions. 
// Without them, code would execute linearly.
// These are fundamental for decision-making, looping, and branching in your code.


// --------------------------------------CONDITIONAL STATEMENT --------------------------------------- 

// if , else if , else 

// 1.) if statement 

// if there is only if then if the condition is true it will run that part of the code otherwise not 


// int a=5;
// if(a==5)
// {
//     cout<<"true"<<endl;
// }


// 2.) if else 

// int main()
// {
//     int x=10;
//     if(x<9)
//     {
//         cout<<'lesser'<<endl;
//     }
//     else
//     {
//         cout<<"larger"<<endl;
//     }
//     return 0;
// }


// 3.) switch statement 


// // It is a conditional (selection) statement, though it uses jump logic internally for performance.

// Used for multiple branching based on value of expression integral or enum types.(int , char ,enum)




// int day=3;

// switch(day)
// {
//     case 1:
//     cout<<"day1"<<endl;
//     break;

//     case 2:
//     cout<<"day2"<<endl;
//     break;

//     case 3:
//     cout<<"day3"<<endl;
//     break;

//     default:
//     cout<<"invalid"<<endl;
// }

// here only case 3 will execute

// adding break is very important as by not adding break it will lead to fall through means it can run 
// cases after the case which is find out 
// All the cases will execute until the break is find out 

// we can also give intentionlly fall through using [[fallthrough]]; it is a concept f cpp17

// we can also use return in place of break as it will return means exit the program 

// default is like else means if there is no case matched then default will run 

// it is faster than if else in many compiler due to jump table optimization 

// it will not execute complex conditions 

// it can only use int char enum const expr not other data types 



// TERNARY OPERATOR 

// int a=5, b=10;

// int max=(a>b)?a:b;

// it is also like if else statement if the first part means the condition is true run the first part else run the second part


//---------------------------------------------LOOPING STATEMENT--------------------------------------------------


// looping statement allow to execute the code until the condition is true 

//1.) for loop 

// in  this we know how many times we want to loop 

// for(int i=0;i<5;i++)
// {
    // cout<<i<<endl;
// }

// initialization condtion update 

// mutiple statement of for loop 

// for (int i = 0, j = 10; i < j; i++, j--) {
//     std::cout << "i = " << i << ", j = " << j << std::endl;
// }

// it is good to use pre increment as there are less instructions for pre fix incremet  



// 2.) while

// while(condition)
// {
//     cout<<"code"<<endl;
// }

// if the conditon is true then it will execute otherwise out of program 


//3.) do while

// do {
//     // code to execute
// } while (condition);

//Loop body executes at least once, then condition is checked.
// Useful when you want the loop to run once regardless of condition.


// 4.) range based loop 

// for(auto it : mpp)
// {
//     cout<<mpp.first<<endl;
// }



// if we are using 
// break means the loop exit immediately 
// continue means to skip that condition 
// return exit the entire function 


// while check before exection do while check after execution 

// if we forget to update it will run infintely

// loop variable can also be defined outside the loop 

// for(;;) // without condition infinite loop 

// loop variable can also be modified inside loop 


// we can also nest loop of different types like while inside for

// loop condition can also have function calls 
// while(func())




// ------------------------------------JUMP STATEMENTS--------------------------------


// Jump statements alter the normal sequential flow of control by transferring control to another part of the program.

// break  continue return goto 

// break exits the loop 
// continue skip that particular condition 
// return exits the function and can return value
// goto Transfers control unconditionally to a labeled statement within the same function.

// goto can jump to labels within the same function not outside the function 

// continue cannot be used in switch 

// for (int i = 0; i < 3; i++) {
//     for (int j = 0; j < 3; j++) {
//         if (i == 1 && j == 1)
//             goto end_loops;  // Exit both loops immediately
//         std::cout << i << "," << j << " ";
//     }
// }
// end_loops:
// std::cout << "Loops ended\n";



//int main() {

// int i = 0;

// start:
//     std::cout << i << " ";
//     i++;
//     if (i < 5) goto start;
// }
// Output: 0 1 2 3 4

// if we write goto before it is declared it will not give error and compiler will send it to that part 