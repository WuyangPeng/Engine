///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:03)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_PROGRAM_STATUS_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_PROGRAM_STATUS_TESTING_H

#include "OpenGLProgramTestingBase.h"

#include <vector>

namespace System
{
    class OpenGLProgramStatusTesting final : public OpenGLProgramTestingBase
    {
    public:
        using ClassType = OpenGLProgramStatusTesting;
        using ParentType = OpenGLProgramTestingBase;

    public:
        explicit OpenGLProgramStatusTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ProgramStatusTest();

        void DoProgramStatusTest(OpenGLUInt programHandle);
        void ProgramStatusFalseTest(OpenGLUInt programHandle);
        void ValidateGLProgramTest(OpenGLUInt programHandle);

        void DoCreateGLShaderTest(OpenGLUInt shaderHandle, OpenGLUInt programHandle);

    private:
        CodeType code;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_PROGRAM_STATUS_TESTING_H