// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/25 11:24)

#include "Rendering/RenderingExport.h"

#include "LightPntPerVerEffect.h"
#include "Rendering/ShaderFloats/MaterialEmissiveConstant.h"
#include "Rendering/ShaderFloats/MaterialAmbientConstant.h"
#include "Rendering/ShaderFloats/MaterialDiffuseConstant.h"
#include "Rendering/ShaderFloats/MaterialSpecularConstant.h"
#include "Rendering/ShaderFloats/LightAmbientConstant.h"
#include "Rendering/ShaderFloats/LightDiffuseConstant.h"
#include "Rendering/ShaderFloats/LightSpecularConstant.h"
#include "Rendering/ShaderFloats/LightAttenuationConstant.h"
#include "Rendering/ShaderFloats/LightModelPositionConstant.h"
#include "Rendering/ShaderFloats/WorldMatrixConstant.h" 
#include "Rendering/ShaderFloats/CameraModelPositionConstant.h"
#include "Rendering/ShaderFloats/ProjectionViewMatrixConstant.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, LightPntPerVerEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, LightPntPerVerEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, LightPntPerVerEffect);

Rendering::LightPntPerVerEffect
	::LightPntPerVerEffect ()
{
	VertexShaderSmartPointer vshader{ NEW0 VertexShader{"Wm5.LightPntPerVer",2, 2, 12, 0} };
    vshader->SetInput(0, "modelPosition", ShaderFlags::VariableType::Float3,ShaderFlags::VariableSemantic::Position);
    vshader->SetInput(1, "modelNormal", ShaderFlags::VariableType::Float3,ShaderFlags::VariableSemantic::TextureCoord1);
    vshader->SetOutput(0, "clipPosition", ShaderFlags::VariableType::Float4,ShaderFlags::VariableSemantic::Position);
    vshader->SetOutput(1, "vertexColor", ShaderFlags::VariableType::Float4,ShaderFlags::VariableSemantic::Color0);
    vshader->SetConstant(0, "PVWMatrix", 4);
    vshader->SetConstant(1, "WMatrix", 4);
    vshader->SetConstant(2, "CameraModelPosition", 1);
    vshader->SetConstant(3, "MaterialEmissive", 1);
    vshader->SetConstant(4, "MaterialAmbient", 1);
    vshader->SetConstant(5, "MaterialDiffuse", 1);
    vshader->SetConstant(6, "MaterialSpecular", 1);
    vshader->SetConstant(7, "LightModelPosition", 1);
    vshader->SetConstant(8, "LightAmbient", 1);
    vshader->SetConstant(9, "LightDiffuse", 1);
    vshader->SetConstant(10, "LightSpecular", 1);
    vshader->SetConstant(11, "LightAttenuation", 1);
	auto profile = vshader->GetProfile();

	for (auto i = 0; i < ShaderFlags::MaxProfiles; ++i)
	{
		for (auto j = 0; j < 12; ++j)
		{
			profile->SetBaseRegister(i, j, msVRegisters[i][j]);
		}

		profile->SetProgram(i, msVPrograms[i]);
	}

	PixelShaderSmartPointer pshader{ NEW0 PixelShader{ "Wm5.LightPntPerVer",1, 1, 0, 0 } };
    pshader->SetInput(0, "vertexColor", ShaderFlags::VariableType::Float4,ShaderFlags::VariableSemantic::Color0);
    pshader->SetOutput(0, "pixelColor", ShaderFlags::VariableType::Float4,ShaderFlags::VariableSemantic::Color0);
	for (auto i = 0; i < ShaderFlags::MaxProfiles; ++i)
	{
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

Rendering::LightPntPerVerEffect
	::~LightPntPerVerEffect ()
{
}

Rendering::VisualEffectInstance* Rendering::LightPntPerVerEffect
	::CreateInstance (Light* light, Material* material) const
{
	VisualEffectInstance* instance = CoreTools::New0 < VisualEffectInstance>(VisualEffectSmartPointer((VisualEffect*)this), 0);
    instance->SetVertexConstant(0, 0, ShaderFloatSmartPointer(NEW0 ProjectionViewMatrixConstant()));
    instance->SetVertexConstant(0, 1, ShaderFloatSmartPointer(NEW0 WorldMatrixConstant()));
    instance->SetVertexConstant(0, 2, ShaderFloatSmartPointer(NEW0 CameraModelPositionConstant()));
    instance->SetVertexConstant(0, 3, ShaderFloatSmartPointer(NEW0 MaterialEmissiveConstant(MaterialSmartPointer(material))));
    instance->SetVertexConstant(0, 4, ShaderFloatSmartPointer(NEW0 MaterialAmbientConstant(MaterialSmartPointer(material))));
    instance->SetVertexConstant(0, 5, ShaderFloatSmartPointer(NEW0 MaterialDiffuseConstant(MaterialSmartPointer(material))));
    instance->SetVertexConstant(0, 6, ShaderFloatSmartPointer(NEW0 MaterialSpecularConstant(MaterialSmartPointer(material))));
    instance->SetVertexConstant(0, 7, ShaderFloatSmartPointer(NEW0 LightModelPositionConstant(LightSmartPointer(light))));
    instance->SetVertexConstant(0, 8, ShaderFloatSmartPointer(NEW0 LightAmbientConstant(LightSmartPointer(light))));
    instance->SetVertexConstant(0, 9, ShaderFloatSmartPointer(NEW0 LightDiffuseConstant(LightSmartPointer(light))));
    instance->SetVertexConstant(0, 10, ShaderFloatSmartPointer(NEW0 LightSpecularConstant(LightSmartPointer(light))));
    instance->SetVertexConstant(0, 11, ShaderFloatSmartPointer(NEW0 LightAttenuationConstant(LightSmartPointer(light))));

    return instance;
}

Rendering::VisualEffectInstance* Rendering::LightPntPerVerEffect::CreateUniqueInstance (
    Light* light, Material* material)
{
    LightPntPerVerEffect* effect = CoreTools::New0 < LightPntPerVerEffect>();
    return effect->CreateInstance(light, material);
}

// Streaming support.

Rendering::LightPntPerVerEffect
	::LightPntPerVerEffect (LoadConstructor value)
	:VisualEffect{ value }
{
}

void Rendering::LightPntPerVerEffect
	::Load(CoreTools::BufferSource& source)
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    VisualEffect::Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::LightPntPerVerEffect
	::Link(CoreTools::ObjectLink& source)
{
    VisualEffect::Link(source);
}

void Rendering::LightPntPerVerEffect
	::PostLink ()
{
	VisualEffect::PostLink();

	auto pass = GetTechnique(0)->GetPass(0);
	auto vshader = pass->GetVertexShader();
	auto pshader = pass->GetPixelShader();
	auto profile = const_cast<ShaderProfileData*>(vshader->GetProfile().GetData());

	for (auto i = 0; i < ShaderFlags::MaxProfiles; ++i)
	{
		for (auto j = 0; j < 12; ++j)
		{
			profile->SetBaseRegister(i, j, msVRegisters[i][j]);
		}

		profile->SetProgram(i, msVPrograms[i]);
	}

	profile = const_cast<ShaderProfileData*>(pshader->GetProfile().GetData());

	for (auto i = 0; i < ShaderFlags::MaxProfiles; ++i)
	{
		profile->SetProgram(i, msPPrograms[i]);
	}
}

uint64_t Rendering::LightPntPerVerEffect
	::Register(CoreTools::ObjectRegister& target) const
{
    return VisualEffect::Register(target);
}

void Rendering::LightPntPerVerEffect
	::Save(CoreTools::BufferTarget& target) const
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    VisualEffect::Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::LightPntPerVerEffect
	::GetStreamingSize () const
{
    return VisualEffect::GetStreamingSize();
}



// Profiles.

int Rendering::LightPntPerVerEffect::msDx9VRegisters[12] 
    { 0, 4, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 };

int Rendering::LightPntPerVerEffect::msOglVRegisters[12] 
    { 1, 5, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 };

int* Rendering::LightPntPerVerEffect::msVRegisters[ShaderFlags::MaxProfiles] 
{
    0,
    msDx9VRegisters,
    msDx9VRegisters,
    msDx9VRegisters,
    msOglVRegisters
};

std::string Rendering::LightPntPerVerEffect::msVPrograms[ShaderFlags::MaxProfiles] 
{
    // VP_NONE
    "",

    // VP_VS_1_1
    "vs_1_1\n"
    "def c18, 1.00000000, 0, 0, 0\n"
    "dcl_position0 v0\n"
    "dcl_texcoord1 v1\n"
    "add r1.xyz, v0, -c13\n"
    "dp3 r0.x, r1, r1\n"
    "add r2.xyz, -v0, c8\n"
    "dp3 r0.w, r2, r2\n"
    "rsq r0.x, r0.x\n"
    "mul r0.xyz, r0.x, r1\n"
    "rsq r0.w, r0.w\n"
    "mad r2.xyz, r0.w, r2, -r0\n"
    "dp3 r0.x, v1, r0\n"
    "dp3 r0.w, r2, r2\n"
    "rsq r0.w, r0.w\n"
    "mul r2.xyz, r0.w, r2\n"
    "dp3 r0.w, v1, r2\n"
    "dp3 r2.z, r1, c6\n"
    "dp3 r2.x, r1, c4\n"
    "dp3 r2.y, r1, c5\n"
    "dp3 r1.x, r2, r2\n"
    "mov r0.x, -r0\n"
    "mov r0.y, c12.w\n"
    "lit r0.yz, r0.xwzy\n"
    "rsq r0.x, r1.x\n"
    "rcp r0.w, r0.x\n"
    "mul r1.xyz, r0.z, c12\n"
    "mul r0.xyz, r0.y, c11\n"
    "mul r2.xyz, r0, c15\n"
    "mad r1.w, r0, c17.z, c17.y\n"
    "mad r0.w, r0, r1, c17.x\n"
    "mov r0.xyz, c10\n"
    "mad r0.xyz, c14, r0, r2\n"
    "mad r1.xyz, r1, c16, r0\n"
    "rcp r0.w, r0.w\n"
    "mul r0.x, r0.w, c17.w\n"
    "mad oD0.xyz, r0.x, r1, c9\n"
    "mov r0.w, c18.x\n"
    "mov r0.xyz, v0\n"
    "dp4 oPos.w, r0, c3\n"
    "dp4 oPos.z, r0, c2\n"
    "dp4 oPos.y, r0, c1\n"
    "dp4 oPos.x, r0, c0\n"
    "mov oD0.w, c11\n",

    // VP_VS_2_0
    "vs_2_0\n"
    "def c18, 1.00000000, 0, 0, 0\n"
    "dcl_position v0\n"
    "dcl_texcoord1 v1\n"
    "add r1.xyz, v0, -c13\n"
    "dp3 r0.x, r1, r1\n"
    "add r2.xyz, -v0, c8\n"
    "dp3 r0.w, r2, r2\n"
    "rsq r0.x, r0.x\n"
    "mul r0.xyz, r0.x, r1\n"
    "rsq r0.w, r0.w\n"
    "mad r2.xyz, r0.w, r2, -r0\n"
    "dp3 r0.x, v1, r0\n"
    "dp3 r0.w, r2, r2\n"
    "rsq r0.w, r0.w\n"
    "mul r2.xyz, r0.w, r2\n"
    "dp3 r0.w, v1, r2\n"
    "dp3 r2.z, r1, c6\n"
    "dp3 r2.x, r1, c4\n"
    "dp3 r2.y, r1, c5\n"
    "dp3 r1.x, r2, r2\n"
    "mov r0.x, -r0\n"
    "mov r0.y, c12.w\n"
    "lit r0.yz, r0.xwzy\n"
    "rsq r0.x, r1.x\n"
    "rcp r0.w, r0.x\n"
    "mul r1.xyz, r0.z, c12\n"
    "mul r0.xyz, r0.y, c11\n"
    "mul r2.xyz, r0, c15\n"
    "mad r1.w, r0, c17.z, c17.y\n"
    "mad r0.w, r0, r1, c17.x\n"
    "mov r0.xyz, c10\n"
    "mad r0.xyz, c14, r0, r2\n"
    "mad r1.xyz, r1, c16, r0\n"
    "rcp r0.w, r0.w\n"
    "mul r0.x, r0.w, c17.w\n"
    "mad oD0.xyz, r0.x, r1, c9\n"
    "mov r0.w, c18.x\n"
    "mov r0.xyz, v0\n"
    "dp4 oPos.w, r0, c3\n"
    "dp4 oPos.z, r0, c2\n"
    "dp4 oPos.y, r0, c1\n"
    "dp4 oPos.x, r0, c0\n"
    "mov oD0.w, c11\n",

    // VP_VS_3_0
    "vs_3_0\n"
    "dcl_position o0\n"
    "dcl_color0 o1\n"
    "def c18, 1.00000000, 0, 0, 0\n"
    "dcl_position0 v0\n"
    "dcl_texcoord1 v1\n"
    "add r1.xyz, v0, -c13\n"
    "dp3 r0.x, r1, r1\n"
    "add r2.xyz, -v0, c8\n"
    "dp3 r0.w, r2, r2\n"
    "rsq r0.x, r0.x\n"
    "mul r0.xyz, r0.x, r1\n"
    "rsq r0.w, r0.w\n"
    "mad r2.xyz, r0.w, r2, -r0\n"
    "dp3 r0.x, v1, r0\n"
    "dp3 r0.w, r2, r2\n"
    "rsq r0.w, r0.w\n"
    "mul r2.xyz, r0.w, r2\n"
    "dp3 r0.w, v1, r2\n"
    "dp3 r2.z, r1, c6\n"
    "dp3 r2.x, r1, c4\n"
    "dp3 r2.y, r1, c5\n"
    "dp3 r1.x, r2, r2\n"
    "mov r0.x, -r0\n"
    "mov r0.y, c12.w\n"
    "lit r0.yz, r0.xwzy\n"
    "rsq r0.x, r1.x\n"
    "rcp r0.w, r0.x\n"
    "mul r1.xyz, r0.z, c12\n"
    "mul r0.xyz, r0.y, c11\n"
    "mul r2.xyz, r0, c15\n"
    "mad r1.w, r0, c17.z, c17.y\n"
    "mad r0.w, r0, r1, c17.x\n"
    "mov r0.xyz, c10\n"
    "mad r0.xyz, c14, r0, r2\n"
    "mad r1.xyz, r1, c16, r0\n"
    "rcp r0.w, r0.w\n"
    "mul r0.x, r0.w, c17.w\n"
    "mad o1.xyz, r0.x, r1, c9\n"
    "mov r0.w, c18.x\n"
    "mov r0.xyz, v0\n"
    "dp4 o0.w, r0, c3\n"
    "dp4 o0.z, r0, c2\n"
    "dp4 o0.y, r0, c1\n"
    "dp4 o0.x, r0, c0\n"
    "mov o1.w, c11\n",

    // VP_ARBVP1
    "!!ARBvp1.0\n"
    "PARAM c[19] = { { 1 }, program.local[1..18] };\n"
    "TEMP R0;\n"
    "TEMP R1;\n"
    "TEMP R2;\n"
    "ADD R1.xyz, vertex.position, -c[14];\n"
    "DP3 R0.x, R1, R1;\n"
    "ADD R2.xyz, -vertex.position, c[9];\n"
    "DP3 R0.w, R2, R2;\n"
    "RSQ R0.x, R0.x;\n"
    "MUL R0.xyz, R0.x, R1;\n"
    "RSQ R0.w, R0.w;\n"
    "MAD R2.xyz, R0.w, R2, -R0;\n"
    "DP3 R0.x, vertex.texcoord[1], R0;\n"
    "DP3 R0.w, R2, R2;\n"
    "RSQ R0.w, R0.w;\n"
    "MUL R2.xyz, R0.w, R2;\n"
    "DP3 R0.w, vertex.texcoord[1], R2;\n"
    "DP3 R2.z, R1, c[7];\n"
    "DP3 R2.x, R1, c[5];\n"
    "DP3 R2.y, R1, c[6];\n"
    "DP3 R1.x, R2, R2;\n"
    "MOV R0.x, -R0;\n"
    "MOV R0.y, c[13].w;\n"
    "LIT R0.yz, R0.xwzy;\n"
    "RSQ R0.x, R1.x;\n"
    "RCP R0.w, R0.x;\n"
    "MUL R1.xyz, R0.z, c[13];\n"
    "MUL R0.xyz, R0.y, c[12];\n"
    "MUL R2.xyz, R0, c[16];\n"
    "MAD R1.w, R0, c[18].z, c[18].y;\n"
    "MAD R0.w, R0, R1, c[18].x;\n"
    "MOV R0.xyz, c[15];\n"
    "MAD R0.xyz, R0, c[11], R2;\n"
    "MAD R1.xyz, R1, c[17], R0;\n"
    "RCP R0.w, R0.w;\n"
    "MUL R0.x, R0.w, c[18].w;\n"
    "MAD result.color.xyz, R0.x, R1, c[10];\n"
    "MOV R0.w, c[0].x;\n"
    "MOV R0.xyz, vertex.position;\n"
    "DP4 result.position.w, R0, c[4];\n"
    "DP4 result.position.z, R0, c[3];\n"
    "DP4 result.position.y, R0, c[2];\n"
    "DP4 result.position.x, R0, c[1];\n"
    "MOV result.color.w, c[12];\n"
    "END\n"
};

std::string Rendering::LightPntPerVerEffect
	::msPPrograms[ShaderFlags::MaxProfiles] 
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

    // PP_PS_ARB
    "!!ARBfp1.0\n"
    "MOV result.color, fragment.color.primary;\n"
    "END\n"
};

