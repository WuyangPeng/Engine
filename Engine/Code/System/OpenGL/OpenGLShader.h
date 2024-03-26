/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/03/01 17:37)

#ifndef SYSTEM_OPENGL_OPENGL_SHADER_H
#define SYSTEM_OPENGL_OPENGL_SHADER_H

#include "System/SystemDll.h"

#include "Fwd/OpenGLFlagsFwd.h"
#include "Using/OpenGLUsing.h"

#include <string>

namespace System
{
    NODISCARD OpenGLUnsignedInt SYSTEM_DEFAULT_DECLARE CreateGLShader(ShaderType type) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsGLShader(OpenGLUnsignedInt shader) noexcept;
    void SYSTEM_DEFAULT_DECLARE DeleteGLShader(OpenGLUnsignedInt shader) noexcept;

    void SYSTEM_DEFAULT_DECLARE AttachGLShader(OpenGLUnsignedInt program, OpenGLUnsignedInt shader) noexcept;
    void SYSTEM_DEFAULT_DECLARE GetAttachedGLShaders(OpenGLUnsignedInt program, OpenGLSize maxCount, OpenGLSize* count, OpenGLUnsignedInt* shaders) noexcept;
    void SYSTEM_DEFAULT_DECLARE DetachGLShader(OpenGLUnsignedInt program, OpenGLUnsignedInt shader) noexcept;

    void SYSTEM_DEFAULT_DECLARE CompileGLShader(OpenGLUnsignedInt shader) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLShaderSource(OpenGLUnsignedInt shader, OpenGLSize count, const OpenGLChar* const* string, const OpenGLInt* length) noexcept;
    void SYSTEM_DEFAULT_DECLARE GetGLShaderSource(OpenGLUnsignedInt shader, OpenGLSize bufSize, OpenGLSize* length, OpenGLChar* source) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetGLShader(OpenGLUnsignedInt shader, ShaderStatus pName) noexcept;
    NODISCARD int SYSTEM_DEFAULT_DECLARE GetGLShader(OpenGLUnsignedInt shader, ShaderAttributes pName) noexcept;
    NODISCARD std::string SYSTEM_DEFAULT_DECLARE GetGLShaderInfoLog(OpenGLUnsignedInt shader);

    NODISCARD OpenGLInt SYSTEM_DEFAULT_DECLARE GetGLUniformLocation(OpenGLUnsignedInt program, const OpenGLChar* name) noexcept;
    SYSTEM_DEFAULT_DECLARE void SetGLShaderStorageBlockBinding(OpenGLUnsignedInt program, OpenGLUnsignedInt storageBlockIndex, OpenGLUnsignedInt storageBlockBinding) noexcept;
}

#endif  // SYSTEM_OPENGL_OPENGL_SHADER_H