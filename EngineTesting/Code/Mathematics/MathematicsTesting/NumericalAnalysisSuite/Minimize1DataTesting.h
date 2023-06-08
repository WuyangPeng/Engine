///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/01 14:59)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_MINIMIZE1_DATA_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_MINIMIZE1_DATA_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Minimize1DataTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = Minimize1DataTesting;
        using ParentType = UnitTest;

    public:
        explicit Minimize1DataTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DataTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_MINIMIZE1_DATA_TESTING_H