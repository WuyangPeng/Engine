// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∏®÷˙∞Ê±æ£∫0.3.0.1 (2020/05/26 15:53)

#ifndef GLUT_MAIN_ENTRY_POINT2_H
#define GLUT_MAIN_ENTRY_POINT2_H

#include "Framework/OpenGLGlutFrame/OpenGLGlutProcess.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutFrameBuild.h"
#include "Framework/MainFunctionHelper/OpenGLGlutMainFunctionHelperDetail.h"

namespace Framework
{
	using BaseType = OpenGLGlutMainFunctionHelper<OpenGLGlutFrameBuild, OpenGLGlutProcessInterface>;

	class GlutMainEntryPoint2 : public BaseType
	{
	public:
		using ClassType = GlutMainEntryPoint2;
		using ParentType = BaseType;

	public:
		GlutMainEntryPoint2(int argc, char** argv, const GLUTApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

		CLASS_INVARIANT_FINAL_DECLARE;
	};
}

#endif // GLUT_MAIN_ENTRY_POINT1_H
