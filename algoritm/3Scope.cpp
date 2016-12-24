//
//  3Scope.cpp
//  algoritm
//
//  Created by wizardholy on 2016/12/24.
//  Copyright © 2016年 wizardholy. All rights reserved.
//
/**
 作用域是程序的一个区域，一般来说有三个地方可以声明变量：
 在函数或一个代码块内部声明的变量，称为局部变量。
 在函数参数的定义中声明的变量，称为形式参数。
 在所有函数外部声明的变量，称为全局变量。
 在程序中，局部变量和全局变量的名称可以相同，但是在函数内，局部变量的值会覆盖全局变量的值。下面是一个实例：

 当局部变量被定义时，系统不会对其初始化，您必须自行对其初始化。定义全局变量时，系统会自动初始化为下列值：
 数据类型	初始化默认值
 int	0
 char	'\0'
 float	0
 double	0
 pointer	NULL
 正确地初始化变量是一个良好的编程习惯，否则有时候程序可能会产生意想不到的结果。
 **/
#include <iostream>
using namespace std;
// 全局变量声明
int g;
int main ()
{
    // 局部变量声明
    int a, b;
    int c;
    
    // 实际初始化
    a = 10;
    b = 20;
    c = a + b;
    
    cout << c << endl;
    
    g = a + b;
    
    cout << g << endl;
    int g = 1;
    cout << g << endl;
    return 0;
}
