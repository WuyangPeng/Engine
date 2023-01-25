///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.0 (2023/01/12 22:42)

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
