//#include<iostream>
//#include"Complex.h"
//
//using namespace std;
//
//
//bool Complex::operator==(const Complex& c) {
//	return ((_real == c._real) && (_image == c._image));
//}
//
//bool Complex::operator!=(const Complex& c) {
//	return !(*this == c);
//}
//Complex& Complex::operator=(const Complex& c) {
//	_real = c._real;
//	_image = c._image;
//	return *this;
//}
//
//
////(a+bi)+(c+di)=(a+c)+(b+d)i
//Complex Complex::operator+(const Complex& c) {
//	Complex temp(*this);
//	temp._real = _real + c._real;
//	temp._image = _image + c._image;
//	return temp;
//}
////(a+bi)-(c+di)=(a-c)+(b-d)i
//Complex Complex::operator-(const Complex& c) {
//	Complex temp(*this);
//	temp._real = _real - c._real;
//	temp._image = _image - c._image;
//	/*if(temp._image)*/
//	return temp;
//}
////(a+bi)(c+di)=(ac-bd)+(bc+ad)i
//Complex Complex::operator*(const Complex& c) {
//	Complex temp(*this);
//	temp._real = (_real * c._real) - (_image * c._image);
//	temp._image = (_image * c._real) + (_real * c._image);
//	return temp;
//}
////(a+bi)/(c+di)=(ac+bd)/(c^2+d^2) +(bc-ad)/(c^2+d^2)i
//Complex Complex::operator/(const Complex& c) {
//	Complex temp(*this);
//	temp._real = ((_real * c._real) + (_image * c._image)) / ((c._real * c._real) + (c._image * c._image));
//	temp._image = ((_image * c._real) - (_real * c._image)) / ((c._real * c._real) + (c._image * c._image));
//	return temp;
//}
//
//Complex& Complex::operator+=(const Complex& c) {
//	_real = _real + c._real;
//	_image = _image + c._image;
//	return *this;
//}
//
//Complex& Complex::operator-=(const Complex& c) {
//	_real = _real - c._real;
//	_image = _image - c._image;
//	return *this;
//}
//
//Complex& Complex::operator*=(const Complex& c) {
//	Complex temp(*this);
//	temp._real = (_real * c._real) - (_image * c._image);
//	temp._image = (_image * c._real) + (_real * c._image);
//	_real = temp._real;
//	_image = temp._image;
//	return *this;
//}
//
//Complex& Complex::operator/=(const Complex& c) {
//	Complex temp(*this);
//	temp._real = ((_real * c._real) + (_image * c._image)) / ((c._real * c._real) + (c._image * c._image));
//	temp._image = ((_image * c._real) - (_real * c._image)) / ((c._real * c._real) + (c._image * c._image));
//	_real = temp._real;
//	_image = temp._image;
//	return *this;
//}