#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
    public:
    Complex(const double re = 0, const double im = 0);
    Complex(const Complex& c);
    Complex& operator=(const Complex& c);
    Complex Polar(const double leng, const double arg);
    double Real();
    double Imag();
    double Norm();
    double Abs();
    double Arg();
    Complex operator++();
    Complex operator++(int);
    Complex operator--();
    Complex operator--(int);
    ~Complex();
    friend Complex Polar(const double leng, const double arg); //not friend function
    friend double Norm(const Complex& x);
    friend double Abs(const Complex& x);
    friend double Arg(const Complex& x);
    friend Complex operator+(const Complex& x, const Complex& y);
    friend Complex operator-(const Complex& x, const Complex& y);
    friend Complex operator*(const Complex& x, const Complex& y);
    friend Complex operator/(const Complex& x, const Complex& y);
    friend Complex operator+=(Complex& x, const Complex& y);
    friend Complex operator-=(Complex& x, const Complex& y);
    friend Complex operator*=(Complex& x, const Complex& y);
    friend Complex operator/=(Complex& x, const Complex& y);
    friend bool operator==(const Complex& x, const Complex& y);
    friend bool operator!=(const Complex& x, const Complex& y);
    friend ostream& operator<<(ostream& o, const Complex& x);
    private:
    double real;
    double imag;
};
Complex Polar(const double leng, const double arg);

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
	return atan2(imag,real);
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
	return atan2(x.imag,x.real);
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
	return Complex(((x*tmp).real)/(Norm(tmp)),((x*tmp).imag)/(Norm(tmp)));
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
	Complex tmp(y.real , 0 - y.imag);
	Complex t(x);
	x.real = ((t*tmp).real)/Norm(tmp);
	x.imag = ((t*tmp).imag)/Norm(tmp);
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

int main()
{
    Complex a(77, 66.3);
    Complex b(a);
    int i = 1;

    cout << i++ << ": (" << a.Real() << ',' << a.Imag() << ')' << endl;
    cout << i++ << ": " << b << endl;
    cout << i++ << ": " << Norm(b) << endl;
    cout << i++ << ": " << b.Norm() << endl;
    cout << i++ << ": " << Abs(b) << endl;
    cout << i++ << ": " << b.Abs() << endl;
    cout << i++ << ": " << Arg(b) << endl;
    cout << i++ << ": " << b.Arg() << endl;

    a = Complex(12, 33.2);
    cout << i++ << ": " << a << endl;
    cout << i++ << ": " << 1 + a << endl;

    cout << i++ << ": " << a++ << endl;
    cout << i++ << ": " << ++a << endl;

    b = a.Polar(5.6, 1.8);

    cout << i++ << ": " << a << endl;
    cout << i++ << ": " << b << endl;

    b = Polar(6.5, 8.1);
    cout << i++ << ": " << b << endl;

    cout << i++ << ": " << a + b << endl;
    cout << i++ << ": " << a - b << endl;
    cout << i++ << ": " << a * b << endl;
    cout << i++ << ": " << a / b << endl;

    a /= b;
    cout << i++ << ": " << a << endl;
    a /= Complex(4, 3);
    cout << i++ << ": " << a << endl;

    a *= b;
    cout << i++ << ": " << a << endl;
    a *= Polar(5.1, 5.1);
    cout << i++ << ": " << a << endl;

    a += b;
    b -= a;
    cout << i++ << ": " << b << endl;

    if (!(a == b))
        cout << i++ << ": "
             << "OK" << endl;
    if (a != b)
        cout << i++ << ": "
             << "OK" << endl;
}