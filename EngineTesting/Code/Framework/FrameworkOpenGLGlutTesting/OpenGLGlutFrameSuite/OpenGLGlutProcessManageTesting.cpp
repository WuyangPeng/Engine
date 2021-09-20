// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/11 14:16)

#include "OpenGLGlutProcessManageTesting.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcessManager.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutCallBackInterface.h"
#include "CoreTools/Helper/AssertMacro.h" 
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Framework,OpenGLGlutProcessManagerTesting) 

void Framework::OpenGLGlutProcessManagerTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(OpenGLGlutCallBackPtrTest);
	ASSERT_NOT_THROW_EXCEPTION_0(MainFunctionHelperPtrTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SetWindowIDSucceedTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SetMillisecondSucceedTest);
	 
	ASSERT_NOT_THROW_EXCEPTION_0(RenderSceneCallbackSucceedTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ChangeSizeCallbackSucceedTest);
	ASSERT_NOT_THROW_EXCEPTION_0(TimerFunctionCallbackSucceedTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SpecialKeysDownCallbackSucceedTest); 
	ASSERT_NOT_THROW_EXCEPTION_0(KeyboardDownCallbackSucceedTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SpecialKeysUpCallbackSucceedTest); 
	ASSERT_NOT_THROW_EXCEPTION_0(KeyboardUpCallbackSucceedTest);
	ASSERT_NOT_THROW_EXCEPTION_0(MouseFunctionCallbackSucceedTest);
	ASSERT_NOT_THROW_EXCEPTION_0(MotionFunctionCallbackSucceedTest);		
	ASSERT_NOT_THROW_EXCEPTION_0(IdleFunctionCallbackSucceedTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ProcessMenuCallbackSucceedTest);
	ASSERT_NOT_THROW_EXCEPTION_0(TerminateCallbackSucceedTest);
	ASSERT_NOT_THROW_EXCEPTION_0(PreCreateSucceedTest);
	ASSERT_NOT_THROW_EXCEPTION_0(InitializeSucceedTest);
	ASSERT_NOT_THROW_EXCEPTION_0(PreIdleSucceedTest);
	ASSERT_NOT_THROW_EXCEPTION_0(TerminateSucceedTest);
}

void Framework::OpenGLGlutProcessManagerTesting
	::OpenGLGlutCallBackPtrTest()
{
	OpenGLGlutProcessManager::OpenGLGlutCallBackInterfaceSharedPtr ptr = OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetOpenGLGlutCallBackInterface();

	ASSERT_UNEQUAL_NULL_PTR(ptr);

	OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.ClearOpenGLGlutCallBack();

	OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.SetOpenGLGlutCallBack(ptr);

	ASSERT_EQUAL(OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetOpenGLGlutCallBackInterface(),ptr);
}

void Framework::OpenGLGlutProcessManagerTesting
	::MainFunctionHelperPtrTest()
{
	auto ptr = OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetMainFunctionHelper();
	OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.ClearMainFunctionHelper();
	OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.SetMainFunctionHelper(ptr);
}

void Framework::OpenGLGlutProcessManagerTesting
	::SetWindowIDSucceedTest()
{
	int window(OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetWindowID());

	OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.SetWindowID(window);
}

void Framework::OpenGLGlutProcessManagerTesting
	::SetMillisecondSucceedTest()
{
	auto millisecond = 17;

	OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.SetMillisecond(millisecond);
	ASSERT_EQUAL(OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetMillisecond(),millisecond);
}

void Framework::OpenGLGlutProcessManagerTesting
	::RenderSceneCallbackSucceedTest()
{
	OpenGLGlutProcessManager::RenderSceneCallback renderScenePtr =	OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetRenderSceneCallback();

	ASSERT_UNEQUAL_NULL_PTR(renderScenePtr);

	renderScenePtr();
}

void Framework::OpenGLGlutProcessManagerTesting
	::ChangeSizeCallbackSucceedTest()
{
	OpenGLGlutProcessManager::ChangeSizeCallback changeSizePtr = OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetChangeSizeCallback();

	ASSERT_UNEQUAL_NULL_PTR(changeSizePtr);

	changeSizePtr(0,0);
}


void Framework::OpenGLGlutProcessManagerTesting
	::TimerFunctionCallbackSucceedTest()
{
	OpenGLGlutProcessManager::TimerFunctionCallback timerFunctionPtr =	OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetTimerFunctionCallback();

	ASSERT_UNEQUAL_NULL_PTR(timerFunctionPtr);

	timerFunctionPtr(0);
}

void Framework::OpenGLGlutProcessManagerTesting
	::SpecialKeysDownCallbackSucceedTest()
{
	OpenGLGlutProcessManager::SpecialKeysDownCallback specialKeysPtr =	OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetSpecialKeysDownCallback();

	ASSERT_UNEQUAL_NULL_PTR(specialKeysPtr);

	specialKeysPtr(0,0,0);
}

void Framework::OpenGLGlutProcessManagerTesting
	::KeyboardDownCallbackSucceedTest()
{
	OpenGLGlutProcessManager::KeyboardDownCallback keyboardPtr = OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetKeyboardDownCallback();

	ASSERT_UNEQUAL_NULL_PTR(keyboardPtr);

	keyboardPtr(0,0,0);
}

void Framework::OpenGLGlutProcessManagerTesting
	::SpecialKeysUpCallbackSucceedTest()
{
	OpenGLGlutProcessManager::SpecialKeysUpCallback specialKeysPtr = OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetSpecialKeysUpCallback();

	ASSERT_UNEQUAL_NULL_PTR(specialKeysPtr);

	specialKeysPtr(0,0,0);
}

void Framework::OpenGLGlutProcessManagerTesting
	::KeyboardUpCallbackSucceedTest()
{
	OpenGLGlutProcessManager::KeyboardUpCallback keyboardPtr = OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetKeyboardUpCallback();

	ASSERT_UNEQUAL_NULL_PTR(keyboardPtr);

	keyboardPtr(0,0,0);
}

void Framework::OpenGLGlutProcessManagerTesting
	::MouseFunctionCallbackSucceedTest()
{
	OpenGLGlutProcessManager::MouseFunctionCallback mouseFunctionPtr =	OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetMouseFunctionCallback();

	ASSERT_UNEQUAL_NULL_PTR(mouseFunctionPtr);

	mouseFunctionPtr(0,0,0,0);
}

void Framework::OpenGLGlutProcessManagerTesting
	::MotionFunctionCallbackSucceedTest()
{
	OpenGLGlutProcessManager::MotionFunctionCallback motionFunctionPtr = OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetMotionFunctionCallback();

	ASSERT_UNEQUAL_NULL_PTR(motionFunctionPtr);

	motionFunctionPtr(0,0);
}
 
void Framework::OpenGLGlutProcessManagerTesting
	::IdleFunctionCallbackSucceedTest()
{
	OpenGLGlutProcessManager::IdleFunctionCallback idleFunction = OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetIdleFunctionCallback();

	ASSERT_UNEQUAL_NULL_PTR(idleFunction);	

	idleFunction();
}

void Framework::OpenGLGlutProcessManagerTesting
	::ProcessMenuCallbackSucceedTest()
{
	OpenGLGlutProcessManager::ProcessMenuCallback processMenuFunction =	OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetProcessMenuCallback();

	ASSERT_UNEQUAL_NULL_PTR(processMenuFunction);		

	processMenuFunction(0);
}

void Framework::OpenGLGlutProcessManagerTesting
	::TerminateCallbackSucceedTest()
{
	OpenGLGlutProcessManager::TerminateCallback terminateFunction =	OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetTerminateCallback();

	ASSERT_UNEQUAL_NULL_PTR(terminateFunction);	
}

void Framework::OpenGLGlutProcessManagerTesting
	::PreCreateSucceedTest()
{
	OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.PreCreate();
}

void Framework::OpenGLGlutProcessManagerTesting
	::InitializeSucceedTest()
{
	OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.Initialize();
}

void Framework::OpenGLGlutProcessManagerTesting
	::PreIdleSucceedTest()
{
	OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.PreIdle();
}

void Framework::OpenGLGlutProcessManagerTesting
	::TerminateSucceedTest()
{
	OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.Terminate();
}





