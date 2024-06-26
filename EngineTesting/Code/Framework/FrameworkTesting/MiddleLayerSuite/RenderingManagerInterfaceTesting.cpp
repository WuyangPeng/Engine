///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 11:09)

#include "MiddleLayerInterfaceTestingBaseDetail.h"
#include "RenderingManagerInterfaceTesting.h"
#include "Test/RenderingManagerInterfaceTest.h"
#include "System/Windows/Flags/WindowsDisplayFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"
#include "Framework/MiddleLayer/RenderingManagerInterface.h"
#include "Framework/MiddleLayer/SystemManagerInterface.h"
#include "Framework/WindowCreate/WindowPoint.h"

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
}

void Framework::RenderingManagerInterfaceTesting::MiddleLayerTest()
{
    const auto middleLayer = std::make_shared<RenderingManagerInterface>(GetMiddleLayerPlatform(), GetEnvironmentDirectory());

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
    const auto middleLayer = std::make_shared<RenderingManagerInterface>(GetMiddleLayerPlatform(), GetEnvironmentDirectory());

    const auto systemManager = std::make_shared<SystemManagerInterface>(GetMiddleLayerPlatform(), GetEnvironmentDirectory());

    middleLayer->SetSystemManager(systemManager);
}

void Framework::RenderingManagerInterfaceTesting::GetMiddleLayerTest()
{
    using Function = MiddleLayerInterfaceSharedPtr (RenderingManagerInterfaceTest::*)();

    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Function>(&RenderingManagerInterfaceTest::GetNetworkManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Function>(&RenderingManagerInterfaceTest::GetInputManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Function>(&RenderingManagerInterfaceTest::GetObjectLogicManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Function>(&RenderingManagerInterfaceTest::GetPhysicalModellingManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Function>(&RenderingManagerInterfaceTest::GetMessageManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Function>(&RenderingManagerInterfaceTest::GetEventManager));

    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Function>(&RenderingManagerInterfaceTest::GetResourceManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Function>(&RenderingManagerInterfaceTest::GetAudioManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Function>(&RenderingManagerInterfaceTest::GetCameraSystemsManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Function>(&RenderingManagerInterfaceTest::GetRenderingManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Function>(&RenderingManagerInterfaceTest::GetGUIManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Function>(&RenderingManagerInterfaceTest::GetEngineManager));
}

void Framework::RenderingManagerInterfaceTesting::GetConstMiddleLayerTest()
{
    using Function = ConstMiddleLayerInterfaceSharedPtr (RenderingManagerInterfaceTest::*)() const;

    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Function>(&RenderingManagerInterfaceTest::GetNetworkManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Function>(&RenderingManagerInterfaceTest::GetInputManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Function>(&RenderingManagerInterfaceTest::GetObjectLogicManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Function>(&RenderingManagerInterfaceTest::GetPhysicalModellingManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Function>(&RenderingManagerInterfaceTest::GetMessageManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Function>(&RenderingManagerInterfaceTest::GetEventManager));

    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Function>(&RenderingManagerInterfaceTest::GetResourceManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Function>(&RenderingManagerInterfaceTest::GetAudioManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Function>(&RenderingManagerInterfaceTest::GetCameraSystemsManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Function>(&RenderingManagerInterfaceTest::GetRenderingManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Function>(&RenderingManagerInterfaceTest::GetGUIManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<RenderingManagerInterfaceTest>,
                             static_cast<Function>(&RenderingManagerInterfaceTest::GetEngineManager));
}

void Framework::RenderingManagerInterfaceTesting::GetSystemManagerTest()
{
    const auto middleLayer = RenderingManagerInterfaceTest::CreateMiddleLayer(GetMiddleLayerPlatform(), GetEnvironmentDirectory());

    const auto systemManager = std::make_shared<SystemManagerInterface>(GetMiddleLayerPlatform(), GetEnvironmentDirectory());

    middleLayer->SetSystemManager(systemManager);

    ASSERT_EQUAL(middleLayer->GetSystemManager(), systemManager);

    const auto constMiddleLayer = middleLayer;

    ASSERT_EQUAL(constMiddleLayer->GetSystemManager(), systemManager);
}

void Framework::RenderingManagerInterfaceTesting::RendererTest()
{
    const auto middleLayer = RenderingManagerInterfaceTest::CreateMiddleLayer(GetMiddleLayerPlatform(), GetEnvironmentDirectory());

    ASSERT_TRUE(middleLayer->Create(Rendering::EnvironmentParameter::Create()));

    ASSERT_UNEQUAL_NULL_PTR(middleLayer->GetRendererSharedPtr());

    const auto constMiddleLayer = middleLayer;

    ASSERT_UNEQUAL_NULL_PTR(constMiddleLayer->GetRendererSharedPtr());
}

void Framework::RenderingManagerInterfaceTesting::RendererExceptionTest()
{
    const auto middleLayer = RenderingManagerInterfaceTest::CreateMiddleLayer(GetMiddleLayerPlatform(), GetEnvironmentDirectory());

    auto renderer = middleLayer->GetRendererSharedPtr();
}

void Framework::RenderingManagerInterfaceTesting::ConstRendererExceptionTest()
{
    const ConstRenderingManagerInterfaceTestSharedPtr middleLayer{ RenderingManagerInterfaceTest::CreateMiddleLayer(GetMiddleLayerPlatform(), GetEnvironmentDirectory()) };

    auto renderer = middleLayer->GetRendererSharedPtr();
}
