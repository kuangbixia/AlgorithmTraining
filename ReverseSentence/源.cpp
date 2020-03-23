#include<iostream>
#include<string>
#include<vector>
using namespace std;

string ReverseSentence(string str) {
    vector<string>arr;
    int index = 0;
    while (index < str.length()) {
        size_t found = str.find(" ", index);
        if (found!=str.npos) {
            arr.push_back(str.substr(index, found - index));
            arr.push_back(" ");
            index = found + 1;
        }
        else {
            arr.push_back(str.substr(index, str.length() - index));
            break;
        }
    }
    string ans("");
    for (int i = arr.size() - 1; i >= 0; i--) {
        ans.insert(ans.length(), arr[i]);
    }
    return ans;
}

int main() {
    string input("student. a am I");
    string output = ReverseSentence(input);
    cout << output;
    return 0;
}