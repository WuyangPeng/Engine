///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/24 18:08)

#include "SystemManagerInterfaceTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/AudioManagerInterface.h"
#include "Framework/MiddleLayer/CameraSystemsManagerInterface.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainerDetail.h"
#include "Framework/MiddleLayer/EventManagerInterface.h"
#include "Framework/MiddleLayer/InputManagerInterface.h"
#include "Framework/MiddleLayer/MessageManagerInterface.h"
#include "Framework/MiddleLayer/ObjectLogicInterface.h"
#include "Framework/MiddleLayer/RenderingManagerInterface.h"
#include "Framework/MiddleLayer/ResourceManagerInterface.h"
#include "Framework/MiddleLayer/SystemManagerInterface.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"
#include "System/Windows/Flags/WindowsDisplayFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"
#include "Framework/WindowProcess/Flags/MouseTypes.h"

namespace Framework
{
    using TestingType = SystemManagerInterface;
}

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
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    ASSERT_TRUE(middleLayer.PreCreate(EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));
    ASSERT_TRUE(middleLayer.Initialize());
    middleLayer.PreIdle();
    ASSERT_TRUE(middleLayer.Create());
    ASSERT_TRUE(middleLayer.Paint());
    ASSERT_TRUE(middleLayer.Move(WindowPoint()));
    ASSERT_TRUE(middleLayer.Resize(System::WindowsDisplay::MaxHide, WindowSize()));
    ASSERT_TRUE(middleLayer.KeyDown(0, WindowPoint()));
    ASSERT_TRUE(middleLayer.KeyUp(0, WindowPoint()));
    ASSERT_TRUE(middleLayer.SpecialKeyDown(0, WindowPoint()));
    ASSERT_TRUE(middleLayer.SpecialKeyUp(0, WindowPoint()));
    ASSERT_TRUE(middleLayer.MouseClick(MouseButtonsTypes::LeftButton, MouseStateTypes::MouseDown, WindowPoint(), VirtualKeysTypes()));
    ASSERT_TRUE(middleLayer.Motion(WindowPoint(), VirtualKeysTypes()));
    ASSERT_TRUE(middleLayer.PassiveMotion(WindowPoint()));
    ASSERT_TRUE(middleLayer.MouseWheel(0, WindowPoint(), VirtualKeysTypes()));
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
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr networkManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

    middleLayer.SetNetworkManager(networkManager);
}

void Framework::SystemManagerInterfaceTesting::SetInputManagerTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr inputManager(std::make_shared<InputManagerInterface>(MiddleLayerPlatform::Windows));

    middleLayer.SetInputManager(inputManager);
}

void Framework::SystemManagerInterfaceTesting::SetObjectLogicManagerTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr objectLogicManager(std::make_shared<ObjectLogicInterface>(MiddleLayerPlatform::Windows));

    middleLayer.SetObjectLogicManager(objectLogicManager);
}

void Framework::SystemManagerInterfaceTesting::SetPhysicalModellingManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr physicalModellingManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

    middleLayer.SetPhysicalModellingManager(physicalModellingManager);
}

void Framework::SystemManagerInterfaceTesting::SetMessageManagerTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr messageManager(std::make_shared<MessageManagerInterface>(MiddleLayerPlatform::Windows));

    middleLayer.SetMessageManager(messageManager);
}

void Framework::SystemManagerInterfaceTesting::SetEventManagerTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr eventManager(std::make_shared<EventManagerInterface>(MiddleLayerPlatform::Windows));

    middleLayer.SetEventManager(eventManager);
}

void Framework::SystemManagerInterfaceTesting::SetSystemManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr systemManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

    middleLayer.SetSystemManager(systemManager);
}

void Framework::SystemManagerInterfaceTesting::SetResourceManagerTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr resourceManager(std::make_shared<ResourceManagerInterface>(MiddleLayerPlatform::Windows));

    middleLayer.SetResourceManager(resourceManager);
}

void Framework::SystemManagerInterfaceTesting::SetAudioManagerTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr audioManager(std::make_shared<AudioManagerInterface>(MiddleLayerPlatform::Windows));

    middleLayer.SetAudioManager(audioManager);
}

void Framework::SystemManagerInterfaceTesting::SetCameraSystemsManagerTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr cameraSystemsManager(std::make_shared<CameraSystemsManagerInterface>(MiddleLayerPlatform::Windows));

    middleLayer.SetCameraSystemsManager(cameraSystemsManager);
}

void Framework::SystemManagerInterfaceTesting::SetRenderingManagerTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr renderingManager(std::make_shared<RenderingManagerInterface>(MiddleLayerPlatform::Windows));

    middleLayer.SetRenderingManager(renderingManager);
}

void Framework::SystemManagerInterfaceTesting::SetGUIManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr guiManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

    middleLayer.SetGUIManager(guiManager);
}

void Framework::SystemManagerInterfaceTesting::SetEngineManagerTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr engineManager(std::make_shared<EngineMiddleLayerContainer<WindowApplicationTrait>>(MiddleLayerPlatform::Windows));

    middleLayer.SetEngineManager(engineManager);
}
