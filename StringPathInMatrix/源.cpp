#include<iostream>
using namespace std;

bool findPath(char* matrix, int rows, int cols, char* str, int i, int j) {
    bool t = false;
    bool r = false;
    bool d = false;
    bool l = false;
    if (i != 0) {
        if (matrix[(i - 1)*cols+j] == *str) {
            matrix[(i - 1) * cols + j] = ' ';
            if (*(str + 1) == '\0') {
                return true;
            }
            t = findPath(matrix, rows, cols, str + 1, i - 1, j);
            if (t) {
                return true;
            }
            else {
                matrix[(i - 1) * cols + j] = *str;
            }
        }
    }
    if (j != (cols - 1)) {
        if (matrix[i*cols+j + 1] == *str) {
            matrix[i*cols+j + 1] = ' ';
            if (*(str + 1) == '\0') {
                return true;
            }
            r = findPath(matrix, rows, cols, str + 1, i, j + 1);
            if (r) {
                return true;
            }
            else {
                matrix[i * cols + j + 1] = *str;
            }
        }
    }
    if (i != (rows - 1)) {
        if (matrix[(i + 1)*cols+j] == *str) {
            matrix[(i + 1)*cols+j] = ' ';
            if (*(str + 1) == '\0') {
                return true;
            }
            d = findPath(matrix, rows, cols, str + 1, i + 1, j);
            if (d) {
                return true;
            }
            else {
                matrix[(i + 1) * cols + j] = *str;
            }
        }
    }
    if (j != 0) {
        if (matrix[i*cols+j - 1] == *str) {
            matrix[i*cols+j - 1] = ' ';
            if (*(str + 1) == '\0') {
                return true;
            }
            l = findPath(matrix, rows, cols, str + 1, i, j - 1);
            if (l) {
                return true;
            }
            else {
                matrix[i * cols + j - 1] = *str;
            }
        }
    }
    return false;
}
bool hasPath(char* matrix, int rows, int cols, char* str)
{
    bool find = false;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i*cols+j] == *str) {
                matrix[i*cols+j] = ' ';
                if (*(str + 1) == '\0') {
                    return true;
                }
                find = findPath(matrix, rows, cols, str + 1, i, j);
                if (find) {
                    return true;
                }
                else {
                    matrix[i*cols+j] = *str;
                }
            }
        }
    }
    return false;
}
