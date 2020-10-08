#include <list>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

int main(void) {
	srand(time(NULL));

	cout << "length1 length2> ";
	int len1, len2;
	cin >> len1 >> len2;

	list<int> l1, l2, l;

	cout << "L1:" << endl;
	for (int i = 0; i < len1; i ++) {
		l1.push_back(rand() % 7);
		cout << l1.back() << " ";
	}

	cout << endl << endl << "L2:" << endl;
	for (int i = 0; i < len2; i ++) {
		l2.push_back(rand() % 7);
		cout << l2.back() << " ";
	}

	cout << endl << endl << "L:" << endl;
	for (list<int>::iterator i = l1.begin(); i != l1.end(); i ++) {
		bool flag = true;
		for (list<int>::iterator j = l2.begin(); j != l2.end(); j ++)
			if (*i == *j)
				flag = false;
		for (list<int>::iterator j = l.begin(); j != l.end(); j ++)
			if (*i == *j)
				flag = false;
		if (flag) {
			l.push_back(*i);
			cout << l.back() << " ";
		}
	}

	for (list<int>::iterator i = l2.begin(); i != l2.end(); i ++) {
		bool flag = true;
		for (list<int>::iterator j = l1.begin(); j != l1.end(); j ++)
			if (*i == *j)
				flag = false;
		for (list<int>::iterator j = l.begin(); j != l.end(); j ++)
			if (*i == *j)
				flag = false;
		if (flag) {
			l.push_back(*i);
			cout << l.back() << " ";
		}
	}
	cout << endl;
	return 0;
}