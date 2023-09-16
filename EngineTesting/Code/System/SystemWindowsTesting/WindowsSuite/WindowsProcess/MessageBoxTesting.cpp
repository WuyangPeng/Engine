///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 15:22)

#include "MessageBoxTesting.h"
#include "System/Windows/WindowsProcess.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::MessageBoxTesting::MessageBoxTesting(const OStreamShared& stream, WindowsHWnd hWnd)
    : ParentType{ stream }, hWnd{ hWnd }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, MessageBoxTesting)

void System::MessageBoxTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::MessageBoxTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MessageBoxTest);
}

void System::MessageBoxTesting::MessageBoxTest()
{
    MAYBE_UNUSED const auto result = DefaultMessageBox(hWnd, SYSTEM_TEXT("消息"), SYSTEM_TEXT("消息标题"));
}
