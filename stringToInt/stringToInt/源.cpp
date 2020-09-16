#include<iostream>
#include<stack>
using namespace std;

int atoi(const char* str) {
    bool isPositive = true;
    stack<int>temp;
    const char* p;
    if (str[0] == '-') {
        isPositive = false;
        p = str + 1;
    }
    else {
        int t = 0;
        while (str[t]!='\0'&&(str[t] < '0' || str[t]>'9')) {
            t++;
        }
        p = str + t;
    }
    for (int i = 0; p[i] != '\0'; i++) {
        temp.push((p[i] - '0') + 0);
    }
    int ans = 0;
    int w = 1;
    while (!temp.empty()) {
        ans += temp.top() * w;
        w *= 10;
        temp.pop();
    }
    if (!isPositive) {
        ans *= (-1);
    }
    return ans;
}

int main() {
    const char* str = "";
    cout << atoi(str) << endl;
    return 0;
}