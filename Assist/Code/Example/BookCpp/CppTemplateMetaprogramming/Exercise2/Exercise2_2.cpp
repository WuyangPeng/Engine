///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/04/15 23:34)

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
