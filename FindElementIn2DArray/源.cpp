#include<iostream>
#include<vector>
using namespace std;

bool Find(int target, vector<vector<int> > array) {
    if (array.size() == 0) {
        return false;
    }
    if (array[0].size() == 0) {
        return false;
    }
    for (int i = 0; i < array.size(); i++) {
        if (array[i][0] <= target) {
            for (int j = 0; j < array[i].size(); j++) {
                if (array[i][j] == target) {
                    return true;
                }
                else if (array[i][j] > target) {
                    return false;
                }
            }
        }
        else {
            return false;
        }
    }
    return false;
}

int main() {
    vector<vector<int>>array;
    int target = 2;
    array.resize(2);
    array[0] = vector<int>({  });
    array[1] = vector<int>({  });
    cout << Find(target, array) << endl;
    return 0;
    system("pause");
}