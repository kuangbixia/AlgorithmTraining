#include<iostream>
#include<string>
#include<vector>
using namespace std;

string longestPalindrome(string s) {
    // write code here
    vector<vector<int>>dp(s.length(), vector<int>(s.length(),0));
    int length = 1;
    string ans = s.substr(0, 1);
    for (int i = 0; i < s.length(); i++) {
        dp[i][i] = 1;
    }
    for (int i = s.length() - 2; i >= 0; i--) {
        for (int j = s.length() - 1; j > i; j--) {
            if (s[i] == s[j]) {
                if (i + 1 == j) {
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                if (dp[i][j] == 1) {
                    int l = j - i + 1;
                    if (l > length) {
                        length = l;
                        ans = s.substr(i, l);
                    }
                }
            }
        }
    }
    return ans;
}

int main() {
    cout << longestPalindrome("abcbd") << endl;
    return 0;
}