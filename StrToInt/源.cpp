#include<iostream>
#include<string>
using namespace std;

int StrToInt(string str) {
    int ans = 0;
    int bit = 0;
    int i;
    for (i = str.length() - 1; i > 0; i--) {
        if (str[i] > '0' && str[i] < '9') {
            ans += (str[i]-'0')* pow(10, bit);
            bit++;
        }
        else {
            return 0;
        }
    }
    if (str[i] == '-') {
        ans = -ans;
    }
    else if (str[i] == '+') {
        
    }
    else {
        if (str[i] > '0' && str[i] < '9') {
            ans += (str[i] - '0') * pow(10, bit);
            if (ans < 0) {
                return 0;
            }
        }
        else {
            return 0;
        }
    }
    return ans;
}

int main() {
    cout << StrToInt(string("2147483648"));
    return 0;
}