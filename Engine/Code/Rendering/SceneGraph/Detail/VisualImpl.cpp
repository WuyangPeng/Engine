///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:15)

#include "Rendering/RenderingExport.h"

#include "VisualImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "Rendering/DataTypes/SpecializedIO.h"

Rendering::VisualImpl::VisualImpl(VisualPrimitiveType type) noexcept
    : visualData{ type }, modelBound{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisualImpl::VisualImpl(VisualPrimitiveType type, const VertexFormatSharedPtr& vertexformat, const VertexBufferSharedPtr& vertexbuffer, const IndexBufferSharedPtr& indexbuffer) noexcept
    : visualData{ type, vertexformat, vertexbuffer, indexbuffer }, modelBound{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VisualImpl)

Rendering::VisualPrimitiveType Rendering::VisualImpl::GetPrimitiveType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return visualData.GetPrimitiveType();
}

Rendering::ConstVertexFormatSharedPtr Rendering::VisualImpl::GetConstVertexFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return visualData.GetConstVertexFormat();
}

Rendering::BoundF& Rendering::VisualImpl::GetModelBound() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26473)

    return const_cast<BoundF&>(static_cast<const ClassType*>(this)->GetModelBound());

#include STSTEM_WARNING_POP
}

const Rendering::BoundF& Rendering::VisualImpl::GetModelBound() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return modelBound;
}

Rendering::IndexBufferSharedPtr Rendering::VisualImpl::GetIndexBuffer() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return visualData.GetIndexBuffer();
}

Rendering::VertexBufferSharedPtr Rendering::VisualImpl::GetVertexBuffer() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return visualData.GetVertexBuffer();
}

Rendering::ConstIndexBufferSharedPtr Rendering::VisualImpl::GetConstIndexBuffer() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return visualData.GetConstIndexBuffer();
}

void Rendering::VisualImpl::SetIndexBuffer(const IndexBufferSharedPtr& indexbuffer) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    visualData.SetIndexBuffer(indexbuffer);
}

Rendering::ConstVertexBufferSharedPtr Rendering::VisualImpl::GetConstVertexBuffer() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return visualData.GetConstVertexBuffer();
}

void Rendering::VisualImpl::SetVertexBuffer(const VertexBufferSharedPtr& vertexbuffer) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    visualData.SetVertexBuffer(vertexbuffer);
}

Rendering::VertexFormatSharedPtr Rendering::VisualImpl::GetVertexFormat() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return visualData.GetVertexFormat();
}

void Rendering::VisualImpl::SetVertexFormat(const VertexFormatSharedPtr& vertexformat) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    visualData.SetVertexFormat(vertexformat);
}

Rendering::BoundF Rendering::VisualImpl::GetWorldBound(const TransformF& worldTransform)
{
    RENDERING_CLASS_IS_VALID_9;

    return modelBound.TransformBy(worldTransform);
}

void Rendering::VisualImpl::UpdateModelBound()
{
    RENDERING_CLASS_IS_VALID_9;

    if (visualData.IsVertexSharedPtrValid())
    {
        DoUpdateModelBound();
    }
}

void Rendering::VisualImpl::ComputeBounding(const std::vector<APoint>& positions)
{
    RENDERING_CLASS_IS_VALID_9;

    modelBound.ComputeFromData(positions);
}

void Rendering::VisualImpl::DoUpdateModelBound()
{
    const auto numVertices = visualData.GetVertexBufferNumElements();
    const auto stride = visualData.GetVertexFormatStride();
    const auto data = visualData.GetVertexBufferReadOnlyData();
    const auto positionOffset = visualData.GetPositionOffset();

    modelBound.ComputeFromData(numVertices, stride, data);
}

void Rendering::VisualImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    visualData.Load(source);
    source.ReadAggregate(modelBound);
}

void Rendering::VisualImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    visualData.Save(target);
    target.WriteAggregate(modelBound);
}

int Rendering::VisualImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = visualData.GetStreamingSize();

    size += RENDERING_STREAM_SIZE(modelBound);

    return size;
}

void Rendering::VisualImpl::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    visualData.Register(target);
}

void Rendering::VisualImpl::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    visualData.Link(source);
}

CoreTools::ObjectSharedPtr Rendering::VisualImpl::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    auto object = visualData.GetObjectByName(name);
    if (object != nullptr)
        return object;

    return object;
}

std::vector<CoreTools::ObjectSharedPtr> Rendering::VisualImpl::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    auto visualDataObjects = visualData.GetAllObjectsByName(name);

    std::vector<CoreTools::ObjectSharedPtr> entirelyObjects{};

    entirelyObjects.insert(entirelyObjects.end(), visualDataObjects.begin(), visualDataObjects.end());

    return entirelyObjects;
}

CoreTools::ConstObjectSharedPtr Rendering::VisualImpl::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    auto object = visualData.GetConstObjectByName(name);
    if (object != nullptr)
        return object;

    return object;
}

std::vector<CoreTools::ConstObjectSharedPtr> Rendering::VisualImpl::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    auto visualDataObjects = visualData.GetAllConstObjectsByName(name);

    std::vector<CoreTools::ConstObjectSharedPtr> entirelyObjects{};

    entirelyObjects.insert(entirelyObjects.end(), visualDataObjects.begin(), visualDataObjects.end());

    return entirelyObjects;
}
