///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/24 17:57)

#include "ViewMiddleLayerTesting.h"
#include "System/Windows/Flags/WindowsDisplayFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"
#include "Framework/MiddleLayer/ModelMiddleLayer.h"
#include "Framework/MiddleLayer/ViewMiddleLayer.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/Flags/MouseTypes.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"

using std::make_shared;

namespace Framework
{
    using TestingType = ViewMiddleLayer;
}

Framework::ViewMiddleLayerTesting::ViewMiddleLayerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ViewMiddleLayerTesting)

void Framework::ViewMiddleLayerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::ViewMiddleLayerTesting::MainTest()
{
    Rendering::RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DrawFrameRateTest);

    Rendering::RendererManager::Destroy();
}

void Framework::ViewMiddleLayerTesting::MiddleLayerTest()
{
    constexpr auto platform = MiddleLayerPlatform::Windows;

    TestingType middleLayer{ platform };

    auto modelMiddleLayer = make_shared<ModelMiddleLayer>(platform);

    middleLayer.SetModelMiddleLayer(modelMiddleLayer);

    ASSERT_ENUM_EQUAL(middleLayer.GetMiddleLayerPlatform(), platform);

    EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };
    ASSERT_TRUE(middleLayer.PreCreate(environmentDirectory));
    ASSERT_TRUE(middleLayer.Create());
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

void Framework::ViewMiddleLayerTesting::DrawFrameRateTest()
{
    constexpr auto platform = MiddleLayerPlatform::Windows;

    TestingType middleLayer{ platform };

    auto modelMiddleLayer = make_shared<ModelMiddleLayer>(platform);

    middleLayer.SetModelMiddleLayer(modelMiddleLayer);

    EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };
    ASSERT_TRUE(middleLayer.PreCreate(environmentDirectory));

    auto clearColor = middleLayer.GetClearColor();
    const decltype(clearColor) blackColour{ 0.0f, 0.0f, 0.0f, 1.0f };
    ASSERT_APPROXIMATE_USE_FUNCTION(Rendering::Approximate<float>, clearColor, blackColour, Mathematics::MathF::epsilon);

    const decltype(clearColor) redColour{ 1.0f, 0.0f, 0.0f, 1.0f };
    middleLayer.SetClearColor(redColour);

    clearColor = middleLayer.GetClearColor();
    ASSERT_APPROXIMATE_USE_FUNCTION(Rendering::Approximate<float>, clearColor, redColour, Mathematics::MathF::epsilon);

    middleLayer.DrawFrameRate(WindowPoint{}, blackColour);
    ASSERT_TRUE(middleLayer.Paint());
}
