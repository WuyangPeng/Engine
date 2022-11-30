///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 18:31)

#ifndef SYSTEM_OPENGL_OPENGL_INIT_H
#define SYSTEM_OPENGL_OPENGL_INIT_H

#include "System/SystemDll.h"

#include <string>

namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE OpenGLInit();

    SYSTEM_DEFAULT_DECLARE void PrintOpenGLInfo();
    SYSTEM_DEFAULT_DECLARE void PrintWglExtensionsInfo();

    SYSTEM_DEFAULT_DECLARE NODISCARD std::string GetOpenGLVendorString();
    SYSTEM_DEFAULT_DECLARE NODISCARD std::string GetOpenGLVersionString();
    SYSTEM_DEFAULT_DECLARE NODISCARD std::string GetOpenGLRendererString();
    SYSTEM_DEFAULT_DECLARE NODISCARD std::string GetOpenGLShadingLanguageVersion();
}

#endif  // SYSTEM_OPENGL_OPENGL_INIT_H
