///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.2.7 (2021/11/29 21:37)

#include "EffectiveModernCppChapter6ExampleTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter6/Chapter6Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter6/Terms31Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter6/Terms32Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter6/Terms33Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter6/Terms34Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

BookExperience::EffectiveModernCpp::Chapter6::EffectiveModernCppChapter6ExampleTesting::EffectiveModernCppChapter6ExampleTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookExperience::EffectiveModernCpp::Chapter6, EffectiveModernCppChapter6ExampleTesting)

void BookExperience::EffectiveModernCpp::Chapter6::EffectiveModernCppChapter6ExampleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookExperience::EffectiveModernCpp::Chapter6::EffectiveModernCppChapter6ExampleTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Chapter6ExampleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Terms31ExampleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Terms32ExampleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Terms33ExampleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Terms34ExampleTest);
}

void BookExperience::EffectiveModernCpp::Chapter6::EffectiveModernCppChapter6ExampleTesting::Chapter6ExampleTest()
{
    const Chapter6Example chapter6Example{};

    chapter6Example.FindExample();
    chapter6Example.LambdaExample();
}

void BookExperience::EffectiveModernCpp::Chapter6::EffectiveModernCppChapter6ExampleTesting::Terms31ExampleTest()
{
    const Terms31::Terms31Example terms31Example{};

    terms31Example.AddDivisorFilterExample();
}

void BookExperience::EffectiveModernCpp::Chapter6::EffectiveModernCppChapter6ExampleTesting::Terms32ExampleTest()
{
    const Terms32::Terms32Example terms32Example{};

    terms32Example.Widget0Example();
    terms32Example.Widget1Example();
    terms32Example.IsValAndArchExample();
    terms32Example.Vector0Example();
    terms32Example.Vector1Example();
    terms32Example.Vector2Example();
    terms32Example.Widget2Example();
}

void BookExperience::EffectiveModernCpp::Chapter6::EffectiveModernCppChapter6ExampleTesting::Terms33ExampleTest() noexcept
{
    const Terms33::Terms33Example terms33Example{};

    terms33Example.Lambda0Example();
    terms33Example.Lambda1Example();
    terms33Example.Lambda2Example();
    terms33Example.Lambda3Example();
}

void BookExperience::EffectiveModernCpp::Chapter6::EffectiveModernCppChapter6ExampleTesting::Terms34ExampleTest()  
{
    const Terms34::Terms34Example terms34Example{};

    terms34Example.SetSound0Example();
    terms34Example.SetSound1Example();
    terms34Example.SetSound2Example();
    terms34Example.SetSound3Example();
    terms34Example.SetSound4Example();
    terms34Example.SetSound5Example();
    terms34Example.SetSound6Example();
    terms34Example.SetSound7Example();

    terms34Example.Between0Example();
    terms34Example.Between1Example();
    terms34Example.Between2Example();
    terms34Example.Between3Example();

    terms34Example.CompressExample();

    terms34Example.PolyWidget0Example();
    terms34Example.PolyWidget1Example();
}
