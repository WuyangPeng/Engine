///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 11:35)

#ifndef SYSTEM_OPENGL_OPENGL_SHADER_H
#define SYSTEM_OPENGL_OPENGL_SHADER_H

#include "System/SystemDll.h"

#include "Fwd/OpenGLShaderFlagsFwd.h"
#include "Using/OpenGLUsing.h"

#include <string>

namespace System
{
    NODISCARD OpenGLUInt SYSTEM_DEFAULT_DECLARE CreateGLShader(ShaderType type) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsGLShader(OpenGLUInt shader) noexcept;
    void SYSTEM_DEFAULT_DECLARE DeleteGLShader(OpenGLUInt shader) noexcept;

    void SYSTEM_DEFAULT_DECLARE AttachGLShader(OpenGLUInt program, OpenGLUInt shader) noexcept;
    void SYSTEM_DEFAULT_DECLARE GetAttachedGLShaders(OpenGLUInt program, OpenGLSize maxCount, OpenGLSize* count, OpenGLUInt* shaders) noexcept;
    void SYSTEM_DEFAULT_DECLARE DetachGLShader(OpenGLUInt program, OpenGLUInt shader) noexcept;

    void SYSTEM_DEFAULT_DECLARE GetGLShaderSource(OpenGLUInt shader, OpenGLSize count, const OpenGLChar* const* string, const OpenGLInt* length) noexcept;
    void SYSTEM_DEFAULT_DECLARE CompileGLShader(OpenGLUInt shader) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetGLShader(OpenGLUInt shader, ShaderStatus pname) noexcept;
    NODISCARD int SYSTEM_DEFAULT_DECLARE GetGLShader(OpenGLUInt shader, ShaderAttributes pname) noexcept;
    std::string SYSTEM_DEFAULT_DECLARE GetGLShaderInfoLog(OpenGLUInt shader);

    NODISCARD OpenGLInt SYSTEM_DEFAULT_DECLARE GetGLUniformLocation(OpenGLUInt program, const OpenGLChar* name) noexcept;
}

#endif  // SYSTEM_OPENGL_OPENGL_SHADER_H