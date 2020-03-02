#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int>testV({ 1,5,3 });
	int out1 = find(testV.begin(), testV.end(), 2) - testV.end();
	int out2 = find(testV.begin(), testV.end(), 3) - testV.end();
	cout << out1 << endl;
	cout << out2 << endl;
}