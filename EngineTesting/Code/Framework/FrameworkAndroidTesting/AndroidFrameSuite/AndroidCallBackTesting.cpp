///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/11 14:26)

#include "AndroidCallBackTesting.h"
#include "System/Android/AndroidInputQueueFacade.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
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
    AndroidCallBack<MiddleLayerInterface> androidCallBackInterface{ System::gMicroseconds / 60 };

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
