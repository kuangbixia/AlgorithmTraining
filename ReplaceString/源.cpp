#include<iostream>
#include<string>
using namespace std;

int main() {
	char _str[] = " helloworld";
	char* str = _str;
	int length = 12;
	int blank = 0;
	for (int i = 0; i < length; i++) {
		cout << *(str + i) << endl;
		if (*(str+i)==' ') {
			blank++;
		}
	}
	cout << "--------" << endl;

	int ansLength = length + blank*2;
	for (int i = 0; i < length; i++) {
		cout << *(str + length - 1 - i) << endl;
		if (*(str + length - 1 - i) == ' ') {
			ansLength--;
			*(str + ansLength) = '0';
			ansLength--;
			*(str + ansLength) = '2';
			ansLength--;
			*(str + ansLength) = '%';
		}
		else {
			ansLength--;
			*(str + ansLength) = *(str + length - 1 - i);
		}
	}
	cout << "--------" << endl;

	cout << str << endl;
	return 0;
	system("pause");
}
