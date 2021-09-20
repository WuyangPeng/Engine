// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/11 11:09)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_PROCESS_MANAGE_TESTING_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_PROCESS_MANAGE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class OpenGLGlutProcessManagerTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(OpenGLGlutProcessManagerTesting); 

	private:
		void MainTest();
		void OpenGLGlutCallBackPtrTest();
		void MainFunctionHelperPtrTest();
		void SetWindowIDSucceedTest();
		void SetMillisecondSucceedTest();

		void RenderSceneCallbackSucceedTest();
		void ChangeSizeCallbackSucceedTest();
		void TimerFunctionCallbackSucceedTest();
		void SpecialKeysDownCallbackSucceedTest(); 
		void KeyboardDownCallbackSucceedTest();
		void SpecialKeysUpCallbackSucceedTest(); 
		void KeyboardUpCallbackSucceedTest();
		void MouseFunctionCallbackSucceedTest();
		void MotionFunctionCallbackSucceedTest();			
		void IdleFunctionCallbackSucceedTest();
		void ProcessMenuCallbackSucceedTest();
		void TerminateCallbackSucceedTest();
		void PreCreateSucceedTest();
		void InitializeSucceedTest();
		void PreIdleSucceedTest();
		void TerminateSucceedTest();

		void DoRunUnitTest() final;	
	};
}

#endif // FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_PROCESS_MANAGE_TESTING_H