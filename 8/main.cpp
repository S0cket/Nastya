#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class ochered {
private:
	vector<int> arr;
	int n;
public:
	ochered() {
		n = 10;
	}
	ochered(int a) {
		n = a;
	}

	void push(int a) {
		if (arr.size() == n) throw 1;
		arr.push_back(a);
	}
	void pop() {
		if (arr.size() == 0) throw 2;
		arr.erase(arr.begin());
	}
	int top() {
		if (arr.size() == 0) throw 2;
		return arr[0];
	}
	void operator()(int a) {
		if (arr.size() > a) throw 3;
		n = a;
	}
	int& operator[](int index) {
		if (index < 0) throw 4;
		if (index >= arr.size()) throw 5;
		return arr[index];
	}
	void operator+(int a) {
		for (int i = 0; i < arr.size(); ++ i) {
			arr[i] += a;
		}
	}
	void operator-(int a) {
		int b = arr.size();
		int m = min(a, b);
		for (int i = 0; i < m; ++ i)
			arr.erase(arr.begin());
	}
	void print() {
		cout << "Max Size = " << n << endl;
		for (int i = 0 ; i < arr.size(); ++ i)
			cout << arr[i] << " ";
		cout << endl;
	}
	~ochered() {}
};

int main(void) {
	ochered a(3);
	a.push(1);
	a.push(2);
	a.push(3);
	a.print();
	a.pop();
	a.print();
	a + 4;
	a.print();
	a - 100;
	a.print();
	try {
		a.push(4);
		a.push(4);
		a.push(4);
		a.push(4);
	}
	catch (int) {
		cout << "Error!!!" << endl;
	}
	return 0;
}