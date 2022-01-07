///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.6 (2021/11/20 22:04)

#include "EffectiveModernCppChapter5ExampleTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter5/Terms23Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter5/Terms24Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter5/Terms25Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter5/Terms26Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter5/Terms27Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter5/Terms28Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter5/Terms29Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter5/Terms30Example.h"
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

void BookExperience::EffectiveModernCpp::Chapter5::EffectiveModernCppChapter5ExampleTesting::Terms23ExampleTest()
{
    const Terms23::Terms23Example terms23Example{};

    terms23Example.LogExample();
}

void BookExperience::EffectiveModernCpp::Chapter5::EffectiveModernCppChapter5ExampleTesting::Terms24ExampleTest() noexcept
{
    const Terms24::Terms24Example terms24Example{};

    terms24Example.UniversalReference0Example();
    terms24Example.UniversalReference1Example();
    terms24Example.Universa1Reference2Example();
    terms24Example.Vector0Example();
    terms24Example.Vector1Example();
    terms24Example.TimeFuncInvocationExample();
}

void BookExperience::EffectiveModernCpp::Chapter5::EffectiveModernCppChapter5ExampleTesting::Terms25ExampleTest()
{
    const Terms25::Terms25Example terms25Example{};

    terms25Example.MoveExample();
    terms25Example.SetNameExample();
}

void BookExperience::EffectiveModernCpp::Chapter5::EffectiveModernCppChapter5ExampleTesting::Terms26ExampleTest()
{
    const Terms26::Terms26Example terms26Example{};

    terms26Example.Log0Example();
    terms26Example.Log1Example();
    terms26Example.Log2Example();
    terms26Example.Person0Example();
    terms26Example.Person1Example();
}

void BookExperience::EffectiveModernCpp::Chapter5::EffectiveModernCppChapter5ExampleTesting::Terms27ExampleTest()
{
    const Terms27::Terms27Example terms27Example{};

    terms27Example.Person0Example();
    terms27Example.Person1Example();
    terms27Example.Person2Example();
}

void BookExperience::EffectiveModernCpp::Chapter5::EffectiveModernCppChapter5ExampleTesting::Terms28ExampleTest() noexcept
{
    const Terms28::Terms28Example terms28Example{};

    terms28Example.Widget0Example();
    terms28Example.RefExample();
    terms28Example.AutoExample();
    terms28Example.Widget1Example();
}

void BookExperience::EffectiveModernCpp::Chapter5::EffectiveModernCppChapter5ExampleTesting::Terms29ExampleTest() noexcept
{
    const Terms29::Terms29Example terms29Example{};

    terms29Example.MoveExample();
}

void BookExperience::EffectiveModernCpp::Chapter5::EffectiveModernCppChapter5ExampleTesting::Terms30ExampleTest()
{
    const Terms30::Terms30Example terms30Example{};

    terms30Example.BracesExample();
    terms30Example.StaticExample();
    terms30Example.ProcessValExample();
    terms30Example.IPv4Example();
}
