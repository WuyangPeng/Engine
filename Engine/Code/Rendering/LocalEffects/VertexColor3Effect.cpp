// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/25 14:59)

#include "Rendering/RenderingExport.h"

#include "VertexColor3Effect.h"
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
#include SYSTEM_WARNING_DISABLE(26815)
CORE_TOOLS_RTTI_DEFINE(Rendering, VertexColor3Effect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, VertexColor3Effect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, VertexColor3Effect);

Rendering::VertexColor3Effect::VertexColor3Effect ()
{
    VertexShaderSmartPointer vshader{ std::make_shared < VertexShader>("Wm5.VertexColor3", 2, 2, 1, 0) };
    vshader->SetInput(0, "modelPosition", ShaderFlags::VariableType::Float3,ShaderFlags::VariableSemantic::Position);
    vshader->SetInput(1, "modelColor", ShaderFlags::VariableType::Float3,ShaderFlags::VariableSemantic::Color0);
    vshader->SetOutput(0, "clipPosition", ShaderFlags::VariableType::Float4,ShaderFlags::VariableSemantic::Position);
    vshader->SetOutput(1, "vertexColor", ShaderFlags::VariableType::Float3,ShaderFlags::VariableSemantic::Color0);
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

	PixelShaderSmartPointer pshader{ std::make_shared<PixelShader>("Wm5.VertexColor3", 1, 1, 0, 0) };
    pshader->SetInput(0, "vertexColor", ShaderFlags::VariableType::Float3,ShaderFlags::VariableSemantic::Color0);
    pshader->SetOutput(0, "pixelColor", ShaderFlags::VariableType::Float4,ShaderFlags::VariableSemantic::Color0);
	profile = pshader->GetProfile();

	for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
	{
		profile->SetProgram(i, msPPrograms[i]);
	}

	VisualPassSmartPointer pass{   };
	pass->SetVertexShader(vshader);
	pass->SetPixelShader(pshader);
	pass->SetAlphaState(AlphaStateSmartPointer{   });
	pass->SetCullState(CullStateSmartPointer{   });
	pass->SetDepthState(DepthStateSmartPointer{   });
	pass->SetOffsetState(OffsetStateSmartPointer{   });
	pass->SetStencilState(StencilStateSmartPointer{   });
	pass->SetWireState(WireStateSmartPointer{   });

	VisualTechniqueSmartPointer technique{   };
	technique->InsertPass(pass);
	InsertTechnique(technique); 
}
 

Rendering::VisualEffectInstance* Rendering::VertexColor3Effect
	::CreateInstance () const
{
	VisualEffectInstance* instance = CoreTools::New0 < VisualEffectInstance>(VisualEffectSmartPointer((VisualEffect*)this), 0);
	instance->SetVertexConstant(0, 0, ShaderFloatSmartPointer(CoreTools::New0 < ProjectionViewMatrixConstant>()));
    return instance;
}

Rendering::VisualEffectInstance* Rendering::VertexColor3Effect
	::CreateUniqueInstance ()
{
    const VertexColor3Effect* effect = CoreTools::New0 < VertexColor3Effect>();
    return effect->CreateInstance();
}



// Streaming support.

Rendering::VertexColor3Effect
	::VertexColor3Effect (LoadConstructor value)
	:VisualEffect{ value }
{
}

void Rendering::VertexColor3Effect
	::Load(CoreTools::BufferSource& source)
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    VisualEffect::Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD( source);
}

void Rendering::VertexColor3Effect
	::Link(CoreTools::ObjectLink& source)
{
    VisualEffect::Link(source);
}

void Rendering::VertexColor3Effect
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
		profile->SetProgram(i, msPPrograms[i]);
	}
}

uint64_t Rendering::VertexColor3Effect ::Register(const CoreTools::ObjectRegisterSharedPtr& target) const
{
    return VisualEffect::Register(target);
}

void Rendering::VertexColor3Effect
	::Save(const CoreTools::BufferTargetSharedPtr& target) const
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    VisualEffect::Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE( target);
}

int Rendering::VertexColor3Effect
	::GetStreamingSize () const
{
    return VisualEffect::GetStreamingSize();
}



// Vertex and pixel programs.

int Rendering::VertexColor3Effect::msDx9VRegisters[1]  { 0 };
int Rendering::VertexColor3Effect::msOglVRegisters[1] { 1 };
int* Rendering::VertexColor3Effect::msVRegisters[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)] 
{
    0,
    msDx9VRegisters,
    msDx9VRegisters,
    msDx9VRegisters,
    msOglVRegisters
};

std::string Rendering::VertexColor3Effect::msVPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)] 
{
    // VP_NONE
    "",

    // VP_VS_1_1
    "vs_1_1\n"
    "def c4, 1.00000000, 0, 0, 0\n"
    "dcl_position0 v0\n"
    "dcl_color0 v1\n"
    "mov r0.w, c4.x\n"
    "mov r0.xyz, v0\n"
    "dp4 oPos.w, r0, c3\n"
    "dp4 oPos.z, r0, c2\n"
    "dp4 oPos.y, r0, c1\n"
    "dp4 oPos.x, r0, c0\n"
    "mov oD0.xyz, v1\n",

    // VP_VS_2_0
    "vs_2_0\n"
    "def c4, 1.00000000, 0, 0, 0\n"
    "dcl_position v0\n"
    "dcl_color v1\n"
    "mov r0.w, c4.x\n"
    "mov r0.xyz, v0\n"
    "dp4 oPos.w, r0, c3\n"
    "dp4 oPos.z, r0, c2\n"
    "dp4 oPos.y, r0, c1\n"
    "dp4 oPos.x, r0, c0\n"
    "mov oD0.xyz, v1\n",

    // VP_VS_3_0
    "vs_3_0\n"
    "dcl_position o0\n"
    "dcl_color0 o1\n"
    "def c4, 1.00000000, 0, 0, 0\n"
    "dcl_position0 v0\n"
    "dcl_color0 v1\n"
    "mov r0.w, c4.x\n"
    "mov r0.xyz, v0\n"
    "dp4 o0.w, r0, c3\n"
    "dp4 o0.z, r0, c2\n"
    "dp4 o0.y, r0, c1\n"
    "dp4 o0.x, r0, c0\n"
    "mov o1.xyz, v1\n",

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
    "MOV result.color.xyz, vertex.color;\n"
    "END\n"
};

std::string Rendering::VertexColor3Effect::msPPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)] 
{
    // PP_NONE
    "",

    // PP_PS_1_1
    "ps.1.1\n"
    "def c0, 0.000000, 0.000000, 1.000000, 0.000000\n"
    "mov r0.rgb, v0\n"
    "+ mov r0.a, c0.b\n",

    // PP_PS_2_0
    "ps_2_0\n"
    "def c0, 1.00000000, 0, 0, 0\n"
    "dcl v0.xyz\n"
    "mov r0.xyz, v0\n"
    "mov r0.w, c0.x\n"
    "mov oC0, r0\n",

    // PP_PS_3_0
    "ps_3_0\n"
    "def c0, 1.00000000, 0, 0, 0\n"
    "dcl_color0 v0.xyz\n"
    "mov oC0.xyz, v0\n"
    "mov oC0.w, c0.x\n",

    // PP_ARBFP1
    "!!ARBfp1.0\n"
    "PARAM c[1] = { { 1 } };\n"
    "MOV result.color.xyz, fragment.color.primary;\n"
    "MOV result.color.w, c[0].x;\n"
    "END\n"
};
#include STSTEM_WARNING_POP
