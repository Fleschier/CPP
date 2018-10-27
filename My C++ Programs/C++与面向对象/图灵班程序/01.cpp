#include<iostream>
using namespace std;

#define UINT unsigned int

template<typename T>
class myvector
{
    T *buf;
	UINT len;
	void new_space(UINT size = 0);
	void bufset ( T *mem, T value, UINT size );
	void bufcpy (T *src, T *des, UINT size );
    void objcpy ( myvector & vec );
public:
    myvector();
    myvector( UINT size );
    myvector( UINT size, T value );
    myvector( myvector &vec );
    myvector( T *begin, T *end );
	~myvector();
    bool empty();
    void clear();
    UINT length();
    T* begin();
    void push_back( T value );
    void pop_back();
    void resize( UINT size, T value );
    void resize( UINT size );
    void remove( UINT index );
    bool operator == ( myvector & vec );
    bool operator != ( myvector &vec );
    T & operator [] ( UINT index );
    myvector operator + ( myvector & vec );
    void operator = ( myvector & vec );
    myvector operator - ( myvector & vec );
	friend ostream & operator <<( ostream & os, const myvector<T> & vec );
};

int main()
{
	myvector<int> a(10, 5);
	a[6] =  20;
	cout<<a;

	a.pop_back();
	cout<<a;

	a.push_back(100);
	cout<<a;

	myvector<int> b(a.begin()+4, a.begin()+1);
	cout<<b;

	myvector<int> c;
	c.push_back( 200 );
	cout << c;

	myvector<int> d(10);
	for (UINT i=0; i<d.length(); d[i++] = i);
	cout << d;

	d.remove( 3 );
	cout << d;

	myvector<int> e(d);
	cout << e;

	if ( d == e ) cout << "EQUAL" << endl;
	else cout << "NOT EQUAL" << endl;
	d.remove( 3 );

	if ( d == e ) cout << "EQUAL" << endl;
	else cout << "NOT EQUAL" << endl;

	cout << d << e;

	myvector<int> f;
	f = e - d;
	cout << f;

	return 0;
}
