// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.1.0 (2020/06/28 21:41)

#include "CameraViewMiddleLayerTesting.h"
#include "System/Windows/Flags/WindowsDisplayFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MiddleLayer/CameraModelMiddleLayer.h"
#include "Framework/MiddleLayer/CameraViewMiddleLayer.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/Flags/MouseTypes.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"

#include <random>

using std::default_random_engine;
using std::make_shared;
using std::string;
using std::uniform_int;

namespace Framework
{
    using TestingType = CameraViewMiddleLayer;
}
#include SYSTEM_WARNING_DISABLE(26440)
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
    Rendering::RendererManager::Create();
    Rendering::CameraManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DrawFrameRateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TrackTest);

    Rendering::CameraManager::Destroy();
    Rendering::RendererManager::Destroy();
}

void Framework::CameraViewMiddleLayerTesting::MiddleLayerTest()
{
    constexpr auto platform = MiddleLayerPlatform::Windows;

    TestingType middleLayer{ platform };

    auto cameraModelMiddleLayer = make_shared<CameraModelMiddleLayer>(platform);

    middleLayer.SetModelMiddleLayer(cameraModelMiddleLayer);

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

void Framework::CameraViewMiddleLayerTesting::DrawFrameRateTest()
{
    constexpr auto platform = MiddleLayerPlatform::Windows;

    TestingType middleLayer{ platform };

    auto cameraModelMiddleLayer = make_shared<CameraModelMiddleLayer>(platform);

    middleLayer.SetModelMiddleLayer(cameraModelMiddleLayer);

    EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };

    ASSERT_TRUE(middleLayer.PreCreate(environmentDirectory));

    const auto clearColor = middleLayer.GetClearColor();
    const decltype(clearColor) blackColour{ 0.0f, 0.0f, 0.0f, 1.0f };
    //      ASSERT_APPROXIMATE_USE_FUNCTION(Rendering::Approximate<float>, clearColor, blackColour, Mathematics::MathF::epsilon);

    middleLayer.DrawFrameRate(WindowPoint{}, clearColor);
    ASSERT_TRUE(middleLayer.Paint());
}

void Framework::CameraViewMiddleLayerTesting::TrackTest()
{
    // 	constexpr auto platform = MiddleLayerPlatform::Windows;
    //
    // 	TestingType middleLayer{ platform };
    //
    // 	auto cameraModelMiddleLayer = make_shared<CameraModelMiddleLayer>(platform);
    //
    // 	middleLayer.SetModelMiddleLayer(cameraModelMiddleLayer);
    //
    // 	EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment") ,SYSTEM_TEXT("") };
    //
    // 	ASSERT_TRUE(middleLayer.PreCreate(environmentDirectory));
    // 	ASSERT_TRUE(middleLayer.Initialize());
    // 	middleLayer.PreIdle();
    // 	ASSERT_TRUE(middleLayer.Create());
    //
    // 	const WindowSize defaultWindowSize{ 1024, 768 };
    // 	ASSERT_TRUE(middleLayer.Resize(System::WindowsDisplay::MaxHide, defaultWindowSize));
    //
    // 	const auto currentWindowSize = middleLayer.GetWindowSize();
    //
    // 	ASSERT_EQUAL(currentWindowSize, defaultWindowSize);
    //
    // 	Rendering::CameraSmartPointer camera{ CoreTools::New0<Rendering::Camera>() };
    // 	middleLayer.SetCamera(camera);
    //
    // 	default_random_engine generator{ GetEngineRandomSeed() };
    // 	const uniform_int<> widthRandom{ 0, defaultWindowSize.GetWindowWidth() };
    // 	const uniform_int<> heightRandom{ 0, defaultWindowSize.GetWindowHeight() };
    //
    // 	const auto testLoopCount = GetTestLoopCount();
    // 	for (int loop = 0; loop < testLoopCount; ++loop)
    // 	{
    // 		const WindowPoint point{ widthRandom(generator), heightRandom(generator) };
    // 		const auto x = middleLayer.GetXTrack(point.GetWindowX());
    // 		const auto y = middleLayer.GetYTrack(point.GetWindowY());
    //
    // 		const auto multiplier = CalculateMultiplier(defaultWindowSize);
    // 		const auto xResult = GetXTrack(point.GetWindowX(), multiplier, defaultWindowSize);
    // 		const auto yResult = GetYTrack(point.GetWindowY(), multiplier, defaultWindowSize);
    //
    // 		ASSERT_APPROXIMATE(x, xResult, Mathematics::MathF::epsilon);
    // 		ASSERT_APPROXIMATE(y, yResult, Mathematics::MathF::epsilon);
    // 	}
    //
    // 	ASSERT_TRUE(middleLayer.Destroy());
    // 	middleLayer.Terminate();
}
