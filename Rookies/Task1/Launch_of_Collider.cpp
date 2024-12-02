#include <iostream>

using namespace std;

int main()
{
    int number;
    cin >> number;
    char direction[number];
    int location[number];
    int time = 1e9;
    for(int i = 0;i<number;i++){
        cin >> direction[i];
    }
    for(int i = 0;i<number;i++){
        cin >> location[i];
    }
    for(int i = 0;i<number-1;i++){
        if(direction[i] == 'R' && direction[i+1] == 'L'){
             time = min(time,(location[i+1]-location[i])/2);
        }
    }
    if(time == 1e9)
        cout << -1;
        else
            cout << time;

    return 0;
}
