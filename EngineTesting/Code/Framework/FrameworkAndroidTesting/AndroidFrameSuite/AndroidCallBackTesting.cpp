///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/24 14:00)

#include "AndroidCallBackTesting.h"
#include "System/Android/AndroidInputKeyEvent.h"
#include "System/Android/AndroidInputQueue.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/AndroidFrame/AndroidCallBackDetail.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/MiddleLayerInterface.h"

Framework::AndroidCallBackTesting::AndroidCallBackTesting(const OStreamShared& stream, AndroidApp* androidApp)
    : ParentType{ stream }, androidApp{ androidApp }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, AndroidCallBackTesting)

void Framework::AndroidCallBackTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::AndroidCallBackTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MessageTest);
}

void Framework::AndroidCallBackTesting::MessageTest()
{
    AndroidCallBack<MiddleLayerInterface> androidCallBackInterface(System::g_Microseconds / 60);

    androidCallBackInterface.NotDealCmdMessage(androidApp);
    androidCallBackInterface.InitMessage(androidApp);
    androidCallBackInterface.TermMessage(nullptr);
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
}
