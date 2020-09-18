#include<iostream>
using namespace std;
#include<vector>

vector<int> getRow(int rowIndex) {
    // write code here
    vector<int>res(rowIndex, 0);
    res[0] = 1;
    for (int i = 2; i <= rowIndex; i++) {
        res[i - 1] = 1;
        for (int j = i - 2; j > 0; j--) {
            res[j] += res[j - 1];
        }
    }
    return res;
}

int main() {
    vector<int>res = getRow(4);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}