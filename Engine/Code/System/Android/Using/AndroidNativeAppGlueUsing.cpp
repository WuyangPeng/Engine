// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:02)

#include "System/SystemExport.h"

#include "AndroidNativeAppGlueUsing.h"
#include "AndroidInputUsing.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/PragmaWarning.h"

#ifndef SYSTEM_PLATFORM_ANDROID

using std::make_shared;

System::AndroidPollSource
	::AndroidPollSource() noexcept
	:id{ 0 }, app{ nullptr }
{

}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26461)
void System::AndroidPollSource
	::process(struct AndroidApp* androidApp, struct AndroidPollSource* source) noexcept
{
	SYSTEM_UNUSED_ARG(androidApp);
	SYSTEM_UNUSED_ARG(source);
}
#include STSTEM_WARNING_POP

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
System::AndroidApp
	::AndroidApp()
	:userData{ nullptr }, activity{ nullptr }, config{ nullptr }, savedState{ nullptr }, savedStateSize{ 0 }, looper{ nullptr }, 
	 contentRect{}, activityState{ 0 }, destroyRequested{ 0 },
	 msgread{ 0 }, msgwrite{ 0 }, cmdPollSource{}, inputPollSource{}, running{ nullptr }, stateSaved{ 0 }, destroyed{ 0 }, redrawNeeded{ 0 }, 
	 pendingInputQueue{ nullptr }, pendingWindow{ nullptr }, pendingContentRect{}, onAppCmd{ nullptr }, onInputEvent{ nullptr },
	 inputQueue{ std::make_shared<AndroidInputQueue>() },window{ std::make_shared<AndroidNativeWindow>() }
{	
	 
}
#include STSTEM_WARNING_POP

void System::AndroidApp
	::SetDestroyRequested(int isDestroyRequested) noexcept
{
	destroyRequested = isDestroyRequested;
}

int System::AndroidApp
	::GetDestroyRequested() const noexcept
{
	return destroyRequested;
}  

System::WindowHWnd System::AndroidApp
	::GetRunning() const noexcept
{
	return running;
}

void System::AndroidApp
	::SetRunning(System::WindowHWnd val) noexcept
{
	running = val;
}

void System::AndroidApp
	::OnAppCmd(struct AndroidApp* app, int cmd) noexcept
{
	onAppCmd(app, cmd);
}

void System::AndroidApp
	::OnInputEvent(struct AndroidApp* app, AndroidInputEvent* event) noexcept
{
	onInputEvent(app, event);
}

void System::AndroidApp
	::SetOnAppCmd(AppCmd value) noexcept
{
	onAppCmd = value;
}

void System::AndroidApp
	::SetOnInputEvent(InputEvent value) noexcept
{
	onInputEvent = value;
}

#endif // SYSTEM_PLATFORM_ANDROID