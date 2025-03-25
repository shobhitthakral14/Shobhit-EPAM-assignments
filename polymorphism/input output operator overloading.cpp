#include <iostream>
#include <string>
using namespace std;

class youtubeChannel {
private:
    string name;
    int subcount;

public:
    
    youtubeChannel() : name(""), subcount(0) {}

    
    youtubeChannel(string Name, int subscount) : name(Name), subcount(subscount) {}

    friend ostream& operator <<(ostream& COUT, const youtubeChannel& ytchannel) {
        COUT << "Name: " << ytchannel.name << endl;
        COUT << "Subscribers: " << ytchannel.subcount << endl;
        return COUT;
    }

    friend istream& operator>>(istream& CIN, youtubeChannel& ytchannel) {
        cout << "Enter channel name: ";
        getline(CIN, ytchannel.name);
        cout << "Enter subscriber count: ";
        CIN >> ytchannel.subcount;
        return CIN;
    }
};

int main() {
    
    youtubeChannel ytchannel1("shobhit thakral", 500000);
    youtubeChannel ytchannel2("shobhit singer", 800000);
    cout << "Channel 1:\n" << ytchannel1 << endl;
    cout << "Channel 2:\n" << ytchannel2 << endl;;
    
    youtubeChannel ytchannel3;
    cin >> ytchannel3;
    cout << "Newly Entered Channel:\n" << ytchannel3;
    
    return 0;
}