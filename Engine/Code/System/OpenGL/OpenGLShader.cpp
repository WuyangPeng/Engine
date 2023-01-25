///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.0 (2023/01/12 22:43)

#include "System/SystemExport.h"

#include "OpenGLShader.h"
#include "Flags/OpenGLShaderFlags.h"
#include "Detail/GL20Extensions.h"
#include "Detail/GL43Extensions.h"
#include "System/Helper/EnumCast.h"

#include <vector>

using namespace std::literals;

bool System::IsGLShader(OpenGLUInt shader) noexcept
{
    if (GLIsShader(shader) != GL_FALSE)
        return true;
    else
        return false;
}

void System::AttachGLShader(OpenGLUInt program, OpenGLUInt shader) noexcept
{
    GLAttachShader(program, shader);
}

void System::GetAttachedGLShaders(OpenGLUInt program, OpenGLSize maxCount, OpenGLSize* count, OpenGLUInt* shaders) noexcept
{
    GLGetAttachedShaders(program, maxCount, count, shaders);
}

void System::DetachGLShader(OpenGLUInt program, OpenGLUInt shader) noexcept
{
    GLDetachShader(program, shader);
}

void System::DeleteGLShader(OpenGLUInt shader) noexcept
{
    GLDeleteShader(shader);
}

System::OpenGLUInt System::CreateGLShader(ShaderType type) noexcept
{
    return GLCreateShader(EnumCastUnderlying(type));
}

void System::SetGLShaderSource(OpenGLUInt shader, OpenGLSize count, const OpenGLChar* const* string, const OpenGLInt* length) noexcept
{
    GLShaderSource(shader, count, string, length);
}

void System::CompileGLShader(OpenGLUInt shader) noexcept
{
    GLCompileShader(shader);
}

void System::GetGLShaderSource(OpenGLUInt shader, OpenGLSize bufSize, OpenGLSize* length, OpenGLChar* source) noexcept
{
    GLGetShaderSource(shader, bufSize, length, source);
}

bool System::GetGLShader(OpenGLUInt shader, ShaderStatus pname) noexcept
{
    OpenGLInt params{};
    GLGetShaderiv(shader, EnumCastUnderlying(pname), &params);

    return params != GL_FALSE;
}

int System::GetGLShader(OpenGLUInt shader, ShaderAttributes pname) noexcept
{
    OpenGLInt params{};
    GLGetShaderiv(shader, EnumCastUnderlying(pname), &params);

    return params;
}

std::string System::GetGLShaderInfoLog(OpenGLUInt shader)
{
    const auto logLength = GetGLShader(shader, ShaderAttributes::InfoLogLength);

    if (0 < logLength)
    {
        std::vector<OpenGLChar> log(logLength);
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

System::OpenGLInt System::GetGLUniformLocation(OpenGLUInt program, const OpenGLChar* name) noexcept
{
    return GLGetUniformLocation(program, name);
}
