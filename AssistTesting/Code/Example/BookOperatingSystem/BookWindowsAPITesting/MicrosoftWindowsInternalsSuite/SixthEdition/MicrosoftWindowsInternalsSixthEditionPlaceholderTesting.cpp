///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.3 (2021/05/23 23:58)

#include "MicrosoftWindowsInternalsSixthEditionPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookOperatingSystem/MicrosoftWindowsInternalsSixthEdition/Helper/MicrosoftWindowsInternalsSixthEditionClassInvariantMacro.h"

BookWindowsAPI::MicrosoftWindowsInternals::MicrosoftWindowsInternalsSixthEditionPlaceholderTesting::MicrosoftWindowsInternalsSixthEditionPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    MICROSOFT_WINDOWS_INTERNALS_SIXTH_EDITION_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookWindowsAPI::MicrosoftWindowsInternals, MicrosoftWindowsInternalsSixthEditionPlaceholderTesting)

void BookWindowsAPI::MicrosoftWindowsInternals::MicrosoftWindowsInternalsSixthEditionPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookWindowsAPI::MicrosoftWindowsInternals::MicrosoftWindowsInternalsSixthEditionPlaceholderTesting::MainTest() noexcept
{
}
