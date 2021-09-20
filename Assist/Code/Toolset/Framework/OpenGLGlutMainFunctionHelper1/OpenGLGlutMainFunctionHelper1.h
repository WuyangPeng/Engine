// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∏®÷˙∞Ê±æ£∫0.3.0.2 (2020/06/02 10:18)

#ifndef OPENGL_GLUT_MAIN_FUNCTION_HELPER1_H
#define OPENGL_GLUT_MAIN_FUNCTION_HELPER1_H

#include "Framework/OpenGLGlutFrame/OpenGLGlutProcess.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutFrameBuild.h"
#include "Framework/MainFunctionHelper/OpenGLGlutMainFunctionHelperDetail.h"

namespace Framework
{
	using BaseType = OpenGLGlutMainFunctionHelper<OpenGLGlutFrameBuild,OpenGLGlutProcessInterface>;

	class OpenGLGlutMainFunctionHelper1 final : public BaseType
	{
	public:
		using ClassType = OpenGLGlutMainFunctionHelper1;
		using ParentType = BaseType; 

	public:
		OpenGLGlutMainFunctionHelper1(int argc,char** argv,const GLUTApplicationInformation& information,const EnvironmentDirectory& environmentDirectory); 
		
		CLASS_INVARIANT_FINAL_DECLARE;	
	};
}

#endif // OPENGL_GLUT_MAIN_FUNCTION_HELPER1_H