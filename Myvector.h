#include <iostream>
using namespace std;
template<typename T>
class MyVector {
private:
	T m_array[1000];
	int m_size;
public:
	~MyVector() {};
	MyVector(int siz = 0):m_size(siz){};
	MyVector(int siz, T n) {
		this->m_size = siz;
		for (int i = 0; i < siz; i++)
		{
			m_array[i] = n;
		}
	};
	MyVector(const MyVector& myvector) {
		this->m_size = myvector.m_size;
		for (int i = 0; i < myvector.m_size; i++)
		{
			m_array[i] = myvector.m_array[i];
		}
	};
	MyVector & operator=(const MyVector&myvector) {
		this->m_size = myvector.m_size;
		for (int i = 0; i < m_size; i++)
		{
			m_array[i] = myvector.m_array[i];
		}
		return *this;
	}
	inline const int getsize() const {
		return this->m_size;
	}
	void resize(int siz, const T& t) {
		if (siz > this->m_size) {
			for (int i = m_size; i < siz; i++) {
				m_array[i] = t;
			}
		}
		else if (siz < this->m_size) {
			for (int i = m_size; i>siz; i--)
				m_array[i-1] = m_array[i];
		}
		this->m_size = siz;
	}
	void resize(int siz) {
         if (siz < this->m_size) {
			for (int i = m_size; i>siz; i--)
				m_array[i - 1] = m_array[i];
		}
		this->m_size = siz;
	}
	inline bool empty()const {
		return (this->m_size == 0) ?  true : false;
	}
	inline T & operator[](int t) {
		return m_array[t];
	}
	inline const T& operator[](int t)const {
		return m_array[t];
	}
	T& at(int t) {
			if (t >= m_size) throw out_of_range("out_of_range");
			else return m_array[t];
	}
	const T& at(int t)const {
		if (t >= m_size) throw out_of_range("out_of_range");
		else return m_array[t];
	}
	T &back() {
		if (this->m_size == 0) throw length_error("length_error");
		return m_array[m_size - 1];
	}
	const T&back()const {
		if (this->m_size == 0) throw length_error("length_error");
		return m_array[m_size - 1];
	}
	T &front() {
		if (this->m_size == 0) throw length_error("length_error");
		return m_array[0];
	}
	const T &front()const{
		if (this->m_size == 0) throw length_error("length_error");
		return m_array[0];
	}
	void push_back(const T& t) {
		this->m_size++;
		m_array[m_size - 1] = t;
	}
	void push_back(T& t) {
		this->m_size++;
		m_array[m_size - 1] = t;
	}
	void pop_back() {
		m_array[m_size - 1] = m_array[m_size];
		this->m_size--;
	}
	void insert(int i, const T& t) {
		for (int j = m_size; j > i; j--)
			m_array[j] = m_array[j - 1];
		m_array[i] = t;
		this->m_size++;
	}
	void insert(int i, int num, const T& t) {
		for (int j = i; j < m_size; j++) {
			m_array[j + num] = m_array[j];
		}
		for (int k = i; k < i + num; k++) {
			m_array[k] = t;
		}
	}
	void erase(int i) {
		for (int j = i; j < m_size-1; j++)
		{
			m_array[j] = m_array[j+1];
		}
		this->m_size--;
	}
	void clear() {
		for (int i = m_size; i > 0; i--) {
			m_array[i - 1] = m_array[i];
		}
		this->m_size = 0;
	}
	void sort(){
		T in;
		for (int i = 0; i < m_size; i++)
			for (int j = 0; j < m_size - i - 1; j++) {
				if (m_array[j] > m_array[j + 1]) {
					in = m_array[j];
					m_array[j] = m_array[j + 1];
					m_array[j + 1] = in;
				}
			}
	}
	int binarySearch(const T& key) {
		if (this->m_size == 0) throw length_error("length_error");
		this->sort();
		int high = m_size - 1, low = 0, mid = -1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (key < m_array[mid]) high = mid - 1;
			else if (key > m_array[mid]) low = mid + 1;
			else { 
				return mid; }
		}
		if (!(m_array[mid] == key)) mid = -1;
		return mid;
	}
	void show(){
		for (int i = 0; i < m_size; i++) {
			cout << m_array[i]<<"    ";
			if (i == m_size-1) cout << endl;
		}
	}
};