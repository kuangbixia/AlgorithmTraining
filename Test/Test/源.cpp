#include<iostream>
#include<vector>
using namespace std;

int main() {
	/*int num;
	cin >> num;
	vector<int>arr;
	arr.push_back(num);
	char c;
	while ((c = getchar()) != '\n') {
		cin >> num;
		arr.push_back(num);

	}*/
	/*string astr;
	getline(cin, astr);
	stringstream s(astr);
	int num;
	vector<int>arr;
	while (s >> num) {
		arr.push_back(num);
	}*/
	vector<int>arr;
	int num;
	while (cin >> num) {
		arr.push_back(num);
		if (cin.get() == '\n') {
			break;
		}
	}
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	return 0;
}