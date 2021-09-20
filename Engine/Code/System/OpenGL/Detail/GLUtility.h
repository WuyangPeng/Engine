///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.5 (2021/06/12 18:23)

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
