// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/12 19:03)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_PROCESS_MANAGE_TESTING_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_PROCESS_MANAGE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class OpenGLGlutProcessManagerTesting : public CoreTools::UnitTest
	{
	public:
		using ClassType = OpenGLGlutProcessManagerTesting;
		using ParentType = UnitTest;

	public:
		explicit OpenGLGlutProcessManagerTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;
		void MainTest();
		 
	};
}

#endif // FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_PROCESS_MANAGE_TESTING_H