//
//  6Constants.cpp
//  algoritm
//
//  Created by wizardholy on 2016/12/24.
//  Copyright © 2016年 wizardholy. All rights reserved.
//
#include <iostream>

extern int data;

void write_extern(void)
{
    std::cout << "Count is " << data << std::endl;
}
