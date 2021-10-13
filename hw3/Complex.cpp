#include "Complex.h"
#include <cmath>

Complex::Complex(const double re, const double im)
{
	real=re;
	imag=im;
}

Complex::Complex(const Complex& c)
{
	real=c.real;
	imag=c.imag;
}

Complex& Complex::operator=(const Complex& c)
{
	this->real=c.real;
	this->imag=c.imag;
	return *this;
}

Complex Complex::Polar(const double leng, const double arg)
{
	real=leng*cos(arg);
	imag=leng*sin(arg);
	return Complex(real,imag);
}

double Complex::Real()
{
	return real;
}

double Complex::Imag()
{
	return imag;
}

double Complex::Norm()
{
	return pow(real,2)+pow(imag,2);
}

double Complex::Abs()
{
	return sqrt(Norm());
}

double Complex::Arg()
{
	return atan(imag/real);
}

Complex Complex::operator++()
{
	real++;
	imag++;
	return Complex(real,imag);
}

Complex Complex::operator++(int)
{
	double r=real++;
	double i=imag++;
	return Complex(r,i);
}

Complex Complex::operator--()
{
	real--;
	imag--;
	return Complex(real,imag);
}

Complex Complex::operator--(int)
{
	double r=real--;
	double i=imag--;
	return Complex(r,i);
}

Complex::~Complex(){}

Complex Polar(const double leng, const double arg)
{
	return Complex(leng*cos(arg),leng*sin(arg));
}

double Norm(const Complex& x)
{
	return x.real*x.real+x.imag*x.imag;
}

double Abs(const Complex& x)
{
	return sqrt(Norm(x));
}

double Arg(const Complex& x)
{
	return atan(x.imag/x.real);
}

Complex operator+(const Complex& x, const Complex& y)
{
	return Complex(x.real+y.real , x.imag+y.imag);
}

Complex operator-(const Complex& x, const Complex& y)
{
	return Complex(x.real-y.real , x.imag-y.imag);
}

Complex operator*(const Complex& x, const Complex& y)
{
	return Complex(x.real*y.real-x.imag*y.imag , x.real*y.imag+x.imag*y.real);
}

Complex operator/(const Complex& x, const Complex& y)
{
	Complex tmp=Complex(y.real,0-y.imag);
	return Complex(((x*tmp).real)/Norm(tmp),((x*tmp).imag)/Norm(tmp));
}

Complex operator+=(Complex& x, const Complex& y)
{
	x.real=x.real+y.real;
	x.imag=x.imag+y.imag;
	return x;
}

Complex operator-=(Complex& x, const Complex& y)
{
	x.real=x.real-y.real;
	x.imag=x.imag-y.imag;
	return x;
}

Complex operator*=(Complex& x, const Complex& y)
{
	double tmp=x.real*y.real-x.imag*y.imag;
    	x.imag=x.real*y.imag+x.imag*y.real;
    	x.real=tmp;
	return x;
}

Complex operator/=(Complex& x, const Complex& y)
{
	double tmp=(x.real*y.real+x.imag*y.imag)/Norm(y);
	x.imag=(x.imag*y.real-x.real*y.imag)/Norm(y);
	x.real=tmp;
	return x;
}

bool operator==(const Complex& x, const Complex& y)
{
	return x.real==y.real&&x.imag==y.imag;
}

bool operator!=(const Complex& x, const Complex& y)
{
	return x.real!=y.real||x.imag!=y.imag;
}

ostream& operator<<(ostream& o, const Complex& x)
{
	o<<"("<<x.real<<","<<x.imag<<")";
	return o;
}

