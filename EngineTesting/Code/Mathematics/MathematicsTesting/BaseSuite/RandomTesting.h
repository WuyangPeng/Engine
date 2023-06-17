///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:25)

#ifndef MATHEMATICS_BASE_SUITE_RANDOM_TESTING_H
#define MATHEMATICS_BASE_SUITE_RANDOM_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class RandomTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = RandomTesting;
        using ParentType = UnitTest;

    public:
        explicit RandomTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        // Random����
        void FloatRandomTest();
        void DoubleRandomTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_BASE_SUITE_RANDOM_TESTING_H