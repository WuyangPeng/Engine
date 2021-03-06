// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/25 10:36)

#include "Rendering/RenderingExport.h"

#include "LightDirPerVerEffect.h"
#include "Rendering/ShaderFloats/MaterialAmbientConstant.h"
#include "Rendering/ShaderFloats/MaterialDiffuseConstant.h"
#include "Rendering/ShaderFloats/MaterialSpecularConstant.h"
#include "Rendering/ShaderFloats/MaterialEmissiveConstant.h"
#include "Rendering/ShaderFloats/LightAmbientConstant.h"
#include "Rendering/ShaderFloats/LightDiffuseConstant.h"
#include "Rendering/ShaderFloats/LightSpecularConstant.h"
#include "Rendering/ShaderFloats/LightAttenuationConstant.h"
#include "Rendering/ShaderFloats/LightModelDirectionVectorConstant.h"
#include "Rendering/ShaderFloats/CameraModelPositionConstant.h"
#include "Rendering/ShaderFloats/ProjectionViewMatrixConstant.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

 #include "System/Helper/PragmaWarning.h" 
#include "CoreTools/Helper/MemoryMacro.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26492)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26493)
#include SYSTEM_WARNING_DISABLE(26485)
#include SYSTEM_WARNING_DISABLE(26815)
#include SYSTEM_WARNING_DISABLE(26455)
CORE_TOOLS_RTTI_DEFINE(Rendering, LightDirPerVerEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, LightDirPerVerEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, LightDirPerVerEffect);

Rendering::LightDirPerVerEffect::LightDirPerVerEffect()
{
    VertexShaderSharedPtr vshader{ std::make_shared < VertexShader>("Wm5.LightDirPerVer", 2, 2, 11, 0 ) };
    vshader->SetInput(0, "modelPosition", ShaderFlags::VariableType::Float3,ShaderFlags::VariableSemantic::Position);
    vshader->SetInput(1, "modelNormal", ShaderFlags::VariableType::Float3,ShaderFlags::VariableSemantic::TextureCoord1);
    vshader->SetOutput(0, "clipPosition", ShaderFlags::VariableType::Float4,ShaderFlags::VariableSemantic::Position);
    vshader->SetOutput(1, "vertexColor", ShaderFlags::VariableType::Float4,ShaderFlags::VariableSemantic::Color0);
    vshader->SetConstant(0, "PVWMatrix", 4);
    vshader->SetConstant(1, "CameraModelPosition", 1);
    vshader->SetConstant(2, "MaterialEmissive", 1);
    vshader->SetConstant(3, "MaterialAmbient", 1);
    vshader->SetConstant(4, "MaterialDiffuse", 1);
    vshader->SetConstant(5, "MaterialSpecular", 1);
    vshader->SetConstant(6, "LightModelDirection", 1);
    vshader->SetConstant(7, "LightAmbient", 1);
    vshader->SetConstant(8, "LightDiffuse", 1);
    vshader->SetConstant(9, "LightSpecular", 1);
    vshader->SetConstant(10, "LightAttenuation", 1);

	auto profile = vshader->GetProfile();

	for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
	{
		for (auto j = 0; j < 11; ++j)
		{
			profile->SetBaseRegister(i, j, msVRegisters[i][j]);
		}

		profile->SetProgram(i, msVPrograms[i]);
	}

	PixelShaderSharedPtr pshader{ std::make_shared<PixelShader>( "Wm5.LightDirPerVer",1, 1, 0, 0 ) };
    pshader->SetInput(0, "vertexColor", ShaderFlags::VariableType::Float4,ShaderFlags::VariableSemantic::Color0);
    pshader->SetOutput(0, "pixelColor", ShaderFlags::VariableType::Float4,ShaderFlags::VariableSemantic::Color0);
	profile = pshader->GetProfile();

	for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
	{
		profile->SetProgram(i, msPPrograms[i]);
	}

	VisualPassSharedPtr pass{ std::make_shared < VisualPass>() };
	pass->SetVertexShader(vshader);
	pass->SetPixelShader(pshader);
        pass->SetAlphaState(AlphaStateSharedPtr{ std::make_shared<AlphaState>() });
        pass->SetCullState(CullStateSharedPtr{ std::make_shared<CullState>() });
        pass->SetDepthState(DepthStateSharedPtr{ std::make_shared<DepthState>() });
        pass->SetOffsetState(OffsetStateSharedPtr{ std::make_shared<OffsetState>() });
        pass->SetStencilState(StencilStateSharedPtr{ std::make_shared<StencilState>() });
        pass->SetWireState(WireStateSharedPtr{ std::make_shared<WireState>() });

	VisualTechniqueSharedPtr technique{ std::make_shared<VisualTechnique>() };
	technique->InsertPass(pass);
	InsertTechnique(technique);
}

 

Rendering::VisualEffectInstance* Rendering::LightDirPerVerEffect::CreateInstance(
    Light* light, Material* material) const
{
	VisualEffectInstance* instance = CoreTools::New0 < VisualEffectInstance>(VisualEffectSharedPtr((VisualEffect*)this), 0);
    instance->SetVertexConstant(0, 0, ShaderFloatSharedPtr(std::make_shared < ProjectionViewMatrixConstant>()));
    instance->SetVertexConstant(0, 1,ShaderFloatSharedPtr(std::make_shared<CameraModelPositionConstant>()));
    instance->SetVertexConstant(0, 2, ShaderFloatSharedPtr(std::make_shared < MaterialEmissiveConstant>(MaterialSharedPtr(material))));
    instance->SetVertexConstant(0, 3, ShaderFloatSharedPtr(std::make_shared < MaterialAmbientConstant>(MaterialSharedPtr(material))));
    instance->SetVertexConstant(0, 4, ShaderFloatSharedPtr(std::make_shared < MaterialDiffuseConstant>(MaterialSharedPtr(material))));
    instance->SetVertexConstant(0, 5, ShaderFloatSharedPtr(std::make_shared < MaterialSpecularConstant>(MaterialSharedPtr(material))));
    instance->SetVertexConstant(0, 6, ShaderFloatSharedPtr(std::make_shared < LightModelDirectionVectorConstant>(LightSharedPtr(light))));
    instance->SetVertexConstant(0, 7, ShaderFloatSharedPtr(std::make_shared < LightAmbientConstant>(LightSharedPtr(light))));
    instance->SetVertexConstant(0, 8, ShaderFloatSharedPtr(std::make_shared < LightDiffuseConstant>(LightSharedPtr(light))));
    instance->SetVertexConstant(0, 9, ShaderFloatSharedPtr(std::make_shared < LightSpecularConstant>(LightSharedPtr(light))));
    instance->SetVertexConstant(0, 10, ShaderFloatSharedPtr(std::make_shared < LightAttenuationConstant>(LightSharedPtr(light))));
    return instance;
}

Rendering::VisualEffectInstance* Rendering::LightDirPerVerEffect::CreateUniqueInstance(
    Light* light, Material* material)
{
    const LightDirPerVerEffect* effect = CoreTools::New0 < LightDirPerVerEffect>();
    return effect->CreateInstance(light, material);
}



// Streaming support.

Rendering::LightDirPerVerEffect
	::LightDirPerVerEffect(LoadConstructor value)
	: VisualEffect{ value }
{
}

void Rendering::LightDirPerVerEffect
	::Load(const CoreTools::BufferSourceSharedPtr& source)
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    VisualEffect::Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::LightDirPerVerEffect
	::Link(const CoreTools::ObjectLinkSharedPtr& source)
{
    VisualEffect::Link(source);
}

void Rendering::LightDirPerVerEffect
	::PostLink()
{
	VisualEffect::PostLink();

	auto pass = GetTechnique(0)->GetPass(0);
	auto vshader = pass->GetVertexShader();
	auto pshader = pass->GetPixelShader();
	auto profile = const_cast<ShaderProfileData*>(vshader->GetProfile().get());

	for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
	{
		for (auto j = 0; j < 11; ++j)
		{
			profile->SetBaseRegister(i, j, msVRegisters[i][j]);
		}

		profile->SetProgram(i, msVPrograms[i]);
	}

	profile = const_cast<ShaderProfileData*>(pshader->GetProfile().get());

	for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
	{
		profile->SetProgram(i, msPPrograms[i]);
	}
}

uint64_t Rendering::LightDirPerVerEffect ::Register(const CoreTools::ObjectRegisterSharedPtr& target) const
{
    return VisualEffect::Register(target);
}

void Rendering::LightDirPerVerEffect
	::Save(const CoreTools::BufferTargetSharedPtr& target) const
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    VisualEffect::Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::LightDirPerVerEffect
	::GetStreamingSize() const
{
    return VisualEffect::GetStreamingSize();
}



// Profiles.

int Rendering::LightDirPerVerEffect::msDx9VRegisters[11] 
    { 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };

int Rendering::LightDirPerVerEffect::msOglVRegisters[11] 
    { 1, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };

int* Rendering::LightDirPerVerEffect::msVRegisters[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)] 
{
    0,
    msDx9VRegisters,
    msDx9VRegisters,
    msDx9VRegisters,
    msOglVRegisters
};

std::string Rendering::LightDirPerVerEffect::msVPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)] 
{
    // VP_NONE
    "",

    // VP_VS_1_1
    "vs_1_1\n"
    "def c14, 1.00000000, 0, 0, 0\n"
    "dcl_position0 v0\n"
    "dcl_texcoord1 v1\n"
    "add r1.xyz, -v0, c4\n"
    "dp3 r0.x, r1, r1\n"
    "rsq r0.x, r0.x\n"
    "mad r1.xyz, r0.x, r1, -c9\n"
    "dp3 r0.x, r1, r1\n"
    "rsq r0.x, r0.x\n"
    "mul r0.xyz, r0.x, r1\n"
    "dp3 r0.y, v1, r0\n"
    "dp3 r0.x, v1, c9\n"
    "mov r0.x, -r0\n"
    "mov r0.z, c8.w\n"
    "lit r0.yz, r0.xyzz\n"
    "mul r1.xyz, r0.y, c7\n"
    "mov r0.xyw, c6.xyzz\n"
    "mul r1.xyz, r1, c11\n"
    "mad r1.xyz, c10, r0.xyww, r1\n"
    "mul r0.xyz, r0.z, c8\n"
    "mad r0.xyz, r0, c12, r1\n"
    "mul r0.xyz, r0, c13.w\n"
    "add oD0.xyz, r0, c5\n"
    "mov r0.w, c14.x\n"
    "mov r0.xyz, v0\n"
    "dp4 oPos.w, r0, c3\n"
    "dp4 oPos.z, r0, c2\n"
    "dp4 oPos.y, r0, c1\n"
    "dp4 oPos.x, r0, c0\n"
    "mov oD0.w, c7\n",

    // VP_VS_2_0
    "vs_2_0\n"
    "def c14, 1.00000000, 0, 0, 0\n"
    "dcl_position v0\n"
    "dcl_texcoord1 v1\n"
    "add r1.xyz, -v0, c4\n"
    "dp3 r0.x, r1, r1\n"
    "rsq r0.x, r0.x\n"
    "mad r1.xyz, r0.x, r1, -c9\n"
    "dp3 r0.x, r1, r1\n"
    "rsq r0.x, r0.x\n"
    "mul r0.xyz, r0.x, r1\n"
    "dp3 r0.y, v1, r0\n"
    "dp3 r0.x, v1, c9\n"
    "mov r0.x, -r0\n"
    "mov r0.z, c8.w\n"
    "lit r0.yz, r0.xyzz\n"
    "mul r1.xyz, r0.y, c7\n"
    "mov r0.xyw, c6.xyzz\n"
    "mul r1.xyz, r1, c11\n"
    "mad r1.xyz, c10, r0.xyww, r1\n"
    "mul r0.xyz, r0.z, c8\n"
    "mad r0.xyz, r0, c12, r1\n"
    "mul r0.xyz, r0, c13.w\n"
    "add oD0.xyz, r0, c5\n"
    "mov r0.w, c14.x\n"
    "mov r0.xyz, v0\n"
    "dp4 oPos.w, r0, c3\n"
    "dp4 oPos.z, r0, c2\n"
    "dp4 oPos.y, r0, c1\n"
    "dp4 oPos.x, r0, c0\n"
    "mov oD0.w, c7\n",

    // VP_VS_3_0
    "vs_3_0\n"
    "dcl_position o0\n"
    "dcl_color0 o1\n"
    "def c14, 1.00000000, 0, 0, 0\n"
    "dcl_position0 v0\n"
    "dcl_texcoord1 v1\n"
    "add r1.xyz, -v0, c4\n"
    "dp3 r0.x, r1, r1\n"
    "rsq r0.x, r0.x\n"
    "mad r1.xyz, r0.x, r1, -c9\n"
    "dp3 r0.x, r1, r1\n"
    "rsq r0.x, r0.x\n"
    "mul r0.xyz, r0.x, r1\n"
    "dp3 r0.y, v1, r0\n"
    "dp3 r0.x, v1, c9\n"
    "mov r0.x, -r0\n"
    "mov r0.z, c8.w\n"
    "lit r0.yz, r0.xyzz\n"
    "mul r1.xyz, r0.y, c7\n"
    "mov r0.xyw, c6.xyzz\n"
    "mul r1.xyz, r1, c11\n"
    "mad r1.xyz, c10, r0.xyww, r1\n"
    "mul r0.xyz, r0.z, c8\n"
    "mad r0.xyz, r0, c12, r1\n"
    "mul r0.xyz, r0, c13.w\n"
    "add o1.xyz, r0, c5\n"
    "mov r0.w, c14.x\n"
    "mov r0.xyz, v0\n"
    "dp4 o0.w, r0, c3\n"
    "dp4 o0.z, r0, c2\n"
    "dp4 o0.y, r0, c1\n"
    "dp4 o0.x, r0, c0\n"
    "mov o1.w, c7\n",

    // VP_ARBVP1
    "!!ARBvp1.0\n"
    "PARAM c[15] = { { 1 }, program.local[1..14] };\n"
    "TEMP R0;\n"
    "TEMP R1;\n"
    "ADD R1.xyz, -vertex.position, c[5];\n"
    "DP3 R0.x, R1, R1;\n"
    "RSQ R0.x, R0.x;\n"
    "MAD R1.xyz, R0.x, R1, -c[10];\n"
    "DP3 R0.x, R1, R1;\n"
    "RSQ R0.x, R0.x;\n"
    "MUL R0.xyz, R0.x, R1;\n"
    "DP3 R0.y, vertex.texcoord[1], R0;\n"
    "DP3 R0.x, vertex.texcoord[1], c[10];\n"
    "MOV R0.x, -R0;\n"
    "MOV R0.z, c[9].w;\n"
    "LIT R0.yz, R0.xyzz;\n"
    "MUL R1.xyz, R0.y, c[8];\n"
    "MOV R0.xyw, c[11].xyzz;\n"
    "MUL R1.xyz, R1, c[12];\n"
    "MAD R1.xyz, R0.xyww, c[7], R1;\n"
    "MUL R0.xyz, R0.z, c[9];\n"
    "MAD R0.xyz, R0, c[13], R1;\n"
    "MUL R0.xyz, R0, c[14].w;\n"
    "ADD result.color.xyz, R0, c[6];\n"
    "MOV R0.w, c[0].x;\n"
    "MOV R0.xyz, vertex.position;\n"
    "DP4 result.position.w, R0, c[4];\n"
    "DP4 result.position.z, R0, c[3];\n"
    "DP4 result.position.y, R0, c[2];\n"
    "DP4 result.position.x, R0, c[1];\n"
    "MOV result.color.w, c[8];\n"
    "END\n"
};

std::string Rendering::LightDirPerVerEffect::msPPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)] 
{
    // PP_NONE
    "",

    // PP_PS_1_1
    "ps.1.1\n"
    "mov r0, v0\n",

    // PP_PS_2_0
    "ps_2_0\n"
    "dcl v0\n"
    "mov oC0, v0\n",

    // PP_PS_3_0
    "ps_3_0\n"
    "dcl_color0 v0\n"
    "mov oC0, v0\n",

    // PP_ARBFP1
    "!!ARBfp1.0\n"
    "MOV result.color, fragment.color.primary;\n"
    "END\n"
};
#include STSTEM_WARNING_POP
