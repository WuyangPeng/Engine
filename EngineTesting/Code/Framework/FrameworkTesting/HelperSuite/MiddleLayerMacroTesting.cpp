///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 20:19)

#include "MiddleLayerMacroTesting.h"
#include "Detail/ChildHelperInterface.h"
#include "Detail/ChildHelperMiddleLayerFlags.h"
#include "Detail/HelperManagerInterface.h"
#include "Detail/HelperMiddleLayerFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/MiddleLayer/AudioManagerInterface.h"
#include "Framework/MiddleLayer/CameraSystemsManagerInterface.h"
#include "Framework/MiddleLayer/EventManagerInterface.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"
#include "Framework/MiddleLayer/GUIManagerInterface.h"
#include "Framework/MiddleLayer/InputManagerInterface.h"
#include "Framework/MiddleLayer/MessageManagerInterface.h"
#include "Framework/MiddleLayer/NetworkManagerInterface.h"
#include "Framework/MiddleLayer/ObjectLogicManagerInterface.h"
#include "Framework/MiddleLayer/PhysicalModellingManagerInterface.h"
#include "Framework/MiddleLayer/RenderingManagerInterface.h"
#include "Framework/MiddleLayer/ResourceManagerInterface.h"
#include "Framework/MiddleLayer/SystemManagerInterface.h"

Framework::MiddleLayerMacroTesting::MiddleLayerMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, MiddleLayerMacroTesting)

void Framework::MiddleLayerMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::MiddleLayerMacroTesting::MainTest()
{
    // MiddleLayerMacro宏供MiddleLayer模块内部使用。

    ASSERT_NOT_THROW_EXCEPTION_0(HelperManagerSuccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ChildHelperManagerSuccessTest);

    ASSERT_THROW_EXCEPTION_0(HelperManagerNetworkExceptionTest);
    ASSERT_THROW_EXCEPTION_0(HelperManagerPhysicalModellingExceptionTest);
    ASSERT_THROW_EXCEPTION_0(HelperManagerSystemExceptionTest);
    ASSERT_THROW_EXCEPTION_0(HelperManagerGUIExceptionTest);

    ASSERT_THROW_EXCEPTION_0(ChildHelperManagerNetworkExceptionTest);
    ASSERT_THROW_EXCEPTION_0(ChildHelperManagerPhysicalModellingExceptionTest);
    ASSERT_THROW_EXCEPTION_0(ChildHelperManagerSystemExceptionTest);
    ASSERT_THROW_EXCEPTION_0(ChildHelperManagerGUIExceptionTest);
}

void Framework::MiddleLayerMacroTesting::HelperManagerSuccessTest()
{
    constexpr auto middleLayerPlatform = MiddleLayerPlatform::Windows;
    HelperManagerInterface helperManagerInterface{ middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    auto inputManager = std::make_shared<InputManagerInterface>(middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });
    helperManagerInterface.SetInputManager(inputManager);

    auto objectLogicManager = std::make_shared<ObjectLogicManagerInterface>(middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });
    helperManagerInterface.SetObjectLogicManager(objectLogicManager);

    auto messageManager = std::make_shared<MessageManagerInterface>(middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });
    helperManagerInterface.SetMessageManager(messageManager);

    auto eventManager = std::make_shared<EventManagerInterface>(middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });
    helperManagerInterface.SetEventManager(eventManager);

    auto resourceManager = std::make_shared<ResourceManagerInterface>(middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });
    helperManagerInterface.SetResourceManager(resourceManager);

    auto audioManager = std::make_shared<AudioManagerInterface>(middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });
    helperManagerInterface.SetAudioManager(audioManager);

    auto cameraSystemsManager = std::make_shared<CameraSystemsManagerInterface>(middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });
    helperManagerInterface.SetCameraSystemsManager(cameraSystemsManager);

    auto renderingManager = RenderingManagerInterface::CreateMiddleLayer(middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });
    helperManagerInterface.SetRenderingManager(renderingManager);

    std::shared_ptr<EngineMiddleLayerInterface> engineMiddleLayer{ EngineMiddleLayerInterface::CreateMiddleLayer(middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }) };
    helperManagerInterface.SetEngineManager(engineMiddleLayer);

    ASSERT_EQUAL(helperManagerInterface.GetManager(HelperMiddleLayer::Input), inputManager);
    ASSERT_EQUAL(helperManagerInterface.GetManager(HelperMiddleLayer::ObjectLogic), objectLogicManager);
    ASSERT_EQUAL(helperManagerInterface.GetManager(HelperMiddleLayer::Message), messageManager);
    ASSERT_EQUAL(helperManagerInterface.GetManager(HelperMiddleLayer::Event), eventManager);
    ASSERT_EQUAL(helperManagerInterface.GetManager(HelperMiddleLayer::Resource), resourceManager);
    ASSERT_EQUAL(helperManagerInterface.GetManager(HelperMiddleLayer::Audio), audioManager);
    ASSERT_EQUAL(helperManagerInterface.GetManager(HelperMiddleLayer::CameraSystems), cameraSystemsManager);
    ASSERT_EQUAL(helperManagerInterface.GetManager(HelperMiddleLayer::Rendering), renderingManager);
    ASSERT_EQUAL(helperManagerInterface.GetManager(HelperMiddleLayer::Engine), engineMiddleLayer);
}

void Framework::MiddleLayerMacroTesting::ChildHelperManagerSuccessTest()
{
    constexpr auto middleLayerPlatform = MiddleLayerPlatform::Windows;
    ChildHelperInterface childHelperManagerInterface{ middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    auto inputManager = std::make_shared<InputManagerInterface>(middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });
    childHelperManagerInterface.SetInputManager(inputManager);

    auto objectLogicManager = std::make_shared<ObjectLogicManagerInterface>(middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });
    childHelperManagerInterface.SetObjectLogicManager(objectLogicManager);

    auto messageManager = std::make_shared<MessageManagerInterface>(middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });
    childHelperManagerInterface.SetMessageManager(messageManager);

    auto eventManager = std::make_shared<EventManagerInterface>(middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });
    childHelperManagerInterface.SetEventManager(eventManager);

    auto resourceManager = std::make_shared<ResourceManagerInterface>(middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });
    childHelperManagerInterface.SetResourceManager(resourceManager);

    auto audioManager = std::make_shared<AudioManagerInterface>(middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });
    childHelperManagerInterface.SetAudioManager(audioManager);

    auto cameraSystemsManager = std::make_shared<CameraSystemsManagerInterface>(middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });
    childHelperManagerInterface.SetCameraSystemsManager(cameraSystemsManager);

    auto renderingManager = RenderingManagerInterface::CreateMiddleLayer(middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });
    childHelperManagerInterface.SetRenderingManager(renderingManager);

    std::shared_ptr<EngineMiddleLayerInterface> engineMiddleLayer{ EngineMiddleLayerInterface::CreateMiddleLayer(middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }) };
    childHelperManagerInterface.SetEngineManager(engineMiddleLayer);

    ASSERT_EQUAL(childHelperManagerInterface.GetManager(ChildHelperMiddleLayer::Input), inputManager);
    ASSERT_EQUAL(childHelperManagerInterface.GetManager(ChildHelperMiddleLayer::ObjectLogic), objectLogicManager);
    ASSERT_EQUAL(childHelperManagerInterface.GetManager(ChildHelperMiddleLayer::Message), messageManager);
    ASSERT_EQUAL(childHelperManagerInterface.GetManager(ChildHelperMiddleLayer::Event), eventManager);
    ASSERT_EQUAL(childHelperManagerInterface.GetManager(ChildHelperMiddleLayer::Resource), resourceManager);
    ASSERT_EQUAL(childHelperManagerInterface.GetManager(ChildHelperMiddleLayer::Audio), audioManager);
    ASSERT_EQUAL(childHelperManagerInterface.GetManager(ChildHelperMiddleLayer::CameraSystems), cameraSystemsManager);
    ASSERT_EQUAL(childHelperManagerInterface.GetManager(ChildHelperMiddleLayer::Rendering), renderingManager);
    ASSERT_EQUAL(childHelperManagerInterface.GetManager(ChildHelperMiddleLayer::Engine), engineMiddleLayer);
}

void Framework::MiddleLayerMacroTesting::HelperManagerNetworkExceptionTest()
{
    constexpr auto middleLayerPlatform = MiddleLayerPlatform::Windows;
    HelperManagerInterface helperManagerInterface{ middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    auto networkManager = std::make_shared<NetworkManagerInterface>(middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    helperManagerInterface.SetNetworkManager(networkManager);
}

void Framework::MiddleLayerMacroTesting::HelperManagerPhysicalModellingExceptionTest()
{
    constexpr auto middleLayerPlatform = MiddleLayerPlatform::Windows;
    HelperManagerInterface helperManagerInterface{ middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    auto physicalModellingManager = std::make_shared<PhysicalModellingManagerInterface>(middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    helperManagerInterface.SetPhysicalModellingManager(physicalModellingManager);
}

void Framework::MiddleLayerMacroTesting::HelperManagerSystemExceptionTest()
{
    constexpr auto middleLayerPlatform = MiddleLayerPlatform::Windows;
    HelperManagerInterface helperManagerInterface{ middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    auto systemManager = std::make_shared<SystemManagerInterface>(middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    helperManagerInterface.SetSystemManager(systemManager);
}

void Framework::MiddleLayerMacroTesting::HelperManagerGUIExceptionTest()
{
    constexpr auto middleLayerPlatform = MiddleLayerPlatform::Windows;
    HelperManagerInterface helperManagerInterface{ middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    auto guiManager = std::make_shared<GUIManagerInterface>(middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    helperManagerInterface.SetGUIManager(guiManager);
}

void Framework::MiddleLayerMacroTesting::ChildHelperManagerNetworkExceptionTest()
{
    constexpr auto middleLayerPlatform = MiddleLayerPlatform::Windows;
    ChildHelperInterface childHelperManagerInterface{ middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    auto networkManager = std::make_shared<NetworkManagerInterface>(middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    childHelperManagerInterface.SetNetworkManager(networkManager);
}

void Framework::MiddleLayerMacroTesting::ChildHelperManagerPhysicalModellingExceptionTest()
{
    constexpr auto middleLayerPlatform = MiddleLayerPlatform::Windows;
    ChildHelperInterface childHelperManagerInterface{ middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    auto physicalModellingManager = std::make_shared<PhysicalModellingManagerInterface>(middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    childHelperManagerInterface.SetPhysicalModellingManager(physicalModellingManager);
}

void Framework::MiddleLayerMacroTesting::ChildHelperManagerSystemExceptionTest()
{
    constexpr auto middleLayerPlatform = MiddleLayerPlatform::Windows;
    ChildHelperInterface childHelperManagerInterface{ middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    auto systemManager = std::make_shared<SystemManagerInterface>(middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    childHelperManagerInterface.SetSystemManager(systemManager);
}

void Framework::MiddleLayerMacroTesting::ChildHelperManagerGUIExceptionTest()
{
    constexpr auto middleLayerPlatform = MiddleLayerPlatform::Windows;
    ChildHelperInterface childHelperManagerInterface{ middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    auto guiManager = std::make_shared<GUIManagerInterface>(middleLayerPlatform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    childHelperManagerInterface.SetGUIManager(guiManager);
}
