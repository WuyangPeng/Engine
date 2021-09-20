///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.0 (2021/01/27 0:11)

#include "AppliedCppChapter2MainTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Example/BookCpp/AppliedCpp/Chapter2/Chapter2Main.h"
#include "Example/BookCpp/AppliedCpp/Helper/AppliedCppClassInvariantMacro.h"

BookIntermediate::AppliedCpp::AppliedCppChapter2MainTesting::AppliedCppChapter2MainTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    APPLIED_CPP_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookIntermediate::AppliedCpp, AppliedCppChapter2MainTesting)

void BookIntermediate::AppliedCpp::AppliedCppChapter2MainTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookIntermediate::AppliedCpp::AppliedCppChapter2MainTesting::MainTest()
{
    const Chapter2Main chapter2Main{};

    ASSERT_EQUAL(0, chapter2Main.Main());

    chapter2Main.ArbitraryAlgorithm();
}
