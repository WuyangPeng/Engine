// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/11 11:09)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_PROCESS_TESTING_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_PROCESS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutCallBackInterface.h"

namespace Framework
{
	class OpenGLGlutProcessOpenGLGlutCallBack : public OpenGLGlutCallBackInterface
	{
	public:
		using ClassType = OpenGLGlutProcessOpenGLGlutCallBack;
		using ParentType = OpenGLGlutCallBackInterface;

	public:
		OpenGLGlutProcessOpenGLGlutCallBack();
		virtual ~OpenGLGlutProcessOpenGLGlutCallBack();

		CLASS_INVARIANT_OVERRIDE_DECLARE;
	};

	class OpenGLGlutProcessTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(OpenGLGlutProcessTesting); 

	private:
		void MainTest();	
		void SetWindowIDSucceedTest();
		void CallbackSucceedTest();	
		void SetMillisecondSucceedTest();	

		void DoRunUnitTest() final;	
	};
}

#endif // FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_PROCESS_TESTING_H