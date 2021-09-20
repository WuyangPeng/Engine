///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.2 (2021/04/14 23:17)

#include "CppTemplateMetaprogrammingExercise2_1Testing.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Exercise2/Exercise2_1.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Helper/CppTemplateMetaprogrammingClassInvariantMacro.h"

using std::is_same_v;

BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_1Testing::CppTemplateMetaprogrammingExercise2_1Testing(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_TEMPLATE_METAPROGRAMMING_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookTemplate::CppTemplateMetaprogramming, CppTemplateMetaprogrammingExercise2_1Testing)

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_1Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_1Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ReplaceType1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(ReplaceType2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(ReplaceType3Test);
    ASSERT_NOT_THROW_EXCEPTION_0(ReplaceType4Test);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_1Testing::ReplaceType1Test() noexcept
{
    static_assert(is_same_v<ReplaceType1<void*, void, int>::Type, int*>);
    static_assert(is_same_v<ReplaceType1<int const* [10], int const, long>::Type, long* [10]>);
    static_assert(is_same_v<ReplaceType1<char& (*)(char&), char&, long&>::Type, long& (*)(long&)>);

    static_assert(is_same_v<int, ReplaceType1<void, void, int>::Type>);
    static_assert(is_same_v<int*, ReplaceType1<void*, void, int>::Type>);
    static_assert(is_same_v<int&, ReplaceType1<char&, char, int>::Type>);
    static_assert(is_same_v<int**, ReplaceType1<void**, void, int>::Type>);
    static_assert(is_same_v<int*&, ReplaceType1<void*&, void, int>::Type>);
    static_assert(is_same_v<int[5], ReplaceType1<char[5], char, int>::Type>);
    static_assert(is_same_v<long* [10], ReplaceType1<const int* [10], const int, long>::Type>);
    static_assert(is_same_v<int (*)(int), ReplaceType1<char (*)(char), char, int>::Type>);
    static_assert(is_same_v<long& (*)(long&), ReplaceType1<char& (*)(char&), char, long>::Type>);
    static_assert(is_same_v<long& (*)(long&), ReplaceType1<char& (*)(char&), char&, long&>::Type>);
    static_assert(is_same_v<long& (*)(int&), ReplaceType1<char& (*)(int&), char&, long&>::Type>);
    static_assert(is_same_v<long*, ReplaceType1<int**, int*, long>::Type>);
    static_assert(is_same_v<long&, ReplaceType1<int**&, int**, long>::Type>);

    static_assert(is_same_v<long* (*)(int*), ReplaceType1<char* (*)(int*), char*, long*>::Type>);

    static_assert(is_same_v<int (*)(), ReplaceType1<char (*)(), char, int>::Type>);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_1Testing::ReplaceType2Test() noexcept
{
    static_assert(is_same_v<ReplaceType2<void*, void, int>::Type, int*>);
    static_assert(is_same_v<ReplaceType2<int const* [10], int const, long>::Type, long* [10]>);
    static_assert(is_same_v<ReplaceType2<char& (*)(char&), char&, long&>::Type, long& (*)(long&)>);

    static_assert(is_same_v<int, ReplaceType2<void, void, int>::Type>);
    static_assert(is_same_v<int*, ReplaceType2<void*, void, int>::Type>);
    static_assert(is_same_v<int&, ReplaceType2<char&, char, int>::Type>);
    static_assert(is_same_v<int**, ReplaceType2<void**, void, int>::Type>);
    static_assert(is_same_v<int*&, ReplaceType2<void*&, void, int>::Type>);
    static_assert(is_same_v<int[5], ReplaceType2<char[5], char, int>::Type>);
    static_assert(is_same_v<long* [10], ReplaceType2<const int* [10], const int, long>::Type>);
    static_assert(is_same_v<int, ReplaceType2<char (*)(char), char, int>::R>);
    static_assert(is_same_v<int, ReplaceType2<char (*)(char), char, int>::B>);
    static_assert(is_same_v<long& (*)(long&), ReplaceType2<char& (*)(char&), char, long>::Type>);
    static_assert(is_same_v<long& (*)(long&), ReplaceType2<char& (*)(char&), char&, long&>::Type>);
    static_assert(is_same_v<long& (*)(int&), ReplaceType2<char& (*)(int&), char&, long&>::Type>);
    static_assert(is_same_v<long*, ReplaceType2<int**, int*, long>::Type>);
    static_assert(is_same_v<long&, ReplaceType2<int**&, int**, long>::Type>);

    // 警告！它不适用于以下替换 (by Jesus Andres)
    // static_assert(is_same_v<long* (*)(int*), ReplaceType2<char* (*)(int*), char*, long*>::Type>);

    static_assert(is_same_v<int (*)(), ReplaceType2<char (*)(), char, int>::Type>);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_1Testing::ReplaceType3Test() noexcept
{
    static_assert(is_same_v<ReplaceType3<void*, void, int>::Type, int*>);
    static_assert(is_same_v<ReplaceType3<int const* [10], int const, long>::Type, long* [10]>);
    static_assert(is_same_v<ReplaceType3<char& (*)(char&), char&, long&>::Type, long& (*)(long&)>);

    static_assert(is_same_v<int, ReplaceType3<void, void, int>::Type>);
    static_assert(is_same_v<int*, ReplaceType3<void*, void, int>::Type>);
    static_assert(is_same_v<int&, ReplaceType3<char&, char, int>::Type>);
    static_assert(is_same_v<int**, ReplaceType3<void**, void, int>::Type>);
    static_assert(is_same_v<int*&, ReplaceType3<void*&, void, int>::Type>);
    static_assert(is_same_v<int[5], ReplaceType3<char[5], char, int>::Type>);
    static_assert(is_same_v<long* [10], ReplaceType3<const int* [10], const int, long>::Type>);
    static_assert(is_same_v<int (*)(int), ReplaceType3<char (*)(char), char, int>::Type>);
    static_assert(is_same_v<long& (*)(long&), ReplaceType3<char& (*)(char&), char, long>::Type>);
    static_assert(is_same_v<long& (*)(long&), ReplaceType3<char& (*)(char&), char&, long&>::Type>);
    static_assert(is_same_v<long& (*)(int&), ReplaceType3<char& (*)(int&), char&, long&>::Type>);
    static_assert(is_same_v<long*, ReplaceType3<int**, int*, long>::Type>);
    static_assert(is_same_v<long&, ReplaceType3<int**&, int**, long>::Type>);

    static_assert(is_same_v<long* (*)(int*), ReplaceType3<char* (*)(int*), char*, long*>::Type>);

    // 测试失败
    // static_assert(is_same_v<int (*)(), ReplaceType3<char (*)(), char, int>::Type>);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_1Testing::ReplaceType4Test() noexcept
{
    static_assert(is_same_v<ReplaceType4<void*, void, int>::Type, int*>);
    static_assert(is_same_v<ReplaceType4<int const* [10], int const, long>::Type, long* [10]>);
    static_assert(is_same_v<ReplaceType4<char& (*)(char&), char&, long&>::Type, long& (*)(long&)>);

    static_assert(is_same_v<int, ReplaceType4<void, void, int>::Type>);
    static_assert(is_same_v<int*, ReplaceType4<void*, void, int>::Type>);
    static_assert(is_same_v<int&, ReplaceType4<char&, char, int>::Type>);
    static_assert(is_same_v<int**, ReplaceType4<void**, void, int>::Type>);
    static_assert(is_same_v<int*&, ReplaceType4<void*&, void, int>::Type>);
    static_assert(is_same_v<int[5], ReplaceType4<char[5], char, int>::Type>);
    static_assert(is_same_v<long* [10], ReplaceType4<const int* [10], const int, long>::Type>);
    static_assert(is_same_v<int (*)(int), ReplaceType4<char (*)(char), char, int>::Type>);
    static_assert(is_same_v<long& (*)(long&), ReplaceType4<char& (*)(char&), char, long>::Type>);
    static_assert(is_same_v<long& (*)(long&), ReplaceType4<char& (*)(char&), char&, long&>::Type>);
    static_assert(is_same_v<long& (*)(int&), ReplaceType4<char& (*)(int&), char&, long&>::Type>);
    static_assert(is_same_v<long*, ReplaceType4<int**, int*, long>::Type>);
    static_assert(is_same_v<long&, ReplaceType4<int**&, int**, long>::Type>);

    static_assert(is_same_v<long* (*)(int*), ReplaceType4<char* (*)(int*), char*, long*>::Type>);

    static_assert(is_same_v<int (*)(), ReplaceType4<char (*)(), char, int>::Type>);
}
