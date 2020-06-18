#include <iostream>

using namespace std;

int main(void) {
	int h, m, s;
	cin >> h >> m >> s;
	cout << (3600 * h + 60 * m + s) << endl;
	return 0;
}
