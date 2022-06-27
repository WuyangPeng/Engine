///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/24 13:52)

#include "AndroidProcessTesting.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/AndroidFrame/AndroidCallBackInterface.h"
#include "Framework/AndroidFrame/AndroidProcessDetail.h"

Framework::AndroidProcessAndroidCallBackInterface::AndroidProcessAndroidCallBackInterface(int64_t delta) noexcept
    : ParentType{ delta }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, AndroidProcessAndroidCallBackInterface);

namespace Framework
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)

    template <>
    AndroidProcess<Framework::AndroidProcessAndroidCallBackInterface>::AndroidProcess(MAYBE_UNUSED int64_t delta)
    {
        FRAMEWORK_SELF_CLASS_IS_VALID_9;
    }

#include STSTEM_WARNING_POP

    template <>
    AndroidProcess<Framework::AndroidProcessAndroidCallBackInterface>::~AndroidProcess()
    {
        FRAMEWORK_SELF_CLASS_IS_VALID_9;
    }
}

Framework::AndroidProcessTesting::AndroidProcessTesting(const OStreamShared& stream, AndroidApp* androidApp)
    : ParentType{ stream }, androidApp{ androidApp }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, AndroidProcessTesting)

void Framework::AndroidProcessTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::AndroidProcessTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CallbackSucceedTest);
}

void Framework::AndroidProcessTesting::CallbackSucceedTest()
{
    AndroidProcess<AndroidProcessAndroidCallBackInterface> process(System::g_Microseconds / 60);

    AndroidProcessManager::AppCmd appCmd = process.GetAppCmd();

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(appCmd, "appCmd == nullptr");

    if (appCmd != nullptr)
    {
        appCmd(androidApp, 0);
    }

    AndroidProcessManager::InputEvent inputEvent = process.GetInputEvent();

    ASSERT_UNEQUAL_NULL_PTR(inputEvent);

    if (inputEvent != nullptr)
    {
        inputEvent(androidApp, nullptr);
    }

    AndroidProcessManager::Display display = process.GetDisplay();

    ASSERT_UNEQUAL_NULL_PTR(display);

    if (display != nullptr)
    {
        display(androidApp, 0);
    }

    ASSERT_TRUE(process.PreCreate());
    ASSERT_TRUE(process.Initialize());
    process.PreIdle();
    process.Terminate();
}
