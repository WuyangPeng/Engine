// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 20:29)

#include "AndroidCallBackTesting.h"
#include "System/Android/AndroidInputKeyEvent.h"
#include "System/Android/AndroidInputQueue.h"
#include "Framework/AndroidFrame/AndroidCallBackDetail.h"
#include "Framework/MiddleLayer/MiddleLayerInterface.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "System/Time/Using/DeltaTimeUsing.h"

using std::ostream;

Framework::AndroidCallBackTesting
	::AndroidCallBackTesting(AndroidApp* androidApp, const OStreamShared& osPtr)
	:ParentType{ osPtr }, m_AndroidApp{ androidApp }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::AndroidCallBackTesting
	::~AndroidCallBackTesting()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework,AndroidCallBackTesting)

void Framework::AndroidCallBackTesting ::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}
 

void Framework::AndroidCallBackTesting
	::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MessageTest);
}

void Framework::AndroidCallBackTesting
	::MessageTest()
{
	AndroidCallBack<MiddleLayerInterface> androidCallBackInterface(System::g_Microseconds / 60);

	androidCallBackInterface.NotDealCmdMessage(m_AndroidApp);
	androidCallBackInterface.InitMessage(m_AndroidApp);
	androidCallBackInterface.TermMessage(nullptr);
	androidCallBackInterface.ResizedMessage(m_AndroidApp);
	androidCallBackInterface.RedrawNeededMessage(m_AndroidApp);
	androidCallBackInterface.RectChanged(m_AndroidApp);

	System::AndroidInputEvent* event = nullptr;
 
	//System::AndroidInputQueueGetEvent(m_AndroidApp->inputQueue, &event);

	ASSERT_EQUAL(androidCallBackInterface.NotDealInputMessage(m_AndroidApp,event),0);
	ASSERT_EQUAL(androidCallBackInterface.KeyDownMessage(m_AndroidApp,event),0);
	ASSERT_EQUAL(androidCallBackInterface.KeyUpMessage(m_AndroidApp,event),0);
	ASSERT_EQUAL(androidCallBackInterface.ActionDownMessage(m_AndroidApp,event),0);
	ASSERT_EQUAL(androidCallBackInterface.ActionUpMessage(m_AndroidApp,event),0);
	ASSERT_EQUAL(androidCallBackInterface.ActionMoveMessage(m_AndroidApp,event), 0);

	androidCallBackInterface.Display(m_AndroidApp,0);
	ASSERT_EQUAL(androidCallBackInterface.GetTerminateKey(),AndroidApplicationTrait::KeyIdentifiers::sm_KeyTerminate);

	ASSERT_TRUE(androidCallBackInterface.PreCreate());
	ASSERT_TRUE(androidCallBackInterface.Initialize());
	androidCallBackInterface.PreIdle();
	androidCallBackInterface.Terminate();
}

