#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int luckyNumbers[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};

    bool isAlmostLucky = false;

    int size = sizeof(luckyNumbers) / sizeof(luckyNumbers[0]);

    for (int i = 0; i < size; i++) {
        if (n % luckyNumbers[i] == 0) {
            isAlmostLucky = true;
            break;
        }
    }

    if (isAlmostLucky) {
        cout << "YES" ;
    } else {
        cout << "NO" ;
    }

    return 0;
}
