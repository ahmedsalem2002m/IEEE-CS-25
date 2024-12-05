#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int cities, towers;
    cin >> cities >> towers;

    int locationOfCities[cities];
    int locationOfTowers[towers];

    for (int i = 0; i < cities; i++) {
        cin >> locationOfCities[i];
    }

    for (int i = 0; i < towers; i++) {
        cin >> locationOfTowers[i];
    }

    int maxDistance = 0;

    for (int i = 0; i < cities; i++) {
        int city = locationOfCities[i];

        auto it = lower_bound(locationOfTowers, locationOfTowers + towers, city);

        int distanceRight = (it == locationOfTowers + towers) ? INT_MAX : abs(*it - city);

        int distanceLeft = (it == locationOfTowers) ? INT_MAX : abs(*(it - 1) - city);

        int minDistance = min(distanceLeft, distanceRight);

        maxDistance = max(maxDistance, minDistance);
    }

    cout << maxDistance ;

    return 0;
}
