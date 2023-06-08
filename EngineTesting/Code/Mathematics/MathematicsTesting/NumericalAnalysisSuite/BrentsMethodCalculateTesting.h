///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/01 14:57)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BRENTS_METHOD_CALUCULATE_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BRENTS_METHOD_CALUCULATE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class BrentsMethodCalculateTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = BrentsMethodCalculateTesting;
        using ParentType = UnitTest;

    public:
        explicit BrentsMethodCalculateTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void HaveSolutionTest();
        void NoSolutionTest();
        void UnknownTest();

        void DoRunUnitTest() override;

        NODISCARD static double Solution(double input, const BrentsMethodCalculateTesting* userData) noexcept;
        NODISCARD double GetUserData() const noexcept;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BRENTS_METHOD_CALUCULATE_TESTING_H