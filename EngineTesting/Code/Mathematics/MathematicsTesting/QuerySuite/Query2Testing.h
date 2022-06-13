///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/26 18:37)

#ifndef MATHEMATICS_QUERY_SUITE_QUERY2_TESTING_H
#define MATHEMATICS_QUERY_SUITE_QUERY2_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class Query2Testing : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Query2Testing);

    private:
        void MainTest();
        void VerticesTest();
        void LineTest();
        void TriangleTest();
        void CircumcircleTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_QUERY_SUITE_QUERY2_TESTING_H