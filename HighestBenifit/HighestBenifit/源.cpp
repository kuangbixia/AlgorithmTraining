#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int getBenifit(int x, int y) {
    return 200 * x + 3 * y;
}

int main() {
    int machine, task;
    cin >> machine >> task;
    vector<vector<int>>m(machine, vector<int>(2, 0));
    vector<vector<int>>t(task, vector<int>(2, 0));
    for (int i = 0; i < machine; i++) {
        cin >> m[i][0] >> m[i][1];
    }
    for (int j = 0; j < task; j++) {
        cin >> t[j][0] >> t[j][1];
    }
    sort(m.begin(), m.end(), [](vector<int>p, vector<int>q) {
        if (p[0] != q[0]) {
            return p[0] > q[0];
        }
        else {
            return p[1] > q[1];
        }
        });
    sort(t.begin(), t.end(), [](vector<int>p, vector<int>q) {
        if (p[0] != q[0]) {
            return p[0] > q[0];
        }
        else {
            return p[1] > q[1];
        }
        });
    int cnt = 0;
    int benifit = 0;

}