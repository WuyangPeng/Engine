// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/02 13:25)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_OPENGL_GLUT_MAIN_FUNCTION_HELPER_TESTING_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_OPENGL_GLUT_MAIN_FUNCTION_HELPER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class OpenGLGlutMainFunctionHelperTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = OpenGLGlutMainFunctionHelperTesting;
		using ParentType = UnitTest;

	public:
		explicit OpenGLGlutMainFunctionHelperTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void OpenGLGlutMainFunctionHelper1Test();
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_OPENGL_GLUT_MAIN_FUNCTION_HELPER_TESTING_H