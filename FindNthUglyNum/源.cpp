#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*vector<int>ugly;

void check(int num) {
    ugly.push_back(num);
    for (int j = ugly.size() - 2; j >= 0; j--) {
        if (ugly[j] == num) {
            j++;
            while (j < ugly.size() - 1) {
                ugly[j] = ugly[j + 1];
                j++;
            }
            ugly.pop_back();
            break;
        }
        if (ugly[j] > num) {
            ugly[j + 1] = ugly[j];
        }
        else if (ugly[j] < num) {
            ugly[j + 1] = num;
            break;
        }
    }
}
int GetUglyNumber_Solution(int index) {
    ugly.push_back(1);
    int i = 0;
    int num;
    while (ugly.size()<index+100) {
        if (i == 0) {
            ugly.push_back(ugly[i] * 2);
            ugly.push_back(ugly[i] * 3);
            ugly.push_back(ugly[i] * 5);
        }
        else {
            num = ugly[i] * 2;
            check(num);
            for (int k = 0; k < ugly.size(); k++) {
                cout << ugly[k] << " ";
            }
            cout << endl;
            num = ugly[i] * 3;
            check(num);
            for (int k = 0; k < ugly.size(); k++) {
                cout << ugly[k] << " ";
            }
            cout << endl;
            num = ugly[i] * 5;
            check(num);
            for (int k = 0; k < ugly.size(); k++) {
                cout << ugly[k] << " ";
            }
            cout << endl;
        }
        i++;
    }
    
    return ugly[index - 1];
}*/

int GetUglyNumber_Solution(int index) {
    vector<int>ans;
    ans.push_back(1);
    int i2 = 0, i3 = 0, i5 = 0;
    for (int i = 1; i <= index; i++) {
        int num2 = ans[i2] * 2;
        int num3 = ans[i3] * 3;
        int num5 = ans[i5] * 5;
        ans.push_back(min(num2, min(num3, num5)));
        if (ans[i] == num2) {
            i2++;
        }
        if (ans[i] == num3) {
            i3++;
        }
        if (ans[i] == num5) {
            i5++;
        }
    }
    return ans[index - 1];
}

int main() {
    cout << GetUglyNumber_Solution(20) << endl;
    return 0;
}