#include<iostream>
#include<map>
using namespace std;

int main() {
	int num;
	cin >> num;
	if (num == 0||num==1) {
		cout << num << endl;
		return 0;
	}
	multimap<int, int>amap;
	int begin, end;
	int ans = 1;
	for (int i = 0; i < num; i++) {
		cin >> begin >> end;
		amap.insert(pair<int, int>(begin,end));
	}
	for (auto it = amap.begin(); it != amap.end(); it++) {
		int temp = 1;
		auto next = it;
		next++;
		for (; next != amap.end(); next++) {
			if (next->first >= it->second) {
				break;
			}
			else {
				temp++;
			}
		}
		if (temp > ans) {
			ans = temp;
		}
	}
	cout << ans << endl;
	return 0;
}