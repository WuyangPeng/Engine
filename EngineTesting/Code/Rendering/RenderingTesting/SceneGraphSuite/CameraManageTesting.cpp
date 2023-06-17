///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:31)

#include "CameraManageTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/SceneGraph/CameraManager.h"

Rendering::CameraManageTesting::CameraManageTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, CameraManageTesting)

void Rendering::CameraManageTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

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

    CAMERA_MANAGE_SINGLETON.SetDefaultDepthType(RendererTypes::Windows);

    ASSERT_ENUM_EQUAL(CAMERA_MANAGE_SINGLETON.GetDepthType(), DepthType::MinusOneToOne);

    CAMERA_MANAGE_SINGLETON.SetDefaultDepthType(RendererTypes::Glut);

    ASSERT_ENUM_EQUAL(CAMERA_MANAGE_SINGLETON.GetDepthType(), DepthType::MinusOneToOne);

    CAMERA_MANAGE_SINGLETON.SetDefaultDepthType(RendererTypes::OpenGL);

    ASSERT_ENUM_EQUAL(CAMERA_MANAGE_SINGLETON.GetDepthType(), DepthType::MinusOneToOne);

    CAMERA_MANAGE_SINGLETON.SetDefaultDepthType(RendererTypes::OpenGLES);

    ASSERT_ENUM_EQUAL(CAMERA_MANAGE_SINGLETON.GetDepthType(), DepthType::MinusOneToOne);

    CAMERA_MANAGE_SINGLETON.SetDefaultDepthType(RendererTypes::Dx11);

    ASSERT_ENUM_EQUAL(CAMERA_MANAGE_SINGLETON.GetDepthType(), DepthType::ZeroToOne);
}
