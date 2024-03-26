/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/08 16:12)

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
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD int PreviouslyBody0Test() const noexcept;
        NODISCARD int PreviouslyBody1Test() const noexcept;
        NODISCARD int PreviouslyBody2Test() const noexcept;
        NODISCARD int PreviouslyBody3Test() const noexcept;
        NODISCARD int PreviouslyBody4Test() const noexcept;
        NODISCARD int PreviouslyBody5Test() const noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_GL_UTILITY_PREVIOUSLY_BODY_RESULT_TESTING_H
