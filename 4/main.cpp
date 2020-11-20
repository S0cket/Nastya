#include <iostream>
#include <math.h>

using namespace std;
#define PI 3.14159265

class Complex {
//z = x+yi
public:
	double x, y;
	Complex() {
		this->x = 0;
		this->y = 0;
	}
	Complex(double x, double y) {
		this->x = x;
		this->y = y;
	}
	double mod() {
		return sqrt(this->x * this->x + this->y * this->y);
	}
	void print(bool verbose = true) {
		if (verbose) {
			cout << x;
			if (y < 0)
				cout << "-";
			else
				cout << "+";
			cout << fabs(y) << "i\n";
		}
		else {
			cout << x;
			if (y < 0)
				cout << "-" << -y << "i";
			else if (y > 0)
				cout << "+" << y << "i";
			cout << "\n";
		}
	}
	Complex sopr() {
		return Complex(this->x, -this->y);
	}
	Complex srt(int n) {
		double r = mod();
		double f = atan(fabs(y / x));
		if (x > 0) {
			if (y < 0)
				f = 2 * PI - f;
		}
		else if (x == 0) {
			f = PI / 2;
		}
		else {
			if (y > 0)
				f = PI - f;
			else
				f = PI + f;
		}
		r = pow(r, 1.0 / n);
		f /= n;
		return Complex(r * cos(f), r * sin(f));
	}
	void read() {
		cout << "z=x+yi, Input x, y: ";
		cin >> x >> y;
	}

	Complex operator+(Complex c) {
		return Complex(this->x + c.x, this->y + c.y);
	}
	Complex operator-(Complex c) {
		return Complex(this->x - c.x, this->y - c.y);
	}
	Complex operator*(Complex c) {
		double x = this->x * c.x + (-1 * this->y * c.y);
		double y = this->y * c.x + this->x * c.y;
		return Complex(x, y);
	}
	Complex operator/(Complex c) {
		Complex cc = c.sopr();
		Complex num = *this * cc;
		double denom = (c * cc).x;
		return Complex(num.x / denom, num.y / denom);
	}
	Complex operator++() {
		this->x += 1;
		return *this;
	}
	Complex operator++(int a) {
		this->y += 1;
		return *this;
	}
	~Complex() {}
};

int main(void) {
	Complex a, b, c, d, R;
	a.read();
	a.print();
	b.read();
	b.print();
	c.read();
	c.print();
	d.read();
	d.print();

	R = a.srt(3) - (b + c) / a + b * d;
	R.print();
	cout << "mod = " << R.mod() << endl;
	++R;
	R++;
	R.print();
	return 0;
}