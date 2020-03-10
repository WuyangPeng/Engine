// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 13:22)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_FRAME_BUILD_DETAIL_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_FRAME_BUILD_DETAIL_H

#include "AndroidFrameBuild.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "System/Console/ConsoleCreate.h"

template <typename AndroidProcess>
Framework::AndroidFrameBuild<AndroidProcess>
	::AndroidFrameBuild(AndroidApp* state)
	:m_State(state),
	 m_AndroidProcess(),
	 m_AndroidMessageLoop(m_State,m_AndroidProcess.GetDisplay())
{
	System::AppDummy();

	if (!(m_AndroidProcess.PreCreate() && InitApplication()))
    {
		THROW_EXCEPTION(SYSTEM_TEXT("¥¥Ω®¥∞ø⁄ ß∞‹£°"));
    }

	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

// private
template <typename AndroidProcess>
bool Framework::AndroidFrameBuild<AndroidProcess>
	::InitApplication()
{
	m_State->onAppCmd = m_AndroidProcess.GetAppCmd();
	m_State->onInputEvent = m_AndroidProcess.GetInputEvent();

	System::CreateVirtualWindow(m_State, SYSTEM_TEXT("Android Virtual Window"));
  
	System::RemoveConsoleCloseButton();

    return true;
}

template <typename AndroidProcess>
Framework::AndroidFrameBuild<AndroidProcess>
	::~AndroidFrameBuild()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
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

	if(m_AndroidProcess.Initialize())
	{
		m_AndroidProcess.PreIdle();

		m_AndroidMessageLoop.EnterMessageLoop();

		m_AndroidProcess.Terminate();
	}
}

template <typename AndroidProcess>
System::AndroidApp* Framework::AndroidFrameBuild<AndroidProcess>
	::GetAndroidApp()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return m_State;
}

#endif // FRAMEWORK_ANDROID_FRAME_ANDROID_FRAME_BUILD_DETAIL_H





