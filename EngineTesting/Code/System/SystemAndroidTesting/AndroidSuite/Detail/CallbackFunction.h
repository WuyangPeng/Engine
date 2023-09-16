///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 13:47)

#ifndef SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_LOOPER_CALLBACK_FUNCTION_H
#define SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_LOOPER_CALLBACK_FUNCTION_H

#include "System/Android/Using/AndroidInputUsing.h"

namespace System::Android::Looper
{
    NODISCARD int CallbackFunction(int fd, int events, void* data) noexcept;
}

#endif  // SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_LOOPER_CALLBACK_FUNCTION_H
