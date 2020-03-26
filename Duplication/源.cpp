#include<iostream>
using namespace std;

bool duplicate(int numbers[], int length, int* duplication) {
    int* hash = new int[length]();
    for (int i = 0; i < length; i++) {
        if (numbers[i] >= length || numbers[i] < 0) {
            return false;
        }
        hash[numbers[i]]++;
    }
    for (int i = 0; i < length; i++) {
        if (hash[i] > 1) {
            *duplication = i;
            return true;
        }
    }
    return false;
}

int main() {
    int numbers[] = { 1,3,2,3 };
    int* dup = new int();
    cout << duplicate(numbers, 4, dup) << endl;
    cout << *dup << endl;
    return 0;
}