#include<iostream>
#include<vector>
#include<map>
using namespace std;

/*void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) {
    if (data.size() == 0) {
        return;
    }
    if (data.size() == 1) {
        *num1 = data[0];
        return;
    }
    if (data.size() == 2) {
        *num1 = data[0];
        *num2 = data[1];
        return;
    }
    for (int i = 1; i < data.size(); i++) {
        int temp = data[i];
        int j;
        for (j = i - 1; j >= 0; j--) {
            if (data[j] > temp) {
                data[j + 1] = data[j];
            }
            else {
                break;
            }
        }
        data[j + 1] = temp;
    }

    bool find1 = false;
    bool find2 = false;
    for (int i = 0; i < data.size(); i++) {
        if (i == 0) {
            if (data[i] != data[i + 1]) {
                find1 = true;
                *num1 = data[i];
            }
        }
        else if (i == data.size() - 1) {
            if (data[i] != data[i - 1]) {
                find2 = true;
                *num2 = data[i];
                return;
            }
        }
        else {
            if (data[i - 1] != data[i] && data[i] != data[i + 1]) {
                if (!find1) {
                    *num1 = data[i];
                    find1 = true;
                }
                else {
                    *num2 = data[i];
                    find2 = true;
                    return;
                }
            }
        }
       
    }
}*/
void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) {
    map<int, int>temp;
    for (int i = 0; i < data.size(); i++) {
        temp[data[i]]++;
    }
    bool find1 = false;
    map<int, int>::iterator it;
    for (it = temp.begin(); it != temp.end(); it++) {
        if (it->second == 1) {
            if (!find1) {
                *num1 = it->first;
                find1 = true;
            }
            else {
                *num2 = it->first;
                break;
            }
        }
    }
    return;
}

int main() {
    vector<int>arr({ 2,2});
    int* num1 = new int();
    int* num2 = new int();
    FindNumsAppearOnce(arr, num1, num2);
    cout << *num1 << " " << *num2 << endl;
    return 0;
}