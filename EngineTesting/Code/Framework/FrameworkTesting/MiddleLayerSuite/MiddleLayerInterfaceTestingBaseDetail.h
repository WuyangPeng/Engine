///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 19:56)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_MIDDLE_LAYER_INTERFACE_TESTING_BASE_DETAIL_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_MIDDLE_LAYER_INTERFACE_TESTING_BASE_DETAIL_H

#include "MiddleLayerInterfaceTestingBase.h"
#include "System/Windows/Flags/WindowsDisplayFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Rendering/Renderers/EnvironmentParameter.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"
#include "Framework/WindowProcess/Flags/MouseTypes.h"

template <typename TestingType>
void Framework::MiddleLayerInterfaceTestingBase::MiddleLayerMemberTest()
{
    auto middleLayer = TestingType::CreateMiddleLayer(middleLayerPlatform, environmentDirectory);

    ASSERT_ENUM_EQUAL(middleLayer->GetMiddleLayerPlatform(), middleLayerPlatform);
    ASSERT_EQUAL(middleLayer->GetEnvironmentDirectory().GetEngineEnvironment(), environmentDirectory.GetEngineEnvironment());
    ASSERT_EQUAL(middleLayer->GetEnvironmentDirectory().GetEngineDirectory(), environmentDirectory.GetEngineDirectory());
}

template <typename TestingType>
void Framework::MiddleLayerInterfaceTestingBase::MiddleLayerTest()
{
    auto middleLayer = TestingType::CreateMiddleLayer(middleLayerPlatform, environmentDirectory);

    ASSERT_TRUE(middleLayer->PreCreate());
    ASSERT_TRUE(middleLayer->Create(EnvironmentParameter::Create()));
    ASSERT_TRUE(middleLayer->Initialize());

    middleLayer->PreIdle();
    ASSERT_TRUE(middleLayer->Idle(0));

    ASSERT_TRUE(middleLayer->Paint());
    ASSERT_TRUE(middleLayer->Move(point));
    ASSERT_TRUE(middleLayer->Resize(System::WindowsDisplay::MaxHide, size));

    ASSERT_TRUE(middleLayer->KeyUp(0, point));
    ASSERT_TRUE(middleLayer->KeyDown(0, point));
    ASSERT_TRUE(middleLayer->SpecialKeyUp(0, point));
    ASSERT_TRUE(middleLayer->SpecialKeyDown(0, point));

    ASSERT_TRUE(middleLayer->PassiveMotion(point));
    ASSERT_TRUE(middleLayer->Motion(point, virtualKeysTypes));
    ASSERT_TRUE(middleLayer->MouseWheel(0, point, virtualKeysTypes));
    ASSERT_TRUE(middleLayer->MouseClick(MouseButtonsTypes::LeftButton, MouseStateTypes::MouseDown, point, virtualKeysTypes));

    ASSERT_TRUE(middleLayer->Destroy());
    middleLayer->Terminate();
}

template <typename TestingType>
void Framework::MiddleLayerInterfaceTestingBase::KeyUpExceptionTest()
{
    auto middleLayer = TestingType::CreateMiddleLayer(middleLayerPlatform, environmentDirectory);

    middleLayer->KeyUp(0, point);
}

template <typename TestingType>
void Framework::MiddleLayerInterfaceTestingBase::KeyDownExceptionTest()
{
    auto middleLayer = TestingType::CreateMiddleLayer(middleLayerPlatform, environmentDirectory);

    middleLayer->KeyDown(0, point);
}

template <typename TestingType>
void Framework::MiddleLayerInterfaceTestingBase::SpecialKeyUpExceptionTest()
{
    auto middleLayer = TestingType::CreateMiddleLayer(middleLayerPlatform, environmentDirectory);

    middleLayer->SpecialKeyUp(0, point);
}

template <typename TestingType>
void Framework::MiddleLayerInterfaceTestingBase::SpecialKeyDownExceptionTest()
{
    auto middleLayer = TestingType::CreateMiddleLayer(middleLayerPlatform, environmentDirectory);

    middleLayer->SpecialKeyDown(0, point);
}

template <typename TestingType>
void Framework::MiddleLayerInterfaceTestingBase::PassiveMotionExceptionTest()
{
    auto middleLayer = TestingType::CreateMiddleLayer(middleLayerPlatform, environmentDirectory);

    middleLayer->PassiveMotion(point);
}

template <typename TestingType>
void Framework::MiddleLayerInterfaceTestingBase::MotionExceptionTest()
{
    auto middleLayer = TestingType::CreateMiddleLayer(middleLayerPlatform, environmentDirectory);

    middleLayer->Motion(point, virtualKeysTypes);
}

template <typename TestingType>
void Framework::MiddleLayerInterfaceTestingBase::MouseWheelExceptionTest()
{
    auto middleLayer = TestingType::CreateMiddleLayer(middleLayerPlatform, environmentDirectory);

    middleLayer->MouseWheel(0, point, virtualKeysTypes);
}

template <typename TestingType>
void Framework::MiddleLayerInterfaceTestingBase::MouseClickExceptionTest()
{
    auto middleLayer = TestingType::CreateMiddleLayer(middleLayerPlatform, environmentDirectory);

    middleLayer->MouseClick(MouseButtonsTypes::LeftButton, MouseStateTypes::MouseDown, point, virtualKeysTypes);
}

template <typename TestingType>
void Framework::MiddleLayerInterfaceTestingBase::SetManagerExceptionTest(SetManagerFunction setManagerFunction)
{
    if (setManagerFunction != nullptr)
    {
        auto middleLayer = TestingType::CreateMiddleLayer(middleLayerPlatform, environmentDirectory);

        auto manager = TestingType::CreateMiddleLayer(middleLayerPlatform, environmentDirectory);

        ((*middleLayer).*setManagerFunction)(manager);
    }
}

template <typename TestingType, typename GetManagerFunction>
void Framework::MiddleLayerInterfaceTestingBase::GetManagerExceptionTest(GetManagerFunction getManagerFunction)
{
    if (getManagerFunction != nullptr)
    {
        auto middleLayer = TestingType::CreateMiddleLayer(middleLayerPlatform, environmentDirectory);

        auto manager = ((*middleLayer).*getManagerFunction)();
    }
}

template <typename TestingType, typename GetConstManagerFunction>
void Framework::MiddleLayerInterfaceTestingBase::GetConstManagerExceptionTest(GetConstManagerFunction getManagerFunction)
{
    if (getManagerFunction != nullptr)
    {
        std::shared_ptr<const TestingType> middleLayer{ TestingType::CreateMiddleLayer(middleLayerPlatform, environmentDirectory) };

        auto manager = ((*middleLayer).*getManagerFunction)();
    }
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SUITE_MIDDLE_LAYER_INTERFACE_TESTING_BASE_DETAIL_H