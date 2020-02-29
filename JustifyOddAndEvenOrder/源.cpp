#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int>array({ 1,2,3,4,5,6 });
    for (int i = 0; i < array.size(); i++) {
        if (array[i] % 2) {
            int odd = array[i];
            int j;
            for (j = i - 1; j >= 0; j--) {
                if (array[j] % 2) {
                    break;
                }
                else {
                    array[j + 1] = array[j];
                }
            }
            array[j + 1] = odd;
        }
    }
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << endl;
    }
	return 0;
	system("pause");
}