// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/16 09:41)

#include "ObjectLogicManagerInterfaceTesting.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h" 

#include "Framework/MiddleLayer/ObjectLogicManagerInterface.h" 
#include "Framework/MiddleLayer/NetworkManagerInterface.h"
#include "Framework/MiddleLayer/InputManagerInterface.h"
#include "Framework/MiddleLayer/PhysicalModellingManagerInterface.h"
#include "Framework/MiddleLayer/MessageManagerInterface.h"
#include "Framework/MiddleLayer/SystemManagerInterface.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"
#include "System/Windows/Flags/WindowsDisplayFlags.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/WindowProcess/Flags/MouseTypes.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"

#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  

namespace Framework
{
	using TestingType = ObjectLogicManagerInterface;
}

Framework::ObjectLogicManagerInterfaceTesting
::ObjectLogicManagerInterfaceTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ObjectLogicManagerInterfaceTesting)

void Framework::ObjectLogicManagerInterfaceTesting
::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}
 
void Framework::ObjectLogicManagerInterfaceTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SetMiddleLayerTest);
}

void Framework::ObjectLogicManagerInterfaceTesting
	::MiddleLayerTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	ASSERT_TRUE(middleLayer.PreCreate(EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }));
	ASSERT_TRUE(middleLayer.Initialize());
	middleLayer.PreIdle();
	ASSERT_TRUE(middleLayer.Create());	
	ASSERT_TRUE(middleLayer.Paint());
	ASSERT_TRUE(middleLayer.Move(WindowPoint()));
	ASSERT_TRUE(middleLayer.Resize(System::WindowsDisplay::MaxHide,WindowSize()));
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

void Framework::ObjectLogicManagerInterfaceTesting
	::SetMiddleLayerTest()
{	 
	ASSERT_NOT_THROW_EXCEPTION_0(SetNetworkManagerTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SetInputManagerTest);
	ASSERT_THROW_EXCEPTION_0(SetObjectLogicManagerExceptionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SetPhysicalModellingManagerTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SetMessageManagerTest);
	ASSERT_THROW_EXCEPTION_0(SetEventManagerExceptionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SetSystemManagerTest);
	ASSERT_THROW_EXCEPTION_0(SetResourceManagerExceptionTest);
	ASSERT_THROW_EXCEPTION_0(SetAudioManagerExceptionTest);
	ASSERT_THROW_EXCEPTION_0(SetCameraSystemsManagerExceptionTest);
	ASSERT_THROW_EXCEPTION_0(SetRenderingManagerExceptionTest);
	ASSERT_THROW_EXCEPTION_0(SetGUIManagerExceptionTest);
}

void Framework::ObjectLogicManagerInterfaceTesting
	::SetNetworkManagerTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr networkManager(std::make_shared < NetworkManagerInterface>(MiddleLayerPlatform::Windows));

	middleLayer.SetNetworkManager(networkManager);
}

void Framework::ObjectLogicManagerInterfaceTesting
	::SetInputManagerTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr inputManager(std::make_shared < InputManagerInterface>(MiddleLayerPlatform::Windows));

	middleLayer.SetInputManager(inputManager);
}

void Framework::ObjectLogicManagerInterfaceTesting
	::SetObjectLogicManagerExceptionTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr objectLogicManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

	middleLayer.SetObjectLogicManager(objectLogicManager);
}

void Framework::ObjectLogicManagerInterfaceTesting
	::SetPhysicalModellingManagerTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr physicalModellingManager(std::make_shared < PhysicalModellingManagerInterface>(MiddleLayerPlatform::Windows));

	middleLayer.SetPhysicalModellingManager(physicalModellingManager);
}

void Framework::ObjectLogicManagerInterfaceTesting
	::SetMessageManagerTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr messageManager(std::make_shared < MessageManagerInterface>(MiddleLayerPlatform::Windows));

	middleLayer.SetMessageManager(messageManager);
}

void Framework::ObjectLogicManagerInterfaceTesting
	::SetEventManagerExceptionTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr eventManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

	middleLayer.SetEventManager(eventManager);
}

void Framework::ObjectLogicManagerInterfaceTesting
	::SetSystemManagerTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr systemManager(std::make_shared < SystemManagerInterface>(MiddleLayerPlatform::Windows));

	middleLayer.SetSystemManager(systemManager);
}

void Framework::ObjectLogicManagerInterfaceTesting
	::SetResourceManagerExceptionTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr resourceManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

	middleLayer.SetResourceManager(resourceManager);
}

void Framework::ObjectLogicManagerInterfaceTesting
	::SetAudioManagerExceptionTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr audioManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

	middleLayer.SetAudioManager(audioManager);
}

void Framework::ObjectLogicManagerInterfaceTesting
	::SetCameraSystemsManagerExceptionTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr cameraSystemsManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

	middleLayer.SetCameraSystemsManager(cameraSystemsManager);
}

void Framework::ObjectLogicManagerInterfaceTesting
	::SetRenderingManagerExceptionTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr renderingManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

	middleLayer.SetRenderingManager(renderingManager);
}

void Framework::ObjectLogicManagerInterfaceTesting
	::SetGUIManagerExceptionTest()
{
	TestingType middleLayer(MiddleLayerPlatform::Windows);

	MiddleLayerInterfaceSharedPtr guiManager(std::make_shared<TestingType>(MiddleLayerPlatform::Windows));

	middleLayer.SetGUIManager(guiManager);
}
