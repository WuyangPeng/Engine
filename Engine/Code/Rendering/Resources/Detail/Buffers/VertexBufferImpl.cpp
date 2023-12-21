/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/13 14:31)

#include "Rendering/RenderingExport.h"

#include "VertexBufferImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"

Rendering::VertexBufferImpl::VertexBufferImpl() noexcept
    : vertexFormat{}, structuredBuffer{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VertexBufferImpl::VertexBufferImpl(const VertexFormat& format)
    : vertexFormat{ format.Clone() }, structuredBuffer{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VertexBufferImpl::VertexBufferImpl(const VertexFormat& format, const StructuredBuffer& structuredBuffer)
    : vertexFormat{ format.Clone() }, structuredBuffer{ structuredBuffer.Clone() }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VertexBufferImpl::VertexBufferImpl(const VertexBufferImpl& rhs)
    : vertexFormat{ rhs.vertexFormat.Clone() }, structuredBuffer{ rhs.structuredBuffer.Clone() }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VertexBufferImpl& Rendering::VertexBufferImpl::operator=(const VertexBufferImpl& rhs)
{
    RENDERING_CLASS_IS_VALID_9;

    vertexFormat.object = rhs.vertexFormat.Clone();
    structuredBuffer.object = rhs.structuredBuffer.Clone();

    return *this;
}

Rendering::VertexBufferImpl::VertexBufferImpl(VertexBufferImpl&& rhs) noexcept
    : vertexFormat{ std::move(rhs.vertexFormat) }, structuredBuffer{ std::move(rhs.structuredBuffer) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VertexBufferImpl& Rendering::VertexBufferImpl::operator=(VertexBufferImpl&& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    vertexFormat = std::move(rhs.vertexFormat);
    structuredBuffer = std::move(rhs.structuredBuffer);

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VertexBufferImpl)

void Rendering::VertexBufferImpl::CheckVertexFormat() const
{
    if (vertexFormat.object == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("vertexFormat指针为空。"))
    }
}

Rendering::VertexFormat Rendering::VertexBufferImpl::GetFormat() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CheckVertexFormat();

    return *vertexFormat;
}

Rendering::VertexBufferImpl::StructuredBufferSharedPtr Rendering::VertexBufferImpl::GetStructuredBuffer() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return structuredBuffer.object;
}

Rendering::VertexBufferImpl::ConstStructuredBufferSharedPtr Rendering::VertexBufferImpl::GetStructuredBuffer() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return structuredBuffer.object;
}

bool Rendering::VertexBufferImpl::StandardUsage() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return vertexFormat->GetNumAttributes() != 0 && structuredBuffer.object == nullptr;
}

int Rendering::VertexBufferImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return CoreTools::GetStreamSize(vertexFormat) + CoreTools::GetStreamSize(structuredBuffer);
}

void Rendering::VertexBufferImpl::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.WriteObjectAssociated(vertexFormat);
    target.WriteObjectAssociated(structuredBuffer);
}

void Rendering::VertexBufferImpl::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.ReadObjectAssociated(vertexFormat);
    source.ReadObjectAssociated(structuredBuffer);
}

void Rendering::VertexBufferImpl::Register(ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.Register(vertexFormat);
    target.Register(structuredBuffer);
}

void Rendering::VertexBufferImpl::Link(ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.ResolveLink(vertexFormat);
    source.ResolveLink(structuredBuffer);
}

int Rendering::VertexBufferImpl::GetIndex(Semantic usage, int usageIndex) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return vertexFormat->GetIndex(usage, usageIndex);
}

Rendering::DataFormatType Rendering::VertexBufferImpl::GetAttributeType(int attribute) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return vertexFormat->GetAttributeType(attribute);
}

int Rendering::VertexBufferImpl::GetOffset(int attribute) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return vertexFormat->GetOffset(attribute);
}

CoreTools::ObjectSharedPtr Rendering::VertexBufferImpl::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    CheckVertexFormat();

    if (auto object = vertexFormat->GetObjectByName(name);
        !object->IsNullObject())
    {
        return object;
    }
    else if (structuredBuffer.object != nullptr)
    {
        return structuredBuffer->GetObjectByName(name);
    }
    else
    {
        return CoreTools::Object::GetNullObject();
    }
}

Rendering::VertexBufferImpl::ObjectSharedPtrContainer Rendering::VertexBufferImpl::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    CheckVertexFormat();

    auto entirelyObjects = vertexFormat->GetAllObjectsByName(name);

    if (structuredBuffer.object != nullptr)
    {
        const auto structuredBufferObjects = structuredBuffer->GetAllObjectsByName(name);
        entirelyObjects.insert(entirelyObjects.end(), structuredBufferObjects.begin(), structuredBufferObjects.end());
    }

    return entirelyObjects;
}

CoreTools::ConstObjectSharedPtr Rendering::VertexBufferImpl::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CheckVertexFormat();

    if (auto object = vertexFormat->GetConstObjectByName(name);
        !object->IsNullObject())
    {
        return object;
    }
    else if (structuredBuffer.object != nullptr)
    {
        return structuredBuffer->GetConstObjectByName(name);
    }
    else
    {
        return CoreTools::Object::GetNullObject();
    }
}

Rendering::VertexBufferImpl::ConstObjectSharedPtrContainer Rendering::VertexBufferImpl::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CheckVertexFormat();

    auto entirelyObjects = vertexFormat->GetAllConstObjectsByName(name);

    if (structuredBuffer.object != nullptr)
    {
        const auto structuredBufferObjects = structuredBuffer->GetAllConstObjectsByName(name);
        entirelyObjects.insert(entirelyObjects.end(), structuredBufferObjects.begin(), structuredBufferObjects.end());
    }

    return entirelyObjects;
}