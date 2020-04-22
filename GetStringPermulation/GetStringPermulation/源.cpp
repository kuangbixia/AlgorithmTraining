#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> getLast(string A) {
    // write code here
    if (A.length() == 1) {
        return vector<string>{A};
    }
    string B = A.substr(1, A.length() - 1);
    vector<string>temp = getLast(B);
    char insertc = A[0];
    int size = temp.size();
    for (int i = 0; i < size; i++) {
        string str = temp[i];
        for (int j = 0; j <= str.length(); j++) {
            string newstr = str;
            newstr.insert(j, 1, insertc);
            if (j == 0) {
                temp[i] = newstr;
            }
            else {
                temp.push_back(newstr);
            }
        }
    }
    return temp;
}

vector<string> getPermutation(string A) {
    vector<string>ans = getLast(A);
    sort(ans.begin(), ans.end(), [](string x, string y) {
        return x > y;
        });
    return ans;
}
int main() {
    vector<string>ans = getPermutation("ABC");
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}