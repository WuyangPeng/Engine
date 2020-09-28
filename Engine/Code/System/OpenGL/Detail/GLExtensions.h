//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 15:40)

#ifndef SYSTEM_GL_EXTENSIONS_H
#define SYSTEM_GL_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h"

namespace System
{
    SYSTEM_HIDDEN_DECLARE const char* GetVendorString() noexcept;
    SYSTEM_HIDDEN_DECLARE const char* GetRendererString() noexcept;
    SYSTEM_HIDDEN_DECLARE const char* GetVersionString() noexcept;
    SYSTEM_HIDDEN_DECLARE const char* GetExtensionString() noexcept;
    SYSTEM_HIDDEN_DECLARE bool InitGL(bool printInfo = true);
    SYSTEM_HIDDEN_DECLARE void PrintOpenGLInfo();
}

#endif  // SYSTEM_GL_EXTENSIONS_H
