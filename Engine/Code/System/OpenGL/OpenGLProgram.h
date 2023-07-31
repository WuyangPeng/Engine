///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.0 (2023/01/12 22:43)

#ifndef SYSTEM_OPENGL_OPENGL_PROGRAM_H
#define SYSTEM_OPENGL_OPENGL_PROGRAM_H

#include "System/SystemDll.h"

#include "Fwd/OpenGLFlagsFwd.h"
#include "Using/OpenGLUsing.h"

#include <array>
#include <string>

namespace System
{
    NODISCARD OpenGLUInt SYSTEM_DEFAULT_DECLARE CreateGLProgram() noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsGLProgram(OpenGLUInt program) noexcept;
    void SYSTEM_DEFAULT_DECLARE DeleteGLProgram(OpenGLUInt program) noexcept;

    void SYSTEM_DEFAULT_DECLARE LinkGLProgram(OpenGLUInt program) noexcept;
    NODISCARD std::string SYSTEM_DEFAULT_DECLARE GetGLProgramInfoLog(OpenGLUInt program);

    void SYSTEM_DEFAULT_DECLARE ValidateGLProgram(OpenGLUInt program) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetGLProgram(OpenGLUInt program, ProgramStatus pname) noexcept;
    NODISCARD int SYSTEM_DEFAULT_DECLARE GetGLProgram(OpenGLUInt program, ProgramAttributes pname) noexcept;
    void SYSTEM_DEFAULT_DECLARE GetGLProgram(OpenGLUInt program, ProgramAttributes pname, ComputeWorkGroupSizeType& params) noexcept;

    NODISCARD int SYSTEM_DEFAULT_DECLARE GetGLProgramInterface(OpenGLUInt program, ProgramInterface programInterface, ProgramInterfaceName pname) noexcept;
    void SYSTEM_DEFAULT_DECLARE GetGLProgramResource(OpenGLUInt program, ProgramInterface programInterface, OpenGLUInt index, OpenGLSize propCount, const OpenGLEnum* props, OpenGLSize bufSize, OpenGLSize* length, OpenGLInt* params) noexcept;
    void SYSTEM_DEFAULT_DECLARE GetGLProgramResourceName(OpenGLUInt program, ProgramInterface programInterface, OpenGLUInt index, OpenGLSize bufSize, OpenGLSize* length, OpenGLChar* name) noexcept;
    NODISCARD OpenGLUInt SYSTEM_DEFAULT_DECLARE GetGLProgramResourceIndex(OpenGLUInt program, ProgramInterface programInterface, const OpenGLChar* name) noexcept;

    SYSTEM_DEFAULT_DECLARE void SetUseProgram(OpenGLUInt program) noexcept;
}

#endif  // SYSTEM_OPENGL_OPENGL_PROGRAM_H