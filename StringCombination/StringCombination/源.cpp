#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> Permutation(string str) {
    vector<string>a;
    vector<string>b;
    if (str.length() < 1) {
        return a;
    }
    a.push_back(str.substr(0, 1));
    int i = 1;
    while (str[i] != '\0') {
        int aSize = a.size();
        for (int k = 0; k < aSize; k++) {
            string temp = a[k];
            for (int l = 0; l <= a[k].length(); l++) {
                b.push_back(temp.insert(l, 1, str[i]));
                temp = a[k];
            }
        }
        a = b;
        b.resize(0);
        i++;
    }
    for (int q = 1; q < a.size(); q++) {
        string t = a[q];
        int p;
        for (p = q - 1; p >= 0; p--) {
            if (a[p] > t) {
                a[p + 1] = a[p];
            }
            else {
                break;
            }
        }
        a[p + 1] = t;
    }
    return a;
}

int main() {
	string s("abc");
    vector<string>a = Permutation(s);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << endl;
    }

    string sub = s.substr(0, 0);
    cout << sub << endl;
	return 0;
}