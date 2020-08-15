// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 17:28)

#include "Rendering/RenderingExport.h"

#include "VisualEffectInstance.h"
#include "Detail/VisualEffectInstanceImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
CORE_TOOLS_RTTI_DEFINE(Rendering, VisualEffectInstance);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, VisualEffectInstance);
CORE_TOOLS_FACTORY_DEFINE(Rendering, VisualEffectInstance);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, VisualEffectInstance);

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, VisualEffectInstance);

CORE_TOOLS_IMPL_OBJECT_PTR_DEFAULT_STREAM(Rendering, VisualEffectInstance);

Rendering::VisualEffectInstance
	::VisualEffectInstance(const VisualEffectSmartPointer& effect, int techniqueIndex)
	:ParentType{ "VisualEffectInstance" }, m_Impl{ make_shared<ImplType>(effect, techniqueIndex) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VisualEffectInstance
	::~VisualEffectInstance()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
} 

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, VisualEffectInstance)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisualEffectInstance,GetEffect, const Rendering::ConstVisualEffectSmartPointer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisualEffectInstance, GetTechniqueIndex, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisualEffectInstance, GetNumPasses, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualEffectInstance, GetConstPass, int, const Rendering::ConstVisualPassSmartPointer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualEffectInstance, GetConstPixelParameters, int, const Rendering::ConstShaderParametersSmartPointer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualEffectInstance,GetConstVertexParameters, int, const Rendering::ConstShaderParametersSmartPointer)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualEffectInstance, GetPixelParameters, int, const Rendering::ShaderParametersSmartPointer)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualEffectInstance, GetVertexParameters, int, const Rendering::ShaderParametersSmartPointer)
 

void Rendering::VisualEffectInstance
	::SetVertexTexture(int pass, int handle, const TextureSmartPointer& texture)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetVertexTexture(pass, handle, texture);
}

void Rendering::VisualEffectInstance
	::SetPixelTexture(int pass, int handle, const TextureSmartPointer& texture)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetPixelTexture(pass, handle, texture);
}

const Rendering::ConstShaderFloatSmartPointer Rendering::VisualEffectInstance
	::GetVertexConstant(int pass, const std::string& name) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetVertexConstant(pass,name);
}

const Rendering::ConstShaderFloatSmartPointer Rendering::VisualEffectInstance
	::GetVertexConstant(int pass, int handle) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetVertexConstant(pass, handle);
}

const Rendering::ConstShaderFloatSmartPointer Rendering::VisualEffectInstance
	::GetPixelConstant(int pass, const std::string& name) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetPixelConstant(pass, name);
}

const Rendering::ConstShaderFloatSmartPointer Rendering::VisualEffectInstance
	::GetPixelConstant(int pass, int handle) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetPixelConstant(pass, handle);
}

const Rendering::ConstTextureSmartPointer Rendering::VisualEffectInstance
	::GetVertexTexture(int pass, const std::string& name) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetVertexTexture(pass, name);
}

const Rendering::ConstTextureSmartPointer Rendering::VisualEffectInstance
	::GetVertexTexture(int pass, int handle) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetVertexTexture(pass, handle);
}

const Rendering::ConstTextureSmartPointer Rendering::VisualEffectInstance
	::GetPixelTexture(int pass, const std::string& name) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetPixelTexture(pass, name);
}

const Rendering::ConstTextureSmartPointer Rendering::VisualEffectInstance
	::GetPixelTexture(int pass, int handle) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetPixelTexture(pass, handle);
} 

void Rendering::VisualEffectInstance
	::SetPixelConstant(int pass, int handle, const ShaderFloatSmartPointer& shaderFloat)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetPixelConstant(pass, handle, shaderFloat);
}

void Rendering::VisualEffectInstance
	::SetVertexConstant(int pass, int handle, const ShaderFloatSmartPointer& shaderFloat)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetVertexConstant(pass, handle, shaderFloat);
}

int Rendering::VisualEffectInstance
	::SetPixelTexture(int pass, const std::string& name, const TextureSmartPointer& texture)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetPixelTexture(pass, name, texture);
}

int Rendering::VisualEffectInstance
	::SetVertexTexture(int pass, const std::string& name, const TextureSmartPointer& texture)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetVertexTexture(pass, name, texture);
}

int Rendering::VisualEffectInstance
	::SetPixelConstant(int pass, const std::string& name, const ShaderFloatSmartPointer& shaderFloat)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetPixelConstant(pass, name, shaderFloat);
}


int Rendering::VisualEffectInstance
	::SetVertexConstant(int pass, const std::string& name, const ShaderFloatSmartPointer& shaderFloat)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetVertexConstant(pass, name, shaderFloat);
}


 #include STSTEM_WARNING_POP