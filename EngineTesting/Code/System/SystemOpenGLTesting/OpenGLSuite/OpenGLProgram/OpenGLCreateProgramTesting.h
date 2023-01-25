///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/13 22:14)

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
        void DoRunUnitTest() final;
        void MainTest();

        void CreateProgramTest();
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_CREATE_PROGRAM_TESTING_H