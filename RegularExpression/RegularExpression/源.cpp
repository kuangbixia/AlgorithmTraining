#include<iostream>
using namespace std;

bool match(char* str, char* pattern)
{
    // 匹配完毕
    if (str[0] == '\0' && pattern[0] == '\0') {
        return true;
    }
    // '*'前的符号不出现
    if (pattern[0] != '\0' && pattern[1] == '*') {
        if (match(str, pattern + 2)) {
            return true;
        }
    }
    // 首字符匹配，包括匹配了pattern中的'.'
    if (pattern[0] == str[0] || (str[0] != '\0' && pattern[0] == '.')) {
        if (match(str + 1, pattern + 1)) {
            return true;
        }
        // pattern[0]后面可能是'*'，表示str[0]可能还会出现
        if (pattern[1] == '*') {
            if (match(str + 1, pattern)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    char str[] = "";
    char pattern[] = " ";
    cout << match(str, pattern) << endl;
    return 0;
}