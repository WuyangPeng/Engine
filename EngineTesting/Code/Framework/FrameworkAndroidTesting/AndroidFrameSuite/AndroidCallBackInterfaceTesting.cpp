// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ²âÊÔ°æ±¾£º0.0.0.4 (2019/09/10 20:28)

#include "AndroidCallBackInterfaceTesting.h"
#include "System/Android/AndroidInputQueue.h"
#include "System/Android/Flags/AndroidInputFlags.h"
#include "System/Android/Flags/AndroidNativeAppGlueFlags.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/AndroidFrame/AndroidCallBackInterface.h"
#include "Framework/Application/Flags/ApplicationTrait.h"

using std::ostream;

Framework::AndroidCallBackInterfaceTesting::AndroidCallBackInterfaceTesting(AndroidApp* androidApp, const OStreamShared& osPtr)
    : ParentType{ osPtr }, m_AndroidApp{ androidApp }
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
    ;

    androidCallBackInterface.NotDealCmdMessage(m_AndroidApp);
    androidCallBackInterface.InitMessage(m_AndroidApp);
    androidCallBackInterface.TermMessage(m_AndroidApp);
    androidCallBackInterface.ResizedMessage(m_AndroidApp);
    androidCallBackInterface.RedrawNeededMessage(m_AndroidApp);
    androidCallBackInterface.RectChanged(m_AndroidApp);

    System::AndroidInputEvent* event = nullptr;

    //	System::AndroidInputQueueGetEvent(m_AndroidApp->inputQueue, &event);

    ASSERT_EQUAL(androidCallBackInterface.NotDealInputMessage(m_AndroidApp, event), 0);
    ASSERT_EQUAL(androidCallBackInterface.KeyDownMessage(m_AndroidApp, event), 0);
    ASSERT_EQUAL(androidCallBackInterface.KeyUpMessage(m_AndroidApp, event), 0);
    ASSERT_EQUAL(androidCallBackInterface.ActionDownMessage(m_AndroidApp, event), 0);
    ASSERT_EQUAL(androidCallBackInterface.ActionUpMessage(m_AndroidApp, event), 0);
    ASSERT_EQUAL(androidCallBackInterface.ActionMoveMessage(m_AndroidApp, event), 0);

    androidCallBackInterface.Display(m_AndroidApp, 0);
    ASSERT_EQUAL(androidCallBackInterface.GetTerminateKey(), AndroidApplicationTrait::KeyIdentifiers::keyTerminate);

    ASSERT_TRUE(androidCallBackInterface.PreCreate());
    ASSERT_TRUE(androidCallBackInterface.Initialize());
    androidCallBackInterface.PreIdle();
    androidCallBackInterface.Terminate();

    ASSERT_EQUAL(androidCallBackInterface.GetAndroidApp(), m_AndroidApp);
}
