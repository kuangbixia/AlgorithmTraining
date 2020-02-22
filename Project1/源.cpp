#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    vector<int>nums({ 0,0,0,0 });
    vector<vector<int>> ans;
    if (nums.size() < 3) {
        //return ans;
        cout << "bad input" << endl;
    }

    sort(nums.begin(), nums.end());

    for (int k = nums.size() - 1; k > 1; k--) {
        while (k < (nums.size() - 1) && k>1&&nums[k] == nums[k + 1]) {
            k--;
        }
        int target = nums[k];
        int l = 0;
        int r = k - 1;
        while (r > l) {
            int sum = nums[l] + nums[r];
            if (sum > -target) {
                while (r > l&& nums[r] == nums[--r]);
            }
            else if (sum < -target) {
                while (r > l&& nums[l] == nums[++l]);
            }
            else {
                vector<int> ele;
                ele.push_back(nums[l]);
                ele.push_back(nums[r]);
                ele.push_back(nums[k]);
                ans.push_back(ele);

                //去重
                while (r > l&& nums[r] == nums[--r] && nums[l] == nums[++l]);
            }
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
    }
    //return ans;
    
    return 0;
    system("pause");

 }

// 只有去重能拯救超时
