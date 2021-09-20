// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/16 09:42)

#include "ResourceManagerInterfaceTesting.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h" 
#include "CoreTools/Helper/MemoryMacro.h"
#include "Framework/MiddleLayer/ResourceManagerInterface.h" 
#include "Framework/MiddleLayer/SystemManagerInterface.h"
#include "Framework/MiddleLayer/AudioManagerInterface.h"
#include "Framework/MiddleLayer/RenderingManagerInterface.h"
#include "Framework/MiddleLayer/GUIManagerInterface.h"
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
	using TestingType = ResourceManagerInterface;
}

Framework::ResourceManagerInterfaceTesting
::ResourceManagerInterfaceTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ResourceManagerInterfaceTesting)

void Framework::ResourceManagerInterfaceTesting
::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}


void Framework::ResourceManagerInterfaceTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SetMiddleLayerTest);
}

void Framework::ResourceManagerInterfaceTesting
	::MiddleLayerTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	ASSERT_TRUE(middleLayer.PreCreate(EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment") , SYSTEM_TEXT("") }));
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

void Framework::ResourceManagerInterfaceTesting
	::SetMiddleLayerTest()
{	 
	ASSERT_THROW_EXCEPTION_0(SetNetworkManagerExceptionTest);
	ASSERT_THROW_EXCEPTION_0(SetInputManagerExceptionTest);
	ASSERT_THROW_EXCEPTION_0(SetObjectLogicManagerExceptionTest);
	ASSERT_THROW_EXCEPTION_0(SetPhysicalModellingManagerExceptionTest);
	ASSERT_THROW_EXCEPTION_0(SetMessageManagerExceptionTest);
	ASSERT_THROW_EXCEPTION_0(SetEventManagerExceptionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SetSystemManagerTest);
	ASSERT_THROW_EXCEPTION_0(SetResourceManagerExceptionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SetAudioManagerTest);
	ASSERT_THROW_EXCEPTION_0(SetCameraSystemsManagerExceptionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SetRenderingManagerTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SetGUIManagerTest);
}

void Framework::ResourceManagerInterfaceTesting
	::SetNetworkManagerExceptionTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr networkManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

	middleLayer.SetNetworkManager(networkManager);
}

void Framework::ResourceManagerInterfaceTesting
	::SetInputManagerExceptionTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr inputManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

	middleLayer.SetInputManager(inputManager);
}

void Framework::ResourceManagerInterfaceTesting
	::SetObjectLogicManagerExceptionTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr objectLogicManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

	middleLayer.SetObjectLogicManager(objectLogicManager);
}

void Framework::ResourceManagerInterfaceTesting
	::SetPhysicalModellingManagerExceptionTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr physicalModellingManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

	middleLayer.SetPhysicalModellingManager(physicalModellingManager);
}

void Framework::ResourceManagerInterfaceTesting
	::SetMessageManagerExceptionTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr messageManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

	middleLayer.SetMessageManager(messageManager);
}

void Framework::ResourceManagerInterfaceTesting
	::SetEventManagerExceptionTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr eventManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

	middleLayer.SetEventManager(eventManager);
}

void Framework::ResourceManagerInterfaceTesting
	::SetSystemManagerTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr systemManager(std::make_shared < SystemManagerInterface>(MiddleLayerPlatform::Windows));

	middleLayer.SetSystemManager(systemManager);
}

void Framework::ResourceManagerInterfaceTesting
	::SetResourceManagerExceptionTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr resourceManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

	middleLayer.SetResourceManager(resourceManager);
}

void Framework::ResourceManagerInterfaceTesting
	::SetAudioManagerTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr audioManager(std::make_shared < AudioManagerInterface>(MiddleLayerPlatform::Windows));

	middleLayer.SetAudioManager(audioManager);
}

void Framework::ResourceManagerInterfaceTesting
	::SetCameraSystemsManagerExceptionTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr cameraSystemsManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

	middleLayer.SetCameraSystemsManager(cameraSystemsManager);
}

void Framework::ResourceManagerInterfaceTesting
	::SetRenderingManagerTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr renderingManager(std::make_shared < RenderingManagerInterface>(MiddleLayerPlatform::Windows));

	middleLayer.SetRenderingManager(renderingManager);
}

void Framework::ResourceManagerInterfaceTesting
	::SetGUIManagerTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr guiManager(std::make_shared < GUIManagerInterface>(MiddleLayerPlatform::Windows));

	middleLayer.SetGUIManager(guiManager);
}
