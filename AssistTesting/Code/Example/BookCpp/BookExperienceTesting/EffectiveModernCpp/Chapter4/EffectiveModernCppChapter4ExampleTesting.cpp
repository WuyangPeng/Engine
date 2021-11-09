///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.2.4 (2021/10/10 21:05)

#include "EffectiveModernCppChapter4ExampleTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter4/Terms18Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter4/Terms19Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter4/Terms20Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter4/Terms21Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter4/Terms22Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

BookExperience::EffectiveModernCpp::Chapter4::EffectiveModernCppChapter4ExampleTesting::EffectiveModernCppChapter4ExampleTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookExperience::EffectiveModernCpp::Chapter4, EffectiveModernCppChapter4ExampleTesting)

void BookExperience::EffectiveModernCpp::Chapter4::EffectiveModernCppChapter4ExampleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookExperience::EffectiveModernCpp::Chapter4::EffectiveModernCppChapter4ExampleTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Terms18ExampleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Terms19ExampleTest);
    ASSERT_THROW_EXCEPTION_0(Terms20ExampleExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Terms21ExampleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Terms22ExampleTest);
}

void BookExperience::EffectiveModernCpp::Chapter4::EffectiveModernCppChapter4ExampleTesting::Terms18ExampleTest()
{
    const Terms18::Terms18Example terms18Example{};

    terms18Example.MakeInvestmentExample();
    terms18Example.SharedPtrExample();
}

void BookExperience::EffectiveModernCpp::Chapter4::EffectiveModernCppChapter4ExampleTesting::Terms19ExampleTest()
{
    const Terms19::Terms19Example terms19Example{};

    terms19Example.SharedPtr0Example();
    terms19Example.SharedPtr1Example();
    terms19Example.ErrorSharedPtrExample();
    terms19Example.SharedPtr2Example();
}

void BookExperience::EffectiveModernCpp::Chapter4::EffectiveModernCppChapter4ExampleTesting::Terms20ExampleExceptionTest()
{
    const Terms20::Terms20Example terms20Example{};

    terms20Example.WeakPtrExample();
}

void BookExperience::EffectiveModernCpp::Chapter4::EffectiveModernCppChapter4ExampleTesting::Terms21ExampleTest()
{
    const Terms21::Terms21Example terms21Example{};

    terms21Example.MakeExample();
    terms21Example.ProcessWidget0Example();
    terms21Example.DeleterExample();
    terms21Example.Vector0Example();
    terms21Example.Vector1Example();
    terms21Example.ReallyBigType0Example();
    terms21Example.ReallyBigType1Example();
    terms21Example.ProcessWidget1Example();
    terms21Example.ProcessWidget2Example();
    terms21Example.ProcessWidget3Example();
}

void BookExperience::EffectiveModernCpp::Chapter4::EffectiveModernCppChapter4ExampleTesting::Terms22ExampleTest()  
{
    const Terms22::Terms22Example terms22Example{};

    terms22Example.Widget0Example();
    terms22Example.Widget1Example();
    terms22Example.Widget2Example();
    terms22Example.SharedPtrExample();
}
