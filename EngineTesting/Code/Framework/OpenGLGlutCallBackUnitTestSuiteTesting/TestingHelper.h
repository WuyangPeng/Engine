// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/17 09:36)

#ifndef OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_TESTING_TESTING_HELPER_H
#define OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_TESTING_TESTING_HELPER_H

#include "Framework/MainFunctionHelper/OpenGLGlutMainFunctionHelperDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutFrameBuildDetail.h"
#include "OpenGLGlutCallBackUnitTestSuiteTestingOpenGLGlutCallBack.h"

namespace OpenGLGlutCallBackUnitTestSuiteTesting
{
	class TestingHelper : public Framework::OpenGLGlutMainFunctionHelper<Framework::OpenGLGlutFrameBuild,OpenGLGlutProcessOpenGLGlutCallBackUnitTestSuiteTesting>
	{
	public:
		using ClassType = TestingHelper;
		using ParentType = OpenGLGlutMainFunctionHelper<Framework::OpenGLGlutFrameBuild,OpenGLGlutProcessOpenGLGlutCallBackUnitTestSuiteTesting>;
		using GLUTApplicationInformation = Framework::GLUTApplicationInformation;

	public:
		TestingHelper(int argc,char* argv[],const GLUTApplicationInformation& information,const Framework::EnvironmentDirectory& environmentDirectory);
		virtual ~TestingHelper();

		CLASS_INVARIANT_OVERRIDE_DECLARE;
	};
}

#endif // OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_TESTING_TESTING_HELPER_H
