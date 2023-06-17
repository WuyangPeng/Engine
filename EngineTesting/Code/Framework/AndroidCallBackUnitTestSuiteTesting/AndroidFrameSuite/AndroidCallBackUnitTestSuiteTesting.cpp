///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 17:50)

#include "AndroidCallBackUnitTestSuiteTesting.h"
#include "System/Android/Flags/AndroidInputFlags.h"
#include "System/Android/Flags/AndroidKeyCodesFlags.h"
#include "System/Android/Using/AndroidInputUsing.h"
#include "System/Windows/Flags/WindowsKeyCodesFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/AndroidCallBackUnitTestSuiteTesting/AndroidCallBackUnitTestSuiteTestingAndroidCallBack.h"
#include "Framework/WindowProcess/WindowMessageUnitTestSuite.h"

AndroidCallBackUnitTestSuiteTesting::AndroidCallBackUnitTestSuiteTesting::AndroidCallBackUnitTestSuiteTesting(const CoreTools::OStreamShared& stream, AndroidCallBackUnitTestSuiteTestingAndroidCallBack* message)
    : ParentType{ stream }, message{ message }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AndroidCallBackUnitTestSuiteTesting, AndroidCallBackUnitTestSuiteTesting)

void AndroidCallBackUnitTestSuiteTesting::AndroidCallBackUnitTestSuiteTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void AndroidCallBackUnitTestSuiteTesting::AndroidCallBackUnitTestSuiteTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(KeyDownMessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateMessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DisplayTest);
}

void AndroidCallBackUnitTestSuiteTesting::AndroidCallBackUnitTestSuiteTesting::KeyDownMessageTest()
{
    System::AndroidInputEvent event;
    event.SetAndroidKeyCodes(System::AndroidKeyCodes::F1);
    ASSERT_EQUAL(message->KeyDownMessage(message->GetAndroidApp(), &event), 0);

    ASSERT_EQUAL(message->GetPassedNumber(), 1);
}

void AndroidCallBackUnitTestSuiteTesting::AndroidCallBackUnitTestSuiteTesting::CreateMessageTest()
{
    ASSERT_TRUE(message->Initialize());
}

void AndroidCallBackUnitTestSuiteTesting::AndroidCallBackUnitTestSuiteTesting::DisplayTest()
{
    message->Display(message->GetAndroidApp(), 0);
}
