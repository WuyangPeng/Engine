///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/14 15:58)

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
        void DoRunUnitTest() final;
        void MainTest();

        void ProgramResourceTest();

        void DoProgramResourceTest(OpenGLUInt programHandle);
        void ProgramInterfaceTest(OpenGLUInt programHandle);
        void ShaderTest(OpenGLUInt shaderHandle, OpenGLUInt programHandle);
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_PROGRAM_INTERFACE_TESTING_H