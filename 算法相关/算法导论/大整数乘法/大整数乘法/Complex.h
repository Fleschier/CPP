//#ifndef __COMPLEX_H__
//#define __COMPLEX_H__
//#include<iostream>
//
//using namespace std;
//
//class Complex {
//public:
//	Complex(double real, double image)
//		:_real(real)
//		, _image(image)
//	{
//	}
//	Complex operator + (const Complex& c);
//	Complex operator - (const Complex& c);
//	Complex operator * (const Complex& c);
//	Complex operator / (const Complex& c);
//
//	Complex& operator += (const Complex& c);
//	Complex& operator -= (const Complex& c);
//	Complex& operator *= (const Complex& c);
//	Complex& operator /= (const Complex& c);
//
//	Complex& operator = (const Complex& c);
//	bool operator != (const Complex& c);
//	bool operator == (const Complex& c);
//	//输出指定复数
//	void PrintComplex() {
//		cout << _real << "+" << "(" << _image << "i" << ")\n" << endl;
//	}
//private:
//	double _real;
//	double _image;
//};
//
//#endif //__COMPLEX_H__