///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 15:22)

#include "PeekMessageTesting.h"
#include "System/Windows/WindowsProcess.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::PeekMessageTesting::PeekMessageTesting(const OStreamShared& stream, WindowsHWnd hWnd)
    : ParentType{ stream }, hWnd{ hWnd }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, PeekMessageTesting)

void System::PeekMessageTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::PeekMessageTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PeekMessageTest);
}

void System::PeekMessageTesting::PeekMessageTest() noexcept
{
    WindowsMessage msg{};
    MAYBE_UNUSED const auto result = PeekSystemMessage(&msg, hWnd);
}
