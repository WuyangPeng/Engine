///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/06 11:07)

#ifndef MATHEMATICS_INTERSECTION_SUITE_TRIANGLE_PLANE_RELATIONS_TESTING_H
#define MATHEMATICS_INTERSECTION_SUITE_TRIANGLE_PLANE_RELATIONS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class TrianglePlaneRelationsTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = TrianglePlaneRelationsTesting;
        using ParentType = UnitTest;

    public:
        explicit TrianglePlaneRelationsTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void RelationsTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_INTERSECTION_SUITE_TRIANGLE_PLANE_RELATIONS_TESTING_H