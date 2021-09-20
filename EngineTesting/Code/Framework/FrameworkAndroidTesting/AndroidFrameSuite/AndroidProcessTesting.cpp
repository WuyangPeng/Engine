// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 20:32)

#include "AndroidProcessTesting.h"
#include "Framework/AndroidFrame/AndroidProcessDetail.h"
#include "Framework/AndroidFrame/AndroidCallBackInterface.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "System/Time/Using/DeltaTimeUsing.h"

using std::ostream;

Framework::AndroidProcessAndroidCallBackInterface
	::AndroidProcessAndroidCallBackInterface(int64_t delta)
	:ParentType{ delta }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::AndroidProcessAndroidCallBackInterface
	::~AndroidProcessAndroidCallBackInterface()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, AndroidProcessAndroidCallBackInterface);

namespace Framework
{
	template<>
	AndroidProcess<Framework::AndroidProcessAndroidCallBackInterface>
		::AndroidProcess(int64_t delta)
	 
	{
		delta;
		FRAMEWORK_SELF_CLASS_IS_VALID_9;
	}

	template<>
	AndroidProcess<Framework::AndroidProcessAndroidCallBackInterface>
		::~AndroidProcess()
	{
		FRAMEWORK_SELF_CLASS_IS_VALID_9;
	}
}

Framework::AndroidProcessTesting
	::AndroidProcessTesting(AndroidApp* androidApp, const OStreamShared& osPtr)
	:ParentType{ osPtr }, m_AndroidApp{ androidApp }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::AndroidProcessTesting
	::~AndroidProcessTesting()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework,AndroidProcessTesting)

 void Framework::AndroidProcessTesting ::DoRunUnitTest()
{
     ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
 }

void Framework::AndroidProcessTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(CallbackSucceedTest);
}

void Framework::AndroidProcessTesting
	::CallbackSucceedTest()
{
	AndroidProcess<AndroidProcessAndroidCallBackInterface> process(System::g_Microseconds / 60);

	AndroidProcessManager::AppCmd appCmd =	process.GetAppCmd();

	ASSERT_UNEQUAL_NULL_PTR(appCmd);

	appCmd(m_AndroidApp,0);

	AndroidProcessManager::InputEvent inputEvent =	process.GetInputEvent();

	ASSERT_UNEQUAL_NULL_PTR(inputEvent);

	inputEvent(m_AndroidApp,nullptr);

	AndroidProcessManager::Display display = process.GetDisplay();

	ASSERT_UNEQUAL_NULL_PTR(display);

	display(m_AndroidApp,0);

	ASSERT_TRUE(process.PreCreate());
	ASSERT_TRUE(process.Initialize());
	process.PreIdle();
	process.Terminate();
}

