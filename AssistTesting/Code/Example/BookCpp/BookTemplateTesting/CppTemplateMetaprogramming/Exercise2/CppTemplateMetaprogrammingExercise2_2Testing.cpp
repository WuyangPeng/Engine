///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.2 (2021/04/14 23:17)

#include "CppTemplateMetaprogrammingExercise2_2Testing.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Exercise2/Exercise2_2.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Helper/CppTemplateMetaprogrammingClassInvariantMacro.h"

#define OPEN_POLYMORPHIC_DOWNCAST_ASSERT_TEST
#undef OPEN_POLYMORPHIC_DOWNCAST_ASSERT_TEST

BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_2Testing::CppTemplateMetaprogrammingExercise2_2Testing(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_TEMPLATE_METAPROGRAMMING_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookTemplate::CppTemplateMetaprogramming, CppTemplateMetaprogrammingExercise2_2Testing)

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PolymorphicDowncastTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PolymorphicDowncast1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(PolymorphicDowncast2Test);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_2Testing::PolymorphicDowncastTest() noexcept(g_CppTemplateMetaprogrammingAssert < 0)
{
    Test();
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_2Testing::PolymorphicDowncast1Test() noexcept(g_CppTemplateMetaprogrammingAssert < 0)
{
    ATest a{};
    B b;
    ATest* aptr = &b;
    MAYBE_UNUSED const B* bptr = PolymorphicDowncast1<B*>(aptr);

    // should assert
#ifdef OPEN_POLYMORPHIC_DOWNCAST_ASSERT_TEST
    aptr = &a;
    bptr = PolymorphicDowncast1<B*>(aptr);
#endif  // OPEN_POLYMORPHIC_DOWNCAST_ASSERT_TEST

    ATest& aref = b;
    MAYBE_UNUSED const B& bref = PolymorphicDowncast1<B&>(aref);

    // should assert (not throw an exception)
#ifdef OPEN_POLYMORPHIC_DOWNCAST_ASSERT_TEST
    ATest& aref2 = a;
    MAYBE_UNUSED const B& bref2 = PolymorphicDowncast1<B&>(aref2);
#endif  // OPEN_POLYMORPHIC_DOWNCAST_ASSERT_TEST
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_2Testing::PolymorphicDowncast2Test() noexcept(g_CppTemplateMetaprogrammingAssert < 0)
{
    ATest a{};
    B b;
    ATest* aptr = &b;
    MAYBE_UNUSED const B* bptr = PolymorphicDowncast2<B*>(aptr);

    // should assert
#ifdef OPEN_POLYMORPHIC_DOWNCAST_ASSERT_TEST
    aptr = &a;
    bptr = PolymorphicDowncast2<B*>(aptr);
#endif  // OPEN_POLYMORPHIC_DOWNCAST_ASSERT_TEST

    ATest& aref = b;
    MAYBE_UNUSED const B& bref = PolymorphicDowncast2<B&>(aref);

    // should assert (not throw an exception)
#ifdef OPEN_POLYMORPHIC_DOWNCAST_ASSERT_TEST
    ATest& aref2 = a;
    MAYBE_UNUSED const B& bref2 = PolymorphicDowncast2<B&>(aref2);
#endif  // OPEN_POLYMORPHIC_DOWNCAST_ASSERT_TEST
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_2Testing::PolymorphicDowncast3Test()
{
    D d{};
    // Our version
    BTest& br = d;
    MAYBE_UNUSED const D& dr = PolymorphicDowncast3<D&>(br);

    // Boost's version
    BTest* bp = &d;
    MAYBE_UNUSED const D* dp = boost::polymorphic_downcast<D*>(bp);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_2Testing::PolymorphicDowncast4Test() noexcept
{
    B b{};
    ATest* aPtr = &b;
    MAYBE_UNUSED const B* bPtr = PolymorphicDowncast4<B*>(aPtr);
    ATest& aRef = b;
    MAYBE_UNUSED const B& bRef = PolymorphicDowncast4<B&, ATest&>(aRef);
}
