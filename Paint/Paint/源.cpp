#include<iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int** plane = new int* [n];
    for (int i = 0; i < n; i++) {
        plane[i] = new int[m];
        string line;
        cin >> line;
        for (int j = 0; j < m; j++) {
            char c = line[j];
            int temp;
            if (c == 'X') {
                temp = 0;
            }
            else if (c == 'B') {
                temp = 1;
            }
            else if (c == 'Y') {
                temp = 2;
            }
            else {
                temp = 3;
            }
            plane[i][j] = temp;
        }
    }
    for (int p = 0; p < n; p++) {
        for (int q = 0; q < m; q++) {
            cout << plane[p][q] << " ";
        }
        cout << endl;
    }
    cout << "------" << endl;
    int ans = 0;
    for (int twice = 0; twice < 2; twice++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (plane[i][j] == 1) {
                    ans++;
                    int k = 0;
                    while (i + k < n && j - k >= 0) {
                        if (plane[i + k][j - k] == 0 || plane[i + k][j - k] == 2) {
                            break;
                        }
                        plane[i + k][j - k] -= 1;
                        k++;
                    }
                    k = 1;
                    while (i - k >= 0 && j + k < m) {
                        if (plane[i - k][j + k] == 0 || plane[i - k][j + k] == 2) {
                            break;
                        }
                        plane[i - k][j + k] -= 1;
                        k++;
                    }
                }
                if (plane[i][j] == 2) {
                    ans++;
                    int k = 0;
                    while (i + k < n && j + k < m) {
                        if (plane[i + k][j + k] == 0 || plane[i + k][j + k] == 1) {
                            break;
                        }
                        plane[i + k][j + k] -= 2;
                        k++;
                    }
                    k = 1;
                    while (i - k >= 0 && j - k >= 0) {
                        if (plane[i - k][j - k] == 0 || plane[i - k][j - k] == 1) {
                            break;
                        }
                        plane[i - k][j - k] -= 2;
                        k++;
                    }
                }
                for (int p = 0; p < n; p++) {
                    for (int q = 0; q < m; q++) {
                        cout << plane[p][q] << " ";
                    }
                    cout << endl;
                }
                cout << "------" << endl;
                cout << ans << endl;
                cout << "------" << endl;
            }
        }
    }
    
    cout << ans;
    return 0;
}