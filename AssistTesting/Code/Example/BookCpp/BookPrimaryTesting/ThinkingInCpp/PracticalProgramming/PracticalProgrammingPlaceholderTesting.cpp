///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.6.0.1 (2021/01/02 22:59)

#include "PracticalProgrammingPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/ThinkingInCppVolumeTwo/Helper/ThinkingInCppVolumeTwoClassInvariantMacro.h"

BookPrimary::ThinkingInCpp::PracticalProgrammingPlaceholderTesting::PracticalProgrammingPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    THINKING_IN_CPP_VOLUME_TWO_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookPrimary::ThinkingInCpp, PracticalProgrammingPlaceholderTesting)

void BookPrimary::ThinkingInCpp::PracticalProgrammingPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookPrimary::ThinkingInCpp::PracticalProgrammingPlaceholderTesting::MainTest() noexcept
{
}
