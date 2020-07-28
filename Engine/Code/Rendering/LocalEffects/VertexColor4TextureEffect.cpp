// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/25 15:05)

#include "Rendering/RenderingExport.h"

#include "VertexColor4TextureEffect.h"
#include "Rendering/ShaderFloats/ProjectionViewMatrixConstant.h" 
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
 
CORE_TOOLS_RTTI_DEFINE(Rendering, VertexColor4TextureEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, VertexColor4TextureEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, VertexColor4TextureEffect);

Rendering::VertexColor4TextureEffect
	::VertexColor4TextureEffect (ShaderFlags::SamplerFilter filter, ShaderFlags::SamplerCoordinate coordinate0,ShaderFlags::SamplerCoordinate coordinate1)
{
	VertexShaderSmartPointer vshader{ NEW0 VertexShader("Wm5.VertexColorTexture",3, 3, 1, 0) };
    vshader->SetInput(0, "modelPosition", ShaderFlags::VariableType::Float3,ShaderFlags::VariableSemantic::Position);
    vshader->SetInput(1, "modelTCoord", ShaderFlags::VariableType::Float2,ShaderFlags::VariableSemantic::TextureCoord0);
    vshader->SetInput(2, "modelColor", ShaderFlags::VariableType::Float4,ShaderFlags::VariableSemantic::Color0);
    vshader->SetOutput(0, "clipPosition", ShaderFlags::VariableType::Float4,ShaderFlags::VariableSemantic::Position);
    vshader->SetOutput(1, "vertexTCoord", ShaderFlags::VariableType::Float2,ShaderFlags::VariableSemantic::TextureCoord0);
    vshader->SetOutput(2, "vertexColor", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Color0);
    vshader->SetConstant(0, "PVWMatrix", 4);
	auto profile = vshader->GetProfile();

	for (auto i = 0; i < ShaderFlags::MaxProfiles; ++i)
	{
		for (auto j = 0; j < 1; ++j)
		{
			profile->SetBaseRegister(i, j, msVRegisters[i][j]);
		}

		profile->SetProgram(i, msVPrograms[i]);
	}

	PixelShaderSmartPointer pshader{ NEW0 PixelShader{"Wm5.VertexColorTexture",2, 1, 0, 1} };
    pshader->SetInput(0, "vertexColor", ShaderFlags::VariableType::Float4,ShaderFlags::VariableSemantic::Color0);
    pshader->SetInput(1, "vertexTCoord", ShaderFlags::VariableType::Float2,ShaderFlags::VariableSemantic::TextureCoord0);
    pshader->SetOutput(0, "pixelColor", ShaderFlags::VariableType::Float4,ShaderFlags::VariableSemantic::Color0);
    pshader->SetSampler(0, "BaseSampler", ShaderFlags::SamplerType::Sampler2D);
    pshader->SetFilter(0, filter);
    pshader->SetCoordinate(0, 0, coordinate0);
    pshader->SetCoordinate(0, 1, coordinate1);
	for (auto i = 0; i < ShaderFlags::MaxProfiles; ++i)
	{
		for (auto j = 0; j < 1; ++j)
		{
			profile->SetTextureUnit(i, j, msPTextureUnits[i][j]);
		}

		profile->SetProgram(i, msPPrograms[i]);
	}

	VisualPassSmartPointer pass{ NEW0 VisualPass{} };
	pass->SetVertexShader(vshader);
	pass->SetPixelShader(pshader);
	pass->SetAlphaState(AlphaStateSmartPointer{ NEW0 AlphaState{} });
	pass->SetCullState(CullStateSmartPointer{ NEW0 CullState{} });
	pass->SetDepthState(DepthStateSmartPointer{ NEW0 DepthState{} });
	pass->SetOffsetState(OffsetStateSmartPointer{ NEW0 OffsetState{} });
	pass->SetStencilState(StencilStateSmartPointer{ NEW0 StencilState{} });
	pass->SetWireState(WireStateSmartPointer{ NEW0 WireState{} });

	VisualTechniqueSmartPointer technique{ NEW0 VisualTechnique{} };
	technique->InsertPass(pass);
	InsertTechnique(technique); 
}

Rendering::VertexColor4TextureEffect
	::~VertexColor4TextureEffect ()
{
}

Rendering::PixelShader* Rendering::VertexColor4TextureEffect
	::GetPixelShader () const
{
	return const_cast<PixelShader*>(GetTechnique(0)->GetPass(0)->GetPixelShader().GetData());

}

Rendering::VisualEffectInstance* Rendering::VertexColor4TextureEffect
	::CreateInstance (Texture2D* texture) const
{
	VisualEffectInstance* instance = CoreTools::New0 < VisualEffectInstance>(VisualEffectSmartPointer((VisualEffect*)this), 0);
	instance->SetVertexConstant(0, 0, ShaderFloatSmartPointer(NEW0 ProjectionViewMatrixConstant()));
    instance->SetPixelTexture(0, 0, TextureSmartPointer(texture));

	ShaderFlags::SamplerFilter filter = GetPixelShader()->GetFilter(0);
	if (filter != ShaderFlags::SamplerFilter::Nearest && filter != ShaderFlags::SamplerFilter::Linear
    &&  !texture->HasMipmaps())
    {
        texture->GenerateMipmaps();
    }

    return instance;
}

Rendering::VisualEffectInstance* Rendering::VertexColor4TextureEffect
	::CreateUniqueInstance ( Texture2D* texture, ShaderFlags::SamplerFilter filter, ShaderFlags::SamplerCoordinate coordinate0, ShaderFlags::SamplerCoordinate coordinate1)
{
    VertexColor4TextureEffect* effect = CoreTools::New0 < VertexColor4TextureEffect>();
    PixelShader* pshader = effect->GetPixelShader();
    pshader->SetFilter(0, filter);
    pshader->SetCoordinate(0, 0, coordinate0);
    pshader->SetCoordinate(0, 1, coordinate1);
    return effect->CreateInstance(texture);
}



// Streaming support.

Rendering::VertexColor4TextureEffect
	::VertexColor4TextureEffect (LoadConstructor value)
	: VisualEffect{ value }
{
}

void Rendering::VertexColor4TextureEffect
	::Load(CoreTools::BufferSource& source)
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    VisualEffect::Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD( source);
}

void Rendering::VertexColor4TextureEffect
	::Link(CoreTools::ObjectLink& source)
{
    VisualEffect::Link(source);
}

void Rendering::VertexColor4TextureEffect
	::PostLink ()
{
	VisualEffect::PostLink();

	auto pass = GetTechnique(0)->GetPass(0);
	auto vshader = pass->GetVertexShader();
	auto pshader = pass->GetPixelShader();
	auto profile = const_cast<ShaderProfileData*>(vshader->GetProfile().GetData());

	for (auto i = 0; i < ShaderFlags::MaxProfiles; ++i)
	{
		for (auto j = 0; j < 1; ++j)
		{
			profile->SetBaseRegister(i, j, msVRegisters[i][j]);
		}

		profile->SetProgram(i, msVPrograms[i]);
	}

	profile = const_cast<ShaderProfileData*>(pshader->GetProfile().GetData());

	for (auto i = 0; i < ShaderFlags::MaxProfiles; ++i)
	{
		for (auto j = 0; j < 1; ++j)
		{
			profile->SetTextureUnit(i, j, msPTextureUnits[i][j]);
		}

		profile->SetProgram(i, msPPrograms[i]);
	}
}

uint64_t Rendering::VertexColor4TextureEffect
	::Register(CoreTools::ObjectRegister& target) const
{
    return VisualEffect::Register(target);
}

void Rendering::VertexColor4TextureEffect
	::Save(CoreTools::BufferTarget& target) const
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    VisualEffect::Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE( target);
}

int Rendering::VertexColor4TextureEffect
	::GetStreamingSize () const
{
    return VisualEffect::GetStreamingSize();
}



// Profiles.

int Rendering::VertexColor4TextureEffect::msDx9VRegisters[1]  { 0 };
int Rendering::VertexColor4TextureEffect::msOglVRegisters[1]  { 1 };
int* Rendering::VertexColor4TextureEffect::msVRegisters[ShaderFlags::MaxProfiles] 
{
    0,
    msDx9VRegisters,
    msDx9VRegisters,
    msDx9VRegisters,
    msOglVRegisters
};

std::string Rendering::VertexColor4TextureEffect::msVPrograms[ShaderFlags::MaxProfiles]
{
    // VP_NONE
    "",

    // VP_VS_1_1
    "vs_1_1\n"
    "def c4, 1.00000000, 0, 0, 0\n"
    "dcl_position0 v0\n"
    "dcl_texcoord0 v1\n"
    "dcl_color0 v2\n"
    "mov r0.w, c4.x\n"
    "mov r0.xyz, v0\n"
    "dp4 oPos.w, r0, c3\n"
    "dp4 oPos.z, r0, c2\n"
    "dp4 oPos.y, r0, c1\n"
    "dp4 oPos.x, r0, c0\n"
    "mov oD0, v2\n"
    "mov oT0.xy, v1\n",

    // VP_VS_2_0
    "vs_2_0\n"
    "def c4, 1.00000000, 0, 0, 0\n"
    "dcl_position0 v0\n"
    "dcl_texcoord0 v1\n"
    "dcl_color0 v2\n"
    "mov r0.w, c4.x\n"
    "mov r0.xyz, v0\n"
    "dp4 oPos.w, r0, c3\n"
    "dp4 oPos.z, r0, c2\n"
    "dp4 oPos.y, r0, c1\n"
    "dp4 oPos.x, r0, c0\n"
    "mov oD0, v2\n"
    "mov oT0.xy, v1\n",

    // VP_VS_3_0
    "vs_3_0\n"
    "dcl_position o0\n"
    "dcl_texcoord0 o1\n"
    "dcl_color0 o2\n"
    "def c4, 1.00000000, 0, 0, 0\n"
    "dcl_position0 v0\n"
    "dcl_texcoord0 v1\n"
    "dcl_color0 v2\n"
    "mov r0.w, c4.x\n"
    "mov r0.xyz, v0\n"
    "dp4 o0.w, r0, c3\n"
    "dp4 o0.z, r0, c2\n"
    "dp4 o0.y, r0, c1\n"
    "dp4 o0.x, r0, c0\n"
    "mov o2, v2\n"
    "mov o1.xy, v1\n",

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
    "MOV result.color, vertex.color;\n"
    "MOV result.texcoord[0].xy, vertex.texcoord[0];\n"
    "END\n"
};

int Rendering::VertexColor4TextureEffect::msAllPTextureUnits[1]  { 0 };
int* Rendering::VertexColor4TextureEffect::msPTextureUnits[ShaderFlags::MaxProfiles] 
{
    0,
    msAllPTextureUnits,
    msAllPTextureUnits,
    msAllPTextureUnits,
    msAllPTextureUnits
};

std::string Rendering::VertexColor4TextureEffect::msPPrograms[ShaderFlags::MaxProfiles] 
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
    "dcl_texcoord0 v0.xy\n"
    "dcl_color0 v1\n"
    "texld r0, v0, s0\n"
    "mul oC0.w, r0, v1\n"
    "add_sat oC0.xyz, r0, v1\n",

    // PP_ARBFP1
    "!!ARBfp1.0\n"
    "TEMP R0;\n"
    "TEX R0, fragment.texcoord[0], texture[0], 2D;\n"
    "MUL result.color.w, R0, fragment.color.primary;\n"
    "ADD_SAT result.color.xyz, R0, fragment.color.primary;\n"
    "END\n"
};

