///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.2 (2021/04/14 23:17)

#include "CppTemplateMetaprogrammingExercise2_3Testing.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Exercise2/Exercise2_3.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Helper/CppTemplateMetaprogrammingClassInvariantMacro.h"

BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_3Testing::CppTemplateMetaprogrammingExercise2_3Testing(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_TEMPLATE_METAPROGRAMMING_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookTemplate::CppTemplateMetaprogramming, CppTemplateMetaprogrammingExercise2_3Testing)

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_3Testing::MainTest() noexcept
{
    ASSERT_NOT_THROW_EXCEPTION_0(FTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TypeDescriptor1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(TypeDescriptor2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(TypeDescriptor3Test);
    ASSERT_NOT_THROW_EXCEPTION_0(TypeDescriptor4Test);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_3Testing::FTest()
{
    F();
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_3Testing::TypeDescriptor1Test()
{
    std::cout << TypeDescriptor1<int>() << "\n"
              << TypeDescriptor1<char*>() << "\n"
              << TypeDescriptor1<long const*&>() << "\n"
              << TypeDescriptor1<short[10]>() << "\n"
              << TypeDescriptor1<volatile int>() << "\n";
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_3Testing::TypeDescriptor2Test()
{
    std::cout << TypeDescriptor2<int>() << "\n"
              << TypeDescriptor2<char*>() << "\n"
              << TypeDescriptor2<long const*&>() << "\n";
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_3Testing::TypeDescriptor3Test()
{
    std::cout << TypeDescriptor3<int>() << "\n"
              << TypeDescriptor3<char*>() << "\n"
              << TypeDescriptor3<long const*&>() << "\n"
              << TypeDescriptor3<short[10]>() << "\n"
              << TypeDescriptor3<volatile int>() << "\n";

    std::cout << TypeDescriptor3<int[2][3]>() << std::endl;
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_3Testing::TypeDescriptor4Test()
{
    std::cout << TypeDescriptor4<int>() << "\n"
              << TypeDescriptor4<char*>() << "\n"
              << TypeDescriptor4<long const*&>() << "\n"
              << TypeDescriptor4<short[10]>() << "\n"
              << TypeDescriptor4<volatile int>() << "\n";

    std::cout << TypeDescriptor4<int[2][3]>() << std::endl;
}
