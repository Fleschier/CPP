//#include<iostream>
//#include<string>
//#include<vector>
//#include<cmath>
//#include<complex>
//
//#define pi 3.14159265358979323846		/* pi */
//#define MAX_LEN  220
//
//using namespace std;
//
//
//complex<double> omega(int n, int k);		//单位复数根的表达式求解
//vector<complex<double>>RecursiveFFT(vector<complex<double>> &a);		//FFT变换
//vector<complex<double>>RecursiveIFFT(vector<complex<double>> &a);		//逆向FFT变换
//vector<complex<double>>toComplex(char* a);				//从字符数组转化为复数向量
//void toCharArr(vector<complex<double>> &a, char* b);				//从复数向量转化为字符数组
//vector<complex<double>> Vec_multi(vector<complex<double>> &a1, vector<complex<double>> &a2);	//两个复数向量对应位相乘
//void showCharArr(char a[]);		//打印字符数组
//template<class T>//模板类，打印向量
//void showVec(std::vector<T> &v);		
//vector<int> toIntVec(vector < complex<double>> &a);		//将复数向量转化为整型向量
//long long getAnswer(vector<int> &vi);	//测试用，从整型向量(卷积)求得结果数值，保存在long long类型中
//int conversion(char a[], int len_a, char res[], int para);	//将一个长度不是2的幂次的数转化为2的幂长度
//int compensation(int n);//根据n补齐到对应的2的次幂
//void BigNumMultiply(vector<int> src, char res[]);	//从卷积Vector转化为结果的字符数组
//
//
//int main() {
//	//store the big number via char array
//	char tnum1[MAX_LEN];
//	char tnum2[MAX_LEN];
//	char num1[MAX_LEN] = { 0 };
//	char num2[MAX_LEN] = { 0 };
//
//	printf("Please enter a num(length less than 100): ");
//	scanf("%s", tnum1);
//	printf("Plesase enter another one: ");
//	scanf("%s", tnum2);
//
//	//预处理，如果两个数不等长，则将较长的数先补齐到2的幂的长度，再将较短的补齐到与较长的等长
//	int len_tnum1 = strlen(tnum1);
//	int len_tnum2 = strlen(tnum2);
//	if (len_tnum1 > len_tnum2) {
//		int tmp = conversion(tnum1, len_tnum1, num1, 0);
//		conversion(tnum2, len_tnum2, num2, tmp);
//	}
//	else {
//		int tmp = conversion(tnum2, len_tnum2, num2, 0);
//		conversion(tnum1, len_tnum1, num1, tmp);
//	}
//
//	//位数拓展，从n拓展到2n(n为2的幂)
//	int length = strlen(num1);
//	for (int i = 0; i < length; i++) {	//0 ---> length - 1
//		//在前面填充'0'，变为2n
//		num1[length + i] = num1[i];
//		num1[i] = '0';
//		num2[length + i] = num2[i];
//		num2[i] = '0';
//	}
//
//	//转化为复数向量
//	vector<complex<double>> num_vec1 = toComplex(num1);
//	vector<complex<double>> num_vec2 = toComplex(num2);
//
//	//分别求两个数的点值表示
//	vector<complex<double>> num1_FFT = RecursiveFFT(num_vec1);
//	vector<complex<double>> num2_FFT = RecursiveFFT(num_vec2);
//
//	//在点值表示下求两个数的积
//	vector<complex<double>> res_FFT = Vec_multi(num1_FFT, num2_FFT);
//
//	//逆向FFT求得卷积
//	vector<complex<double>> result = RecursiveIFFT(res_FFT);
//
//	//cout << "求得的卷积为： ";
//	vector<int> intVec = toIntVec(result);
//	//showVec(intVec);
//	cout << "输入1 :  ";
//	showCharArr(tnum1);
//	cout << "输入2:   ";
//	showCharArr(tnum2);
//	//long long res = getAnswer(intArr);
//	//cout << "大整数乘法结果为:" << res << endl;
//	char bignum_res[MAX_LEN] = { 0 };
//	BigNumMultiply(intVec, bignum_res);
//	printf("大整数乘法的结果为： ");
//	showCharArr(bignum_res);
//
//	return 0;
//}
//
//
////FFT recursive-------------------------------------------------------------------------------------------------
//// 利用快速傅里叶变换将一个数从系数形式转为点值形式
//vector<complex<double>> RecursiveFFT(vector<complex<double>> &a) {
//	int n = a.size();
//	//递归终止条件
//	if (n == 1) return a;
//	//omega n  Wn = e^(2*pi*i/n) = cos(2*pi/n) + i * sin(2*pi/n)
//	//complex<double> Wn = omega(n, 1);
//	//W = 1
//	//complex<double> W(1, 1);		//注意这里的W虚部要取1，否则下面的乘法会有很严重的问题
//	//a[0] 偶数项系数: a_0, a_2....a_n-2	
//	vector<complex<double>> a0;
//	//a[1]奇数项系数: a_1, a_3...a_n-1
//	vector<complex<double>> a1;
//	//将奇数项和偶数项分别传入向量
//	for (int i = 0; i < n; i++) {
//		if (i % 2 == 0)
//			a0.push_back(a[i]);
//		else
//			a1.push_back(a[i]);
//	}
//	//递归调用
//	vector<complex<double>> y0 = RecursiveFFT(a0);
//	vector<complex<double>>y1 = RecursiveFFT(a1);
//	//返回的结果，y是一个值的序列,赋初始长度为n
//	vector<complex<double>> y(n);
//	// yk  = A(omega(n,k)) k = 0,1,2...n-1
//	for (int i = 0; i <= n / 2 - 1; i++) {
//		//cout << " y0[" << i << "]: " << y0[i] << "\ty1[" << i << "]" << y1[i] << endl;
//		//cout << "begin: W: " << W << "\tWn: " << Wn << endl;
//		//if (W.real() == 1 && W.imag() == 1) { //W = 1时
//		//	y[i] = y0[i] + y1[i];
//		//	y[i + n / 2] = y0[i] - y1[i];
//		//	W = Wn;
//		//}
//		//else {
//		//	y[i] = y0[i] + W*y1[i];
//		//	y[i + n / 2] = y0[i] - W*y1[i];
//		//	W = W * Wn;
//		//}
//		y[i] = y0[i] + omega(n, i)*y1[i];
//		y[i + n / 2] = y0[i] - omega(n, i)*y1[i];
//		//cout << "after : W: " << W << endl << endl;
//	}
//	return y;
//}
//
////逆向FFT变换
//vector<complex<double>>RecursiveIFFT(vector<complex<double>> &a) {
//	int n = a.size();
//	if (n == 1) return a;
//	vector<complex<double>> a0;
//	vector<complex<double>> a1;
//	for (int i = 0; i < n; i++) {
//		if (i % 2 == 0)
//			a0.push_back(a[i]);
//		else
//			a1.push_back(a[i]);
//	}
//	//递归调用
//	vector<complex<double>> y0 = RecursiveFFT(a0);
//	vector<complex<double>>y1 = RecursiveFFT(a1);
//	vector<complex<double>> y(n);
//	for (int i = 0; i <= n / 2 - 1; i++) {
//		y[i] = (y0[i] + omega(n, i)*y1[i]) / (double)n;
//		y[i + n / 2] = (y0[i] - omega(n, i)*y1[i]) / (double)n;
//	}
//	return y;
//}
//
////omega n的k次方(返回值是一个复数)
//complex<double> omega(int n, int k) {
//	//利用omega n的表达式和欧拉公式转换来表达
//	double real = cos(2 * k* pi / n);
//	double imag = sin(2 * k*pi / n);
//
//	//因为精度问题，所以手动将趋近于0的取整为0
//	if (abs(real) < 1e-15) real = 0;
//	if (abs(imag) < 1e-15) imag = 0;
//	complex<double> res(real, imag);
//	return res;
//}
//
////转化为复数形式
//vector<complex<double>>toComplex(char* a) {
//	int len = strlen(a);
//	vector<complex<double>> res(len);
//	for (int i = 0; i < len; i++) {
//		res[i] = complex<double>(a[i] - 48, 0);		//'0': 48
//		//cout << res[i] << endl;
//	}
//	return res;
//}
//
////转化为字符数组的形式
//void toCharArr(vector<complex<double>> &a, char * b) {
//	int len = a.size();
//	for (int i = 0; i < len; i++) {
//		b[i] = abs(a[i]) + '0';		//求解复数的模
//	}
//}
//
////两个vector里面元素对应两两相乘，两个vector等长
//vector<complex<double>> Vec_multi(vector<complex<double>>&a1, vector<complex<double>> &a2) {
//	int len = a1.size();
//	vector<complex<double>> res(len);
//	for (int i = 0; i < len; i++) {
//		res[i] = a1[i] * a2[i];
//	}
//	return res;
//}
//
////根据n补齐到对应的2的次幂
//int compensation(int n) {
//	int res;
//	int i = 1;
//	while (true) {
//		res = pow(2, i);
//		if (res >= n) break;
//		i++;
//	}
//	return res;
//}
//
////将一个长度不是2的幂次的数转化为2的幂长度, 返回值是补充后的数组的长度
////参数说明： 源数组， 源数组长度， 目的数组， 要填充到的长度
//int conversion(char a[], int len_a, char res[], int para) {			//C++函数内部创建的数组在函数返回时就会被销毁，即使传出了数组指针也没有用
//	int len = compensation(len_a);		//扩充到2的幂
//	//para是指定的补全长度，如果不为0 则按照para的指定长度来补全(在预处理中，已经确保para的长度大于len_a)，否则补全到len
//	if (para == 0) {
//		for (int j = 0; j < len - len_a; j++) res[j] = '0';
//		for (int i = 0; i < len_a; i++) {
//			res[len - len_a + i] = a[i];
//		}
//	}
//	else {
//		for (int j = 0; j < para - len_a; j++) res[j] = '0';
//		for (int i = 0; i < len_a; i++) {
//			res[para - len_a + i] = a[i];
//		}
//	}
//	return len;
//}
//
//vector<int> toIntVec(vector < complex<double>> &a) {
//	int len = a.size();
//	vector<int> res(len);
//	for (int i = 0; i < len; i++) {
//		res[i] = ceil(abs(a[i]) - 0.5);			//向上取整，四舍五入
//	}
//	//---fix a bug------trick-------------------------------
//	vector<int> result(len);
//	copy(res.begin() + 2, res.end(), result.begin());
//	result[len - 2] = res[0];
//	result[len - 1] = res[1];
//	//--------------------
//	return result;
//}
//
//long long getAnswer(vector<int> &vi) {
//	long long res = 0;
//	for (int i = 0; i < vi.size(); i++) {
//		res += vi[i] * pow(10, i);
//	}
//	return res;
//}
//
////打印字符数组
//void showCharArr(char a[]) {
//	//cout << "the char arr is: \n";
//	int len = strlen(a);
//	int begin = -1;
//	for (int i = 0; i < len; i++) {		//找到第一位非0位的index
//		if (a[i] != '0') {
//			begin = i;
//			break;
//		}
//	}
//	//如果结果全为0，即上面的赋值语句没有执行，则打印0
//	if (begin == -1) {
//		printf("%c\n", '0');
//		return;
//	}
//	for (int i = begin; i < len; i++) printf("%c", a[i]);
//	printf("\n");
//}
//
////打印向量
//template<class T>
//void showVec(vector<T> &v) {
//	int len = v.size();
//	for (int i = 0; i < len; i++) {
//		cout << v[i] << "\t";
//	}
//	cout << endl;
//}
//
//void BigNumMultiply(vector<int> src, char res[]) {
//	int len = src.size();
//	int idx = len - 1;		//从后向前填充结果字符数组
//
//	for (int i = 0; i < len; i++) {
//		//将每一位大于十的部分进位，保证每一位是一位十进制数
//		if(i < len -1) 
//			src[i + 1] += src[i] / 10;
//		res[idx] = (src[i] % 10) + '0';
//		idx--;
//	}
//}