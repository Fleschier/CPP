#include<iostream>
using namespace std;

int main()
{
	cout << "please enter n:\n";
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1;; i++) {
		if (n >= i) {
			n -= i;
			sum += i*i;
		}
		else if (n < i) {
			sum += n*i;
			break;
		}
	}
	cout << "there are " << sum << "  chalks\n";
	return 0;
}