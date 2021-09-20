// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/16 09:37)

#include "InputManagerInterfaceTesting.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h" 
#include "CoreTools/Helper/MemoryMacro.h"
#include "Framework/MiddleLayer/InputManagerInterface.h" 
#include "Framework/MiddleLayer/NetworkManagerInterface.h"
#include "Framework/MiddleLayer/ObjectLogicInterface.h"
#include "Framework/MiddleLayer/SystemManagerInterface.h"
#include "Framework/MiddleLayer/CameraSystemsManagerInterface.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"
#include "System/Window/Flags/WindowDisplayFlags.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/WindowProcess/Flags/MouseTypes.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"

#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  

namespace Framework
{
	using TestingType = InputManagerInterface;
}

Framework::InputManagerInterfaceTesting
::InputManagerInterfaceTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, InputManagerInterfaceTesting)

void Framework::InputManagerInterfaceTesting
::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::InputManagerInterfaceTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SetMiddleLayerTest);
}

void Framework::InputManagerInterfaceTesting
	::MiddleLayerTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	ASSERT_TRUE(middleLayer.PreCreate(EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"),SYSTEM_TEXT("") }));
	ASSERT_TRUE(middleLayer.Initialize());
	middleLayer.PreIdle();
	ASSERT_TRUE(middleLayer.Create());	
	ASSERT_TRUE(middleLayer.Paint());
	ASSERT_TRUE(middleLayer.Move(WindowPoint()));
	ASSERT_TRUE(middleLayer.Resize(System::WindowDisplay::MaxHide,WindowSize()));
	ASSERT_TRUE(middleLayer.KeyDown(0,WindowPoint()));
	ASSERT_TRUE(middleLayer.KeyUp(0,WindowPoint()));
	ASSERT_TRUE(middleLayer.SpecialKeyDown (0,WindowPoint()));
	ASSERT_TRUE(middleLayer.SpecialKeyUp (0,WindowPoint()));
	ASSERT_TRUE(middleLayer.MouseClick(MouseButtonsTypes::LeftButton,MouseStateTypes::MouseDown,WindowPoint(),VirtualKeysTypes()));
	ASSERT_TRUE(middleLayer.Motion(WindowPoint(),VirtualKeysTypes()));
	ASSERT_TRUE(middleLayer.PassiveMotion(WindowPoint()));
	ASSERT_TRUE(middleLayer.MouseWheel(0,WindowPoint(),VirtualKeysTypes()));
	ASSERT_TRUE(middleLayer.Idle(0));

	ASSERT_TRUE(middleLayer.Destroy());
	middleLayer.Terminate();	
}

void Framework::InputManagerInterfaceTesting
	::SetMiddleLayerTest()
{	 
	ASSERT_NOT_THROW_EXCEPTION_0(SetNetworkManagerTest);
	ASSERT_THROW_EXCEPTION_0(SetInputManagerExceptionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SetObjectLogicManagerTest);
	ASSERT_THROW_EXCEPTION_0(SetPhysicalModellingManagerExceptionTest);
	ASSERT_THROW_EXCEPTION_0(SetMessageManagerExceptionTest);
	ASSERT_THROW_EXCEPTION_0(SetEventManagerExceptionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SetSystemManagerTest);
	ASSERT_THROW_EXCEPTION_0(SetResourceManagerExceptionTest);
	ASSERT_THROW_EXCEPTION_0(SetAudioManagerExceptionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SetCameraSystemsManagerTest);
	ASSERT_THROW_EXCEPTION_0(SetRenderingManagerExceptionTest);
	ASSERT_THROW_EXCEPTION_0(SetGUIManagerExceptionTest);
}

void Framework::InputManagerInterfaceTesting
	::SetNetworkManagerTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr networkManager(std::make_shared < NetworkManagerInterface>(MiddleLayerPlatform::Windows));

	middleLayer.SetNetworkManager(networkManager);
}

void Framework::InputManagerInterfaceTesting
	::SetInputManagerExceptionTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr inputManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

	middleLayer.SetInputManager(inputManager);
}

void Framework::InputManagerInterfaceTesting
	::SetObjectLogicManagerTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr objectLogicManager(std::make_shared < ObjectLogicInterface>(MiddleLayerPlatform::Windows));

	middleLayer.SetObjectLogicManager(objectLogicManager);
}

void Framework::InputManagerInterfaceTesting
	::SetPhysicalModellingManagerExceptionTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr physicalModellingManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

	middleLayer.SetPhysicalModellingManager(physicalModellingManager);
}

void Framework::InputManagerInterfaceTesting
	::SetMessageManagerExceptionTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr messageManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

	middleLayer.SetMessageManager(messageManager);
}

void Framework::InputManagerInterfaceTesting
	::SetEventManagerExceptionTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr eventManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

	middleLayer.SetEventManager(eventManager);
}

void Framework::InputManagerInterfaceTesting
	::SetSystemManagerTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr systemManager(std::make_shared < SystemManagerInterface>(MiddleLayerPlatform::Windows));

	middleLayer.SetSystemManager(systemManager);
}

void Framework::InputManagerInterfaceTesting
	::SetResourceManagerExceptionTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr resourceManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

	middleLayer.SetResourceManager(resourceManager);
}

void Framework::InputManagerInterfaceTesting
	::SetAudioManagerExceptionTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr audioManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

	middleLayer.SetAudioManager(audioManager);
}

void Framework::InputManagerInterfaceTesting
	::SetCameraSystemsManagerTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr cameraSystemsManager(std::make_shared < CameraSystemsManagerInterface>(MiddleLayerPlatform::Windows));

	middleLayer.SetCameraSystemsManager(cameraSystemsManager);
}

void Framework::InputManagerInterfaceTesting
	::SetRenderingManagerExceptionTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr renderingManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

	middleLayer.SetRenderingManager(renderingManager);
}

void Framework::InputManagerInterfaceTesting
	::SetGUIManagerExceptionTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr guiManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

	middleLayer.SetGUIManager(guiManager);
}
