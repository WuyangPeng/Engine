///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/11 14:27)

#include "AndroidProcessAndroidCallBackInterface.h"
#include "AndroidProcessTesting.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/AndroidFrame/AndroidProcessDetail.h"

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
    AndroidProcess<AndroidProcessAndroidCallBackInterface> process(System::gMicroseconds / 60);

    const auto appCmd = process.GetAppCmd();

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(appCmd, "appCmd == nullptr");

    if (appCmd != nullptr)
    {
        appCmd(androidApp, 0);
    }

    const auto inputEvent = process.GetInputEvent();

    ASSERT_UNEQUAL_NULL_PTR(inputEvent);

    if (inputEvent != nullptr)
    {
        inputEvent(androidApp, nullptr);
    }

    const auto display = process.GetDisplay();

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