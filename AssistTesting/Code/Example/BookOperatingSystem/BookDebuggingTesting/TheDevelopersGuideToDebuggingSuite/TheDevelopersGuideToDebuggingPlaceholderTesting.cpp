///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.2.4 (2021/10/10 19:55)

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
