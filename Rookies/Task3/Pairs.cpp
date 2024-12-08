#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int pairs(int k, vector<int>& arr) {

    sort(arr.begin(), arr.end());
    int left = 0, right = 1;
    int count = 0;
    
    while (right < arr.size()) {
        int diff = arr[right] - arr[left];
        
        if (diff == k) {
            count++;
            left++;
            right++;
        } else if (diff < k) {
            right++;
        } else {
            left++;
        }
    }
    
    return count;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << pairs(k, arr);
    return 0;
}
