#include<iostream>
#include<ctime>
#include<iomanip> 
using namespace std;

int h;
int m;
int s;

int main()
{
	int x;
	int y;
	int a;
	a = time(0);
	while (1) {
		x = time(0);
		y = x - a;
		h = y / 3600;
		m = (y % 3600) / 60;
		s = (y % 3600) % 60;
		cout << setfill('0') << setw(2) << h << ":" << setw(2) << m << ":" << setw(2) << s << endl;
	}


}

