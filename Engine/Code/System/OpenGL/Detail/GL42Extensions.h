//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/25 15:38)

#ifndef SYSTEM_OPENGL_GL_42_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_42_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/Detail/OpenGL/GL42ExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    // OpenGL 4.2

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsOpenGL42() noexcept;

    void InitOpenGL42() noexcept;
}

#endif  // SYSTEM_OPENGL_GL_42_EXTENSIONS_H
