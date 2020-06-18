#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string s;
	getline(cin, s);
	int cnt = 0, n = 0;
	for (int i = 0; i < s.size(); ++ i) {
		if (s[i] == ' ') {
			if (n == 5)
				++ cnt;
			n = 0;
		}
		else {
			++ n;
		}
	}
	if (n == 5)
		++ cnt;
	cout << cnt << endl;
	return 0;
}