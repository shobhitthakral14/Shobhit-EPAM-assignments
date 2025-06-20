#include <iostream>
#include <list>
#include <string>
using namespace std;

class youtubeChannel {
private:
    string name;
    int subcount;

public:
    youtubeChannel() : name(""), subcount(0) {}
    youtubeChannel(string Name, int subscount) : name(Name), subcount(subscount) {}

    bool operator==(const youtubeChannel& other) const {
        return this->name == other.name && this->subcount == other.subcount;
    }

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
        CIN.ignore(); // Clear newline character left in the input stream
        return CIN;
    }
};

class mycollection {
public:
    list<youtubeChannel> mychannel;

    void operator+=(youtubeChannel& ytchannel) {
        this->mychannel.push_back(ytchannel);
    }
    void operator-=(youtubeChannel& ytchannel) {
        this->mychannel.remove(ytchannel);
    }

    friend ostream& operator<<(ostream& COUT, mycollection& mycoll) {
        for (const youtubeChannel& yt : mycoll.mychannel) {
            COUT << yt << endl;
        }
        return COUT;
    }
};

int main() {
    youtubeChannel ytchannel1("shobhit thakral", 500000);
    youtubeChannel ytchannel2("shobhit singer", 800000);
    youtubeChannel ytchannel3("shobhit chef", 900000);
    mycollection myc;
    myc += ytchannel1;
    myc += ytchannel2;
    myc -= ytchannel2;
    myc += ytchannel3;
    myc -= ytchannel3;
    cout << myc;

    return 0;
}