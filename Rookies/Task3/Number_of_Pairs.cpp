#include <iostream>
#include <algorithm>
using namespace std;

long long count_pairs(int a[], int n, int l, int r) {
    sort(a, a + n);
    long long count = 0;

    for (int i = 0; i < n - 1; i++) {
        int low = l - a[i];
        int high = r - a[i];

        int left = lower_bound(a + i + 1, a + n, low) - a;
        int right = upper_bound(a + i + 1, a + n, high) - a;

        count += (right - left);
    }

    return count;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;

        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        cout << count_pairs(a, n, l, r);
    }

    return 0;
}
