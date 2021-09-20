///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.2 (2021/03/27 22:17)

#include "STLTutorialAndReferenceGuidePrefaceTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Example/BookCpp/STLTutorialAndReferenceGuide/Helper/STLTutorialAndReferenceGuideClassInvariantMacro.h"
#include "Example/BookCpp/STLTutorialAndReferenceGuide/Preface/PrefaceDetail.h"

BookStandardLibrary::STLTutorialAndReferenceGuide::STLTutorialAndReferenceGuidePrefaceTesting::STLTutorialAndReferenceGuidePrefaceTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    STL_TUTORIAL_AND_REFERENCE_GUIDE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookStandardLibrary::STLTutorialAndReferenceGuide, STLTutorialAndReferenceGuidePrefaceTesting)

void BookStandardLibrary::STLTutorialAndReferenceGuide::STLTutorialAndReferenceGuidePrefaceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookStandardLibrary::STLTutorialAndReferenceGuide::STLTutorialAndReferenceGuidePrefaceTesting::MainTest()
{
    const Preface preface{};

    preface.Main();

    ASSERT_EQUAL(preface.Gcd0(1, -1), -1);
    ASSERT_EQUAL(preface.Gcd0(-1, 1), 1);
    ASSERT_EQUAL(preface.Gcd1(1, -1), 1);
    ASSERT_EQUAL(preface.Gcd1(-1, 1), 1);

    ASSERT_EQUAL(preface.Gcd0(2, 4), 2);
    ASSERT_EQUAL(preface.Gcd0(9, 27), 9);
    ASSERT_EQUAL(preface.Gcd1(4, 8), 4);
    ASSERT_EQUAL(preface.Gcd1(21, 9), 3);
}
