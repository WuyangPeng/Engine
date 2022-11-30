///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/20 14:23)

#include "Rendering/RenderingExport.h"

#include "ShaderDetail.h"
#include "Detail/ShaderFactory.h"
#include "Detail/ShaderImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/Resources/Buffers/ConstantBuffer.h"
#include "Rendering/Resources/Buffers/StructuredBuffer.h"
#include "Rendering/Resources/Buffers/TextureBuffer.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Rendering, Shader)

CORE_TOOLS_RTTI_DEFINE(Rendering, Shader);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Shader);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Shader);

Rendering::Shader::Shader(GraphicsObjectType graphicsObjectType, RendererTypes rendererTypes, const GLSLReflection& reflector, ReferenceType referenceType)
    : ParentType{ "Shader", graphicsObjectType }, impl{ CoreTools::ImplCreateUseFactory::Default, rendererTypes, reflector, referenceType }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Shader)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Shader, Get, std::string, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Shader, GetConstantBufferSize, int, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Shader, GetConstantBufferSize, std::string, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Shader, GetTextureBufferSize, int, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Shader, GetTextureBufferSize, std::string, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Shader, GetStructuredBufferSize, int, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Shader, GetStructuredBufferSize, std::string, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Shader, GetConstantBufferLayout, int, Rendering::Shader::MemberLayoutContainer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Shader, GetConstantBufferLayout, std::string, Rendering::Shader::MemberLayoutContainer)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Shader, GetTextureBufferLayout, int, Rendering::Shader::MemberLayoutContainer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Shader, GetTextureBufferLayout, std::string, Rendering::Shader::MemberLayoutContainer)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Shader, GetStructuredBufferLayout, int, Rendering::Shader::MemberLayoutContainer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Shader, GetStructuredBufferLayout, std::string, Rendering::Shader::MemberLayoutContainer)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Shader, GetNumXThreads, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Shader, GetNumYThreads, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Shader, GetNumZThreads, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Shader, GetCompiledCode, Rendering::Shader::CompiledCodeContainer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Shader, GetData, int, Rendering::Shader::ShaderDataContainer)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Shader, GetShaderDataBegin, int, Rendering::Shader::ConstShaderDataContainerIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Shader, GetShaderDataEnd, int, Rendering::Shader::ConstShaderDataContainerIter)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Shader, GetShaderDataBegin, int, Rendering::Shader::ShaderDataContainerIter)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Shader, GetShaderDataEnd, int, Rendering::Shader::ShaderDataContainerIter)

Rendering::ConstGraphicsObjectSharedPtr Rendering::Shader::GetGraphicsObject(int index, int handle) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetGraphicsObject(index, handle);
}

void Rendering::Shader::Set(const std::string& textureName, const TextureSingleSharedPtr& texture, const std::string& samplerName, const SamplerStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_9;

    impl->Set(textureName, texture, samplerName, state);
}

void Rendering::Shader::Set(const std::string& textureName, const TextureArraySharedPtr& texture, const std::string& samplerName, const SamplerStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_9;

    impl->Set(textureName, texture, samplerName, state);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::Shader::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

Rendering::Shader::Shader(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseFactory::Default, RendererTypes::Default, GLSLReflection{ 0 }, ReferenceType::Vertex }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

int Rendering::Shader::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::Shader::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto registerID = ParentType::Register(target);

    if (0 < registerID)
    {
        impl->Register(target);
    }

    return registerID;
}

void Rendering::Shader::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Shader::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::Link(source);

    impl->Link(source);
}

void Rendering::Shader::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::PostLink();
}

void Rendering::Shader::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

bool Rendering::Shader::IsValid(const ShaderData& goal, const ConstantBuffer* resource) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->IsValid(goal, resource);
}

bool Rendering::Shader::IsValid(const ShaderData& goal, const TextureBuffer* resource) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->IsValid(goal, resource);
}

bool Rendering::Shader::IsValid(const ShaderData& goal, const StructuredBuffer* resource) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->IsValid(goal, resource);
}

bool Rendering::Shader::IsValid(const ShaderData& goal, const RawBuffer* resource) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->IsValid(goal, resource);
}

bool Rendering::Shader::IsValid(const ShaderData& goal, const TextureSingle* resource) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->IsValid(goal, resource);
}

bool Rendering::Shader::IsValid(const ShaderData& goal, const TextureArray* resource) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->IsValid(goal, resource);
}

bool Rendering::Shader::IsValid(const ShaderData& goal, const SamplerState* resource) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->IsValid(goal, resource);
}

Rendering::Shader::RendererObjectSharedPtr Rendering::Shader::CreateRendererObject(MAYBE_UNUSED RendererTypes rendererTypes)
{
    RENDERING_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("函数未实现"));
}