///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.4 (2022/11/19 18:17)

#ifndef SYSTEM_OPENGL_GL_UTILITY_H
#define SYSTEM_OPENGL_GL_UTILITY_H

#include "System/SystemDll.h"

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    // �����顣
    SYSTEM_HIDDEN_DECLARE NODISCARD const char* GetOpenGLErrorString(OpenGLErrorCode code) noexcept;

    NODISCARD OpenGLSystemVersion SYSTEM_HIDDEN_DECLARE GetOpenGLVersion(int major, int minor) noexcept;

    SYSTEM_HIDDEN_DECLARE void PrintExtensionsInfo(const char* extensions);

    // ÿ��ƽ̨����ʵ�����������
    MAYBE_NULLPTR void* SYSTEM_HIDDEN_DECLARE GetOpenGLFunctionPointer(const char* glFunction) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_UTILITY_H
