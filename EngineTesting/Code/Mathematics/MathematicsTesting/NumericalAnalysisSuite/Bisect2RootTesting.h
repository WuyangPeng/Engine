///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:55)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BISECT2_ROOT_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BISECT2_ROOT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Bisect2RootTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = Bisect2RootTesting;
        using ParentType = UnitTest;

    public:
        explicit Bisect2RootTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void HaveSolutionTest();
        void NoSolutionXTest();
        void NoSolutionYTest();
        void UnknownTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BISECT2_ROOT_TESTING_H