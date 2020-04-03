#include<iostream>
#include<vector>
using namespace std;

vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
    vector<int>ans;
    if (num.empty() || num.size() < size) {
        return ans;
    }
    int i = 0;
    while (i <= (num.size() - size)) {
        int max = num[i];
        for (int w = 0; w < size; w++) {
            if (num[i + w] > max) {
                max = num[i + w];
            }
        }
        ans.push_back(max);
        i++;
    }
    return ans;
}

int main() {
    const vector<int>input({ 2,3,4,2,6,2 });
    vector<int>output = maxInWindows(input, 3);
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << endl;
    }
    return 0;

}