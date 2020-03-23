#include<iostream>
#include<string>
using namespace std;

string LeftRotateString(string str, int n) {
    int len = str.length();
    if (len <= 1) {
        return str;
    }
    n %= len;
    for (int i = 0; i < n; i++) {
        str.insert(str.length(), str.substr(i, 1));
    }
    str = str.substr(n, len);
    return str;
}

int main() {
    string input("abcde");
    string output = LeftRotateString(input, 3);
    cout << output << endl;
    return 0;
}