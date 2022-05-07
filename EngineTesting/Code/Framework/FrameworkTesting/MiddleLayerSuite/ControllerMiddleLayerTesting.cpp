// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.1.0 (2020/06/26 23:15)

#include "ControllerMiddleLayerTesting.h"
#include "System/Windows/Flags/WindowsDisplayFlags.h"
#include "CoreTools/Helper/AssertMacro.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"
#include "Framework/WindowProcess/Flags/MouseTypes.h"
#include "Framework/MiddleLayer/ControllerMiddleLayerDetail.h" 
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"

using std::make_shared;

namespace Framework
{
	using TestingType = ControllerMiddleLayer<WindowApplicationTrait>;
}

Framework::ControllerMiddleLayerTesting
	::ControllerMiddleLayerTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ControllerMiddleLayerTesting)

void Framework::ControllerMiddleLayerTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::ControllerMiddleLayerTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerTest); 
}

void Framework::ControllerMiddleLayerTesting
	::MiddleLayerTest()
{
	constexpr auto platform = MiddleLayerPlatform::Windows;

	TestingType middleLayer{ platform };

	ASSERT_ENUM_EQUAL(middleLayer.GetMiddleLayerPlatform(), platform);

	auto modelMiddleLayer = make_shared<ModelMiddleLayer>(platform);

	middleLayer.SetModelMiddleLayer(modelMiddleLayer);

	EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment") ,SYSTEM_TEXT("") };
	ASSERT_TRUE(middleLayer.PreCreate(environmentDirectory));
	ASSERT_TRUE(middleLayer.Create());
	ASSERT_TRUE(middleLayer.Initialize());

	ASSERT_TRUE(middleLayer.Destroy());
	middleLayer.Terminate();

	middleLayer.PreIdle();
	ASSERT_TRUE(middleLayer.Idle(0));

	constexpr WindowPoint point{ };
	const WindowSize size{ };
	const VirtualKeysTypes virtualKeysTypes{ };

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

 
