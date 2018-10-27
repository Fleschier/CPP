#include <iostream>
#include "name2.h"

using namespace std;

namespace n2
{
    void f2()
    {
        cout << "this is n2::f2();" << endl;
        return;
    }
}
namespace n3
{
    void f2()
    {
        cout << "this is n3::f2();" << endl;
        return;
    }
}