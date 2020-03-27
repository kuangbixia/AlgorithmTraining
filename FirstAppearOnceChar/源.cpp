#include<iostream>
#include<map>
#include<vector>
using namespace std;

vector<char>str;
map<char, int>amap;

void Insert(char ch)
{
    
    amap[ch]++;
    str.push_back(ch);
}
//return the first appearence once char in current stringstream
char FirstAppearingOnce()
{
    for (int i = 0; i < str.size(); i++) {
        if (amap[str[i]] == 1) {
            return str[i];
        }
    }
    return '#';
}

int main() {
	Insert('g');
	cout << FirstAppearingOnce() << endl;
	Insert('o');
	cout << FirstAppearingOnce() << endl;
	Insert('o');
	cout << FirstAppearingOnce() << endl;
	Insert('g');
	cout << FirstAppearingOnce() << endl;
	Insert('l');
	cout << FirstAppearingOnce() << endl;
	Insert('e');
	cout << FirstAppearingOnce() << endl;
	return 0;
}