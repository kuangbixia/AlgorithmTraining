#include<iostream>
using namespace std;

int main() {
	float x = 13.14;
	float* ptr = &x;
	cout << "ǿ������ת��ǰ��" << ptr << endl;
	int y = (int)ptr;
	cout << "ǿ������ת����" << y << endl;
	return 0;
}