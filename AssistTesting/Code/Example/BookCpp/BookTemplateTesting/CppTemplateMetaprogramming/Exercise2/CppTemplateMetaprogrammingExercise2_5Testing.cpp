///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.2 (2021/04/14 23:17)

#include "CppTemplateMetaprogrammingExercise2_5Testing.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Exercise2/Exercise2_5.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Helper/CppTemplateMetaprogrammingClassInvariantMacro.h"

BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_5Testing::CppTemplateMetaprogrammingExercise2_5Testing(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_TEMPLATE_METAPROGRAMMING_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookTemplate::CppTemplateMetaprogramming, CppTemplateMetaprogrammingExercise2_5Testing)

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_5Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_5Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TypeDescriptor20Test);
    ASSERT_NOT_THROW_EXCEPTION_0(TypeDescriptor21Test);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_5Testing::TypeDescriptor20Test()
{
    std::cout << TypeDescriptor20<int>() << "\n"
              << TypeDescriptor20<char*>() << "\n"
              << TypeDescriptor20<long const*&>() << "\n"
              << TypeDescriptor20<short[10]>() << "\n"
              << TypeDescriptor20<volatile int>() << "\n"
              << TypeDescriptor20<char* (*[])()>() << "\n";
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_5Testing::TypeDescriptor21Test()
{
    std::cout << TypeDescriptor21<int>() << "\n"
              << TypeDescriptor21<char*>() << "\n"
              << TypeDescriptor21<long const*&>() << "\n"
              << TypeDescriptor21<short[10]>() << "\n"
              << TypeDescriptor21<volatile int>() << "\n"
              << TypeDescriptor21<char* (*[])()>() << "\n";
}
