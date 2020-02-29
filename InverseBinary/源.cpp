#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int count = 0;
	/*
	if (n > 0) {
		while (n) {
			count += (n % 2);
			n /= 2;
		}
	}
	else if (n < 0) {
		count++;
		// int类型有32位
		n = pow(2, 31) + n;
		while (n) {
			count += (n % 2);
			n /= 2;
		}
	}
	*/
	int temp = 1;
	while (temp) {
		if (temp & n) {
			count++;
		}
		temp <<= 1;
	}
	
	cout << count << endl;
	return 0;
	system("pause");
}