#include <iostream>
#include <list>
#include <string>
using namespace std;

class YoutubeChanel {
public:
    string name;
    string ownername;
    int subcount;
    list<string> PublishedVideoTitle;

    //default constructor or non parametrized construtor
    YoutubeChanel()
    {
        name="not given";
        ownername="NULL";
        subcount=0;
    }
    // parametrized constructor 
    YoutubeChanel(string Name, string Ownername, int Subcount = 0) 
    {
        name = Name;
        ownername = Ownername;
        subcount = Subcount;
    }
    
    // get info function 
    void getinfo() {
        cout << "Name : " << name << endl;
        cout << "Owner Name : " << ownername << endl;
        cout << "Subcount : " << subcount << endl;
        for (string video : PublishedVideoTitle) {
            cout << "Videos : " << video << endl;
        }
    }
};

int main() {
    YoutubeChanel ytChannel("shobhit", "shobhit thakral");
    ytChannel.PublishedVideoTitle.push_back("C++ for beginners");
    ytChannel.PublishedVideoTitle.push_back("HTML for beginners");
    ytChannel.getinfo();

    YoutubeChanel ytChannel2("shobhit singer", "shobhit thakral", 5000);
    ytChannel2.getinfo();

    YoutubeChanel ytChannel3;
    ytChannel3.getinfo();
    return 0;
}
