#include<iostream>
//#include<vector>
using namespace std;

int main() {
    int num;
    cin >> num;
    //vector<int>heights;
    int heights[200010] = {};
    //heights.push_back(NULL);
    heights[0] = NULL;
    for (int i = 1; i <= num;i++) {
        /*
        int height;
        cin >> height;
        heights.push_back(height);
        */
        cin >> heights[i];
    }
    heights[num + 1] = NULL;
    int caseNum;
    cin >> caseNum;
    while (caseNum--) {
        int caseHeight;
        cin >> caseHeight;
        
        int ans = 0;
        for (int i = 0; i <= num; i++) {
            if ((heights[i] == NULL||heights[i]<=caseHeight) && heights[i + 1] >caseHeight) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
    system("pause");
}