#include<iostream>
using namespace std;
class Fraction
{
private:
	int m_above;
	int m_below;
public:
	Fraction(int a = 0,int b = 1);
	~Fraction(){};
	void Simplification(Fraction&f);
	void Show();
	friend ostream& operator<<(ostream& os,Fraction & f);
	Fraction operator+(const Fraction&f)const;
	Fraction operator-(const Fraction&f)const;
	Fraction operator*(const Fraction&f)const;
	Fraction operator/(const Fraction&f)const;
	bool operator==(const Fraction&f)const;
	bool operator>(const Fraction&f)const;
	bool operator<(const Fraction&f)const;
	Fraction GetReciprocal();
};