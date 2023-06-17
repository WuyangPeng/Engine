///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:06)

#include "ShaderManageTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/Shaders/ShaderManager.h"

Rendering::ShaderManageTesting::ShaderManageTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ShaderManageTesting)

void Rendering::ShaderManageTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::ShaderManageTesting::MainTest()
{
    ShaderManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);

    ShaderManager::Destroy();
}

void Rendering::ShaderManageTesting::InitTest()
{
    ASSERT_ENUM_EQUAL(SHADER_MANAGE_SINGLETON.GetPixelProfile(), ShaderFlags::PixelShaderProfile::None);
    ASSERT_ENUM_EQUAL(SHADER_MANAGE_SINGLETON.GetVertexProfile(), ShaderFlags::VertexShaderProfile::None);

    SHADER_MANAGE_SINGLETON.SetPixelProfile(ShaderFlags::PixelShaderProfile::ARBFP1);

    ASSERT_ENUM_EQUAL(SHADER_MANAGE_SINGLETON.GetPixelProfile(), ShaderFlags::PixelShaderProfile::ARBFP1);
    ASSERT_ENUM_EQUAL(SHADER_MANAGE_SINGLETON.GetVertexProfile(), ShaderFlags::VertexShaderProfile::None);

    SHADER_MANAGE_SINGLETON.SetVertexProfile(ShaderFlags::VertexShaderProfile::VS20);

    ASSERT_ENUM_EQUAL(SHADER_MANAGE_SINGLETON.GetPixelProfile(), ShaderFlags::PixelShaderProfile::ARBFP1);
    ASSERT_ENUM_EQUAL(SHADER_MANAGE_SINGLETON.GetVertexProfile(), ShaderFlags::VertexShaderProfile::VS20);
}
