// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 14:29)

#include "Rendering/RenderingExport.h"

#include "Texture2ColorBlendEffect.h"
#include "Rendering/ShaderFloats/ProjectionViewMatrixConstant.h" 
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "System/Helper/PragmaWarning.h" 
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
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26487)
#include SYSTEM_WARNING_DISABLE(26434)
#include SYSTEM_WARNING_DISABLE(26815)
CORE_TOOLS_RTTI_DEFINE(Rendering, Texture2ColorBlendEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Texture2ColorBlendEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Texture2ColorBlendEffect);

Rendering::Texture2ColorBlendEffect
	::Texture2ColorBlendEffect ()
{
    VertexShaderSmartPointer vshader{ std::make_shared < VertexShader>( "Wm5.Texture2ColorBlend", 3, 3, 1, 0 ) };
    vshader->SetInput(0, "modelPosition", ShaderFlags::VariableType::Float3,ShaderFlags::VariableSemantic::Position);
    vshader->SetInput(1, "modelTCoord0", ShaderFlags::VariableType::Float2,ShaderFlags::VariableSemantic::TextureCoord0);
    vshader->SetInput(2, "modelTCoord1", ShaderFlags::VariableType::Float2,ShaderFlags::VariableSemantic::TextureCoord1);
    vshader->SetOutput(0, "clipPosition", ShaderFlags::VariableType::Float4,ShaderFlags::VariableSemantic::Position);
    vshader->SetOutput(1, "vertexTCoord0", ShaderFlags::VariableType::Float2,ShaderFlags::VariableSemantic::TextureCoord0);
    vshader->SetOutput(2, "vertexTCoord1", ShaderFlags::VariableType::Float2, ShaderFlags::VariableSemantic::TextureCoord1);
    vshader->SetConstant(0, "PVWMatrix", 4);
	auto profile = vshader->GetProfile();

	for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
	{
		for (auto j = 0; j < 1; ++j)
		{
			profile->SetBaseRegister(i, j, msVRegisters[i][j]);
		}

		profile->SetProgram(i, msVPrograms[i]);
	}

	PixelShaderSmartPointer pshader{ std::make_shared<PixelShader>("Wm5.Texture2ColorBlend",2, 1, 0, 2) };
    pshader->SetInput(0, "vertexTCoord0", ShaderFlags::VariableType::Float2,ShaderFlags::VariableSemantic::TextureCoord0);
    pshader->SetInput(1, "vertexTCoord1", ShaderFlags::VariableType::Float2,ShaderFlags::VariableSemantic::TextureCoord1);
    pshader->SetOutput(0, "pixelColor", ShaderFlags::VariableType::Float4,ShaderFlags::VariableSemantic::Color0);
    pshader->SetSampler(0, "Sampler0", ShaderFlags::SamplerType::Sampler2D);
    pshader->SetSampler(1, "Sampler1", ShaderFlags::SamplerType::Sampler2D);

	for(auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
	{
		for (auto j = 0; j < 2; ++j)
		{
			profile->SetTextureUnit(i, j, msPTextureUnits[i][j]);
		}

		profile->SetProgram(i, msPPrograms[i]);
	}

   VisualPassSmartPointer pass{   };
	pass->SetVertexShader(vshader);
	pass->SetPixelShader(pshader);
	pass->SetAlphaState(AlphaStateSmartPointer{   });
	pass->SetCullState(CullStateSmartPointer{   });
	pass->SetDepthState(DepthStateSmartPointer{   });
	pass->SetOffsetState(OffsetStateSmartPointer{    });
	pass->SetStencilState(StencilStateSmartPointer{   });
	pass->SetWireState(WireStateSmartPointer{   });

	VisualTechniqueSmartPointer technique{   };
	technique->InsertPass(pass);
	InsertTechnique(technique);
}

 

Rendering::PixelShader* Rendering
	::Texture2ColorBlendEffect::GetPixelShader () const
{
	return const_cast<PixelShader*>(GetTechnique(0)->GetPass(0)->GetPixelShader().get());

}

Rendering::VisualEffectInstance* Rendering::Texture2ColorBlendEffect
	::CreateInstance ( Texture2D* texture0, Texture2D* texture1) const
{
	VisualEffectInstance* instance = CoreTools::New0 < VisualEffectInstance>(VisualEffectSmartPointer((VisualEffect*)this), 0);
    instance->SetVertexConstant(0, 0, ShaderFloatSmartPointer(std::make_shared < ProjectionViewMatrixConstant>()));
	instance->SetPixelTexture(0, 0, TextureSmartPointer(texture0));
	instance->SetPixelTexture(0, 1, TextureSmartPointer(texture1));

    const PixelShader* pshader = GetPixelShader();

	const ShaderFlags::SamplerFilter filter0 = pshader->GetFilter(0);
	if (filter0 != ShaderFlags::SamplerFilter::Nearest && filter0 != ShaderFlags::SamplerFilter::Linear &&  !texture0->HasMipmaps())
    {
        texture0->GenerateMipmaps();
    }

	const ShaderFlags::SamplerFilter filter1 = pshader->GetFilter(1);
	if (filter1 != ShaderFlags::SamplerFilter::Nearest && filter1 != ShaderFlags::SamplerFilter::Linear &&  !texture1->HasMipmaps())
    {
        texture1->GenerateMipmaps();
    }

    return instance;
}

Rendering::VisualEffectInstance* Rendering::Texture2ColorBlendEffect
	::CreateUniqueInstance ( Texture2D* texture0, ShaderFlags::SamplerFilter filter0, ShaderFlags::SamplerCoordinate coordinate00, ShaderFlags::SamplerCoordinate coordinate01,
							 Texture2D* texture1,ShaderFlags::SamplerFilter filter1, ShaderFlags::SamplerCoordinate coordinate10,ShaderFlags::SamplerCoordinate coordinate11)
{
    const Texture2ColorBlendEffect* effect = CoreTools::New0 < Texture2ColorBlendEffect>();
    PixelShader* pshader = effect->GetPixelShader();
    pshader->SetFilter(0, filter0);
    pshader->SetCoordinate(0, 0, coordinate00);
    pshader->SetCoordinate(0, 1, coordinate01);
    pshader->SetFilter(1, filter1);
    pshader->SetCoordinate(1, 0, coordinate10);
    pshader->SetCoordinate(1, 1, coordinate11);
    return effect->CreateInstance(texture0, texture1);
}



// Streaming support.

Rendering::Texture2ColorBlendEffect
	::Texture2ColorBlendEffect (LoadConstructor value)
	: VisualEffect{ value }
{
}

void Rendering::Texture2ColorBlendEffect
	::Load(CoreTools::BufferSource& source)
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    VisualEffect::Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD( source);
}

void Rendering::Texture2ColorBlendEffect
	::Link(CoreTools::ObjectLink& source)
{
    VisualEffect::Link(source);
}

void Rendering::Texture2ColorBlendEffect
	::PostLink ()
{
	VisualEffect::PostLink();

	auto pass = GetTechnique(0)->GetPass(0);
	auto vshader = pass->GetVertexShader();
	auto pshader = pass->GetPixelShader();
	auto profile = const_cast<ShaderProfileData*>(vshader->GetProfile().get());

	for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
	{
		for (auto j = 0; j < 1; ++j)
		{
			profile->SetBaseRegister(i, j, msVRegisters[i][j]);
		}

		profile->SetProgram(i, msVPrograms[i]);
	}

	profile = const_cast<ShaderProfileData*>(pshader->GetProfile().get());

	for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
	{
		for (auto j = 0; j < 2; ++j)
		{
			profile->SetTextureUnit(i, j, msPTextureUnits[i][j]);
		}

		profile->SetProgram(i, msPPrograms[i]);
	}
}

uint64_t Rendering::Texture2ColorBlendEffect
	::Register(CoreTools::ObjectRegister& target) const
{
    return VisualEffect::Register(target);
}

void Rendering::Texture2ColorBlendEffect
	::Save(CoreTools::BufferTarget& target) const
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    VisualEffect::Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE( target);
}

int Rendering::Texture2ColorBlendEffect
	::GetStreamingSize () const
{
    return VisualEffect::GetStreamingSize();
}



// Profiles.

int Rendering::Texture2ColorBlendEffect::msDx9VRegisters[1]   { 0 };
int Rendering::Texture2ColorBlendEffect::msOglVRegisters[1]   { 1 };
int* Rendering::Texture2ColorBlendEffect::msVRegisters[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)]  
{
    0,
    msDx9VRegisters,
    msDx9VRegisters,
    msDx9VRegisters,
    msOglVRegisters
};

std::string Rendering::Texture2ColorBlendEffect::msVPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)]  
{ 
    // VP_NONE
    "",

    // VP_VS_1_1
    "vs_1_1\n"
    "def c4, 1.00000000, 0, 0, 0\n"
    "dcl_position0 v0\n"
    "dcl_texcoord0 v1\n"
    "dcl_texcoord1 v2\n"
    "mov r0.w, c4.x\n"
    "mov r0.xyz, v0\n"
    "dp4 oPos.w, r0, c3\n"
    "dp4 oPos.z, r0, c2\n"
    "dp4 oPos.y, r0, c1\n"
    "dp4 oPos.x, r0, c0\n"
    "mov oT0.xy, v1\n"
    "mov oT1.xy, v2\n",

    // VP_VS_2_0
    "vs_2_0\n"
    "def c4, 1.00000000, 0, 0, 0\n"
    "dcl_position v0\n"
    "dcl_texcoord0 v1\n"
    "dcl_texcoord1 v2\n"
    "mov r0.w, c4.x\n"
    "mov r0.xyz, v0\n"
    "dp4 oPos.w, r0, c3\n"
    "dp4 oPos.z, r0, c2\n"
    "dp4 oPos.y, r0, c1\n"
    "dp4 oPos.x, r0, c0\n"
    "mov oT0.xy, v1\n"
    "mov oT1.xy, v2\n",

    // VP_VS_3_0
    "vs_3_0\n"
    "dcl_position o0\n"
    "dcl_texcoord0 o1\n"
    "dcl_texcoord1 o2\n"
    "def c4, 1.00000000, 0, 0, 0\n"
    "dcl_position0 v0\n"
    "dcl_texcoord0 v1\n"
    "dcl_texcoord1 v2\n"
    "mov r0.w, c4.x\n"
    "mov r0.xyz, v0\n"
    "dp4 o0.w, r0, c3\n"
    "dp4 o0.z, r0, c2\n"
    "dp4 o0.y, r0, c1\n"
    "dp4 o0.x, r0, c0\n"
    "mov o1.xy, v1\n"
    "mov o2.xy, v2\n",

    // VP_ARBVP1
    "!!ARBvp1.0\n"
    "PARAM c[5] = { { 1 }, program.local[1..4] };\n"
    "TEMP R0;\n"
    "MOV R0.w, c[0].x;\n"
    "MOV R0.xyz, vertex.position;\n"
    "DP4 result.position.w, R0, c[4];\n"
    "DP4 result.position.z, R0, c[3];\n"
    "DP4 result.position.y, R0, c[2];\n"
    "DP4 result.position.x, R0, c[1];\n"
    "MOV result.texcoord[0].xy, vertex.texcoord[0];\n"
    "MOV result.texcoord[1].xy, vertex.texcoord[1];\n"
    "END\n"
};

int Rendering::Texture2ColorBlendEffect::msAllPTextureUnits[2]   { 0, 1 };
int* Rendering::Texture2ColorBlendEffect::msPTextureUnits[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)]  
{
    0,
    msAllPTextureUnits,
    msAllPTextureUnits,
    msAllPTextureUnits,
    msAllPTextureUnits
};

std::string Rendering::Texture2ColorBlendEffect::msPPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)]  
{
    // PP_NONE
    "",

    // PP_PS_1_1
    "ps.1.1\n"
    "tex t0\n"
    "tex t1\n"
    "mov_sat r0, t0\n"
    "mad r0, 1-r0, t1, t0\n",

    // PP_PS_2_0
    "ps_2_0\n"
    "dcl_2d s0\n"
    "dcl_2d s1\n"
    "def c0, 1.00000000, 0, 0, 0\n"
    "dcl t0.xy\n"
    "dcl t1.xy\n"
    "texld r1, t0, s0\n"
    "texld r0, t1, s1\n"
    "add r2, -r1, c0.x\n"
    "mad r0, r2, r0, r1\n"
    "mov oC0, r0\n",

    // PP_PS_3_0
    "ps_3_0\n"
    "dcl_2d s0\n"
    "dcl_2d s1\n"
    "def c0, 1.00000000, 0, 0, 0\n"
    "dcl_texcoord0 v0.xy\n"
    "dcl_texcoord1 v1.xy\n"
    "texld r0, v0, s0\n"
    "texld r1, v1, s1\n"
    "add r2, -r0, c0.x\n"
    "mad oC0, r2, r1, r0\n",

    // PP_ARBFP1
    "!!ARBfp1.0\n"
    "PARAM c[1] = { { 1 } };\n"
    "TEMP R0;\n"
    "TEMP R1;\n"
    "TEMP R2;\n"
    "TEX R0, fragment.texcoord[0], texture[0], 2D;\n"
    "TEX R1, fragment.texcoord[1], texture[1], 2D;\n"
    "ADD R2, -R0, c[0].x;\n"
    "MAD result.color, R2, R1, R0;\n"
    "END\n"
};
#include STSTEM_WARNING_POP
