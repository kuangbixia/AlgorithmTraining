#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
bool IsPopOrder(vector<int> pushV, vector<int> popV) {
    for (int i = 1; i < pushV.size(); i++) {
        int flag = 0;
        for (int j = i - 1; j >= 0; j--) {
            int dis = find(popV.begin(), popV.end(), pushV[j]) - find(popV.begin(), popV.end(), pushV[i]);
            if (dis > 0) {
                // pushV中从右到左，popV中从左到右距离j越来越远
                if (dis > flag) {
                    flag = dis;
                }
                else {
                    return false;
                }
            }
        }
    }
    return true;
}
*/
bool IsPopOrder(vector<int> pushV, vector<int> popV) {
    stack<int>temp;
    int popI = 0;
    for (int i = 0; i < pushV.size(); i++) {
        temp.push(pushV[i]);
        while (!temp.empty()&&temp.top() == popV[popI]) {
            temp.pop();
            popI++;
        }
    }
    return temp.empty();
}

int main() {
    vector<int>pushV({ 1 });
    vector<int>popV({ 4 });
    cout << IsPopOrder(pushV, popV) << endl;
    return 0;
    system("pause");
}