#include <iostream>
#include <string>
using namespace std;

int main() {
    string row1 = "qwertyuiop";
    string row2 = "asdfghjkl;";
    string row3 = "zxcvbnm,./";

    char direction;
    cin >> direction;

    string typed_message;
    cin >> typed_message;

    int shift = (direction == 'R') ? -1 : 1;

    string original_message = "";
    for (char ch : typed_message) {
        if (row1.find(ch) != string::npos) {
            int index = row1.find(ch);
            original_message += row1[index + shift];
        }
        else if (row2.find(ch) != string::npos) {
            int index = row2.find(ch);
            original_message += row2[index + shift];
        }
        else if (row3.find(ch) != string::npos) {
            int index = row3.find(ch);
            original_message += row3[index + shift];
        }
    }

    cout << original_message << endl;

    return 0;
}
