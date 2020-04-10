#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*string PrintMinNumber(vector<int> numbers) {
    string ans;
    if (numbers.empty()) {
        return ans;
    }
    vector<vector<int>>sequence;
    vector<vector<int>>temp;
    int n = 0;
    sequence.push_back({ numbers[n++] });
    while (n < numbers.size()) {
        for (int i = 0; i < sequence.size(); i++) {
            for (int j = 0; j <= sequence[i].size(); j++) {
                vector<int>r;
                r.resize(sequence[i].size() + 1);
                r[j] = numbers[n];
                int k;
                for (k = 0; k < r.size() && k != j; k++) {
                    r[k] = sequence[i][k];
                }
                while ((++k) < r.size()) {
                    r[k] = sequence[i][k - 1];
                }
                temp.push_back(r);
            }
        }
        sequence = temp;
        for (int p = 0; p < sequence.size(); p++) {
            for (int q = 0; q < sequence[p].size(); q++) {
                cout << sequence[p][q] << " ";
            }
            cout << endl;
        }
        temp.resize(0);
        n++;
    }
    vector<string>str;
    for (int i = 0; i < sequence.size(); i++) {
        string t("");
        for (int j = 0; j < sequence[i].size(); j++) {
            t += to_string(sequence[i][j]);
        }
        str.push_back(t);
    }
    ans = str[0];
    for (int i = 0; i < str.size(); i++) {
        cout << str[i] << endl;
        if (str[i] < ans) {
            ans = str[i];
        }
    }
    return ans;
}*/

// 预排序：排序条件是组合后的字符串小
string PrintMinNumber(vector<int> numbers) {
    string ans = "";
    if (numbers.empty()) {
        return ans;
    }
    for (int i = 0; i < numbers.size() - 1; i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            string strF = to_string(numbers[i]) + to_string(numbers[j]);
            string strB = to_string(numbers[j]) + to_string(numbers[i]);
            if (strB < strF) {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    for (int i = 0; i < numbers.size(); i++) {
        ans += to_string(numbers[i]);
    }
    return ans;
}

int main() {
    vector<int>input({ 3,5,1,4,2 });
    cout << PrintMinNumber(input) << endl;
	return 0;
}