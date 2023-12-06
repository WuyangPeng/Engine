/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/21 09:42)

#ifndef RENDERING_CONTROLLERS_SUITE_CONTROLLER_OBJECT_TESTING_H
#define RENDERING_CONTROLLERS_SUITE_CONTROLLER_OBJECT_TESTING_H

#include "Detail/ControllerTest.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class ControlledObjectTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ControlledObjectTesting;
        using ParentType = UnitTest;

    public:
        explicit ControlledObjectTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using ControllerTestSharedPtr = ControllerTest::ControllerTestSharedPtr;

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void NameTest();
        void SearchSelfTest();
        void SearchChildTest();
        void ControllerSetExceptionTest();
        void UpdateTest();
        void ControllersTest();
        void StreamTest();
        void EqualTest(const ControllerTest& lhs, const ControllerTest& rhs);

    private:
        std::string controlledObjectTestName;
        std::string controllerTestName;
    };
}

#endif  // RENDERING_CONTROLLERS_SUITE_CONTROLLER_OBJECT_TESTING_H