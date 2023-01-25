///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/13 22:14)

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