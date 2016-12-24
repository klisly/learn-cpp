//
//  8Number.cpp
//  algoritm
//
//  Created by wizardholy on 2016/12/24.
//  Copyright © 2016年 wizardholy. All rights reserved.
//

/**
 当我们需要用到数字时，我们会使用原始的数据类型，如 int、short、long、float 和 double 等等。
 
 **/

#include <iostream>
#include <cmath>
#include <ctime>
//#include <cstring>
#include <cstring>


using namespace std;

#include <iomanip>
/**
 iomanip在c++程序里面经常见到下面的头文件#include <iomanip>，io代表输入输出，
 manip是manipulator（操纵器）的缩写(在c++上只能通过输入缩写才有效。）
 主要是对cin,cout之类的一些操纵运算子，比如setfill,setw,setbase,setprecision等等。
 它是I/O流控制头文件,就像C里面的格式化输出一样.以下是一些常见的控制函数的:
 dec 置基数为10 相当于"%d"
 hex 置基数为16 相当于"%X"
 oct 置基数为8 相当于"%o"
 setfill( 'c' ) 设填充字符为c
 setprecision( n ) 设显示有效数字为n位
 setw( n ) 设域宽为n个字符
 这个控制符的意思是保证输出宽度为n。如：
 cout << setw( 3 ) << 1 << setw( 3 ) << 10 << setw( 3 ) << 100 << endl; 输出结果为
 _ _1_10100 （默认是右对齐）当输出长度大于3时(<<1000)，setw(3)不起作用。
 ▲setw(n)用法： 通俗地讲就是预设宽度
 如 cout<<setw(5)<<255<<endl;
 **/
using std::setw;

double getAverage(int arr[], int size)
{
    int    i, sum = 0;
    double avg;
    
    for (i = 0; i < size; ++i)
    {
        sum += arr[i];
    }
    
    avg = double(sum) / size;
    
    return avg;
}


double getAveragePtr(int *arr, int size)
{
    int    i, sum = 0;
    double avg;
    
    for (i = 0; i < size; ++i)
    {
        sum += *(arr + i);
    }
    
    avg = double(sum) / size;
    
    return avg;
}

double getAveragePtr(int aar[10])
{
    int    i, sum = 0;
    double avg;
    
    for (i = 0; i < 10; ++i)
    {
        sum += aar[i];
    }
    
    avg = double(sum) / 10;
    
    return avg;
}
int * getRandom( );

int main ()
{
    // 数字定义
    short  s;
    int    i;
    long   l;
    float  f;
    double d;
    
    // 数字赋值
    s = 10;
    i = 1000;
    l = 1000000;
    f = 230.479999;
    d = 30949.374;
    
    // 数字输出
    cout << "short  s :" << s << endl;
    cout << "int    i :" << i << endl;
    cout << "long   l :" << l << endl;
    cout << "float  f :" << f << endl; // 默认保留两位小数 四舍五入
    cout << "double d :" << d << endl; // 默认保留一位小数 四舍五入
    
    /**
     C++ 内置了丰富的数学函数，可对各种数字进行运算。下表列出了 C++ 中一些有用的内置的数学函数。
     为了利用这些函数，您需要引用数学头文件 <cmath>。
     序号	函数 & 描述
     1	double cos(double);
     该函数返回弧度角（double 型）的余弦。
     2	double sin(double);
     该函数返回弧度角（double 型）的正弦。
     3	double tan(double);
     该函数返回弧度角（double 型）的正切。
     4	double log(double);
     该函数返回参数的自然对数。
     5	double pow(double, double);
     假设第一个参数为 x，第二个参数为 y，则该函数返回 x 的 y 次方。
     6	double hypot(double, double);
     该函数返回两个参数的平方总和的平方根，也就是说，参数为一个直角三角形的两个直角边，函数会返回斜边的长度。
     7	double sqrt(double);
     该函数返回参数的平方根。
     8	int abs(int);
     该函数返回整数的绝对值。
     9	double fabs(double);
     该函数返回任意一个十进制数的绝对值。
     10	double floor(double);
     该函数返回一个小于或等于传入参数的最大整数。
     **/
    
    // 数学运算
    cout << "sin(d) :" << sin(d) << endl;
    cout << "abs(i)  :" << abs(i) << endl;
    cout << "floor(d) :" << floor(d) << endl;
    cout << "sqrt(f) :" << sqrt(f) << endl;
    cout << "pow( d, 2) :" << pow(d, 2) << endl;
    
    /**
     在许多情况下，需要生成随机数。关于随机数生成器，有两个相关的函数。
     一个是 rand()，该函数只返回一个伪随机数。生成随机数之前必须先调用 srand() 函数。
     **/
    int j;
    
    // 设置种子
    srand( (unsigned)time( NULL ) );
    
    /* 生成 10 个随机数 */
    for( i = 0; i < 1000; i++ )
    {
        // 生成实际的随机数
        j= rand() % 10 + 1;
        cout <<"随机数： " << j << endl;
    }
    
    /**
     C++ 支持数组数据结构，它可以存储一个固定大小的相同类型元素的顺序集合。
     数组是用来存储一系列数据，但它往往被认为是一系列相同类型的变量。
     数组的声明并不是声明一个个单独的变量，比如 number0、number1、...、number99，
     而是声明一个数组变量，比如 numbers，然后使用 numbers[0]、numbers[1]、...、numbers[99] 
     来代表一个个单独的变量。数组中的特定元素可以通过索引访问。
     所有的数组都是由连续的内存位置组成。最低的地址对应第一个元素，
     最高的地址对应最后一个元素。
     
     在 C++ 中要声明一个数组，需要指定元素的类型和元素的数量，如下所示：
     type arrayName [ arraySize ];
     **/
    double balance[10];
   // 在 C++ 中，您可以逐个初始化数组，也可以使用一个初始化语句，如下所示：
//    double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
    //大括号 { } 之间的值的数目不能大于我们在数组声明时在方括号 [ ] 中指定的元素数目。
    //如果您省略掉了数组的大小，数组的大小则为初始化时元素的个数。因此，如果：
//    double balance[] = {1000.0, 2.0, 3.4, 17.0, 50.0};
    //您将创建一个数组，它与前一个实例中所创建的数组是完全相同的。下面是一个为数组中某个元素赋值的实例：
    balance[4] = 50.0;
    
    int n[ 10 ]; // n 是一个包含 10 个整数的数组
    
    // 初始化数组元素
    for ( int i = 0; i < 10; i++ )
    {
        n[ i ] = i + 100; // 设置元素 i 为 i + 100
    }
    cout << "Element" << setw( 13 ) << "Value" << endl;
    
    // 输出数组中每个元素的值
    for ( int j = 0; j < 10; j++ )
    {
        cout << setw( 7 )<< j << setw( 13 ) << n[ j ] << endl;
    }
    
    /**
     
     C++ 支持多维数组。多维数组声明的一般形式如下：
     type name[size1][size2]...[sizeN];
     例如，下面的声明创建了一个三维 5 . 10 . 4 整型数组：
     int threedim[5][10][4];
     type arrayName [ x ][ y ];
     
     **/
    
    // 一个带有 5 行 2 列的数组
    int a[5][2] = { {0,0}, {1,2}, {2,4}, {3,6},{4,8}};
    
    // 输出数组中每个元素的值
    for ( int i = 0; i < 5; i++ )
        for ( int j = 0; j < 2; j++ )
        {
            cout << "a[" << i << "][" << j << "]: ";
            cout << a[i][j]<< endl;
        }
 
    /**
     double balance[50];
     balance 是一个指向 &balance[0] 的指针，即数组 balance 的第一个元素的地址。因此，下面的程序片段把 p 赋值为 balance 的第一个元素的地址：
     double *p;
     double balance[10];
     
     p = balance;
     使用数组名作为常量指针是合法的，反之亦然。因此，*(balance + 4) 是一种访问 balance[4] 数据的合法方式。
     一旦您把第一个元素的地址存储在 p 中，您就可以使用 *p、*(p+1)、*(p+2) 等来访问数组元素。下面的实例演示了上面讨论到的这些概念：

     **/
    
    // 带有 5 个元素的整型数组
    double bs[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
    double *p;
    
    p = bs;
    
    // 输出数组中每个元素的值
    cout << "使用指针的数组值 " << endl;
    for ( int i = 0; i < 5; i++ )
    {
        cout << "*(p + " << i << ") : ";
        cout << *(p + i) << endl;
    }
    
    cout << "使用 balance 作为地址的数组值 " << endl;
    for ( int i = 0; i < 5; i++ )
    {
        cout << "*(balance + " << i << ") : ";
        cout << *(bs + i) << endl;
    }
    
    /**
     传递数组给函数
     C++ 不允许向函数传递一个完整的数组作为参数，但是，您可以通过指定不带索引的数组名来传递一个指向数组的指针。
     如果您想要在函数中传递一个一维数组作为参数，您必须以下面三种方式来声明函数形式参数，这三种声明方式的结果是一样的，因为每种方式都会告诉编译器将要接收一个整型指针。同样地，您也可以传递一个多维数组作为形式参数。
     方式 1
     形式参数是一个指针：
     void myFunction(int *param)
     {
     .
     .
     .
     }
     方式 2
     形式参数是一个已定义大小的数组：
     void myFunction(int param[10])
     {
     .
     .
     .
     }
     方式 3
     形式参数是一个未定义大小的数组：
     void myFunction(int param[])
     {
     .
     .
     .
     }

     **/
    
    // 带有 5 个元素的整型数组
    int bbs[5] = {1000, 2, 3, 17, 50};
    double avg;
    
    // 传递一个指向数组的指针作为参数
//    avg = getAverage( bbs, 5 ) ;
    avg = getAveragePtr( bbs, 5);
    // 输出返回值
    cout << "平均值是：" << avg << endl;
    
    /**
     C++ 不允许返回一个完整的数组作为函数的参数。但是，您可以通过指定不带索引的数组名来返回一个指向数组的指针。
     如果您想要从函数返回一个一维数组，您必须声明一个返回指针的函数，如下：
     int * myFunction()
     {
     .
     .
     .
     }
     另外，C++ 不支持在函数外返回局部变量的地址，除非定义局部变量为 static 变量。
     **/
    
    // 一个指向整数的指针
    int *pint;
    
    pint = getRandom();
    for ( int i = 0; i < 10; i++ )
    {
        cout << "*(p + " << i << ") : ";
        cout << *(pint + i) << endl;
    }
    
    /**
     C 风格的字符串起源于 C 语言，并在 C++ 中继续得到支持。字符串实际上是使用 null 字符 '\0' 终止的一维字符数组。因此，一个以 null 结尾的字符串，包含了组成字符串的字符。
     下面的声明和初始化创建了一个 "Hello" 字符串。由于在数组的末尾存储了空字符，所以字符数组的大小比单词 "Hello" 的字符数多一个。
     char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
     依据数组初始化规则，您可以把上面的语句写成以下语句：
     char greeting[] = "Hello";
     **/
    
    char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

    cout << "Greeting message: ";
    cout << greeting << endl;
    
//    /**
//     strings:
//     序号	函数 & 目的
//     1	strcpy(s1, s2);
//     复制字符串 s2 到字符串 s1。
//     2	strcat(s1, s2);
//     连接字符串 s2 到字符串 s1 的末尾。
//     3	strlen(s1);
//     返回字符串 s1 的长度。
//     4	strcmp(s1, s2);
//     如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回小于 0；如果 s1>s2 则返回大于 0。
//     5	strchr(s1, ch);
//     返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置。
//     6	strstr(s1, s2);
//     返回一个指针，指向字符串 s1 中字符串 s2 的第一次出现的位置。
//     **/
//    char str1[10] = "Hello";
//    char str2[10] = "World";
//    char str3[10];
//    int  len ;
//    
//    // 复制 str1 到 str3
//    strcpy( str3, str1);
//    cout << "strcpy( str3, str1) : " << str3 << endl;
//    
//    // 连接 str1 和 str2
//    strcat( str1, str2);
//    cout << "strcat( str1, str2): " << str1 << endl;
//    
//    // 连接后，str1 的总长度
//    len = strlen(str1);
//    cout << "strlen(str1) : " << len << endl;
//    
//    // 连接后，str1 str2 大小
//    len = strcmp(str1, str2);
//    cout << "strcmp(str1, str12) : " << len << endl;
//    
//    // str中 l 首次出现的位置
//    char * res = strchr(str1, '1');
//    cout << "strchr(str1) : " << res << endl;
//    
//    // 连接后，str1 str2 大小
//    len = strcmp(str1, str2);
//    cout << "strcmp(str1, str12) : " << len << endl;
    
    string str1 = "Hello";
    string str2 = "World";
    string str3;
    int  len ;
    
    // 复制 str1 到 str3
    str3 = str1;
    cout << "str3 : " << str3 << endl;
    
    // 连接 str1 和 str2
    str3 = str1 + str2;
    cout << "str1 + str2 : " << str3 << endl;
    
    // 连接后，str3 的总长度
    len = str3.size();
    cout << "str3.size() :  " << len << endl;
    
    return 0;
}

// 要生成和返回随机数的函数
int * getRandom( )
{
    static int  r[10];
    
    // 设置种子
    srand( (unsigned)time( NULL ) );
    for (int i = 0; i < 10; ++i)
    {
        r[i] = rand() % 100;
        cout << r[i] << endl;
    }
    
    return r;
}
