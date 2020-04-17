#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>h;
    int i = n;
    while (i--) {
        int height;
        cin >> height;
        h.push_back(height);
    }
    while (++i < n) {
        int ans = 1;
        int left = 0, right = 0;
        for (int p = i - 1; p >= 0; p--) {
            if (p == (i - 1)) {
                left = h[p];
                ans++;
            }
            else if (h[p] > left) {
                ans++;
                left = h[p];
            }
        }
        for (int q = i + 1; q < n; q++) {
            if (q == (i + 1)) {
                right = h[q];
                ans++;
            }
            else if (h[q] > right) {
                ans++;
                right = h[q];
            }
        }
        cout << ans << " ";
    }
    return 0;
}