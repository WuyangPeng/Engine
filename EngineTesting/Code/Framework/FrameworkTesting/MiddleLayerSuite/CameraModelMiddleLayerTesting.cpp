///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/12 16:37)

#include "CameraModelMiddleLayerTesting.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/Threading/SyncTools.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "System/Windows/Flags/WindowsDisplayFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Time/CustomTime.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/RendererEngine/EnvironmentParameter.h"
#include "Rendering/SceneGraph/Node.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MiddleLayer/CameraControllerMiddleLayerDetail.h"
#include "Framework/MiddleLayer/CameraModelMiddleLayer.h"
#include "Framework/MiddleLayer/CameraViewMiddleLayer.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/Flags/MouseTypes.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"

#include <random>

using System::operator*;

Framework::CameraModelMiddleLayerTesting::CameraModelMiddleLayerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, CameraModelMiddleLayerTesting)

void Framework::CameraModelMiddleLayerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::CameraModelMiddleLayerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FrameRateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CameraMotionSpeedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MoveObjectTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TrackBallDownTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RotateTrackBallTest);
}

void Framework::CameraModelMiddleLayerTesting::MiddleLayerTest()
{
    constexpr auto platform = MiddleLayerPlatform::Windows;

    CameraModelMiddleLayer middleLayer{ platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    const auto cameraViewMiddleLayer = std::make_shared<CameraViewMiddleLayer>(platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    middleLayer.SetViewMiddleLayer(cameraViewMiddleLayer);

    ASSERT_EQUAL(middleLayer.GetMiddleLayerPlatform(), platform);

    EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };
    ASSERT_TRUE(middleLayer.PreCreate());
    ASSERT_TRUE(cameraViewMiddleLayer->PreCreate());
    ASSERT_TRUE(middleLayer.Create(Rendering::EnvironmentParameter::Create()));
    ASSERT_TRUE(cameraViewMiddleLayer->Create(Rendering::EnvironmentParameter::Create()));
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

void Framework::CameraModelMiddleLayerTesting::FrameRateTest()
{
    constexpr auto maxTimer = 30;
    constexpr auto platform = MiddleLayerPlatform::Windows;

    CameraModelMiddleLayer middleLayer{ platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    auto cameraViewMiddleLayer = std::make_shared<CameraViewMiddleLayer>(platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    middleLayer.SetViewMiddleLayer(cameraViewMiddleLayer);

    EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };
    ASSERT_TRUE(middleLayer.PreCreate());
    ASSERT_TRUE(cameraViewMiddleLayer->PreCreate());
    ASSERT_TRUE(middleLayer.Create(Rendering::EnvironmentParameter::Create()));
    ASSERT_TRUE(cameraViewMiddleLayer->Create(Rendering::EnvironmentParameter::Create()));
    ASSERT_TRUE(middleLayer.Initialize());

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

    middleLayer.Terminate();
}

void Framework::CameraModelMiddleLayerTesting::CameraMotionSpeedTest()
{
    constexpr auto platform = MiddleLayerPlatform::Windows;

    CameraModelMiddleLayer middleLayer{ platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    const auto cameraViewMiddleLayer = std::make_shared<CameraViewMiddleLayer>(platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    middleLayer.SetViewMiddleLayer(cameraViewMiddleLayer);

    EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };
    ASSERT_TRUE(middleLayer.PreCreate());
    ASSERT_TRUE(cameraViewMiddleLayer->PreCreate());
    ASSERT_TRUE(middleLayer.Create(Rendering::EnvironmentParameter::Create()));
    ASSERT_TRUE(cameraViewMiddleLayer->Create(Rendering::EnvironmentParameter::Create()));
    ASSERT_TRUE(middleLayer.Initialize());

    constexpr auto speed = 0.01f;
    constexpr auto speedFactor = 2.0f;

    ASSERT_APPROXIMATE(middleLayer.GetTranslationSpeed(), speed, Mathematics::MathF::epsilon);
    ASSERT_APPROXIMATE(middleLayer.GetRotationSpeed(), speed, Mathematics::MathF::epsilon);

    middleLayer.SlowerCameraTranslation();
    ASSERT_APPROXIMATE(middleLayer.GetTranslationSpeed(), speed / speedFactor, Mathematics::MathF::epsilon);
    ASSERT_APPROXIMATE(middleLayer.GetRotationSpeed(), speed, Mathematics::MathF::epsilon);

    middleLayer.FasterCameraTranslation();
    ASSERT_APPROXIMATE(middleLayer.GetTranslationSpeed(), speed, Mathematics::MathF::epsilon);
    ASSERT_APPROXIMATE(middleLayer.GetRotationSpeed(), speed, Mathematics::MathF::epsilon);

    middleLayer.SlowerCameraRotation();
    middleLayer.SlowerCameraRotation();
    ASSERT_APPROXIMATE(middleLayer.GetTranslationSpeed(), speed, Mathematics::MathF::epsilon);
    ASSERT_APPROXIMATE(middleLayer.GetRotationSpeed(), speed / (speedFactor * speedFactor), Mathematics::MathF::epsilon);

    middleLayer.FasterCameraRotation();
    ASSERT_APPROXIMATE(middleLayer.GetTranslationSpeed(), speed, Mathematics::MathF::epsilon);
    ASSERT_APPROXIMATE(middleLayer.GetRotationSpeed(), speed / speedFactor, Mathematics::MathF::epsilon);

    middleLayer.Terminate();
}

void Framework::CameraModelMiddleLayerTesting::MoveObjectTest()
{
    constexpr auto platform = MiddleLayerPlatform::Windows;

    CameraModelMiddleLayer middleLayer{ platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    const auto cameraViewMiddleLayer = std::make_shared<CameraViewMiddleLayer>(platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    middleLayer.SetViewMiddleLayer(cameraViewMiddleLayer);

    EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };
    ASSERT_TRUE(middleLayer.PreCreate());
    ASSERT_TRUE(cameraViewMiddleLayer->PreCreate());
    ASSERT_TRUE(middleLayer.Create(Rendering::EnvironmentParameter::Create()));
    ASSERT_TRUE(cameraViewMiddleLayer->Create(Rendering::EnvironmentParameter::Create()));
    ASSERT_TRUE(middleLayer.Initialize());

    middleLayer.SetTrackBallDow(false);
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int<> random{ 0, 1 };
    std::uniform_int<> selectRandom{ 0, 2 };

    ASSERT_FALSE(middleLayer.MoveObject());

    middleLayer.Terminate();

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        constexpr auto rotationSpeed = 0.01f;

        ASSERT_TRUE(middleLayer.Initialize());

        const auto select = selectRandom(generator);

        const auto value = random(generator);
        const auto numericalValueSymbol = (value == 0 ? NumericalValueSymbol::Negative : NumericalValueSymbol::Positive);

        AVector axis{};
        switch (select)
        {
            case 0:
            {
                middleLayer.SetDoRoll(numericalValueSymbol);
                middleLayer.SetDoYaw(NumericalValueSymbol::Zero);
                middleLayer.SetDoPitch(NumericalValueSymbol::Zero);
                axis = AVector::GetUnitX();
            }
            break;
            case 1:
            {
                middleLayer.SetDoRoll(NumericalValueSymbol::Zero);
                middleLayer.SetDoYaw(numericalValueSymbol);
                middleLayer.SetDoPitch(NumericalValueSymbol::Zero);
                axis = AVector::GetUnitY();
            }
            break;
            case 2:
            {
                middleLayer.SetDoRoll(NumericalValueSymbol::Zero);
                middleLayer.SetDoYaw(NumericalValueSymbol::Zero);
                middleLayer.SetDoPitch(numericalValueSymbol);
                axis = AVector::GetUnitZ();
            }
            break;
            default:
                break;
        }

        auto rotate = middleLayer.GetMotionObjectLocalTransform().GetRotate();
        const auto angle = numericalValueSymbol * rotationSpeed;

        const Mathematics::MatrixF incr{ axis, boost::numeric_cast<float>(angle) };
        rotate = incr * rotate;
        rotate.Orthonormalize();

        middleLayer.Terminate();
    }
}

void Framework::CameraModelMiddleLayerTesting::TrackBallDownTest()
{
    constexpr auto platform = MiddleLayerPlatform::Windows;

    CameraModelMiddleLayer middleLayer{ platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    const auto cameraViewMiddleLayer = std::make_shared<CameraViewMiddleLayer>(platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    middleLayer.SetViewMiddleLayer(cameraViewMiddleLayer);

    EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };
    ASSERT_TRUE(middleLayer.PreCreate());
    ASSERT_TRUE(cameraViewMiddleLayer->PreCreate());
    ASSERT_TRUE(middleLayer.Create(Rendering::EnvironmentParameter::Create()));
    ASSERT_TRUE(cameraViewMiddleLayer->Create(Rendering::EnvironmentParameter::Create()));
    ASSERT_TRUE(middleLayer.Initialize());

    ASSERT_FALSE(middleLayer.GetTrackBallDow());

    middleLayer.SetTrackBallDow(true);
    ASSERT_TRUE(middleLayer.GetTrackBallDow());

    middleLayer.SetTrackBallDow(false);
    ASSERT_FALSE(middleLayer.GetTrackBallDow());

    middleLayer.Terminate();
}

void Framework::CameraModelMiddleLayerTesting::RotateTrackBallTest()
{
    constexpr auto platform = MiddleLayerPlatform::Windows;

    CameraModelMiddleLayer middleLayer{ platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    const auto cameraViewMiddleLayer = std::make_shared<CameraViewMiddleLayer>(platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    middleLayer.SetViewMiddleLayer(cameraViewMiddleLayer);

    EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };
    ASSERT_TRUE(middleLayer.PreCreate());
    ASSERT_TRUE(cameraViewMiddleLayer->PreCreate());
    ASSERT_TRUE(middleLayer.Create(Rendering::EnvironmentParameter::Create()));
    ASSERT_TRUE(cameraViewMiddleLayer->Create(Rendering::EnvironmentParameter::Create()));
    ASSERT_TRUE(middleLayer.Initialize());

    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<float> random{ 0.0f, 100.0f };

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        const auto xTrackBegin = random(generator);
        const auto yTrackBegin = random(generator);
        const auto xTrackEnd = random(generator);
        const auto yTrackEnd = random(generator);

        middleLayer.SetBeginTrack(xTrackBegin, yTrackBegin);
        middleLayer.SetEndTrack(xTrackEnd, yTrackEnd);
        middleLayer.SetSaveRotate();

        const auto rotate = middleLayer.GetMotionObjectLocalTransform().GetRotate();

        const auto vecBegin = Calculate3DVector(xTrackBegin, yTrackBegin);
        const auto vecEnd = Calculate3DVector(xTrackEnd, yTrackEnd);

        auto axis = Cross(vecBegin, vecEnd);
        const auto dot = Dot(vecBegin, vecEnd);
        auto angle = 0.0f;
        if (!axis.IsZero())
        {
            axis.Normalize();
            angle = Mathematics::MathF::ACos(dot);
        }
        else
        {
            if (dot < 0.0f)
            {
                const auto invLength = Mathematics::MathF::InvSqrt(xTrackBegin * xTrackBegin + yTrackBegin * yTrackBegin);
                axis[0] = yTrackBegin * invLength;
                axis[1] = -xTrackBegin * invLength;
                axis[2] = 0.0f;
                angle = Mathematics::MathF::GetPI();
            }
            else
            {
                axis = AVector::GetUnitX();
                angle = 0.0f;
            }
        }

        auto worldAxis = axis[0] * middleLayer.GetCameraDirectionVector() + axis[1] * middleLayer.GetCameraUpVector() + axis[2] * middleLayer.GetCameraRightVector();

        const Matrix trackRotate{ worldAxis, angle };

        auto localRotate = trackRotate * rotate;

        localRotate.Orthonormalize();

        middleLayer.RotateTrackBall();

        MatrixTest(localRotate, middleLayer.GetMotionObjectLocalTransform().GetRotate(), __func__, i);
    }

    middleLayer.Terminate();
}
