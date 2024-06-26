///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 11:13)

#include "SystemManagerInterfaceTesting.h"
#include "System/Windows/Flags/WindowsDisplayFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/RendererEngine/EnvironmentParameter.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MiddleLayer/AudioManagerInterface.h"
#include "Framework/MiddleLayer/CameraSystemsManagerInterface.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainerDetail.h"
#include "Framework/MiddleLayer/EventManagerInterface.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"
#include "Framework/MiddleLayer/InputManagerInterface.h"
#include "Framework/MiddleLayer/MessageManagerInterface.h"
#include "Framework/MiddleLayer/ObjectLogicInterface.h"
#include "Framework/MiddleLayer/RenderingManagerInterface.h"
#include "Framework/MiddleLayer/ResourceManagerInterface.h"
#include "Framework/MiddleLayer/SystemManagerInterface.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/Flags/MouseTypes.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"

Framework::SystemManagerInterfaceTesting::SystemManagerInterfaceTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, SystemManagerInterfaceTesting)

void Framework::SystemManagerInterfaceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::SystemManagerInterfaceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetMiddleLayerTest);
}

void Framework::SystemManagerInterfaceTesting::MiddleLayerTest()
{
    SystemManagerInterface middleLayer{ MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    ASSERT_TRUE(middleLayer.PreCreate());
    ASSERT_TRUE(middleLayer.Initialize());
    middleLayer.PreIdle();
    ASSERT_TRUE(middleLayer.Create(Rendering::EnvironmentParameter::Create()));
    ASSERT_TRUE(middleLayer.Paint());
    ASSERT_TRUE(middleLayer.Move(WindowPoint{}));
    ASSERT_TRUE(middleLayer.Resize(System::WindowsDisplay::MaxHide, WindowSize{}));
    ASSERT_TRUE(middleLayer.KeyDown(0, WindowPoint{}));
    ASSERT_TRUE(middleLayer.KeyUp(0, WindowPoint{}));
    ASSERT_TRUE(middleLayer.SpecialKeyDown(0, WindowPoint{}));
    ASSERT_TRUE(middleLayer.SpecialKeyUp(0, WindowPoint{}));
    ASSERT_TRUE(middleLayer.MouseClick(MouseButtonsTypes::LeftButton, MouseStateTypes::MouseDown, WindowPoint{}, VirtualKeysTypes{}));
    ASSERT_TRUE(middleLayer.Motion(WindowPoint{}, VirtualKeysTypes{}));
    ASSERT_TRUE(middleLayer.PassiveMotion(WindowPoint{}));
    ASSERT_TRUE(middleLayer.MouseWheel(0, WindowPoint{}, VirtualKeysTypes{}));
    ASSERT_TRUE(middleLayer.Idle(0));

    ASSERT_TRUE(middleLayer.Destroy());
    middleLayer.Terminate();
}

void Framework::SystemManagerInterfaceTesting::SetMiddleLayerTest()
{
    ASSERT_THROW_EXCEPTION_0(SetNetworkManagerExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetInputManagerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetObjectLogicManagerTest);
    ASSERT_THROW_EXCEPTION_0(SetPhysicalModellingManagerExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetMessageManagerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetEventManagerTest);
    ASSERT_THROW_EXCEPTION_0(SetSystemManagerExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetResourceManagerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetAudioManagerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetCameraSystemsManagerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetRenderingManagerTest);
    ASSERT_THROW_EXCEPTION_0(SetGUIManagerExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetEngineManagerTest);
}

void Framework::SystemManagerInterfaceTesting::SetNetworkManagerExceptionTest()
{
    SystemManagerInterface middleLayer{ MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    const auto networkManager = std::make_shared<SystemManagerInterface>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    middleLayer.SetNetworkManager(networkManager);
}

void Framework::SystemManagerInterfaceTesting::SetInputManagerTest()
{
    SystemManagerInterface middleLayer{ MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    const auto inputManager = std::make_shared<InputManagerInterface>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    middleLayer.SetInputManager(inputManager);
}

void Framework::SystemManagerInterfaceTesting::SetObjectLogicManagerTest()
{
    SystemManagerInterface middleLayer{ MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    const auto objectLogicManager = std::make_shared<ObjectLogicInterface>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    middleLayer.SetObjectLogicManager(objectLogicManager);
}

void Framework::SystemManagerInterfaceTesting::SetPhysicalModellingManagerExceptionTest()
{
    SystemManagerInterface middleLayer{ MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    const auto physicalModellingManager = std::make_shared<SystemManagerInterface>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    middleLayer.SetPhysicalModellingManager(physicalModellingManager);
}

void Framework::SystemManagerInterfaceTesting::SetMessageManagerTest()
{
    SystemManagerInterface middleLayer{ MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    const auto messageManager = std::make_shared<MessageManagerInterface>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    middleLayer.SetMessageManager(messageManager);
}

void Framework::SystemManagerInterfaceTesting::SetEventManagerTest()
{
    SystemManagerInterface middleLayer{ MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    const auto eventManager = std::make_shared<EventManagerInterface>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    middleLayer.SetEventManager(eventManager);
}

void Framework::SystemManagerInterfaceTesting::SetSystemManagerExceptionTest()
{
    SystemManagerInterface middleLayer{ MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    const auto systemManager = std::make_shared<SystemManagerInterface>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    middleLayer.SetSystemManager(systemManager);
}

void Framework::SystemManagerInterfaceTesting::SetResourceManagerTest()
{
    SystemManagerInterface middleLayer{ MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    const auto resourceManager = std::make_shared<ResourceManagerInterface>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    middleLayer.SetResourceManager(resourceManager);
}

void Framework::SystemManagerInterfaceTesting::SetAudioManagerTest()
{
    SystemManagerInterface middleLayer{ MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    const auto audioManager = std::make_shared<AudioManagerInterface>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    middleLayer.SetAudioManager(audioManager);
}

void Framework::SystemManagerInterfaceTesting::SetCameraSystemsManagerTest()
{
    SystemManagerInterface middleLayer{ MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    const auto cameraSystemsManager = std::make_shared<CameraSystemsManagerInterface>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    middleLayer.SetCameraSystemsManager(cameraSystemsManager);
}

void Framework::SystemManagerInterfaceTesting::SetRenderingManagerTest()
{
    SystemManagerInterface middleLayer{ MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    const auto renderingManager = std::make_shared<RenderingManagerInterface>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    middleLayer.SetRenderingManager(renderingManager);
}

void Framework::SystemManagerInterfaceTesting::SetGUIManagerExceptionTest()
{
    SystemManagerInterface middleLayer{ MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    const auto guiManager = std::make_shared<SystemManagerInterface>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    middleLayer.SetGUIManager(guiManager);
}

void Framework::SystemManagerInterfaceTesting::SetEngineManagerTest()
{
    SystemManagerInterface middleLayer{ MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    const auto engineManager = std::make_shared<EngineMiddleLayerContainer<WindowApplicationTrait>>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    middleLayer.SetEngineManager(engineManager);
}
