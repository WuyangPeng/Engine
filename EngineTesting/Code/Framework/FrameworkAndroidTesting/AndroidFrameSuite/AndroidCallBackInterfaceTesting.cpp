///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/24 14:01)

#include "AndroidCallBackInterfaceTesting.h"
#include "System/Android/AndroidInputQueue.h"
#include "System/Android/Flags/AndroidInputFlags.h"
#include "System/Android/Flags/AndroidNativeAppGlueFlags.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/AndroidFrame/AndroidCallBackInterface.h"
#include "Framework/Application/Flags/ApplicationTrait.h"

Framework::AndroidCallBackInterfaceTesting::AndroidCallBackInterfaceTesting(const OStreamShared& stream, AndroidApp* androidApp)
    : ParentType{ stream }, androidApp{ androidApp }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, AndroidCallBackInterfaceTesting)

void Framework::AndroidCallBackInterfaceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}
void Framework::AndroidCallBackInterfaceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MessageTest);
}

void Framework::AndroidCallBackInterfaceTesting::MessageTest()
{
    AndroidCallBackInterface androidCallBackInterface(System::g_Microseconds / 60);

    androidCallBackInterface.NotDealCmdMessage(androidApp);
    androidCallBackInterface.InitMessage(androidApp);
    androidCallBackInterface.TermMessage(androidApp);
    androidCallBackInterface.ResizedMessage(androidApp);
    androidCallBackInterface.RedrawNeededMessage(androidApp);
    androidCallBackInterface.RectChanged(androidApp);

    System::AndroidInputEvent* event = nullptr;

    ASSERT_EQUAL(androidCallBackInterface.NotDealInputMessage(androidApp, event), 0);
    ASSERT_EQUAL(androidCallBackInterface.KeyDownMessage(androidApp, event), 0);
    ASSERT_EQUAL(androidCallBackInterface.KeyUpMessage(androidApp, event), 0);
    ASSERT_EQUAL(androidCallBackInterface.ActionDownMessage(androidApp, event), 0);
    ASSERT_EQUAL(androidCallBackInterface.ActionUpMessage(androidApp, event), 0);
    ASSERT_EQUAL(androidCallBackInterface.ActionMoveMessage(androidApp, event), 0);

    androidCallBackInterface.Display(androidApp, 0);
    ASSERT_EQUAL(androidCallBackInterface.GetTerminateKey(), AndroidApplicationTrait::KeyIdentifiers::keyTerminate);

    ASSERT_TRUE(androidCallBackInterface.PreCreate());
    ASSERT_TRUE(androidCallBackInterface.Initialize());
    androidCallBackInterface.PreIdle();
    androidCallBackInterface.Terminate();

    ASSERT_EQUAL(androidCallBackInterface.GetAndroidApp(), androidApp);
}
