// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/20 21:16)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_WINDOW_MAIN_FUNCTION_HELPER_DETAIL_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_WINDOW_MAIN_FUNCTION_HELPER_DETAIL_H

#include "WindowMainFunctionHelper.h"

#include "Flags/MainFunctionSchedule.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Contract/Noexcept.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Framework/WindowProcess/WindowProcessManager.h"

template <template<typename> class Build, typename Process>
Framework::WindowMainFunctionHelper<Build, Process>
	::WindowMainFunctionHelper(HInstance instance, const char* commandLine, const WindowApplicationInformation& information,
							   const EnvironmentDirectory& environmentDirectory)
	:ParentType{ environmentDirectory }, m_Build{ }, m_WindowMainFunctionSchedule{ WindowMainFunctionSchedule::Failure }
{
	Initializers(instance, commandLine, information);

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <template<typename> class Build, typename Process>
Framework::WindowMainFunctionHelper<Build, Process>
	::WindowMainFunctionHelper(WindowMainFunctionHelper&& rhs) noexcept
	:ParentType{ std::move(rhs) }, m_Build{ std::move(rhs.m_Build) }, m_WindowMainFunctionSchedule{ rhs.m_WindowMainFunctionSchedule }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <template<typename> class Build, typename Process>
Framework::WindowMainFunctionHelper<Build, Process>& Framework::WindowMainFunctionHelper<Build, Process>
	::operator=(WindowMainFunctionHelper&& rhs) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	ParentType::operator=(std::move(rhs));

	m_Build = std::move(rhs.m_Build);
	m_WindowMainFunctionSchedule = rhs.m_WindowMainFunctionSchedule;

	return *this;
}

template <template<typename> class Build, typename Process>
Framework::WindowMainFunctionHelper<Build, Process>
	::~WindowMainFunctionHelper() noexcept
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;

	CoreTools::NoexceptNoReturn(*this, &ClassType::Destroy);
}

#ifdef OPEN_CLASS_INVARIANT
template <template<typename> class Build, typename Process>
bool Framework::WindowMainFunctionHelper<Build, Process>
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && ((WindowMainFunctionSchedule::Max <= m_WindowMainFunctionSchedule) ^ (m_Build == nullptr)))
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <template<typename> class Build, typename Process>
int Framework::WindowMainFunctionHelper<Build, Process>
	::DoRun()
{
	return EnterMessageLoop();
}

template <template<typename> class Build, typename Process>
int Framework::WindowMainFunctionHelper<Build, Process>
	::EnterMessageLoop()
{
	if (m_Build != nullptr)
		return boost::numeric_cast<int>(m_Build->EnterMessageLoop());
	else
		return -1;
}

template <template<typename> class Build, typename Process>
System::WindowHWnd Framework::WindowMainFunctionHelper<Build, Process>
	::GetHwnd() const noexcept
{
	if (m_Build != nullptr)
		return m_Build->GetHwnd();
	else
		return nullptr;
}

template <template<typename> class Build, typename Process>
void Framework::WindowMainFunctionHelper<Build, Process>
	::Destroy()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (WindowMainFunctionSchedule::Failure < m_WindowMainFunctionSchedule)
	{
		Terminators();		
	}

	ParentType::Destroy();
}

// private
template <template<typename> class Build, typename Process>
void Framework::WindowMainFunctionHelper<Build, Process>
	::Initializers(HInstance instance, const char* commandLine, const WindowApplicationInformation& information)
{
	EXCEPTION_TRY
	{		
		InitWindowProcess();
		InitCamera();
		InitRendererManager();
		InitImpl(instance, commandLine, information);
	}
	EXCEPTION_WINDOWS_ENTRY_POINT_CATCH
}

// private
template <template<typename> class Build, typename Process>
void Framework::WindowMainFunctionHelper<Build, Process>
	::InitWindowProcess()
{
	WindowProcessManager::Create();
	m_WindowMainFunctionSchedule = WindowMainFunctionSchedule::WindowProcess;
}

// private
template <template<typename> class Build, typename Process>
void Framework::WindowMainFunctionHelper<Build, Process>
	::InitCamera()
{
	Rendering::CameraManager::Create();
	m_WindowMainFunctionSchedule = WindowMainFunctionSchedule::Camera;
}

// private
template <template<typename> class Build, typename Process>
void Framework::WindowMainFunctionHelper<Build, Process>
	::InitRendererManager()
{
	Rendering::RendererManager::Create();
	m_WindowMainFunctionSchedule = WindowMainFunctionSchedule::RendererManager;
}

// private
template <template<typename> class Build, typename Process>
void Framework::WindowMainFunctionHelper<Build, Process>
	::InitImpl(HInstance instance, const char* commandLine, const WindowApplicationInformation& information)
{
	m_Build = std::make_shared<BuildType>(instance, commandLine, information, GetEnvironmentDirectory());
	m_WindowMainFunctionSchedule = WindowMainFunctionSchedule::Max;
}

// private
template <template<typename> class Build, typename Process>
void Framework::WindowMainFunctionHelper<Build, Process>
	::Terminators()
{
	EXCEPTION_TRY
	{
		DestroyImpl();
		DestroyRendererManager();
		DestroyCamera();
		DestroyWindowProcess();
	}
	EXCEPTION_WINDOWS_ENTRY_POINT_CATCH
}

// private
template <template<typename> class Build, typename Process>
void Framework::WindowMainFunctionHelper<Build, Process>
	::DestroyImpl() noexcept
{
	if (WindowMainFunctionSchedule::Max <= m_WindowMainFunctionSchedule)
	{
		m_Build.reset();
		m_WindowMainFunctionSchedule = WindowMainFunctionSchedule::RendererManager;
	}
}

// private
template <template<typename> class Build, typename Process>
void Framework::WindowMainFunctionHelper<Build, Process>
	::DestroyRendererManager() noexcept
{
	if (WindowMainFunctionSchedule::RendererManager <= m_WindowMainFunctionSchedule)
	{
		Rendering::RendererManager::Destroy();
		m_WindowMainFunctionSchedule = WindowMainFunctionSchedule::Camera;
	}
}

// private
template <template<typename> class Build, typename Process>
void Framework::WindowMainFunctionHelper<Build, Process>
	::DestroyCamera() noexcept
{
	if (WindowMainFunctionSchedule::Camera <= m_WindowMainFunctionSchedule)
	{
		Rendering::CameraManager::Destroy();
		m_WindowMainFunctionSchedule = WindowMainFunctionSchedule::WindowProcess;
	}
}

// private
template <template<typename> class Build, typename Process>
void Framework::WindowMainFunctionHelper<Build, Process>
	::DestroyWindowProcess() noexcept
{
	if (WindowMainFunctionSchedule::WindowProcess <= m_WindowMainFunctionSchedule)
	{
		WindowProcessManager::Destroy();
		m_WindowMainFunctionSchedule = WindowMainFunctionSchedule::Failure;
	}
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_WINDOW_MAIN_FUNCTION_HELPER_DETAIL_H
