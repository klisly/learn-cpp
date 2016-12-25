//
//  Static.cpp
//  algoritm
//
//  Created by wizardholy on 2016/12/25.
//  Copyright © 2016年 wizardholy. All rights reserved.
//
/*
 到目前为止，我们设计的类中所有的成员变量和成员函数都是属于对象的，如我们在前面定义的book类，利用book类声明两个对象Alice和Harry，这两个对象均拥有各自的price和title成员变量，同时还拥有类中所有的成员函数。
 
 除了这种情况以外，我们还有另外一种类型的成员，那就是与static结合的成员变量和成员函数。类中的成员变量或成员函数一旦与static关键字相结合，则该成员变量或成员函数就是属于类的，而不是再是属于任何一个对象的，当然任何一个对象都可以共享该成员变量及成员函数。
 静态成员变量
 
 静态成员变量声明非常简单，只需要将static关键字加在成员变量声明的前面即可，如例1所示，我们在例中声明了一个静态成员变量count，并将其设置为private属性。设计这个count变量主要是为了统计当前存活的student类对象的个数，当然这个类并不完善，通过这个例子，我们可以了解静态成员变量的声明语法。
 
 例1：
 class student
 {
 public:
 student(){count ++;}
 ~student(){count --;}
 private:
 static int count;
 //其它成员变量
 };
 静态成员变量在类内部声明之后还需要进行定义操作。
 
 例2：
 class student
 {
 public:
 student(){count ++;}
 ~student(){count --;}
 private:
 static int count;
 //其它成员变量
 };
 int student::count = 0;
 请仔细查看例2的代码，这段代码虽然与例1相比只是增添了一行代码，却是有几处需要我们特别留心。首先静态成员变量的定义必须在任何程序块之外；其次调用该变量的时候可以直接用类名加上域解析符“::”加上变量名的形式，这是静态成员变量特有的引用方式；在类外部进行定义的时候static关键字是不需要的。
 
 在C++语法中规定静态成员变量会被默认初始化为0，类外定义可有可无。而实际上在一些编译器中，如果不加上类外的定义，会出现一些不可知的情况，故在实际设计程序的时候最好还是将类外定义加上。
 
 静态成员变量不会影响类及其对象的大小，也即sizeof结果不会受到影响。在上面的例2中，无论我们是否声明count这个静态成员变量，sizeof(student)或者sizeof(student的对象)其结果都是不会变的。
 
 静态成员变量属于类而不属于任何一个对象，如此一来可以实现数据共享功能，如例3所示。
 
 例3：
 #include<iostream>
 using namespace std;
 class test
 {
 public:
 static int num;
 };
 int test::num = 1;
 int main()
 {
 test one;
 test two;
 test three;
 cout<<test::num<<" "<<one.num<<" "<<two.num<<" "<<three.num<<endl;
 test::num = 5;
 cout<<test::num<<" "<<one.num<<" "<<two.num<<" "<<three.num<<endl;
 one.num = 8;
 cout<<test::num<<" "<<one.num<<" "<<two.num<<" "<<three.num<<endl;
 two.num = 4;
 cout<<test::num<<" "<<one.num<<" "<<two.num<<" "<<three.num<<endl;
 three.num = 2;
 cout<<test::num<<" "<<one.num<<" "<<two.num<<" "<<three.num<<endl;
 return 0;
 }
 程序运行结果：
 1 1 1 1
 5 5 5 5
 8 8 8 8
 4 4 4 4
 2 2 2 2
 
 在本例中，为了方便样式static成员变量的共享特性，我们将静态成员变量设为public属性，如此一来在类外可以方便调用。在类外我们先将静态成员变量进行定义，并初始化为1。在主函数中我们为test类定义了三个对象，分别为one、two和three。之后分别用类名和对象名调用该静态成员变量修改其值，并各自调用的结果打印出来。从程序运行结果可以看出，四种调用静态成员变量的方法，其值都是相等的，如果其中有任何一个修改该静态成员变量，所有其他的调用静态成员变量都会跟着一起改变。这就是静态成员变量的共享特性，静态成员变量不属于任何对象，但是可以通过对象访问静态成员变量。静态成员变量属于类，因此可以通过类来调用静态成员变量。静态成员变量如果被设置为private或protected属性，则在类外同样无法访问，但定义该变量的时候却不受此限制，如例2所示，虽然静态成员变量count为private属性，但是它在类外定义的时候不受private限制。
 静态成员函数
 
 在类内除了能用static声明静态成员变量外，同样可以使用static声明静态成员函数，静态成员函数只能访问static成员变量。
 
 例4：
 #include<iostream>
 using namespace std;
 class test
 {
 public:
 test(int a, int b){num = a; plus = b;}
 static int getnum(){return num;}
 static int add(){return num+plus;}  //compile error
 void setnum(int a){num = a;}
 void setplus(int a){plus = a;}
 private:
 static int num;
 int plus;
 };
 int test::num = 1;
 int main()
 {
 test one;
 one.setnum(5);
 cout<<test::getnum()<<endl;
 return 0;
 }
 在本例程中，类test内有一个静态成员变量num，一个普通成员变量plus，这两个变量都是private属性，成员函数有一个构造函数，两个普通成员函数和两个静态成员函数。在构造函数中，我们引用了静态成员变量num，这是允许的，同样在setnum函数中，同样引用了静态成员变量num，这个也是允许的。然而在add函数中我们不仅引用了静态成员变量num，同时还访问了非静态成员变量plus，而这是不允许的。静态成员函数只能访问静态成员变量，而不能访问非静态成员变量。普通成员函数（包括构造函数和析构函数）既可以访问普通成员变量，同时又可以访问静态成员变量。
 
 访问静态成员变量和静态成员函数均有两种方式，其一是和普通的成员变量成员函数相同，通过对象来访问，其二则是可以通过类名加上域解析操作符访问。当然访问过程中仍然要遵循private、protected和public关键字的访问权限限定。访问静态成员变量和静态成员函数首选的方法是通过类来访问，毕竟静态成员变量和静态成员函数都是属于类的，与类相关联，而不是属于类的对象。普通成员变量或成员函数不可以通过类来访问。由于静态成员变量和静态成员函数都是属于类，而不是属于对象，因此静态成员函数内部也不存在this指针，因为静态成员函数不属于对象。
 
 在静态成员函数内部可以声明静态变量，注意不是静态成员变量。如果在静态成员函数内部声明一个静态变量，则该类的所有对象将共享这个变量。
 
 例5：
 #include<iostream>
 using namespace std;
 class test
 {
 public:
 static void add(int a);
 };
 void test::add(int a)
 {
 static int num = 0;
 int count = 0;
 num += a;
 count += a;
 cout<<num<<" "<<count<<endl;
 }
 int main()
 {
 test one,two,three;
 one.add(5);
 two.add(4);
 three.add(11);
 return 0;
 }
 程序运行结果：
 5 5
 9 4
 20 11
 
 为了直截了当地说明这个问题，我们只在类test中声明了一个静态成员函数add，并且在类外对这个函数进行了定义。注意，在类外定义静态成员函数是不需要static关键字的。在add函数内部我们定义了一个静态变量num，并且初始化为0，为了增强对比效果，我们又定义了一个普通的变量count。在主函数中定义了三个变量，分别调用静态成员函数，结果num值打印结果是累加的，而count则每次都是从0开始的，并不是累加的。通过对比我们很容易看出，static是被这三个对象同时共享的，三个对象一份数据。
 */

//#include<iostream>
//using namespace std;
//class test
//{
//public:
//    static int num;
//};
//int test::num = 1;
//int main()
//{
//    test one;
//    test two;
//    test three;
//    cout<<test::num<<" "<<one.num<<" "<<two.num<<" "<<three.num<<endl;
//    test::num = 5;
//    cout<<test::num<<" "<<one.num<<" "<<two.num<<" "<<three.num<<endl;
//    one.num = 8;
//    cout<<test::num<<" "<<one.num<<" "<<two.num<<" "<<three.num<<endl;
//    two.num = 4;
//    cout<<test::num<<" "<<one.num<<" "<<two.num<<" "<<three.num<<endl;
//    three.num = 2;
//    cout<<test::num<<" "<<one.num<<" "<<two.num<<" "<<three.num<<endl;
//    return 0;
//}

/*
 静态成员函数只能访问静态成员变量，而不能访问非静态成员变量。
 普通成员函数（包括构造函数和析构函数）既可以访问普通成员变量，同时又可以访问静态成员变量。

 */

#include<iostream>
using namespace std;
class test
{
public:
    test(int a, int b){num = a; plus = b;}
    static int getnum(){return num;}
    static int add(){return num+plus;}  //compile error
    void setnum(int a){num = a;}
    void setplus(int a){plus = a;}
private:
    static int num;
    int plus;
};
int test::num = 1;
int main()
{
    test one(1,2);
    one.setnum(5);
    cout<<test::getnum()<<endl;
    return 0;
}

//
//#include<iostream>
//using namespace std;
//class test
//{
//public:
//    static void add(int a);
//};
//void test::add(int a)
//{
//    static int num = 0;
//    int count = 0;
//    num += a;
//    count += a;
//    cout<<num<<" "<<count<<endl;
//}
//int main()
//{
//    test one,two,three;
//    one.add(5);
//    two.add(4);
//    three.add(11);
//    return 0;
//}
