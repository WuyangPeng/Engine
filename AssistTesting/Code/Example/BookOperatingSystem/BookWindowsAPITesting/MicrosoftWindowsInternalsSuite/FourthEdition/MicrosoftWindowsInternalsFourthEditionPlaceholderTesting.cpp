///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.3 (2021/05/23 23:58)

#include "MicrosoftWindowsInternalsFourthEditionPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookOperatingSystem/MicrosoftWindowsInternalsFourthEdition/Helper/MicrosoftWindowsInternalsFourthEditionClassInvariantMacro.h"

BookWindowsAPI::MicrosoftWindowsInternals::MicrosoftWindowsInternalsFourthEditionPlaceholderTesting::MicrosoftWindowsInternalsFourthEditionPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookWindowsAPI::MicrosoftWindowsInternals, MicrosoftWindowsInternalsFourthEditionPlaceholderTesting)

void BookWindowsAPI::MicrosoftWindowsInternals::MicrosoftWindowsInternalsFourthEditionPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookWindowsAPI::MicrosoftWindowsInternals::MicrosoftWindowsInternalsFourthEditionPlaceholderTesting::MainTest() noexcept
{
}
