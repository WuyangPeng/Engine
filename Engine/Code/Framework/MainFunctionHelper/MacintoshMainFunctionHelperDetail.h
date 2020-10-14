// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/20 21:13)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_MACINTOSH_MAIN_FUNCTION_HELPER_DETAIL_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_MACINTOSH_MAIN_FUNCTION_HELPER_DETAIL_H

#include "MacintoshMainFunctionHelper.h"
#include "Flags/MainFunctionSchedule.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 

template <template<typename> class Build, typename Process>
Framework::MacintoshMainFunctionHelper<Build, Process>
	::MacintoshMainFunctionHelper(const EnvironmentDirectory& environmentDirectory)
	:ParentType{ environmentDirectory }, m_Build{ }, m_MacintoshMainFunctionSchedule{ MacintoshMainFunctionSchedule::Failure }
{
	Initializers();

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <template<typename> class Build, typename Process>
Framework::MacintoshMainFunctionHelper<Build, Process>
	::MacintoshMainFunctionHelper(MacintoshMainFunctionHelper&& rhs) noexcept
	:ParentType{ std::move(rhs) }, m_Build{ std::move(rhs.m_Build) }, m_MacintoshMainFunctionSchedule{ rhs.m_MacintoshMainFunctionSchedule }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <template<typename> class Build, typename Process>
Framework::MacintoshMainFunctionHelper<Build, Process>& Framework::MacintoshMainFunctionHelper<Build, Process>
	::operator=(MacintoshMainFunctionHelper&& rhs) noexcept
{
	ParentType::operator=(std::move(rhs));

	m_Build = std::move(rhs.m_Build);
	m_MacintoshMainFunctionSchedule = rhs.m_MacintoshMainFunctionSchedule;

	return *this;
}

template <template<typename> class Build, typename Process>
Framework::MacintoshMainFunctionHelper<Build, Process>
	::~MacintoshMainFunctionHelper() noexcept
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
	 
	CoreTools::NoexceptNoReturn(*this, &ClassType::Destroy);
}

#ifdef OPEN_CLASS_INVARIANT
template <template<typename> class Build, typename Process>
bool Framework::MacintoshMainFunctionHelper<Build, Process>
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && ((MacintoshMainFunctionSchedule::Max <= m_MacintoshMainFunctionSchedule) ^ (m_Build == nullptr)))
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <template<typename> class Build, typename Process>
void Framework::MacintoshMainFunctionHelper<Build, Process>
	::Destroy()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (MacintoshMainFunctionSchedule::Failure < m_MacintoshMainFunctionSchedule)
	{
		Terminators();		
	}

	ParentType::Destroy();
}

// private
template <template<typename > class Build, typename CallBack>
int Framework::MacintoshMainFunctionHelper<Build, CallBack>
	::DoRun() noexcept
{
	return RunMacintoshMainLoop();
}

// private
template <template<typename> class Build, typename Process>
int Framework::MacintoshMainFunctionHelper<Build, Process>
	::RunMacintoshMainLoop() noexcept
{
	if (m_Build != nullptr)
	{
		m_Build->EnterMessageLoop();
	}	

	return 0;
}

// private
template <template<typename> class Build, typename Process>
void Framework::MacintoshMainFunctionHelper<Build, Process>
	::Initializers()
{
	EXCEPTION_TRY
	{		
		InitMacintoshProcess();
		InitImpl();
	}
	EXCEPTION_ENTRY_POINT_CATCH
}

// private
template <template<typename> class Build, typename Process>
void Framework::MacintoshMainFunctionHelper<Build, Process>
	::InitMacintoshProcess() noexcept
{ 
	m_MacintoshMainFunctionSchedule = MacintoshMainFunctionSchedule::MacintoshProcess;
}

// private
template <template<typename> class Build, typename Process>
void Framework::MacintoshMainFunctionHelper<Build, Process>
	::InitImpl()
{
	m_Build = std::make_shared<BuildType>();
	m_MacintoshMainFunctionSchedule = MacintoshMainFunctionSchedule::Max;
}

// private
template <template<typename> class Build, typename Process>
void Framework::MacintoshMainFunctionHelper<Build, Process>
	::Terminators()
{
	EXCEPTION_TRY
	{
		DestroyImpl();
		DestroyMacintoshProcess();
	}
	EXCEPTION_ENTRY_POINT_CATCH
}

// private
template <template<typename> class Build, typename Process>
void Framework::MacintoshMainFunctionHelper<Build, Process>
	::DestroyImpl() noexcept
{
	if (MacintoshMainFunctionSchedule::Max <= m_MacintoshMainFunctionSchedule)
	{
		m_Build.reset();
		m_MacintoshMainFunctionSchedule = MacintoshMainFunctionSchedule::MacintoshProcess;
	}
}

// private
template <template<typename> class Build, typename Process>
void Framework::MacintoshMainFunctionHelper<Build, Process>
	::DestroyMacintoshProcess() noexcept
{
	if (MacintoshMainFunctionSchedule::MacintoshProcess <= m_MacintoshMainFunctionSchedule)
	{ 
		m_MacintoshMainFunctionSchedule = MacintoshMainFunctionSchedule::Failure;
	}
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_MACINTOSH_MAIN_FUNCTION_HELPER_DETAIL_H
