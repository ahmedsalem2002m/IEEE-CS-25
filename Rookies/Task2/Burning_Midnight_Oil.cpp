#include <iostream>

using namespace std;

bool canWrite(int v, int n, int k) {
    long long sum = 0, current = v;
    while (current > 0) {
        sum += current;
        current /= k;  
        if (sum >= n) return true; 
    }
    return sum >= n;
}

int main() {
    int n, k;
    cin >> n >> k;

    int left = 1, right = n, answer = n;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (canWrite(mid, n, k)) {
            answer = mid;  
            right = mid - 1; 
        } else {
            left = mid + 1;   
        }
    }

    cout << answer;
    return 0;
}
