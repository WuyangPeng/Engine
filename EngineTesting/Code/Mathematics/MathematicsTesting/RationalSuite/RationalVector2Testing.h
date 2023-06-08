///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/26 11:30)

#ifndef MATHEMATICS_RATIONAL_SUITE_RATIONAL_VECTOR2_TESTING_H
#define MATHEMATICS_RATIONAL_SUITE_RATIONAL_VECTOR2_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class RationalVector2Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = RationalVector2Testing;
        using ParentType = UnitTest;

    public:
        explicit RationalVector2Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void ConstructionTest();
        void CalculateTest();
        void OperatorTest();
        void CompareTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_RATIONAL_SUITE_RATIONAL_VECTOR2_TESTING_H