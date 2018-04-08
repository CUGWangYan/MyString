#include "Fraction.h"
ostream& operator<<(ostream& os, Fraction&f)
{
	f.Simplification(f);
		os<< f.m_above << "/" << f.m_below ;
	return os;
}
Fraction::Fraction(int a, int b)
{
	while (b == 0)
	{
		cout << "Error" << endl;
		cin >> b;
	}
	this->m_above =a;
	this->m_below =b;
}
void Fraction::Simplification(Fraction&f)
{
	int a = m_above ,b=m_below;
	int r = a%b;
	while (r)
	{
		a = b;
		b = r;
		r = a%b;
	}
	m_above /= b;
	m_below /= b;
}
Fraction Fraction::operator+(const Fraction &f)const
{
	Fraction temp;
		temp.m_above = abs(m_above*f.m_below - m_below*f.m_above);
		temp.m_below = abs(m_below*f.m_below);
	return temp;
}
void Fraction::Show()
{
	cout << *this;
}
Fraction Fraction::operator-(const Fraction&f)const
{
	Fraction temp;
		temp.m_above = abs(m_above*f.m_below - m_below*f.m_above);
		temp.m_below = m_below*f.m_below;
	return temp;
}
Fraction Fraction::operator*(const Fraction &f)const
{
	Fraction temp;
	temp.m_above = m_above*f.m_above;
	temp.m_below = m_below*f.m_below;
	return temp;

}
Fraction Fraction::operator/(const Fraction&f)const
{
	Fraction temp;
	temp.m_above = f.m_below*this->m_above;
	temp.m_below = f.m_above*this->m_below;
	return temp;
}
Fraction Fraction::GetReciprocal()
{
	Fraction temp;
	temp.m_below = m_above;
	temp.m_above = m_below;
	return temp;
}
bool Fraction::operator==(const Fraction &f)const
{
	if (this->m_above*f.m_below==this->m_below*f.m_above)
		return true;
	else
		return false;
}
bool Fraction::operator<(const Fraction &f)const
{

		if (this->m_above*f.m_below<f.m_above*this->m_below)
				return true;
			else
				return false;
}
bool Fraction::operator>(const Fraction& f)const
{
	return (f<*this);
}