/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/20 09:54)

#include "Rendering/RenderingExport.h"

#include "VisualData.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Rendering/Resources/Flags/DataFormatType.h"

Rendering::VisualData::VisualData() noexcept
    : vertexFormat{}, vertexBuffer{}, indexBuffer{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisualData::VisualData(const VertexFormatSharedPtr& vertexFormat, const VertexBufferSharedPtr& vertexBuffer, const IndexBufferSharedPtr& indexBuffer) noexcept
    : vertexFormat{ vertexFormat }, vertexBuffer{ vertexBuffer }, indexBuffer{ indexBuffer }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisualData::VisualData(const VisualData& rhs)
    : vertexFormat{ rhs.vertexFormat.Clone() },
      vertexBuffer{ rhs.vertexBuffer.Clone() },
      indexBuffer{ rhs.indexBuffer.Clone() }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisualData& Rendering::VisualData::operator=(const VisualData& rhs)
{
    RENDERING_CLASS_IS_VALID_9;

    vertexFormat.object = rhs.vertexFormat.Clone();
    vertexBuffer.object = rhs.vertexBuffer.Clone();
    indexBuffer.object = rhs.indexBuffer.Clone();

    return *this;
}

Rendering::VisualData::VisualData(VisualData&& rhs) noexcept
    : vertexFormat{ std::move(rhs.vertexFormat) },
      vertexBuffer{ std::move(rhs.vertexBuffer) },
      indexBuffer{ std::move(rhs.indexBuffer) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisualData& Rendering::VisualData::operator=(VisualData&& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    vertexFormat = std::move(rhs.vertexFormat);
    vertexBuffer = std::move(rhs.vertexBuffer);
    indexBuffer = std::move(rhs.indexBuffer);

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VisualData)

Rendering::IndexFormatType Rendering::VisualData::GetPrimitiveType() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (indexBuffer.object == nullptr || indexBuffer->IsNullObject())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("索引缓冲区未连接"))
    }

    return indexBuffer->GetPrimitiveType();
}

Rendering::ConstVertexFormatSharedPtr Rendering::VisualData::GetConstVertexFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return vertexFormat.object;
}

Rendering::VisualData::ConstSpanIterator Rendering::VisualData::GetVertexBufferReadOnlyData() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return static_pointer_cast<const VertexBuffer>(vertexBuffer.object)->GetStorage();
}

Rendering::VisualData::SpanIterator Rendering::VisualData::GetChannel(Semantic semantic, int unit, const DataFormatTypeContainer& requiredTypes)
{
    RENDERING_CLASS_IS_VALID_9;

    if (vertexBuffer.object == nullptr || vertexBuffer->IsNullObject())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("缓冲区未连接"))
    }

    return vertexBuffer->GetChannel(semantic, unit, requiredTypes);
}

Rendering::VisualData::ConstSpanIterator Rendering::VisualData::GetConstChannel(Semantic semantic, int unit, const DataFormatTypeContainer& requiredTypes) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (vertexBuffer.object == nullptr || vertexBuffer->IsNullObject())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("缓冲区未连接"))
    }

    return vertexBuffer->GetConstChannel(semantic, unit, requiredTypes);
}

int Rendering::VisualData::GetPositionOffset() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto positionIndex = vertexFormat->GetIndex(VertexFormatFlags::Semantic::Position);
    if (positionIndex == -1)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("更新需要顶点位置\n"s))
    }

    if (const auto positionType = vertexFormat->GetAttributeType(positionIndex);
        positionType != DataFormatType::R32G32B32Float && positionType != DataFormatType::R32G32B32A32Float)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("顶点必须是3元组或4元组\n"s))
    }

    return vertexFormat.object->GetOffset(positionIndex);
}

int Rendering::VisualData::GetVertexFormatStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return vertexFormat.object->GetVertexSize();
}

int Rendering::VisualData::GetVertexBufferNumElements() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return vertexBuffer.object->GetNumElements();
}

bool Rendering::VisualData::IsVertexSharedPtrValid() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (!(!vertexBuffer.object || !vertexFormat.object))
    {
        return true;
    }
    else
    {
        return false;
    }
}

Rendering::IndexBufferSharedPtr Rendering::VisualData::GetIndexBuffer() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return indexBuffer.object;
}

Rendering::VertexBufferSharedPtr Rendering::VisualData::GetVertexBuffer() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return vertexBuffer.object;
}

Rendering::ConstIndexBufferSharedPtr Rendering::VisualData::GetConstIndexBuffer() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return indexBuffer.object;
}

void Rendering::VisualData::SetIndexBuffer(const IndexBufferSharedPtr& aIndexBuffer) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    indexBuffer.object = aIndexBuffer;
}

Rendering::ConstVertexBufferSharedPtr Rendering::VisualData::GetConstVertexBuffer() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return vertexBuffer.object;
}

void Rendering::VisualData::SetVertexBuffer(const VertexBufferSharedPtr& aVertexBuffer) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    vertexBuffer.object = aVertexBuffer;
}

Rendering::VertexFormatSharedPtr Rendering::VisualData::GetVertexFormat() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return vertexFormat.object;
}

void Rendering::VisualData::SetVertexFormat(const VertexFormatSharedPtr& aVertexFormat) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    vertexFormat.object = aVertexFormat;
}

void Rendering::VisualData::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadObjectAssociated(vertexFormat);
    source.ReadObjectAssociated(vertexBuffer);
    source.ReadObjectAssociated(indexBuffer);
}

void Rendering::VisualData::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteObjectAssociated(vertexFormat);
    target.WriteObjectAssociated(vertexBuffer);
    target.WriteObjectAssociated(indexBuffer);
}

int Rendering::VisualData::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CoreTools::GetStreamSize(vertexFormat);

    size += CoreTools::GetStreamSize(vertexBuffer);
    size += CoreTools::GetStreamSize(indexBuffer);

    return size;
}

void Rendering::VisualData::Register(ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Register(vertexFormat);
    target.Register(vertexBuffer);
    target.Register(indexBuffer);
}

void Rendering::VisualData::Link(ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ResolveLink(vertexFormat);
    source.ResolveLink(vertexBuffer);
    source.ResolveLink(indexBuffer);
}

CoreTools::ObjectSharedPtr Rendering::VisualData::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    auto object = vertexFormat->GetObjectByName(name);
    if (!object->IsNullObject())
    {
        return object;
    }

    object = vertexBuffer->GetObjectByName(name);
    if (!object->IsNullObject())
    {
        return object;
    }

    object = indexBuffer->GetObjectByName(name);
    if (!object->IsNullObject())
    {
        return object;
    }

    return Object::GetNullObject();
}

Rendering::VisualData::ObjectSharedPtrContainer Rendering::VisualData::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto vertexFormatObjects = vertexFormat->GetAllObjectsByName(name);
    const auto vertexBufferObjects = vertexBuffer->GetAllObjectsByName(name);
    const auto indexBufferObjects = indexBuffer->GetAllObjectsByName(name);

    ObjectSharedPtrContainer entirelyObjects{};

    entirelyObjects.insert(entirelyObjects.end(), vertexFormatObjects.begin(), vertexFormatObjects.end());
    entirelyObjects.insert(entirelyObjects.end(), vertexBufferObjects.begin(), vertexBufferObjects.end());
    entirelyObjects.insert(entirelyObjects.end(), indexBufferObjects.begin(), indexBufferObjects.end());

    return entirelyObjects;
}

CoreTools::ConstObjectSharedPtr Rendering::VisualData::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    auto object = vertexFormat->GetConstObjectByName(name);
    if (!object->IsNullObject())
    {
        return object;
    }

    object = vertexBuffer->GetConstObjectByName(name);
    if (!object->IsNullObject())
    {
        return object;
    }

    object = indexBuffer->GetConstObjectByName(name);
    if (!object->IsNullObject())
    {
        return object;
    }

    return Object::GetNullObject();
}

Rendering::VisualData::ConstObjectSharedPtrContainer Rendering::VisualData::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    const auto vertexFormatObjects = vertexFormat->GetAllConstObjectsByName(name);
    const auto vertexBufferObjects = vertexBuffer->GetAllConstObjectsByName(name);
    const auto indexBufferObjects = indexBuffer->GetAllConstObjectsByName(name);

    ConstObjectSharedPtrContainer entirelyObjects{};

    entirelyObjects.insert(entirelyObjects.end(), vertexFormatObjects.begin(), vertexFormatObjects.end());
    entirelyObjects.insert(entirelyObjects.end(), vertexBufferObjects.begin(), vertexBufferObjects.end());
    entirelyObjects.insert(entirelyObjects.end(), indexBufferObjects.begin(), indexBufferObjects.end());

    return entirelyObjects;
}
