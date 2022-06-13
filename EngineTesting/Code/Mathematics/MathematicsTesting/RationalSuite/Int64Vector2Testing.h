///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/26 11:27)

#ifndef MATHEMATICS_RATIONAL_SUITE_INT64_VECTOR2_TESTING_H
#define MATHEMATICS_RATIONAL_SUITE_INT64_VECTOR2_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class Int64Vector2Testing : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Int64Vector2Testing);

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