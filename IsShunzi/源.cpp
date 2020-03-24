#include<iostream>
#include<vector>
using namespace std;

bool IsContinuous(vector<int> numbers) {
    if (numbers.size() == 0) {
        return false;
    }
    int poke[14] = {};
    for (int i = 0; i < numbers.size(); i++) {
        poke[numbers[i]]++;
    }
    int shunziCnt = 0;
    for (int i = 1; i < 14; i++) {
        if (poke[i] > 1) {
            return false;
        }
        if (poke[i] == 1) {
            shunziCnt++;
        }
        else {
            // 找到了顺子的头
            if (shunziCnt>0) {
                if (poke[0]) {
                    shunziCnt++;
                    poke[0]--;
                }
                else {
                    break;
                }
            }
        }
    }
    // 顺子的头在后面，如11，12，13，0，0
    if (shunziCnt+poke[0] == numbers.size()) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    vector<int>numbers({0,0,11,12,13});
    cout << IsContinuous(numbers);
    return 0;
}