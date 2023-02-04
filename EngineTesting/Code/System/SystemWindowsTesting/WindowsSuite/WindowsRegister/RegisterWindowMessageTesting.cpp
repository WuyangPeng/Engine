///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/02 21:13)

#include "RegisterWindowMessageTesting.h"
#include "System/Windows/Flags/WindowsPictorialFlags.h"
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
    const auto messageID = RegisterSystemWindowMessage(SYSTEM_TEXT("WindowRegisterTesting"));

    ASSERT_RANGE(messageID, 0xC000u, 0xFFFFu);
}
