///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/04/15 23:34)

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingExport.h"

#include "Exercise2_3.h"

#include <iostream>

void BookTemplate::CppTemplateMetaprogramming::F()
{
    // prints "int"
    std::cout << TypeDescriptor<int>();

    // prints "char*"
    std::cout << TypeDescriptor<char*>();

    // prints "long const*&"
    std::cout << TypeDescriptor<long const*&>();

    // prints "array of pointer to function returning pointer to char"
    std::cout << TypeDescriptor<char* (*[])()>();
}
