///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.2.3 (2021/09/03 21:00)

#include "EffectiveModernCppChapter2ExampleTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter2/Terms5Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter2/Terms6Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

BookExperience::EffectiveModernCpp::Chapter2::EffectiveModernCppChapter2ExampleTesting::EffectiveModernCppChapter2ExampleTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookExperience::EffectiveModernCpp::Chapter2, EffectiveModernCppChapter2ExampleTesting)

void BookExperience::EffectiveModernCpp::Chapter2::EffectiveModernCppChapter2ExampleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookExperience::EffectiveModernCpp::Chapter2::EffectiveModernCppChapter2ExampleTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Terms5ExampleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Terms6ExampleTest);
}

void BookExperience::EffectiveModernCpp::Chapter2::EffectiveModernCppChapter2ExampleTesting::Terms5ExampleTest()
{
    const Terms5::Terms5Example terms5Example{};

    terms5Example.AutoExample();
    terms5Example.LambadExample();
    terms5Example.FunctionExample();
    terms5Example.TypeExample();
}

void BookExperience::EffectiveModernCpp::Chapter2::EffectiveModernCppChapter2ExampleTesting::Terms6ExampleTest()
{
    const Terms6::Terms6Example terms6Example{};

    terms6Example.VectorExample();
    terms6Example.AutoErrorExample();
    terms6Example.MatrixExample();
    terms6Example.StaticCastExample();
    terms6Example.CalcEpsilonExample();
    terms6Example.IndexExample();
}
