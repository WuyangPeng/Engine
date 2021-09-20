// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/20 21:14)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_OPENGL_GLUT_MAIN_FUNCTION_HELPER_DETAIL_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_OPENGL_GLUT_MAIN_FUNCTION_HELPER_DETAIL_H

#include "OpenGLGlutMainFunctionHelper.h"
#include "Flags/MainFunctionSchedule.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Framework/Application/GlutApplicationInformation.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcessManager.h"

template <template<typename> class Build, typename Process>
Framework::OpenGLGlutMainFunctionHelper<Build, Process>
	::OpenGLGlutMainFunctionHelper(int argc, char** argv, const GLUTApplicationInformation& information, const EnvironmentDirectory& environmentDirectory)
	:ParentType{ environmentDirectory }, m_Build{ }, m_OpenGLGlutMainFunctionSchedule{ OpenGLGlutMainFunctionSchedule::Failure }
{
	Initializers(argc, argv, information, environmentDirectory);

	// 构造未完成
}

template <template<typename> class Build, typename Process>
void Framework::OpenGLGlutMainFunctionHelper<Build, Process>
	::Init()
{
	OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.SetMainFunctionHelper(shared_from_this());
	m_OpenGLGlutMainFunctionSchedule = OpenGLGlutMainFunctionSchedule::InitComplete;

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <template<typename> class Build, typename Process>
Framework::OpenGLGlutMainFunctionHelper<Build, Process>
	::OpenGLGlutMainFunctionHelper(OpenGLGlutMainFunctionHelper&& rhs) noexcept
	:ParentType{ std::move(rhs) }, m_Build{ std::move(rhs.m_Build) }, m_OpenGLGlutMainFunctionSchedule{ rhs.m_OpenGLGlutMainFunctionSchedule }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <template<typename> class Build, typename Process>
Framework::OpenGLGlutMainFunctionHelper<Build, Process>& Framework::OpenGLGlutMainFunctionHelper<Build, Process>
	::operator=(OpenGLGlutMainFunctionHelper&& rhs) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	ParentType::operator=(std::move(rhs));

	m_Build = std::move(rhs.m_Build);
	m_OpenGLGlutMainFunctionSchedule = rhs.m_OpenGLGlutMainFunctionSchedule;

	return *this;
}

template <template<typename> class Build, typename Process>
Framework::OpenGLGlutMainFunctionHelper<Build, Process>
	::~OpenGLGlutMainFunctionHelper() noexcept
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;

	CoreTools::NoexceptNoReturn(*this, &ClassType::Destroy);
}

#ifdef OPEN_CLASS_INVARIANT
template <template<typename> class Build, typename Process>
bool Framework::OpenGLGlutMainFunctionHelper<Build, Process>
	::IsValid() const noexcept
{
	if (ParentType::IsValid() &&
		(m_OpenGLGlutMainFunctionSchedule != OpenGLGlutMainFunctionSchedule::Max) &&
		((m_OpenGLGlutMainFunctionSchedule == OpenGLGlutMainFunctionSchedule::InitComplete) ^ (m_Build == nullptr)))
	{
		return true;
	}		
	else
	{
		return false;
	}		
}
#endif // OPEN_CLASS_INVARIANT

template <template<typename> class Build, typename Process>
void Framework::OpenGLGlutMainFunctionHelper<Build, Process>
	::Destroy()
{
	;

	if (OpenGLGlutMainFunctionSchedule::Failure < m_OpenGLGlutMainFunctionSchedule)
	{
		Terminators();
	}

	ParentType::Destroy();
}

// private
template <template<typename> class Build, typename Process>
int Framework::OpenGLGlutMainFunctionHelper<Build, Process>
	::DoRun()
{
	return RunOpenGLGlutMainLoop();
}

// private
template <template<typename> class Build, typename Process>
int Framework::OpenGLGlutMainFunctionHelper<Build, Process>
	::RunOpenGLGlutMainLoop()
{
	if (m_Build != nullptr)
	{
		m_Build->RunOpenGLGlutMainLoop();
	}	

	return 0;
}

// private
template <template<typename> class Build, typename Process>
void Framework::OpenGLGlutMainFunctionHelper<Build, Process>
	::Initializers(int argc, char** argv, const GLUTApplicationInformation& information, const EnvironmentDirectory& environmentDirectory)
{
	EXCEPTION_TRY
	{
		InitOpenGLGlutProcess();
		InitCamera();
		InitImpl(argc, argv, information, environmentDirectory);
	}
	EXCEPTION_WINDOWS_ENTRY_POINT_CATCH
}

template <template<typename> class Build, typename Process>
void Framework::OpenGLGlutMainFunctionHelper<Build, Process>
	::InitOpenGLGlutProcess()
{
	OpenGLGlutProcessManager::Create();	
	m_OpenGLGlutMainFunctionSchedule = OpenGLGlutMainFunctionSchedule::OpenGLGlutProcess;	
}

template <template<typename> class Build, typename Process>
void Framework::OpenGLGlutMainFunctionHelper<Build, Process>
	::InitCamera()
{
	Rendering::CameraManager::Create();
	m_OpenGLGlutMainFunctionSchedule = OpenGLGlutMainFunctionSchedule::Camera;
}

template <template<typename> class Build, typename Process>
void Framework::OpenGLGlutMainFunctionHelper<Build, Process>
	::InitImpl(int argc, char** argv, const GLUTApplicationInformation& information, const EnvironmentDirectory& environmentDirectory)
{
	m_Build = std::make_shared<BuildType>(information, environmentDirectory);
	m_OpenGLGlutMainFunctionSchedule = OpenGLGlutMainFunctionSchedule::Max;
	m_Build->InitOpenGLGlutContext(argc, argv);
}

template <template<typename> class Build, typename Process>
void Framework::OpenGLGlutMainFunctionHelper<Build, Process>
	::Terminators()
{
	EXCEPTION_TRY
	{		
		DestroyImpl();
		DestroyCamera();
		DestroyOpenGLGlutProcess(); 		
	}
	EXCEPTION_WINDOWS_ENTRY_POINT_CATCH
}

template <template<typename> class Build, typename Process>
void Framework::OpenGLGlutMainFunctionHelper<Build, Process>
	::DestroyImpl() noexcept
{
	if (OpenGLGlutMainFunctionSchedule::Max <= m_OpenGLGlutMainFunctionSchedule)
	{
		m_Build.reset();
		m_OpenGLGlutMainFunctionSchedule = OpenGLGlutMainFunctionSchedule::Camera;
	}
}

template <template<typename> class Build, typename Process>
void Framework::OpenGLGlutMainFunctionHelper<Build, Process>
	::DestroyCamera() noexcept
{
	if (OpenGLGlutMainFunctionSchedule::Camera <= m_OpenGLGlutMainFunctionSchedule)
	{
		Rendering::CameraManager::Destroy();
		
		m_OpenGLGlutMainFunctionSchedule = OpenGLGlutMainFunctionSchedule::OpenGLGlutProcess;
	}
}

template <template<typename> class Build, typename Process>
void Framework::OpenGLGlutMainFunctionHelper<Build, Process>
	::DestroyOpenGLGlutProcess()  
{
	if (OpenGLGlutMainFunctionSchedule::OpenGLGlutProcess <= m_OpenGLGlutMainFunctionSchedule)
	{
		OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.ClearMainFunctionHelper();
		OpenGLGlutProcessManager::Destroy();

		m_OpenGLGlutMainFunctionSchedule = OpenGLGlutMainFunctionSchedule::Failure;
	}
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_OPENGL_GLUT_MAIN_FUNCTION_HELPER_DETAIL_H
