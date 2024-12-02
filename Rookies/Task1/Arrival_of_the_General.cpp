#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int number;
    cin >> number;

    int heights[number];
    int min;
    int max;
    int minIndex = 0;
    int maxIndex = 0;
    for(int i=0;i<number;i++){
        cin >> heights[i];
    }
    max = heights[0];
    min = heights[0];
    for(int i=1;i<number;i++){
        if(heights[i]> max){
            max = heights[i];
            maxIndex = i;
        }
        if(heights[i]<= min){
            min = heights[i];
            minIndex = i;
        }
    }
    //cout << "max " << max << " maxIndex " << maxIndex << "\n";
    //cout << "min " << min << " minIndex " << minIndex << "\n";
    if (minIndex < maxIndex)
    {
        cout << ((maxIndex + abs(minIndex - (number - 1))) - 1);
    }
    else
    {
        cout << (maxIndex + abs(minIndex - (number - 1)));
    }


    return 0;
}


