///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 20:08)

#include "EngineMiddleLayerContainerTesting.h"
#include "System/Windows/Flags/WindowsDisplayFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/RendererEngine/EnvironmentParameter.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MiddleLayer/ArtificialIntelligenceInterface.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainerDetail.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"
#include "Framework/MiddleLayer/ObjectLogicManagerDetail.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/Flags/MouseTypes.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"

Framework::EngineMiddleLayerContainerTesting::EngineMiddleLayerContainerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, EngineMiddleLayerContainerTesting)

void Framework::EngineMiddleLayerContainerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::EngineMiddleLayerContainerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultEngineMiddleLayerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EngineMiddleLayerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetMiddleLayerTest);
}

void Framework::EngineMiddleLayerContainerTesting::DefaultEngineMiddleLayerTest()
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    EngineMiddleLayerInterfaceSharedPtr middleLayer(std::make_shared<EngineMiddleLayerContainer<WindowApplicationTrait>>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));

#include STSTEM_WARNING_POP

    ASSERT_TRUE(middleLayer->PreCreate());
    ASSERT_TRUE(middleLayer->Create(Rendering::EnvironmentParameter::Create()));
    ASSERT_TRUE(middleLayer->Initialize());
    middleLayer->PreIdle();

    ASSERT_TRUE(middleLayer->Paint());
    ASSERT_TRUE(middleLayer->Move(WindowPoint()));
    ASSERT_TRUE(middleLayer->Resize(System::WindowsDisplay::MaxHide, WindowSize()));
    ASSERT_TRUE(middleLayer->KeyDown(0, WindowPoint()));
    ASSERT_TRUE(middleLayer->KeyUp(0, WindowPoint()));
    ASSERT_TRUE(middleLayer->SpecialKeyDown(0, WindowPoint()));
    ASSERT_TRUE(middleLayer->SpecialKeyUp(0, WindowPoint()));
    ASSERT_TRUE(middleLayer->MouseClick(MouseButtonsTypes::LeftButton, MouseStateTypes::MouseDown, WindowPoint(), VirtualKeysTypes()));
    ASSERT_TRUE(middleLayer->Motion(WindowPoint(), VirtualKeysTypes()));
    ASSERT_TRUE(middleLayer->PassiveMotion(WindowPoint()));
    ASSERT_TRUE(middleLayer->MouseWheel(0, WindowPoint(), VirtualKeysTypes()));
    ASSERT_TRUE(middleLayer->Idle(0));

    ASSERT_TRUE(middleLayer->Destroy());
    middleLayer->Terminate();
}

void Framework::EngineMiddleLayerContainerTesting::EngineMiddleLayerTest()
{
    using ObjectLogicManager = ObjectLogicManager<ObjectLogicManagerInterface, ArtificialIntelligenceInterface>;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    EngineMiddleLayerInterfaceSharedPtr middleLayer(std::make_shared<EngineMiddleLayerContainer<WindowApplicationTrait, InputManager, NetworkManagerInterface,
                                                                                                ObjectLogicManager, PhysicalModellingManagerInterface,
                                                                                                MessageManagerInterface, EventManagerInterface, SystemManagerInterface,
                                                                                                ResourceManagerInterface, AudioManagerInterface,
                                                                                                CameraSystemsManagerInterface, RenderingManagerInterface, GUIManagerInterface>>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));

#include STSTEM_WARNING_POP

    ASSERT_TRUE(middleLayer->PreCreate());
    ASSERT_TRUE(middleLayer->Create(Rendering::EnvironmentParameter::Create()));
    ASSERT_TRUE(middleLayer->Initialize());
    middleLayer->PreIdle();

    ASSERT_TRUE(middleLayer->Paint());
    ASSERT_TRUE(middleLayer->Move(WindowPoint()));
    ASSERT_TRUE(middleLayer->Resize(System::WindowsDisplay::MaxHide, WindowSize()));
    ASSERT_TRUE(middleLayer->KeyDown(0, WindowPoint()));
    ASSERT_TRUE(middleLayer->KeyUp(0, WindowPoint()));
    ASSERT_TRUE(middleLayer->SpecialKeyDown(0, WindowPoint()));
    ASSERT_TRUE(middleLayer->SpecialKeyUp(0, WindowPoint()));
    ASSERT_TRUE(middleLayer->MouseClick(MouseButtonsTypes::LeftButton, MouseStateTypes::MouseDown, WindowPoint(), VirtualKeysTypes()));
    ASSERT_TRUE(middleLayer->Motion(WindowPoint(), VirtualKeysTypes()));
    ASSERT_TRUE(middleLayer->PassiveMotion(WindowPoint()));
    ASSERT_TRUE(middleLayer->MouseWheel(0, WindowPoint(), VirtualKeysTypes()));
    ASSERT_TRUE(middleLayer->Idle(0));

    ASSERT_TRUE(middleLayer->Destroy());
    middleLayer->Terminate();
}

void Framework::EngineMiddleLayerContainerTesting::SetMiddleLayerTest()
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    EngineMiddleLayerInterfaceSharedPtr middleLayer(std::make_shared<EngineMiddleLayerContainer<WindowApplicationTrait>>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));

#include STSTEM_WARNING_POP

    NetworkManagerInterfaceSharedPtr networkManagerInterface(std::make_shared<NetworkManagerInterface>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));
    middleLayer->SetNetworkManager(networkManagerInterface);

    InputManagerInterfaceSharedPtr inputManagerInterface(std::make_shared<InputManagerInterface>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));
    middleLayer->SetInputManager(inputManagerInterface);

    ObjectLogicManagerInterfaceSharedPtr objectLogicManagerInterface(std::make_shared<ObjectLogicManagerInterface>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));
    middleLayer->SetObjectLogicManager(objectLogicManagerInterface);

    PhysicalModellingManagerInterfaceSharedPtr physicalModellingManagerInterface(std::make_shared<PhysicalModellingManagerInterface>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));
    middleLayer->SetPhysicalModellingManager(physicalModellingManagerInterface);

    MessageManagerInterfaceSharedPtr messageManagerInterface(std::make_shared<MessageManagerInterface>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));
    middleLayer->SetMessageManager(messageManagerInterface);

    EventManagerInterfaceSharedPtr eventManagerInterface(std::make_shared<EventManagerInterface>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));
    middleLayer->SetEventManager(eventManagerInterface);

    SystemManagerInterfaceSharedPtr systemManagerInterface(std::make_shared<SystemManagerInterface>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));
    middleLayer->SetSystemManager(systemManagerInterface);

    ResourceManagerInterfaceSharedPtr resourceManagerInterface(std::make_shared<ResourceManagerInterface>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));
    middleLayer->SetResourceManager(resourceManagerInterface);

    AudioManagerInterfaceSharedPtr audioManagerInterface(std::make_shared<AudioManagerInterface>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));
    middleLayer->SetAudioManager(audioManagerInterface);

    CameraSystemsManagerInterfaceSharedPtr cameraSystemsManagerInterface(std::make_shared<CameraSystemsManagerInterface>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));
    middleLayer->SetCameraSystemsManager(cameraSystemsManagerInterface);

    RenderingManagerInterfaceSharedPtr renderingManagerInterface(RenderingManagerInterface::CreateMiddleLayer(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));
    middleLayer->SetRenderingManager(renderingManagerInterface);

    GUIManagerInterfaceSharedPtr guiManagerInterface(std::make_shared<GUIManagerInterface>(MiddleLayerPlatform::Windows, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));
    middleLayer->SetGUIManager(guiManagerInterface);
}
