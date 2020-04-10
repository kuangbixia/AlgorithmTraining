#include<iostream>
using namespace std;

bool match(char* str, char* pattern)
{
    int si = 0;
    int pi = 0;
    if (str[si] == '\0') {
        if (pattern[pi] == '\0') {
            return true;
        }
        while (pattern[pi] != '\0') {
            if (pattern[pi + 1] != '*') {
                return false;
            }
            else {
                pi += 2;
            }
        }
    }
    while (*(pattern + pi) != '\0') {
        if (pattern[pi] == '.') {
            pattern[pi] = str[si];
        }
        if (pattern[pi] == str[si]) {
            if (pattern[pi + 1] == '*') {
                int pl = 1;
                int sl = 1;
                while (str[si + sl] == str[si]) {
                    sl++;
                }
                while (pattern[pi + pl + 1] == pattern[pi]) {
                    pl++;
                }
                if (pl - sl > 1) {
                    return false;
                }
                pi += (pl + 1);
                si += sl;
            }
            else {
                pi++;
                si++;
            }
        }
        else {
            if (pattern[pi + 1] == '*') {
                pi += 2;
                si++;
            }
            else {
                return false;
            }
        }
    }
    if (str[si] == '\0') {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    char str[] = "";
    char pattern[] = " ";
    cout << match(str, pattern) << endl;
    return 0;
}