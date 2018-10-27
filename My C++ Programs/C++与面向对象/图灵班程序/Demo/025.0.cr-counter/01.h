#include <iostream>
using namespace std;

namespace userdefined
{

    class cr_counter
    {
        int count;
        int line;
    public:
        void init( int l )
        {
            count = 0;
            line = l;
            return;
        }
        void cr()
        {
            count++;
            if ( ! ( count % line ) ) cout << endl;
            return;
        }
    };

}