#include<iostream>
#include<string>
using namespace std;

string zipString(string iniString) {
    // write code here
    string out("");
    for (int i = 0; i < iniString.length();) {
        out.append(iniString.substr(i, 1));
        char find = iniString[i];
        int cnt = 1;
        for (int j = i + 1; j < iniString.length(); j++) {
            if (iniString[j] == find) {
                cnt++;
            }
            else {
                break;
            }
        }
        if (cnt > 1) {
            out += to_string(cnt);
        }
        i += cnt;
    }
    return out;
}
