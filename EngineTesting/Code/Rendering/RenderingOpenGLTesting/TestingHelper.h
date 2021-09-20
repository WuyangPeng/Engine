// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/09 12:51)

#ifndef RENDERING_OPENGL_TESTING_TESTING_HELPER_H
#define RENDERING_OPENGL_TESTING_TESTING_HELPER_H

#include "Framework/MainFunctionHelper/OpenGLGlutMainFunctionHelperDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutFrameBuildDetail.h"
#include "RenderingOpenGLTestingOpenGLGlutCallBack.h"

namespace Rendering
{
	using TestingHelperBase = Framework::OpenGLGlutMainFunctionHelper<Framework::OpenGLGlutFrameBuild,OpenGLGlutProcessSystemOpenGLTesting>;

	class TestingHelper : public TestingHelperBase
	{
	public:
		using ClassType = TestingHelper ;
		using ParentType = TestingHelperBase ;
		using GLUTApplicationInformation = Framework::GLUTApplicationInformation ;

	public:
		TestingHelper(int argc,char* argv[],const GLUTApplicationInformation& information,const Framework::EnvironmentDirectory& environmentDirectory);
		virtual ~TestingHelper();

		CLASS_INVARIANT_OVERRIDE_DECLARE;
	};
}

#endif // RENDERING_OPENGL_TESTING_TESTING_HELPER_H