///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/26 11:27)

#ifndef MATHEMATICS_RATIONAL_SUITE_INT64_VECTOR_TESTING_H
#define MATHEMATICS_RATIONAL_SUITE_INT64_VECTOR_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Int64VectorTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = Int64VectorTesting;
        using ParentType = UnitTest;

    public:
        explicit Int64VectorTesting(const OStreamShared& streamShared);

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

#endif  // MATHEMATICS_RATIONAL_SUITE_INT64_VECTOR_TESTING_H