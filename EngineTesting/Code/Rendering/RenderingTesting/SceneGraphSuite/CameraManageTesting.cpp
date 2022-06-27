///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/14 19:09)

#include "CameraManageTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/SceneGraph/CameraManager.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, CameraManageTesting)

void Rendering::CameraManageTesting::MainTest()
{
    CameraManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(DepthTypeTest);

    CameraManager::Destroy();
}

void Rendering::CameraManageTesting::DepthTypeTest()
{
    CAMERA_MANAGE_SINGLETON.SetDefaultDepthType(RendererTypes::Default);

    ASSERT_ENUM_EQUAL(CAMERA_MANAGE_SINGLETON.GetDepthType(), DepthType::MinusOneToOne);

    CAMERA_MANAGE_SINGLETON.SetDefaultDepthType(RendererTypes::Window);

    ASSERT_ENUM_EQUAL(CAMERA_MANAGE_SINGLETON.GetDepthType(), DepthType::MinusOneToOne);

    CAMERA_MANAGE_SINGLETON.SetDefaultDepthType(RendererTypes::Glut);

    ASSERT_ENUM_EQUAL(CAMERA_MANAGE_SINGLETON.GetDepthType(), DepthType::MinusOneToOne);

    CAMERA_MANAGE_SINGLETON.SetDefaultDepthType(RendererTypes::OpenGL);

    ASSERT_ENUM_EQUAL(CAMERA_MANAGE_SINGLETON.GetDepthType(), DepthType::MinusOneToOne);

    CAMERA_MANAGE_SINGLETON.SetDefaultDepthType(RendererTypes::OpenGLES);

    ASSERT_ENUM_EQUAL(CAMERA_MANAGE_SINGLETON.GetDepthType(), DepthType::MinusOneToOne);

    CAMERA_MANAGE_SINGLETON.SetDefaultDepthType(RendererTypes::Dx9);

    ASSERT_ENUM_EQUAL(CAMERA_MANAGE_SINGLETON.GetDepthType(), DepthType::ZeroToOne);
}
