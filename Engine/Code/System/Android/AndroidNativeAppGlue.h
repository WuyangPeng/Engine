///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/12 9:33)

#ifndef SYSTEM_ANDROID_ANDROID_NATIVE_APP_GLUE_H
#define SYSTEM_ANDROID_ANDROID_NATIVE_APP_GLUE_H

#include "System/SystemDll.h"

#include "Using/AndroidNativeAppGlueUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

#include <string>

namespace System
{
    void SYSTEM_DEFAULT_DECLARE AppDummy() noexcept;
    MAYBE_NULLPTR WindowsHWnd SYSTEM_DEFAULT_DECLARE CreateVirtualWindow(AndroidApp* androidApp,
                                                                         const String& appName,
                                                                         AppCommand appCommand,
                                                                         InputEvent inputEvent);
}

#endif  // SYSTEM_ANDROID_ANDROID_NATIVE_APP_GLUE_H
