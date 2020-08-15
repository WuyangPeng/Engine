// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-2018
//
// “˝«Ê∞Ê±æ£∫1.0.0.0 (2018/01/04 14:04)

#include "Rendering/RenderingExport.h"

#include "MaterialTextureEffect.h"
#include "Rendering/ShaderFloats/MaterialDiffuseConstant.h"
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
#include SYSTEM_WARNING_DISABLE(26434)
#include SYSTEM_WARNING_DISABLE(26815)
#include SYSTEM_WARNING_DISABLE(26487)
CORE_TOOLS_RTTI_DEFINE(Rendering, MaterialTextureEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, MaterialTextureEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, MaterialTextureEffect);

Rendering::MaterialTextureEffect
	::MaterialTextureEffect(ShaderFlags::SamplerFilter filter, ShaderFlags::SamplerCoordinate coordinate0, ShaderFlags::SamplerCoordinate coordinate1)
{ 
	VertexShaderSmartPointer vshader{ std::make_shared< VertexShader>( "Wm5.MaterialTexture",  2, 3, 2, 0 ) };
    vshader->SetInput(0, "modelPosition", ShaderFlags::VariableType::Float3, ShaderFlags::VariableSemantic::Position);
    vshader->SetInput(1, "modelTCoord", ShaderFlags::VariableType::Float2, ShaderFlags::VariableSemantic::TextureCoord0);
    vshader->SetOutput(0, "clipPosition", ShaderFlags::VariableType::Float4,  ShaderFlags::VariableSemantic::Position);
    vshader->SetOutput(1, "vertexColor", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Color0);
    vshader->SetOutput(2, "vertexTCoord", ShaderFlags::VariableType::Float2, ShaderFlags::VariableSemantic::TextureCoord0);
    vshader->SetConstant(0, "PVWMatrix", 4);
    vshader->SetConstant(1, "MaterialDiffuse", 1);

	auto profile = vshader->GetProfile();

	for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
	{
		for (auto j = 0; j < 2; ++j)
		{
			profile->SetBaseRegister(i, j, msVRegisters[i][j]);
		}

		profile->SetProgram(i, msVPrograms[i]);
	}
 

	PixelShaderSmartPointer pshader{ std::make_shared<PixelShader>("Wm5.MaterialTexture",  2, 1, 0, 1) };
    pshader->SetInput(0, "vertexColor", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Color0);
    pshader->SetInput(1, "vertexTCoord", ShaderFlags::VariableType::Float2, ShaderFlags::VariableSemantic::TextureCoord0);
    pshader->SetOutput(0, "pixelColor", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Color0);
    pshader->SetSampler(0, "BaseSampler", ShaderFlags::SamplerType::Sampler2D);
    pshader->SetFilter(0, filter);
    pshader->SetCoordinate(0, 0, coordinate0);
    pshader->SetCoordinate(0, 1, coordinate1);

	profile = pshader->GetProfile();

	for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
	{
		for (auto j = 0; j < 1; ++j)
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
	pass->SetDepthState(DepthStateSmartPointer{    });
	pass->SetOffsetState(OffsetStateSmartPointer{   });
	pass->SetStencilState(StencilStateSmartPointer{   });
	pass->SetWireState(WireStateSmartPointer{   });

	VisualTechniqueSmartPointer technique{   };
	technique->InsertPass(pass);
	InsertTechnique(technique); 
}
 

Rendering::PixelShader* Rendering::MaterialTextureEffect
	::GetPixelShader () const
{
	return const_cast<PixelShader*>(GetTechnique(0)->GetPass(0)->GetPixelShader().get());
}

Rendering::VisualEffectInstance* Rendering::MaterialTextureEffect
	::CreateInstance ( Material* material, Texture2D* texture) const
{
	VisualEffectInstance* instance = CoreTools::New0 < VisualEffectInstance>(VisualEffectSmartPointer((VisualEffect*)this), 0);
	instance->SetVertexConstant(0, 0, ShaderFloatSmartPointer(std::make_shared< ProjectionViewMatrixConstant>()));
        instance->SetVertexConstant(0, 1, ShaderFloatSmartPointer(std::make_shared < MaterialDiffuseConstant>(MaterialSmartPointer(material))));
	instance->SetPixelTexture(0, 0, TextureSmartPointer(texture));

	const ShaderFlags::SamplerFilter filter = GetPixelShader()->GetFilter(0);
	if (filter != ShaderFlags::SamplerFilter::Nearest && filter != ShaderFlags::SamplerFilter::NearesLinear &&  !texture->HasMipmaps())
    {
        texture->GenerateMipmaps();
    }

    return instance;
}

Rendering::VisualEffectInstance* Rendering::MaterialTextureEffect
	::CreateUniqueInstance (Material* material, Texture2D* texture, ShaderFlags::SamplerFilter filter,ShaderFlags::SamplerCoordinate coordinate0,ShaderFlags::SamplerCoordinate coordinate1)
{
    const MaterialTextureEffect* effect = CoreTools::New0 < MaterialTextureEffect>();
    PixelShader* pshader = effect->GetPixelShader();
    pshader->SetFilter(0, filter);
    pshader->SetCoordinate(0, 0, coordinate0);
    pshader->SetCoordinate(0, 1, coordinate1);
    return effect->CreateInstance(material, texture);
}



// Streaming support.

Rendering::MaterialTextureEffect
	::MaterialTextureEffect (LoadConstructor value)
	: VisualEffect{ value }
{
}

void Rendering::MaterialTextureEffect
	::Load(CoreTools::BufferSource& source)
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    VisualEffect::Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD( source);
}

void Rendering::MaterialTextureEffect
	::Link(CoreTools::ObjectLink& source)
{
    VisualEffect::Link(source);
}

void Rendering::MaterialTextureEffect
	::PostLink ()
{
	VisualEffect::PostLink();

	auto pass = GetTechnique(0)->GetPass(0);
	auto vshader = pass->GetVertexShader();
	auto pshader = pass->GetPixelShader();
	auto profile = const_cast<ShaderProfileData*>(vshader->GetProfile().get());

	for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
	{
		for (auto j = 0; j < 2; ++j)
		{
			profile->SetBaseRegister(i, j, msVRegisters[i][j]);
		}

		profile->SetProgram(i, msVPrograms[i]);
	}

	profile = const_cast<ShaderProfileData*>(pshader->GetProfile().get());

	for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
	{
		for (auto j = 0; j < 1; ++j)
		{
			profile->SetTextureUnit(i, j, msPTextureUnits[i][j]);
		}

		profile->SetProgram(i, msPPrograms[i]);
	}
}

uint64_t Rendering::MaterialTextureEffect
	::Register(CoreTools::ObjectRegister& target) const
{
    return VisualEffect::Register(target);
}

void Rendering::MaterialTextureEffect
	::Save(CoreTools::BufferTarget& target) const
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    VisualEffect::Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE( target);
}

int Rendering::MaterialTextureEffect
	::GetStreamingSize () const
{
    return VisualEffect::GetStreamingSize();
}



// Profiles.

int Rendering::MaterialTextureEffect::msDx9VRegisters[2]  { 0, 4 };
int Rendering::MaterialTextureEffect::msOglVRegisters[2] { 1, 5 };
int* Rendering::MaterialTextureEffect::msVRegisters[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)] 
{
    0,
    msDx9VRegisters,
    msDx9VRegisters,
    msDx9VRegisters,
    msOglVRegisters
};

std::string Rendering::MaterialTextureEffect::msVPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)] 
{
    // VP_NONE
    "",

    // VP_VS_1_1
    "vs_1_1\n"
    "def c5, 1.00000000, 0, 0, 0\n"
    "dcl_position0 v0\n"
    "dcl_texcoord0 v1\n"
    "mov r0.w, c5.x\n"
    "mov r0.xyz, v0\n"
    "dp4 oPos.w, r0, c3\n"
    "dp4 oPos.z, r0, c2\n"
    "dp4 oPos.y, r0, c1\n"
    "dp4 oPos.x, r0, c0\n"
    "mov oD0, c4\n"
    "mov oT0.xy, v1\n",

    // VP_VS_2_0
    "vs_2_0\n"
    "def c5, 1.00000000, 0, 0, 0\n"
    "dcl_position v0\n"
    "dcl_texcoord0 v1\n"
    "mov r0.w, c5.x\n"
    "mov r0.xyz, v0\n"
    "dp4 oPos.w, r0, c3\n"
    "dp4 oPos.z, r0, c2\n"
    "dp4 oPos.y, r0, c1\n"
    "dp4 oPos.x, r0, c0\n"
    "mov oD0, c4\n"
    "mov oT0.xy, v1\n",

    // VP_VS_3_0
    "vs_3_0\n"
    "dcl_position o0\n"
    "dcl_color0 o1\n"
    "dcl_texcoord0 o2\n"
    "def c5, 1.00000000, 0, 0, 0\n"
    "dcl_position0 v0\n"
    "dcl_texcoord0 v1\n"
    "mov r0.w, c5.x\n"
    "mov r0.xyz, v0\n"
    "dp4 o0.w, r0, c3\n"
    "dp4 o0.z, r0, c2\n"
    "dp4 o0.y, r0, c1\n"
    "dp4 o0.x, r0, c0\n"
    "mov o1, c4\n"
    "mov o2.xy, v1\n",

    // VP_ARBVP1
    "!!ARBvp1.0\n"
    "PARAM c[6] = { { 1 }, program.local[1..5] };\n"
    "TEMP R0;\n"
    "MOV R0.w, c[0].x;\n"
    "MOV R0.xyz, vertex.position;\n"
    "DP4 result.position.w, R0, c[4];\n"
    "DP4 result.position.z, R0, c[3];\n"
    "DP4 result.position.y, R0, c[2];\n"
    "DP4 result.position.x, R0, c[1];\n"
    "MOV result.color, c[5];\n"
    "MOV result.texcoord[0].xy, vertex.texcoord[0];\n"
    "END\n"
};

int Rendering::MaterialTextureEffect::msAllPTextureUnits[1]  { 0 };
int* Rendering::MaterialTextureEffect::msPTextureUnits[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)] 
{
    0,
    msAllPTextureUnits,
    msAllPTextureUnits,
    msAllPTextureUnits,
    msAllPTextureUnits
};

std::string Rendering::MaterialTextureEffect::msPPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)] 
{
    // PP_NONE
    "",

    // PP_PS_1_1
    "ps.1.1\n"
    "tex t0\n"
    "add_sat r0.rgb, t0, v0\n"
    "+ mul r0.a, t0.a, v0.a\n",

    // PP_PS_2_0
    "ps_2_0\n"
    "dcl_2d s0\n"
    "dcl t0.xy\n"
    "dcl v0\n"
    "texld r0, t0, s0\n"
    "add_sat r0.xyz, r0, v0\n"
    "mul r0.w, r0, v0\n"
    "mov oC0, r0\n",

    // PP_PS_3_0
    "ps_3_0\n"
    "dcl_2d s0\n"
    "dcl_texcoord0 v1.xy\n"
    "dcl_color0 v0\n"
    "texld r0, v1, s0\n"
    "mul oC0.w, r0, v0\n"
    "add_sat oC0.xyz, r0, v0\n",

    // PP_ARBFP1
    "!!ARBfp1.0\n"
    "TEMP R0;\n"
    "TEX R0, fragment.texcoord[0], texture[0], 2D;\n"
    "MUL result.color.w, R0, fragment.color.primary;\n"
    "ADD_SAT result.color.xyz, R0, fragment.color.primary;\n"
    "END\n"
};
#include STSTEM_WARNING_POP
