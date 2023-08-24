///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/11 14:27)

#include "AndroidProcessManagerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/AndroidFrame/AndroidCallBackInterface.h"
#include "Framework/AndroidFrame/AndroidProcessManager.h"

Framework::AndroidProcessManagerTesting::AndroidProcessManagerTesting(const OStreamShared& stream, AndroidApp* androidApp)
    : ParentType{ stream }, androidApp{ androidApp }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, AndroidProcessManagerTesting)

void Framework::AndroidProcessManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::AndroidProcessManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AndroidCallBackPtrTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CallbackSucceedTest);
}

void Framework::AndroidProcessManagerTesting::AndroidCallBackPtrTest()
{
    const auto androidCallBackInterfaceSharedPtr = ANDROID_PROCESS_MANAGE_SINGLETON.GetAndroidCallBackInterface();

    ASSERT_UNEQUAL_NULL_PTR(androidCallBackInterfaceSharedPtr);
    ANDROID_PROCESS_MANAGE_SINGLETON.ClearAndroidCallBack();

    ANDROID_PROCESS_MANAGE_SINGLETON.SetAndroidCallBack(androidCallBackInterfaceSharedPtr);

    ASSERT_EQUAL(ANDROID_PROCESS_MANAGE_SINGLETON.GetAndroidCallBackInterface(), androidCallBackInterfaceSharedPtr);
}

void Framework::AndroidProcessManagerTesting::CallbackSucceedTest()
{
    const auto appCmd = ANDROID_PROCESS_MANAGE_SINGLETON.GetAppCmd();

    ASSERT_UNEQUAL_NULL_PTR(appCmd);

    if (appCmd != nullptr)
    {
        appCmd(androidApp, 0);
    }

    const auto inputEvent = ANDROID_PROCESS_MANAGE_SINGLETON.GetInputEvent();

    ASSERT_UNEQUAL_NULL_PTR(inputEvent);

    if (inputEvent != nullptr)
    {
        inputEvent(androidApp, nullptr);
    }

    const auto display = ANDROID_PROCESS_MANAGE_SINGLETON.GetDisplay();

    ASSERT_UNEQUAL_NULL_PTR(display);

    if (display != nullptr)
    {
        display(androidApp, 0);
    }

    ASSERT_TRUE(ANDROID_PROCESS_MANAGE_SINGLETON.PreCreate());
    ASSERT_TRUE(ANDROID_PROCESS_MANAGE_SINGLETON.Initialize());
    ANDROID_PROCESS_MANAGE_SINGLETON.PreIdle();
    ANDROID_PROCESS_MANAGE_SINGLETON.Terminate();
}
