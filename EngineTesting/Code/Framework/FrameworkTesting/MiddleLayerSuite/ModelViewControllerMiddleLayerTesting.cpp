///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/24 18:14)

#include "ModelViewControllerMiddleLayerTesting.h"
#include "Detail/ModelViewControllerMiddleLayerTest.h"
#include "System/Windows/Flags/WindowsDisplayFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Rendering/Renderers/EnvironmentParameter.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"
#include "Framework/MiddleLayer/ModelViewControllerMiddleLayer.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/Flags/MouseTypes.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"

using std::make_shared;

namespace Framework
{
    using TestingType = ModelViewControllerMiddleLayer;
}

Framework::ModelViewControllerMiddleLayerTesting::ModelViewControllerMiddleLayerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ModelViewControllerMiddleLayerTesting)

void Framework::ModelViewControllerMiddleLayerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::ModelViewControllerMiddleLayerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetMiddleLayerTest);
}

void Framework::ModelViewControllerMiddleLayerTesting::MiddleLayerTest()
{
    constexpr auto platform = MiddleLayerPlatform::Windows;

    TestingType middleLayer{ platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    ASSERT_ENUM_EQUAL(middleLayer.GetMiddleLayerPlatform(), platform);

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
    const VirtualKeysTypes virtualKeysTypes{};

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

void Framework::ModelViewControllerMiddleLayerTesting::SetMiddleLayerTest()
{
    constexpr auto platform = MiddleLayerPlatform::Windows;

    ModelViewControllerMiddleLayerTest middleLayer{ platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    auto modelMiddleLayer = std::make_shared<TestingType>(platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });
    auto viewMiddleLayer = std::make_shared<TestingType>(platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });
    auto controllerMiddleLayer = std::make_shared<TestingType>(platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    middleLayer.SetModelMiddleLayer(modelMiddleLayer);
    middleLayer.SetViewMiddleLayer(viewMiddleLayer);
    middleLayer.SetControllerMiddleLayer(controllerMiddleLayer);

    ASSERT_EQUAL(middleLayer.GetConstPublicModelMiddleLayer(), modelMiddleLayer);
    ASSERT_EQUAL(middleLayer.GetPublicModelMiddleLayer(), modelMiddleLayer);

    ASSERT_EQUAL(middleLayer.GetConstPublicViewMiddleLayer(), viewMiddleLayer);
    ASSERT_EQUAL(middleLayer.GetPublicViewMiddleLayer(), viewMiddleLayer);

    ASSERT_EQUAL(middleLayer.GetConstPublicControllerMiddleLayer(), controllerMiddleLayer);
    ASSERT_EQUAL(middleLayer.GetPublicControllerMiddleLayer(), controllerMiddleLayer);
}
