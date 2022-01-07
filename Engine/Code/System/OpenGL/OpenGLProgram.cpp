///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 14:09)

#include "System/SystemExport.h"

#include "OpenGLProgram.h"
#include "Flags/OpenGLProgramFlags.h"
#include "Detail/GL20Extensions.h"
#include "Detail/GL43Extensions.h"
#include "System/Helper/EnumCast.h"

#include <vector>

using std::string;
using std::vector;
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

int System::GetGLProgram(OpenGLUInt program, ProgramAttributes pname) noexcept
{
    OpenGLInt params{};
    GLGetProgramiv(program, EnumCastUnderlying(pname), &params);

    return params;
}

string System::GetGLProgramInfoLog(OpenGLUInt program)
{
    const auto logLength = GetGLProgram(program, ProgramAttributes::InfoLogLength);

    if (0 < logLength)
    {
        vector<GLchar> log(logLength);
        auto numWritten = 0;
        GLGetProgramInfoLog(program, logLength, &numWritten, log.data());
        string message{ log.begin(), log.end() };

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
