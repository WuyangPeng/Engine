///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 20:12)

#include "MiddleLayerInterfaceTestingBaseDetail.h"
#include "RenderingManagerInterfaceTesting.h"
#include "Test/RenderingManagerInterfaceTest.h"
#include "System/Windows/Flags/WindowsDisplayFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/RendererEngine/Renderer.h"
#include "Rendering/RendererEngine/RendererManager.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"
#include "Framework/MiddleLayer/RenderingManagerInterface.h"
#include "Framework/MiddleLayer/SystemManagerInterface.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/Flags/MouseTypes.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"

Framework::RenderingManagerInterfaceTesting::RenderingManagerInterfaceTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, RenderingManagerInterfaceTesting)

void Framework::RenderingManagerInterfaceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::RenderingManagerInterfaceTesting::MainTest()
{
    Rendering::RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerMemberTest<RenderingManagerInterface>);
    ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerExceptionTest);

    ASSERT_NOT_THROW_EXCEPTION_0(SetMiddleLayerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetSystemManagerTest);

    ASSERT_NOT_THROW_EXCEPTION_0(GetMiddleLayerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetConstMiddleLayerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetSystemManagerTest);

    ASSERT_NOT_THROW_EXCEPTION_0(RendererTest);
    ASSERT_THROW_EXCEPTION_0(RendererExceptionTest);
    ASSERT_THROW_EXCEPTION_0(ConstRendererExceptionTest);

    Rendering::RendererManager::Destroy();
}

void Framework::RenderingManagerInterfaceTesting::MiddleLayerTest()
{
    auto middleLayer = RenderingManagerInterface::CreateMiddleLayer(GetMiddleLayerPlatform(), GetEnvironmentDirectory());

    ASSERT_TRUE(middleLayer->PreCreate());
    ASSERT_TRUE(middleLayer->Create(Rendering::EnvironmentParameter::Create()));
    ASSERT_TRUE(middleLayer->Initialize());

    middleLayer->PreIdle();
    ASSERT_TRUE(middleLayer->Idle(0));

    ASSERT_TRUE(middleLayer->Paint());
    ASSERT_TRUE(middleLayer->Move(GetWindowPoint()));
    ASSERT_TRUE(middleLayer->Resize(System::WindowsDisplay::MaxHide, GetWindowSize()));

    ASSERT_TRUE(middleLayer->Destroy());
    middleLayer->Terminate();
}

void Framework::RenderingManagerInterfaceTesting::MiddleLayerExceptionTest()
{
    ASSERT_THROW_EXCEPTION_0(KeyUpExceptionTest<RenderingManagerInterface>);
    ASSERT_THROW_EXCEPTION_0(KeyDownExceptionTest<RenderingManagerInterface>);
    ASSERT_THROW_EXCEPTION_0(SpecialKeyUpExceptionTest<RenderingManagerInterface>);
    ASSERT_THROW_EXCEPTION_0(SpecialKeyDownExceptionTest<RenderingManagerInterface>);

    ASSERT_THROW_EXCEPTION_0(PassiveMotionExceptionTest<RenderingManagerInterface>);
    ASSERT_THROW_EXCEPTION_0(MotionExceptionTest<RenderingManagerInterface>);
    ASSERT_THROW_EXCEPTION_0(MouseWheelExceptionTest<RenderingManagerInterface>);
    ASSERT_THROW_EXCEPTION_0(MouseClickExceptionTest<RenderingManagerInterface>);
}

void Framework::RenderingManagerInterfaceTesting::SetMiddleLayerTest()
{
    ASSERT_THROW_EXCEPTION_1(SetManagerExceptionTest<EngineMiddleLayerInterface>, &EngineMiddleLayerInterface::SetNetworkManager);
    ASSERT_THROW_EXCEPTION_1(SetManagerExceptionTest<EngineMiddleLayerInterface>, &EngineMiddleLayerInterface::SetInputManager);
    ASSERT_THROW_EXCEPTION_1(SetManagerExceptionTest<EngineMiddleLayerInterface>, &EngineMiddleLayerInterface::SetObjectLogicManager);
    ASSERT_THROW_EXCEPTION_1(SetManagerExceptionTest<EngineMiddleLayerInterface>, &EngineMiddleLayerInterface::SetPhysicalModellingManager);
    ASSERT_THROW_EXCEPTION_1(SetManagerExceptionTest<EngineMiddleLayerInterface>, &EngineMiddleLayerInterface::SetMessageManager);
    ASSERT_THROW_EXCEPTION_1(SetManagerExceptionTest<EngineMiddleLayerInterface>, &EngineMiddleLayerInterface::SetEventManager);

    ASSERT_THROW_EXCEPTION_1(SetManagerExceptionTest<EngineMiddleLayerInterface>, &EngineMiddleLayerInterface::SetResourceManager);
    ASSERT_THROW_EXCEPTION_1(SetManagerExceptionTest<EngineMiddleLayerInterface>, &EngineMiddleLayerInterface::SetAudioManager);
    ASSERT_THROW_EXCEPTION_1(SetManagerExceptionTest<EngineMiddleLayerInterface>, &EngineMiddleLayerInterface::SetCameraSystemsManager);
    ASSERT_THROW_EXCEPTION_1(SetManagerExceptionTest<EngineMiddleLayerInterface>, &EngineMiddleLayerInterface::SetRenderingManager);
    ASSERT_THROW_EXCEPTION_1(SetManagerExceptionTest<EngineMiddleLayerInterface>, &EngineMiddleLayerInterface::SetGUIManager);
    ASSERT_THROW_EXCEPTION_1(SetManagerExceptionTest<EngineMiddleLayerInterface>, &EngineMiddleLayerInterface::SetEngineManager);
}

void Framework::RenderingManagerInterfaceTesting::SetSystemManagerTest()
{
    auto middleLayer = RenderingManagerInterface::CreateMiddleLayer(GetMiddleLayerPlatform(), GetEnvironmentDirectory());

    auto systemManager = std::make_shared<SystemManagerInterface>(GetMiddleLayerPlatform(), GetEnvironmentDirectory());

    middleLayer->SetSystemManager(systemManager);
}

void Framework::RenderingManagerInterfaceTesting::GetMiddleLayerTest()
{
    using Funtion = MiddleLayerInterfaceSharedPtr (RenderingManagerInterfaceTest::*)();

    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Funtion>(&RenderingManagerInterfaceTest::GetNetworkManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Funtion>(&RenderingManagerInterfaceTest::GetInputManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Funtion>(&RenderingManagerInterfaceTest::GetObjectLogicManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Funtion>(&RenderingManagerInterfaceTest::GetPhysicalModellingManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Funtion>(&RenderingManagerInterfaceTest::GetMessageManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Funtion>(&RenderingManagerInterfaceTest::GetEventManager));

    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Funtion>(&RenderingManagerInterfaceTest::GetResourceManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Funtion>(&RenderingManagerInterfaceTest::GetAudioManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Funtion>(&RenderingManagerInterfaceTest::GetCameraSystemsManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Funtion>(&RenderingManagerInterfaceTest::GetRenderingManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Funtion>(&RenderingManagerInterfaceTest::GetGUIManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Funtion>(&RenderingManagerInterfaceTest::GetEngineManager));
}

void Framework::RenderingManagerInterfaceTesting::GetConstMiddleLayerTest()
{
    using Funtion = ConstMiddleLayerInterfaceSharedPtr (RenderingManagerInterfaceTest::*)() const;

    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Funtion>(&RenderingManagerInterfaceTest::GetNetworkManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Funtion>(&RenderingManagerInterfaceTest::GetInputManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Funtion>(&RenderingManagerInterfaceTest::GetObjectLogicManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Funtion>(&RenderingManagerInterfaceTest::GetPhysicalModellingManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Funtion>(&RenderingManagerInterfaceTest::GetMessageManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Funtion>(&RenderingManagerInterfaceTest::GetEventManager));

    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Funtion>(&RenderingManagerInterfaceTest::GetResourceManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Funtion>(&RenderingManagerInterfaceTest::GetAudioManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Funtion>(&RenderingManagerInterfaceTest::GetCameraSystemsManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Funtion>(&RenderingManagerInterfaceTest::GetRenderingManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Funtion>(&RenderingManagerInterfaceTest::GetGUIManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Funtion>(&RenderingManagerInterfaceTest::GetEngineManager));
}

void Framework::RenderingManagerInterfaceTesting::GetSystemManagerTest()
{
    auto middleLayer = RenderingManagerInterfaceTest::CreateMiddleLayer(GetMiddleLayerPlatform(), GetEnvironmentDirectory());

    auto systemManager = std::make_shared<SystemManagerInterface>(GetMiddleLayerPlatform(), GetEnvironmentDirectory());

    middleLayer->SetSystemManager(systemManager);

    ASSERT_EQUAL(middleLayer->GetSystemManager(), systemManager);

    ConstRenderingManagerInterfaceTestSharedPtr constMiddleLayer = middleLayer;

    ASSERT_EQUAL(constMiddleLayer->GetSystemManager(), systemManager);
}

void Framework::RenderingManagerInterfaceTesting::RendererTest()
{
    auto middleLayer = RenderingManagerInterfaceTest::CreateMiddleLayer(GetMiddleLayerPlatform(), GetEnvironmentDirectory());

    ASSERT_TRUE(middleLayer->Create(Rendering::EnvironmentParameter::Create()));

    ASSERT_UNEQUAL_NULL_PTR(middleLayer->GetRendererSharedPtr());

    ConstRenderingManagerInterfaceTestSharedPtr constMiddleLayer = middleLayer;

    ASSERT_UNEQUAL_NULL_PTR(constMiddleLayer->GetRendererSharedPtr());
}

void Framework::RenderingManagerInterfaceTesting::RendererExceptionTest()
{
    auto middleLayer = RenderingManagerInterfaceTest::CreateMiddleLayer(GetMiddleLayerPlatform(), GetEnvironmentDirectory());

    auto renderer = middleLayer->GetRendererSharedPtr();
}

void Framework::RenderingManagerInterfaceTesting::ConstRendererExceptionTest()
{
    ConstRenderingManagerInterfaceTestSharedPtr middleLayer{ RenderingManagerInterfaceTest::CreateMiddleLayer(GetMiddleLayerPlatform(), GetEnvironmentDirectory()) };

    auto renderer = middleLayer->GetRendererSharedPtr();
}
