#include <iostream>
#include <list>
#include <string>
using namespace std;
class book
{
     public:
     string title;
     string author;
     float* rates;
     int ratecounter;


     // this is a paramterized constructor 
     book (string Title,string Author)
     {
        title=Title;
        author=Author;
        ratecounter=2;
        rates=new float[ratecounter];
        rates[0]=5;
        rates[1]=4;
     }

// creating a copy constructor

     book(const book& original)
     {
        title=original.title;
        author=original.author;
        ratecounter=original.ratecounter;
        // creating the pointer area again so that it will not give error when the destructor is called 
        rates=new float[ratecounter];
        for(int i=0;i<ratecounter;i++)
        {
            rates[i]=original.rates[i];
        }

     }
     ~book()
     {
        delete[]rates;
        rates=nullptr;
     }
     
};


// function that is using copy constructor and is outside the class

void printbook(book bk)
{
   cout<<"title: "<<bk.title<<endl;
   cout<<"author: "<<bk.author<<endl;
   float sum=0;
   for(int i=0;i<bk.ratecounter;i++)
   {
       sum+=bk.rates[i];
   }
   cout<<"Avg Rate : "<< sum/bk.ratecounter<<endl;
}


int main()
{
    book book1("millionaire fastlane","M.J.demacor");
    book book2("c++","bartek");
    book book3=book1;
    
    printbook(book1);
    cout<<endl;
    
    printbook(book2);
    cout<<endl;
    
    printbook(book3);


}