///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.4 (2021/10/10 19:55)

#include "SafeCppPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookOperatingSystem/SafeCpp/Helper/SafeCppClassInvariantMacro.h"

BookDebugging::SafeCpp::SafeCppPlaceholderTesting::SafeCppPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SAFE_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookDebugging::SafeCpp, SafeCppPlaceholderTesting)

void BookDebugging::SafeCpp::SafeCppPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookDebugging::SafeCpp::SafeCppPlaceholderTesting::MainTest() noexcept
{
}
