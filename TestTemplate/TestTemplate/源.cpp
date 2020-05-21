#include<iostream>
using namespace std;

class Base {
public:
	virtual ~Base() {

	}
};

class Derived :public Base {

};

template<class T>
auto add(T a, T b) {
	return a + b;
}

int main() {
	//cout << add(1.2, 3.4) << endl;

	/*int* pi = (int*)malloc(3 * sizeof(int));
	for (int i = 0; i < 3; i++) {
		*pi = i;
		cout << *pi << endl;
		pi++;
	}*/
	/*const int size = 2000;
	int* p = (int*)malloc(20 * sizeof(int));
	*p = 0;
	cout << p << endl;
	p = (int*)realloc(p, size * sizeof(int));
	*p = 1;
	cout << p << endl;
	free(p);
	cout << p << endl;// 本身没有释放
	cout << *p << endl;// 指向的内容被释放*/


	/*int* p = new int;
	*p = 10; // 假如未初始化，就会随机分配一个值
	cout << *p << endl;
	delete p;
	p = NULL;
	cout << p << endl;*/

	/*Base b;
	Derived d;
	Derived* pd;
	pd = (Derived*)(&b);
	cout << pd << endl;
	pd = reinterpret_cast<Derived*> (&b);
	cout << pd << endl;
	pd = dynamic_cast<Derived*> (&b);// 不抛出异常，返回空指针
	cout << pd << endl;
	Derived& rd = dynamic_cast<Derived&>(b);// 抛出异常，因为没有空引用*/

	/*int x = 9;
	float& pf = reinterpret_cast<float&>(x);*/

	char c = '4';
	float f = static_cast<float>(c);
	cout << f << endl;

	return 0;
}