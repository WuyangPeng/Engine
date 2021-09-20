///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.2 (2021/08/27 22:51)

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