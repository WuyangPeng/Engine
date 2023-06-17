///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:54)

#include "Rendering/RenderingExport.h"

#include "VisualEffectInstance.h"
#include "Detail/VisualEffectInstanceImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, VisualEffectInstance)

CORE_TOOLS_RTTI_DEFINE(Rendering, VisualEffectInstance);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, VisualEffectInstance);
CORE_TOOLS_FACTORY_DEFINE(Rendering, VisualEffectInstance);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, VisualEffectInstance);

Rendering::VisualEffectInstance::VisualEffectInstance(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, VisualEffectInstance)
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, VisualEffectInstance)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, VisualEffectInstance)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, VisualEffectInstance)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, VisualEffectInstance)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, VisualEffectInstance)

Rendering::VisualEffectInstance::VisualEffectInstance(const VisualEffectSharedPtr& effect, int techniqueIndex)
    : ParentType{ "VisualEffectInstance" }, impl{ effect, techniqueIndex }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, VisualEffectInstance)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VisualEffectInstance, GetEffect, Rendering::ConstVisualEffectSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VisualEffectInstance, GetTechniqueIndex, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VisualEffectInstance, GetNumPasses, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, VisualEffectInstance, GetConstPass, int, Rendering::ConstVisualPassSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualEffectInstance, GetConstPixelParameters, int, Rendering::ConstShaderParametersSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualEffectInstance, GetConstVertexParameters, int, Rendering::ConstShaderParametersSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualEffectInstance, GetPixelParameters, int, Rendering::ShaderParametersSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualEffectInstance, GetVertexParameters, int, Rendering::ShaderParametersSharedPtr)

void Rendering::VisualEffectInstance::SetVertexTexture(int pass, int handle, const TextureSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetVertexTexture(pass, handle, texture);
}

void Rendering::VisualEffectInstance::SetPixelTexture(int pass, int handle, const TextureSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetPixelTexture(pass, handle, texture);
}

Rendering::ConstShaderFloatSharedPtr Rendering::VisualEffectInstance::GetVertexConstant(int pass, const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetVertexConstant(pass, name);
}

Rendering::ConstShaderFloatSharedPtr Rendering::VisualEffectInstance::GetVertexConstant(int pass, int handle) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetVertexConstant(pass, handle);
}

Rendering::ConstShaderFloatSharedPtr Rendering::VisualEffectInstance::GetPixelConstant(int pass, const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetPixelConstant(pass, name);
}

Rendering::ConstShaderFloatSharedPtr Rendering::VisualEffectInstance::GetPixelConstant(int pass, int handle) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetPixelConstant(pass, handle);
}

Rendering::ConstTextureSharedPtr Rendering::VisualEffectInstance::GetVertexTexture(int pass, const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetVertexTexture(pass, name);
}

Rendering::ConstTextureSharedPtr Rendering::VisualEffectInstance::GetVertexTexture(int pass, int handle) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetVertexTexture(pass, handle);
}

Rendering::ConstTextureSharedPtr Rendering::VisualEffectInstance::GetPixelTexture(int pass, const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetPixelTexture(pass, name);
}

Rendering::ConstTextureSharedPtr Rendering::VisualEffectInstance::GetPixelTexture(int pass, int handle) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetPixelTexture(pass, handle);
}

void Rendering::VisualEffectInstance::SetPixelConstant(int pass, int handle, const ShaderFloatSharedPtr& shaderFloat)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetPixelConstant(pass, handle, shaderFloat);
}

void Rendering::VisualEffectInstance::SetVertexConstant(int pass, int handle, const ShaderFloatSharedPtr& shaderFloat)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetVertexConstant(pass, handle, shaderFloat);
}

int Rendering::VisualEffectInstance::SetPixelTexture(int pass, const std::string& name, const TextureSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetPixelTexture(pass, name, texture);
}

int Rendering::VisualEffectInstance::SetVertexTexture(int pass, const std::string& name, const TextureSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetVertexTexture(pass, name, texture);
}

int Rendering::VisualEffectInstance::SetPixelConstant(int pass, const std::string& name, const ShaderFloatSharedPtr& shaderFloat)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetPixelConstant(pass, name, shaderFloat);
}

int Rendering::VisualEffectInstance::SetVertexConstant(int pass, const std::string& name, const ShaderFloatSharedPtr& shaderFloat)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetVertexConstant(pass, name, shaderFloat);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::VisualEffectInstance::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
