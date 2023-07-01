///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/18 23:14)

#include "SystemProjectManagerTesting.h"
#include "Detail/ResourceProjectManagerMock.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/RendererEngine/EnvironmentParameter.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"
#include "Framework/Project/SystemProjectManager.h"

Framework::SystemProjectManagerTesting::SystemProjectManagerTesting(const OStreamShared& stream)
    : ParentType{ stream },
      environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") },
      resourceProjectManager{ CreateResourceProjectManager(environmentDirectory) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, SystemProjectManagerTesting)

void Framework::SystemProjectManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::SystemProjectManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetContainerPrintWidthTest);
    ASSERT_THROW_EXCEPTION_0(ExecuteExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExecuteTest);
}

void Framework::SystemProjectManagerTesting::GetContainerPrintWidthTest()
{
    const auto systemProjectManager = CreateSystemProjectManager();

    ASSERT_EQUAL(systemProjectManager.GetContainerPrintWidth(), 2);
}

void Framework::SystemProjectManagerTesting::ExecuteTest()
{
    auto systemProjectManager = CreateSystemProjectManager();

    ASSERT_EQUAL(resourceProjectManager->GetPrintEngineering(), 0);
    systemProjectManager.Execute(0);
    ASSERT_EQUAL(resourceProjectManager->GetPrintEngineering(), 1);
}

void Framework::SystemProjectManagerTesting::ExecuteExceptionTest()
{
    auto systemProjectManager = CreateSystemProjectManager();

    systemProjectManager.Execute(1);
}

Framework::SystemProjectManager Framework::SystemProjectManagerTesting::CreateSystemProjectManager() const
{
    SystemProjectManager systemProjectManager{ MiddleLayerPlatform::Windows, environmentDirectory };
    systemProjectManager.SetResourceManager(resourceProjectManager);
    resourceProjectManager->Clear();

    return systemProjectManager;
}

Framework::SystemProjectManagerTesting::ResourceProjectManagerSharedPtr Framework::SystemProjectManagerTesting::CreateResourceProjectManager(const EnvironmentDirectory& environmentDirectory)
{
    if (auto resourceProjectManager = ResourceProjectManagerMock::CreateMiddleLayer(MiddleLayerPlatform::Windows, environmentDirectory);
        resourceProjectManager->Create(Rendering::EnvironmentParameter::Create()))
    {
        return resourceProjectManager;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("ResourceProjectManager Create 错误。"))
    }
}
