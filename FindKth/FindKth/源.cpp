#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findKth(int k) {
    // write code here
    vector<int>v( k + 1,1 );
    int i = 0;
    auto i_3 = v.begin();
    auto i_5 = v.begin();
    auto i_7 = v.begin();
    while (i < k) {
        int val_3 = *i_3 * 3;
        int val_5 = *i_5 * 5;
        int val_7 = *i_7 * 7;
        int next = val_3 < val_5 ? val_3 : val_5;
        next = next < val_7 ? next : val_7;
        v[++i] = next;
        if (next == val_3) {
            ++i_3;
        }
        if (next == val_5) {
            ++i_5;
        }
        if (next == val_7) {
            ++i_7;
        }
    }
    for (int i = 0; i <= k; i++) {
        cout << v[i] << endl;
    }
    return v[k];
}

int main() {
    vector<int>test({ 1,2,3,4,5 });
    test.push_back(6);
    auto end = test.end() - 1;
    cout << *end << endl;
    end++;
    cout << (end == test.end()) << endl;
    auto it = test.begin();
    while (it != test.end()) {
        cout << *it << endl;
        it++;
    }
    return 0;
}