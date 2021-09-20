// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/11 11:10)

#include "OpenGLGlutCallBackInterfaceTesting.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutCallBackInterface.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "System/Helper/Helper.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Framework,OpenGLGlutCallBackInterfaceTesting) 

void Framework::OpenGLGlutCallBackInterfaceTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(InterfaceTest);
}

void Framework::OpenGLGlutCallBackInterfaceTesting
	::InterfaceTest()
{
	OpenGLGlutCallBackInterface openGLGlutCallBackInterface(9);

	openGLGlutCallBackInterface.SetWindowID(10);
	ASSERT_EQUAL(openGLGlutCallBackInterface.GetWindowID(),10);
	
	ASSERT_TRUE(openGLGlutCallBackInterface.RenderScene()); 
	ASSERT_TRUE(openGLGlutCallBackInterface.ChangeSize(0,0));
	ASSERT_TRUE(openGLGlutCallBackInterface.TimerFunction(TimerFunction));
	ASSERT_TRUE(openGLGlutCallBackInterface.MotionFunction(0,0));
	ASSERT_TRUE(openGLGlutCallBackInterface.PassiveMotion(0,0));
	ASSERT_TRUE(openGLGlutCallBackInterface.MouseClick(0,0,0,0));
	ASSERT_TRUE(openGLGlutCallBackInterface.KeyboardDown(0,0,0));
	ASSERT_TRUE(openGLGlutCallBackInterface.KeyboardUp(0,0,0));
	ASSERT_TRUE(openGLGlutCallBackInterface.SpecialKeysDown(0,0,0));
	ASSERT_TRUE(openGLGlutCallBackInterface.SpecialKeysUp(0,0,0));
	ASSERT_TRUE(openGLGlutCallBackInterface.IdleFunction());
	ASSERT_TRUE(openGLGlutCallBackInterface.ProcessMenu(0));
	ASSERT_TRUE(openGLGlutCallBackInterface.PreCreate());
	ASSERT_TRUE(openGLGlutCallBackInterface.Initialize());
	openGLGlutCallBackInterface.PreIdle();
	openGLGlutCallBackInterface.Terminate();
	openGLGlutCallBackInterface.DestroyWindow();
		
	openGLGlutCallBackInterface.SetMillisecond(10u);
	ASSERT_EQUAL(openGLGlutCallBackInterface.GetMillisecond(),10);

	ASSERT_EQUAL(openGLGlutCallBackInterface.GetTerminateKey(),GlutApplicationTrait::KeyIdentifiers::sm_KeyTerminate);				 
}

void Framework::OpenGLGlutCallBackInterfaceTesting ::TimerFunction([[maybe_unused]] int value)
{
}

