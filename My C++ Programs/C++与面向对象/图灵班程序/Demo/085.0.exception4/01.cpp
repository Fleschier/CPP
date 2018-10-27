#include<iostream>
#include<exception>
#include<string>

using namespace std;

void f1()
{
    int *b = NULL;

    if ( !b ) throw( string( "null pointer!" ) );

    ( *b ) = 0;		// error

    return;
}

int f2()
{
    int a = 1, b = 0;

    if ( b == 0 ) throw( string( "divided by zero!" ) );
    //if (b==0) throw(b);

    return a / b;		// error
}

void f3()
{
    int c[10], i = 100;

    if ( i >= 10 ) throw( 1 );

    c[i] = 0;		//error

    return;
}

int main()
{

    try
    {
        f1();
        f2();
        f3();
    }
    catch( string s )
    {
        cout << s << endl;
    }
    catch( int i )
    {
        switch( i )
        {
        case 0 :
            cout << "b=0, from f2()." << endl;
            break;
        case 1 :
            cout << "b=1, from f3()." << endl;
            break;
        }
    }
    catch( ... )
    {
        cout << "others" << endl;
    }

    return 0;
}
