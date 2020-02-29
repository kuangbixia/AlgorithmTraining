#include<iostream>
using namespace std;

int main() {
	int number = 229;
	cout << "number address: " << &number << endl;
	int* pointer = &number;
	cout << "pointer address: " << &pointer << endl;
	cout << "pointer value: " << pointer << endl;
	cout << "pointer point to value: " << *pointer << endl;
	return 0;
	system("pause");
}