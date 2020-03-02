#include<iostream>
#include<vector>
using namespace std;

/*
vector<int> printMatrix(vector<vector<int> > matrix) {
    vector<int>ans;
    int rowNum = matrix.size();
    int columnNum = matrix[0].size();
    if (rowNum == 0 || columnNum == 0) {
        return ans;
    }
    int cycle = rowNum < columnNum ? rowNum / 2 + rowNum % 2 : columnNum / 2 + columnNum % 2;
    for (int i = 0; i < cycle; i++) {
        // 向右
        int j;
        for (j = i; j < columnNum - i; j++) {
            ans.push_back(matrix[i][j]);
        }
        j--;
        // 向下
        int k = i + 1;
        if (k > rowNum -1-i) {
            return ans;
        }
        for (; k < rowNum - i; k++) {
            ans.push_back(matrix[k][j]);
        }
        k--;
        // 向左
        int m = j - 1;
        if (m < i) {
            return ans;
        }
        for (; m >= i; m--) {
            ans.push_back(matrix[k][m]);
        }
        // 向上
        m++;
        int n;
        for (n = k - 1; n > i; n--) {
            ans.push_back(matrix[n][m]);
        }
    }
    return ans;
}
*/

vector<int> printMatrix(vector<vector<int> > matrix) {
    vector<int>ans;
    int rowNum = matrix.size();
    int columnNum = matrix[0].size();
    if (rowNum == 0 || columnNum == 0) {
        return ans;
    }
    int left = 0, right = columnNum - 1, top = 0, bottom = rowNum - 1;
    // 每次打印一层，剩下的又是一个矩阵
    while (left <= right && top <= bottom) {
        //向右
        for (int i = left; i <= right; i++) {
            ans.push_back(matrix[top][i]);
        }
        //向下
        if (top >= bottom) {
            return ans;
        }
        for (int i = top + 1; i <= bottom; i++) {
            ans.push_back(matrix[i][right]);
        }
        //向左
        if (left >= right) {
            return ans;
        }
        for (int i = right - 1; i >= left; i--) {
            ans.push_back(matrix[bottom][i]);
        }
        //向上
        if (top + 1 >= bottom) {
            return ans;
        }
        for (int i = bottom - 1; i >= top + 1; i--) {
            ans.push_back(matrix[i][left]);
        }
        left++;
        right--;
        top++;
        bottom--;
    }

    return ans;
}

int main() {
    vector<vector<int>>matrix({ {1},{2 }, { 6},{ 7 } });
    vector<int>ans = printMatrix(matrix);
    for (int i = 0; i < ans.size();i++) {
        cout << ans[i] << " ";
    }
    return 0;
    system("pause");
}