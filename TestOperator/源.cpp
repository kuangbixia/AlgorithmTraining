#include<iostream>
#include<queue>
using namespace std;

int main() {
	int array[10] = { 55, 34, 21, 13, 8, 5, 3, 2, 1, 1 };
	int num = 3;
	int excited = (num & 2 | 1);
	int ha = (num & 1 | num);
	queue<int>q;
	for (int i = 0; i <= excited; i++) {
		cout << (i ^ 3) << endl;
		q.push(array[i ^ 3]);
	}
	for (int i = 1; i <= ha; i++) {
		q.pop();
	}
	cout << excited << " " << ha << endl;
	cout << q.size() << endl;
	cout << q.front() << endl;
	return 0;
}