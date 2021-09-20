// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/20 21:10)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_ANDROID_MAIN_FUNCTION_HELPER_DETAIL_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_ANDROID_MAIN_FUNCTION_HELPER_DETAIL_H

#include "AndroidMainFunctionHelper.h"
#include "Flags/MainFunctionSchedule.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/AndroidFrame/AndroidProcessManager.h"

template <template<typename> class Build, typename Process>
Framework::AndroidMainFunctionHelper<Build, Process>
	::AndroidMainFunctionHelper(AndroidApp* androidApp, const EnvironmentDirectory& environmentDirectory)
	:ParentType{ environmentDirectory }, m_Build{ }, m_AndroidMainFunctionSchedule{ AndroidMainFunctionSchedule::Failure }
{
	Initializers(androidApp);

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <template<typename> class Build, typename Process>
Framework::AndroidMainFunctionHelper<Build, Process>
	::AndroidMainFunctionHelper(AndroidMainFunctionHelper&& rhs) noexcept
	:ParentType{ std::move(rhs) }, m_Build{ std::move(rhs.m_Build) }, m_AndroidMainFunctionSchedule{ rhs.m_AndroidMainFunctionSchedule }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <template<typename> class Build, typename Process>
Framework::AndroidMainFunctionHelper<Build, Process>& Framework::AndroidMainFunctionHelper<Build, Process>
	::operator=(AndroidMainFunctionHelper&& rhs) noexcept
{
	ParentType::operator=(std::move(rhs));

	m_Build = std::move(rhs.m_Build);
	m_AndroidMainFunctionSchedule = rhs.m_AndroidMainFunctionSchedule;

	return *this;
}

template <template<typename> class Build, typename Process>
Framework::AndroidMainFunctionHelper<Build, Process>
	::~AndroidMainFunctionHelper() noexcept
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
	 
	CoreTools::NoexceptNoReturn(*this, &ClassType::Destroy);
}

#ifdef OPEN_CLASS_INVARIANT
template <template<typename> class Build, typename Process>
bool Framework::AndroidMainFunctionHelper<Build, Process>
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && ((AndroidMainFunctionSchedule::Max <= m_AndroidMainFunctionSchedule) ^ (m_Build == nullptr)))
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <template<typename> class Build, typename Process>
void Framework::AndroidMainFunctionHelper<Build, Process>
	::Destroy()
{
	;

	if (AndroidMainFunctionSchedule::Failure < m_AndroidMainFunctionSchedule)
	{
		Terminators();		
	}

	ParentType::Destroy();
}

// protected
template <template<typename> class Build, typename Process>
System::AndroidApp* Framework::AndroidMainFunctionHelper<Build, Process>
	::GetAndroidApp()
{
	using namespace std::literals;

	if (m_Build != nullptr)
	{
		return m_Build->GetAndroidApp();
	}		
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("ªÒ»°∞≤◊øApp ß∞‹£°"s));
	}
}

// private
template <template<typename > class Build, typename CallBack>
int Framework::AndroidMainFunctionHelper<Build, CallBack>
	::DoRun()
{
	return RunAndroidMainLoop();
}

// private
template <template<typename> class Build, typename Process>
int Framework::AndroidMainFunctionHelper<Build, Process>
	::RunAndroidMainLoop()
{
	if (m_Build != nullptr)
	{
		m_Build->EnterMessageLoop();
	}

	return 0;
}

// private
template <template<typename> class Build, typename Process>
void Framework::AndroidMainFunctionHelper<Build, Process>
	::Initializers(AndroidApp* androidApp)
{
	EXCEPTION_TRY
	{		
		InitAndroidProcess();
		InitImpl(androidApp);
	}
	EXCEPTION_ENTRY_POINT_CATCH
}

// private
template <template<typename> class Build, typename Process>
void Framework::AndroidMainFunctionHelper<Build, Process>
	::InitAndroidProcess()
{
	AndroidProcessManager::Create();
	m_AndroidMainFunctionSchedule = AndroidMainFunctionSchedule::AndroidProcess;
}

// private
template <template<typename> class Build, typename Process>
void Framework::AndroidMainFunctionHelper<Build, Process>
	::InitImpl(AndroidApp* androidApp)
{
	m_Build = std::make_shared<BuildType>(androidApp);
	m_AndroidMainFunctionSchedule = AndroidMainFunctionSchedule::Max;	 
}

// private
template <template<typename> class Build, typename Process>
void Framework::AndroidMainFunctionHelper<Build, Process>
	::Terminators()
{
	EXCEPTION_TRY
	{
		DestroyImpl();
		DestroyAndroidProcess();		
	}
	EXCEPTION_ENTRY_POINT_CATCH
}

// private
template <template<typename> class Build, typename Process>
void Framework::AndroidMainFunctionHelper<Build, Process>
	::DestroyImpl() noexcept
{
	if (AndroidMainFunctionSchedule::Max <= m_AndroidMainFunctionSchedule)
	{
		m_Build.reset();
		m_AndroidMainFunctionSchedule = AndroidMainFunctionSchedule::AndroidProcess;
	}
}

// private
template <template<typename> class Build, typename Process>
void Framework::AndroidMainFunctionHelper<Build, Process>
	::DestroyAndroidProcess()
{
	if (AndroidMainFunctionSchedule::AndroidProcess <= m_AndroidMainFunctionSchedule)
	{
		AndroidProcessManager::Destroy();
		m_AndroidMainFunctionSchedule = AndroidMainFunctionSchedule::Failure;
	}
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_ANDROID_MAIN_FUNCTION_HELPER_DETAIL_H
