#include <iostream>
#include <list>
#include<string>
using namespace std;

class YoutubeChanel{
    public:
    string name;
    string ownername;
    int subcount;
    list<string>PublishedVideoTitle;
};

int main()
{
    YoutubeChanel ytChannel;
    ytChannel.name="Shobhit";
    ytChannel.ownername="shobhit thakral";
    ytChannel.subcount=10000;
    ytChannel.PublishedVideoTitle={"c++ for begineers","html for begineer"};

    cout<<"Name : "<<ytChannel.name<<endl;
    cout<<"Owner Name : "<<ytChannel.ownername<<endl;
    cout<<"Subcount : "<<ytChannel.subcount<<endl;
    for(string video : ytChannel.PublishedVideoTitle)
    {
        cout<<"videos : "<<video<<endl;
    }
    
}