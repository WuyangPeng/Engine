///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:57)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_NONITERATIVE_EIGEN3X3_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_NONITERATIVE_EIGEN3X3_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class NoniterativeEigen3x3Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = NoniterativeEigen3x3Testing;
        using ParentType = UnitTest;

    public:
        explicit NoniterativeEigen3x3Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void EigenTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_NONITERATIVE_EIGEN3X3_TESTING_H