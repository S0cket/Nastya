#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Vector {
public:
	vector<T> v;
	Vector() {}
	Vector(int a, T b) {
		v = vector<T>(a, b);
	}
	Vector(vector<T> t) {
		v = t;
	}

	int size() {
		return v.size();
	}
	void operator()(int a) {
		v.resize(a);
	}
	T& operator[](int i) {
		return v[i];
	}
	Vector operator+(int n) {
		vector<T> a = v;
		for (int i = 0; i < a.size(); ++ i)
			a[i] += n;
		return Vector<T>(a);
	}


	~Vector() {}
};

class Time {
public:
	int m, s;
	Time() {
		m = 0;
		s = 0;
	}
	Time(int s_) {
		m = s_ / 60;
		s = s_ % 60;
	}
	Time(int m_, int s_) {
		m = m_ + s_ / 60;
		s = s_ % 60;
	}
	void print() {
		cout << m << ":" << s << endl;
	}
	~Time() {}
};

int main(void) {
	Vector<int> a(3, 0);
	return 0;
}