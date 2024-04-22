///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/12 16:26)

#include "CameraControllerMiddleLayerTesting.h"
#include "System/Windows/Flags/WindowsDisplayFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Rendering/RendererEngine/EnvironmentParameter.h"
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

Framework::CameraControllerMiddleLayerTesting::CameraControllerMiddleLayerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, CameraControllerMiddleLayerTesting)

void Framework::CameraControllerMiddleLayerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::CameraControllerMiddleLayerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(KeyDownTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TrackBallDownTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RotateTrackBallTest);
}

void Framework::CameraControllerMiddleLayerTesting::MiddleLayerTest()
{
    constexpr auto platform = MiddleLayerPlatform::Windows;

    CameraControllerMiddleLayer<WindowApplicationTrait> middleLayer{ platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    const auto cameraModelMiddleLayer = std::make_shared<CameraModelMiddleLayer>(platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });
    middleLayer.SetModelMiddleLayer(cameraModelMiddleLayer);
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

void Framework::CameraControllerMiddleLayerTesting::KeyDownTest()
{
    constexpr auto platform = MiddleLayerPlatform::Windows;

    const auto middleLayer = std::make_shared<CameraControllerMiddleLayer<WindowApplicationTrait>>(platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    const auto cameraModelMiddleLayer = std::make_shared<CameraModelMiddleLayer>(platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });
    middleLayer->SetModelMiddleLayer(cameraModelMiddleLayer);
    const auto cameraViewMiddleLayer = std::make_shared<CameraViewMiddleLayer>(platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });
    middleLayer->SetViewMiddleLayer(cameraViewMiddleLayer);
    cameraModelMiddleLayer->SetViewMiddleLayer(cameraViewMiddleLayer);
    cameraModelMiddleLayer->SetControllerMiddleLayer(middleLayer);
    cameraViewMiddleLayer->SetModelMiddleLayer(cameraModelMiddleLayer);
    cameraViewMiddleLayer->SetControllerMiddleLayer(middleLayer);

    EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };
    ASSERT_TRUE(middleLayer->PreCreate());

    ASSERT_TRUE(cameraModelMiddleLayer->PreCreate());
    ASSERT_TRUE(cameraViewMiddleLayer->PreCreate());

    ASSERT_TRUE(middleLayer->Create(Rendering::EnvironmentParameter::Create()));
    ASSERT_TRUE(cameraModelMiddleLayer->Create(Rendering::EnvironmentParameter::Create()));
    ASSERT_TRUE(cameraViewMiddleLayer->Create(Rendering::EnvironmentParameter::Create()));

    ASSERT_TRUE(cameraModelMiddleLayer->Initialize());
    ASSERT_TRUE(cameraViewMiddleLayer->Initialize());
    ASSERT_TRUE(middleLayer->Initialize());

    const WindowSize defaultWindowSize{ 1024, 768 };
    ASSERT_TRUE(middleLayer->Resize(System::WindowsDisplay::MaxHide, defaultWindowSize));
    ASSERT_TRUE(cameraModelMiddleLayer->Resize(System::WindowsDisplay::MaxHide, defaultWindowSize));

    const auto originalRotationSpeed = cameraModelMiddleLayer->GetRotationSpeed();
    const auto originalTranslationSpeed = cameraModelMiddleLayer->GetTranslationSpeed();
    constexpr auto speedFactor = 2.0f;
    constexpr WindowPoint point{};

    ASSERT_TRUE(middleLayer->KeyDown(WindowApplicationTrait::KeyIdentifiers::lowerT, point));
    ASSERT_APPROXIMATE(originalTranslationSpeed / speedFactor, cameraModelMiddleLayer->GetTranslationSpeed(), Mathematics::MathF::epsilon);
    ASSERT_APPROXIMATE(originalRotationSpeed, cameraModelMiddleLayer->GetRotationSpeed(), Mathematics::MathF::epsilon);

    ASSERT_TRUE(middleLayer->KeyDown(WindowApplicationTrait::KeyIdentifiers::upperR, point));
    ASSERT_APPROXIMATE(originalTranslationSpeed / speedFactor, cameraModelMiddleLayer->GetTranslationSpeed(), Mathematics::MathF::epsilon);
    ASSERT_APPROXIMATE(originalRotationSpeed * speedFactor, cameraModelMiddleLayer->GetRotationSpeed(), Mathematics::MathF::epsilon);

    ASSERT_TRUE(middleLayer->KeyDown(WindowApplicationTrait::KeyIdentifiers::lowerR, point));
    ASSERT_APPROXIMATE(originalTranslationSpeed / speedFactor, cameraModelMiddleLayer->GetTranslationSpeed(), Mathematics::MathF::epsilon);
    ASSERT_APPROXIMATE(originalRotationSpeed, cameraModelMiddleLayer->GetRotationSpeed(), Mathematics::MathF::epsilon);

    ASSERT_TRUE(middleLayer->KeyDown(WindowApplicationTrait::KeyIdentifiers::upperT, point));
    ASSERT_APPROXIMATE(originalTranslationSpeed, cameraModelMiddleLayer->GetTranslationSpeed(), Mathematics::MathF::epsilon);
    ASSERT_APPROXIMATE(originalRotationSpeed, cameraModelMiddleLayer->GetRotationSpeed(), Mathematics::MathF::epsilon);

    ASSERT_TRUE(cameraModelMiddleLayer->Destroy());
    cameraModelMiddleLayer->Terminate();

    ASSERT_TRUE(middleLayer->Destroy());
    middleLayer->Terminate();
}

void Framework::CameraControllerMiddleLayerTesting::TrackBallDownTest()
{
    constexpr auto platform = MiddleLayerPlatform::Windows;

    const auto middleLayer = std::make_shared<CameraControllerMiddleLayer<WindowApplicationTrait>>(platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    const auto cameraModelMiddleLayer = std::make_shared<CameraModelMiddleLayer>(platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });
    middleLayer->SetModelMiddleLayer(cameraModelMiddleLayer);
    const auto cameraViewMiddleLayer = std::make_shared<CameraViewMiddleLayer>(platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });
    middleLayer->SetViewMiddleLayer(cameraViewMiddleLayer);
    cameraModelMiddleLayer->SetViewMiddleLayer(cameraViewMiddleLayer);
    cameraModelMiddleLayer->SetControllerMiddleLayer(middleLayer);
    cameraViewMiddleLayer->SetModelMiddleLayer(cameraModelMiddleLayer);
    cameraViewMiddleLayer->SetControllerMiddleLayer(middleLayer);

    EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };
    ASSERT_TRUE(middleLayer->PreCreate());

    ASSERT_TRUE(cameraModelMiddleLayer->PreCreate());
    ASSERT_TRUE(cameraViewMiddleLayer->PreCreate());

    ASSERT_TRUE(middleLayer->Create(Rendering::EnvironmentParameter::Create()));
    ASSERT_TRUE(cameraModelMiddleLayer->Create(Rendering::EnvironmentParameter::Create()));
    ASSERT_TRUE(cameraViewMiddleLayer->Create(Rendering::EnvironmentParameter::Create()));

    ASSERT_TRUE(cameraModelMiddleLayer->Initialize());
    ASSERT_TRUE(cameraViewMiddleLayer->Initialize());
    ASSERT_TRUE(middleLayer->Initialize());

    ASSERT_FALSE(cameraModelMiddleLayer->GetTrackBallDow());

    constexpr WindowPoint point{};
    constexpr VirtualKeysTypes virtualKeysTypes{};

    ASSERT_TRUE(middleLayer->MouseClick(MouseButtonsTypes::LeftButton, MouseStateTypes::MouseDown, point, virtualKeysTypes));
    ASSERT_TRUE(cameraModelMiddleLayer->GetTrackBallDow());

    ASSERT_TRUE(middleLayer->MouseClick(MouseButtonsTypes::LeftButton, MouseStateTypes::MouseUp, point, virtualKeysTypes));
    ASSERT_FALSE(cameraModelMiddleLayer->GetTrackBallDow());

    ASSERT_TRUE(cameraModelMiddleLayer->Destroy());
    cameraModelMiddleLayer->Terminate();

    ASSERT_TRUE(middleLayer->Destroy());
    middleLayer->Terminate();
}

void Framework::CameraControllerMiddleLayerTesting::RotateTrackBallTest()
{
    constexpr auto platform = MiddleLayerPlatform::Windows;

    const auto middleLayer = std::make_shared<CameraControllerMiddleLayer<WindowApplicationTrait>>(platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });

    const auto cameraModelMiddleLayer = std::make_shared<CameraModelMiddleLayer>(platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });
    middleLayer->SetModelMiddleLayer(cameraModelMiddleLayer);
    const auto cameraViewMiddleLayer = std::make_shared<CameraViewMiddleLayer>(platform, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") });
    middleLayer->SetViewMiddleLayer(cameraViewMiddleLayer);
    cameraModelMiddleLayer->SetViewMiddleLayer(cameraViewMiddleLayer);
    cameraModelMiddleLayer->SetControllerMiddleLayer(middleLayer);
    cameraViewMiddleLayer->SetModelMiddleLayer(cameraModelMiddleLayer);
    cameraViewMiddleLayer->SetControllerMiddleLayer(middleLayer);

    const WindowSize windowSize{ 1024, 768 };
    const auto multiplier = 1.0f / static_cast<float>(windowSize.GetWindowHeight());

    EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };
    ASSERT_TRUE(middleLayer->PreCreate());

    ASSERT_TRUE(cameraModelMiddleLayer->PreCreate());
    ASSERT_TRUE(cameraViewMiddleLayer->PreCreate());

    ASSERT_TRUE(middleLayer->Create(Rendering::EnvironmentParameter::Create()));
    ASSERT_TRUE(cameraModelMiddleLayer->Create(Rendering::EnvironmentParameter::Create()));
    ASSERT_TRUE(cameraViewMiddleLayer->Create(Rendering::EnvironmentParameter::Create()));

    ASSERT_TRUE(cameraViewMiddleLayer->Initialize());
    ASSERT_TRUE(cameraViewMiddleLayer->Resize(System::WindowsDisplay::MaxHide, windowSize));
    ASSERT_TRUE(cameraModelMiddleLayer->Initialize());
    ASSERT_TRUE(cameraModelMiddleLayer->Resize(System::WindowsDisplay::MaxHide, windowSize));

    ASSERT_TRUE(middleLayer->Initialize());
    ASSERT_TRUE(middleLayer->Resize(System::WindowsDisplay::MaxHide, windowSize));

    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int<> random{ 0, 100 };

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        const auto xBegin = random(generator);
        const auto yBegin = random(generator);
        const auto xEnd = random(generator);
        const auto yEnd = random(generator);

        const auto xTrackBegin = GetXTrack(xBegin, multiplier, windowSize);
        const auto yTrackBegin = GetYTrack(yBegin, multiplier, windowSize);
        const auto xTrackEnd = GetXTrack(xEnd, multiplier, windowSize);
        const auto yTrackEnd = GetYTrack(yEnd, multiplier, windowSize);

        const WindowPoint point{ xBegin, yBegin };
        constexpr VirtualKeysTypes virtualKeysTypes{};

        ASSERT_TRUE(middleLayer->MouseClick(MouseButtonsTypes::LeftButton, MouseStateTypes::MouseDown, point, virtualKeysTypes));

        const auto rotate = cameraModelMiddleLayer->GetMotionObjectLocalTransform().GetRotate();

        const auto vecBegin = Calculate3DVector(boost::numeric_cast<float>(xTrackBegin), boost::numeric_cast<float>(yTrackBegin));
        const auto vecEnd = Calculate3DVector(boost::numeric_cast<float>(xTrackEnd), boost::numeric_cast<float>(yTrackEnd));

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
                const auto invLength = Mathematics::MathF::InvSqrt(boost::numeric_cast<float>(xBegin * xBegin + yBegin * yBegin));
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

        auto worldAxis = axis[0] * cameraModelMiddleLayer->GetCameraDirectionVector() + axis[1] * cameraModelMiddleLayer->GetCameraUpVector() + axis[2] * cameraModelMiddleLayer->GetCameraRightVector();

        const Matrix trackRotate{ worldAxis, angle };

        auto localRotate = trackRotate * rotate;

        localRotate.Orthonormalize();

        ASSERT_TRUE(middleLayer->Motion(WindowPoint{ xEnd, yEnd }, VirtualKeysTypes{ boost::numeric_cast<System::WindowsWParam>(WindowApplicationTrait::MouseModifiers::modifierLeftButton) }));

        MatrixTest(localRotate, cameraModelMiddleLayer->GetMotionObjectLocalTransform().GetRotate(), __func__, i);
    }

    ASSERT_TRUE(cameraModelMiddleLayer->Destroy());
    cameraModelMiddleLayer->Terminate();

    ASSERT_TRUE(middleLayer->Destroy());
    middleLayer->Terminate();
}