///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 16:22)

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