//
//  Constant.cpp
//  algoritm
//
//  Created by wizardholy on 2016/12/25.
//  Copyright © 2016年 wizardholy. All rights reserved.
//
/*
 在类中，有时候为了避免误操作而修改了一些人们不希望被修改的数据，此时就必须借助const关键字加以限定了。借助const关键字可以定义const类型的成员变量、成员函数、常对象以及对象的常引用。
 const成员变量
 
 const成员变量其用法和普通的const变量用法相似，在定义时只需在前面加上const关键字即可。const成员变量的初始化只有唯一的一条途径：参数初始化表。这个在前面已经提到过，不记得的话可以再去翻看参数初始化表那一小节。
 const成员函数
 
 const成员函数可以使用类中的所有成员变量，但是不能修改变量的值，这种措施主要还是为了保护数据而设置的。
 
 我们来看一下下面的例子，例1依然是前面见过多次的book类，不过已经将与const成员函数不相关的代码都去掉了。在类中定义了两个构造函数及四个普通的成员函数，其功能分别是设置成员变量和获得成员变量。但这个book类与前面不相同的是在getprice函数和gettitle函数声明后面多了const关键字，这就是const成员函数，也可以成为常成员函数。常成员函数就是在声明和定义的时候在函数头部的结尾加上const关键字。注意在定义函数的时候const关键字依然是不能少的，具体可以参见例1中getprice和gettitle函数的定义。
 
 为什么要将这两个函数定义成常成员函数呢？这两个函数的功能我们知道就是为了返回price和title的，功能单一，并且不希望修改这两个变量的，如此，定义成常成员函数是非常保险的一种做法，可以避免在这两个函数内部修改成员变量。如果需要修改这两个变量则只需通过setprice和settitle函数完成，因此设置为const是非常合适的。
 
 例1：
 class book
 {
 public:
 book(){}
 book(char* a, double p = 5.0);
 void setprice(double a);
 void settitle(char* a);
 double getprice()const;
 char * gettitle()const;
 private:
 double price;
 char * title;
 };
 double book::getprice()const
 {
 return price;
 }
 char * book::gettitle()const
 {
 return title;
 }
 
 
 常成员函数可以访问类中的任何成员变量，但是不能修改任何成员变量。
 而普通的成员函数不能访问常对象的成员变量，其它的成员变量都可以访问，普通的成员函数可以修改的成员变量也只有非const成员变量了，
 一旦加上了const关键字加以修饰，初始化完成后就不能被修改了。还有一点需要注意的是const成员函数是不能调用类中非const成员函数的。
 const对象
 
 const对象定义的基本语法如下：
 const 类名 对象名(实参名);
 类名 const 对象名(实参名);
 这两种定义方式都是可以的，我们一旦将对象定义为常对象之后，该对象就只能调用类中的常成员函数了。
 
 例2：
 #include<iostream>
 using namespace std;
 class book
 {
 public:
 book(){}
 book(book &b);
 book(char* a, double p = 5.0);
 void setprice(double a);
 double getprice()const;
 void settitle(char* a);
 char * gettitle()const;
 void display()const;
 private:
 double price;
 char * title;
 };
 book::book(book &b)
 {
 price = b.price;
 title = b.title;
 }
 book::book(char* a, double p)
 {
 title = a;
 price = p;
 }
 void book::display()const
 {
 cout<<"The price of "<<title<<" is $"<<price<<endl;
 }
 void book::setprice(double a)
 {
 price = a;
 }
 double book::getprice()const
 {
 return price;
 }
 void book::settitle(char* a)
 {
 title = a;
 }
 char * book::gettitle()const
 {
 return title;
 }
 int main()
 {
 const book Alice("Alice in Wonderland",29.9);
 Alice.display();
 Alice.setprice(51.0);//compile error
 return 0;
 }
 在本例中，我们将类中的getprice、gettitle和display三个函数都声明为了常成员函数，之后在主函数中我们定义了一个常对象Alice，Alice作为一个常对象，只能调用常成员函数，因此在调用display函数时没有问题，但是在调用setprice函数时编译报错，因为setprice不是常成员函数。
 
 有些时候我们在程序设计过程中要求修改常对象中的某个成员变量，这个时候如果是普通的成员变量是不能被修改的。为了满足这一需求，C++提供了mutable关键字。
 mutable int var;
 通过这样的声明将变量var声明为可变的成员变量，此时如果要修改常对象的该变量时，只需要通过常对象调用const成员函数修改该变量即可。
 对象的const引用
 
 在将对象作为函数参数的时候，通常我们会采用引用的方式作为函数参数。有时候为了在函数中避免对对象本身做出什么修改，在函数形参前加上const关键字。
 
 例3：
 #include<iostream>
 using namespace std;
 class book
 {
 public:
 book(){}
 book(book &b);
 book(char* a, double p = 5.0);
 void setprice(double a);
 double getprice()const;
 void settitle(char* a);
 char * gettitle()const;
 private:
 double price;
 char * title;
 };
 book::book(book &b)
 {
 price = b.price;
 title = b.title;
 }
 book::book(char* a, double p)
 {
 title = a;
 price = p;
 }
 void book::setprice(double a)
 {
 price = a;
 }
 double book::getprice()const
 {
 return price;
 }
 void book::settitle(char* a)
 {
 title = a;
 }
 char * book::gettitle()const
 {
 return title;
 }
 void display(const book &b)
 {
 b.setprice(59.9);  //compile error
 cout<<"The price of "<<b.gettitle()<<" is $"<<b.getprice()<<endl;  //ok
 }
 int main()
 {
 book Alice("Alice in Wonderland",29.9);
 display(Alice);
 book Harry("Harry potter", 49.9);
 display(Harry);
 return 0;
 }
 在本例中，我们将display函数声明为顶层函数，其函数形参为book类对象的常引用，在函数内部我们首先调用public属性的setprice函数，企图修改price成员变量，编译无法通过。而在其后调用gettitle和getprice函数则没有问题，因为这些函数没有修改成员变量。
 */

/*
 const成员变量
 
 const成员变量其用法和普通的const变量用法相似，在定义时只需在前面加上const关键字即可。const成员变量的初始化只有唯一的一条途径：参数初始化表。这个在前面已经提到过，不记得的话可以再去翻看参数初始化表那一小节。
 
 const成员函数
 
 const成员函数可以使用类中的所有成员变量，但是不能修改变量的值，这种措施主要还是为了保护数据而设置的。
 
 const对象
 
 const对象定义的基本语法如下：
 const 类名 对象名(实参名);
 类名 const 对象名(实参名);
 这两种定义方式都是可以的，我们一旦将对象定义为常对象之后，该对象就只能调用类中的常成员函数了。

 */

#include <iostream>
#include <string>
using namespace std;
class book
{
public:
    book(){}
    book(book &b);
    book(string a, double p = 5.0);
    void setprice(double a);
    double getprice()const;
    void settitle(string a);
    string gettitle()const;
    void display()const;
private:
    double price;
    string title;
};
book::book(book &b)
{
    price = b.price;
    title = b.title;
}
book::book(string a, double p)
{
    title = a;
    price = p;
}
void book::display()const
{
    cout<<"The price of "<<title<<" is $"<<price<<endl;
}
void book::setprice(double a)
{
    price = a;
}
double book::getprice()const
{
    return price;
}
void book::settitle(string a)
{
    title = a;
}
string book::gettitle()const
{
    return title;
}
int main()
{
    const book Alice("Alice in Wonderland",29.9);
    Alice.display();
    Alice.setprice(51.0);//compile error
    return 0;
}
