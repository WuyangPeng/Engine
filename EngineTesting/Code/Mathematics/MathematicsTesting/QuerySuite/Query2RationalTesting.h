///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 16:22)

#ifndef MATHEMATICS_QUERY_SUITE_QUERY2_RATIONAL_TESTING_H
#define MATHEMATICS_QUERY_SUITE_QUERY2_RATIONAL_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Query2RationalTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = Query2RationalTesting;
        using ParentType = UnitTest;

    public:
        explicit Query2RationalTesting(const OStreamShared& streamShared);

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

#endif  // MATHEMATICS_QUERY_SUITE_QUERY2_RATIONAL_TESTING_H