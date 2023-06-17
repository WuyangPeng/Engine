///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:50)

#ifndef MATHEMATICS_INTERSECTION_SUITE_STATIC_TEST_INTERSECTOR_LINE2_CLASSIFY_TESTING_H
#define MATHEMATICS_INTERSECTION_SUITE_STATIC_TEST_INTERSECTOR_LINE2_CLASSIFY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class StaticTestIntersectorLine2ClassifyTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = StaticTestIntersectorLine2ClassifyTesting;
        using ParentType = UnitTest;

    public:
        explicit StaticTestIntersectorLine2ClassifyTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void LineTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_INTERSECTION_SUITE_STATIC_TEST_INTERSECTOR_LINE2_CLASSIFY_TESTING_H