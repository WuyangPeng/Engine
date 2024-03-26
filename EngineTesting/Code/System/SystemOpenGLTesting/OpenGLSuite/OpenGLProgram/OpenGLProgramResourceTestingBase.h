/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 16:38)

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
        NODISCARD static bool IsProgramInterfaceInvalid(ProgramInterface programInterface, ProgramInterfaceName programInterfaceName) noexcept;
        void ShaderSourceTest(OpenGLUnsignedInt shaderHandle) const;
        NODISCARD ProgramInterface GetProgramInterface(int index) const;
        NODISCARD ProgramInterfaceName GetProgramInterfaceName(int index) const;
        NODISCARD int GetProgramInterfaceCount() const;
        NODISCARD int GetProgramInterfaceNameCount() const;

    private:
        CodeType code;
        ProgramInterfaceContainer programInterfaces;
        ProgramInterfaceNameContainer programInterfaceNames;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_PROGRAM_RESOURCE_TESTING_BASE_H