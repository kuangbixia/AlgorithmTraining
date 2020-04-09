#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int main() {
    int group;
    cin >> group;
    while (group--) {
        int count;
        cin >> count;
        vector<int>ids;
        while (count--) {
            int id;
            cin >> id;
            if (ids.size() == 0) {
                ids.push_back(id);
            }
            else {
                vector<int>::iterator it = find(ids.begin(), ids.end(), id);
                if (it != ids.end()) {
                    while (it > ids.begin()) {
                        *it = *(it-1);
                        it--;
                    }
                    *it = id;
                }
                else {
                    ids.push_back(id);
                    int i;
                    for (i = ids.size() - 1; i > 0; i--) {
                        ids[i] = ids[i - 1];
                    }
                    ids[i] = id;
                }
            }
        }
        for (int j = 0; j < ids.size(); j++) {
            cout << ids[j] << " ";
        }
        if (group > 0) {
            cout << endl;
        }
    }
    return 0;
}