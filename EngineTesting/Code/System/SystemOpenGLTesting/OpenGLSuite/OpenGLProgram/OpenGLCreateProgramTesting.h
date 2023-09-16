///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 14:02)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_CREATE_PROGRAM_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_CREATE_PROGRAM_TESTING_H

#include "OpenGLProgramTestingBase.h"

namespace System
{
    class OpenGLCreateProgramTesting final : public OpenGLProgramTestingBase
    {
    public:
        using ClassType = OpenGLCreateProgramTesting;
        using ParentType = OpenGLProgramTestingBase;

    public:
        explicit OpenGLCreateProgramTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CreateProgramTest();
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_CREATE_PROGRAM_TESTING_H