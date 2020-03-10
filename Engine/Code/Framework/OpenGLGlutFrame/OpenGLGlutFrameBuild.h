// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 13:18)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_FRAME_BUILD_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_FRAME_BUILD_H

#include "Framework/Application/GLUTApplicationInformation.h"
#include "Rendering/Renderers/RendererParameter.h"

namespace Framework
{
	template <typename OpenGLGlutProcess>
	class OpenGLGlutFrameBuild
	{
	public:
		typedef OpenGLGlutProcess ProcessType;
		typedef OpenGLGlutFrameBuild<ProcessType> ClassType;
		typedef Rendering::RendererParameter  RendererParameter;

	public:
		explicit OpenGLGlutFrameBuild(const GLUTApplicationInformation& glutInformation);
		virtual ~OpenGLGlutFrameBuild();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual bool InitOpenGLGlutContext(int argc,char* argv[]);
		virtual void RunOpenGLGlutMainLoop();

	private:
		virtual bool PreCreate();
		virtual bool InitGlutFunctionLibrary(int argc,char* argv[]);
		virtual bool CreateGlutWindow();
		virtual bool SetCallBackFunction();
		virtual bool SetupRenderStatus();
		virtual bool OpenGLInit();
		virtual bool CreateMenu();

	private:
		OpenGLGlutProcess m_OpenGLGlutProcess;
		GLUTApplicationInformation m_GLUTInformation;
		int m_WindowID;
		int m_MenuID;
		RendererParameter m_RendererParameter;
	};
}

#endif // FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_FRAME_BUILD_H
