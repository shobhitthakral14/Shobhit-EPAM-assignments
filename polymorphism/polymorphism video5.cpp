#include <iostream>
#include <list>
#include <string>
using namespace std;

class YoutubeChanel {

private:
    string name;
    int subcount;
    list<string> PublishedVideoTitle;
protected:
    string ownername;
    int contentquality;

public:
    // constructor 
    YoutubeChanel(string Name, string Ownername, int Subcount = 0) 
    {
        name = Name;
        ownername = Ownername;
        subcount = Subcount;
        contentquality=0;
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

    void subscribe()
    {
        subcount++;
    }
    
    void unsubscribe()
    {
        if(subcount>0)
        {
            subcount--;
        }
    }

    void publishvideo(string title)
    {
        PublishedVideoTitle.push_back(title);
    }

    void checkanalytics()
    {
        if(contentquality<5)
        {
            cout<<name<<" has bad quality content"<<endl;
        }
        else
        {
            cout<<name<<" has good content"<<endl;
        }
    }


};


class cookingYoutubeChanel : public YoutubeChanel
{
    public:
    cookingYoutubeChanel(string name ,string ownername) : YoutubeChanel(name,ownername)
    {

    }
    void practice()
    {
        cout<<ownername<<" is practicing cooking"<<endl;
        contentquality++;
    }
};

class singersYoutubeChanel : public YoutubeChanel
{
    public:
    singersYoutubeChanel(string name ,string ownername) : YoutubeChanel(name,ownername)
    {

    }
    void practice()
    {
        cout<<ownername<<" is practicing singing"<<endl;
        contentquality++;
    }
};



int main() {
    cookingYoutubeChanel cyc("shobhit kitchen","shobhit cook");
    singersYoutubeChanel syc("shobhit sings","shobhit singer");
    cyc.practice();
    syc.practice();
    syc.practice();
    syc.practice();
    syc.practice();
    syc.practice(); 
    

    return 0;
}
