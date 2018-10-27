#include<iostream>

using namespace std;

class trigger
{
    int	 q;
    int _q;
    int	 d;
public:
    void reset();
    void _reset();
    void _q_set();
    void cp();
    void set( int );
    int  tell( int );
};

void trigger::_q_set()
{
    if ( q ) _q = 0;
    else _q = 1;
    return;
}

void trigger::reset()
{
    q  = 1;
    _q_set();
    return;
}

void trigger::_reset()
{
    q  = 0;
    _q_set();
    return;
}

void trigger::cp()
{
    q = d;
    _q_set();
    return;
}

void trigger::set( int data )
{
    if ( data == 0 ) d = 0;
    else d = 1;
}

int trigger::tell( int port )
{
    if ( port == 0 ) return _q;
    return q;
}

int main()
{
    trigger t1;

    t1.reset();
    cout << " q = " << t1.tell( 1 ) << endl;
    cout << "_q = " << t1.tell( 0 ) << endl;
    cout << endl;

    t1.set( 0 );
    cout << " q = " << t1.tell( 1 ) << endl;
    cout << "_q = " << t1.tell( 0 ) << endl;
    cout << endl;

    t1.cp();
    cout << " q = " << t1.tell( 1 ) << endl;
    cout << "_q = " << t1.tell( 0 ) << endl;
    cout << endl;

    return 0;
}