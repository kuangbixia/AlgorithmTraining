#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

vector<int> solve(int n, int m, vector<int>& a, vector<int>& x) {
    // write code here
    vector<int>res;
    sort(a.begin(), a.end());
    for (int i = 0; i < x.size(); i++) {
        int y = x[i];
        int dis = INT_MAX;
        // ¶þ·Ö²éÕÒ
        int l = 0;
        int r = a.size() - 1;
        while (l <= r) {
            int p = (l + r) / 2;
            if (a[p] == y) {
                dis = 0;
                break;
            }
            else if (a[p] < y) {
                dis = y - a[p] < dis ? y - a[p] : dis;
                l = p + 1;
            }
            else {
                dis = a[p] - y < dis ? a[p] - y : dis;
                r = p - 1;
            }
        }
        res.push_back(dis);
    }
    return res;
}

int main() {
    vector<int>a({ 2,4,7 });
    vector<int>x({ 5,8 });
    vector<int>res = solve(3, 2, a, x);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}