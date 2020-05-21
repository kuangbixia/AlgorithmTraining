#include<iostream>
#include<vector>
using namespace std;

int selectPresent(vector<vector<int> >& presentVolumn) {
    // write code here
    int n = presentVolumn.size();
    int m = presentVolumn[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0) {
                if (j > 0) {
                    presentVolumn[i][j] += presentVolumn[i][j - 1];
                }
            }
            if (j == 0) {
                if (i > 0) {
                    presentVolumn[i][j] += presentVolumn[i - 1][j];
                }
            }
            if (i > 0 && j > 0) {
                int next = presentVolumn[i][j - 1];
                next = next < presentVolumn[i - 1][j - 1] ? next : presentVolumn[i - 1][j - 1];
                next = next < presentVolumn[i - 1][j] ? next : presentVolumn[i - 1][j];
                presentVolumn[i][j] += next;
            }
        }
    }
    return presentVolumn[n - 1][m - 1];
}

int main() {
    //vector<vector<int>>input = { {1}};
    //cout << selectPresent(input) << endl;
    int n = 10;
    vector<vector<int>>f(n + 1, vector<int>(n + 1, 0));
    return 0;
}