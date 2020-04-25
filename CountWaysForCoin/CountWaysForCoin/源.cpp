#include<iostream>
#include<vector>
using namespace std;

int countWays(int n) {
    // write code here
    vector<int>f(n + 1, 0);
    f[0] = 1;
    int* single = new int[4]{ 1, 5, 10, 25 };
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= n; j++) {
            if (j - single[i] >= 0) {
                f[j] += f[j - single[i]];
                f[j] %= 1000000007;
            }
        }
    }
    return f[n];
}

int main() {
    int n;
    cin >> n;
    cout << countWays(n) << endl;
    return 0;
}