///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/16 19:45)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OEPNGL_MASK_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OEPNGL_MASK_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class OpenGLMaskTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLMaskTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenGLMaskTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SetGLColorMaskTest() noexcept;
        void SetGLSampleMaskTest() noexcept;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OEPNGL_MASK_TESTING_H