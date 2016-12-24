//
//  12CinOut.cpp
//  algoritm
//
//  Created by wizardholy on 2016/12/24.
//  Copyright © 2016年 wizardholy. All rights reserved.
//
/**
 C++ 的 I/O 发生在流中，流是字节序列。如果字节流是从设备（如键盘、磁盘驱动器、网络连接等）流向内存，
 这叫做输入操作。如果字节流是从内存流向设备（如显示屏、打印机、磁盘驱动器、网络连接等），这叫做输出操作。
 I/O 库头文件
 下列的头文件在 C++ 编程中很重要。
 头文件	函数和描述
 <iostream>	该文件定义了 cin、cout、cerr 和 clog 对象，分别对应于标准输入流、标准输出流、非缓冲标准错误流和缓冲标准错误流。
 <iomanip>	该文件通过所谓的参数化的流操纵器（比如 setw 和 setprecision），来声明对执行标准化 I/O 有用的服务。
 <fstream>	该文件为用户控制的文件处理声明服务。我们将在文件和流的相关章节讨论它的细节。
 **/

#include <iostream>

using namespace std;

int main( )
{
    char str[] = "Hello C++";
    /**
     C++ 编译器根据要输出变量的数据类型，选择合适的流插入运算符来显示值。
     << 运算符被重载来输出内置类型（整型、浮点型、double 型、字符串和指针）的数据项。
     流插入运算符 << 在一个语句中可以多次使用，如上面实例中所示，endl 用于在行末添加一个换行符。
     **/
    cout << "Value of str is : " << str << endl;
    
    /**
     预定义的对象 cin 是 istream 类的一个实例。cin 对象附属到标准输入设备，
     通常是键盘。cin 是与流提取运算符 >> 结合使用的，如下所示：
     **/
    char name[50];
    int age;
//    cout << "请输入您的名称： ";
//    cin >> name;
//    cout << "您的名称是： " << name << endl;
//    
//    cout << "请输入您的名称和年龄, 换行符结束： ";
//    cin >> name >> age;
//    cout << "您的名称是： " << name <<" 年龄:"<<age<< endl;
//    char c;
//    while ((c = cin.get()) != EOF) {
//        cout << "输入的字符： " << c << endl;
//    }
    
    /**
     预定义的对象 cerr 是 ostream 类的一个实例。cerr 对象附属到标准错误设备，
     通常也是显示屏，但是 cerr 对象是非缓冲的，且每个流插入到 cerr 都会立即输出。
     cerr 也是与流插入运算符 << 结合使用的，如下所示：

     **/
    char errstr[] = "Unable to read....";
    
    cerr << "Error message : " << errstr << endl;
    
    /**
     预定义的对象 clog 是 ostream 类的一个实例。clog 对象附属到标准错误设备，通常也是显示屏，但是 clog 对象是缓冲的。这意味着每个流插入到 clog 都会先存储在缓冲在，直到缓冲填满或者缓冲区刷新时才会输出。
     clog 也是与流插入运算符 << 结合使用的，如下所示：
     **/
    char logstr[] = "Unable to read....";
    
    cerr << "Error message : " << logstr << endl;
}
