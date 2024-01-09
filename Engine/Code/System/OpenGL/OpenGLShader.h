/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 17:11)

#ifndef SYSTEM_OPENGL_OPENGL_SHADER_H
#define SYSTEM_OPENGL_OPENGL_SHADER_H

#include "System/SystemDll.h"

#include "Fwd/OpenGLFlagsFwd.h"
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

    void SYSTEM_DEFAULT_DECLARE CompileGLShader(OpenGLUInt shader) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLShaderSource(OpenGLUInt shader, OpenGLSize count, const OpenGLChar* const* string, const OpenGLInt* length) noexcept;
    void SYSTEM_DEFAULT_DECLARE GetGLShaderSource(OpenGLUInt shader, OpenGLSize bufSize, OpenGLSize* length, OpenGLChar* source) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetGLShader(OpenGLUInt shader, ShaderStatus pName) noexcept;
    NODISCARD int SYSTEM_DEFAULT_DECLARE GetGLShader(OpenGLUInt shader, ShaderAttributes pName) noexcept;
    NODISCARD std::string SYSTEM_DEFAULT_DECLARE GetGLShaderInfoLog(OpenGLUInt shader);

    NODISCARD OpenGLInt SYSTEM_DEFAULT_DECLARE GetGLUniformLocation(OpenGLUInt program, const OpenGLChar* name) noexcept;
    SYSTEM_DEFAULT_DECLARE void SetGLShaderStorageBlockBinding(OpenGLUInt program, OpenGLUInt storageBlockIndex, OpenGLUInt storageBlockBinding) noexcept;
}

#endif  // SYSTEM_OPENGL_OPENGL_SHADER_H