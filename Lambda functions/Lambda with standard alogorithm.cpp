#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Lamda expressions are extensively used in STL in place of callback i.e. functions passed as arguments.
// 1.) SORT DESCENDING ORDER
// int main() {
//     std::vector<int> nums = {5, 2, 8, 1, 3};

//     std::sort(nums.begin(), nums.end() , [](const int &a ,const int &b) { return a>b;}     );

//     for (int num : nums)
//     std::cout << num << " "; // Output: 8 5 3 2 1
//     return 0;
// }


// 2.) FIND IF 

    // int main()
    // {
    //     vector<int>v={10,13,16,15,7,90};

    //     auto it=find_if(v.begin(),v.end(), [](const int &a) { return a%3==0 ;});

    //     if(it!=v.end()) cout<<*it;
    //     else cout<<"NO element";
    //     return 0;
    // }

// 3.) FOR EACH 

    int main()
    {
        vector<int>v={1,2,4,5,7,8,9};

        for_each(v.begin(),v.end(),[](const int &a) {cout<<a*a <<" ";} );  


        return 0;
    }

    // Lambda expressions’ main purpose was to replace the functions in callbacks by providing inline definitions.

    