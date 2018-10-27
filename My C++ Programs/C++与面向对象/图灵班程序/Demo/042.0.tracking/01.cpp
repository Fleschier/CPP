#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

enum direction { Login = 1, Logout = 0 };

class trackingdemo
{
    static int sum;
    static int max;
    string name;
    int number;
public:
    trackingdemo( string & );
    ~trackingdemo();
    void report( int );
};

int trackingdemo::sum = 0;
int trackingdemo::max = 0;

trackingdemo::trackingdemo( string &obj_name = ( string )"No Name" )
{
    name = obj_name;
    number = ++max;
    sum++;
    report( Login );
}

trackingdemo::~trackingdemo()
{
    sum--;
    report( Logout );
}

void trackingdemo::report( int dir )
{
    cout << "Object No." << number << "(" << name << ( ( dir ) ? ")\tcreated. " : ")\tremoved. " );
    cout << "Totally " << sum << " object(s) " << ( ( dir ) ? "available." : "left." ) << endl;
    //ofstream fout("log.txt", ios::app);
    //fout<<"Object No."<<number<<"("<<name<<((dir)?")\tcreated.\t":")\tremoved.\t");
    //fout<<"Totally "<<sum <<" object(s) "<<((dir)?"available.":"left.")<<endl;
    //fout.close();
}

int main()
{
    trackingdemo *tr1, *tr2, *tr3, tr4( ( string )"Alice" );

    tr1 = new trackingdemo( ( string )"Mike" );
    tr2 = new trackingdemo( ( string )"Tom" );
    delete tr1;
    tr1 = NULL;
    tr3 = new trackingdemo;
    delete tr2;
    tr2 = NULL;
    delete tr3;
    tr3 = NULL;

    return 0;
}