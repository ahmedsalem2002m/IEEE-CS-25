#include <iostream>
using namespace std;

void simulateAlgorithm(long long n) {
    cout << n << " ";
    if (n == 1) return;
    if (n % 2 == 0) {
        simulateAlgorithm(n / 2);
    } else {
        simulateAlgorithm(3 * n + 1);
    }
}

int main() {
    long long n;
    cin >> n;
    simulateAlgorithm(n);
    return 0;
}
