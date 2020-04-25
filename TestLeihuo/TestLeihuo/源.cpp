#include<iostream>
using namespace std;

int calculate(int* h, int n, int width) {
    int maxlength = 0;
    int length = 0;
    for (int i = 0; i < n; i++) {
        if (h[i] < width) {
            if (maxlength < length) {
                maxlength = length;
            }
            length = 0;
            continue;
        }
        else {
            length++;
        }
    }
    if (maxlength < length) {
        maxlength = length;
    }
    return maxlength * width;
}

int main() {
    int num;
    cin >> num;
    int* h = new int[num];
    int* sortH = new int[num];
    for (int i = 0; i < num; i++) {
        cin >> h[i];
        if (i == 0) {
            sortH[i] = h[i];
        }
        else {
            int j;
            for (j = i - 1; j >= 0; j--) {
                if (sortH[j] > h[i]) {
                    sortH[j + 1] = sortH[j];
                }
                else {
                    break;
                }
            }
            sortH[j + 1] = h[i];
        }
    }
    int ans = 0;
    for (int i = 0; i < num; i++) {
        if (i > 0 && sortH[i] == sortH[i - 1]) {
            continue;
        }
        int temp = calculate(h, num, sortH[i]);
        if (temp > ans) {
            ans = temp;
        }
    }
    cout << ans << endl;
    return 0;
}