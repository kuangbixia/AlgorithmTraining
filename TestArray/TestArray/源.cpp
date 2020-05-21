#include<iostream>
#include<map>
using namespace std;

#define add(a,b)(a+b)

struct type1 {
	char a;
	char b;
	int c;
}x1;

struct type2
{
	char a;
	int b;
	char c;
}x2;

struct type3 {
	int a;
	char b;
	char c;
}x3;


void testPointer(int* p) {
	int another = 30;
	p = &another;
	cout << p << endl;
}

void testRef(int& x) {
	cout << &x << endl;
}

void testArray(int* arr) {
	cout << arr << endl;
}

int& testReturn() {
	static int a = 0;
	cout << a << endl;
	cout << &a << endl;
	return a;
}

int main() {
	/*const int X = 0;
	int Y = 3;
	int Z = 9;
	int& yy = Y;
	yy = Z;
	yy = 10;
	cout << yy << endl;*/

	/*const int* p = &X;
	cout << *p << endl;
	cout << add(1, 3) << endl;
	cout << sizeof(x1) << " " << sizeof(x2) << " " << sizeof(x3) << endl;*/

	/*int age = 18;
	int* ptr = &age;
	cout << *ptr << endl;
	testPointer(ptr);
	cout << *ptr << endl;
	cout << ptr << endl;*/

	/*int x = 10;
	cout << &x << endl;
	testRef(x);*/

	/*int arr[5] = {};
	cout << arr << endl;
	testArray(arr);*/

	/*int& b = testReturn();
	b = 100;
	cout << &b << endl;
	cout << b << endl;// bug
	testReturn();*/

	map<int, int, greater<int>>mp;
	mp[3] = 30;
	mp[6] = 15;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		cout << (*it).first << endl;
	}
	return 0;
}

