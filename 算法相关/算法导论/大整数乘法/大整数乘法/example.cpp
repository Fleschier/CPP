//#include <stdio.h>
//#include <string.h>
//#include <set>
//#include <map>
//#include <algorithm>
//#include<complex>
//#include<iostream>
//#define pi acos(-1)
//using namespace std;
//typedef complex<double> E;
//
//const int maxn = 100000 + 10;
//
//int R[maxn];
//char ch[maxn];
//E a[maxn], b[maxn];
//int  c[maxn];
//int n, m, L;
//
//void fft(E *a, int f) {
//	for (int i = 0; i<n; i++) if (i<R[i]) swap(a[i], a[R[i]]);
//	for (int i = 1; i<n; i <<= 1) {
//		E wn(cos(pi / i), f*sin(pi / i));
//		for (int p = i << 1, j = 0; j<n; j += p) {
//			E w(1, 0);
//			for (int k = 0; k<i; k++, w *= wn) {
//				E x = a[j + k], y = w*a[j + k + i];
//				a[j + k] = x + y; a[j + k + i] = x - y;
//			}
//		}
//	}
//	if (f == -1) for (int i = 0; i<n; i++) a[i] /= n;
//}
//
//int main() {
//	scanf("%s", ch);
//	int len1 = strlen(ch);
//	for (int i = 0; i<len1; i++) a[i] = ch[len1 - 1 - i] - '0';
//	scanf("%s", ch);
//	int len2 = strlen(ch);
//	for (int i = 0; i<len2; i++) b[i] = ch[len2 - 1 - i] - '0';
//	n = max(len1, len2); n--; L = 0; m = 2 * n;
//	for (n = 1; n <= m; n <<= 1) L++;
//	for (int i = 0; i<n; i++) R[i] = (R[i >> 1] >> 1) | ((i & 1) << (L - 1));
//	fft(a, 1), fft(b, 1);
//	for (int i = 0; i <= n; i++) a[i] = a[i] * b[i];
//	fft(a, -1);
//	for (int i = 0; i <= m; i++) c[i] = (int)(a[i].real() + 0.1);
//	for (int i = 0; i <= m; i++) {
//		if (c[i] >= 10) {
//			c[i + 1] += c[i] / 10, c[i] %= 10;
//			if (i == m) m++;
//		}
//	}
//	bool flag = false;
//	for (int i = m; i >= 0; i--) {
//		if (flag || c[i]) {
//			printf("%d", c[i]);
//			flag = true;
//		}
//	}
//}