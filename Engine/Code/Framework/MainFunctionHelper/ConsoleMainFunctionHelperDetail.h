// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/20 21:12)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_DETAIL_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_DETAIL_H

#include "ConsoleMainFunctionHelper.h"
#include "Flags/MainFunctionSchedule.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 

template <template<typename> class Build, typename Process>
Framework::ConsoleMainFunctionHelper<Build, Process>
	::ConsoleMainFunctionHelper(int argc, char** argv, const String& consoleTitle, const EnvironmentDirectory& environmentDirectory)
	:ParentType{ argc,argv,consoleTitle,environmentDirectory }, m_Build{ }, m_ConsoleMainFunctionSchedule{ ConsoleMainFunctionSchedule::Failure }
{
	Initializers();

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <template<typename> class Build, typename Process>
Framework::ConsoleMainFunctionHelper<Build, Process>
	::ConsoleMainFunctionHelper(ConsoleMainFunctionHelper&& rhs) noexcept
	:ParentType{ std::move(rhs) }, m_Build{ std::move(rhs.m_Build) }, m_ConsoleMainFunctionSchedule{ rhs.m_ConsoleMainFunctionSchedule }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <template<typename> class Build, typename Process>
Framework::ConsoleMainFunctionHelper<Build, Process>& Framework::ConsoleMainFunctionHelper<Build, Process>
	::operator=(ConsoleMainFunctionHelper&& rhs) noexcept
{
	ParentType::operator=(std::move(rhs));

	m_Build = std::move(rhs.m_Build);
	m_ConsoleMainFunctionSchedule = rhs.m_ConsoleMainFunctionSchedule;

	return *this;
}

template <template<typename> class Build, typename Process>
Framework::ConsoleMainFunctionHelper<Build, Process>
	::~ConsoleMainFunctionHelper() noexcept
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;

	CoreTools::NoexceptNoReturn(*this, &ClassType::Destroy);
}

#ifdef OPEN_CLASS_INVARIANT
template <template<typename> class Build, typename Process>
bool Framework::ConsoleMainFunctionHelper<Build, Process>
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && ((ConsoleMainFunctionSchedule::Max <= m_ConsoleMainFunctionSchedule) ^ (m_Build == nullptr)))
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <template<typename> class Build, typename Process>
void Framework::ConsoleMainFunctionHelper<Build, Process>
	::Destroy()
{
	;

	if (ConsoleMainFunctionSchedule::Failure < m_ConsoleMainFunctionSchedule)
	{
		Terminators();
	}

	ParentType::Destroy();
}

// private
template <template<typename > class Build, typename CallBack>
int Framework::ConsoleMainFunctionHelper<Build, CallBack>
	::DoRun() noexcept
{
	return RunConsoleMainLoop();
}

// private
template <template<typename> class Build, typename Process>
int Framework::ConsoleMainFunctionHelper<Build, Process>
	::RunConsoleMainLoop() noexcept
{
	if (m_Build != nullptr)
	{
		m_Build->EnterMessageLoop();
	}	

	return 0;
}

// private
template <template<typename> class Build, typename Process>
void Framework::ConsoleMainFunctionHelper<Build, Process>
	::Initializers()
{
	EXCEPTION_TRY
	{
		InitConsoleProcess();
		InitImpl();
	}
	EXCEPTION_ENTRY_POINT_CATCH
}

// private
template <template<typename> class Build, typename Process>
void Framework::ConsoleMainFunctionHelper<Build, Process>
	::InitConsoleProcess() noexcept
{
	m_ConsoleMainFunctionSchedule = ConsoleMainFunctionSchedule::ConsoleProcess;
}

// private
template <template<typename> class Build, typename Process>
void Framework::ConsoleMainFunctionHelper<Build, Process>
	::InitImpl()
{
	m_Build = std::make_shared<BuildType>();
	m_ConsoleMainFunctionSchedule = ConsoleMainFunctionSchedule::Max;
}

// private
template <template<typename> class Build, typename Process>
void Framework::ConsoleMainFunctionHelper<Build, Process>
	::Terminators()
{
	EXCEPTION_TRY
	{
		DestroyImpl();
		DestroyConsoleProcess();
	}
	EXCEPTION_ENTRY_POINT_CATCH
}

// private
template <template<typename> class Build, typename Process>
void Framework::ConsoleMainFunctionHelper<Build, Process>
	::DestroyImpl() noexcept
{
	if (ConsoleMainFunctionSchedule::Max <= m_ConsoleMainFunctionSchedule)
	{
		m_Build.reset();
		m_ConsoleMainFunctionSchedule = ConsoleMainFunctionSchedule::ConsoleProcess;
	}
}

// private
template <template<typename> class Build, typename Process>
void Framework::ConsoleMainFunctionHelper<Build, Process>
	::DestroyConsoleProcess() noexcept
{
	if (ConsoleMainFunctionSchedule::ConsoleProcess <= m_ConsoleMainFunctionSchedule)
	{
		m_ConsoleMainFunctionSchedule = ConsoleMainFunctionSchedule::Failure;
	}
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_DETAIL_H
