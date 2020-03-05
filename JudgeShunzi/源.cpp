#include<iostream>
using namespace std;

int main() {
	int poker[14] = {};
	char ch;
	while (true) {
		ch = cin.get();
		if (ch == '\n') {
			break;
		}
		switch (ch) {
		case 'A':
			poker[1]++;
			break;
		case '1':
			ch = cin.get();
			if (ch == '0') {
				poker[10]++;
			}
			break;
		case 'J': 
			poker[11]++;
			break;
		case 'Q':
			poker[12]++;
			break;
		case 'K':
			poker[13]++;
			break;
		default:
			if (ch != ' ') {
				poker[ch - '0']++;
			}
		}
	}

	for (int i = 1; i <= 13; i++) {
		cout << poker[i] << " ";
	}
	int ShunziCount = 0;
	int ShunziLength = 5;
	while (ShunziLength < 14) {
		for (int i = 1; i <= 13; i++) {
			int j;
			for (j = 0; j < ShunziLength; j++) {
				if (poker[i + j] < 1) {
					break;
				}
			}
			if (j == ShunziLength) {
				ShunziCount++;
			}
		}
		ShunziLength++;
	}

	cout << "\nË³×Ó¸öÊý£º" << ShunziCount << endl;
	return 0;
}