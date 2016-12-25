//
//  NewDeleteTest.cpp
//  algoritm
//
//  Created by wizardholy on 2016/12/25.
//  Copyright © 2016年 wizardholy. All rights reserved.
//

/*
 我们应该使用C++语言提供的new与new[]操作符，而不要使用C语言提供的malloc函数。
 c使用malloc 和 free 进行内存分配
 
 虽然malloc函数具有分配存储空间的功能，但是这些函数除了分配存储空间外，不会调用类的构造函数。
 
 而C++语言提供的new和new[]操作符则不会如此，使用它们为对象分配存储空间的同时，它们也会调用相应的构造函数。
 
 操作符delete和delete[]在释放对象存储空间的同时也会调用析构函数，而free函数则不会调用析构函数。
 */
#include<iostream>
using namespace std;

class test
{
public:
    test(int i = 1){num = i;cout<<num<<" Constructor"<<endl;}
    ~test(){cout<<num<<" Destructor"<<endl;}
private:
    int num;
};

int main()
{
    test * t0 = new test(0);
    test * t1 = new test[5];
    test * t2 = (test *)malloc(sizeof(test));
    delete t0;
    delete[] t1;
    free(t2);
    return 0;
}
