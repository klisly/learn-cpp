//
//  1Type.cpp
//  algoritm
//
//  Created by wizardholy on 2016/12/23.
//  Copyright © 2016年 wizardholy. All rights reserved.
//
/**
 C++ 为程序员提供了种类丰富的内置数据类型和用户自定义的数据类型。下表列出了七种基本的 C++ 数据类型：
 类型	关键字
 布尔型	bool
 字符型	char
 整型	int
 浮点型	float
 双浮点型	double
 无类型	void
 宽字符型	wchar_t
 一些基本类型可以使用一个或多个类型修饰符进行修饰：
 signed
 unsigned
 short
 long
 **/

#include <iostream>
using namespace std;
typedef int xmint ;
#define  varName(x) #x;
#define printExp(exp) cout<<#exp<<"为:\t\t"<<（exp）<<endl
#define pringExpToString(exp) cout<<(string(#exp)+"为:\t\t")<<(exp).toString()<<endl
int main()
{
    bool isRun = false;
    cout << "boolean isRun:"<<isRun<<" length:"<<varName(isRun);
    cout <<"\r\n";
    char word = '2';
    cout << "cahr:"<<word<<"\r\n";
    
    /**
     char	1 个字节	-128 到 127 或者 0 到 255
     unsigned char	1 个字节	0 到 255
     signed char	1 个字节	-128 到 127
     int	4 个字节	-2147483648 到 2147483647
     unsigned int	4 个字节	0 到 4294967295
     signed int	4 个字节	-2147483648 到 2147483647
     short int	2 个字节	-32768 到 32767
     unsigned short int	Range	0 到 65,535
     signed short int	Range	-32768 到 32767
     long int	4 个字节	-2,147,483,647 到 2,147,483,647
     signed long int	4 个字节	与 long int 相同
     unsigned long int	4 个字节	0 到 4,294,967,295
     float	4 个字节	+/- 3.4e +/- 38 (~7 个数字)
     double	8 个字节	+/- 1.7e +/- 308 (~15 个数字)
     long double	8 个字节	+/- 1.7e +/- 308 (~15 个数字)
     wchar_t	2 或 4 个字节	1 个宽字符
     **/
    
    cout << "Size of char : " << sizeof(char) << endl;
    cout << "Size of signed char : " << sizeof(signed char) << endl;
    cout << "Size of unsigned char : " << sizeof(unsigned char) << endl;
    
    cout << "Size of int : " << sizeof(int) << endl;
    cout << "Size of short int : " << sizeof(short int) << endl;
    cout << "Size of long int : " << sizeof(long int) << endl;
    cout << "Size of long int : " << sizeof(long int) << endl;
    cout << "Size of float : " << sizeof(float) << endl;
    cout << "Size of double : " << sizeof(double) << endl;
    cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;
    cout << "Size of xmint : " << sizeof(xmint) << endl;
    setlocale(LC_ALL,"chs");//LC_ALL表示设置所有的选项（包括金融货币、小数点，时间日期格式、语言字符串的使用习惯等），chs表示中文简体
    wchar_t wt[] = L"你好C加加的世界";
    wcout << wt << endl;
    cout <<"slkdjslk \r\n";
    enum level_list {level1 = 9, level2, level3} level;
    level = level3;
    cout << "Size of level : " << level << endl;
    enum grade_list {grade0 = 8, grade1, grade2} grade;
    grade = grade1;
    cout << "Size of grade : " << grade << endl;
    
    /**
     type 必须是一个有效的 C++ 数据类型，可以是 char、w_char、int、float、double、bool 或任何用户自定义的对象，variable_list 可以由一个或多个标识符名称组成，多个标识符之间用逗号分隔。下面列出几个有效的声明：
     int    i, j, k;
     char   c, ch;
     float  f, salary;
     double d;
     **/
//    extern int d = 3, f = 5;
    int d  = 3, f = 5;
    int z =22;
    int m; // 默认值是0
    cout << "out value d: " << d << endl;
    cout << "out value f: " << f << endl;
    cout << "out value m: " << m << endl;
    cout << "out value z: " << z << endl;

    return 0;
}
