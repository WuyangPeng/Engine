/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 16:38)

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

        void DoProgramStatusTest(OpenGLUnsignedInt programHandle);
        void ProgramStatusFalseTest(OpenGLUnsignedInt programHandle);
        void ValidateGLProgramTest(OpenGLUnsignedInt programHandle);
        void UseProgramTest(OpenGLUnsignedInt programHandle) const noexcept;

        void DoCreateGLShaderTest(OpenGLUnsignedInt shaderHandle, OpenGLUnsignedInt programHandle);

    private:
        CodeType code;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_PROGRAM_STATUS_TESTING_H