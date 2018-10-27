#include<iostream>

using namespace std;



int getPermuStack(int n, int m)
{
	if (n == 0)//递归边界
		return 1;
	if (m == 0)//(n,0)问题的处理
		return getPermuStack(n - 1, 1);
	return getPermuStack(n, m - 1) + getPermuStack(n - 1, m + 1);
}


int main()
{
	cout << "please enter the number of the nums:" << endl;
	int i;
	cin >> i;
	cout << "The total count of stackout permutation is  "<<getPermuStack(i, 0) << endl;
	return 0;
}
