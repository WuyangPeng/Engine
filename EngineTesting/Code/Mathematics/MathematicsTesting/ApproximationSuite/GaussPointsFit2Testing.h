///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 11:37)

#ifndef MATHEMATICS_APPROXIMATION_SUITE_GUASS_POINTS_FIT2_TESTING_H
#define MATHEMATICS_APPROXIMATION_SUITE_GUASS_POINTS_FIT2_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class GaussPointsFit2Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = GaussPointsFit2Testing;
        using ParentType = UnitTest;

    public:
        explicit GaussPointsFit2Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void FitTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_SUITE_GUASS_POINTS_FIT2_TESTING_H