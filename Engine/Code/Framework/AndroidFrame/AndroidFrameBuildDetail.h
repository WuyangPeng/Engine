// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 16:39)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_FRAME_BUILD_DETAIL_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_FRAME_BUILD_DETAIL_H

#include "AndroidFrameBuild.h"
#include "System/Console/ConsoleCreate.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

template <typename AndroidProcess>
Framework::AndroidFrameBuild<AndroidProcess>
	::AndroidFrameBuild(AndroidApp* state)
	:m_State{ state }, m_AndroidProcess{ System::g_Microseconds / sm_Interval }, m_AndroidMessageLoop{ m_State, m_AndroidProcess.GetDisplay() }
{
	using namespace std::literals;

	System::AppDummy();

	if (!(m_AndroidProcess.PreCreate() && InitApplication()))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("¥¥Ω®¥∞ø⁄ ß∞‹£°"s));
	}

	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

// private
template <typename AndroidProcess>
bool Framework::AndroidFrameBuild<AndroidProcess>
	::InitApplication()
{
	m_State->SetOnAppCmd(m_AndroidProcess.GetAppCmd());
	m_State->SetOnInputEvent(m_AndroidProcess.GetInputEvent());

	System::CreateVirtualWindow(m_State, SYSTEM_TEXT("Android Virtual Window"));

	System::RemoveConsoleCloseButton();

	return true;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename AndroidProcess>
bool Framework::AndroidFrameBuild<AndroidProcess>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename AndroidProcess>
void Framework::AndroidFrameBuild<AndroidProcess>
	::EnterMessageLoop()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_AndroidProcess.Initialize())
	{
		m_AndroidProcess.PreIdle();

		m_AndroidMessageLoop.EnterMessageLoop();

		m_AndroidProcess.Terminate();
	}
}

template <typename AndroidProcess>
System::AndroidApp* Framework::AndroidFrameBuild<AndroidProcess>
	::GetAndroidApp() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return m_State;
}

#endif // FRAMEWORK_ANDROID_FRAME_ANDROID_FRAME_BUILD_DETAIL_H





