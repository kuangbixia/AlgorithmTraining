#include<iostream>
using namespace std;

int main() {
    string s ="abcabcbb";
    if (s.length() < 1) {
        return 0;
    }
    int maxLength = 1;
    for (int i = 0; i < s.length() - maxLength; i++) {
        string subString = s.substr(i, 1);
        int subLength = 1;
        for (int j = i + 1; j < s.length(); j++) {
            if (subString.find(s[j]) != subString.npos) {
                break;
            }
            subString += s[j];
            subLength++;
        }
        if (subLength > maxLength) {
            maxLength = subLength;
        }
    }
    cout << maxLength << endl;
    return 0;
    system("pause");
}