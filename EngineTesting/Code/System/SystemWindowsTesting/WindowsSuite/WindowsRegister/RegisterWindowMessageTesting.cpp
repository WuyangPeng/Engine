/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 17:18)

#include "RegisterWindowMessageTesting.h"
#include "System/Windows/WindowsRegister.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::RegisterWindowMessageTesting::RegisterWindowMessageTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, RegisterWindowMessageTesting)

void System::RegisterWindowMessageTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::RegisterWindowMessageTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RegisterWindowMessageTest);
}

void System::RegisterWindowMessageTesting::RegisterWindowMessageTest()
{
    const auto messageId = RegisterSystemWindowMessage(SYSTEM_TEXT("WindowRegisterTesting"));

    ASSERT_RANGE(messageId, 0xC000u, 0xFFFFu);
}
