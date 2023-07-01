///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/18 23:14)

#ifndef FRAMEWORK_PROJECT_SUITE_SYSTEM_PROJECT_MANAGER_TESTING_H
#define FRAMEWORK_PROJECT_SUITE_SYSTEM_PROJECT_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Detail/ResourceProjectManagerMock.h"
#include "Framework/Project/ResourceProjectManager.h"
#include "Framework/Project/SystemProjectManager.h"

namespace Framework
{
    class SystemProjectManagerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SystemProjectManagerTesting;
        using ParentType = UnitTest;

    public:
        explicit SystemProjectManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using ResourceProjectManagerSharedPtr = ResourceProjectManagerMock::ResourceProjectManagerSharedPtr;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void GetContainerPrintWidthTest();
        void ExecuteTest();
        void ExecuteExceptionTest();

        NODISCARD SystemProjectManager CreateSystemProjectManager() const;
        NODISCARD static ResourceProjectManagerSharedPtr CreateResourceProjectManager(const EnvironmentDirectory& environmentDirectory);

    private:
        EnvironmentDirectory environmentDirectory;
        ResourceProjectManagerSharedPtr resourceProjectManager;
    };
}

#endif  // FRAMEWORK_PROJECT_SUITE_SYSTEM_PROJECT_MANAGER_TESTING_H