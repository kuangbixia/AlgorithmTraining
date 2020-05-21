#include<iostream>
#include<vector>
using namespace std;

int maxPresent(vector<int>& presentVec) {
    // write code here
    int n = presentVec.size();
    int val = 0;
    for (int i = 0; i < n; i++) {
        val += presentVec[i];
    }
    vector<vector<int>>f(n + 1, vector<int>(val / 2 + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= val/2; j++) {
            int pre = f[i - 1][j];
            if (j - presentVec[i-1] >= 0) {
                int now = f[i - 1][j - presentVec[i-1]] + presentVec[i-1];
                f[i][j] = pre > now ? pre : now;
            }
            else {
                f[i][j] = pre;
            }
        }
    }
    int ans = val - f[n][val / 2] - f[n][val / 2];
    ans = ans < 0 ? -ans : ans;
    return ans;
}

int main() {
    vector<int>input = { 1,3,5 };
    cout << maxPresent(input) << endl;
    return 0;
}