/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.6 (2024/02/29 09:29)

#ifndef SYSTEM_OPENGL_GL_UTILITY_H
#define SYSTEM_OPENGL_GL_UTILITY_H

#include "System/SystemDll.h"

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    /// �����顣
    SYSTEM_HIDDEN_DECLARE NODISCARD const char* GetOpenGLErrorString(OpenGLErrorCode code) noexcept;

    NODISCARD OpenGLSystemVersion SYSTEM_HIDDEN_DECLARE GetOpenGLVersion(int major, int minor) noexcept;

    SYSTEM_HIDDEN_DECLARE void PrintExtensionsInfo(const char* extensions);
}

#endif  // SYSTEM_OPENGL_GL_UTILITY_H
