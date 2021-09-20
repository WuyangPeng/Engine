///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.2.2 (2021/08/27 22:51)

#include "EffectiveModernCppPrefaceExampleTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"
#include "Example/BookCpp/EffectiveModernCpp/Preface/ConstructorTemplateArgumentDeductionDetail.h"
#include "Example/BookCpp/EffectiveModernCpp/Preface/PrefaceExample.h"

BookExperience::EffectiveModernCpp::Preface::EffectiveModernCppPrefaceExampleTesting::EffectiveModernCppPrefaceExampleTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookExperience::EffectiveModernCpp::Preface, EffectiveModernCppPrefaceExampleTesting)

void BookExperience::EffectiveModernCpp::Preface::EffectiveModernCppPrefaceExampleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookExperience::EffectiveModernCpp::Preface::EffectiveModernCppPrefaceExampleTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructorTemplateArgumentDeductionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PrefaceExampleTest);
}

void BookExperience::EffectiveModernCpp::Preface::EffectiveModernCppPrefaceExampleTesting::ConstructorTemplateArgumentDeductionTest() noexcept
{
    const ConstructorTemplateArgumentDeduction constructorTemplateArgumentDeduction{ 1, 1.0, 3.0f };
}

void BookExperience::EffectiveModernCpp::Preface::EffectiveModernCppPrefaceExampleTesting::PrefaceExampleTest()
{
    const PrefaceExample prefaceExample{};

    prefaceExample.ProcessValsTest();
    prefaceExample.SomeFuncTest();
    prefaceExample.MatrixTest();
    ASSERT_TRUE(prefaceExample.DeclarationTest());
}