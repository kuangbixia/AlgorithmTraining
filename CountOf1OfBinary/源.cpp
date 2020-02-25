#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int group;
    cin >> group;
    while (group--) {
        int length;
        cin >> length;
        vector<int>counts;
        for (int i = 0; i < length; i++) {
            int sample;
            cin >> sample;
            int count = 0;
            if (sample == 0) {
                counts.push_back(count);
                continue;
            }
            while (sample) {
                count += sample % 2;
                sample /= 2;
            }
            counts.push_back(count);
        }
        // Ҫ������
        sort(counts.begin(), counts.end());
        // uniqueȥ�������ڡ����ظ�Ԫ��
        /*
        counts.erase(unique(counts.begin(), counts.end()), counts.end());
        cout << counts.size() << endl;
        */
        cout << unique(counts.begin(), counts.end()) - counts.begin() << endl;
    }
    return 0;
    system("pause");
}