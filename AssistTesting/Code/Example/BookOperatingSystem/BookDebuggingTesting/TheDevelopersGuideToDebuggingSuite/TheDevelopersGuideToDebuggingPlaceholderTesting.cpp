///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.4 (2021/10/10 19:55)

#include "TheDevelopersGuideToDebuggingPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookOperatingSystem/TheDevelopersGuideToDebugging/Helper/TheDevelopersGuideToDebuggingClassInvariantMacro.h"

BookDebugging::TheDevelopersGuideToDebugging::TheDevelopersGuideToDebuggingPlaceholderTesting::TheDevelopersGuideToDebuggingPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    THE_DEVELOPERS_GUIDE_TO_DEBUGGING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookDebugging::TheDevelopersGuideToDebugging, TheDevelopersGuideToDebuggingPlaceholderTesting)

void BookDebugging::TheDevelopersGuideToDebugging::TheDevelopersGuideToDebuggingPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookDebugging::TheDevelopersGuideToDebugging::TheDevelopersGuideToDebuggingPlaceholderTesting::MainTest() noexcept
{
}
