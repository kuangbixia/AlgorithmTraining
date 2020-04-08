#include<iostream>
#include<vector>
using namespace std;

int ans = 0;

void merge(vector<int>b, vector<int>c, vector<int>&a) {
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < b.size() && j < c.size()) {
        if (b[i] < c[j]) {
            a[k++] = b[i++];
        }
        else {
            a[k++] = c[j++];
            ans += (b.size() - i);
            ans %= 1000000007;
        }
    }
    if (i == b.size()) {
        while (j < c.size()) {
            a[k++] = c[j++];
        }
    }
    if (j == c.size()) {
        while (i < b.size()) {
            a[k++] = b[i++];
            ans += (c.size() - j);
            ans %= 1000000007;
        }
    }
}

void mergesort(vector<int>&a) {
    if (a.size() > 1) {
        vector<int>b;
        vector<int>c;
        int i = 0;
        for (; i < a.size() / 2; i++) {
            b.push_back(a[i]);
        }
        for (; i < a.size(); i++) {
            c.push_back(a[i]);
        }
        mergesort(b);
        mergesort(c);
        merge(b, c, a);
    }
}

int InversePairs(vector<int> data) {
    if (data.size() < 2) {
        return 0;
    }
    mergesort(data);
    return ans;
}

int main() {
    vector<int>input({ 1,2,13,4,5,6,7,0 });
    cout << InversePairs(input) << endl;
    return 0;
}