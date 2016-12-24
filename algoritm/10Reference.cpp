//
//  9Pointer.cpp
//  algoritm
//
//  Created by wizardholy on 2016/12/24.
//  Copyright © 2016年 wizardholy. All rights reserved.
//
/**
 引用变量是一个别名，也就是说，它是某个已存在变量的另一个名字。
 一旦把引用初始化为某个变量，就可以使用该引用名称或变量名称来指向变量。
 不存在空引用。引用必须连接到一块合法的内存。
 一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
 引用必须在创建时被初始化。指针可以在任何时间被初始化。
 
 试想变量名称是变量附属在内存位置中的标签，您可以把引用当成是变量附属在内存位置中的第二个标签。因此，您可以通过原始变量名称或引用来访问变量的内容。例如：
 int i = 17;
 我们可以为 i 声明引用变量，如下所示：
 int&    r = i;
 在这些声明中，& 读作引用。因此，第一个声明可以读作 "r 是一个初始化为 i 的整型引用"，第二个声明可以读作 "s 是一个初始化为 d 的 double 型引用"。下面的实例使用了 int 和 double 引用：

 **/
#include <iostream>

using namespace std;
const int MAX = 3;
double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};

double& setValues( int i )
{
    return vals[i];   // 返回第 i 个元素的引用
}

// 函数声明
void swap(int& x, int& y);
int main ()
{
    // 声明简单的变量
    int    i;
    double d;
    
    // 声明引用变量
    int&    r = i;
    double& s = d;
    
    i = 5;
    cout << "Value of i : " << i << endl;
    cout << "Value of i reference : " << r  << endl;
    
    d = 11.7;
    cout << "Value of d : " << d << endl;
    cout << "Value of d reference : " << s  << endl;
    /*
     把引用作为参数
     */
    // 局部变量声明
    int a = 100;
    int b = 200;
    
    cout << "交换前，a 的值：" << a << endl;
    cout << "交换前，b 的值：" << b << endl;
    
    /* 调用函数来交换值 */
    swap(a, b);
    
    cout << "交换后，a 的值：" << a << endl;
    cout << "交换前，b 的值：" << b << endl;
    /*
     把引用作为返回值
     通过使用引用来替代指针，会使 C++ 程序更容易阅读和维护。C++ 函数可以返回一个引用，方式与返回一个指针类似。
     当函数返回一个引用时，则返回一个指向返回值的隐式指针。这样，函数就可以放在赋值语句的左边。
     当返回一个引用时，要注意被引用的对象不能超出作用域。所以返回一个对局部变量的引用是不合法的，但是，可以返回一个对静态变量的引用。
     int& func() {
     int q;
     //! return q; // 在编译时发生错误
     static int x;
     return x;     // 安全，x 在函数作用域外依然是有效的
     }
     */
    cout << "改变前的值" << endl;
    for ( int i = 0; i < 5; i++ )
    {
        cout << "vals[" << i << "] = ";
        cout << vals[i] << endl;
    }
    
    setValues(1) = 20.23; // 改变第 2 个元素
    setValues(3) = 70.8;  // 改变第 4 个元素
    
    cout << "改变后的值" << endl;
    for ( int i = 0; i < 5; i++ )
    {
        cout << "vals[" << i << "] = ";
        cout << vals[i] << endl;
    }
    return 0;
}

// 函数定义
void swap(int& x, int& y)
{
    int tmp = x;
    x = y;
    y = tmp;
    return;
}

