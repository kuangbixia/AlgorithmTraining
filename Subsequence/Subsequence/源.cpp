#include<iostream>
using namespace std;
#include<vector>

int numDistinct(string S, string T) {
    // write code here
    if (S.length() < T.length()) {
        return 0;
    }
    vector<vector<int>>dp(T.length() + 1, vector<int>(S.length() + 1, 0));
    for (int i = 0; i <= S.length(); i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= T.length(); i++) {
        for (int j = 1; j <= S.length(); j++) {
            if (S[j - 1] == T[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
            }
            else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    return dp[T.length()][S.length()];
}

int main() {
    string S = "b";
    string T = "b";
    cout << numDistinct(S, T) << endl;
    return 0;
}