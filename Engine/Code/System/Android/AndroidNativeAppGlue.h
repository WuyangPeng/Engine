///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.6 (2021/07/11 14:29)

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
    NODISCARD WindowsHWnd SYSTEM_DEFAULT_DECLARE CreateVirtualWindow(AndroidApp* androidApp, const String& appName, AndroidApp::AppCmd appCmd, AndroidApp::InputEvent inputEvent);
}

#endif  // SYSTEM_ANDROID_ANDROID_NATIVE_APP_GLUE_H
