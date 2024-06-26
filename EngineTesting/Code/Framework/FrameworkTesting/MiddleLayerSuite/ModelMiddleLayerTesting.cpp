///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 10:45)

#include "ModelMiddleLayerTesting.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/Threading/SyncTools.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "System/Windows/Flags/WindowsDisplayFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Time/CustomTime.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Rendering/RendererEngine/EnvironmentParameter.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"
#include "Framework/MiddleLayer/ModelMiddleLayer.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/Flags/MouseTypes.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"

Framework::ModelMiddleLayerTesting::ModelMiddleLayerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ModelMiddleLayerTesting)

void Framework::ModelMiddleLayerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::ModelMiddleLayerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FrameRateTest);
}

void Framework::ModelMiddleLayerTesting::MiddleLayerTest()
{
    constexpr auto platform = MiddleLayerPlatform::Windows;

    ModelMiddleLayer middleLayer{ platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

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

void Framework::ModelMiddleLayerTesting::FrameRateTest()
{
    constexpr auto maxTimer = 30;
    constexpr auto platform = MiddleLayerPlatform::Windows;

    ModelMiddleLayer middleLayer{ platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    constexpr auto frame = System::gMillisecond / maxTimer;
    const auto maxTimerTestLoopCount = maxTimer * GetTestLoopCount();

    CoreTools::CustomTime customTime{};
    auto delta = 0;
    auto frameSum = 0;
    for (auto i = 0; i < maxTimerTestLoopCount; ++i)
    {
        middleLayer.UpdateFrameCount();

        delta += boost::numeric_cast<int>(customTime.GetThisElapsedMillisecondTime());
        frameSum += frame;

        if (delta < frameSum)
        {
            System::SystemSleep(frameSum - delta);
        }

        middleLayer.MeasureTime();
    }

    const auto rate = middleLayer.GetFrameRate();

    constexpr auto epsilon = 0.5;

    ASSERT_RANGE(rate, maxTimer - epsilon, maxTimer + epsilon);

    boost::format message{ "fps: %.2lf" };
    message % middleLayer.GetFrameRate();

    ASSERT_EQUAL(middleLayer.GetFrameRateMessage(), message.str());

    middleLayer.ResetTime();

    const auto zero = middleLayer.GetFrameRate();

    ASSERT_APPROXIMATE(0.0, zero, Mathematics::MathD::epsilon);
}
