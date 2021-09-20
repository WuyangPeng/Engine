///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.2 (2021/04/13 23:25)

#include "CppTemplateMetaprogrammingExercise2_0Testing.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Exercise2/Exercise2_0.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Helper/CppTemplateMetaprogrammingClassInvariantMacro.h"

using std::is_same_v;

BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_0Testing::CppTemplateMetaprogrammingExercise2_0Testing(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_TEMPLATE_METAPROGRAMMING_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookTemplate::CppTemplateMetaprogramming, CppTemplateMetaprogrammingExercise2_0Testing)

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_0Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_0Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AddConstRef1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(AddConstRef2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(AddConstRef3Test);
    ASSERT_NOT_THROW_EXCEPTION_0(AddConstRef4Test);
    ASSERT_NOT_THROW_EXCEPTION_0(AddConstRef5Test);
    ASSERT_NOT_THROW_EXCEPTION_0(AddConstRef6Test);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_0Testing::AddConstRef1Test() noexcept
{
    static_assert(is_same_v<const char&, AddConstRef1<char>::Type>);
    static_assert(is_same_v<int* const&, AddConstRef1<int*>::Type>);
    static_assert(is_same_v<int&, AddConstRef1<int&>::Type>);
    static_assert(is_same_v<const long&, AddConstRef1<const long&>::Type>);

    static_assert(is_same_v<int const&, AddConstRef1<int>::Type>);
    static_assert(is_same_v<int const&, AddConstRef1<const int&>::Type>);

    static_assert(is_same_v<int const&, AddConstRef1<int const>::Type>);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_0Testing::AddConstRef2Test() noexcept
{
    static_assert(is_same_v<const char&, AddConstRef2<char>::Type>);
    static_assert(is_same_v<int* const&, AddConstRef2<int*>::Type>);
    static_assert(is_same_v<int&, AddConstRef2<int&>::Type>);
    static_assert(is_same_v<const long&, AddConstRef2<const long&>::Type>);

    static_assert(is_same_v<int const&, AddConstRef2<int>::Type>);
    static_assert(is_same_v<int const&, AddConstRef2<const int&>::Type>);

    static_assert(is_same_v<int const&, AddConstRef2<int const>::Type>);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_0Testing::AddConstRef3Test() noexcept
{
    static_assert(is_same_v<const char&, AddConstRef3<char>::Type>);
    static_assert(is_same_v<int* const&, AddConstRef3<int*>::Type>);
    static_assert(is_same_v<int&, AddConstRef3<int&>::Type>);
    static_assert(is_same_v<const long&, AddConstRef3<const long&>::Type>);

    static_assert(is_same_v<int const&, AddConstRef3<int>::Type>);
    static_assert(is_same_v<int const&, AddConstRef3<const int&>::Type>);

    static_assert(is_same_v<int const&, AddConstRef3<int const>::Type>);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_0Testing::AddConstRef4Test() noexcept
{
    static_assert(is_same_v<const char&, AddConstRef4<char>::Type>);
    static_assert(is_same_v<int* const&, AddConstRef4<int*>::Type>);
    static_assert(is_same_v<int&, AddConstRef4<int&>::Type>);
    static_assert(is_same_v<const long&, AddConstRef4<const long&>::Type>);

    static_assert(is_same_v<int const&, AddConstRef4<int>::Type>);
    static_assert(is_same_v<int const&, AddConstRef4<const int&>::Type>);

    static_assert(is_same_v<int const&, AddConstRef4<int const>::Type>);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_0Testing::AddConstRef5Test() noexcept
{
    static_assert(is_same_v<const char&, AddConstRef5<char>::Type>);
    static_assert(is_same_v<int* const&, AddConstRef5<int*>::Type>);
    static_assert(is_same_v<int&, AddConstRef5<int&>::Type>);
    static_assert(is_same_v<const long&, AddConstRef5<const long&>::Type>);

    static_assert(is_same_v<int const&, AddConstRef5<int>::Type>);
    static_assert(is_same_v<int const&, AddConstRef5<const int&>::Type>);

    static_assert(is_same_v<int const&, AddConstRef5<int const>::Type>);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_0Testing::AddConstRef6Test() noexcept
{
    static_assert(is_same_v<const char&, AddConstRef6<char>::Type>);
    static_assert(is_same_v<int* const&, AddConstRef6<int*>::Type>);
    static_assert(is_same_v<const long&, AddConstRef6<const long&>::Type>);

    static_assert(is_same_v<int const&, AddConstRef6<int>::Type>);
    static_assert(is_same_v<int const&, AddConstRef6<const int&>::Type>);

    static_assert(is_same_v<int const&, AddConstRef6<int const>::Type>);

    // 这里并不符合题目的要求。
    static_assert(is_same_v<const int&, AddConstRef6<int&>::Type>);   
}
