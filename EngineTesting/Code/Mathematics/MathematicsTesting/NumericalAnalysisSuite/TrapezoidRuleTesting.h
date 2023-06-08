///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/01 16:06)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_TRAPEZOID_RULE_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_TRAPEZOID_RULE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class TrapezoidRuleTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = TrapezoidRuleTesting;
        using ParentType = UnitTest;

    public:
        explicit TrapezoidRuleTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void ValueTest();

        void DoRunUnitTest() override;

        NODISCARD static double Solution(double input, const TrapezoidRuleTesting* userData) noexcept;
        NODISCARD double GetUserData() const noexcept;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_TRAPEZOID_RULE_TESTING_H