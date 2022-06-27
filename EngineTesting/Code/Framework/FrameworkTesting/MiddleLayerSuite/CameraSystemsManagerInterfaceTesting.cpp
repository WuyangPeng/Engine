///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/26 22:44)

#include "CameraSystemsManagerInterfaceTesting.h"
#include "System/Windows/Flags/WindowsDisplayFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MiddleLayer/CameraSystemsManagerInterface.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"
#include "Framework/MiddleLayer/GUIManagerInterface.h"
#include "Framework/MiddleLayer/ResourceManagerInterface.h"
#include "Framework/MiddleLayer/SystemManagerInterface.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/Flags/MouseTypes.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"

namespace Framework
{
    using TestingType = CameraSystemsManagerInterface;
}

Framework::CameraSystemsManagerInterfaceTesting::CameraSystemsManagerInterfaceTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, CameraSystemsManagerInterfaceTesting)

void Framework::CameraSystemsManagerInterfaceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::CameraSystemsManagerInterfaceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetMiddleLayerTest);
}

void Framework::CameraSystemsManagerInterfaceTesting::MiddleLayerTest()
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

void Framework::CameraSystemsManagerInterfaceTesting::SetMiddleLayerTest()
{
    ASSERT_THROW_EXCEPTION_0(SetNetworkManagerExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetInputManagerExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetObjectLogicManagerExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetPhysicalModellingManagerExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetMessageManagerExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetEventManagerExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetSystemManagerTest);
    ASSERT_THROW_EXCEPTION_0(SetResourceManagerExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetAudioManagerExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetCameraSystemsManagerExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetRenderingManagerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetGUIManagerTest);
}

void Framework::CameraSystemsManagerInterfaceTesting::SetNetworkManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr networkManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

    middleLayer.SetNetworkManager(networkManager);
}

void Framework::CameraSystemsManagerInterfaceTesting::SetInputManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr inputManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

    middleLayer.SetInputManager(inputManager);
}

void Framework::CameraSystemsManagerInterfaceTesting::SetObjectLogicManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr objectLogicManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

    middleLayer.SetObjectLogicManager(objectLogicManager);
}

void Framework::CameraSystemsManagerInterfaceTesting::SetPhysicalModellingManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr physicalModellingManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

    middleLayer.SetPhysicalModellingManager(physicalModellingManager);
}

void Framework::CameraSystemsManagerInterfaceTesting::SetMessageManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr messageManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

    middleLayer.SetMessageManager(messageManager);
}

void Framework::CameraSystemsManagerInterfaceTesting::SetEventManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr eventManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

    middleLayer.SetEventManager(eventManager);
}

void Framework::CameraSystemsManagerInterfaceTesting::SetSystemManagerTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr systemManager(std::make_shared<SystemManagerInterface>(MiddleLayerPlatform::Windows));

    middleLayer.SetSystemManager(systemManager);
}

void Framework::CameraSystemsManagerInterfaceTesting::SetResourceManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr resourceManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

    middleLayer.SetResourceManager(resourceManager);
}

void Framework::CameraSystemsManagerInterfaceTesting::SetAudioManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr audioManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

    middleLayer.SetAudioManager(audioManager);
}

void Framework::CameraSystemsManagerInterfaceTesting::SetCameraSystemsManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr cameraSystemsManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

    middleLayer.SetCameraSystemsManager(cameraSystemsManager);
}

void Framework::CameraSystemsManagerInterfaceTesting::SetRenderingManagerTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr renderingManager(std::make_shared<ResourceManagerInterface>(MiddleLayerPlatform::Windows));

    middleLayer.SetRenderingManager(renderingManager);
}

void Framework::CameraSystemsManagerInterfaceTesting::SetGUIManagerTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows);

    MiddleLayerInterfaceSharedPtr guiManager(std::make_shared<GUIManagerInterface>(MiddleLayerPlatform::Windows));

    middleLayer.SetGUIManager(guiManager);
}
