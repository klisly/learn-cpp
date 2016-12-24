//
//  9Pointer.cpp
//  algoritm
//
//  Created by wizardholy on 2016/12/24.
//  Copyright © 2016年 wizardholy. All rights reserved.
//
/**
 通过指针，可以简化一些 C++ 编程任务的执行，还有一些任务，如动态内存分配，没有指针是无法执行的。
 所以，想要成为一名优秀的 C++ 程序员，学习指针是很有必要的。
 正如您所知道的，每一个变量都有一个内存位置，每一个内存位置都定义了可使用连字号（&）运算符访问的地址，
 它表示了在内存中的一个地址。请看下面的实例，它将输出定义的变量地址：
 
 **/
#include <iostream>

using namespace std;
const int MAX = 3;
int main ()
{
    int  var1;
    char var2[10];
    
    cout << "var1 变量的地址： ";
    cout << &var1 << endl;
    
    cout << "var2 变量的地址： ";
    cout << &var2 << endl;
    
    /*指针是一个变量，其值为另一个变量的地址，即，内存位置的直接地址。就像其他变量或常量一样，您必须在使用指针存储其他变量地址之前，对其进行声明。指针变量声明的一般形式为：
    type *var-name;
    在这里，type 是指针的基类型，它必须是一个有效的 C++ 数据类型，var-name 是指针变量的名称。用来声明指针的星号 * 与乘法中使用的星号是相同的。但是，在这个语句中，星号是用来指定一个变量是指针。以下是有效的指针声明：
     */
    int    *ip;    /* 一个整型的指针 */
    double *dp;    /* 一个 double 型的指针 */
    float  *fp;    /* 一个浮点型的指针 */
    char   *ch;     /* 一个字符型的指针 */
    
    int  var = 20;   // 实际变量的声明
//    int  *ip;        // 指针变量的声明
    
    ip = &var;       // 在指针变量中存储 var 的地址
    
    cout << "Value of var variable: ";
    cout << var << endl;
    
    // 输出在指针变量中存储的地址
    cout << "Address stored in ip variable: ";
    cout << ip << endl;
    
    // 访问指针中地址的值
    cout << "Value of *ip variable: ";
    cout << *ip << endl;
    
    /**
     为指针变量赋一个 NULL 值是一个良好的编程习惯。赋为 NULL 值的指针被称为空指针。
     在大多数的操作系统上，程序不允许访问地址为 0 的内存，因为该内存是操作系统保留的。
     然而，内存地址 0 有特别重要的意义，它表明该指针不指向一个可访问的内存位置。
     **/
    int  *ptr = NULL;
    int  *ptr1;
    cout << "ptr 的值是 " << ptr << endl ;
    cout << "ptr1 的值是 " << ptr1 << endl ;
    // 指针的算术运算
    /*
     可以对指针进行四种算术运算：++、--、+、-。
     假设 ptr 是一个指向地址 1000 的整型指针，是一个 32 位的整数，让我们对该指针执行下列的算术运算：
     ptr++
     在执行完上述的运算之后，ptr 将指向位置 1004，因为 ptr 每增加一次，它都将指向下一个整数位置，即当前位置往后移 4 个字节。
     这个运算会在不影响内存位置中实际值的情况下，移动指针到下一个内存位置。如果 ptr 指向一个地址为 1000 的字符，
     上面的运算会导致指针指向位置 1001，因为下一个字符位置是在 1001。
     */
    int  vvar[MAX] = {10, 100, 200};
    int  *vptr;
    
    // 指针中的数组地址
    vptr = vvar;
    for (int i = 0; i < MAX; i++)
    {
        cout << "Address of var[" << i << "] = ";
        cout << vptr << endl;
        
        cout << "Value of var[" << i << "] = ";
        cout << *vptr << endl;
        
        // 移动到下一个位置
        vptr++;
    }
    
    //同样地，对指针进行递减运算，即把值减去其数据类型的字节数，如下所示：

    // 指针中最后一个元素的地址
    ptr = &vvar[MAX-1];
    for (int i = MAX; i > 0; i--)
    {
        cout << "Address of var[" << i << "] = ";
        cout << ptr << endl;
        
        cout << "Value of var[" << i << "] = ";
        cout << *ptr << endl;
        
        // 移动到下一个位置
        ptr--;
    }
    
    // 指针的比较
    /*
     指针可以用关系运算符进行比较，如 ==、< 和 >。如果 p1 和 p2 指向两个相关的变量，
     比如同一个数组中的不同元素，则可对 p1 和 p2 进行大小比较。
     */
    
    //指向指针的指针（多级间接寻址）
    int  pvar;
    int  *pptr;
    int  **ppptr;
    
    pvar = 3000;
    
    // 获取 var 的地址
    pptr = &pvar;
    
    // 使用运算符 & 获取 ptr 的地址
    ppptr = &pptr;
    
    // 使用 pptr 获取值
    cout << "Value of var :" << pvar << endl;
    cout << "Value available at *ptr :" << *pptr << endl;
    cout << "Value available at **pptr :" << **ppptr << endl;
    
    // 传递指针给函数 从函数返回指针 参见8Number.cpp
    return 0;
}

