///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.0 (2021/01/24 16:55)

#include "AdvancedCppPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/AdvancedCpp/Helper/AdvancedCppClassInvariantMacro.h"

BookIntermediate::AdvancedCpp::AdvancedCppPlaceholderTesting::AdvancedCppPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    ADVANCED_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookIntermediate::AdvancedCpp, AdvancedCppPlaceholderTesting)

void BookIntermediate::AdvancedCpp::AdvancedCppPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookIntermediate::AdvancedCpp::AdvancedCppPlaceholderTesting::MainTest() noexcept
{
}
