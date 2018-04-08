#include <iostream>
using namespace std;
class Point {
private:
	double m_X, m_Y;
public:
	~Point() { };
	Point(int x = 0, int y = 0);
	Point(Point &po);
	Point&operator=(const Point &po);
	friend ostream &operator<<(ostream &os, const Point &p);
};
