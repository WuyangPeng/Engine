///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 14:11)

#include "ResourceProjectManagerTesting.h"
#include "Detail/GUIProjectManagerMock.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/RendererEngine/EnvironmentParameter.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"

Framework::ResourceProjectManagerTesting::ResourceProjectManagerTesting(const OStreamShared& stream)
    : ParentType{ stream },
      environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") },
      guiProjectManager{ CreateGuiProjectManager(environmentDirectory) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ResourceProjectManagerTesting)

void Framework::ResourceProjectManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::ResourceProjectManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitializeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PrintEngineeringTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ProjectNameTest);
}

void Framework::ResourceProjectManagerTesting::InitializeTest()
{
    auto resourceProjectManager = CreateResourceProjectManagerTesting();

    ASSERT_EQUAL(guiProjectManager->GetPrintSelect(), 0);
    ASSERT_TRUE(resourceProjectManager.Initialize());
    ASSERT_EQUAL(guiProjectManager->GetPrintSelect(), 1);
}

void Framework::ResourceProjectManagerTesting::PrintEngineeringTest()
{
    const auto resourceProjectManager = CreateResourceProjectManagerTesting();

    ASSERT_EQUAL(guiProjectManager->GetPrintEngineering(), 0);
    ASSERT_EQUAL(guiProjectManager->GetPrintSelect(), 0);
    resourceProjectManager.PrintEngineering(SYSTEM_TEXT("Engineering"));
    ASSERT_EQUAL(guiProjectManager->GetPrintEngineering(), 1);
    ASSERT_EQUAL(guiProjectManager->GetPrintSelect(), 1);
}

void Framework::ResourceProjectManagerTesting::ProjectNameTest()
{
    const auto resourceProjectManager = CreateResourceProjectManagerTesting();

    ASSERT_EQUAL(resourceProjectManager.GetContainerPrintWidth(), 2);
    ASSERT_TRUE(resourceProjectManager.IsSelectValid(0));
    ASSERT_TRUE(resourceProjectManager.IsSelectValid(1));
    ASSERT_FALSE(resourceProjectManager.IsSelectValid(11));
    ASSERT_EQUAL(resourceProjectManager.GetEngineeringName(0), SYSTEM_TEXT("FrameworkTesting"));
    ASSERT_EQUAL(resourceProjectManager.GetEngineeringName(1), SYSTEM_TEXT("FrameworkWindowTesting"));
}

Framework::ResourceProjectManager Framework::ResourceProjectManagerTesting::CreateResourceProjectManagerTesting()
{
    ResourceProjectManager resourceProjectManager{ MiddleLayerPlatform::Windows, environmentDirectory };
    resourceProjectManager.SetGUIManager(guiProjectManager);
    guiProjectManager->Clear();

    ASSERT_TRUE(resourceProjectManager.Create(Rendering::EnvironmentParameter::Create()));

    return resourceProjectManager;
}

Framework::ResourceProjectManagerTesting::GUIProjectManagerSharedPtr Framework::ResourceProjectManagerTesting::CreateGuiProjectManager(const EnvironmentDirectory& environmentDirectory)
{
    auto guiProjectManager = GUIProjectManagerMock::CreateMiddleLayer(MiddleLayerPlatform::Windows, environmentDirectory);
    guiProjectManager->Create(Rendering::EnvironmentParameter::Create());

    return guiProjectManager;
}
