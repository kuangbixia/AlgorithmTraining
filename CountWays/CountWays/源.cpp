#include<iostream>
#include<vector>
using namespace std;

int countWays(int n) {
    // write code here
    //f(n)=f(n-1)+f(n-2)+f(n-3)
    vector<int>f(n, 1);
    f[0] = 1;
    f[1] = 2;
    f[2] = 4;
    for (int i = 3; i < n; i++) {
        f[i] = f[i - 1] + f[i - 2];
        f[i] %= 1000000007;
        f[i] += f[i - 3];
        f[i] %= 1000000007;
    }
    return f[n - 1];
}

int main() {
    int n;
    cin >> n;
    cout << countWays(n) << endl;
    return 0;
}