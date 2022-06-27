///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 17:22)

#include "WindowMessageUnitTestSuiteTesting.h"
#include "System/Windows/Flags/WindowsKeyCodesFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/WindowMessageUnitTestSuiteTesting/SuiteWindowMessage.h"

Framework::WindowMessageUnitTestSuiteTesting::WindowMessageUnitTestSuiteTesting(const OStreamShared& stream, const WindowMessageSharedPtr& message)
    : ParentType{ stream }, mMessage{ message }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowMessageUnitTestSuiteTesting)

void Framework::WindowMessageUnitTestSuiteTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowMessageUnitTestSuiteTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(KeyDownMessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateMessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DisplayTest);
}

void Framework::WindowMessageUnitTestSuiteTesting::KeyDownMessageTest()
{
    auto message = mMessage.lock();

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(message, "消息指针已无效！");

    ASSERT_EQUAL(message->KeyDownMessage(message->GetHwnd(), System::EnumCastUnderlying<System::WindowsWParam>(System::WindowsKeyCodes::F1), 0), 0);
    ASSERT_EQUAL(message->GetPassedNumber(), 1);
}

void Framework::WindowMessageUnitTestSuiteTesting::CreateMessageTest()
{
    auto message = mMessage.lock();

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(message, "消息指针已无效！");

    ASSERT_EQUAL(message->CreateMessage(message->GetHwnd(), 0, 0), 0);
}

void Framework::WindowMessageUnitTestSuiteTesting::DisplayTest()
{
    auto message = mMessage.lock();

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(message, "消息指针已无效！");

    message->Display(message->GetHwnd(), 0);
}
