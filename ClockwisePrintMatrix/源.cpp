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
        // ����
        int j;
        for (j = i; j < columnNum - i; j++) {
            ans.push_back(matrix[i][j]);
        }
        j--;
        // ����
        int k = i + 1;
        if (k > rowNum -1-i) {
            return ans;
        }
        for (; k < rowNum - i; k++) {
            ans.push_back(matrix[k][j]);
        }
        k--;
        // ����
        int m = j - 1;
        if (m < i) {
            return ans;
        }
        for (; m >= i; m--) {
            ans.push_back(matrix[k][m]);
        }
        // ����
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
    // ÿ�δ�ӡһ�㣬ʣ�µ�����һ������
    while (left <= right && top <= bottom) {
        //����
        for (int i = left; i <= right; i++) {
            ans.push_back(matrix[top][i]);
        }
        //����
        if (top >= bottom) {
            return ans;
        }
        for (int i = top + 1; i <= bottom; i++) {
            ans.push_back(matrix[i][right]);
        }
        //����
        if (left >= right) {
            return ans;
        }
        for (int i = right - 1; i >= left; i--) {
            ans.push_back(matrix[bottom][i]);
        }
        //����
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