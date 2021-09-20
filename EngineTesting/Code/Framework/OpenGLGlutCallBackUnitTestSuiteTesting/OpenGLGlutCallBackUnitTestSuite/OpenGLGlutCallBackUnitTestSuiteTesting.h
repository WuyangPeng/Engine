// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/17 09:38)

#ifndef OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_TESTING_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_TESTING_H
#define OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_TESTING_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "System/Window/Flags/WindowFlags.h"
#include "System/Window/Using/WindowUsing.h"

namespace OpenGLGlutCallBackUnitTestSuiteTesting
{
	class OpenGLGlutCallBackUnitTestSuiteTestingOpenGLGlutCallBack;

	class OpenGLGlutCallBackUnitTestSuiteTesting : public CoreTools::UnitTest
	{
	public:
		using ClassType = OpenGLGlutCallBackUnitTestSuiteTesting;
		using ParentType = UnitTest;
		using HWnd = System::WindowHWnd;

	public:
		explicit OpenGLGlutCallBackUnitTestSuiteTesting(OpenGLGlutCallBackUnitTestSuiteTestingOpenGLGlutCallBack* message,const OStreamShared& osPtr);
		virtual ~OpenGLGlutCallBackUnitTestSuiteTesting();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	private:
		void MainTest();
		void KeyDownMessageTest();
		void CreateMessageTest();		
		void DisplayTest();

		void DoRunUnitTest() final;

	private:
		OpenGLGlutCallBackUnitTestSuiteTestingOpenGLGlutCallBack* m_Message;
	};
}

#endif // OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_TESTING_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_TESTING_H
