
#include <iostream>
#include <math.h>
 
using namespace std;
 
 
class Complex // ����� ����������� �����
{
    double re, im; // ����� � ������ �����
 
    // ������� ������������   
    public:
 
    Complex() {};
 
    Complex (double r)
    {
        re = r; 
        im = 0;
    }
 
    Complex (double r, double i)
    {
        re = r; 
        im = i;
    } 
 
    Complex (Complex &c) // ����������� �����������
    {
        re = c.re; 
        im = c.im;
    }
 
    ~Complex() {}
 
    float fabs() // ������ ������������ �����
    {
        return sqrt(re * re - im * im);
    }     
 
    Complex & operator = (Complex &c) // ���������� ��������� ������������
    {
        re = c.re;
        im = c.im;
 
        return (*this);
    }
 
    Complex operator + (Complex &c) // ���������� ��������� ��������
    {
      Complex temp;
 
        temp.re = re + c.re;
        temp.im = im + c.re;
 
        return temp;
    }  
 
    Complex operator - (Complex &c) // ���������� ��������� ���������
    {
        Complex temp;
 
        temp.re = re - c.re;
        temp.im = im - c.re;
 
        return temp;
    }
 
    Complex operator * (Complex &c) // ���������� ��������� ���������
    {
        Complex temp;
 
        temp.re = re*c.re;
        temp.im = re*c.im;
 
        return temp;
    }
 
    Complex operator / (Complex &c) // ���������� ��������� �������
    {
        Complex temp;
 
        double r = c.re * c.re + c.im * c.im;
        temp.re = (re * c.re + im * c.im) / r;
        temp.im = (im * c.re - re * c.im) / r;
 
        return temp;
    }   
 
    friend ostream &operator<<(ostream &, const Complex &); // ���������� ��������� <<
    friend istream &operator>>(istream &, const Complex &); // ���������� ��������� >>
 
};
 
ostream &operator<<(ostream &out, const Complex &c)
{
    out << c.re;
    if( c.im > 0 )
        out << "+";
    out << c.im << "i";
 
    return out;
}
 
istream &operator>>(istream &in, const Complex &c)
{
    in >> c.re >> c.im;
 
    return in;
}