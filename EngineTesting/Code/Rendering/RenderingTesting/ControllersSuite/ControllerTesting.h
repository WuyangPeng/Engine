/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/20 18:11)

#ifndef RENDERING_CONTROLLERS_SUITE_CONTROLLER_TESTING_H
#define RENDERING_CONTROLLERS_SUITE_CONTROLLER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class ControllerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ControllerTesting;
        using ParentType = UnitTest;

    public:
        explicit ControllerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();
        void NameTest();
        void SearchTest();
        void ControllerSetTest();
        void UpdateTest();
        void ValueTest();
        void StreamTest();

    private:
        std::string controllerTestName;
    };
}

#endif  // RENDERING_CONTROLLERS_SUITE_CONTROLLER_TESTING_H