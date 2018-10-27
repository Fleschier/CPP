#include<iostream>
#include<string>
using namespace std;

class mail
{
public:
    virtual string transfer() = 0;
};

class regular : public mail
{
public:
    virtual string transfer()
    {
        return string( "mailcart" );
    }
};

class express : public mail
{
public:
    string transfer()
    {
        return string( "high speed railway station" );
    }
};

class airmail : public mail
{
public:
    string transfer()
    {
        return string( "airport" );
    }
};

class postman
{
public:
    void diliver( mail &m )
    {
        cout << "Sending mail to " << m.transfer() << endl;
    }
};

class dispatcher
{
public:
    void dispatch( mail &m, postman &d )
    {
        d.diliver( m );
    }
};

int main()
{
    regular r1, r2, r3;
    express e1, e2, e3;
    airmail a1, a2, a3;

    dispatcher	worker1;
    postman worker2;

    worker1.dispatch( r1, worker2 );
    worker1.dispatch( r2, worker2 );
    worker1.dispatch( r3, worker2 );
    worker1.dispatch( e1, worker2 );
    worker1.dispatch( e2, worker2 );
    worker1.dispatch( e3, worker2 );
    worker1.dispatch( a1, worker2 );
    worker1.dispatch( a2, worker2 );
    worker1.dispatch( a3, worker2 );

    return 0;
}
