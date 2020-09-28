//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 18:44)

#ifndef SYSTEM_ANDROID_ANDROID_NATIVE_APP_GLUE_H
#define SYSTEM_ANDROID_ANDROID_NATIVE_APP_GLUE_H

#include "System/SystemDll.h"

#include "Using/AndroidNativeAppGlueUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"

#include <string>

namespace System
{
    void SYSTEM_DEFAULT_DECLARE AppDummy() noexcept;
    [[nodiscard]] WindowHWnd SYSTEM_DEFAULT_DECLARE CreateVirtualWindow(AndroidApp* androidApp, const String& appName);
}

#endif  // SYSTEM_ANDROID_ANDROID_NATIVE_APP_GLUE_H
