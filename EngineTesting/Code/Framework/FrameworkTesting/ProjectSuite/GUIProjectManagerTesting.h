///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 14:10)

#ifndef FRAMEWORK_PROJECT_SUITE_GUI_PROJECT_MANAGER_TESTING_H
#define FRAMEWORK_PROJECT_SUITE_GUI_PROJECT_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"

namespace Framework
{
    class GUIProjectManagerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GUIProjectManagerTesting;
        using ParentType = UnitTest;

    public:
        explicit GUIProjectManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void PrintSelectTest();

    private:
        EnvironmentDirectory environmentDirectory;
    };
}

#endif  // FRAMEWORK_PROJECT_SUITE_GUI_PROJECT_MANAGER_TESTING_H