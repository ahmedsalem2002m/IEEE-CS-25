#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int skills[n];
    
    for (int i = 0; i < n; i++) {
        cin >> skills[i];
    }
    
    sort(skills, skills + n);
    
    int max_team_size = 1;
    int left = 0;
    
    for (int right = 0; right < n; right++) {
        while (skills[right] - skills[left] > 5) {
            left++;
        }
        max_team_size = max(max_team_size, right - left + 1);
    }
    
    cout << max_team_size;
    
    return 0;
}
