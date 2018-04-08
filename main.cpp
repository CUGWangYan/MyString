#include "Myvector.h"
#include "Fraction.h"
#include "Circle.h"
#include <string>
template<typename Vector,typename DataType>
void test(Vector& v, const DataType& val) {
	v.show();
	cout << v.at(0) << endl;
	v.push_back(val);
	v.show();
	v.sort();
	v.show();
	cout << v.binarySearch(val) << endl;
	v.erase(0);
	v.show();
	v.insert(0,val);
	v.show();
	v.insert(0, 2, val);
	v.show();
	cout<<v.getsize()<<endl;
	v.resize(10, val);
	v.show();
	cout<<v.empty()<<endl;
	cout << v.front() << endl;
	cout << v.back() << endl;
	v.pop_back();
	v.show();
	v.clear();
}
int main() {
	MyVector<int> v(10);
	MyVector<int> vi(5,1);
	vi[0] = -1;
	vi[1] = 3;
	vi[2] = 9;
	vi[3] = -5;
	MyVector<string> vs(5,"c");
	vs[0] = "Java";
	vs[1] = "Lisp";
	vs[2] = "c#";
	vs[3] = "Object-c";
	MyVector<Fraction> vf(5, Fraction(1, 2));
	vf[0] = Fraction(2, 3);
	vf[1] = Fraction(2, 3);
	vf[2] = Fraction(2, 5);
	vf[3] = Fraction(4, 7);
	MyVector<Circle> vc(5, Circle(Point(), 1.0));
	vc[0] = Circle(Point(), 2.0);
	vc[1] = Circle(Point(), 1.0);
	vc[2] = Circle(Point(), 5.0);
	vc[3] = Circle(Point(), 0.1);
	test<MyVector<int>, int>(vi, 10);
	test<MyVector<string>, string>(vs, "C++");
	test<MyVector<Fraction>, Fraction>(vf, Fraction(7, 10));
	test<MyVector<Circle>, Circle>(vc, Circle(Point(), 3.0));
	return 0;
}