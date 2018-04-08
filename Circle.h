#include<iostream>
#include "Point.h"
using namespace std;
class Circle{
	double m_r;
	Point m_point;
public:
	~Circle() {};
	Circle() {};
	Circle(Point po, double ra);
	Circle(Circle &cir);
	Circle&operator=(const Circle& cir);
	bool operator==(const Circle& cir)const;
	bool operator<(const Circle& cir)const;
	bool operator>(const Circle& cir)const;
	friend ostream &operator<<(ostream &os, const Circle &c);
};
