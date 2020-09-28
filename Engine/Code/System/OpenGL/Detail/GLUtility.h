//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/25 15:41)

#ifndef SYSTEM_OPENGL_GL_UTILITY_H
#define SYSTEM_OPENGL_GL_UTILITY_H

#include "System/SystemDll.h"

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/GL11ExtensionsUsing.h"

namespace System
{
    // �����顣
    const char* SYSTEM_HIDDEN_DECLARE GetOpenGLErrorString(OpenGLErrorCode code) noexcept;

    OpenGLSystemVersion SYSTEM_HIDDEN_DECLARE GetOpenGLVersion(char major, char minor) noexcept;
    int SYSTEM_HIDDEN_DECLARE ToIndex(char index) noexcept;
}

extern "C"
{
    // ÿ��ƽ̨����ʵ�����������
    void* SYSTEM_HIDDEN_DECLARE GetOpenGLFunctionPointer(const char* glFunction) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_UTILITY_H
