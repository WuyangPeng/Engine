///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.2 (2021/04/14 23:17)

#include "CppTemplateMetaprogrammingExercise2_4Testing.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Exercise2/Exercise2_4.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Helper/CppTemplateMetaprogrammingClassInvariantMacro.h"

BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_4Testing::CppTemplateMetaprogrammingExercise2_4Testing(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_TEMPLATE_METAPROGRAMMING_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookTemplate::CppTemplateMetaprogramming, CppTemplateMetaprogrammingExercise2_4Testing)

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_4Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_4Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TypeDescriptor10Test);
    ASSERT_NOT_THROW_EXCEPTION_0(TypeDescriptor11Test);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_4Testing::TypeDescriptor10Test()
{
    std::cout << TypeDescriptor10<int>() << "\n"
              << TypeDescriptor10<char*>() << "\n"
              << TypeDescriptor10<long const*&>() << "\n"
              << TypeDescriptor10<short[10]>() << "\n"
              << TypeDescriptor10<volatile int>() << "\n";

    std::cout << TypeDescriptor10<int[2][3]>() << std::endl;
    std::cout << TypeDescriptor10<const volatile long*&>() << " " << std::endl;
    std::cout << TypeDescriptor11<const volatile long* const&>() << " " << std::endl;
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_4Testing::TypeDescriptor11Test()
{
    std::cout << TypeDescriptor11<int>() << "\n"
              << TypeDescriptor11<char*>() << "\n"
              << TypeDescriptor11<long const*&>() << "\n"
              << TypeDescriptor11<short[10]>() << "\n"
              << TypeDescriptor11<volatile int>() << "\n";

    std::cout << TypeDescriptor11<const volatile long*&>() << " " << std::endl;
    std::cout << TypeDescriptor11<const volatile long* const&>() << " " << std::endl;
}
