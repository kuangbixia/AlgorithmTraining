#include<iostream>
using namespace std;

int main() {
	float x = 13.14;
	float* ptr = &x;
	cout << "强制类型转换前：" << ptr << endl;
	int y = (int)ptr;
	cout << "强制类型转换后：" << y << endl;
	return 0;
}