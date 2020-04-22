#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int> > getLast(vector<int> A, int n) {
    // write code here
    if (n == 1) {
        return vector<vector<int>>{ {A[n - 1]}};
    }
    vector<int>B = A;
    B.pop_back();
    vector<vector<int>>ans = getLast(B, n - 1);
    int size = ans.size();
    for (int i = 0; i < size; i++) {
        vector<int>temp = ans[i];
        temp.push_back(A[n - 1]);
        ans.push_back(temp);
    }
    ans.push_back(vector<int>{A[n - 1]});
    return ans;
}
vector<vector<int> > getSubsets(vector<int> A, int n) {
    // write code here
    sort(A.begin(), A.end(), [](int x, int y) {
        return x > y;
        });
    vector<vector<int>>ans = getLast(A, n);
    sort(ans.begin(), ans.end(), [](vector<int>A, vector<int>B) {
        int i = 0;
        while (i < A.size() && i < B.size()) {
            if (A[i] > B[i]) {
                return true;
            }
            else if (A[i] < B[i]) {
                return false;
            }
            else {
                i++;
            }
        }
        if (i < A.size()) {
            return true;
        }
        else {
            return false;
        }
        });
    return ans;
}
int main() {
    vector<int>A{ 123,456,789 };
    vector<vector<int>>ans = getSubsets(A, 3);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
