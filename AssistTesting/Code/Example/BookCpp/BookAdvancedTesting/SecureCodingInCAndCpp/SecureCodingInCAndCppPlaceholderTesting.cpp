///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.1 (2021/03/21 12:34)

#include "SecureCodingInCAndCppPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/LargeScaleCppSoftwareDesign/Helper/LargeScaleCppSoftwareDesignClassInvariantMacro.h"

BookAdvanced::SecureCodingInCAndCpp::SecureCodingInCAndCppPlaceholderTesting::SecureCodingInCAndCppPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    LARGE_SCALE_CPP_SOFTWARE_DESIGN_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAdvanced::SecureCodingInCAndCpp, SecureCodingInCAndCppPlaceholderTesting)

void BookAdvanced::SecureCodingInCAndCpp::SecureCodingInCAndCppPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAdvanced::SecureCodingInCAndCpp::SecureCodingInCAndCppPlaceholderTesting::MainTest() noexcept
{
}
