///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/13 13:06)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_PROGRAM_ATTRIBUTES_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_PROGRAM_ATTRIBUTES_TESTING_H

#include "OpenGLProgramTestingBase.h"

namespace System
{
    class OpenGLProgramAttributesTesting final : public OpenGLProgramTestingBase
    {
    public:
        using ClassType = OpenGLProgramAttributesTesting;
        using ParentType = OpenGLProgramTestingBase;

    public:
        explicit OpenGLProgramAttributesTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ProgramAttributesTest();

        void DoProgramAttributesTest(OpenGLUInt programHandle);
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_PROGRAM_ATTRIBUTES_TESTING_H