// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 17:51)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_OPENGL_GLUT_MAIN_FUNCTION_HELPER_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_OPENGL_GLUT_MAIN_FUNCTION_HELPER_H

#include "MainFunctionHelperBase.h"

namespace Framework
{
	class GLUTApplicationInformation;

	template <template<typename > class Build,typename Process>
	class OpenGLGlutMainFunctionHelper : public MainFunctionHelperBase
	{
	public:
		using ClassType = OpenGLGlutMainFunctionHelper<Build,Process>;
		using ParentType = MainFunctionHelperBase;
		using BuildType = Build<Process>;

	public:
		OpenGLGlutMainFunctionHelper(int argc,char* argv[],const GLUTApplicationInformation& information,
			                         const EnvironmentDirectory& environmentDirectory);
		virtual ~OpenGLGlutMainFunctionHelper();

		CLASS_INVARIANT_VIRTUAL_DECLARE;
		
		virtual void Destroy();

	private:
		typedef std::shared_ptr<BuildType> BuildTypePtr;

	private:
		virtual int DoRun();
		virtual int RunOpenGLGlutMainLoop();

        void Initializers(int argc,char* argv[], const GLUTApplicationInformation& information);
        void Terminators();	

	private:
		BuildTypePtr m_Build;		
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_OPENGL_GLUT_MAIN_FUNCTION_HELPER_H