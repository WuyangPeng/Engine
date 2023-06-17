///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:21)

#ifndef MATHEMATICS_QUERY_SUITE_QUERY2_FILTERED_TESTING_H
#define MATHEMATICS_QUERY_SUITE_QUERY2_FILTERED_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Query2FilteredTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = Query2FilteredTesting;
        using ParentType = UnitTest;

    public:
        explicit Query2FilteredTesting(const OStreamShared& streamShared);

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

#endif  // MATHEMATICS_QUERY_SUITE_QUERY2_FILTERED_TESTING_H