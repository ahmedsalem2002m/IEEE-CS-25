#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;



//using AI because the problem was difficult.

struct Cow {
    int start, end, coolingRequired;
};

struct AC {
    int start, end, coolingPower, cost;
};

int N, M;
vector<Cow> cows;
vector<AC> airConditioners;
vector<int> dp(1 << 10, INT_MAX);

bool satisfies(const vector<int>& acSet) {
    vector<int> cooling(101, 0);
    for (int i = 0; i < M; ++i) {
        if (acSet[i]) {
            for (int j = airConditioners[i].start; j <= airConditioners[i].end; ++j) {
                cooling[j] += airConditioners[i].coolingPower;
            }
        }
    }
    
    for (const Cow& cow : cows) {
        for (int j = cow.start; j <= cow.end; ++j) {
            if (cooling[j] < cow.coolingRequired) {
                return false;
            }
        }
    }
    
    return true;
}

int solve() {
    for (int mask = 1; mask < (1 << M); ++mask) {
        vector<int> acSet(M, 0);
        for (int i = 0; i < M; ++i) {
            if (mask & (1 << i)) {
                acSet[i] = 1;
            }
        }
        
        if (satisfies(acSet)) {
            int cost = 0;
            for (int i = 0; i < M; ++i) {
                if (acSet[i]) {
                    cost += airConditioners[i].cost;
                }
            }
            dp[mask] = min(dp[mask], cost);
        }
    }
    
    int minCost = INT_MAX;
    for (int mask = 1; mask < (1 << M); ++mask) {
        minCost = min(minCost, dp[mask]);
    }
    
    return minCost;
}

int main() {
    cin >> N >> M;
    
    cows.resize(N);
    airConditioners.resize(M);
    
    for (int i = 0; i < N; ++i) {
        cin >> cows[i].start >> cows[i].end >> cows[i].coolingRequired;
    }
    
    for (int i = 0; i < M; ++i) {
        cin >> airConditioners[i].start >> airConditioners[i].end >> airConditioners[i].coolingPower >> airConditioners[i].cost;
    }
    
    cout << solve() << endl;
    
    return 0;
}
