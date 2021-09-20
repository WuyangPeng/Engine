///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.6 (2021/06/28 11:24)

#ifndef SYSTEM_OPENGL_SUITE_OPENGL_SHADER_TESTING_H
#define SYSTEM_OPENGL_SUITE_OPENGL_SHADER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class OpenGLShaderTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLShaderTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenGLShaderTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest() noexcept;
    };
}

#endif  // SYSTEM_OPENGL_SUITE_OPENGL_SHADER_TESTING_H