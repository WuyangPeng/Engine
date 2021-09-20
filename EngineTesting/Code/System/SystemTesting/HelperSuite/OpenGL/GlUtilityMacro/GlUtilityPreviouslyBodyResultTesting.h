///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.1 (2021/03/18 13:17)

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

        int PreviouslyBody0Test() noexcept;
        int PreviouslyBody1Test() noexcept;
        int PreviouslyBody2Test() noexcept;
        int PreviouslyBody3Test() noexcept;
        int PreviouslyBody4Test() noexcept;
        int PreviouslyBody5Test() noexcept; 
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_GL_UTILITY_PREVIOUSLY_BODY_RESULT_TESTING_H
