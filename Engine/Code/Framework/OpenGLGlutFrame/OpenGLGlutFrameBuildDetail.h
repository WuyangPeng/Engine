// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 15:56)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_FRAME_BUILD_DETAIL_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_FRAME_BUILD_DETAIL_H

#include "OpenGLGlutFrameBuild.h"
#include "System/OpenGL/OpenGLAPI.h"
#include "System/OpenGL/OpenGLGlut.h"
#include "System/OpenGL/OpenGLInit.h"
#include "System/Console/ConsoleCreate.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"

template <typename OpenGLGlutProcess>
Framework::OpenGLGlutFrameBuild<OpenGLGlutProcess>
	::OpenGLGlutFrameBuild(const GLUTApplicationInformation& glutInformation, const EnvironmentDirectory& environmentDirectory)
	:m_OpenGLGlutProcess{ System::g_Microseconds / sm_Interval }, m_GLUTInformation{ glutInformation }, m_WindowID{ 0 }, m_MenuID{ 0 },
	 m_RendererParameter{ GetRendererParameter(environmentDirectory) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <typename OpenGLGlutProcess>
std::string Framework::OpenGLGlutFrameBuild<OpenGLGlutProcess>
	::GetRendererParameter(const EnvironmentDirectory& environmentDirectory)
{
	return CoreTools::StringConversion::StandardConversionMultiByte(environmentDirectory.GetDirectory(UpperDirectory::Configuration) + SYSTEM_TEXT("Renderer.json"));
}

#ifdef OPEN_CLASS_INVARIANT
template <typename OpenGLGlutProcess>
bool Framework::OpenGLGlutFrameBuild<OpenGLGlutProcess>
	::IsValid() const noexcept
{
	if (0 <= m_WindowID && 0 <= m_MenuID)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename OpenGLGlutProcess>
bool Framework::OpenGLGlutFrameBuild<OpenGLGlutProcess>
	::InitOpenGLGlutContext(int argc, char** argv)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (PreCreate() &&
		InitGlutFunctionLibrary(argc, argv) &&
		CreateGlutWindow() &&
		SetCallBackFunction() &&
		OpenGLInit() &&
		SetupRenderStatus() &&
		CreateMenu())
		return true;

	return false;
}

// private
template <typename OpenGLGlutProcess>
bool Framework::OpenGLGlutFrameBuild<OpenGLGlutProcess>
	::PreCreate()
{
	CLASS_IS_VALID;

	return m_OpenGLGlutProcess.PreCreate();
}

// private
template <typename OpenGLGlutProcess>
bool Framework::OpenGLGlutFrameBuild<OpenGLGlutProcess>
	::InitGlutFunctionLibrary(int argc, char** argv)
{
	System::GlutInit(&argc, argv);

	System::GlutInitDisplayMode(0 < m_RendererParameter.GetNumMultisamples());

	System::GlutInitWindowPosition(m_RendererParameter.GetXPosition(), m_RendererParameter.GetYPosition());
	System::GlutInitWindowSize(m_RendererParameter.GetWidth(), m_RendererParameter.GetHeight());
	System::GlutInitContextVersion(m_GLUTInformation.GetOpenGLMajorVersion(), m_GLUTInformation.GetOpenGLMinorVersion());

	System::GlutSetOption(System::EnumCastUnderlying(System::GlutExtension::WindowClose), System::EnumCastUnderlying(System::GlutExtension::GlutMainLoopReturns));

	System::RemoveConsoleCloseButton();

	return true;
}

// private
template <typename OpenGLGlutProcess>
bool Framework::OpenGLGlutFrameBuild<OpenGLGlutProcess>
	::CreateGlutWindow()
{
	m_WindowID = System::GlutCreateWindow(m_RendererParameter.GetWindowTitle());

	if (m_WindowID == 0)
	{
		return false;
	}
	else
	{
		m_OpenGLGlutProcess.SetWindowID(m_WindowID);
		m_OpenGLGlutProcess.SetMillisecond(System::EnumCastUnderlying(m_GLUTInformation.GetFrame()));

		return true;
	}
}

// private
template <typename OpenGLGlutProcess>
bool Framework::OpenGLGlutFrameBuild<OpenGLGlutProcess>
	::SetCallBackFunction() noexcept
{
	System::GlutReshapeFunc(m_OpenGLGlutProcess.GetChangeSizeCallback());
	System::GlutDisplayFunc(m_OpenGLGlutProcess.GetRenderSceneCallback());
	System::GlutIdleFunc(m_OpenGLGlutProcess.GetIdleFunctionCallback());
	System::GlutKeyboardFunc(m_OpenGLGlutProcess.GetKeyboardDownCallback());
	System::GlutSpecialFunc(m_OpenGLGlutProcess.GetSpecialKeysDownCallback());
	System::GlutKeyboardUpFunc(m_OpenGLGlutProcess.GetKeyboardUpCallback());
	System::GlutSpecialUpFunc(m_OpenGLGlutProcess.GetSpecialKeysUpCallback());
	System::GlutMouseFunc(m_OpenGLGlutProcess.GetMouseFunctionCallback());
	System::GlutMotionFunc(m_OpenGLGlutProcess.GetMotionFunctionCallback());
	System::GlutPassiveMotionFunc(m_OpenGLGlutProcess.GetPassiveMotionCallback());
	System::GlutTimerFunc(System::EnumCastUnderlying(m_GLUTInformation.GetFrame()), m_OpenGLGlutProcess.GetTimerFunctionCallback(), 1);

	// 注册终止函数，这样我们就可以在GLUT调用exit前销毁窗口。
	if (atexit(m_OpenGLGlutProcess.GetTerminateCallback()) != 0)
	{
		return false;
	}

	return true;
}

// private
template <typename OpenGLGlutProcess>
bool Framework::OpenGLGlutFrameBuild<OpenGLGlutProcess>
	::SetupRenderStatus() noexcept
{
	System::SetupRenderStatus();

	return true;
}

// private
template <typename OpenGLGlutProcess>
bool Framework::OpenGLGlutFrameBuild<OpenGLGlutProcess>
	::OpenGLInit()
{
	return System::OpenGLInit();
}

// private
template <typename OpenGLGlutProcess>
bool Framework::OpenGLGlutFrameBuild<OpenGLGlutProcess>
	::CreateMenu() noexcept
{
	m_MenuID = System::GlutCreateMenu(m_OpenGLGlutProcess.GetProcessMenuCallback());

	if (m_MenuID == 0)
		return false;

	return true;
}

template <typename OpenGLGlutProcess>
void Framework::OpenGLGlutFrameBuild<OpenGLGlutProcess>
	::RunOpenGLGlutMainLoop()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (m_OpenGLGlutProcess.Initialize())
	{
		m_OpenGLGlutProcess.PreIdle();

		System::GlutMainLoop();
	}
}

#endif // FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_FRAME_BUILD_DETAIL_H





