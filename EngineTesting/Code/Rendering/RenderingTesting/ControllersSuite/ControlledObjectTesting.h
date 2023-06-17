///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 16:02)

#ifndef RENDERING_CONTROLLERS_SUITE_CONTROLLER_OBJECT_TESTING_H
#define RENDERING_CONTROLLERS_SUITE_CONTROLLER_OBJECT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class ControlledObjectTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = ControlledObjectTesting;
        using ParentType = UnitTest;

    public:
        explicit ControlledObjectTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void InitTest();
        void CopyTest() noexcept;
        void StreamTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_CONTROLLERS_SUITE_CONTROLLER_OBJECT_TESTING_H