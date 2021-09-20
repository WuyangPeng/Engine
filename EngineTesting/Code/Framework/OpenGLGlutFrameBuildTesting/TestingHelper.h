// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/17 09:54)

#ifndef OPENGL_GLUT_FRAME_BUILD_TESTING_TESTING_HELPER_H
#define OPENGL_GLUT_FRAME_BUILD_TESTING_TESTING_HELPER_H

#include "Framework/MainFunctionHelper/OpenGLGlutMainFunctionHelperDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutFrameBuildDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcess.h"

namespace OpenGLGlutFrameBuildTesting
{
	class TestingHelper : public Framework::OpenGLGlutMainFunctionHelper<Framework::OpenGLGlutFrameBuild, Framework::OpenGLGlutProcessInterface>
	{
	public:
		using ClassType = TestingHelper;
		using ParentType = OpenGLGlutMainFunctionHelper<Framework::OpenGLGlutFrameBuild,Framework::OpenGLGlutProcessInterface>;
		using GLUTApplicationInformation = Framework::GLUTApplicationInformation;

	public:
		TestingHelper(int argc,char* argv[],const GLUTApplicationInformation& information,const Framework::EnvironmentDirectory& environmentDirectory);
		virtual ~TestingHelper();

		CLASS_INVARIANT_OVERRIDE_DECLARE;	
	};
}

#endif // OPENGL_GLUT_FRAME_BUILD_TESTING_TESTING_HELPER_H