// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/07 14:32)

#include "ShaderManageTesting.h"
#include "Rendering/Shaders/ShaderManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, ShaderManageTesting) 

void Rendering::ShaderManageTesting
	::MainTest()
{ 
	ShaderManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(InitTest); 

	ShaderManager::Destroy();
}
 
void Rendering::ShaderManageTesting
	::InitTest()
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
 