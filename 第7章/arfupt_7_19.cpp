#include <iostream>

const double* f1(const double ar[], int n);
const double* f2(const double[], int);
const double* f3(const double*, int);

int main()
{
    using namespace std;

    double av[3] = {1112.3, 1542.6, 2227.9};

    const double* (*p1)(const double*, int) = f1;   //函数指针p1指向f1

    auto p2 = f2;       //p2指向f2

    cout << "Using pointers to functions:\n";
    cout << " Address Value\n";
    cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl;      //函数指针间接访问，函数返回地址，再对地址进行间接访问，获得数组第一个元素的内容
    cout << p2(av, 3) << ": " << *p2(av, 3) << endl;            //函数指针使用的另一种形式

    const double *(*pa[3])(const double*, int) = {f1, f2, f3};      //pa是数组，数组中有三个元素，元素为函数指针
    auto pb = pa;
    cout << "\nUsing an array of pointers to functions:\n";
    cout << " Address Value\n";
    for(int i = 0; i < 3; i++)
        cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << endl;

    cout << "\nUsing a pointer to a pointer to a function:\n";
    cout << " Address Value\n";
    for(int i = 0; i < 3; i++)
        cout << pb[i](av, 3) << ": " << *pb[i](av, 3) << endl;
    
    cout << "\nUsing pointer to an array of pointers:\n";
    cout << " Address Value\n";
    auto pc = &pa;                                                  //pc类型为指针，pa是数组，所以pc为指向数组的指针
    cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << endl;

    const double *(*(*pd)[3])(const double*, int) = &pa;            //pd是指针，指向数组，数组有3个元素，数组元素的类型为函数指针
    const double* pdb = (*pd)[1](av, 3);                               //用函数返回值赋值给pdb，pdb是指针，指向double类型
    cout << pdb << ": " << *pdb << endl;
    cout << (*(*pd)[2])(av, 3) << ": " << *(*(*pd)[2])(av, 3) << endl;
    return 0;
}

const double * f1(const double * ar, int n)
{
    return ar;
}

const double * f2(const double ar[], int n)
{
    return ar+1;
}

const double * f3(const double ar[], int n)
{
    return ar+2;
}
