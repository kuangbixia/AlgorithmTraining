#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>a;
vector<int>now;

int least(vector<int>b) {
    sort(b.begin(), b.end());
    now.clear();
    int cnt = 0;
    for (int i = 0; i < b.size(); i++) {
        int price = b[i];
        int j;
        for (j = 0; j < a.size(); j++) {
            if (price < a[j]) {
                break;
            }
        }
        if (j != 0) {
            cnt++;
            price -= a[j-1];
            if (price != 0) {
                now.push_back(price);
            }
        }
        else {
            now.push_back(price);
        }
    }
    if (cnt == b.size()) {
        int sum = 0;
        for (int i = 0; i < now.size(); i++) {
            sum += now[i];
        }
        return sum;
    }
    else {
        return least(now);
    }
}

int main() {
    int acnt;
    int bcnt;
    cin >> acnt >> bcnt;
    a.resize(acnt);
    for (int i = 0; i < acnt; i++) {
        cin >> a[i];
    }
    vector<int>b;
    b.resize(bcnt);
    for (int i = 0; i < bcnt; i++) {
        cin >> b[i];
    }
    cout << least(b) << endl;
    return 0;
}