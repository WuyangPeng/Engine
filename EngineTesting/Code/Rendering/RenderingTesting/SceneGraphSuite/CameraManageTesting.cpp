// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/05 09:39)

#include "CameraManageTesting.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering,CameraManageTesting) 

void Rendering::CameraManageTesting
	::MainTest()
{
	CameraManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(DepthTypeTest);

	CameraManager::Destroy();
}
 
void Rendering::CameraManageTesting
	::DepthTypeTest()
{
	CAMERA_MANAGE_SINGLETON.SetDefaultDepthType(RendererTypes::Default);

 	ASSERT_ENUM_EQUAL(CAMERA_MANAGE_SINGLETON.GetDepthType(),DepthType::MinusOneToOne);

	CAMERA_MANAGE_SINGLETON.SetDefaultDepthType(RendererTypes::Window);

	ASSERT_ENUM_EQUAL(CAMERA_MANAGE_SINGLETON.GetDepthType(),DepthType::MinusOneToOne);

	CAMERA_MANAGE_SINGLETON.SetDefaultDepthType(RendererTypes::Glut);

	ASSERT_ENUM_EQUAL(CAMERA_MANAGE_SINGLETON.GetDepthType(),DepthType::MinusOneToOne);

	CAMERA_MANAGE_SINGLETON.SetDefaultDepthType(RendererTypes::OpenGL);

	ASSERT_ENUM_EQUAL(CAMERA_MANAGE_SINGLETON.GetDepthType(),DepthType::MinusOneToOne);

	CAMERA_MANAGE_SINGLETON.SetDefaultDepthType(RendererTypes::OpenGLES);

	ASSERT_ENUM_EQUAL(CAMERA_MANAGE_SINGLETON.GetDepthType(),DepthType::MinusOneToOne);

	CAMERA_MANAGE_SINGLETON.SetDefaultDepthType(RendererTypes::Dx9);

	ASSERT_ENUM_EQUAL(CAMERA_MANAGE_SINGLETON.GetDepthType(),DepthType::ZeroToOne);
}

 