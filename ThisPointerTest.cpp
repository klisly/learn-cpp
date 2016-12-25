//
//  ThisPointerTest.cpp
//  algoritm
//
//  Created by wizardholy on 2016/12/25.
//  Copyright © 2016年 wizardholy. All rights reserved.
//
/*
 
 在每一个成员函数中都包含一个常量指针，我们称其为this指针，该指针指向调用本函数的对象，其值为该对象的首地址。通过该指针，我们可以在成员函数的函数体内访问对象。其中this是C++的一个关键字。
 
 例1：
 class book
 {
 public:
 book(){this->price = 0.0; this->title = NULL;}
 private:
 double price;
 char * title;
 };
 如例1程序所示，该例向我们展示了this指针的使用方法。当然在我们在实际的程序设计中并不需要如此，这样写未免太麻烦了，例1只是做介绍this指针基本语法所用。在实际设计程序时只需要按照例2就行。
 
 例2：
 class book
 {
 public:
 book(){price = 0.0; title = NULL;}
 private:
 double price;
 char * title;
 };
 通常我们在设计成员函数时会将形参与成员变量设计成同一个名字，如例3所示，此时函数定义的时候price = price;这样的程序看起来总是有些别扭的。这个使用如果使用this指针则就能很明朗的进行区分两个price了。
 
 例3：
 void setprice(double price)
 {
 price = price;
 }
 
 例4：
 void setprice(double price)
 {
 this->price = price;
 }
 如例4所示，利用this->price表明前面一个price为类中的成员变量，而后面一个price为形参中的price。this指针在此时避免命名冲突产生理解上的歧义。
 
 例5：
 #include<iostream>
 using namespace std;
 
 class book
 {
 public:
 book(){price = 0.0; title = NULL;}
 void copy(book &b);
 private:
 double price;
 char * title;
 };
 void book::copy(book &b)
 {
 if(this == &b)
 {
 cout<<"same object!"<<endl;
 return;
 }
 else
 {
 price = b.price;
 }
 }
 int main()
 {
 book Alice;
 book Harry;
 Harry.copy(Alice);
 Harry.copy(Harry);
 return 0;
 }
 在本例中，我们为book类新增了一个copy函数，即将book类对象拷贝给调用copy函数的对象，
 在函数体中，我们用this指针先判断被拷贝的对象的引用是否是调用该函数的对象自身，
 如果是的话则推出函数。
 在主函数中Harry.copy(Harry);就是拷贝自身，这样的事情当然是我们不希望看到的，
 因此直接退出函数。这在程序设计过程中也是一种常用的检测手段。
 
 this指针是常量指针，它的值是不能被修改的，一切企图修改该指针的操作如赋值、递增、递减等都是不允许的。
 此外this指针只非static成员函数中才是有效的，这一点在我们介绍完static成员函数后大家就会明白为何会如此了，
 在此处暂时只要知道这一点就可以了。
 
 例6：
 复制纯文本新窗口
 
 class book
 {
 public:
 book(){price = 0.0; title = NULL;}
 static void setprice(double price)
 {
 this->price = price;//compile error
 }
 private:
 double price;
 char * title;
 };
 在例6中，
 
 <b>this指针出现在static成员函数中，编译出错。this指针只能用于非静态成员函数内。</b>
 
 */


#include<iostream>
using namespace std;

class book
{
public:
    book(){price = 0.0; title = NULL;}
    void copy(book &b);
private:
    double price;
    char * title;
};
void book::copy(book &b)
{
    if(this == &b)
    {
        cout<<"same object!"<<endl;
        return;
    }
    else
    {
        price = b.price;
    }
}
int main()
{
    book Alice;
    book Harry;
    Harry.copy(Alice);
    Harry.copy(Harry);
    return 0;
}
