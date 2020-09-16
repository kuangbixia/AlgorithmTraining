#include<iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
int removeElement(int A[], int n, int elem) {
    int f = 0;
    int b = n - 1;
    while (f < b) {
        if (A[f] == elem) {
            swap(A[f], A[b]);
            b--;
        }
        else {
            f++;
        }
    }
    return A[f] == elem ? f : f+1;
}

int main() {
    int A[] = { 1,2,3,4,1,5,1,6 };
    cout << removeElement(A, 8, 1) << endl;
}