// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/25 10:07)

#include "Rendering/RenderingExport.h"

#include "LightAmbEffect.h"
#include "Rendering/ShaderFloats/LightAmbientConstant.h"
#include "Rendering/ShaderFloats/MaterialAmbientConstant.h"
#include "Rendering/ShaderFloats/MaterialEmissiveConstant.h"
#include "Rendering/ShaderFloats/LightAttenuationConstant.h"
#include "Rendering/ShaderFloats/ProjectionViewMatrixConstant.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"

#include "System/Helper/PragmaWarning.h" 
#include "CoreTools/Helper/MemoryMacro.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26492)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26493)
#include SYSTEM_WARNING_DISABLE(26485)
#include SYSTEM_WARNING_DISABLE(26815)
CORE_TOOLS_RTTI_DEFINE(Rendering, LightAmbEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, LightAmbEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, LightAmbEffect);

Rendering::LightAmbEffect
	::LightAmbEffect()
{
    VertexShaderSharedPtr vshader{ std::make_shared < VertexShader>( "Wm5.LightAmb", 1, 2, 5, 0 ) };
    vshader->SetInput(0, "modelPosition", ShaderFlags::VariableType::Float3,ShaderFlags::VariableSemantic::Position);
    vshader->SetOutput(0, "clipPosition", ShaderFlags::VariableType::Float4,ShaderFlags::VariableSemantic::Position);
    vshader->SetOutput(1, "vertexColor", ShaderFlags::VariableType::Float4,ShaderFlags::VariableSemantic::Color0);
    vshader->SetConstant(0, "PVWMatrix", 4);
    vshader->SetConstant(1, "MaterialEmissive", 1);
    vshader->SetConstant(2, "MaterialAmbient", 1);
    vshader->SetConstant(3, "LightAmbient", 1);
    vshader->SetConstant(4, "LightAttenuation", 1);

	auto profile = vshader->GetProfile();

	for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
	{
		for (auto j = 0; j < 5; ++j)
		{
			profile->SetBaseRegister(i, j, msVRegisters[i][j]);
		}

		profile->SetProgram(i, msVPrograms[i]);
	} 

	PixelShaderSharedPtr pshader{ std::make_shared<PixelShader>("Wm5.LightAmb",1, 1, 0, 0) };
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
 

Rendering::VisualEffectInstance* Rendering::LightAmbEffect
	::CreateInstance(Light* light,  Material* material) const
{
    VisualEffectInstance* instance = CoreTools::New0<VisualEffectInstance>(VisualEffectSharedPtr((VisualEffect*)this), 0);
	instance->SetVertexConstant(0, 0, ShaderFloatSharedPtr(std::make_shared< ProjectionViewMatrixConstant>()));
        instance->SetVertexConstant(0, 1, ShaderFloatSharedPtr(std::make_shared < MaterialEmissiveConstant>(MaterialSharedPtr(material))));
        instance->SetVertexConstant(0, 2, ShaderFloatSharedPtr(std::make_shared < MaterialAmbientConstant>(MaterialSharedPtr(material))));
        instance->SetVertexConstant(0, 3, ShaderFloatSharedPtr(std::make_shared < LightAmbientConstant>(LightSharedPtr(light))));
        instance->SetVertexConstant(0, 4, ShaderFloatSharedPtr(std::make_shared < LightAttenuationConstant>(LightSharedPtr(light))));

    return instance;
}

Rendering::VisualEffectInstance* Rendering::LightAmbEffect
	::CreateUniqueInstance(Light* light, Material* material)
{
   const LightAmbEffect* effect = CoreTools::New0 < LightAmbEffect>();
    return effect->CreateInstance(light, material);
}


// Streaming support.

Rendering::LightAmbEffect
	::LightAmbEffect(LoadConstructor value)
	: ParentType{ value }
{
}

void Rendering::LightAmbEffect
	::Load(const CoreTools::BufferSourceSharedPtr& source)
{
	CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    VisualEffect::Load(source);

	CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::LightAmbEffect
	::Link(const CoreTools::ObjectLinkSharedPtr& source)
{
    VisualEffect::Link(source);
}

void Rendering::LightAmbEffect
	::PostLink()
{
    VisualEffect::PostLink();   

	auto pass = GetTechnique(0)->GetPass(0);
	auto vshader = pass->GetVertexShader();
	auto pshader = pass->GetPixelShader();
	auto profile = const_cast<ShaderProfileData*>(vshader->GetProfile().get());

	for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
	{
		for (auto j = 0; j < 5; ++j)
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

uint64_t Rendering::LightAmbEffect ::Register(const CoreTools::ObjectRegisterSharedPtr& target) const
{
    return VisualEffect::Register(target);
}

void Rendering::LightAmbEffect
	::Save(const CoreTools::BufferTargetSharedPtr& target) const
{
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    VisualEffect::Save(target);

	CORE_TOOLS_END_DEBUG_STREAM_SAVE( target);
}

int  Rendering::LightAmbEffect
	::GetStreamingSize() const
{
    return VisualEffect::GetStreamingSize();
}

// Profiles.

int  Rendering::LightAmbEffect::msDx9VRegisters[5]  { 0, 4, 5, 6, 7 };
int  Rendering::LightAmbEffect::msOglVRegisters[5] { 1, 5, 6, 7, 8 };
int*  Rendering::LightAmbEffect::msVRegisters[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)] 
{
    0,
    msDx9VRegisters,
    msDx9VRegisters,
    msDx9VRegisters,
    msOglVRegisters
};

std::string  Rendering::LightAmbEffect::msVPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)] 
{
    // VP_NONE
    "",

    // VP_VS_1_1
    "vs_1_1\n"
    "def c8, 1.00000000, 0, 0, 0\n"
    "dcl_position0 v0\n"
    "mov r1.x, c7.w\n"
    "mul r1.xyz, c6, r1.x\n"
    "mul r1.xyz, r1, c5\n"
    "mov r0.w, c8.x\n"
    "mov r0.xyz, v0\n"
    "dp4 oPos.w, r0, c3\n"
    "dp4 oPos.z, r0, c2\n"
    "dp4 oPos.y, r0, c1\n"
    "dp4 oPos.x, r0, c0\n"
    "add oD0.xyz, r1, c4\n"
    "mov oD0.w, c8.x\n",

    // VP_VS_2_0
    "vs_2_0\n"
    "def c8, 1.00000000, 0, 0, 0\n"
    "dcl_position v0\n"
    "mov r1.x, c7.w\n"
    "mul r1.xyz, c6, r1.x\n"
    "mul r1.xyz, r1, c5\n"
    "mov r0.w, c8.x\n"
    "mov r0.xyz, v0\n"
    "dp4 oPos.w, r0, c3\n"
    "dp4 oPos.z, r0, c2\n"
    "dp4 oPos.y, r0, c1\n"
    "dp4 oPos.x, r0, c0\n"
    "add oD0.xyz, r1, c4\n"
    "mov oD0.w, c8.x\n",

    // VP_VS_3_0
    "vs_3_0\n"
    "dcl_position o0\n"
    "dcl_color0 o1\n"
    "def c8, 1.00000000, 0, 0, 0\n"
    "dcl_position0 v0\n"
    "mov r1.x, c7.w\n"
    "mul r1.xyz, c6, r1.x\n"
    "mul r1.xyz, r1, c5\n"
    "mov r0.w, c8.x\n"
    "mov r0.xyz, v0\n"
    "dp4 o0.w, r0, c3\n"
    "dp4 o0.z, r0, c2\n"
    "dp4 o0.y, r0, c1\n"
    "dp4 o0.x, r0, c0\n"
    "add o1.xyz, r1, c4\n"
    "mov o1.w, c8.x\n",

    // VP_ARBVP1
    "!!ARBvp1.0\n"
    "PARAM c[9] = { { 1 }, program.local[1..8] };\n"
    "TEMP R0;\n"
    "TEMP R1;\n"
    "MOV R1.xyz, c[7];\n"
    "MUL R1.xyz, R1, c[8].w;\n"
    "MUL R1.xyz, R1, c[6];\n"
    "MOV R0.w, c[0].x;\n"
    "MOV R0.xyz, vertex.position;\n"
    "DP4 result.position.w, R0, c[4];\n"
    "DP4 result.position.z, R0, c[3];\n"
    "DP4 result.position.y, R0, c[2];\n"
    "DP4 result.position.x, R0, c[1];\n"
    "ADD result.color.xyz, R1, c[5];\n"
    "MOV result.color.w, c[0].x;\n"
    "END\n"
};

std::string  Rendering::LightAmbEffect::msPPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)] 
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