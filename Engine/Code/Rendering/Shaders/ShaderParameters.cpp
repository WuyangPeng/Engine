// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 17:06)

#include "Rendering/RenderingExport.h"

#include "ShaderParameters.h"
#include "Detail/ShaderParametersImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/MemoryTools/FirstSubclassSmartPointerDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;
using std::make_shared;

CORE_TOOLS_RTTI_DEFINE(Rendering, ShaderParameters);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ShaderParameters);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ShaderParameters); 

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, ShaderParameters);

CORE_TOOLS_IMPL_OBJECT_PTR_DEFAULT_STREAM(Rendering, ShaderParameters);

Rendering::ShaderParameters
	::ShaderParameters(const ConstShaderBaseSmartPointer& shader)
	:ParentType{ "ShaderParameters" }, m_Impl{ make_shared<ImplType>(shader) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ShaderParameters
	::~ShaderParameters()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, ShaderParameters)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderParameters,GetNumConstants,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderParameters, GetNumTextures, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderParameters, GetConstants,const Rendering::ShaderParameters::ConstShaderFloatSmartPointerGather)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderParameters,GetTextures,const Rendering::ShaderParameters::ConstTextureSmartPointerGather)

int Rendering::ShaderParameters
	::SetConstant(const string& name, const ShaderFloatSmartPointer& shaderFloat)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
       
	return m_Impl->SetConstant(name, shaderFloat);
}

void Rendering::ShaderParameters
	::SetConstant(int handle, const ShaderFloatSmartPointer& shaderFloat)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
       
	return m_Impl->SetConstant(handle, shaderFloat);
}

int Rendering::ShaderParameters
	::SetTexture(const string& name, const TextureSmartPointer& texture)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
       
	return m_Impl->SetTexture(name, texture);
}

void Rendering::ShaderParameters
	::SetTexture(int handle, const TextureSmartPointer& texture)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
       
	return m_Impl->SetTexture(handle, texture);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, ShaderParameters,GetConstant,string,const Rendering::ConstShaderFloatSmartPointer)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, ShaderParameters,GetTexture,string, const Rendering::ConstTextureSmartPointer)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderParameters,GetConstant,int,const Rendering::ConstShaderFloatSmartPointer)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderParameters, GetTexture,int, const Rendering::ConstTextureSmartPointer)



void Rendering::ShaderParameters
	::UpdateConstants(const Visual* visual, const Camera* camera)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
       
	return m_Impl->UpdateConstants(visual, camera);
}

 