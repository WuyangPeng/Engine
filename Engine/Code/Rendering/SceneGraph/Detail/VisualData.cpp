///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/02 14:05)

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
#include "Rendering/Shaders/VisualEffectInstance.h"

using std::string;
using std::vector;

Rendering::VisualData::VisualData(VisualPrimitiveType type) noexcept
    : visualPrimitiveType{ type }, vertexFormat{}, vertexBuffer{}, indexBuffer{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisualData::VisualData(VisualPrimitiveType type, const VertexFormatSharedPtr& vertexformat, const VertexBufferSharedPtr& vertexbuffer, const IndexBufferSharedPtr& indexbuffer) noexcept
    : visualPrimitiveType{ type }, vertexFormat{ vertexformat }, vertexBuffer{ vertexbuffer }, indexBuffer{ indexbuffer }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VisualData)

void Rendering::VisualData::SetPrimitiveType(VisualPrimitiveType type) noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    visualPrimitiveType = type;
}

Rendering::VisualPrimitiveType Rendering::VisualData::GetPrimitiveType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return visualPrimitiveType;
}

Rendering::ConstVertexFormatSharedPtr Rendering::VisualData::GetConstVertexFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return vertexFormat.object;
}

Rendering::VisualData::SpanIterator Rendering::VisualData::GetVertexBufferReadOnlyData() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return static_pointer_cast<const VertexBuffer>(vertexBuffer.object)->GetData();
}

int Rendering::VisualData::GetPositionOffset() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto positionIndex = vertexFormat.object->GetIndex(VertexFormatFlags::Semantic::Position);
    if (positionIndex == -1)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("更新需要顶点位置\n"s));
    }

    const auto positionType = vertexFormat.object->GetAttributeType(positionIndex);
    if (positionType != DataFormatType::R32G32B32Float && positionType != DataFormatType::R32G32B32A32Float)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("顶点必须是3元组或4元组\n"s));
    }

    return vertexFormat.object->GetOffset(positionIndex);
}

int Rendering::VisualData::GetVertexFormatStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return vertexFormat.object->GetStride();
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

void Rendering::VisualData::SetIndexBuffer(const IndexBufferSharedPtr& indexbuffer) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    indexBuffer.object = indexbuffer;
}

Rendering::ConstVertexBufferSharedPtr Rendering::VisualData::GetConstVertexBuffer() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return vertexBuffer.object;
}

void Rendering::VisualData::SetVertexBuffer(const VertexBufferSharedPtr& vertexbuffer) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    vertexBuffer.object = vertexbuffer;
}

Rendering::VertexFormatSharedPtr Rendering::VisualData::GetVertexFormat() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return vertexFormat.object;
}

void Rendering::VisualData::SetVertexFormat(const VertexFormatSharedPtr& vertexformat) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    vertexFormat.object = vertexformat;
}

void Rendering::VisualData::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadEnum(visualPrimitiveType);
    source.ReadObjectAssociated(vertexFormat);
    source.ReadObjectAssociated(vertexBuffer);
    source.ReadObjectAssociated(indexBuffer);
}

void Rendering::VisualData::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteEnum(visualPrimitiveType);
    target.WriteObjectAssociated(vertexFormat);
    target.WriteObjectAssociated(vertexBuffer);
    target.WriteObjectAssociated(indexBuffer);
}

int Rendering::VisualData::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    int size = CORE_TOOLS_STREAM_SIZE(visualPrimitiveType);

    size += CORE_TOOLS_STREAM_SIZE(vertexFormat);
    size += CORE_TOOLS_STREAM_SIZE(vertexBuffer);
    size += CORE_TOOLS_STREAM_SIZE(indexBuffer);

    return size;
}

void Rendering::VisualData::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Register(vertexFormat);
    target.Register(vertexBuffer);
    target.Register(indexBuffer);
}

void Rendering::VisualData::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ResolveLink(vertexFormat);
    source.ResolveLink(vertexBuffer);
    source.ResolveLink(indexBuffer);
}

CoreTools::ObjectSharedPtr Rendering::VisualData::GetObjectByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    auto object = vertexFormat.object->GetObjectByName(name);
    if (object != nullptr)
        return object;

    object = vertexBuffer.object->GetObjectByName(name);
    if (object != nullptr)
        return object;

    object = indexBuffer.object->GetObjectByName(name);
    if (object != nullptr)
        return object;
    else
        return nullptr;
}

vector<CoreTools::ObjectSharedPtr> Rendering::VisualData::GetAllObjectsByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    auto vertexFormatObjects = vertexFormat.object->GetAllObjectsByName(name);
    auto vertexBufferObjects = vertexBuffer.object->GetAllObjectsByName(name);
    auto indexBufferObjects = indexBuffer.object->GetAllObjectsByName(name);

    vector<CoreTools::ObjectSharedPtr> entirelyObjects{};

    entirelyObjects.insert(entirelyObjects.end(), vertexFormatObjects.begin(), vertexFormatObjects.end());

    entirelyObjects.insert(entirelyObjects.end(), vertexBufferObjects.begin(), vertexBufferObjects.end());

    entirelyObjects.insert(entirelyObjects.end(), indexBufferObjects.begin(), indexBufferObjects.end());

    return entirelyObjects;
}

CoreTools::ConstObjectSharedPtr Rendering::VisualData::GetConstObjectByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    auto object = vertexFormat.object->GetConstObjectByName(name);
    if (object != nullptr)
        return object;

    object = vertexBuffer.object->GetConstObjectByName(name);
    if (object != nullptr)
        return object;

    object = indexBuffer.object->GetConstObjectByName(name);
    if (object != nullptr)
        return object;
    else
        return nullptr;
}

vector<CoreTools::ConstObjectSharedPtr> Rendering::VisualData::GetAllConstObjectsByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    auto vertexFormatObjects = vertexFormat.object->GetAllConstObjectsByName(name);
    auto vertexBufferObjects = vertexBuffer.object->GetAllConstObjectsByName(name);
    auto indexBufferObjects = indexBuffer.object->GetAllConstObjectsByName(name);

    vector<CoreTools::ConstObjectSharedPtr> entirelyObjects{};

    entirelyObjects.insert(entirelyObjects.end(), vertexFormatObjects.begin(), vertexFormatObjects.end());

    entirelyObjects.insert(entirelyObjects.end(), vertexBufferObjects.begin(), vertexBufferObjects.end());

    entirelyObjects.insert(entirelyObjects.end(), indexBufferObjects.begin(), indexBufferObjects.end());

    return entirelyObjects;
}
