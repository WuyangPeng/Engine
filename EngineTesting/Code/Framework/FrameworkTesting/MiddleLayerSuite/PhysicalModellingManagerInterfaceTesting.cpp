///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 20:10)

#include "PhysicalModellingManagerInterfaceTesting.h"
#include "System/Windows/Flags/WindowsDisplayFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/Renderers/EnvironmentParameter.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"
#include "Framework/MiddleLayer/ObjectLogicInterface.h"
#include "Framework/MiddleLayer/PhysicalModellingManagerInterface.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/Flags/MouseTypes.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"

namespace Framework
{
    using TestingType = PhysicalModellingManagerInterface;
}

Framework::PhysicalModellingManagerInterfaceTesting::PhysicalModellingManagerInterfaceTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, PhysicalModellingManagerInterfaceTesting)

void Framework::PhysicalModellingManagerInterfaceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::PhysicalModellingManagerInterfaceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetMiddleLayerTest);
}

void Framework::PhysicalModellingManagerInterfaceTesting::MiddleLayerTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    ASSERT_TRUE(middleLayer.PreCreate());
    ASSERT_TRUE(middleLayer.Initialize());
    middleLayer.PreIdle();
    ASSERT_TRUE(middleLayer.Create(Rendering::EnvironmentParameter::Create()));
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

void Framework::PhysicalModellingManagerInterfaceTesting::SetMiddleLayerTest()
{
    ASSERT_THROW_EXCEPTION_0(SetNetworkManagerExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetInputManagerExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetObjectLogicManagerTest);
    ASSERT_THROW_EXCEPTION_0(SetPhysicalModellingManagerExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetMessageManagerExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetEventManagerExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetSystemManagerExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetResourceManagerExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetAudioManagerExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetCameraSystemsManagerExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetRenderingManagerExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetGUIManagerExceptionTest);
}

void Framework::PhysicalModellingManagerInterfaceTesting::SetNetworkManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    MiddleLayerInterfaceSharedPtr networkManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));

    middleLayer.SetNetworkManager(networkManager);
}

void Framework::PhysicalModellingManagerInterfaceTesting::SetInputManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    MiddleLayerInterfaceSharedPtr inputManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));

    middleLayer.SetInputManager(inputManager);
}

void Framework::PhysicalModellingManagerInterfaceTesting::SetObjectLogicManagerTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    MiddleLayerInterfaceSharedPtr objectLogicManager(std::make_shared<ObjectLogicInterface>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));

    middleLayer.SetObjectLogicManager(objectLogicManager);
}

void Framework::PhysicalModellingManagerInterfaceTesting::SetPhysicalModellingManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    MiddleLayerInterfaceSharedPtr physicalModellingManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));

    middleLayer.SetPhysicalModellingManager(physicalModellingManager);
}

void Framework::PhysicalModellingManagerInterfaceTesting::SetMessageManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    MiddleLayerInterfaceSharedPtr messageManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));

    middleLayer.SetMessageManager(messageManager);
}

void Framework::PhysicalModellingManagerInterfaceTesting::SetEventManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    MiddleLayerInterfaceSharedPtr eventManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));

    middleLayer.SetEventManager(eventManager);
}

void Framework::PhysicalModellingManagerInterfaceTesting::SetSystemManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    MiddleLayerInterfaceSharedPtr systemManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));

    middleLayer.SetSystemManager(systemManager);
}

void Framework::PhysicalModellingManagerInterfaceTesting::SetResourceManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    MiddleLayerInterfaceSharedPtr resourceManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));

    middleLayer.SetResourceManager(resourceManager);
}

void Framework::PhysicalModellingManagerInterfaceTesting::SetAudioManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    MiddleLayerInterfaceSharedPtr audioManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));

    middleLayer.SetAudioManager(audioManager);
}

void Framework::PhysicalModellingManagerInterfaceTesting::SetCameraSystemsManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    MiddleLayerInterfaceSharedPtr cameraSystemsManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));

    middleLayer.SetCameraSystemsManager(cameraSystemsManager);
}

void Framework::PhysicalModellingManagerInterfaceTesting::SetRenderingManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    MiddleLayerInterfaceSharedPtr renderingManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));

    middleLayer.SetRenderingManager(renderingManager);
}

void Framework::PhysicalModellingManagerInterfaceTesting::SetGUIManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    MiddleLayerInterfaceSharedPtr guiManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));

    middleLayer.SetGUIManager(guiManager);
}
