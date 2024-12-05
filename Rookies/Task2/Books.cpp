#include <iostream>
#include <vector>

using namespace std;

bool canReadBooks(int a[], int n, int time, int mid) {
    int sum = 0;
    for (int i = 0; i < mid; i++) {
        sum += a[i];
    }
    if (sum <= time) return true;

    for (int i = mid; i < n; i++) {
        sum += a[i] - a[i - mid];
        if (sum <= time) return true;
    }
    return false;
}

int main() {
    int n, time;
    cin >> n >> time;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int left = 0, right = n-1, maxBooks = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (canReadBooks(a, n, time, mid)) {
            maxBooks = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << maxBooks ;

    return 0;
}
