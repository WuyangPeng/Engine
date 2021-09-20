// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/11 10:02)

#ifndef FRAMEWORK_TESTING_TESTING_HELPER_H
#define FRAMEWORK_TESTING_TESTING_HELPER_H

#include "Framework/MainFunctionHelper/OpenGLGlutMainFunctionHelperDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutFrameBuildDetail.h"
#include "FrameworkTestingOpenGLGlutCallBack.h"

namespace Framework
{
	class TestingHelper : public OpenGLGlutMainFunctionHelper<OpenGLGlutFrameBuild,OpenGLGlutProcessFrameworkTesting>
	{
	public:
		using ClassType = TestingHelper;
		using ParentType = OpenGLGlutMainFunctionHelper<Framework::OpenGLGlutFrameBuild, OpenGLGlutProcessFrameworkTesting>;
		using GLUTApplicationInformation = Framework::GLUTApplicationInformation;

	public:
		TestingHelper(int argc,char* argv[],const GLUTApplicationInformation& information,const Framework::EnvironmentDirectory& environmentDirectory);
		virtual ~TestingHelper();

		CLASS_INVARIANT_OVERRIDE_DECLARE;
	};
}

#endif // FRAMEWORK_TESTING_TESTING_HELPER_H
