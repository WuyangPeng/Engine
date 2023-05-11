///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/12 23:12)

#ifndef SYSTEM_OPENGL_SUITE_OPENGL_SAMPLERS_TESTING_H
#define SYSTEM_OPENGL_SUITE_OPENGL_SAMPLERS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class OpenGLSamplersTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLSamplersTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenGLSamplersTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest() noexcept;
    };
}

#endif  // SYSTEM_OPENGL_SUITE_OPENGL_SAMPLERS_TESTING_H