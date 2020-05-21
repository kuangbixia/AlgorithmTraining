#include<iostream>
#include<vector>
using namespace std;

vector<int> findSegment(vector<int> A, int n) {
    // write code here
    int l = 0;
    int r = n - 1;
    while (l < r) {
        if (A[l] > A[r]) {
            int i;
            for (i = l-1; i >= 0; i--) {
                if (A[i] < A[r]) {
                    break;
                }
            }
            l = i + 1;
            int j;
            for (j = r+1; j < n; j++) {
                if (A[j] > A[l]) {
                    break;
                }
            }
            r = j - 1;
        }
        else {
            l++;
            r--;
        }
        if (l == r) {
            int i;
            for (i = l - 1; i >= 0; i--) {
                if (A[i] < A[r]) {
                    break;
                }
            }
            l = i + 1;
            int j;
            for (j = r; j < n; j++) {
                if (A[j] > A[l]) {
                    break;
                }
            }
            r = j - 1;
        }
    }
    if (l >= r) {
        l = 0;
        r = 0;
    }

    return vector<int>{l, r};
}

int main() {
    vector<int>A{ 1,7,6,5,9,10 };
    vector<int>out= findSegment(A, 6);
    cout << out[0] << " " << out[1] << endl;
    return 0;
}