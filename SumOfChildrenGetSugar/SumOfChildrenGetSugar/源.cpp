#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    vector<int>sugar;
    char c;
    int num;
    cin >> num;
    sugar.push_back(num);
    while ((c = getchar()) != '\n') {
        cin >> num;
        sugar.push_back(num);
    }
    sort(sugar.begin(), sugar.end());
    int ans = 0;
    int n;
    for (int i = 0; i < sugar.size(); i++) {
        n = sugar[i] + 1;
        ans += n;
        int j;
        for (j = i + 1; j < i + n && j < sugar.size(); j++) {
            if (sugar[j] != sugar[i]) {
                break;
            }
        }
        i = j - 1;

    }
    cout << ans;
    return 0;
}