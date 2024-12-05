#include <iostream>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    int x[n];
    
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    long  long group = 0;
    int j = 0;

    for (int i = 0; i < n; i++) {
        while (j < n && x[j] - x[i] <= d) {
            j++;
        }
        int count = j - i - 1;
        if (count >= 2) {
            group += (long long)count * (count - 1) / 2;
        }
    }
    
    cout << group;
    return 0;
}
