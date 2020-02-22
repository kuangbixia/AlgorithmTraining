#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int>nums1({ 1,3 });
    vector<int>nums2({ 2 });

    int length1 = nums1.size();
    int length2 = nums2.size();
    int length = length1 + length2;
    int odd = length % 2;
    int pos = length / 2;
    double ans = 0;
    int p1 = 0;
    int p2 = 0;
    vector<int>nums;

    cout << 0 - 1 << endl;

    while (nums.size() < pos + 1) {
        if (p1 == length1 && p2 < length2) {
            nums.push_back(nums2[p2]);
            p2++;
        }
        else if (p2 == length2 && p1 < length1) {
            nums.push_back(nums1[p1]);
            p1++;
        }
        else if (nums1[p1] < nums2[p2]) {
            nums.push_back(nums1[p1]);
            p1++;
        }
        else if (nums1[p1] >= nums2[p2]) {
            nums.push_back(nums2[p2]);
            p2++;
        }

    }

    if (odd) {
        ans = nums[pos];
    }
    else {
        ans = nums[pos - 1] + nums[pos];
        ans /= 2;
    }

    cout << ans << endl;
    return 0;
    system("pause");
}
