#include<iostream>
#include<string>
using namespace std;

int main() {
	string n;
	int j;
	int ans = 0;
	cout << "输入二进制：";
	cin >> n;
	for (int i = 0; i < n.size(); i++) {
		if (n[i] == '1') {
			ans += pow(2, n.size() - i - 1);
		}
	}
	cout << ans << endl;
	return 0;
}