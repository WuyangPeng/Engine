///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/18 13:00)

#ifndef SYSTEM_TESTING_HELPER_SUITE_GL_UTILITY_PREVIOUSLY_BODY_RESULT_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_GL_UTILITY_PREVIOUSLY_BODY_RESULT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class GlUtilityPreviouslyBodyResultTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GlUtilityPreviouslyBodyResultTesting;
        using ParentType = UnitTest;

    public:
        explicit GlUtilityPreviouslyBodyResultTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD int PreviouslyBody0Test() noexcept;
        NODISCARD int PreviouslyBody1Test() noexcept;
        NODISCARD int PreviouslyBody2Test() noexcept;
        NODISCARD int PreviouslyBody3Test() noexcept;
        NODISCARD int PreviouslyBody4Test() noexcept;
        NODISCARD int PreviouslyBody5Test() noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_GL_UTILITY_PREVIOUSLY_BODY_RESULT_TESTING_H
