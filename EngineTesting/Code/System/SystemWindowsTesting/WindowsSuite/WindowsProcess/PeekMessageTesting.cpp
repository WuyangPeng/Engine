///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/05 19:45)

#include "PeekMessageTesting.h"
#include "System/Windows/WindowsProcess.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::PeekMessageTesting::PeekMessageTesting(const OStreamShared& stream, WindowsHWnd hwnd)
    : ParentType{ stream }, hwnd{ hwnd }
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
    WindowsMsg msg{};
    MAYBE_UNUSED const auto result = PeekSystemMessage(&msg, hwnd);
}
