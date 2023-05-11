///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/14 0:15)

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
        void DoRunUnitTest() final;
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