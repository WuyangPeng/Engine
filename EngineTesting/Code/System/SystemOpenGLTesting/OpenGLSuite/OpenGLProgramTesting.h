///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.6 (2021/06/28 11:24)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_PROGRAM_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_PROGRAM_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class OpenGLProgramTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLProgramTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenGLProgramTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CreateProgramTest();
        void LinkTest();
        void ProgramStatusTest();
        void ProgramAttributesTest();
        void ProgramResourceTest();
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_PROGRAM_TESTING_H