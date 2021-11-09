///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.2.5 (2021/11/03 22:34)

#include "EffectiveModernCppChapter5ExampleTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

BookExperience::EffectiveModernCpp::Chapter5::EffectiveModernCppChapter5ExampleTesting::EffectiveModernCppChapter5ExampleTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookExperience::EffectiveModernCpp::Chapter5, EffectiveModernCppChapter5ExampleTesting)

void BookExperience::EffectiveModernCpp::Chapter5::EffectiveModernCppChapter5ExampleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookExperience::EffectiveModernCpp::Chapter5::EffectiveModernCppChapter5ExampleTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Terms23ExampleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Terms24ExampleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Terms25ExampleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Terms26ExampleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Terms27ExampleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Terms28ExampleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Terms29ExampleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Terms30ExampleTest);
}

void BookExperience::EffectiveModernCpp::Chapter5::EffectiveModernCppChapter5ExampleTesting::Terms23ExampleTest() noexcept
{
}

void BookExperience::EffectiveModernCpp::Chapter5::EffectiveModernCppChapter5ExampleTesting::Terms24ExampleTest() noexcept
{
}

void BookExperience::EffectiveModernCpp::Chapter5::EffectiveModernCppChapter5ExampleTesting::Terms25ExampleTest() noexcept
{
}

void BookExperience::EffectiveModernCpp::Chapter5::EffectiveModernCppChapter5ExampleTesting::Terms26ExampleTest() noexcept
{
}

void BookExperience::EffectiveModernCpp::Chapter5::EffectiveModernCppChapter5ExampleTesting::Terms27ExampleTest() noexcept
{
}

void BookExperience::EffectiveModernCpp::Chapter5::EffectiveModernCppChapter5ExampleTesting::Terms28ExampleTest() noexcept
{
}

void BookExperience::EffectiveModernCpp::Chapter5::EffectiveModernCppChapter5ExampleTesting::Terms29ExampleTest() noexcept
{
}

void BookExperience::EffectiveModernCpp::Chapter5::EffectiveModernCppChapter5ExampleTesting::Terms30ExampleTest() noexcept
{
}
