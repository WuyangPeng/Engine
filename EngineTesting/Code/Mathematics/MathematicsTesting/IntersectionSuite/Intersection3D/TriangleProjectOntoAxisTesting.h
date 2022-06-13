///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/06 11:08)

#ifndef MATHEMATICS_INTERSECTION_SUITE_TRIANGLE_PROJECT_ONTO_AXIS_TESTING_H
#define MATHEMATICS_INTERSECTION_SUITE_TRIANGLE_PROJECT_ONTO_AXIS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class TriangleProjectOntoAxisTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(TriangleProjectOntoAxisTesting);

    private:
        void MainTest();
        void ProjectTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_INTERSECTION_SUITE_TRIANGLE_PROJECT_ONTO_AXIS_TESTING_H