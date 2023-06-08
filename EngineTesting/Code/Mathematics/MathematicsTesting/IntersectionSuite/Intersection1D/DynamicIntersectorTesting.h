///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/06 10:40)

#ifndef MATHEMATICS_INTERSECTION_SUITE_DYNAMIC_INTERSECTOR_TESTING_H
#define MATHEMATICS_INTERSECTION_SUITE_DYNAMIC_INTERSECTOR_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class DynamicIntersectorTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = DynamicIntersectorTesting;
        using ParentType = UnitTest;

    public:
        explicit DynamicIntersectorTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void IntersectionTypeTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_INTERSECTION_SUITE_DYNAMIC_INTERSECTOR_TESTING_H