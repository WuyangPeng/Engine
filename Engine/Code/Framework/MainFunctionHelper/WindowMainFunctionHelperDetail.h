// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.4 (2019/07/31 17:53)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_WINDOW_MAIN_FUNCTION_HELPER_DETAIL_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_WINDOW_MAIN_FUNCTION_HELPER_DETAIL_H

#include "WindowMainFunctionHelper.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/WindowProcess/WindowProcessManager.h"
#include "System/SystemOutput/MessageBoxSelection.h"
#include "CoreTools/Exception/Error.h"

#include <stdexcept>

template <template<typename > class Build,typename Process>
Framework::WindowMainFunctionHelper<Build, Process>
	::WindowMainFunctionHelper(HInstance instance,char* commandLine, const WindowApplicationInformation& information,
							   const EnvironmentDirectory& environmentDirectory)
	:ParentType{ environmentDirectory }, m_Build{}
{
    Initializers(instance,commandLine,information);

	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

// private
template <template<typename > class Build,typename Process>
void Framework::WindowMainFunctionHelper<Build, Process>
	::Initializers(HInstance instance,char* commandLine, const WindowApplicationInformation& information)
{
	try
	{
		WindowProcessManager::Create();

		m_Build.reset(new BuildType(instance,commandLine,information));
	}
	catch (CoreTools::Error& error)
	{
		System::MessageBoxSelectionWithTChar(error.GetError().c_str(),SYSTEM_TEXT("´íÎó"));
	}
	catch(std::runtime_error& error)
	{
		System::MessageBoxSelectionWithChar(error.what(),"´íÎó");
	}
	catch(...)
	{
		System::MessageBoxSelectionWithTChar(SYSTEM_TEXT("Î´Öª´íÎó£¡"),SYSTEM_TEXT("´íÎó"));
	}
}

template <template<typename > class Build,typename Process>
Framework::WindowMainFunctionHelper<Build, Process>
	::~WindowMainFunctionHelper()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;

	if(!IsDestroy())
	{
        Destroy();
	}
}

// private
template <template<typename > class Build,typename Process>
void Framework::WindowMainFunctionHelper<Build, Process>
	::Terminators()
{
	try
	{
		m_Build.reset();
		WindowProcessManager::Destroy();
	}
	catch (CoreTools::Error& error)
	{
		System::MessageBoxSelectionWithTChar(error.GetError().c_str(),SYSTEM_TEXT("´íÎó"));
	}
	catch(std::runtime_error& error)
	{
		System::MessageBoxSelectionWithChar(error.what(), "´íÎó");
	}
	catch(...)
	{
		System::MessageBoxSelectionWithTChar(SYSTEM_TEXT("Î´Öª´íÎó£¡"),SYSTEM_TEXT("´íÎó"));
	}
}

#ifdef OPEN_CLASS_INVARIANT
template <template<typename > class Build,typename Process>
bool Framework::WindowMainFunctionHelper<Build, Process>
   ::IsValid() const noexcept
{
	if(ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <template<typename > class Build,typename Process>
int Framework::WindowMainFunctionHelper<Build, Process>
    ::DoRun()
{
	return EnterMessageLoop();
}

template <template<typename > class Build,typename Process>
int Framework::WindowMainFunctionHelper<Build, Process>
   ::EnterMessageLoop()
{
	if(m_Build != nullptr)
		return static_cast<int>(  m_Build->EnterMessageLoop());
	else
		return -1;
}

template <template<typename > class Build,typename Process>
System::WindowHWnd Framework::WindowMainFunctionHelper<Build, Process>
	::GetHwnd() const
{
	if(m_Build != nullptr)
		return m_Build->GetHwnd();
	else
		return nullptr;
}

template <template<typename > class Build,typename Process>
void Framework::WindowMainFunctionHelper<Build, Process>
    ::Destroy()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(!IsDestroy())
	{
		Terminators();

		ParentType::Destroy();
	}
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_WINDOW_MAIN_FUNCTION_HELPER_DETAIL_H
