#include<iostream>
using namespace std;

bool match(char* str, char* pattern)
{
    // ƥ�����
    if (str[0] == '\0' && pattern[0] == '\0') {
        return true;
    }
    // '*'ǰ�ķ��Ų�����
    if (pattern[0] != '\0' && pattern[1] == '*') {
        if (match(str, pattern + 2)) {
            return true;
        }
    }
    // ���ַ�ƥ�䣬����ƥ����pattern�е�'.'
    if (pattern[0] == str[0] || (str[0] != '\0' && pattern[0] == '.')) {
        if (match(str + 1, pattern + 1)) {
            return true;
        }
        // pattern[0]���������'*'����ʾstr[0]���ܻ������
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