///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/24 18:32)

#include "InputManagerTesting.h"
#include "System/Windows/Flags/WindowsDisplayFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MiddleLayer/CameraSystemsManagerInterface.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"
#include "Framework/MiddleLayer/InputManagerDetail.h"
#include "Framework/MiddleLayer/NetworkManagerInterface.h"
#include "Framework/MiddleLayer/ObjectLogicInterface.h"
#include "Framework/MiddleLayer/SystemManagerInterface.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/Flags/MouseTypes.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"

namespace Framework
{
    using TestingType = InputManager<WindowApplicationTrait>;
}

Framework::InputManagerTesting::InputManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, InputManagerTesting)

void Framework::InputManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::InputManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetMiddleLayerTest);
}

void Framework::InputManagerTesting::MiddleLayerTest()
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

void Framework::InputManagerTesting::SetMiddleLayerTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SetNetworkManagerTest);
    ASSERT_THROW_EXCEPTION_0(SetInputManagerExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetObjectLogicManagerTest);
    ASSERT_THROW_EXCEPTION_0(SetPhysicalModellingManagerExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetMessageManagerExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetEventManagerExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetSystemManagerTest);
    ASSERT_THROW_EXCEPTION_0(SetResourceManagerExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetAudioManagerExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetCameraSystemsManagerTest);
    ASSERT_THROW_EXCEPTION_0(SetRenderingManagerExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetGUIManagerExceptionTest);
}

void Framework::InputManagerTesting::SetNetworkManagerTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr networkManager(std::make_shared<NetworkManagerInterface>(MiddleLayerPlatform::Windows));

    middleLayer.SetNetworkManager(networkManager);
}

void Framework::InputManagerTesting::SetInputManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr inputManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

    middleLayer.SetInputManager(inputManager);
}

void Framework::InputManagerTesting::SetObjectLogicManagerTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr objectLogicManager(std::make_shared<ObjectLogicInterface>(MiddleLayerPlatform::Windows));

    middleLayer.SetObjectLogicManager(objectLogicManager);
}

void Framework::InputManagerTesting::SetPhysicalModellingManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr physicalModellingManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

    middleLayer.SetPhysicalModellingManager(physicalModellingManager);
}

void Framework::InputManagerTesting::SetMessageManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr messageManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

    middleLayer.SetMessageManager(messageManager);
}

void Framework::InputManagerTesting::SetEventManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr eventManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

    middleLayer.SetEventManager(eventManager);
}

void Framework::InputManagerTesting::SetSystemManagerTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr systemManager(std::make_shared<SystemManagerInterface>(MiddleLayerPlatform::Windows));

    middleLayer.SetSystemManager(systemManager);
}

void Framework::InputManagerTesting::SetResourceManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr resourceManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

    middleLayer.SetResourceManager(resourceManager);
}

void Framework::InputManagerTesting::SetAudioManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr audioManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

    middleLayer.SetAudioManager(audioManager);
}

void Framework::InputManagerTesting::SetCameraSystemsManagerTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr cameraSystemsManager(std::make_shared<CameraSystemsManagerInterface>(MiddleLayerPlatform::Windows));

    middleLayer.SetCameraSystemsManager(cameraSystemsManager);
}

void Framework::InputManagerTesting::SetRenderingManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr renderingManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

    middleLayer.SetRenderingManager(renderingManager);
}

void Framework::InputManagerTesting::SetGUIManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr guiManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

    middleLayer.SetGUIManager(guiManager);
}
