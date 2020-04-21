#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct animal {
    int num;
    int i;
    animal(int a, int b) :num(a), i(b) {}
};

vector<int> asylum(vector<vector<int> > ope) {
    // write code here
    queue<animal>dog;
    queue<animal>cat;
    vector<int>out;
    int k = 0;
    for (int i = 0; i < ope.size(); i++) {
        int op = ope[i][0];
        if (op == 1) {
            int num = ope[i][1];
            animal el(num, k++);
            if (num > 0) {
                dog.push(el);
            }
            else if (num < 0) {
                cat.push(el);
            }
        }
        else if (op == 2) {
            int type = ope[i][1];
            if (type == 0) {
                if (!dog.empty() && !cat.empty()) {
                    if (dog.front().i < cat.front().i) {
                        out.push_back(dog.front().num);
                        dog.pop();
                    }
                    else {
                        out.push_back(cat.front().num);
                        cat.pop();
                    }
                }
                else if (!dog.empty()) {
                    out.push_back(dog.front().num);
                    dog.pop();
                }
                else if (!cat.empty()) {
                    out.push_back(cat.front().num);
                    cat.pop();
                }
            }
            else if (type == 1) {
                if (!dog.empty()) {
                    out.push_back(dog.front().num);
                    dog.pop();
                }
            }
            else if (type == -1) {
                if (!cat.empty()) {
                    out.push_back(cat.front().num);
                    cat.pop();
                }
            }
        }
    }
    return out;
}

int main() {
    vector<vector<int>>in({ {1,-5} ,{1,-1},{1,9},{1,9},{2,0},{2,1},{1,-8},{2,1},{1,-71},{1,-92},{1,18},{1,91},{1,61},{2,-1} });
    vector<int>out = asylum(in);
    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << endl;
    }
    return 0;
}