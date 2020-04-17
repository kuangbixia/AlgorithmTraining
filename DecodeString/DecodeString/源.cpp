#include<iostream>
#include<string>
#include<math.h>
using namespace std;

string decode(string s) {
    string o("");
    int i;
    for (i = 0; i < s.length(); i++) {
        if (s[i] == '[') {
            break;
        }
        else {
            o.append(1, s[i]);
        }
    }
    if (i != s.length()) {
        i++;
        int bit = 1;
        while (s[++i] != '|') {
            bit++;
        }
        int cnt = 0;
        for (int k = 0; k < bit; k++) {
            cnt += pow(10, k) * (s[--i] - '0');
        }
        i += bit;
        int k = i;
        int begin = 1;
        int end = 0;
        while ((++k) < s.length()) {
            if (s[i] == ']') {
                end++;
            }
            if (s[i] == '[') {
                begin++;
            }
            if (end == begin) {
                break;
            }
        }
        i++;
        k--;
        string sub = s.substr(i, k - i + 1);
        string next = decode(sub);
        for (int p = 0; p < cnt; p++) {
            o += next;
        }
        k += 2;
        if (k < s.length()) {
            string last = s.substr(k, s.length() - k);
            o += decode(last);
        }
    }
    return o;
}

int main() {
    string input;
    cin >> input;
    cout << decode(input) << endl;
    return 0;
}