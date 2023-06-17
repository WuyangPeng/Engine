///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:22)

#ifndef MATHEMATICS_QUERY_SUITE_QUERY2_INTEGER_TESTING_H
#define MATHEMATICS_QUERY_SUITE_QUERY2_INTEGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Query2IntegerTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = Query2IntegerTesting;
        using ParentType = UnitTest;

    public:
        explicit Query2IntegerTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void VerticesTest();
        void LineTest();
        void TriangleTest();
        void CircumcircleTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_QUERY_SUITE_QUERY2_INTEGER_TESTING_H