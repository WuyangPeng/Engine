///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 10:46)

#include "ModelViewControllerMiddleLayerContainerTesting.h"
#include "System/Windows/Flags/WindowsDisplayFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/RendererEngine/EnvironmentParameter.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MiddleLayer/CameraControllerMiddleLayerDetail.h"
#include "Framework/MiddleLayer/CameraModelMiddleLayer.h"
#include "Framework/MiddleLayer/CameraViewMiddleLayer.h"
#include "Framework/MiddleLayer/ControllerMiddleLayerDetail.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"
#include "Framework/MiddleLayer/ModelMiddleLayer.h"
#include "Framework/MiddleLayer/ModelViewControllerMiddleLayerContainerDetail.h"
#include "Framework/MiddleLayer/PixelViewMiddleLayer.h"
#include "Framework/MiddleLayer/ViewMiddleLayer.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/Flags/MouseTypes.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"

namespace Framework
{
    using TestingType = ModelViewControllerMiddleLayerContainer<WindowApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>;
    using PixelTestingType = ModelViewControllerMiddleLayerContainer<WindowApplicationTrait, ModelMiddleLayer, PixelViewMiddleLayer, ControllerMiddleLayer>;
    using CameraTestingType = ModelViewControllerMiddleLayerContainer<WindowApplicationTrait, CameraModelMiddleLayer, CameraViewMiddleLayer, CameraControllerMiddleLayer>;
}

Framework::ModelViewControllerMiddleLayerContainerTesting::ModelViewControllerMiddleLayerContainerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ModelViewControllerMiddleLayerContainerTesting)

void Framework::ModelViewControllerMiddleLayerContainerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::ModelViewControllerMiddleLayerContainerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PixelMiddleLayerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CameraMiddleLayerTest);
}

void Framework::ModelViewControllerMiddleLayerContainerTesting::MiddleLayerTest()
{
    constexpr auto platform = MiddleLayerPlatform::Windows;

    TestingType middleLayer{ platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    ASSERT_EQUAL(middleLayer.GetMiddleLayerPlatform(), platform);

    EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };
    ASSERT_TRUE(middleLayer.PreCreate());
    ASSERT_TRUE(middleLayer.Create(Rendering::EnvironmentParameter::Create()));
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

void Framework::ModelViewControllerMiddleLayerContainerTesting::PixelMiddleLayerTest()
{
    constexpr auto platform = MiddleLayerPlatform::Windows;

    PixelTestingType middleLayer{ platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    ASSERT_EQUAL(middleLayer.GetMiddleLayerPlatform(), platform);

    EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };
    ASSERT_TRUE(middleLayer.PreCreate());
    ASSERT_TRUE(middleLayer.Create(Rendering::EnvironmentParameter::Create()));
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

void Framework::ModelViewControllerMiddleLayerContainerTesting::CameraMiddleLayerTest()
{
    constexpr auto platform = MiddleLayerPlatform::Windows;

    CameraTestingType middleLayer{ platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    ASSERT_EQUAL(middleLayer.GetMiddleLayerPlatform(), platform);

    EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };
    ASSERT_TRUE(middleLayer.PreCreate());
    ASSERT_TRUE(middleLayer.Create(Rendering::EnvironmentParameter::Create()));
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
