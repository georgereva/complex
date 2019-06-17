
#include <iostream>
#include <math.h>

using namespace std;


class Complex
{
private:
	double re, im; // ����� � ������ �����

	// ������� ������������   
public:

	Complex() {};

	Complex(double r)
	{
		re = r;
		im = 0;
	}

	Complex(double r, double i)
	{
		re = r;
		im = i;
	}

	Complex(Complex& c) // ����������� �����������
	{
		re = c.GetRe();
		im = c.GetIm();
	}

	~Complex() {}

	float fabs() // ������ ������������ �����
	{
		return sqrt(re * re - im * im);
	}

	Complex& operator = (Complex & c) // ���������� ��������� ������������
	{
		re = c.GetRe();
		im = c.GetIm();

		return (*this);
	}

	Complex operator + (Complex & c) // ���������� ��������� ��������
	{
		Complex temp;

		temp.SetRe(re + c.GetRe());
		temp.SetIm(im + GetRe());

		return temp;
	}

	Complex operator - (Complex & c) // ���������� ��������� ���������
	{
		Complex temp;

		temp.SetRe(re - c.GetRe());
		temp.SetIm(im - c.GetRe());

		return temp;
	}

	Complex operator * (Complex & c) // ���������� ��������� ���������
	{
		Complex temp;

		temp.SetRe(re * c.GetRe());
		temp.SetIm(re * c.GetRe());

		return temp;
	}

	Complex operator / (Complex & c) // ���������� ��������� �������
	{
		Complex temp;

		double r = c.GetRe() * c.GetRe(); +GetIm() * GetIm();
		temp.SetRe((re * c.GetRe() + im * c.GetIm()) / r);
		temp.SetIm((im * c.GetRe() - re * c.GetIm()) / r);

		return temp;
	}

	friend ostream & operator<<(ostream&, const Complex&); // ���������� ��������� <<
	friend istream & operator>>(istream&, const Complex&); // ���������� ��������� >>

	double GetRe()
	{
		return re;
	};
	double GetIm()
	{
		return im;
	};
	int SetRe(double newVal)
	{
		re = newVal;
		return 1;
	};
	int SetIm(double newVal)
	{
		im = newVal;
		return 1;
	};

};

ostream& operator<<(ostream & out, const Complex & c)
{
	out << c.re;
	if (c.im > 0)
		out << "+";
	out << c.im << "i";

	return out;
}

istream& operator>>(istream & in, const Complex & c)
{
	in >> c.re >> c.im;

	return in;
}
