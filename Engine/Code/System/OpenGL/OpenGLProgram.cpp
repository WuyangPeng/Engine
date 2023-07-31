///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.0 (2023/01/12 22:43)

#include "System/SystemExport.h"

#include "OpenGLProgram.h"
#include "Flags/OpenGLProgramFlags.h"
#include "Detail/GL20Extensions.h"
#include "Detail/GL43Extensions.h"
#include "System/Helper/EnumCast.h"

#include <vector>

using namespace std::literals;

System::OpenGLUInt System::CreateGLProgram() noexcept
{
    return GLCreateProgram();
}

bool System::IsGLProgram(OpenGLUInt program) noexcept
{
    if (GLIsProgram(program) != GL_FALSE)
        return true;
    else
        return false;
}

void System::DeleteGLProgram(OpenGLUInt program) noexcept
{
    GLDeleteProgram(program);
}

void System::ValidateGLProgram(OpenGLUInt program) noexcept
{
    GLValidateProgram(program);
}

void System::LinkGLProgram(OpenGLUInt program) noexcept
{
    GLLinkProgram(program);
}

bool System::GetGLProgram(OpenGLUInt program, ProgramStatus pname) noexcept
{
    OpenGLInt params{};
    GLGetProgramiv(program, EnumCastUnderlying(pname), &params);

    return params != GL_FALSE;
}

void System::GetGLProgram(OpenGLUInt program, ProgramAttributes pname, ComputeWorkGroupSizeType& params) noexcept
{
    GLGetProgramiv(program, EnumCastUnderlying(pname), params.data());
}

int System::GetGLProgram(OpenGLUInt program, ProgramAttributes pname) noexcept
{
    OpenGLInt params{};
    GLGetProgramiv(program, EnumCastUnderlying(pname), &params);

    return params;
}

std::string System::GetGLProgramInfoLog(OpenGLUInt program)
{
    const auto logLength = GetGLProgram(program, ProgramAttributes::InfoLogLength);

    if (0 < logLength)
    {
        std::vector<OpenGLChar> log(logLength);
        auto numWritten = 0;
        GLGetProgramInfoLog(program, logLength, &numWritten, log.data());
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

int System::GetGLProgramInterface(OpenGLUInt program, ProgramInterface programInterface, ProgramInterfaceName pname) noexcept
{
    auto result = 0;
    GLGetProgramInterfaceiv(program, EnumCastUnderlying(programInterface), EnumCastUnderlying(pname), &result);

    return result;
}

void System::GetGLProgramResource(OpenGLUInt program, ProgramInterface programInterface, OpenGLUInt index, OpenGLSize propCount, const OpenGLEnum* props, OpenGLSize bufSize, OpenGLSize* length, OpenGLInt* params) noexcept
{
    GLGetProgramResourceiv(program, EnumCastUnderlying(programInterface), index, propCount, props, bufSize, length, params);
}

void System::GetGLProgramResourceName(OpenGLUInt program, ProgramInterface programInterface, OpenGLUInt index, OpenGLSize bufSize, OpenGLSize* length, OpenGLChar* name) noexcept
{
    GLGetProgramResourceName(program, EnumCastUnderlying(programInterface), index, bufSize, length, name);
}

System::OpenGLUInt System::GetGLProgramResourceIndex(OpenGLUInt program, ProgramInterface programInterface, const OpenGLChar* name) noexcept
{
    return GLGetProgramResourceIndex(program, EnumCastUnderlying(programInterface), name);
}

void System::SetUseProgram(OpenGLUInt program) noexcept
{
    GLUseProgram(program);
}