///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/12 14:56)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OEPNGL_API_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OEPNGL_API_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class OpenGLAPITesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLAPITesting;
        using ParentType = UnitTest;

    public:
        explicit OpenGLAPITesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void BaseTest() noexcept;
        void QueryTest();
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OEPNGL_API_TESTING_H