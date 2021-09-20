///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/03/31 1:06)

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingExport.h"

#include "Binary1.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Helper/CppTemplateMetaprogrammingClassInvariantMacro.h"

#include <iostream>
#include <libs/mpl/book/chapter1/binary.hpp>

BookTemplate::CppTemplateMetaprogramming::Binary1::Binary1() noexcept
{
    CPP_TEMPLATE_METAPROGRAMMING_SELF_CLASS_IS_VALID_9;
}

int BookTemplate::CppTemplateMetaprogramming::Binary1::Main() const
{
    CPP_TEMPLATE_METAPROGRAMMING_CLASS_IS_VALID_CONST_9;

    std::cout << binary<101010>::value << std::endl;

    return 0;
}