///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 14:11)

#ifndef FRAMEWORK_PROJECT_SUITE_INPUT_PROJECT_MANAGER_TESTING_H
#define FRAMEWORK_PROJECT_SUITE_INPUT_PROJECT_MANAGER_TESTING_H

#include "Detail/ResourceProjectManagerMock.h"
#include "Detail/SystemProjectManagerMock.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/Project/InputProjectManager.h"

namespace Framework
{
    class InputProjectManagerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = InputProjectManagerTesting;
        using ParentType = UnitTest;

    public:
        explicit InputProjectManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using SystemProjectManagerSharedPtr = SystemProjectManagerMock::SystemProjectManagerSharedPtr;
        using ApplicationTrait = ApplicationTrait<PlatformTypes::Window>;
        using InputProjectManager = InputProjectManager<ApplicationTrait>;
        using ResourceProjectManagerSharedPtr = ResourceProjectManagerMock::ResourceProjectManagerSharedPtr;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void KeyDownTest();

        NODISCARD InputProjectManager CreateInputProjectManager() const;
        NODISCARD static SystemProjectManagerSharedPtr CreateSystemProjectManager(const EnvironmentDirectory& environmentDirectory);
        NODISCARD static ResourceProjectManagerSharedPtr CreateResourceProjectManager(const EnvironmentDirectory& environmentDirectory);

    private:
        EnvironmentDirectory environmentDirectory;
        SystemProjectManagerSharedPtr systemProjectManager;
        ResourceProjectManagerSharedPtr resourceProjectManager;
    };
}

#endif  // FRAMEWORK_PROJECT_SUITE_INPUT_PROJECT_MANAGER_TESTING_H