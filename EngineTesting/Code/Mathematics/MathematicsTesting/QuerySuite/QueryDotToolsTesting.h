///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/26 18:37)

#ifndef MATHEMATICS_QUERY_SUITE_QUERY_DOT_TOOLS_TESTING_H
#define MATHEMATICS_QUERY_SUITE_QUERY_DOT_TOOLS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class QueryDotToolsTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = QueryDotToolsTesting;
        using ParentType = UnitTest;

    public:
        explicit QueryDotToolsTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DotTest();
        void Det2Test();
        void Det3Test();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_QUERY_SUITE_QUERY_DOT_TOOLS_TESTING_H