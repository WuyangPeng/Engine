/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/03/01 17:36)

#ifndef SYSTEM_OPENGL_OPENGL_PROGRAM_H
#define SYSTEM_OPENGL_OPENGL_PROGRAM_H

#include "System/SystemDll.h"

#include "Fwd/OpenGLFlagsFwd.h"
#include "Using/OpenGLUsing.h"

#include <string>

namespace System
{
    NODISCARD OpenGLUInt SYSTEM_DEFAULT_DECLARE CreateGLProgram() noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsGLProgram(OpenGLUInt program) noexcept;
    void SYSTEM_DEFAULT_DECLARE DeleteGLProgram(OpenGLUInt program) noexcept;

    void SYSTEM_DEFAULT_DECLARE LinkGLProgram(OpenGLUInt program) noexcept;
    NODISCARD std::string SYSTEM_DEFAULT_DECLARE GetGLProgramInfoLog(OpenGLUInt program);

    void SYSTEM_DEFAULT_DECLARE ValidateGLProgram(OpenGLUInt program) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetGLProgram(OpenGLUInt program, ProgramStatus pName) noexcept;
    NODISCARD int SYSTEM_DEFAULT_DECLARE GetGLProgram(OpenGLUInt program, ProgramAttributes pName) noexcept;
    void SYSTEM_DEFAULT_DECLARE GetGLProgram(OpenGLUInt program, ProgramAttributes pName, ComputeWorkGroupSizeType& params) noexcept;

    NODISCARD int SYSTEM_DEFAULT_DECLARE GetGLProgramInterface(OpenGLUInt program, ProgramInterface programInterface, ProgramInterfaceName pName) noexcept;
    void SYSTEM_DEFAULT_DECLARE GetGLProgramResource(OpenGLUInt program, ProgramInterface programInterface, OpenGLUInt index, OpenGLSize propCount, const OpenGLEnum* props, OpenGLSize bufSize, OpenGLSize* length, OpenGLInt* params) noexcept;
    void SYSTEM_DEFAULT_DECLARE GetGLProgramResourceName(OpenGLUInt program, ProgramInterface programInterface, OpenGLUInt index, OpenGLSize bufSize, OpenGLSize* length, OpenGLChar* name) noexcept;
    NODISCARD OpenGLUInt SYSTEM_DEFAULT_DECLARE GetGLProgramResourceIndex(OpenGLUInt program, ProgramInterface programInterface, const OpenGLChar* name) noexcept;

    SYSTEM_DEFAULT_DECLARE void SetUseProgram(OpenGLUInt program) noexcept;

    SYSTEM_DEFAULT_DECLARE void SetGLDispatchCompute(int numXGroups, int numYGroups, int numZGroups) noexcept;

    SYSTEM_DEFAULT_DECLARE void SetGLUniform1(OpenGLInt location, OpenGLInt unit) noexcept;
}

#endif  // SYSTEM_OPENGL_OPENGL_PROGRAM_H