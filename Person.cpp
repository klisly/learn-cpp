//
//  Person.cpp
//  algoritm
//
//  Created by wizardholy on 2016/12/24.
//  Copyright © 2016年 wizardholy. All rights reserved.
//

#include "Person.hpp"
#include <iostream>
using namespace std;
/*
 数据隐藏是面向对象编程的一个重要特点，它防止函数直接访问类类型的内部成员。
 类成员的访问限制是通过在类主体内部对各个区域标记 public、private、protected 来指定的。
 关键字 public、private、protected 称为访问说明符。
 一个类可以有多个 public、protected 或 private 标记区域。
 每个标记区域在下一个标记区域开始之前或者在遇到类主体结束右括号之前都是有效的。
 成员和类的默认访问修饰符是 private。
 
 在类内部，无论成员变量或成员函数被声明为private、public或者protected属性，均是可以互相访问的，无访问权限限制。
 在类外，通过对象无法访问private和protected属性的成员变量和成员函数，而仅可以访问public属性的成员变量和成员函数。
 
 ++语言继承了C语言的struct，并且加以扩充。在C语言中struct是只能定义数据成员，而不能定义成员函数的。
 而在C++中，struct类似于class，在其中既可以定义数据成员，又可以定义成员函数。
 
 在C++中，struct与class基本是通用的，唯一不同的是如果使用class关键字，
 类中定义的成员变量或成员函数默认都是private属性的，而采用struct关键字，
 结构体中定义的成员变量或成员函数默认都是public属性的。
 
 在C++中，没有抛弃C语言中的struct关键字，其意义就在于给C语言程序开发人员有一个归属感，
 并且能让C++编译器兼容以前用C语言开发出来的项目。
 
 ，除非是迫不得已，否则最好不要采用传值的方式传递和返回对象，
 这是因为采用传值的方式传递和返回对象的过程中需要经历对象间的拷贝操作，
 这样会在一定程度上降低程序运行的效率，从而使得待处理数据量增大，
 增加内存的使用。而采用引用或指针的方式则不会有这样的问题，
 而实际上，因为引用表达更加简练直观，因此也较少使用指针来传递对象或作为函数返回值。
 */
class Box{
    /*
     私有成员变量或函数在类的外部是不可访问的，甚至是不可查看的。只有类和友元函数可以访问私有成员。
     默认情况下，类的所有成员都是私有的。例如在下面的类中，paramprivate 是一个私有成员，
     这意味着，如果您没有使用任何访问修饰符，类的成员将被假定为私有成员：
     
     实际操作中，我们一般会在私有区域定义数据，在公有区域定义相关的函数，
     以便在类的外部也可以调用这些函数
     
     类中显式地声明了默认构造函数，无论其属性被设置为public、private还是protected，系统都不会再自动生成默认构造函数了。
     类中显式地声明了其它任意一个不是默认构造函数的构造函数，系统均不会再自动生成默认构造函数。

    */
    double paramprivate;
     // 公有成员在程序中类的外部是可访问的。您可以不使用任何成员函数来设置和获取公有变量的值，如下所示：
    public:
        /*
         构造函数是类中一种特殊的成员函数，其特殊之处有三点：
         构造函数的函数名必须与类名相同；
         构造函数无返回值；
         当我们创建类对象的时候构造函数会被自动调用，而无需我们主动调用。
    
         一个类中可以有多个构造函数，构造函数之间构成函数重载的关系。
         */
        Box();
        // 带默认参数的构造函数。
        Box(double w, double h = 0.8, double l = 1.0);
        double length;
        double width;
        double height;
        friend void printWidth( Box box );

    void setLength(double length);
    double getLength(double length);
        // 在本例中，两个成员函数均是在类声明内部进行声明和定义的，因此这两个函数是inline类型的。
        double getVolume(void){
            return height * width *length;
        };
        double getAdd();
        void setParamPrivate(double param);
        double getParamPrivate();
    /**
     保护成员变量或函数与私有成员十分相似，但有一点不同，
     保护成员在派生类（即子类）中是可访问的。
     在下一个章节中，您将学习到派生类和继承的知识。
     现在您可以看到下面的实例中，我们从父类 Box 派生了一个子类 smallBox。
     **/
    protected:
        double paramprotected;
};

double Box::getAdd(){
    return length + width + height;
}
double Box::getParamPrivate(){
    return paramprivate;
}
void Box::setParamPrivate(double param){
    paramprivate = param;
}
Box::Box(){
    length = 1;
    width = 2;
    height = 3;
}

//Box::Box(double w, double h, double l){
//    length = l;
//    height = h;
//    width = w;
//}

// 另一种构造函数方法
Box::Box(double w, double h, double l):length(l), width(w), height(h){
    
}

/*
 当一个类派生自基类，该基类可以被继承为 public、protected 或 private 几种类型。
 继承类型是通过上面讲解的访问修饰符 access-specifier 来指定的。
 我们几乎不使用 protected 或 private 继承，通常使用 public 继承。
 当使用不同类型的继承时，遵循以下几个规则：
 公有继承（public）：当一个类派生自公有基类时，基类的公有成员也是派生类的公有成员，
 基类的保护成员也是派生类的保护成员，基类的私有成员不能直接被派生类访问，但是可以通过调用基类的公有和保护成员来访问。
 保护继承（protected）： 当一个类派生自保护基类时，基类的公有和保护成员将成为派生类的保护成员。
 私有继承（private）：当一个类派生自私有基类时，基类的公有和保护成员将成为派生类的私有成员。
 */
class ABox: public Box{
    public:
        void setParamProtected(double param);
        double getParamProtected();
};
double ABox::getParamProtected(){
    return paramprotected;
}
void ABox::setParamProtected(double param){
    paramprotected = param;
}

/*
 我们已经将构造函数划分为两类：默认构造函数（不带参数的构造函数）和带参构造函数。
 其中带参数的构造函数中有两种比较常见的构造函数：拷贝构造函数和转型构造函数。
 转型构造函数用于类型间的转换，将其它数据类型转变为类的对象类型。
 转型构造函数只有一个参数，如果该参数是int型，则我们是将int型对象转换为类对象，
 如果该参数类型为char *类型，我们则是将字符串常量转换为类对象。
 
 */
class Age
{
public:
    Age(int a){age = a;}
    /*
     为什么拷贝构造函数的参数一定要是对象的引用呢？我们可以想一下，
     如果不是引用，而是通过传值的方式将实参传递给形参，
     这中间本身就要经历一次对象的拷贝的过程，而对象拷贝则必须调用拷贝构造函数，
     如此一来则会形成一个死循环，无解。所以拷贝构造函数的参数必须是对象的引用。
     */
    Age(Age &a){
        age = a.age;
    }
    
    private :
    int age;
};

/*
 当一个类派生自基类，该基类可以被继承为 public、protected 或 private 几种类型。
 继承类型是通过上面讲解的访问修饰符 access-specifier 来指定的。
 我们几乎不使用 protected 或 private 继承，通常使用 public 继承。当使用不同类型的继承时，遵循以下几个规则：
 公有继承（public）：当一个类派生自公有基类时，基类的公有成员也是派生类的公有成员，基类的保护成员也是派生类的保护成员，
 基类的私有成员不能直接被派生类访问，但是可以通过调用基类的公有和保护成员来访问。
 保护继承（protected）： 当一个类派生自保护基类时，基类的公有和保护成员将成为派生类的保护成员。
 私有继承（private）：当一个类派生自私有基类时，基类的公有和保护成员将成为派生类的私有成员。
 多继承
 多继承即一个子类可以有多个父类，它继承了多个父类的特性。
 C++ 类可以从多个类继承成员，语法如下：
 class <派生类名>:<继承方式1><基类名1>,<继承方式2><基类名2>,…
 {
 <派生类类体>
 };
 */


// 基类 Shape
class Shape
{
public:
    void setWidth(int w)
    {
        width = w;
    }
    void setHeight(int h)
    {
        height = h;
    }
protected:
    int width;
    int height;
};

// 基类 PaintCost
class PaintCost
{
public:
    int getCost(int area)
    {
        return area * 70;
    }
};

// 派生类
class Rectangle: public Shape, public PaintCost
{
public:
    int getArea()
    {
        return (width * height);
    }
};



/**
 C++ 允许在同一作用域中的某个函数和运算符指定多个定义，分别称为函数重载和运算符重载。
 重载声明是指一个与之前已经在该作用域内声明过的函数或方法具有相同名称的声明，但是它们的参数列表和定义（实现）不相同。
 当您调用一个重载函数或重载运算符时，编译器通过把您所使用的参数类型与定义中的参数类型进行比较，
 决定选用最合适的定义。选择最合适的重载函数或重载运算符的过程，称为重载决策。
 **/
class printData
{
public:
    // 函数重载
    void print(int i) {
        cout << "Printing int: " << i << endl;
    }
    
    void print(double  f) {
        cout << "Printing float: " << f << endl;
    }
    
    void print(char* c) {
        cout << "Printing character: " << c << endl;
    }
    
    /*
     您可以重定义或重载大部分 C++ 内置的运算符。这样，您就能使用自定义类型的运算符。
     重载的运算符是带有特殊名称的函数，函数名是由关键字 operator 和其后要重载的运算符符号构成的。
     与其他函数一样，重载运算符有一个返回类型和一个参数列表。
     
     可重载运算符/不可重载运算符
     下面是可重载的运算符列表：
     +	-	*	/	%	^
     &	|	~	!	,	=
     <	>	<=	>=	++	--
     <<	>>	==	!=	&&	||
     +=	-=	/=	%=	^=	&=
     |=	*=	<<=	>>=	[]	()
     ->	->*	new	new []	delete	delete []
     下面是不可重载的运算符列表：
     ::	.*	.	?:
     
     */
    printData operator+(const printData& c){
        printData b;
        return b;
    }

};

/*
 多态按字面的意思就是多种形态。当类之间存在层次结构，并且类之间是通过继承关联时，就会用到多态。
 C++ 多态意味着调用成员函数时，会根据调用函数的对象的类型来执行不同的函数。
 */
class AShape {
protected:
    int width, height;
public:
    AShape( int a=0, int b=0)
    {
        width = a;
        height = b;
    }
    /*
     虚函数 是在基类中使用关键字 virtual 声明的函数。在派生类中重新定义基类中定义的虚函数时，
     会告诉编译器不要静态链接到该函数。
     我们想要的是在程序中任意点可以根据所调用的对象类型来选择调用的函数，这种操作被称为动态链接，或后期绑定。
     */
    virtual int area()
    {
        cout << "Parent class area :" <<endl;
        return 0;
    }
    /*
     您可能想要在基类中定义虚函数，以便在派生类中重新定义该函数更好地适用于对象，
     但是您在基类中又不能对虚函数给出有意义的实现，这个时候就会用到纯虚函数。
     */
    virtual int aarea() = 0;
};
class ARectangle: public AShape{
public:
    ARectangle( int a=0, int b=0):AShape(a, b) { }
    int area ()
    {
        cout << "Rectangle class area :" <<endl;
        return (width * height);
    }
};
class ATriangle: public AShape{
public:
    ATriangle( int a=0, int b=0):AShape(a, b) { }
    int area ()
    {
        cout << "Triangle class area :" <<endl;
        return (width * height / 2);
    }
};

int main(){
    Box box1;
    Box box2;
    ABox abox1;
    box1.height = 2.0;
    box1.width = 2.0;
    box1.length = 3.0;
   
    
    double volume = box1.height * box1.length * box1.width;
    cout << "Box1 的体积：" << volume <<endl;
    cout << "Box1 的体积：" << box2.length * box2.width * box2.height <<endl;
    /*
     类的成员函数是指那些把定义和原型写在类定义内部的函数，就像类定义中的其他变量一样。
     类成员函数是类的一个成员，它可以操作类的任意对象，可以访问对象中的所有成员。
     成员函数可以定义在类定义内部，或者单独使用范围解析运算符 :: 来定义。
     在类定义中定义的成员函数把函数声明为内联的，即便没有使用 inline 标识符。
     
     this指针只能用于非静态成员函数内。
     
     */
    
    cout << "Box1 的体积 by getVolume：" << box1.getVolume() <<endl;
    cout << "Box1 的getAdd by getAdd：" << box1.getAdd() <<endl;

    box1.setParamPrivate(1.00001);
    cout << "Box1 的getParamPrivate：" << box1.getParamPrivate() <<endl;
    abox1.width = 1;
    abox1.height = 1;
    abox1.length = 1;
    abox1.setParamProtected(1.002121);
//    tmp.width = 1;
//    tmp.height =1;
//    tmp.length = 2;
    cout << "abox1 的setParamProtected：" << abox1.getParamProtected() <<endl;
    Box structparam;// default construct
    Box structSpec(3, 4, 5);
    cout << "structparam的体积：" << structparam.getVolume() <<endl;
    cout << "structSpec 的体积：" << structSpec.getVolume() <<endl;

    Rectangle Rect;
    int area;
    
    Rect.setWidth(5);
    Rect.setHeight(7);
    
    area = Rect.getArea();
    
    // 输出对象的面积
    cout << "Total area: " << Rect.getArea() << endl;
    
    // 输出总花费
    cout << "Total paint cost: $" << Rect.getCost(area) << endl;

    
    printData pd;
    
    // Call print to print integer
    pd.print(5);
    // Call print to print float
    pd.print(500.263);
    // Call print to print character
    pd.print("Hello C++");
    
    
    AShape *shape;
    ARectangle rec(10,7);
    ATriangle  tri(10,5);
    
    // 存储矩形的地址
    shape = &rec;
    // 调用矩形的求面积函数 area
    shape->area();
    
    // 存储三角形的地址
    shape = &tri;
    // 调用三角形的求面积函数 area
    shape->area();
    
    
    return 0;
}


/*
 数据抽象是指，只向外界提供关键信息，并隐藏其后台的实现细节，即只表现必要的信息而不呈现细节。
 数据抽象是一种依赖于接口和实现分离的编程（设计）技术。
 
 访问标签强制抽象
 在 C++ 中，我们使用访问标签来定义类的抽象接口。一个类可以包含零个或多个访问标签：
 使用公共标签定义的成员都可以访问该程序的所有部分。一个类型的数据抽象视图是由它的公共成员来定义的。
 使用私有标签定义的成员无法访问到使用类的代码。私有部分对使用类型的代码隐藏了实现细节。
 访问标签出现的频率没有限制。每个访问标签指定了紧随其后的成员定义的访问级别。指定的访问级别会一直有效，直到遇到下一个访问标签或者遇到类主体的关闭右括号为止。
 数据抽象的好处
 数据抽象有两个重要的优势：
 类的内部受到保护，不会因无意的用户级错误导致对象状态受损。
 类实现可能随着时间的推移而发生变化，以便应对不断变化的需求，或者应对那些要求不改变用户级代码的错误报告。
 如果只在类的私有部分定义数据成员，编写该类的作者就可以随意更改数据。如果实现发生改变，则只需要检查类的代码，看看这个改变会导致哪些影响。如果数据是公有的，则任何直接访问旧表示形式的数据成员的函数都可能受到影响。
 
 
 抽象把代码分离为接口和实现。所以在设计组件时，必须保持接口独立于实现，这样，如果改变底层实现，接口也将保持不变。
 在这种情况下，不管任何程序使用接口，接口都不会受到影响，只需要将最新的实现重新编译即可。
 
 所有的 C++ 程序都有以下两个基本要素：
 程序语句（代码）：这是程序中执行动作的部分，它们被称为函数。
 程序数据：数据是程序的信息，会受到程序函数的影响。
 封装是面向对象编程中的把数据和操作数据的函数绑定在一起的一个概念，这样能避免受到外界的干扰和误用，从而确保了安全。数据封装引申出了另一个重要的 OOP 概念，即数据隐藏。
 数据封装是一种把数据和操作数据的函数捆绑在一起的机制，数据抽象是一种仅向用户暴露接口而把具体的实现细节隐藏起来的机制。
 
 通常情况下，我们都会设置类成员状态为私有（private），除非我们真的需要将其暴露，这样才能保证良好的封装性。
 这通常应用于数据成员，但它同样适用于所有成员，包括虚函数。
 
 面向对象的系统可能会使用一个抽象基类为所有的外部应用程序提供一个适当的、通用的、
 标准化的接口。然后，派生类通过继承抽象基类，就把所有类似的操作都继承下来。
 外部应用程序提供的功能（即公有函数）在抽象基类中是以纯虚函数的形式存在的。
 这些纯虚函数在相应的派生类中被实现。
 这个架构也使得新的应用程序可以很容易地被添加到系统中，
 即使是在系统被定义之后依然可以如此。
 
 */




