///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/11 14:23)

#ifndef FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_PROCESS_ANDROID_CALLBACK_INTERFACE_H
#define FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_PROCESS_ANDROID_CALLBACK_INTERFACE_H

#include "Framework/AndroidFrame/AndroidCallBackInterface.h"
#include "Framework/AndroidFrame/AndroidProcess.h"

namespace Framework
{
    class AndroidProcessAndroidCallBackInterface final : public AndroidCallBackInterface
    {
    public:
        using ClassType = AndroidProcessAndroidCallBackInterface;
        using ParentType = AndroidCallBackInterface;

    public:
        explicit AndroidProcessAndroidCallBackInterface(int64_t delta) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };

    template <>
    AndroidProcess<AndroidProcessAndroidCallBackInterface>::AndroidProcess(int64_t delta);

    template <>
    AndroidProcess<AndroidProcessAndroidCallBackInterface>::~AndroidProcess() noexcept;
}

#endif  // FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_PROCESS_ANDROID_CALLBACK_INTERFACE_H