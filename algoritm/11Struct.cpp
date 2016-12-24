//
//  11Struct.cpp
//  algoritm
//
//  Created by wizardholy on 2016/12/24.
//  Copyright © 2016年 wizardholy. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;
 struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};
/*
 typedef 关键字
 下面是一种更简单的定义结构的方式，您可以为创建的类型取一个"别名"。例如：
 typedef struct
 {
 char  title[50];
 char  author[50];
 char  subject[100];
 int   book_id;
 }Books;
 
 
 指向结构的指针
 您可以定义指向结构的指针，方式与定义指向其他类型变量的指针相似，如下所示：
 struct Books *struct_pointer;
 现在，您可以在上述定义的指针变量中存储结构变量的地址。为了查找结构变量的地址，请把 & 运算符放在结构名称的前面，如下所示：
 struct_pointer = &Book1;
 为了使用指向该结构的指针访问结构的成员，您必须使用 -> 运算符，如下所示：
 struct_pointer->title;
 让我们使用结构指针来重写上面的实例，这将有助于您理解结构指针的概念：
 
 现在，您可以直接使用 Books 来定义 Books 类型的变量，而不需要使用 struct 关键字。下面是实例：
 Books Book1, Book2;
 您可以使用 typedef 关键字来定义非结构类型，如下所示：
 typedef long int *pint32;
 
 pint32 x, y, z;
 x, y 和 z 都是指向长整型 long int 的指针。
 
 
 */
void printBook( struct Books *book );

int main(){
    struct Books book1;
    strcpy(book1.title, "Learn C++");
    strcpy(book1.author, "ChanMina");
    strcpy(book1.subject, "C++ Learning");
    book1.book_id = 40004;
    // 输出 Book1 信息
    cout << "Book 1 title : " << book1.title <<endl;
    cout << "Book 1 author : " << book1.author <<endl;
    cout << "Book 1 subject : " << book1.subject <<endl;
    cout << "Book 1 id : " << book1.book_id <<endl;
    
    struct Books Book1;        // 声明 Book1，类型为 Book
    struct Books Book2;        // 声明 Book2，类型为 Book */
    
    // Book1 详述
    strcpy( Book1.title, "Learn C++ Programming");
    strcpy( Book1.author, "Chand Miyan");
    strcpy( Book1.subject, "C++ Programming");
    Book1.book_id = 6495407;
    
    // Book2 详述
    strcpy( Book2.title, "Telecom Billing");
    strcpy( Book2.author, "Yakit Singha");
    strcpy( Book2.subject, "Telecom");
    Book2.book_id = 6495700;
    
    // 通过传 Book1 的地址来输出 Book1 信息
    printBook( &Book1 );
    
    // 通过传 Book2 的地址来输出 Book2 信息
    printBook( &Book2 );

    return 0;
}

// 该函数以结构指针作为参数
void printBook( struct Books *book )
{
    cout << "Book title : " << book->title <<endl;
    cout << "Book author : " << book->author <<endl;
    cout << "Book subject : " << book->subject <<endl;
    cout << "Book id : " << book->book_id <<endl;
}
