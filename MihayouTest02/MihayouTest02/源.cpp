#include<iostream>
#include<cstring>
#include<map>
using namespace std;

int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i]-'A' >= 0 && str[i]-'Z' <= 0) {
			str[i] = char('a' + (str[i] - 'A'));
		}
	}
	map<char, int>amap;
	for (int i = str.length()-1; i >= 0;) {
		if (str[i] >= '0' && str[i] <= '9') {
			int time = str[i] - '0';
			int p = 1;
			int bit = 1;
			for (int j = i - 1; j >= 0; j--) {
				if (str[j] >= '0' && str[j] <= '9') {
					p *= 10;
					time += (str[j] - '0') * p;
				}
				else {
					break;
				}
			}
			i -= bit;
			amap[str[i]] += time;
			i--;
			while (i>=0&&!(str[i]>='0'&&str[i]<='9')) {
				if (str[i] == '-') {
					char begin = str[i - 1];
					if (begin < str[i+1]) {
						for (int k = begin; k < str[i+1]; k++) {
							amap[char(k)] += time;
						}
					}
					else {
						for (int k = begin; k <= 'z'; k++) {
							amap[char(k)] += time;
						}
						for (int k = 'a'; k < str[i+1]; k++) {
							amap[char(k)] += time;
						}
					}
					i -= 2;
				}
				else {
					amap[str[i]] += time;
					i--;
				}
			}

		}

	}
	auto it = amap.begin();
	char c = it->first;
	int max = it->second;
	for (; it != amap.end(); it++) {
		if (it->second > max) {
			max = it->second;
			c = it->first;
		}
	}
	cout << c << max << endl;
	return 0;
}