///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/26 18:36)

#ifndef MATHEMATICS_QUERY_SUITE_QUERY2_INT64_TESTING_H
#define MATHEMATICS_QUERY_SUITE_QUERY2_INT64_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Query2Int64Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = Query2Int64Testing;
        using ParentType = UnitTest;

    public:
        explicit Query2Int64Testing(const OStreamShared& streamShared);

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

#endif  // MATHEMATICS_QUERY_SUITE_QUERY2_INT64_TESTING_H