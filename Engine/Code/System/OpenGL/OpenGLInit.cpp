//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/26 15:32)

#include "System/SystemExport.h"

#include "OpenGLInit.h"
#include "Detail/GLExtensions.h"
#include "Detail/GlxExtensions.h"
#include "Detail/WglExtensions.h"

bool System::OpenGLInit()
{
#ifdef SYSTEM_PLATFORM_WIN32
    return InitWGL();
#elif defined(SYSTEM_PLATFORM_LINUX)
    return InitGLX();
#else  // !SYSTEM_PLATFORM_WIN32 && !SYSTEM_PLATFORM_LINUX
    return InitGL();
#endif  // SYSTEM_PLATFORM_WIN32
}
