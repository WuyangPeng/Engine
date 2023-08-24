///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/12 17:52)

#include "EngineMiddleLayerInterfaceTesting.h"
#include "MiddleLayerInterfaceTestingBaseDetail.h"
#include "Test/EngineMiddleLayerInterfaceNullTest.h"
#include "Test/EngineMiddleLayerInterfaceTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/MiddleLayer/EngineMiddleLayerInterface.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"
#include "Framework/MiddleLayer/MiddleLayerInterface.h"

Framework::EngineMiddleLayerInterfaceTesting::EngineMiddleLayerInterfaceTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, EngineMiddleLayerInterfaceTesting)

void Framework::EngineMiddleLayerInterfaceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::EngineMiddleLayerInterfaceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerMemberTest<EngineMiddleLayerInterface>);
    ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerTest<EngineMiddleLayerInterface>);
    ASSERT_NOT_THROW_EXCEPTION_0(SetMiddleLayerTest);

    // 测试GetManager函数抛出异常
    ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerMemberTest<EngineMiddleLayerInterfaceTest>);
    ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerTest<EngineMiddleLayerInterfaceTest>);
    ASSERT_NOT_THROW_EXCEPTION_0(GetMiddleLayerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetConstMiddleLayerTest);

    // 测试GetManager函数返回空指针
    ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerMemberTest<EngineMiddleLayerInterfaceNullTest>);
    ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerTest<EngineMiddleLayerInterfaceNullTest>);
    ASSERT_NOT_THROW_EXCEPTION_0(GetNullMiddleLayerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetConstNullMiddleLayerTest);
}

void Framework::EngineMiddleLayerInterfaceTesting::SetMiddleLayerTest()
{
    ASSERT_THROW_EXCEPTION_1(SetManagerExceptionTest<EngineMiddleLayerInterface>, &EngineMiddleLayerInterface::SetNetworkManager);
    ASSERT_THROW_EXCEPTION_1(SetManagerExceptionTest<EngineMiddleLayerInterface>, &EngineMiddleLayerInterface::SetInputManager);
    ASSERT_THROW_EXCEPTION_1(SetManagerExceptionTest<EngineMiddleLayerInterface>, &EngineMiddleLayerInterface::SetObjectLogicManager);
    ASSERT_THROW_EXCEPTION_1(SetManagerExceptionTest<EngineMiddleLayerInterface>, &EngineMiddleLayerInterface::SetPhysicalModellingManager);
    ASSERT_THROW_EXCEPTION_1(SetManagerExceptionTest<EngineMiddleLayerInterface>, &EngineMiddleLayerInterface::SetMessageManager);
    ASSERT_THROW_EXCEPTION_1(SetManagerExceptionTest<EngineMiddleLayerInterface>, &EngineMiddleLayerInterface::SetEventManager);
    ASSERT_THROW_EXCEPTION_1(SetManagerExceptionTest<EngineMiddleLayerInterface>, &EngineMiddleLayerInterface::SetSystemManager);
    ASSERT_THROW_EXCEPTION_1(SetManagerExceptionTest<EngineMiddleLayerInterface>, &EngineMiddleLayerInterface::SetResourceManager);
    ASSERT_THROW_EXCEPTION_1(SetManagerExceptionTest<EngineMiddleLayerInterface>, &EngineMiddleLayerInterface::SetAudioManager);
    ASSERT_THROW_EXCEPTION_1(SetManagerExceptionTest<EngineMiddleLayerInterface>, &EngineMiddleLayerInterface::SetCameraSystemsManager);
    ASSERT_THROW_EXCEPTION_1(SetManagerExceptionTest<EngineMiddleLayerInterface>, &EngineMiddleLayerInterface::SetRenderingManager);
    ASSERT_THROW_EXCEPTION_1(SetManagerExceptionTest<EngineMiddleLayerInterface>, &EngineMiddleLayerInterface::SetGUIManager);
    ASSERT_THROW_EXCEPTION_1(SetManagerExceptionTest<EngineMiddleLayerInterface>, &EngineMiddleLayerInterface::SetEngineManager);
}

void Framework::EngineMiddleLayerInterfaceTesting::GetMiddleLayerTest()
{
    using Function = MiddleLayerInterfaceSharedPtr (EngineMiddleLayerInterfaceTest::*)();

    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<EngineMiddleLayerInterfaceTest>,
                             static_cast<Function>(&EngineMiddleLayerInterfaceTest::GetNetworkManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<EngineMiddleLayerInterfaceTest>,
                             static_cast<Function>(&EngineMiddleLayerInterfaceTest::GetInputManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<EngineMiddleLayerInterfaceTest>,
                             static_cast<Function>(&EngineMiddleLayerInterfaceTest::GetObjectLogicManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<EngineMiddleLayerInterfaceTest>,
                             static_cast<Function>(&EngineMiddleLayerInterfaceTest::GetPhysicalModellingManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<EngineMiddleLayerInterfaceTest>,
                             static_cast<Function>(&EngineMiddleLayerInterfaceTest::GetMessageManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<EngineMiddleLayerInterfaceTest>,
                             static_cast<Function>(&EngineMiddleLayerInterfaceTest::GetEventManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<EngineMiddleLayerInterfaceTest>,
                             static_cast<Function>(&EngineMiddleLayerInterfaceTest::GetSystemManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<EngineMiddleLayerInterfaceTest>,
                             static_cast<Function>(&EngineMiddleLayerInterfaceTest::GetResourceManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<EngineMiddleLayerInterfaceTest>,
                             static_cast<Function>(&EngineMiddleLayerInterfaceTest::GetAudioManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<EngineMiddleLayerInterfaceTest>,
                             static_cast<Function>(&EngineMiddleLayerInterfaceTest::GetCameraSystemsManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<EngineMiddleLayerInterfaceTest>,
                             static_cast<Function>(&EngineMiddleLayerInterfaceTest::GetRenderingManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<EngineMiddleLayerInterfaceTest>,
                             static_cast<Function>(&EngineMiddleLayerInterfaceTest::GetGUIManager));
    ASSERT_THROW_EXCEPTION_1(GetManagerExceptionTest<EngineMiddleLayerInterfaceTest>,
                             static_cast<Function>(&EngineMiddleLayerInterfaceTest::GetEngineManager));
}

void Framework::EngineMiddleLayerInterfaceTesting::GetConstMiddleLayerTest()
{
    using Function = ConstMiddleLayerInterfaceSharedPtr (EngineMiddleLayerInterfaceTest::*)() const;

    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<EngineMiddleLayerInterfaceTest>,
                             static_cast<Function>(&EngineMiddleLayerInterfaceTest::GetNetworkManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<EngineMiddleLayerInterfaceTest>,
                             static_cast<Function>(&EngineMiddleLayerInterfaceTest::GetInputManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<EngineMiddleLayerInterfaceTest>,
                             static_cast<Function>(&EngineMiddleLayerInterfaceTest::GetObjectLogicManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<EngineMiddleLayerInterfaceTest>,
                             static_cast<Function>(&EngineMiddleLayerInterfaceTest::GetPhysicalModellingManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<EngineMiddleLayerInterfaceTest>,
                             static_cast<Function>(&EngineMiddleLayerInterfaceTest::GetMessageManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<EngineMiddleLayerInterfaceTest>,
                             static_cast<Function>(&EngineMiddleLayerInterfaceTest::GetEventManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<EngineMiddleLayerInterfaceTest>,
                             static_cast<Function>(&EngineMiddleLayerInterfaceTest::GetSystemManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<EngineMiddleLayerInterfaceTest>,
                             static_cast<Function>(&EngineMiddleLayerInterfaceTest::GetResourceManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<EngineMiddleLayerInterfaceTest>,
                             static_cast<Function>(&EngineMiddleLayerInterfaceTest::GetAudioManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<EngineMiddleLayerInterfaceTest>,
                             static_cast<Function>(&EngineMiddleLayerInterfaceTest::GetCameraSystemsManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<EngineMiddleLayerInterfaceTest>,
                             static_cast<Function>(&EngineMiddleLayerInterfaceTest::GetRenderingManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<EngineMiddleLayerInterfaceTest>,
                             static_cast<Function>(&EngineMiddleLayerInterfaceTest::GetGUIManager));
    ASSERT_THROW_EXCEPTION_1(GetConstManagerExceptionTest<EngineMiddleLayerInterfaceTest>,
                             static_cast<Function>(&EngineMiddleLayerInterfaceTest::GetEngineManager));
}

void Framework::EngineMiddleLayerInterfaceTesting::GetNullMiddleLayerTest()
{
    const auto middleLayer = std::make_shared<EngineMiddleLayerInterfaceNullTest>(GetMiddleLayerPlatform(), GetEnvironmentDirectory());

    ASSERT_EQUAL_NULL_PTR(middleLayer->GetNetworkManager());
    ASSERT_EQUAL_NULL_PTR(middleLayer->GetInputManager());
    ASSERT_EQUAL_NULL_PTR(middleLayer->GetObjectLogicManager());
    ASSERT_EQUAL_NULL_PTR(middleLayer->GetPhysicalModellingManager());
    ASSERT_EQUAL_NULL_PTR(middleLayer->GetMessageManager());
    ASSERT_EQUAL_NULL_PTR(middleLayer->GetEventManager());
    ASSERT_EQUAL_NULL_PTR(middleLayer->GetSystemManager());
    ASSERT_EQUAL_NULL_PTR(middleLayer->GetResourceManager());
    ASSERT_EQUAL_NULL_PTR(middleLayer->GetAudioManager());
    ASSERT_EQUAL_NULL_PTR(middleLayer->GetCameraSystemsManager());
    ASSERT_EQUAL_NULL_PTR(middleLayer->GetRenderingManager());
    ASSERT_EQUAL_NULL_PTR(middleLayer->GetGUIManager());
    ASSERT_EQUAL_NULL_PTR(middleLayer->GetEngineManager());
}

void Framework::EngineMiddleLayerInterfaceTesting::GetConstNullMiddleLayerTest()
{
    const auto middleLayer = std::make_shared<EngineMiddleLayerInterfaceNullTest>(GetMiddleLayerPlatform(), GetEnvironmentDirectory());

    ASSERT_EQUAL_NULL_PTR(middleLayer->GetNetworkManager());
    ASSERT_EQUAL_NULL_PTR(middleLayer->GetInputManager());
    ASSERT_EQUAL_NULL_PTR(middleLayer->GetObjectLogicManager());
    ASSERT_EQUAL_NULL_PTR(middleLayer->GetPhysicalModellingManager());
    ASSERT_EQUAL_NULL_PTR(middleLayer->GetMessageManager());
    ASSERT_EQUAL_NULL_PTR(middleLayer->GetEventManager());
    ASSERT_EQUAL_NULL_PTR(middleLayer->GetSystemManager());
    ASSERT_EQUAL_NULL_PTR(middleLayer->GetResourceManager());
    ASSERT_EQUAL_NULL_PTR(middleLayer->GetAudioManager());
    ASSERT_EQUAL_NULL_PTR(middleLayer->GetCameraSystemsManager());
    ASSERT_EQUAL_NULL_PTR(middleLayer->GetRenderingManager());
    ASSERT_EQUAL_NULL_PTR(middleLayer->GetGUIManager());
    ASSERT_EQUAL_NULL_PTR(middleLayer->GetEngineManager());
}
