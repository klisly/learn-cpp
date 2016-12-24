//
//  6StoreClass.cpp
//  algoritm
//
//  Created by wizardholy on 2016/12/24.
//  Copyright © 2016年 wizardholy. All rights reserved.
//
/**
 存储类定义 C++ 程序中变量/函数的范围（可见性）和生命周期。
 这些说明符放置在它们所修饰的类型之前。下面列出 C++ 程序中可用的存储类：
 auto
 register
 static
 extern
 mutable
 **/


#include <iostream>
using namespace std;
/*
 * 这个程序演示了有符号整数和无符号整数之间的差别
 */
void func(void);
static int ad = 10;

int data;

extern void write_extern();

int main()
{
    //auto 存储类
     // auto 存储类是所有局部变量默认的存储类。
    // ，auto 只能用在函数内，即 auto 只能修饰局部变量。


    short int i;           // 有符号短整数
    auto  j  = 1;  // 有符号短整数

    j = 50000;
    
    i = j;
    cout << i << " " << j << endl;
    /*
     uto第一种作用是为了自动类型推导
     auto的自动类型推导，用于从初始化表达式中推断出变量的数据类型。通过auto的自动类型推导，可以大大简化我们的编程工作
     auto实际上实在编译时对变量进行了类型推导，所以不会对程序的运行效率造成不良影响
     另外，似乎auto并不会影响编译速度，因为编译时本来也要右侧推导然后判断与左侧是否匹配。
     */
//    auto d = 1.0;
//    auto str = "Hello World";
//    auto ch = 'A';
//    auto func = less<int>();
    

//    vector<int> iv;
//    auto ite = iv.begin();
//    auto p = new foo() // 对自定义类型进行类型推导
   
    while(ad-- > 0){
        func();
    }
    
   // extern 存储类用于提供一个全局变量的引用，全局变量对所有的程序文件都是可见的。
    // 当您使用 'extern' 时，对于无法初始化的变量，会把变量名指向一个之前定义过的存储位置。
    
    /*
     
     extern 存储类用于提供一个全局变量的引用，全局变量对所有的程序文件都是可见的。当您使用 'extern' 时，对于无法初始化的变量，会把变量名指向一个之前定义过的存储位置。
     当您有多个文件且定义了一个可以在其他文件中使用的全局变量或函数时，可以在其他文件中使用 extern 来得到已定义的变量或函数的引用。可以这么理解，extern 是用来在另一个文件中声明一个全局变量或函数。
     extern 修饰符通常用于当有两个或多个文件共享相同的全局变量或函数的时候，如下所示：
     
     */
    
    data = 10;
    write_extern();
    /**
     mutable 存储类
     mutable 说明符仅适用于类的对象，这将在本教程的最后进行讲解。它允许对象的成员替代常量。
     也就是说，mutable 成员可以通过 const 成员函数修改。
     **/
    return 0;
}

void func(void){
    static int i = 6;
    i++;
    cout<<" i is :"<< i;
    cout << ", count is:" << ad << endl;
}
