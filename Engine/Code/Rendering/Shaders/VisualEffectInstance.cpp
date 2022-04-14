// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 17:28)

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

using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26456)
CORE_TOOLS_RTTI_DEFINE(Rendering, VisualEffectInstance);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, VisualEffectInstance);
CORE_TOOLS_FACTORY_DEFINE(Rendering, VisualEffectInstance);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, VisualEffectInstance);

#define COPY_CONSTRUCTION_DEFINE_WITH_PARENT(namespaceName, className)                      \
    namespaceName::className::className(const className& rhs)                               \
        : ParentType{ rhs }, impl{ std::make_shared<ImplType>(*rhs.impl) }                  \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        SELF_CLASS_IS_VALID_0;                                                              \
    }                                                                                       \
    namespaceName::className& namespaceName::className::operator=(const className& rhs)     \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        className temp{ rhs };                                                              \
        Swap(temp);                                                                         \
        return *this;                                                                       \
    }                                                                                       \
    void namespaceName::className::Swap(className& rhs) noexcept                            \
    {                                                                                       \
        ;                                                                                   \
        std::swap(impl, rhs.impl);                                                          \
    }                                                                                       \
    namespaceName::className::className(className&& rhs) noexcept                           \
        : ParentType{ std::move(rhs) }, impl{ std::move(rhs.impl) }                         \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
    }                                                                                       \
    namespaceName::className& namespaceName::className::operator=(className&& rhs) noexcept \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        ParentType::operator=(std::move(rhs));                                              \
        impl = std::move(rhs.impl);                                                         \
        return *this;                                                                       \
    }
COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, VisualEffectInstance);

Rendering::VisualEffectInstance::VisualEffectInstance(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ make_shared<ImplType>() }
{
    SELF_CLASS_IS_VALID_0;
}
CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, VisualEffectInstance)
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, VisualEffectInstance)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, VisualEffectInstance)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, VisualEffectInstance)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, VisualEffectInstance)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, VisualEffectInstance)

Rendering::VisualEffectInstance::VisualEffectInstance(const VisualEffectSharedPtr& effect, int techniqueIndex)
    : ParentType{ "VisualEffectInstance" }, impl{ make_shared<ImplType>(effect, techniqueIndex) }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VisualEffectInstance::~VisualEffectInstance()
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, VisualEffectInstance)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisualEffectInstance, GetEffect, const Rendering::ConstVisualEffectSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisualEffectInstance, GetTechniqueIndex, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisualEffectInstance, GetNumPasses, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualEffectInstance, GetConstPass, int, const Rendering::ConstVisualPassSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualEffectInstance, GetConstPixelParameters, int, const Rendering::ConstShaderParametersSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualEffectInstance, GetConstVertexParameters, int, const Rendering::ConstShaderParametersSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualEffectInstance, GetPixelParameters, int, const Rendering::ShaderParametersSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualEffectInstance, GetVertexParameters, int, const Rendering::ShaderParametersSharedPtr)

void Rendering::VisualEffectInstance::SetVertexTexture(int pass, int handle, const TextureSharedPtr& texture)
{
    ;

    return impl->SetVertexTexture(pass, handle, texture);
}

void Rendering::VisualEffectInstance::SetPixelTexture(int pass, int handle, const TextureSharedPtr& texture)
{
    ;

    return impl->SetPixelTexture(pass, handle, texture);
}

const Rendering::ConstShaderFloatSharedPtr Rendering::VisualEffectInstance::GetVertexConstant(int pass, const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetVertexConstant(pass, name);
}

const Rendering::ConstShaderFloatSharedPtr Rendering::VisualEffectInstance::GetVertexConstant(int pass, int handle) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetVertexConstant(pass, handle);
}

const Rendering::ConstShaderFloatSharedPtr Rendering::VisualEffectInstance::GetPixelConstant(int pass, const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetPixelConstant(pass, name);
}

const Rendering::ConstShaderFloatSharedPtr Rendering::VisualEffectInstance::GetPixelConstant(int pass, int handle) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetPixelConstant(pass, handle);
}

const Rendering::ConstTextureSharedPtr Rendering::VisualEffectInstance::GetVertexTexture(int pass, const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetVertexTexture(pass, name);
}

const Rendering::ConstTextureSharedPtr Rendering::VisualEffectInstance::GetVertexTexture(int pass, int handle) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetVertexTexture(pass, handle);
}

const Rendering::ConstTextureSharedPtr Rendering::VisualEffectInstance::GetPixelTexture(int pass, const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetPixelTexture(pass, name);
}

const Rendering::ConstTextureSharedPtr Rendering::VisualEffectInstance::GetPixelTexture(int pass, int handle) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetPixelTexture(pass, handle);
}

void Rendering::VisualEffectInstance::SetPixelConstant(int pass, int handle, const ShaderFloatSharedPtr& shaderFloat)
{
    ;

    return impl->SetPixelConstant(pass, handle, shaderFloat);
}

void Rendering::VisualEffectInstance::SetVertexConstant(int pass, int handle, const ShaderFloatSharedPtr& shaderFloat)
{
    ;

    return impl->SetVertexConstant(pass, handle, shaderFloat);
}

int Rendering::VisualEffectInstance::SetPixelTexture(int pass, const std::string& name, const TextureSharedPtr& texture)
{
    ;

    return impl->SetPixelTexture(pass, name, texture);
}

int Rendering::VisualEffectInstance::SetVertexTexture(int pass, const std::string& name, const TextureSharedPtr& texture)
{
    ;

    return impl->SetVertexTexture(pass, name, texture);
}

int Rendering::VisualEffectInstance::SetPixelConstant(int pass, const std::string& name, const ShaderFloatSharedPtr& shaderFloat)
{
    ;

    return impl->SetPixelConstant(pass, name, shaderFloat);
}

int Rendering::VisualEffectInstance::SetVertexConstant(int pass, const std::string& name, const ShaderFloatSharedPtr& shaderFloat)
{
    ;

    return impl->SetVertexConstant(pass, name, shaderFloat);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::VisualEffectInstance::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP