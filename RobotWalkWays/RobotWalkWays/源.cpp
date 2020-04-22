#include<iostream>
#include<vector>
using namespace std;

int countWays(vector<vector<int> > map, int x, int y) {
    // write code here
    vector<vector<int>>f;
    f.resize(x);
    for (int i = 0; i < x; i++) {
        f[i].resize(y);
        if (i == 0) {
            int j;
            for (j = 0; j < y; j++) {
                if (map[i][j] != 1) {
                    break;
                }
                f[i][j] = 1;
            }
            for (; j < y; j++) {
                f[i][j] = 0;
            }
        }
        else {
            if (map[i][0] != 1) {
                f[i][0] = 0;
            }
            else {
                f[i][0] = f[i - 1][0];
            }
        }
    }
    for (int i = 1; i < x; i++) {
        for (int j = 1; j < y; j++) {
            if (map[i][j] != 1) {
                f[i][j] = 0;
            }
            else {
                f[i][j] = f[i][j - 1] + f[i - 1][j];
            }
        }
    }
    return f[x - 1][y - 1];
}

int main() {
    vector<vector<int>>map{ {1,1,1,1} ,{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,0,1,1},{0,1,1,1},{1,1,1,1},{1,1,1,1} };
    cout << countWays(map, 11, 4) << endl;
    return 0;
}