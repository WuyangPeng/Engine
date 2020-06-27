// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 16:39)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_PROCESS_DETAIL_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_PROCESS_DETAIL_H

#include "AndroidProcess.h"
#include "AndroidProcessManager.h"
#include "CoreTools/ClassInvariant/NoexceptDetail.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

template <typename AndroidCallBack>
Framework::AndroidProcess<AndroidCallBack>
	::AndroidProcess(int64_t delta)
{
	AndroidCallBackInterfaceSharedPtr androidCallBack{ std::make_shared<AndroidCallBack>(delta) };

	ANDROID_PROCESS_MANAGE_SINGLETON.SetAndroidCallBack(androidCallBack);

	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

template <typename AndroidCallBack>
Framework::AndroidProcess<AndroidCallBack>
	::~AndroidProcess()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;

	CoreTools::NoexceptNoReturn(*this, &ClassType::ClearAndroidCallBack);
}

template <typename AndroidCallBack>
void Framework::AndroidProcess<AndroidCallBack>
	::ClearAndroidCallBack()
{
	ANDROID_PROCESS_MANAGE_SINGLETON.ClearAndroidCallBack();
}

#ifdef OPEN_CLASS_INVARIANT
template <typename AndroidCallBack>
bool Framework::AndroidProcess<AndroidCallBack>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename AndroidCallBack>
bool Framework::AndroidProcess<AndroidCallBack>
	::PreCreate()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return ANDROID_PROCESS_MANAGE_SINGLETON.PreCreate();
}

template <typename AndroidCallBack>
bool Framework::AndroidProcess<AndroidCallBack>
	::Initialize()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return ANDROID_PROCESS_MANAGE_SINGLETON.Initialize();;
}

template <typename AndroidCallBack>
void Framework::AndroidProcess<AndroidCallBack>
	::PreIdle()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	ANDROID_PROCESS_MANAGE_SINGLETON.PreIdle();
}

template <typename AndroidCallBack>
void Framework::AndroidProcess<AndroidCallBack>
	::Terminate()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	ANDROID_PROCESS_MANAGE_SINGLETON.Terminate();
}

template <typename AndroidCallBack>
typename Framework::AndroidProcess<AndroidCallBack>::AppCmd Framework::AndroidProcess<AndroidCallBack>
	::GetAppCmd() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return ANDROID_PROCESS_MANAGE_SINGLETON.GetAppCmd();
}

template <typename AndroidCallBack>
typename Framework::AndroidProcess<AndroidCallBack>::InputEvent Framework::AndroidProcess<AndroidCallBack>
	::GetInputEvent() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return ANDROID_PROCESS_MANAGE_SINGLETON.GetInputEvent();
}

template <typename AndroidCallBack>
typename Framework::AndroidProcess<AndroidCallBack>::Display Framework::AndroidProcess<AndroidCallBack>
	::GetDisplay() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return ANDROID_PROCESS_MANAGE_SINGLETON.GetDisplay();
}

#endif // FRAMEWORK_ANDROID_FRAME_ANDROID_PROCESS_DETAIL_H
