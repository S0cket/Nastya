#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Rect {
protected:
	double a;
public:
	Rect() {
		a = 1;
	}
	Rect(double a) {
		this->a = a;
	}

	double D() {
		return a * sqrt(2.0);
	}
	double P() {
		return 4 * a;
	}
	double S() {
		return a * a;
	}
	void print() {
		cout << "Rect:\n"
			<< "a: " << a << "\n"
			<< "D: " << D() << "\n"
			<< "P: " << P() << "\n"
			<< "S: " << S() << "\n\n";
	}

	~Rect() {}
};

class Prizma : public Rect {
protected:
	double h;
public:
	Prizma() {
		a = 1.0;
		h = 1.0;
	}
	Prizma(double a, double h) {
		this->a = a;
		this->h = h;
	}

	double V() {
		return a * a * h;
	}
	double S() {
		return a * 4 * h + 2 * a * a;
	}
	double D() {
		return sqrt(pow(a * sqrt(2.0), 2) + pow(h, 2));
	}

	void print() {
		cout << "Prizma:\n"
			<< "a: " << a << "\n"
			<< "h: " << h << "\n"
			<< "V: " << V() << "\n"
			<< "D: " << D() << "\n"
			<< "S: " << S() << "\n\n";
	}


	~Prizma() {}
};

int main(void) {
	int n, m;
	cin >> n >> m;
	Rect mx;
	bool flag = false;
	for (int i = 0; i < n; ++ i) {
		double a;
		cout << "Rect" << i << endl;
		cin >> a;
		if (!flag) {
			flag = true;
			mx = Rect(a);
		}
		else {
			if (mx.S() < Rect(a).S())
				mx = Rect(a);
		}
	}
	flag = false;
	Prizma mpx;
	for (int i = 0; i < m; ++ i) {
		double a, h;
		cout << "Prizma" << i << endl;
		cin >> a >> h;
		if (!flag) {
			flag = true;
			mpx = Prizma(a, h);
		}
		else {
			if (mpx.D() < Prizma(a, h).D())
				mpx = Prizma(a, h);
		}
	}
	mx.print();
	mpx.print();
	return 0;
}