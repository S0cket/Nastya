#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    if (n < 1 || n > 7) {
        cout << "Error" << endl;
        return 1;
    }
    switch (n) {
        case 6:
        cout << "Weekend" << endl;
        break;

        case 7:
        cout << "Weekend" << endl;
        break;

        default:
        cout << "Workday" << endl;
        break;
    }
    return 0;
}
