#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int t[n]; 
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    
    int alice_time = 0, bob_time = 0;
    int alice_count = 0, bob_count = 0;
    int left = 0, right = n - 1;
    
    while (left <= right) {
        if (alice_time <= bob_time) {
            alice_time += t[left];
            alice_count++;
            left++;
        } else {
            bob_time += t[right];
            bob_count++;
            right--;
        }
    }
    
    cout << alice_count << " " << bob_count;
    
    return 0;
}
