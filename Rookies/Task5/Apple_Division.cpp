#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long findMinDifference(int idx, long long group1, long long group2, const int weights[], int n) {
    if (idx == n) {
        return abs(group1 - group2);
    }
    long long option1 = findMinDifference(idx + 1, group1 + weights[idx], group2, weights, n);
    long long option2 = findMinDifference(idx + 1, group1, group2 + weights[idx], weights, n);
    return min(option1, option2);
}

int main() {
    int n;
    cin >> n;

    int weights[20];
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    long long min_difference = findMinDifference(0, 0, 0, weights, n);
    cout << min_difference << endl;

    return 0;
}
