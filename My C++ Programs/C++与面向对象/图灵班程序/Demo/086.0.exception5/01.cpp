#include<iostream>
#include<exception>
#include<string>

using namespace std;

class Exception
{
    int errorcode;
    string errormsg;
public:
    Exception( int code, string str )
    {
        errorcode = code;
        errormsg  = str;
    }
    void tell()
    {
        cout << "errorcode=" << errorcode << "," << errormsg << endl;
    }
};

class count
{
    int t;
public:
    count( int i )
    {
        if ( i == 0 ) throw( Exception( 0, "zero" ) );
        if ( i < 0 )  throw( Exception( -1, "minus" ) );
        t = i;
    }
    void kickback()
    {
        if ( t == 0 ) throw( string( "no way" ) );
        t--;
    }
};

int main()
{
    try
    {
        count c1( -1 );
        count c2( 0 );
        count c3( 1 );
        c3.kickback();
        c3.kickback();
    }
    catch( string s )
    {
        cout << s << endl;
        return 1;
    }
    catch( int i )
    {
        switch( i )
        {
        case 0 :
            cout << "b=0" << endl;
            break;
        case 1 :
            cout << "b=1" << endl;
            break;
        }
        return 1;
    }
    catch( Exception e )
    {
        e.tell();
        return 1;
    }
    catch( ... )
    {
        cout << "others" << endl;
        return 1;
    }

    cout << "Done." << endl;
    return 0;
}
