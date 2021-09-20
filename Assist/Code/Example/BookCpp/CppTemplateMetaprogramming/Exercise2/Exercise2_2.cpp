///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/04/15 23:34)

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingExport.h"

#include "Exercise2_2.h"

void BookTemplate::CppTemplateMetaprogramming::Test() noexcept(g_CppTemplateMetaprogrammingAssert < 0)
{
    B b;
    ATest* aPtr = &b;
    MAYBE_UNUSED const B* bPtr = PolymorphicDowncast<B*>(aPtr);

    ATest& aRef = b;
    MAYBE_UNUSED const B& bRef = PolymorphicDowncast<B&>(aRef);
}

void BookTemplate::CppTemplateMetaprogramming::BTest::Fn() noexcept
{
}
