#include "Circle.h"
Circle::Circle(Point po, double ra) {
	m_point = po;
	m_r = ra;
}
Circle::Circle(Circle &cir) {
	this->m_r = cir.m_r;
	this->m_point = cir.m_point;
}
Circle&Circle::operator=(const Circle& cir) {
	this->m_r = cir.m_r;
	this->m_point = cir.m_point;
	return *this;
}
bool Circle::operator==(const Circle& cir)const {
	if (this->m_r == cir.m_r) return false;
	else return true;
}
bool Circle::operator<(const Circle& cir)const {
	if (this->m_r > cir.m_r)
		return false;
	else return true;
}
bool Circle::operator>(const Circle& cir)const {
	if (this->m_r > cir.m_r)
		return true;
	else return false;
}
ostream &operator<<(ostream &os, const Circle &c) {
	os << "(" << c.m_point << "," << c.m_r << ")";
	return os;
}