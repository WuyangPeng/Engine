///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:51)

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