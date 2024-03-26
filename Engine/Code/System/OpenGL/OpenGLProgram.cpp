/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/03 00:12)

#include "System/SystemExport.h"

#include "OpenGLProgram.h"
#include "Flags/OpenGLProgramFlags.h"
#include "Detail/GL20Extensions.h"
#include "Detail/GL31Extensions.h"
#include "Detail/GL43Extensions.h"
#include "System/Helper/EnumCast.h"

#include <vector>

using namespace std::literals;

System::OpenGLUnsignedInt System::CreateGLProgram() noexcept
{
    return GLCreateProgram();
}

bool System::IsGLProgram(OpenGLUnsignedInt program) noexcept
{
    return GLIsProgram(program) != GL_FALSE;
}

void System::DeleteGLProgram(OpenGLUnsignedInt program) noexcept
{
    GLDeleteProgram(program);
}

void System::ValidateGLProgram(OpenGLUnsignedInt program) noexcept
{
    GLValidateProgram(program);
}

void System::LinkGLProgram(OpenGLUnsignedInt program) noexcept
{
    GLLinkProgram(program);
}

bool System::GetGLProgram(OpenGLUnsignedInt program, ProgramStatus pName) noexcept
{
    OpenGLInt params{};
    GLGetProgramIv(program, EnumCastUnderlying(pName), &params);

    return params != GL_FALSE;
}

void System::GetGLProgram(OpenGLUnsignedInt program, ProgramAttributes pName, ComputeWorkGroupSizeType& params) noexcept
{
    GLGetProgramIv(program, EnumCastUnderlying(pName), params.data());
}

System::ComputeWorkGroupSizeType System::GetComputeWorkGroupSize(OpenGLUnsignedInt program) noexcept
{
    ComputeWorkGroupSizeType result{};
    GetGLProgram(program, ProgramAttributes::ComputeWorkGroupSize, result);

    return result;
}

int System::GetGLProgram(OpenGLUnsignedInt program, ProgramAttributes pName) noexcept
{
    OpenGLInt params{};
    GLGetProgramIv(program, EnumCastUnderlying(pName), &params);

    return params;
}

std::string System::GetGLProgramInfoLog(OpenGLUnsignedInt program)
{
    if (const auto logLength = GetGLProgram(program, ProgramAttributes::InfoLogLength);
        0 < logLength)
    {
        LogInfoType log(logLength);
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

int System::GetGLProgramInterface(OpenGLUnsignedInt program, ProgramInterface programInterface, ProgramInterfaceName pName) noexcept
{
    auto result = 0;
    GLGetProgramInterfaceIv(program, EnumCastUnderlying(programInterface), EnumCastUnderlying(pName), &result);

    return result;
}

void System::GetGLProgramResource(OpenGLUnsignedInt program, ProgramInterface programInterface, OpenGLUnsignedInt index, OpenGLSize propCount, const OpenGLEnum* props, OpenGLSize bufSize, OpenGLSize* length, OpenGLInt* params) noexcept
{
    GLGetProgramResourceIv(program, EnumCastUnderlying(programInterface), index, propCount, props, bufSize, length, params);
}

void System::GetGLProgramResourceName(OpenGLUnsignedInt program, ProgramInterface programInterface, OpenGLUnsignedInt index, OpenGLSize bufSize, OpenGLSize* length, OpenGLChar* name) noexcept
{
    GLGetProgramResourceName(program, EnumCastUnderlying(programInterface), index, bufSize, length, name);
}

System::OpenGLUnsignedInt System::GetGLProgramResourceIndex(OpenGLUnsignedInt program, ProgramInterface programInterface, const OpenGLChar* name) noexcept
{
    return GLGetProgramResourceIndex(program, EnumCastUnderlying(programInterface), name);
}

void System::SetUseProgram(OpenGLUnsignedInt program) noexcept
{
    GLUseProgram(program);
}

void System::SetGLDispatchCompute(int numXGroups, int numYGroups, int numZGroups) noexcept
{
    GLDispatchCompute(numXGroups, numYGroups, numZGroups);
}

void System::SetGLUniform1(OpenGLInt location, OpenGLInt unit) noexcept
{
    GLUniform1I(location, unit);
}

void System::SetGLUniformBlockBinding(OpenGLUnsignedInt program, OpenGLUnsignedInt uniformBlockIndex, OpenGLUnsignedInt uniformBlockBinding) noexcept
{
    GLUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding);
}
