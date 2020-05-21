#ifndef CSTUDENT_H
#define CSTUDENT_H
#include<string.h>
using namespace std;

class Cstudent

{
    string name;

    int age;

    string gradeandclass;

public:

    Cstudent() { name = "shazi"; age = 0; gradeandclass = "first"; }
    Cstudent(string a, int b, string c);

    void show();

};

Cstudent::Cstudent(string a, int b, string c)
    :name(a), age(b), gradeandclass(c) {}

void Cstudent::show()

{

    cout << "name:" << name << endl;

    cout << "age:" << age << endl;

    cout << "grade and class:" << gradeandclass << endl;

}
#endif 