///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.5 (2021/06/24 23:25)

#ifndef SYSTEM_OPENGL_OPENGL_API_H
#define SYSTEM_OPENGL_OPENGL_API_H

#include "System/SystemDll.h"

#include "Fwd/OpenGLFlagsFwd.h"
#include "Using/OpenGLUsing.h"
#include "System/Helper/GLExtensionsMacro.h"

namespace System
{
    void SYSTEM_DEFAULT_DECLARE ClearAllGLBufferBit() noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLViewport(OpenGLInt x, OpenGLInt y, OpenGLSize width, OpenGLSize height) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetupRenderStatus() noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDepthRange(OpenGLDouble nearDepthRange, OpenGLDouble farDepthRange) noexcept;

    NODISCARD OpenGLInt SYSTEM_DEFAULT_DECLARE GetGLInteger(OpenGLQuery name) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetGLBoolean(OpenGLQuery name) noexcept;
    NODISCARD OpenGLFloat SYSTEM_DEFAULT_DECLARE GetGLFloat(OpenGLQuery name) noexcept;
    NODISCARD OpenGLDouble SYSTEM_DEFAULT_DECLARE GetGLDouble(OpenGLQuery name) noexcept; 
}

#endif  // SYSTEM_OPENGL_OPENGL_API_H