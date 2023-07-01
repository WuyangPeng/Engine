///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/19 15:10)

#ifndef FRAMEWORK_PROJECT_SUITE_RESOURCE_PROJECT_MANAGER_TESTING_H
#define FRAMEWORK_PROJECT_SUITE_RESOURCE_PROJECT_MANAGER_TESTING_H

#include "Detail/GUIProjectManagerMock.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Framework/Project/ResourceProjectManager.h"

namespace Framework
{
    class ResourceProjectManagerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ResourceProjectManagerTesting;
        using ParentType = UnitTest;

    public:
        explicit ResourceProjectManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using GUIProjectManagerSharedPtr = GUIProjectManagerMock::GUIProjectManagerSharedPtr;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void InitializeTest();
        void PrintEngineeringTest();
        void ProjectNameTest();

        NODISCARD ResourceProjectManager CreateResourceProjectManagerTesting();
        NODISCARD static GUIProjectManagerSharedPtr CreateGuiProjectManager(const EnvironmentDirectory& environmentDirectory);

    private:
        EnvironmentDirectory environmentDirectory;
        GUIProjectManagerSharedPtr guiProjectManager;
    };
}

#endif  // FRAMEWORK_PROJECT_SUITE_RESOURCE_PROJECT_MANAGER_TESTING_H