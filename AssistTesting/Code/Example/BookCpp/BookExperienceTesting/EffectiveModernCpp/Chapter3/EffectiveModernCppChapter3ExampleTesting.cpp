///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.2.3 (2021/09/03 21:00)

#include "EffectiveModernCppChapter3ExampleTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter3/Terms10Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter3/Terms11Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter3/Terms12Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter3/Terms13Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter3/Terms14Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter3/Terms15Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter3/Terms16Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter3/Terms17Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter3/Terms7Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter3/Terms8Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter3/Terms9Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

BookExperience::EffectiveModernCpp::Chapter3::EffectiveModernCppChapter3ExampleTesting::EffectiveModernCppChapter3ExampleTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookExperience::EffectiveModernCpp::Chapter3, EffectiveModernCppChapter3ExampleTesting)

void BookExperience::EffectiveModernCpp::Chapter3::EffectiveModernCppChapter3ExampleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookExperience::EffectiveModernCpp::Chapter3::EffectiveModernCppChapter3ExampleTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Terms7ExampleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Terms8ExampleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Terms9ExampleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Terms10ExampleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Terms11ExampleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Terms12ExampleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Terms13ExampleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Terms14ExampleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Terms15ExampleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Terms16ExampleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Terms17ExampleTest);
}

void BookExperience::EffectiveModernCpp::Chapter3::EffectiveModernCppChapter3ExampleTesting::Terms7ExampleTest()
{
    const Terms7::Terms7Example terms7Example{};

    terms7Example.InitExample();
    terms7Example.WidgetExample();
    terms7Example.Vector0Example();
    terms7Example.AtomicExample();
    terms7Example.SumExample();
    terms7Example.WidgetConstruction0Example();
    terms7Example.WidgetConstruction1Example();
    terms7Example.WidgetConstruction2Example();
    terms7Example.WidgetConstruction3Example();
    terms7Example.WidgetConstruction4Example();
    terms7Example.WidgetConstruction5Example();
    terms7Example.WidgetConstruction6Example();
    terms7Example.Vector1Example();
    terms7Example.DoSomeWorkExample();
}

void BookExperience::EffectiveModernCpp::Chapter3::EffectiveModernCppChapter3ExampleTesting::Terms8ExampleTest()
{
    const Terms8::Terms8Example terms8Example{};

    terms8Example.OverloadExample();
    terms8Example.FindRecordExample();
    terms8Example.MutexExample0();
    terms8Example.MutexExample1();
    terms8Example.MutexExample2();
}

void BookExperience::EffectiveModernCpp::Chapter3::EffectiveModernCppChapter3ExampleTesting::Terms9ExampleTest()
{
    const Terms9::Terms9Example terms9Example{};

    terms9Example.MyAllocList0Example();
    terms9Example.MyAllocList1Example();
}

void BookExperience::EffectiveModernCpp::Chapter3::EffectiveModernCppChapter3ExampleTesting::Terms10ExampleTest()
{
    const Terms10::Terms10Example terms10Example{};

    terms10Example.EnumExample();
    terms10Example.EnumClassExample();
    terms10Example.EnumConversionExample();
    terms10Example.EnumClassConversionExample();
    terms10Example.Tuple0Example();
    terms10Example.Tuple1Example();
    terms10Example.Tuple2Example();
    terms10Example.Tuple3Example();
}

void BookExperience::EffectiveModernCpp::Chapter3::EffectiveModernCppChapter3ExampleTesting::Terms11ExampleTest() noexcept
{
    const Terms11::Terms11Example terms11Example{};

    terms11Example.IsLucky0Example();
    terms11Example.IsLucky1Example();
}

void BookExperience::EffectiveModernCpp::Chapter3::EffectiveModernCppChapter3ExampleTesting::Terms12ExampleTest()
{
    const Terms12::Terms12Example terms12Example{};

    terms12Example.DoWorkExample();
    terms12Example.Widget0Example();
    terms12Example.Widget1Example();
    terms12Example.Widget2Example();
}

void BookExperience::EffectiveModernCpp::Chapter3::EffectiveModernCppChapter3ExampleTesting::Terms13ExampleTest()
{
    const Terms13::Terms13Example terms13Example{};

    terms13Example.FindExample();
    terms13Example.ConstFindCpp98Example();
    terms13Example.ConstFindCpp11Example();
}

void BookExperience::EffectiveModernCpp::Chapter3::EffectiveModernCppChapter3ExampleTesting::Terms14ExampleTest()
{
    const Terms14::Terms14Example terms14Example{};

    terms14Example.VectorExample();
}

void BookExperience::EffectiveModernCpp::Chapter3::EffectiveModernCppChapter3ExampleTesting::Terms15ExampleTest()
{
    const Terms15::Terms15Example terms15Example{};

    terms15Example.ConstexprExample();
    terms15Example.ConstExample();
    terms15Example.Pow0Example();
    terms15Example.Pow1Example();
    terms15Example.Point0Example();
    terms15Example.Point1Example();
}

void BookExperience::EffectiveModernCpp::Chapter3::EffectiveModernCppChapter3ExampleTesting::Terms16ExampleTest()
{
    const Terms16::Terms16Example terms16Example{};

    terms16Example.PolynomialExample();
}

void BookExperience::EffectiveModernCpp::Chapter3::EffectiveModernCppChapter3ExampleTesting::Terms17ExampleTest() noexcept
{
    const Terms17::Terms17Example terms17Example{};
}
