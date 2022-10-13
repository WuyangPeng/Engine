///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/24 18:12)

#include "ObjectLogicManagerTesting.h"
#include "System/Windows/Flags/WindowsDisplayFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/Renderers/EnvironmentParameter.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MiddleLayer/ArtificialIntellegenceInterface.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"
#include "Framework/MiddleLayer/InputManagerInterface.h"
#include "Framework/MiddleLayer/MessageManagerInterface.h"
#include "Framework/MiddleLayer/NetworkManagerInterface.h"
#include "Framework/MiddleLayer/ObjectLogicInterface.h"
#include "Framework/MiddleLayer/ObjectLogicManagerDetail.h"
#include "Framework/MiddleLayer/PhysicalModellingManagerInterface.h"
#include "Framework/MiddleLayer/SystemManagerInterface.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/Flags/MouseTypes.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"

namespace Framework
{
    using TestingType = ObjectLogicManager<ObjectLogicInterface, ArtificialIntellegenceInterface>;
}

Framework::ObjectLogicManagerTesting::ObjectLogicManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ObjectLogicManagerTesting)

void Framework::ObjectLogicManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::ObjectLogicManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetMiddleLayerTest);
}

void Framework::ObjectLogicManagerTesting::MiddleLayerTest()
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

void Framework::ObjectLogicManagerTesting::SetMiddleLayerTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SetNetworkManagerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetInputManagerTest);
    ASSERT_THROW_EXCEPTION_0(SetObjectLogicManagerExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetPhysicalModellingManagerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetMessageManagerTest);
    ASSERT_THROW_EXCEPTION_0(SetEventManagerExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetSystemManagerTest);
    ASSERT_THROW_EXCEPTION_0(SetResourceManagerExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetAudioManagerExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetCameraSystemsManagerExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetRenderingManagerExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetGUIManagerExceptionTest);
}

void Framework::ObjectLogicManagerTesting::SetNetworkManagerTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    MiddleLayerInterfaceSharedPtr networkManager(std::make_shared<NetworkManagerInterface>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));

    middleLayer.SetNetworkManager(networkManager);
}

void Framework::ObjectLogicManagerTesting::SetInputManagerTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    MiddleLayerInterfaceSharedPtr inputManager(std::make_shared<InputManagerInterface>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));

    middleLayer.SetInputManager(inputManager);
}

void Framework::ObjectLogicManagerTesting::SetObjectLogicManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    MiddleLayerInterfaceSharedPtr objectLogicManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));

    middleLayer.SetObjectLogicManager(objectLogicManager);
}

void Framework::ObjectLogicManagerTesting::SetPhysicalModellingManagerTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    MiddleLayerInterfaceSharedPtr physicalModellingManager(std::make_shared<PhysicalModellingManagerInterface>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));

    middleLayer.SetPhysicalModellingManager(physicalModellingManager);
}

void Framework::ObjectLogicManagerTesting::SetMessageManagerTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    MiddleLayerInterfaceSharedPtr messageManager(std::make_shared<MessageManagerInterface>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));

    middleLayer.SetMessageManager(messageManager);
}

void Framework::ObjectLogicManagerTesting::SetEventManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    MiddleLayerInterfaceSharedPtr eventManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));

    middleLayer.SetEventManager(eventManager);
}

void Framework::ObjectLogicManagerTesting::SetSystemManagerTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    MiddleLayerInterfaceSharedPtr systemManager(std::make_shared<SystemManagerInterface>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));

    middleLayer.SetSystemManager(systemManager);
}

void Framework::ObjectLogicManagerTesting::SetResourceManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    MiddleLayerInterfaceSharedPtr resourceManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));

    middleLayer.SetResourceManager(resourceManager);
}

void Framework::ObjectLogicManagerTesting::SetAudioManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    MiddleLayerInterfaceSharedPtr audioManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));

    middleLayer.SetAudioManager(audioManager);
}

void Framework::ObjectLogicManagerTesting::SetCameraSystemsManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    MiddleLayerInterfaceSharedPtr cameraSystemsManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));

    middleLayer.SetCameraSystemsManager(cameraSystemsManager);
}

void Framework::ObjectLogicManagerTesting::SetRenderingManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    MiddleLayerInterfaceSharedPtr renderingManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));

    middleLayer.SetRenderingManager(renderingManager);
}

void Framework::ObjectLogicManagerTesting::SetGUIManagerExceptionTest()
{
    TestingType middleLayer(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    MiddleLayerInterfaceSharedPtr guiManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));

    middleLayer.SetGUIManager(guiManager);
}
