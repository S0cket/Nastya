#include <iostream>
#include <map>
#include <time.h>
#include <stdlib.h>

using namespace std;

void mapprint(multimap<int, double> mp) {
	cout << "Map:" << endl;
	for (multimap<int, double>::iterator iter = mp.begin(); iter != mp.end(); ++ iter)
		cout << iter->first << ":" << iter->second << endl;
}

int main(void) {
	srand(time(NULL));

	int n;
	multimap<int, double> mp;
	cin >> n;
	for (int i = 0; i < n; ++ i)
		mp.insert(pair<int, double>(i, rand() % 100));
	mapprint(mp);

//1
	cout << "1:" << endl;
	auto mx = mp.begin();
	for (auto iter = ++mp.begin(); iter != mp.end(); ++ iter)
		if (iter->second > mx->second)
			mx = iter;
	cout << "Max = " << mx->first << ":" << mx->second << endl;

//2
	cout << endl << "2:" << endl;
	auto mn = mp.begin();
	for (auto iter = ++mp.begin(); iter != mp.end(); ++ iter)
		if (iter->second < mn->second)
			mn = iter;
	cout << "Min = " << mn->first << ":" << mn->second << endl;
	mp.erase(mn);
	mapprint(mp);

//3
	cout << endl << "3:" << endl;
	double s = 0;
	for (auto iter = mp.begin(); iter != mp.end(); ++ iter)
		s += iter->second;
	s /= mp.size();
	cout << "Srednee: " << s << endl;
	for (auto iter = mp.begin(); iter != mp.end(); ++ iter)
		iter->second += s;
	mapprint(mp);

	return 0;
}