/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 15:13)

#include "Rendering/RenderingExport.h"

#include "ShaderDetail.h"
#include "Flags/ReferenceType.h"
#include "Detail/ShaderFactory.h"
#include "Detail/ShaderImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Rendering/RendererEngine/Flags/RendererTypes.h"
#include "Rendering/Resources/Buffers/TextureBuffer.h"
#include "Rendering/Shaders/Reflection.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Rendering, Shader)

CORE_TOOLS_RTTI_DEFINE(Rendering, Shader)
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Shader);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Shader);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, Shader)

Rendering::Shader::Shader(GraphicsObjectType graphicsObjectType, RendererTypes rendererTypes, const Reflection& reflector, ReferenceType referenceType)
    : ParentType{ "Shader", graphicsObjectType }, impl{ CoreTools::ImplCreateUseFactory::Default, rendererTypes, reflector, referenceType }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Shader)

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
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseFactory::Default, RendererTypes::Default, Reflection::Create(), ReferenceType::Vertex }
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

    const auto registerId = ParentType::Register(target);

    if (0 < registerId)
    {
        impl->Register(target);
    }

    return registerId;
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

Rendering::Shader::RendererObjectSharedPtr Rendering::Shader::CreateRendererObject(RendererTypes rendererTypes)
{
    RENDERING_CLASS_IS_VALID_9;

    System::UnusedFunction(rendererTypes);

    THROW_EXCEPTION(SYSTEM_TEXT("着色器无法生成RendererObject。"))
}

int Rendering::Shader::Get(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->Get(name);
}

int Rendering::Shader::GetConstantBufferSize(int handle) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetConstantBufferSize(handle);
}

int Rendering::Shader::GetConstantBufferSize(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetConstantBufferSize(name);
}

int Rendering::Shader::GetTextureBufferSize(int handle) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetTextureBufferSize(handle);
}

int Rendering::Shader::GetTextureBufferSize(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetTextureBufferSize(name);
}

int Rendering::Shader::GetStructuredBufferSize(int handle) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetStructuredBufferSize(handle);
}

int Rendering::Shader::GetStructuredBufferSize(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetStructuredBufferSize(name);
}

Rendering::Shader::MemberLayoutContainer Rendering::Shader::GetConstantBufferLayout(int handle) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetConstantBufferLayout(handle);
}

Rendering::Shader::MemberLayoutContainer Rendering::Shader::GetConstantBufferLayout(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetConstantBufferLayout(name);
}

Rendering::Shader::MemberLayoutContainer Rendering::Shader::GetTextureBufferLayout(int handle) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetTextureBufferLayout(handle);
}

Rendering::Shader::MemberLayoutContainer Rendering::Shader::GetTextureBufferLayout(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetTextureBufferLayout(name);
}

Rendering::Shader::MemberLayoutContainer Rendering::Shader::GetStructuredBufferLayout(int handle) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetStructuredBufferLayout(handle);
}

Rendering::Shader::MemberLayoutContainer Rendering::Shader::GetStructuredBufferLayout(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetStructuredBufferLayout(name);
}

int Rendering::Shader::GetNumXThreads() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetNumXThreads();
}

int Rendering::Shader::GetNumYThreads() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetNumYThreads();
}

int Rendering::Shader::GetNumZThreads() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetNumZThreads();
}

Rendering::Shader::CompiledCodeContainer Rendering::Shader::GetCompiledCode() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetCompiledCode();
}

Rendering::Shader::ShaderDataContainer& Rendering::Shader::GetData(int lookup)  
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetData(lookup);
}

Rendering::Shader::ConstShaderDataContainerIter Rendering::Shader::GetShaderDataBegin(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetShaderDataBegin(index);
}

Rendering::Shader::ConstShaderDataContainerIter Rendering::Shader::GetShaderDataEnd(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetShaderDataEnd(index);
}

Rendering::Shader::ShaderDataContainerIter Rendering::Shader::GetShaderDataBegin(int index)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetShaderDataBegin(index);
}

Rendering::Shader::ShaderDataContainerIter Rendering::Shader::GetShaderDataEnd(int index)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetShaderDataEnd(index);
}