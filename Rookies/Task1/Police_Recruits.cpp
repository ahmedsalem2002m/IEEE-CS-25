#include <iostream>

using namespace std;

int main()
{
    int number;
    cin >> number;
    int crimes = 0;
    int police = 0;
    for(int i = 0; i< number; i++)
    {
        int input;
        cin >> input;
        if(input == -1)
        {
            if(police >= 1)
            {
                police = police - abs(input);
            }else{
                crimes = crimes + abs(input);
            }
        }
        else
        {
            police = police + input;
        }
    }
    cout << crimes;
    return 0;
}
