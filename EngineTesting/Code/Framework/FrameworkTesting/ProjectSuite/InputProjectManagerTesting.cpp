///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/19 15:10)

#include "InputProjectManagerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/RendererEngine/EnvironmentParameter.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"
#include "Framework/Project/InputProjectManagerDetail.h"
#include "Framework/WindowCreate/WindowPoint.h"

Framework::InputProjectManagerTesting::InputProjectManagerTesting(const OStreamShared& stream)
    : ParentType{ stream },
      environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") },
      systemProjectManager{ CreateSystemProjectManager(environmentDirectory) },
      resourceProjectManager{ CreateResourceProjectManager(environmentDirectory) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, InputProjectManagerTesting)

void Framework::InputProjectManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::InputProjectManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(KeyDownTest);
}

void Framework::InputProjectManagerTesting::KeyDownTest()
{
    auto inputProjectManager = CreateInputProjectManager();

    ASSERT_EQUAL(systemProjectManager->GetExecute(), 0);
    ASSERT_TRUE(inputProjectManager.KeyDown(ApplicationTrait::KeyIdentifiers::keyCode0, WindowPoint{}));
    ASSERT_EQUAL(systemProjectManager->GetExecute(), 0);

    ASSERT_TRUE(inputProjectManager.KeyDown(ApplicationTrait::KeyIdentifiers::keyCode5, WindowPoint{}));
    constexpr auto keyCode5 = ApplicationTrait::KeyIdentifiers::keyCode5 - ApplicationTrait::KeyIdentifiers::keyCode0;
    ASSERT_EQUAL(systemProjectManager->GetExecute(), keyCode5 - 1);

    systemProjectManager->Clear();

    ASSERT_TRUE(inputProjectManager.KeyDown(ApplicationTrait::KeyIdentifiers::keyCode1, WindowPoint{}));
    ASSERT_EQUAL(systemProjectManager->GetExecute(), 0);

    ASSERT_TRUE(inputProjectManager.KeyDown(ApplicationTrait::KeyIdentifiers::keyCode1, WindowPoint{}));
    constexpr auto keyCode1 = ApplicationTrait::KeyIdentifiers::keyCode1 - ApplicationTrait::KeyIdentifiers::keyCode0;
    ASSERT_EQUAL(systemProjectManager->GetExecute(), keyCode1 * 10 + keyCode1 - 1);
}

Framework::InputProjectManagerTesting::InputProjectManager Framework::InputProjectManagerTesting::CreateInputProjectManager() const
{
    InputProjectManager inputProjectManager{ MiddleLayerPlatform::Windows, environmentDirectory };
    systemProjectManager->SetResourceManager(resourceProjectManager);
    inputProjectManager.SetSystemManager(systemProjectManager);
    systemProjectManager->Clear();

    return inputProjectManager;
}

Framework::InputProjectManagerTesting::SystemProjectManagerSharedPtr Framework::InputProjectManagerTesting::CreateSystemProjectManager(const EnvironmentDirectory& environmentDirectory)
{
    auto systemProjectManager = SystemProjectManagerMock::CreateMiddleLayer(MiddleLayerPlatform::Windows, environmentDirectory);
    systemProjectManager->Create(Rendering::EnvironmentParameter::Create());

    return systemProjectManager;
}

Framework::InputProjectManagerTesting::ResourceProjectManagerSharedPtr Framework::InputProjectManagerTesting::CreateResourceProjectManager(const EnvironmentDirectory& environmentDirectory)
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
