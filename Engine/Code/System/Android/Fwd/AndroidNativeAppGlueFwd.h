// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2019/12/31 15:22)

#ifndef SYSTEM_ANDROID_ANDROID_NATIVE_APP_GLUE_FWD_H
#define SYSTEM_ANDROID_ANDROID_NATIVE_APP_GLUE_FWD_H 

#include "System/Helper/UnicodeUsing.h"
#include "System/Android/Using/AndroidNativeAppGlueUsing.h"

#include <string>

namespace System
{
	void AppDummy() noexcept;
	WindowHWnd CreateVirtualWindow(AndroidApp* androidApp, const String& appName) noexcept;
}

#endif // SYSTEM_ANDROID_ANDROID_NATIVE_APP_GLUE_FWD_H