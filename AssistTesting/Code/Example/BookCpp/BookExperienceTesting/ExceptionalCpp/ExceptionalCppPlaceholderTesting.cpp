///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.0 (2021/02/20 0:17)

#include "ExceptionalCppPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/ExceptionalCpp/Helper/ExceptionalCppClassInvariantMacro.h"

BookExperience::ExceptionalCpp::ExceptionalCppPlaceholderTesting::ExceptionalCppPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    EXCEPTIONAL_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookExperience::ExceptionalCpp, ExceptionalCppPlaceholderTesting)

void BookExperience::ExceptionalCpp::ExceptionalCppPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookExperience::ExceptionalCpp::ExceptionalCppPlaceholderTesting::MainTest() noexcept
{
}
