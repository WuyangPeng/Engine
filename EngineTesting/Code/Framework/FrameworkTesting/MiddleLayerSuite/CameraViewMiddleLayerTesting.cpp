///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/12 17:30)

#include "CameraViewMiddleLayerTesting.h"
#include "System/Windows/Flags/WindowsDisplayFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/RendererEngine/EnvironmentParameter.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MiddleLayer/CameraModelMiddleLayer.h"
#include "Framework/MiddleLayer/CameraViewMiddleLayer.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/Flags/MouseTypes.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"

#include <random>

Framework::CameraViewMiddleLayerTesting::CameraViewMiddleLayerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, CameraViewMiddleLayerTesting)

void Framework::CameraViewMiddleLayerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::CameraViewMiddleLayerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DrawFrameRateTest);
}

void Framework::CameraViewMiddleLayerTesting::MiddleLayerTest()
{
    constexpr auto platform = MiddleLayerPlatform::Windows;

    CameraViewMiddleLayer middleLayer{ platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    const auto cameraModelMiddleLayer = std::make_shared<CameraModelMiddleLayer>(platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    middleLayer.SetModelMiddleLayer(cameraModelMiddleLayer);

    ASSERT_EQUAL(middleLayer.GetMiddleLayerPlatform(), platform);

    EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };
    ASSERT_TRUE(middleLayer.PreCreate());
    ASSERT_TRUE(middleLayer.Create(Rendering::EnvironmentParameter::Create()));
    ASSERT_TRUE(cameraModelMiddleLayer->Create(Rendering::EnvironmentParameter::Create()));
    ASSERT_TRUE(middleLayer.Initialize());

    ASSERT_TRUE(middleLayer.Destroy());
    middleLayer.Terminate();

    middleLayer.PreIdle();
    ASSERT_TRUE(middleLayer.Idle(0));

    constexpr WindowPoint point{};
    const WindowSize size{};
    constexpr VirtualKeysTypes virtualKeysTypes{};

    ASSERT_TRUE(middleLayer.Paint());
    ASSERT_TRUE(middleLayer.Move(point));
    ASSERT_TRUE(middleLayer.Resize(System::WindowsDisplay::MaxHide, size));

    ASSERT_TRUE(middleLayer.KeyUp(0, point));
    ASSERT_TRUE(middleLayer.KeyDown(0, point));
    ASSERT_TRUE(middleLayer.SpecialKeyUp(0, point));
    ASSERT_TRUE(middleLayer.SpecialKeyDown(0, point));

    ASSERT_TRUE(middleLayer.PassiveMotion(point));
    ASSERT_TRUE(middleLayer.Motion(point, virtualKeysTypes));
    ASSERT_TRUE(middleLayer.MouseWheel(0, point, virtualKeysTypes));
    ASSERT_TRUE(middleLayer.MouseClick(MouseButtonsTypes::LeftButton, MouseStateTypes::MouseDown, point, virtualKeysTypes));
}

void Framework::CameraViewMiddleLayerTesting::DrawFrameRateTest()
{
    constexpr auto platform = MiddleLayerPlatform::Windows;

    CameraViewMiddleLayer middleLayer{ platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    const auto cameraModelMiddleLayer = std::make_shared<CameraModelMiddleLayer>(platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    middleLayer.SetModelMiddleLayer(cameraModelMiddleLayer);

    EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };

    ASSERT_TRUE(middleLayer.PreCreate());
    ASSERT_TRUE(middleLayer.Create(Rendering::EnvironmentParameter::Create()));
    ASSERT_TRUE(cameraModelMiddleLayer->Create(Rendering::EnvironmentParameter::Create()));

    const auto clearColor = middleLayer.GetClearColour();

    middleLayer.DrawFrameRate(WindowPoint{}, clearColor);
    ASSERT_TRUE(middleLayer.Paint());
}
