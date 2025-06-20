// Functors are commonly used with STL algorithms such as std::sort(), std::for_each(), etc.

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

// SORT

// //The functor decending overrides operator() to compare values.
// class decending
// {
//     public:
//     bool operator()(int a ,int b) const
//     {
//         return a>b;
//     }
// };

// int main()
// {
//     vector<int> arr={11,23,3,41,5};
//     //sort() uses this functor to sort in descending.
//     sort(arr.begin(),arr.end(),decending());
//     for(int num :arr)
//     {
//         cout<<num<<" ";
//     }
//     return 0;
// }


// TRANSFORM

// int increment(int a )
// {
//     return a+1;
// }

// int main()
// {
//     vector<int> v1 = {11, 5, 36, 8};
//     vector<int> v2(v1.size());
//     // Incrementing all elements of vector by 1
//     transform(v1.begin(), v1.end(), v2.begin(),increment);
//     for (auto i : v2)
//         cout << i << " ";

//     return 0;
// }


//Use lambdas for simple one-time operations.
// Use functors when reusability, stateful behavior, or performance matters.





// 3.) FOR EACH
class printt
{
    public:
    void operator() (int value)
    {
        cout<<value<< " ";
    }
};


int main()
{
    vector<int> vec={1,2,3,4,5};
    for_each(vec.begin(),vec.end(),printt());
    return 0;
}