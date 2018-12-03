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
//complex<double> omega(int n, int k);		//��λ�������ı��ʽ���
//vector<complex<double>>RecursiveFFT(vector<complex<double>> &a);		//FFT�任
//vector<complex<double>>RecursiveIFFT(vector<complex<double>> &a);		//����FFT�任
//vector<complex<double>>toComplex(char* a);				//���ַ�����ת��Ϊ��������
//void toCharArr(vector<complex<double>> &a, char* b);				//�Ӹ�������ת��Ϊ�ַ�����
//vector<complex<double>> Vec_multi(vector<complex<double>> &a1, vector<complex<double>> &a2);	//��������������Ӧλ���
//void showCharArr(char a[]);		//��ӡ�ַ�����
//template<class T>//ģ���࣬��ӡ����
//void showVec(std::vector<T> &v);		
//vector<int> toIntVec(vector < complex<double>> &a);		//����������ת��Ϊ��������
//long long getAnswer(vector<int> &vi);	//�����ã�����������(���)��ý����ֵ��������long long������
//int conversion(char a[], int len_a, char res[], int para);	//��һ�����Ȳ���2���ݴε���ת��Ϊ2���ݳ���
//int compensation(int n);//����n���뵽��Ӧ��2�Ĵ���
//void BigNumMultiply(vector<int> src, char res[]);	//�Ӿ��Vectorת��Ϊ������ַ�����
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
//	//Ԥ����������������ȳ����򽫽ϳ������Ȳ��뵽2���ݵĳ��ȣ��ٽ��϶̵Ĳ��뵽��ϳ��ĵȳ�
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
//	//λ����չ����n��չ��2n(nΪ2����)
//	int length = strlen(num1);
//	for (int i = 0; i < length; i++) {	//0 ---> length - 1
//		//��ǰ�����'0'����Ϊ2n
//		num1[length + i] = num1[i];
//		num1[i] = '0';
//		num2[length + i] = num2[i];
//		num2[i] = '0';
//	}
//
//	//ת��Ϊ��������
//	vector<complex<double>> num_vec1 = toComplex(num1);
//	vector<complex<double>> num_vec2 = toComplex(num2);
//
//	//�ֱ����������ĵ�ֵ��ʾ
//	vector<complex<double>> num1_FFT = RecursiveFFT(num_vec1);
//	vector<complex<double>> num2_FFT = RecursiveFFT(num_vec2);
//
//	//�ڵ�ֵ��ʾ�����������Ļ�
//	vector<complex<double>> res_FFT = Vec_multi(num1_FFT, num2_FFT);
//
//	//����FFT��þ��
//	vector<complex<double>> result = RecursiveIFFT(res_FFT);
//
//	//cout << "��õľ��Ϊ�� ";
//	vector<int> intVec = toIntVec(result);
//	//showVec(intVec);
//	cout << "����1 :  ";
//	showCharArr(tnum1);
//	cout << "����2:   ";
//	showCharArr(tnum2);
//	//long long res = getAnswer(intArr);
//	//cout << "�������˷����Ϊ:" << res << endl;
//	char bignum_res[MAX_LEN] = { 0 };
//	BigNumMultiply(intVec, bignum_res);
//	printf("�������˷��Ľ��Ϊ�� ");
//	showCharArr(bignum_res);
//
//	return 0;
//}
//
//
////FFT recursive-------------------------------------------------------------------------------------------------
//// ���ÿ��ٸ���Ҷ�任��һ������ϵ����ʽתΪ��ֵ��ʽ
//vector<complex<double>> RecursiveFFT(vector<complex<double>> &a) {
//	int n = a.size();
//	//�ݹ���ֹ����
//	if (n == 1) return a;
//	//omega n  Wn = e^(2*pi*i/n) = cos(2*pi/n) + i * sin(2*pi/n)
//	//complex<double> Wn = omega(n, 1);
//	//W = 1
//	//complex<double> W(1, 1);		//ע�������W�鲿Ҫȡ1����������ĳ˷����к����ص�����
//	//a[0] ż����ϵ��: a_0, a_2....a_n-2	
//	vector<complex<double>> a0;
//	//a[1]������ϵ��: a_1, a_3...a_n-1
//	vector<complex<double>> a1;
//	//���������ż����ֱ�������
//	for (int i = 0; i < n; i++) {
//		if (i % 2 == 0)
//			a0.push_back(a[i]);
//		else
//			a1.push_back(a[i]);
//	}
//	//�ݹ����
//	vector<complex<double>> y0 = RecursiveFFT(a0);
//	vector<complex<double>>y1 = RecursiveFFT(a1);
//	//���صĽ����y��һ��ֵ������,����ʼ����Ϊn
//	vector<complex<double>> y(n);
//	// yk  = A(omega(n,k)) k = 0,1,2...n-1
//	for (int i = 0; i <= n / 2 - 1; i++) {
//		//cout << " y0[" << i << "]: " << y0[i] << "\ty1[" << i << "]" << y1[i] << endl;
//		//cout << "begin: W: " << W << "\tWn: " << Wn << endl;
//		//if (W.real() == 1 && W.imag() == 1) { //W = 1ʱ
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
////����FFT�任
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
//	//�ݹ����
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
////omega n��k�η�(����ֵ��һ������)
//complex<double> omega(int n, int k) {
//	//����omega n�ı��ʽ��ŷ����ʽת�������
//	double real = cos(2 * k* pi / n);
//	double imag = sin(2 * k*pi / n);
//
//	//��Ϊ�������⣬�����ֶ���������0��ȡ��Ϊ0
//	if (abs(real) < 1e-15) real = 0;
//	if (abs(imag) < 1e-15) imag = 0;
//	complex<double> res(real, imag);
//	return res;
//}
//
////ת��Ϊ������ʽ
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
////ת��Ϊ�ַ��������ʽ
//void toCharArr(vector<complex<double>> &a, char * b) {
//	int len = a.size();
//	for (int i = 0; i < len; i++) {
//		b[i] = abs(a[i]) + '0';		//��⸴����ģ
//	}
//}
//
////����vector����Ԫ�ض�Ӧ������ˣ�����vector�ȳ�
//vector<complex<double>> Vec_multi(vector<complex<double>>&a1, vector<complex<double>> &a2) {
//	int len = a1.size();
//	vector<complex<double>> res(len);
//	for (int i = 0; i < len; i++) {
//		res[i] = a1[i] * a2[i];
//	}
//	return res;
//}
//
////����n���뵽��Ӧ��2�Ĵ���
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
////��һ�����Ȳ���2���ݴε���ת��Ϊ2���ݳ���, ����ֵ�ǲ���������ĳ���
////����˵���� Դ���飬 Դ���鳤�ȣ� Ŀ�����飬 Ҫ��䵽�ĳ���
//int conversion(char a[], int len_a, char res[], int para) {			//C++�����ڲ������������ں�������ʱ�ͻᱻ���٣���ʹ����������ָ��Ҳû����
//	int len = compensation(len_a);		//���䵽2����
//	//para��ָ���Ĳ�ȫ���ȣ������Ϊ0 ����para��ָ����������ȫ(��Ԥ�����У��Ѿ�ȷ��para�ĳ��ȴ���len_a)������ȫ��len
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
//		res[i] = ceil(abs(a[i]) - 0.5);			//����ȡ������������
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
////��ӡ�ַ�����
//void showCharArr(char a[]) {
//	//cout << "the char arr is: \n";
//	int len = strlen(a);
//	int begin = -1;
//	for (int i = 0; i < len; i++) {		//�ҵ���һλ��0λ��index
//		if (a[i] != '0') {
//			begin = i;
//			break;
//		}
//	}
//	//������ȫΪ0��������ĸ�ֵ���û��ִ�У����ӡ0
//	if (begin == -1) {
//		printf("%c\n", '0');
//		return;
//	}
//	for (int i = begin; i < len; i++) printf("%c", a[i]);
//	printf("\n");
//}
//
////��ӡ����
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
//	int idx = len - 1;		//�Ӻ���ǰ������ַ�����
//
//	for (int i = 0; i < len; i++) {
//		//��ÿһλ����ʮ�Ĳ��ֽ�λ����֤ÿһλ��һλʮ������
//		if(i < len -1) 
//			src[i + 1] += src[i] / 10;
//		res[idx] = (src[i] % 10) + '0';
//		idx--;
//	}
//}