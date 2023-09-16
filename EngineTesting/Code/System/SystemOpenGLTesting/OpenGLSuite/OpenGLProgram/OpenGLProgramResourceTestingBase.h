///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:03)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_PROGRAM_RESOURCE_TESTING_BASE_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_PROGRAM_RESOURCE_TESTING_BASE_H

#include "OpenGLProgramTestingBase.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

#include <vector>

namespace System
{
    class OpenGLProgramResourceTestingBase : public OpenGLProgramTestingBase
    {
    public:
        using ClassType = OpenGLProgramResourceTestingBase;
        using ParentType = OpenGLProgramTestingBase;

    public:
        explicit OpenGLProgramResourceTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        using ProgramInterfaceContainer = std::vector<ProgramInterface>;
        using ProgramInterfaceNameContainer = std::vector<ProgramInterfaceName>;

    protected:
        NODISCARD bool IsProgramInterfaceInvalid(ProgramInterface programInterface, ProgramInterfaceName programInterfaceName) noexcept;
        void ShaderSourceTest(OpenGLUInt shaderHandle);
        NODISCARD ProgramInterface GetProgramInterface(size_t index) const;
        NODISCARD ProgramInterfaceName GetProgramInterfaceName(size_t index) const;
        NODISCARD size_t GetProgramInterfaceCount() const noexcept;
        NODISCARD size_t GetProgramInterfaceNameCount() const noexcept;

    private:
        CodeType code;
        ProgramInterfaceContainer programInterfaces;
        ProgramInterfaceNameContainer programInterfaceNames;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_PROGRAM_RESOURCE_TESTING_BASE_H