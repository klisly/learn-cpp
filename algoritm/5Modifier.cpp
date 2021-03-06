//
//  Modifier.cpp
//  algoritm
//
//  Created by wizardholy on 2016/12/24.
//  Copyright © 2016年 wizardholy. All rights reserved.
//

/**
 下面列出了数据类型修饰符：
 signed
 unsigned
 long
 short
 修饰符 signed、unsigned、long 和 short 可应用于整型，signed 和 unsigned 可应用于字符型，long 可应用于双精度型。
 修饰符 signed 和 unsigned 也可以作为 long 或 short 修饰符的前缀。例如：unsigned long int。
 
 C++ 允许使用速记符号来声明无符号短整数或无符号长整数。您可以不写 int，只写单词 unsigned、short 或 unsigned、long，int 是隐含的。例如，下面的两个语句都声明了无符号整型变量。
 
 C++ 中的类型限定符
 类型限定符提供了变量的额外信息。
 限定符	含义
 const	const 类型的对象在程序执行期间不能被修改改变。
 volatile	修饰符 volatile 告诉编译器，变量的值可能以程序未明确指定的方式被改变。
 restrict	由 restrict 修饰的指针是唯一一种访问它所指向的对象的方式。只有 C99 增加了新的类型限定符 restrict。

 **/

#include <iostream>
using namespace std;

/*
 * 这个程序演示了有符号整数和无符号整数之间的差别
 */
int main()
{
    short int i;           // 有符号短整数
    short unsigned int j;  // 无符号短整数
    
    j = 50000;
    
    i = j;
    cout << i << " " << j;
    
    return 0;
}
