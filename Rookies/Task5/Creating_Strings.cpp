#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void generate_permutations(string& s, int index, set<string>& result) {
    if (index == s.size()) {
        result.insert(s);
        return;
    }

    for (int i = index; i < s.size(); ++i) {
        swap(s[i], s[index]);
        generate_permutations(s, index + 1, result);
        swap(s[i], s[index]);
    }
}

int main() {
    string s;
    cin >> s;

    set<string> result;
    generate_permutations(s, 0, result);

    cout << result.size() << endl;
    for (const string& str : result) {
        cout << str << endl;
    }

    return 0;
}
