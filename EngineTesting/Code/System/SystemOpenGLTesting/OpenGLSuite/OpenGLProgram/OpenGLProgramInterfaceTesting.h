/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:38)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_PROGRAM_INTERFACE_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_PROGRAM_INTERFACE_TESTING_H

#include "OpenGLProgramResourceTestingBase.h"

namespace System
{
    class OpenGLProgramInterfaceTesting final : public OpenGLProgramResourceTestingBase
    {
    public:
        using ClassType = OpenGLProgramInterfaceTesting;
        using ParentType = OpenGLProgramResourceTestingBase;

    public:
        explicit OpenGLProgramInterfaceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ProgramResourceTest();

        void DoProgramResourceTest(OpenGLUnsignedInt programHandle);
        void ProgramInterfaceTest(OpenGLUnsignedInt programHandle);
        void ShaderTest(OpenGLUnsignedInt shaderHandle, OpenGLUnsignedInt programHandle);
        void DoProgramInterfaceTest(System::OpenGLUnsignedInt programHandle, int outer, int inner);
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_PROGRAM_INTERFACE_TESTING_H