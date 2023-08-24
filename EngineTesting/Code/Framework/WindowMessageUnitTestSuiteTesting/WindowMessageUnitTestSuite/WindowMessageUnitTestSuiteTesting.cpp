///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/10 10:51)

#include "WindowMessageUnitTestSuiteTesting.h"
#include "System/Helper/EnumCast.h"
#include "System/Windows/Flags/WindowsKeyCodesFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/WindowMessageUnitTestSuiteTesting/SuiteWindowMessage.h"

Framework::WindowMessageUnitTestSuiteTesting::WindowMessageUnitTestSuiteTesting(const OStreamShared& stream, const WindowMessageSharedPtr& message)
    : ParentType{ stream }, message{ message }
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
    const auto messageSharedPtr = message.lock();

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(messageSharedPtr, "��Ϣָ������Ч��");

    ASSERT_EQUAL(messageSharedPtr->KeyDownMessage(messageSharedPtr->GetHWnd(), System::EnumCastUnderlying<System::WindowsWParam>(System::WindowsKeyCodes::F1), 0), 0);
    ASSERT_EQUAL(messageSharedPtr->GetPassedNumber(), 1);
}

void Framework::WindowMessageUnitTestSuiteTesting::CreateMessageTest()
{
    const auto messageSharedPtr = message.lock();

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(messageSharedPtr, "��Ϣָ������Ч��");

    ASSERT_EQUAL(messageSharedPtr->CreateMessage(messageSharedPtr->GetHWnd(), 0, 0), 0);
}

void Framework::WindowMessageUnitTestSuiteTesting::DisplayTest()
{
    const auto messageSharedPtr = message.lock();

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(messageSharedPtr, "��Ϣָ������Ч��");

    messageSharedPtr->Display(messageSharedPtr->GetHWnd(), 0);
}
