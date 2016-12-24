//
//  7Function.cpp
//  algoritm
//
//  Created by wizardholy on 2016/12/24.
//  Copyright © 2016年 wizardholy. All rights reserved.
//
/**
 函数声明会告诉编译器函数名称及如何调用函数。函数的实际主体可以单独定义。
 函数声明包括以下几个部分：
 return_type function_name( parameter list );
 针对上面定义的函数 max()，以下是函数声明：
 int max(int num1, int num2);
 在函数声明中，参数的名称并不重要，只有参数的类型是必需的，因此下面也是有效的声明：
 int max(int, int);
 当您在一个源文件中定义函数且在另一个文件中调用函数时，函数声明是必需的。在这种情况下，您应该在调用函数的文件顶部声明函数。
 
 
 **/

#include <iostream>
using namespace std;

// 函数声明
int max(int num1, int num2);

int main ()
{
    // 局部变量声明
    int a = 100;
    int b = 200;
    int ret;
    
    // 调用函数来获取最大值
    ret = max(a, b);
    
    cout << "Max value is : " << ret << endl;
    
    /**
     如果函数要使用参数，则必须声明接受参数值的变量。这些变量称为函数的形式参数。
     形式参数就像函数内的其他局部变量，在进入函数时被创建，退出函数时被销毁。
     当调用函数时，有两种向函数传递参数的方式：
     调用类型	描述
     传值调用	该方法把参数的实际值复制给函数的形式参数。在这种情况下，修改函数内的形式参数对实际参数没有影响。
     指针调用	该方法把参数的地址复制给形式参数。在函数内，该地址用于访问调用中要用到的实际参数。这意味着，修改形式参数会影响实际参数。
     引用调用	该方法把参数的引用复制给形式参数。在函数内，该引用用于访问调用中要用到的实际参数。这意味着，修改形式参数会影响实际参数。
     默认情况下，C++ 使用传值调用来传递参数。一般来说，这意味着函数内的代码不能改变用于调用函数的参数。之前提到的实例，调用 max() 函数时，使用了相同的方法。
     **/
    
    return 0;
}

// 函数返回两个数中较大的那个数
int max(int num1, int num2)
{
    // 局部变量声明
    int result;
    
    if (num1 > num2)
        result = num1;
    else
        result = num2;
    
    return result; 
}
