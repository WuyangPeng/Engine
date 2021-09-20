///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/03/31 1:06)

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingExport.h"

#include "Binary.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Helper/CppTemplateMetaprogrammingClassInvariantMacro.h"

unsigned BookTemplate::CppTemplateMetaprogramming::BinaryFunction1(unsigned long N)
{
    return N == 0 ? 0 : N % 10 + 2 * BinaryFunction1(N / 10);
}