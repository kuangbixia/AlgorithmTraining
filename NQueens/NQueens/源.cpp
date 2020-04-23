#include<iostream>
#include<vector>
using namespace std;

bool check(int i, int j, vector<vector<bool>>now, int n) {
    for (int p = 0; p < n; p++) {
        if (now[i][p]) {
            return false;
        }
        if (now[p][j]) {
            return false;
        }
    }
    for (int p = i + 1, q = j + 1; p < n && q < n; p++, q++) {
        if (now[p][q]) {
            return false;
        }
    }
    for (int p = i - 1, q = j - 1; p >= 0 && q >= 0; p--, q--) {
        if (now[p][q]) {
            return false;
        }
    }
    for (int p = i - 1, q = j + 1; p >= 0 && q < n; p--, q++) {
        if (now[p][q]) {
            return false;
        }
    }
    for (int p = i + 1, q = j - 1; p < n && q >= 0; p++, q--) {
        if (now[p][q]) {
            return false;
        }
    }
    return true;
}
void iQueen(int row, vector<vector<bool>>now, int n, int& count) {
    for (int p = 0; p < n; p++) {
        if (check(row, p,now,n)) {
            now[row][p] = true;
            if (row == n - 1) {
                count++;
                return;
            }
            iQueen(row + 1, now, n, count);
            now[row][p] = false;
        }
    }
    return;
}
int nQueens(int n) {
    // write code here
    vector<bool>p(n, false);
    vector<vector<bool>>q(n, p);
    int count = 0;
    iQueen(0, q, n, count);
    return count;
}

int main() {
    int n;
    cin >> n;
    cout << nQueens(n) << endl;
    return 0;
}