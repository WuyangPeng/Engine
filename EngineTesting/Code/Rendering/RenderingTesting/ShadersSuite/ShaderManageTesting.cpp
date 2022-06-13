///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/11 18:44)

#include "ShaderManageTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/Shaders/ShaderManager.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, ShaderManageTesting)

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
