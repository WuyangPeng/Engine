// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/11 14:17)

#include "OpenGLGlutProcessTesting.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcessDetail.h"
#include "CoreTools/Helper/AssertMacro.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/OpenGLGlutFrame/Flags/FrameParameter.h"
#include "System/Time/Using/DeltaTimeUsing.h"

Framework::OpenGLGlutProcessOpenGLGlutCallBack
	::OpenGLGlutProcessOpenGLGlutCallBack()
	:ParentType(0)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::OpenGLGlutProcessOpenGLGlutCallBack
	::~OpenGLGlutProcessOpenGLGlutCallBack()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, OpenGLGlutProcessOpenGLGlutCallBack);

namespace Framework
{
    template<>
    OpenGLGlutProcess<Framework::OpenGLGlutProcessOpenGLGlutCallBack>
        ::OpenGLGlutProcess(int64_t delta)
		 
    {	
		delta;
		FRAMEWORK_SELF_CLASS_IS_VALID_9;
    }
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Framework,OpenGLGlutProcessTesting) 

void Framework::OpenGLGlutProcessTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(SetWindowIDSucceedTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CallbackSucceedTest);	
	ASSERT_NOT_THROW_EXCEPTION_0(SetMillisecondSucceedTest);
}

void Framework::OpenGLGlutProcessTesting
	::SetWindowIDSucceedTest()
{
	OpenGLGlutProcess<OpenGLGlutProcessOpenGLGlutCallBack> process{ System::g_Microseconds / 60 };

	int window(process.GetWindowID());

	process.SetWindowID(window);
}

void Framework::OpenGLGlutProcessTesting
	::CallbackSucceedTest()
{
	OpenGLGlutProcess<OpenGLGlutProcessOpenGLGlutCallBack> process{ System::g_Microseconds / 60 };

	ASSERT_TRUE(process.PreCreate());
	ASSERT_TRUE(process.Initialize());
	process.PreIdle();
	process.Terminate();

	OpenGLGlutProcessManager::RenderSceneCallback renderScenePtr =	process.GetRenderSceneCallback();

	ASSERT_UNEQUAL_NULL_PTR(renderScenePtr);

	renderScenePtr();

	OpenGLGlutProcessManager::ChangeSizeCallback changeSizePtr = process.GetChangeSizeCallback();

	ASSERT_UNEQUAL_NULL_PTR(changeSizePtr);

	changeSizePtr(0,0);

	OpenGLGlutProcessManager::TimerFunctionCallback timerFunctionPtr =	process.GetTimerFunctionCallback();

	ASSERT_UNEQUAL_NULL_PTR(timerFunctionPtr);

	timerFunctionPtr(0);

	OpenGLGlutProcessManager::SpecialKeysDownCallback specialKeysPtr =	process.GetSpecialKeysDownCallback();

	ASSERT_UNEQUAL_NULL_PTR(specialKeysPtr);

	specialKeysPtr(0,0,0);

	OpenGLGlutProcessManager::KeyboardDownCallback keyboardPtr = process.GetKeyboardDownCallback();

	ASSERT_UNEQUAL_NULL_PTR(keyboardPtr);

	keyboardPtr(0,0,0);

	OpenGLGlutProcessManager::SpecialKeysUpCallback specialKeysUpPtr =	process.GetSpecialKeysUpCallback();

	ASSERT_UNEQUAL_NULL_PTR(specialKeysUpPtr);

	specialKeysUpPtr(0,0,0);

	OpenGLGlutProcessManager::KeyboardUpCallback keyboardUpPtr = process.GetKeyboardUpCallback();

	ASSERT_UNEQUAL_NULL_PTR(keyboardUpPtr);

	keyboardUpPtr(0,0,0);

	OpenGLGlutProcessManager::MouseFunctionCallback mouseFunctionPtr =	process.GetMouseFunctionCallback();

	ASSERT_UNEQUAL_NULL_PTR(mouseFunctionPtr);

	mouseFunctionPtr(0,0,0,0);

	OpenGLGlutProcessManager::MotionFunctionCallback motionFunctionPtr = process.GetMotionFunctionCallback();

	ASSERT_UNEQUAL_NULL_PTR(motionFunctionPtr);

	motionFunctionPtr(0,0);

	OpenGLGlutProcessManager::PassiveMotionFunctionCallback passiveFunctionPtr = process.GetPassiveMotionCallback();

	ASSERT_UNEQUAL_NULL_PTR(passiveFunctionPtr);

	passiveFunctionPtr(0,0);

	OpenGLGlutProcessManager::IdleFunctionCallback idleFunction = process.GetIdleFunctionCallback();

	ASSERT_UNEQUAL_NULL_PTR(idleFunction);	

	idleFunction();

	OpenGLGlutProcessManager::ProcessMenuCallback processMenuFunction =	process.GetProcessMenuCallback();

	ASSERT_UNEQUAL_NULL_PTR(processMenuFunction);		

	processMenuFunction(0);

	OpenGLGlutProcessManager::TerminateCallback terminateFunction =	process.GetTerminateCallback();

	ASSERT_UNEQUAL_NULL_PTR(terminateFunction);		
}

void Framework::OpenGLGlutProcessTesting
	::SetMillisecondSucceedTest()
{
	OpenGLGlutProcess<OpenGLGlutProcessOpenGLGlutCallBack> process{ System::g_Microseconds / 60 };;

	auto millisecond = 17;

	process.SetMillisecond(millisecond);
	
	ASSERT_EQUAL(process.GetMillisecond(),millisecond);
}

