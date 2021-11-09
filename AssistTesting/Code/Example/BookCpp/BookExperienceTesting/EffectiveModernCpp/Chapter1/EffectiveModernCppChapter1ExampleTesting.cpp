///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.2.3 (2021/09/03 21:00)

#include "EffectiveModernCppChapter1ExampleTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter1/Terms1Derive.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter1/Terms1Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter1/Terms2Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter1/Terms3Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter1/Terms4Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

BookExperience::EffectiveModernCpp::Chapter1::EffectiveModernCppChapter1ExampleTesting::EffectiveModernCppChapter1ExampleTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookExperience::EffectiveModernCpp::Chapter1, EffectiveModernCppChapter1ExampleTesting)

void BookExperience::EffectiveModernCpp::Chapter1::EffectiveModernCppChapter1ExampleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookExperience::EffectiveModernCpp::Chapter1::EffectiveModernCppChapter1ExampleTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Terms1ExampleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ArraySizeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Terms2ExampleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Terms3ExampleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Terms4ExampleTest);
}

void BookExperience::EffectiveModernCpp::Chapter1::EffectiveModernCppChapter1ExampleTesting::Terms1ExampleTest() noexcept
{
    const Terms1::Terms1Example chapter1Example{};

    chapter1Example.Derivation();
    chapter1Example.Derivation0();
    chapter1Example.Derivation1();
    chapter1Example.Derivation2();
    chapter1Example.Derivation3();
    chapter1Example.Derivation4();
    chapter1Example.Derivation5();
    chapter1Example.ArrayDegeneratePointer();
    chapter1Example.Derivation7();
    chapter1Example.ArraySizeTest();
    chapter1Example.Derivation8();
}

void BookExperience::EffectiveModernCpp::Chapter1::EffectiveModernCppChapter1ExampleTesting::ArraySizeTest() noexcept
{
    const int keyVals[] = { 1, 3, 7, 9, 11, 22, 35 };  // keyVals含有7个元素

    static_assert(Terms1::ArraySize(keyVals) == 7);
}

void BookExperience::EffectiveModernCpp::Chapter1::EffectiveModernCppChapter1ExampleTesting::Terms2ExampleTest() noexcept
{
    const Terms2::Terms2Example chapter2Example{};

    chapter2Example.Derivation();
    chapter2Example.Derivation0();
    chapter2Example.Derivation1();
    chapter2Example.Derivation2();
}

void BookExperience::EffectiveModernCpp::Chapter1::EffectiveModernCppChapter1ExampleTesting::Terms3ExampleTest()
{
    const Terms3::Terms3Example chapter3Example{};

    chapter3Example.Derivation();
    chapter3Example.AuthAndAccessTest();
}

void BookExperience::EffectiveModernCpp::Chapter1::EffectiveModernCppChapter1ExampleTesting::Terms4ExampleTest()
{
    const Terms4::Terms4Example chapter4Example{};

    chapter4Example.Derivation();
    chapter4Example.TypeIndex();
}
