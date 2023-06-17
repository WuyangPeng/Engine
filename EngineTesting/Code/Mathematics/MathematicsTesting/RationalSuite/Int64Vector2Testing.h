///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 16:28)

#ifndef MATHEMATICS_RATIONAL_SUITE_INT64_VECTOR2_TESTING_H
#define MATHEMATICS_RATIONAL_SUITE_INT64_VECTOR2_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Int64Vector2Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = Int64Vector2Testing;
        using ParentType = UnitTest;

    public:
        explicit Int64Vector2Testing(const OStreamShared& streamShared);

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

#endif  // MATHEMATICS_RATIONAL_SUITE_INT64_VECTOR2_TESTING_H