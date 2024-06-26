///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 16:03)

#ifndef RENDERING_CONTROLLERS_SUITE_POINT_CONTROLLER_TESTING_H
#define RENDERING_CONTROLLERS_SUITE_POINT_CONTROLLER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class PointControllerTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = PointControllerTesting;
        using ParentType = UnitTest;

    public:
        explicit PointControllerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_CONTROLLERS_SUITE_POINT_CONTROLLER_TESTING_H