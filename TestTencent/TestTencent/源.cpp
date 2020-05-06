#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<iomanip>
using namespace std;

bool compare(vector<int>x, vector<int>y) {
    if (x[0] != y[0]) {
        return x[0] < y[0];
    }
    else {
        return x[1] < y[1];
    }
}

int main() {
    int group;
    cin >> group;
    while (group--) {
        int n;
        cin >> n;
        vector<vector<int>>A(n, vector<int>(2, 0));
        vector<vector<int>>B(n, vector<int>(2, 0));
        for (int i = 0; i < n; i++) {
            cin >> A[i][0] >> A[i][1];
        }
        for (int i = 0; i < n; i++) {
            cin >> B[i][0] >> B[i][1];
        }
        sort(A.begin(), A.end(), compare);
        sort(B.begin(), B.end(), compare);
        int iA = 0;
        int iB = 0;
        int dx = abs(B[iA][0] - A[iB][0]);
        int dy = abs(B[iA][1] - A[iB][1]);
        double ans = 0;
        bool flag = false;
        while (iA < n && iB < n) {
            while (iA < n && A[iA][0] < B[iB][0]) {
                dx = abs(B[iA][0] - A[iB][0]);
                iA++;
            }
            if (iA == n) {
                iA--;
            }
            while (iB < n && B[iB][0] < A[iA][0]) {
                dx = abs(B[iA][0] - A[iB][0]);
                iB++;
            }
            if (iB == n) {
                iB--;
            }
            int tdx = abs(B[iA][0] - A[iB][0]);
            if (tdx < dx) {
                dx = tdx;
            }
            dy = abs(B[iA][1] - A[iB][1]);
            while (iA < n && A[iA][1] < B[iB][1]) {
                dy = abs(B[iA][1] - A[iB][1]);
                iA++;
            }
            if (iA == n) {
                iA--;
            }
            while (iB < n && B[iB][1] < A[iA][1]) {
                dy = abs(B[iA][1] - A[iB][1]);
                iB++;
            }
            if (iB == n) {
                iB--;
            }
            int tdy = abs(B[iA][1] - A[iB][1]);
            if (tdy < dy) {
                dy = tdy;
            }
            double temp = sqrt(dx * dx + dy * dy);
            if (!flag) {
                ans = temp;
                flag = true;
            }
            else {
                if (temp < ans) {
                    ans = temp;
                }
            }

        }

        cout << fixed << setprecision(3) << ans << endl;
    }
}