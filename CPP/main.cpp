#include <iostream>

using namespace std;

class test{
    public:
        int a;
        int b;
        test(int m, int n){
            a = m;
            b = n;
        }
};

int main() {
    test a1 = test(2,3);
    cout << "Hello, world!\n";
    return 0;
}
