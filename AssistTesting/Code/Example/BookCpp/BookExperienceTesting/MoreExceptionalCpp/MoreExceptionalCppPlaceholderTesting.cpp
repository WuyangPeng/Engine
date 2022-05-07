///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.0 (2021/02/20 0:17)

#include "MoreExceptionalCppPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/MoreExceptionalCpp/Helper/MoreExceptionalCppClassInvariantMacro.h"

BookExperience::MoreExceptionalCpp::MoreExceptionalCppPlaceholderTesting::MoreExceptionalCppPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    MORE_EXCEPTIONAL_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookExperience::MoreExceptionalCpp, MoreExceptionalCppPlaceholderTesting)

void BookExperience::MoreExceptionalCpp::MoreExceptionalCppPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookExperience::MoreExceptionalCpp::MoreExceptionalCppPlaceholderTesting::MainTest() noexcept
{
}