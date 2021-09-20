// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 20:32)

#include "AndroidProcessManagerTesting.h"
#include "Framework/AndroidFrame/AndroidProcessManager.h"
#include "Framework/AndroidFrame/AndroidCallBackInterface.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::ostream;

Framework::AndroidProcessManagerTesting
	::AndroidProcessManagerTesting(AndroidApp* androidApp, const OStreamShared& osPtr)
	:ParentType{ osPtr }, m_AndroidApp{ androidApp }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::AndroidProcessManagerTesting
	::~AndroidProcessManagerTesting()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework,AndroidProcessManagerTesting)

 void Framework::AndroidProcessManagerTesting ::DoRunUnitTest()
{
     ASSERT_NOT_THROW_EXCEPTION_0(MainTest); 
}

void Framework::AndroidProcessManagerTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(AndroidCallBackPtrTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CallbackSucceedTest);
}

void Framework::AndroidProcessManagerTesting
	::AndroidCallBackPtrTest()
{
	AndroidProcessManager::AndroidCallBackInterfaceSharedPtr	ptr(ANDROID_PROCESS_MANAGE_SINGLETON.GetAndroidCallBackInterface());

	ASSERT_UNEQUAL_NULL_PTR(ptr);
	ANDROID_PROCESS_MANAGE_SINGLETON.ClearAndroidCallBack();

	ANDROID_PROCESS_MANAGE_SINGLETON.SetAndroidCallBack(ptr);

	ASSERT_EQUAL(ANDROID_PROCESS_MANAGE_SINGLETON.GetAndroidCallBackInterface(), ptr);
}

void Framework::AndroidProcessManagerTesting
	::CallbackSucceedTest()
{
	AndroidProcessManager::AppCmd appCmd = ANDROID_PROCESS_MANAGE_SINGLETON.GetAppCmd();

	ASSERT_UNEQUAL_NULL_PTR(appCmd);

	appCmd(m_AndroidApp,0);

	AndroidProcessManager::InputEvent inputEvent = ANDROID_PROCESS_MANAGE_SINGLETON.GetInputEvent();

	ASSERT_UNEQUAL_NULL_PTR(inputEvent);

	inputEvent(m_AndroidApp,nullptr);

	AndroidProcessManager::Display display = ANDROID_PROCESS_MANAGE_SINGLETON.GetDisplay();

	ASSERT_UNEQUAL_NULL_PTR(display);

	display(m_AndroidApp,0);

	ASSERT_TRUE(ANDROID_PROCESS_MANAGE_SINGLETON.PreCreate());
	ASSERT_TRUE(ANDROID_PROCESS_MANAGE_SINGLETON.Initialize());
	ANDROID_PROCESS_MANAGE_SINGLETON.PreIdle();
	ANDROID_PROCESS_MANAGE_SINGLETON.Terminate();
}



