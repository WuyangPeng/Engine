//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 15:39)

#ifndef SYSTEM_OPENGL_GL_44_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_44_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/Detail/OpenGL/GL44ExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    // OpenGL 4.4

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsOpenGL44() noexcept;

    void InitOpenGL44() noexcept;
}

#endif  // SYSTEM_OPENGL_GL_44_EXTENSIONS_H
