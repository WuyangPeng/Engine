/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/03 00:12)

#include "System/SystemExport.h"

#include "OpenGLShader.h"
#include "Flags/OpenGLShaderFlags.h"
#include "Detail/GL20Extensions.h"
#include "Detail/GL43Extensions.h"
#include "System/Helper/EnumCast.h"

#include <vector>

using namespace std::literals;

bool System::IsGLShader(OpenGLUnsignedInt shader) noexcept
{
    return GLIsShader(shader) != GL_FALSE;
}

void System::AttachGLShader(OpenGLUnsignedInt program, OpenGLUnsignedInt shader) noexcept
{
    GLAttachShader(program, shader);
}

void System::GetAttachedGLShaders(OpenGLUnsignedInt program, OpenGLSize maxCount, OpenGLSize* count, OpenGLUnsignedInt* shaders) noexcept
{
    GLGetAttachedShaders(program, maxCount, count, shaders);
}

void System::DetachGLShader(OpenGLUnsignedInt program, OpenGLUnsignedInt shader) noexcept
{
    GLDetachShader(program, shader);
}

void System::DeleteGLShader(OpenGLUnsignedInt shader) noexcept
{
    GLDeleteShader(shader);
}

System::OpenGLUnsignedInt System::CreateGLShader(ShaderType type) noexcept
{
    return GLCreateShader(EnumCastUnderlying(type));
}

void System::SetGLShaderSource(OpenGLUnsignedInt shader, OpenGLSize count, const OpenGLChar* const* string, const OpenGLInt* length) noexcept
{
    GLShaderSource(shader, count, string, length);
}

void System::CompileGLShader(OpenGLUnsignedInt shader) noexcept
{
    GLCompileShader(shader);
}

void System::GetGLShaderSource(OpenGLUnsignedInt shader, OpenGLSize bufSize, OpenGLSize* length, OpenGLChar* source) noexcept
{
    GLGetShaderSource(shader, bufSize, length, source);
}

bool System::GetGLShader(OpenGLUnsignedInt shader, ShaderStatus pName) noexcept
{
    OpenGLInt params{};
    GLGetShaderIv(shader, EnumCastUnderlying(pName), &params);

    return params != GL_FALSE;
}

int System::GetGLShader(OpenGLUnsignedInt shader, ShaderAttributes pName) noexcept
{
    OpenGLInt params{};
    GLGetShaderIv(shader, EnumCastUnderlying(pName), &params);

    return params;
}

std::string System::GetGLShaderInfoLog(OpenGLUnsignedInt shader)
{
    if (const auto logLength = GetGLShader(shader, ShaderAttributes::InfoLogLength);
        0 < logLength)
    {
        LogInfoType log(logLength);
        auto numWritten = 0;
        GLGetShaderInfoLog(shader, logLength, &numWritten, log.data());
        std::string message{ log.begin(), log.end() };

        return message;
    }
    else if (logLength == 0)
    {
        return ""s;
    }
    else
    {
        return "日志信息长度无效。"s;
    }
}

System::OpenGLInt System::GetGLUniformLocation(OpenGLUnsignedInt program, const OpenGLChar* name) noexcept
{
    return GLGetUniformLocation(program, name);
}

void System::SetGLShaderStorageBlockBinding(OpenGLUnsignedInt program, OpenGLUnsignedInt storageBlockIndex, OpenGLUnsignedInt storageBlockBinding) noexcept
{
    GLShaderStorageBlockBinding(program, storageBlockIndex, storageBlockBinding);
}
