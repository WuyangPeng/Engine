///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/09 20:47)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_PROCESS_DETAIL_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_PROCESS_DETAIL_H

#include "AndroidProcess.h"
#include "AndroidProcessManager.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

template <typename AndroidCallBack>
Framework::AndroidProcess<AndroidCallBack>::AndroidProcess(int64_t delta)
{
    auto androidCallBack = std::make_shared<AndroidCallBack>(delta);

    ANDROID_PROCESS_MANAGE_SINGLETON.SetAndroidCallBack(androidCallBack);

    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

template <typename AndroidCallBack>
Framework::AndroidProcess<AndroidCallBack>::~AndroidProcess() noexcept
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;

    CoreTools::NoexceptNoReturn(*this, &ClassType::ClearAndroidCallBack);
}

template <typename AndroidCallBack>
void Framework::AndroidProcess<AndroidCallBack>::ClearAndroidCallBack()
{
    ANDROID_PROCESS_MANAGE_SINGLETON.ClearAndroidCallBack();
}

#ifdef OPEN_CLASS_INVARIANT

template <typename AndroidCallBack>
bool Framework::AndroidProcess<AndroidCallBack>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename AndroidCallBack>
bool Framework::AndroidProcess<AndroidCallBack>::PreCreate()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ANDROID_PROCESS_MANAGE_SINGLETON.PreCreate();
}

template <typename AndroidCallBack>
bool Framework::AndroidProcess<AndroidCallBack>::Initialize()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ANDROID_PROCESS_MANAGE_SINGLETON.Initialize();
}

template <typename AndroidCallBack>
void Framework::AndroidProcess<AndroidCallBack>::PreIdle()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    ANDROID_PROCESS_MANAGE_SINGLETON.PreIdle();
}

template <typename AndroidCallBack>
void Framework::AndroidProcess<AndroidCallBack>::Terminate()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    ANDROID_PROCESS_MANAGE_SINGLETON.Terminate();
}

template <typename AndroidCallBack>
typename Framework::AndroidProcess<AndroidCallBack>::AppCmd Framework::AndroidProcess<AndroidCallBack>::GetAppCmd() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return AndroidProcessManager::GetAppCmd();
}

template <typename AndroidCallBack>
typename Framework::AndroidProcess<AndroidCallBack>::InputEvent Framework::AndroidProcess<AndroidCallBack>::GetInputEvent() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return AndroidProcessManager::GetInputEvent();
}

template <typename AndroidCallBack>
typename Framework::AndroidProcess<AndroidCallBack>::Display Framework::AndroidProcess<AndroidCallBack>::GetDisplay() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return AndroidProcessManager::GetDisplay();
}

#endif  // FRAMEWORK_ANDROID_FRAME_ANDROID_PROCESS_DETAIL_H
