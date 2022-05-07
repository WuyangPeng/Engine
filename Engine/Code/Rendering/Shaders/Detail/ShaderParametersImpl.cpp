///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/12 13:41)

#include "Rendering/RenderingExport.h"

#include "ShaderParametersImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

using std::string;
using std::swap;
using std::vector;

Rendering::ShaderParametersImpl::ShaderParametersImpl(const ConstShaderBaseSharedPtr& shaderBase)
    : shader{ shaderBase }, constants{}, textures{}
{
    const auto numConstants = shader.object->GetNumConstants();
    if (0 < numConstants)
    {
        constants.resize(numConstants);
    }

    const auto numSamplers = shader.object->GetNumSamplers();
    if (0 < numSamplers)
    {
        textures.resize(numSamplers);
    }

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ShaderParametersImpl::ShaderParametersImpl() noexcept
    : shader{}, constants{}, textures{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ShaderParametersImpl::ShaderParametersImpl(const ShaderParametersImpl& rhs)
    : shader{ rhs.shader }, constants{}, textures{}
{
    for (const auto& pointer : rhs.constants)
    {
        constants.emplace_back(pointer.object->Clone());
    }

    for (const auto& pointer : rhs.textures)
    {
        textures.emplace_back(pointer.object->Clone());
    }

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ShaderParametersImpl& Rendering::ShaderParametersImpl::operator=(const ShaderParametersImpl& rhs)
{
    RENDERING_CLASS_IS_VALID_9;

    ShaderParametersImpl result{ rhs };

    Swap(result);

    return *this;
}

void Rendering::ShaderParametersImpl::Swap(ShaderParametersImpl& rhs) noexcept
{
    swap(shader, rhs.shader);
    constants.swap(rhs.constants);
    textures.swap(rhs.textures);
}

Rendering::ShaderParametersImpl& Rendering::ShaderParametersImpl::operator=(ShaderParametersImpl&& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    ShaderParametersImpl result{ std::move(rhs) };

    Swap(result);

    return *this;
}

Rendering::ShaderParametersImpl::ShaderParametersImpl(ShaderParametersImpl&& rhs) noexcept
    : shader{ std::move(rhs.shader) }, constants{ std::move(rhs.constants) }, textures{ std::move(rhs.textures) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ShaderParametersImpl)

void Rendering::ShaderParametersImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadObjectAssociated(shader);
    source.ReadObjectAssociatedContainer(constants);
    source.ReadObjectAssociatedContainer(textures);
}

void Rendering::ShaderParametersImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteObjectAssociated(shader);
    target.WriteObjectAssociatedContainerWithNumber(constants);
    target.WriteObjectAssociatedContainerWithNumber(textures);
}

int Rendering::ShaderParametersImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CORE_TOOLS_STREAM_SIZE(shader);

    size += CORE_TOOLS_STREAM_SIZE(constants);
    size += CORE_TOOLS_STREAM_SIZE(textures);

    return size;
}

void Rendering::ShaderParametersImpl::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ResolveLink(shader);

    if (0 < constants.size())
    {
        source.ResolveLinkContainer(constants);
    }

    if (0 < textures.size())
    {
        source.ResolveLinkContainer(textures);
    }
}

void Rendering::ShaderParametersImpl::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Register(shader);

    if (0 < constants.size())
    {
        target.RegisterContainer(constants);
    }

    if (0 < textures.size())
    {
        target.RegisterContainer(textures);
    }
}

CoreTools::ObjectSharedPtr Rendering::ShaderParametersImpl::GetObjectByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto& pointer : constants)
    {
        auto object = pointer.object->GetObjectByName(name);
        if (object != nullptr)
        {
            return object;
        }
    }

    for (auto& pointer : textures)
    {
        auto object = pointer.object->GetObjectByName(name);
        if (object != nullptr)
        {
            return object;
        }
    }

    return nullptr;
}

vector<CoreTools::ObjectSharedPtr> Rendering::ShaderParametersImpl::GetAllObjectsByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    vector<CoreTools::ObjectSharedPtr> objects{};

    for (auto& pointer : constants)
    {
        auto pointerObjects = pointer.object->GetAllObjectsByName(name);
        objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
    }

    for (auto& pointer : textures)
    {
        auto pointerObjects = pointer.object->GetAllObjectsByName(name);
        objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
    }

    return objects;
}

CoreTools::ConstObjectSharedPtr Rendering::ShaderParametersImpl::GetConstObjectByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    auto object = shader.object->GetConstObjectByName(name);

    if (object != nullptr)
    {
        return object;
    }
    else
    {
        for (const auto& pointer : constants)
        {
            object = pointer.object->GetConstObjectByName(name);
            if (object != nullptr)
            {
                return object;
            }
        }

        for (const auto& pointer : textures)
        {
            object = pointer.object->GetConstObjectByName(name);
            if (object != nullptr)
            {
                return object;
            }
        }
    }

    return nullptr;
}

vector<CoreTools::ConstObjectSharedPtr> Rendering::ShaderParametersImpl::GetAllConstObjectsByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    auto objects = shader.object->GetAllConstObjectsByName(name);

    for (const auto& pointer : constants)
    {
        auto pointerObjects = pointer.object->GetAllConstObjectsByName(name);
        objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
    }

    for (const auto& pointer : textures)
    {
        auto pointerObjects = pointer.object->GetAllConstObjectsByName(name);
        objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
    }

    return objects;
}

int Rendering::ShaderParametersImpl::GetNumConstants() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(constants.size());
}

int Rendering::ShaderParametersImpl::GetNumTextures() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(textures.size());
}

Rendering::ShaderParametersImpl::ConstShaderFloatSharedPtrGather Rendering::ShaderParametersImpl::GetConstants() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    ConstShaderFloatSharedPtrGather gather{};

    for (const auto& pointer : constants)
    {
        gather.emplace_back(pointer.object);
    }

    return gather;
}

Rendering::ShaderParametersImpl::ConstTextureSharedPtrGather Rendering::ShaderParametersImpl::GetTextures() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    ConstTextureSharedPtrGather gather{};

    for (const auto& pointer : textures)
    {
        gather.emplace_back(pointer.object);
    }

    return gather;
}

int Rendering::ShaderParametersImpl::SetConstant(const string& name, const ShaderFloatSharedPtr& shaderFloat)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto numConstants = GetNumConstants();

    for (auto index = 0; index < numConstants; ++index)
    {
        if (shader.object->GetConstantName(index) == name)
        {
            constants.at(index).object = shaderFloat;
            return index;
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("找不到常量！\n"s));
}

void Rendering::ShaderParametersImpl::SetConstant(int handle, const ShaderFloatSharedPtr& shaderFloat)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_0(0 <= handle && handle < GetNumConstants(), "索引越界！\n");

    constants.at(handle).object = shaderFloat;
}

int Rendering::ShaderParametersImpl::SetTexture(const string& name, const TextureSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto numTextures = GetNumTextures();

    for (auto index = 0; index < numTextures; ++index)
    {
        if (shader.object->GetSamplerName(index) == name)
        {
            textures.at(index).object = texture;
            return index;
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("找不到纹理！\n"s));
}

void Rendering::ShaderParametersImpl::SetTexture(int handle, const TextureSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_0(0 <= handle && handle < GetNumTextures(), "索引越界！\n");

    textures.at(handle).object = texture;
}

Rendering::ConstShaderFloatSharedPtr Rendering::ShaderParametersImpl::GetConstant(const string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto numConstants = GetNumConstants();

    for (auto index = 0; index < numConstants; ++index)
    {
        if (shader.object->GetConstantName(index) == name)
        {
            return GetConstant(index);
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("找不到常量！\n"s));
}

Rendering::ConstShaderFloatSharedPtr Rendering::ShaderParametersImpl::GetConstant(int handle) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= handle && handle < GetNumConstants(), "索引越界！\n");

    return constants.at(handle).object;
}

Rendering::ConstTextureSharedPtr Rendering::ShaderParametersImpl::GetTexture(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto numTextures = GetNumTextures();

    for (auto index = 0; index < numTextures; ++index)
    {
        if (shader.object->GetSamplerName(index) == name)
        {
            return GetTexture(index);
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("找不到纹理！\n"s));
}

Rendering::ConstTextureSharedPtr Rendering::ShaderParametersImpl::GetTexture(int handle) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= handle && handle < GetNumTextures(), "索引越界！\n");

    return textures.at(handle).object;
}

void Rendering::ShaderParametersImpl::UpdateConstants(const Visual* visual, const Camera* camera)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto& constant : constants)
    {
        if (constant.object->AllowUpdater())
        {
            constant.object->Update(visual, camera);
        }
    }
}
