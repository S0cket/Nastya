#include <iostream>
#include <vector>
#include <deque>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <list>

using namespace std;

void print(vector<int> a) {
	for (int i = 0; i < a.size(); ++ i)
		cout << a[i] << " ";
	cout << endl;
}
void print(deque<int> a) {
	for (int i = 0; i < a.size(); ++ i)
		cout << a[i] << " ";
	cout << endl;
}
void print(list<int> a) {
	for (auto iter = a.begin(); iter != a.end(); ++ iter)
		cout << *iter << " ";
	cout << endl;
}

int main(void) {
	srand(time(NULL));

	//1
	int n;
	cin >> n;
	vector<int> a;
	deque<int> b;
	for (int i = 0; i < n; ++ i)
		a.push_back(rand() % 100);
	for (int i = 0; i < n; ++ i) {
		int x;
		cin >> x;
		b.push_back(x);
	}

	cout << "vector:\n";
	print(a);
	int vd = 0, vnd = 0;
	double vs = 0;
	for (int i = 0; i < a.size(); ++ i) {
		vs += a[i];
		if (a[i] % 2 == 0)
			vd ++;
		else
			vnd ++;
	}
	vs /= a.size();
	cout << "srednee: " << vs << ", chet: " << vd << ", nechet: " << vnd << endl;

	cout << "deque:\n";
	print(b);
	int dd = 0, dnd = 0;
	double ds = 0;
	for (int i = 0; i < b.size(); ++ i) {
		ds += b[i];
		if (b[i] % 2 == 0)
			dd ++;
		else
			dnd ++;
	}
	ds /= b.size();
	cout << "srednee: " << ds << ", chet: " << dd << ", nechet: " << dnd << endl;

	//2
	cout << endl;
	list<int> l;
	for (int i = 0; i < n; ++ i)
		l.push_back(rand() % 100);
	print(l);
	auto iter = min_element(l.begin(), l.end());
	int x = *iter;
	l.erase(iter);
	l.push_front(x);
	print(l);
	return 0;

}