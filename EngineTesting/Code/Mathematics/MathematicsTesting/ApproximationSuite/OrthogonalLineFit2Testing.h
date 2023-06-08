///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 11:41)

#ifndef MATHEMATICS_APPROXIMATION_SUITE_ORTHGONAL_LINE_FIT2_TESTING_H
#define MATHEMATICS_APPROXIMATION_SUITE_ORTHGONAL_LINE_FIT2_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class OrthogonalLineFit2Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = OrthogonalLineFit2Testing;
        using ParentType = UnitTest;

    public:
        explicit OrthogonalLineFit2Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void FitTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_SUITE_ORTHGONAL_LINE_FIT2_TESTING_H