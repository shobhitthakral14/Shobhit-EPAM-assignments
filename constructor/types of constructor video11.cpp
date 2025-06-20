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

    // default consturctor
    YoutubeChanel()
    {
        name="not given";
        ownername="not present";
        subcount=0;
    }
    // parameterized constructor 
    YoutubeChanel(string Name, string Ownername, int Subcount=0) 
    {
        name = Name;
        ownername = Ownername;
        subcount = Subcount;
    }
    
    // get info function 
    void getinfo(YoutubeChanel u) {
        cout << "Name : " << u.name << endl;
        cout << "Owner Name : " << u.ownername << endl;
        cout << "Subcount : " << u.subcount << endl;
        for (string video : u.PublishedVideoTitle) {
            cout << "Videos : " << video << endl;
        }
    }
};

int main() {
    
    YoutubeChanel ytChannel("shobhit", "shobhit thakral");
    YoutubeChanel ytChannel1("shobhit singer", "shobhit thakral", 5000);
    YoutubeChanel ytChannel2;
    ytChannel.PublishedVideoTitle.push_back("C++ for beginners");
    ytChannel.PublishedVideoTitle.push_back("HTML for beginners");
    
    ytChannel.getinfo(ytChannel);
    cout<<endl;
    
    ytChannel2.getinfo(ytChannel2);
    cout<<endl;
    
    ytChannel1.getinfo(ytChannel1);
    cout<<endl;

    return 0;
}
