#include <iostream>

using namespace std;

class Int {
private:
	int value;
public:
	Int() {
		this->value = 0;
	}
	Int(int value) {
		this->value = value;
	}
	void Null() {
		this->value = 0;
	}
	void Set(int value) {
		this->value = value;
	}
	int Get() {
		return this->value;
	}
	void Print() {
		cout << "Int:" << this->value << endl;
	}
	void Add(Int n) {
		this->value += n.Get();
	}
	~Int() {}
};

int main(void) {
	Int a, b(5), c(6);
	a.Print();
	b.Print();
	c.Print();

	a.Set(4);
	b.Add(a);
	b.Print();
	b.Add(c);
	b.Print();
	return 0;
}