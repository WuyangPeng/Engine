///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:56)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BRENTS_METHOD_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BRENTS_METHOD_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class BrentsMethodTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = BrentsMethodTesting;
        using ParentType = UnitTest;

    public:
        explicit BrentsMethodTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void BaseTest();
        void HaveSolutionTest();
        void NoSolutionTest();
        void UnknownTest();

        void DoRunUnitTest() override;

        NODISCARD static double FirstSolution(double input, const BrentsMethodTesting* userData) noexcept;
        NODISCARD static double SecondSolution(double input, const BrentsMethodTesting* userData) noexcept;
        NODISCARD double GetUserData() const noexcept;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BRENTS_METHOD_TESTING_H