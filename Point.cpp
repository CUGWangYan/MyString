#include "Point.h"
Point::Point(int x , int y ): m_X(x),m_Y(y){
}
Point::Point(Point &po) {
	this->m_X = po.m_X;
	this->m_Y = po.m_Y;
}
Point&Point::operator=(const Point &po) {
	this->m_X = po.m_X;
	this->m_Y = po.m_Y;
	return *this;
}
ostream &operator<<(ostream &os, const Point &p) {
	os << "(" << p.m_X << "," << p.m_Y << ")";
	return os;
}