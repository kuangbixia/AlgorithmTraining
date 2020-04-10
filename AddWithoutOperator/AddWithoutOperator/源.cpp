#include<iostream>
using namespace std;

int Add(int num1, int num2)
{
    int _xor = num1 ^ num2;
    int _and = num1 & num2;
    _and = _and << 1;
    if (_and) {
        return Add(_xor, _and);
    }
    else {
        return _xor;
    }
}
int main() {
    cout << Add(5, 7) << endl;
    return 0;
}