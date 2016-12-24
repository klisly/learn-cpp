#include <iostream>
using namespace std;

/**
 当您使用多个文件且只在其中一个文件中定义变量时（定义变量的文件在程序连接时是可用的），变量声明就显得非常有用。您可以使用 extern 关键字在任何地方声明一个变量。虽然您可以在 C++ 程序中多次声明一个变量，但变量只能在某个文件、函数或代码块中被定义一次。
 **/
// 变量声明
extern int a, b;
extern int c;
extern float f;
//同样的，在函数声明时，提供一个函数名，而函数的实际定义则可以在任何地方进行。例如：

int func(int a); // 函数声明

/**
 左值（lvalue）：指向内存位置的表达式被称为左值（lvalue）表达式。左值可以出现在赋值号的左边或右边。
 右值（rvalue）：术语右值（rvalue）指的是存储在内存中某些地址的数值。右值是不能对其进行赋值的表达式，也就是说，右值可以出现在赋值号的右边，但不能出现在赋值号的左边。
 变量是左值，因此可以出现在赋值号的左边。数值型的字面值是右值，因此不能被赋值，不能出现在赋值号的左边。
 **/
int main ()
{
    // 变量定义
    int a, b;
    int c;
    float f;
    
    // 实际初始化
    a = 10;
    b = 20;
    c = a + b;
    
    cout << c << endl ;
    
    f = 70.0/3.0;
    cout << f << endl ;
    cout << func(a) << endl;
    return 0;
}

int func(int a){
    return a * 10;
}
