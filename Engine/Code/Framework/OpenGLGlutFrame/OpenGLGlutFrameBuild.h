// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 15:58)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_FRAME_BUILD_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_FRAME_BUILD_H

#include "Rendering/Renderers/RendererParameter.h"
#include "Framework/Application/GLUTApplicationInformation.h"
#include "Framework/MainFunctionHelper/MainFunctionHelperFwd.h"

namespace Framework
{
	template <typename OpenGLGlutProcess>
	class OpenGLGlutFrameBuild
	{
	public:
		using ProcessType = OpenGLGlutProcess;
		using ClassType = OpenGLGlutFrameBuild<ProcessType>;
		using RendererParameter = Rendering::RendererParameter;

	public:
		OpenGLGlutFrameBuild(const GLUTApplicationInformation& glutInformation, const EnvironmentDirectory& environmentDirectory);
		virtual ~OpenGLGlutFrameBuild() = default;
		OpenGLGlutFrameBuild(const OpenGLGlutFrameBuild& rhs) noexcept = default;
		OpenGLGlutFrameBuild& operator=(const OpenGLGlutFrameBuild& rhs) noexcept = default;
		OpenGLGlutFrameBuild(OpenGLGlutFrameBuild&& rhs) noexcept = default;
		OpenGLGlutFrameBuild& operator=(OpenGLGlutFrameBuild&& rhs) noexcept = default;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual bool InitOpenGLGlutContext(int argc, char** argv);
		virtual void RunOpenGLGlutMainLoop();

	private:
		virtual bool PreCreate();
		virtual bool InitGlutFunctionLibrary(int argc, char** argv);
		virtual bool CreateGlutWindow();
		virtual bool SetCallBackFunction() noexcept;
		virtual bool SetupRenderStatus() noexcept;
		virtual bool OpenGLInit();
		virtual bool CreateMenu() noexcept;

		static std::string GetRendererParameter(const EnvironmentDirectory& environmentDirectory);

	private:
		static constexpr auto sm_Interval = 60;

		OpenGLGlutProcess m_OpenGLGlutProcess;
		GLUTApplicationInformation m_GLUTInformation;
		int m_WindowID;
		int m_MenuID;
		RendererParameter m_RendererParameter;
	};
}

#endif // FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_FRAME_BUILD_H
