/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/20 09:55)

#include "Rendering/RenderingExport.h"

#include "VisualImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Rendering/Resources/Flags/DataFormatType.h"

using System::operator&;

Rendering::VisualImpl::VisualImpl() noexcept
    : visualData{}, modelBound{}, visualEffect{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisualImpl::VisualImpl(const VertexFormatSharedPtr& vertexFormat, const VertexBufferSharedPtr& vertexBuffer, const IndexBufferSharedPtr& indexBuffer) noexcept
    : visualData{ vertexFormat, vertexBuffer, indexBuffer }, modelBound{}, visualEffect{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisualImpl::VisualImpl(const VisualImpl& rhs)
    : visualData{ rhs.visualData }, modelBound{ rhs.modelBound }, visualEffect{ rhs.visualEffect.Clone() }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisualImpl& Rendering::VisualImpl::operator=(const VisualImpl& rhs)
{
    RENDERING_CLASS_IS_VALID_9;

    visualData = rhs.visualData;
    modelBound = rhs.modelBound;
    visualEffect.object = rhs.visualEffect.Clone();

    return *this;
}

Rendering::VisualImpl::VisualImpl(VisualImpl&& rhs) noexcept
    : visualData{ std::move(rhs.visualData) }, modelBound{ rhs.modelBound }, visualEffect{ std::move(rhs.visualEffect) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisualImpl& Rendering::VisualImpl::operator=(VisualImpl&& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    visualData = std::move(rhs.visualData);
    modelBound = rhs.modelBound;
    visualEffect = std::move(rhs.visualEffect);

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VisualImpl)

Rendering::IndexFormatType Rendering::VisualImpl::GetPrimitiveType() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return visualData.GetPrimitiveType();
}

Rendering::ConstVertexFormatSharedPtr Rendering::VisualImpl::GetConstVertexFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return visualData.GetConstVertexFormat();
}

Rendering::VisualImpl::BoundingSphere& Rendering::VisualImpl::GetModelBound() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26473)

    return const_cast<Mathematics::BoundingSphereF&>(static_cast<const ClassType*>(this)->GetModelBound());

#include SYSTEM_WARNING_POP
}

Rendering::VisualImpl::BoundingSphere Rendering::VisualImpl::UpdateWorldBound(const Transform& worldTransform) const
{
    RENDERING_CLASS_IS_VALID_9;

    return modelBound.TransformBy(worldTransform);
}

const Rendering::VisualImpl::BoundingSphere& Rendering::VisualImpl::GetModelBound() const noexcept
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

void Rendering::VisualImpl::SetIndexBuffer(const IndexBufferSharedPtr& indexBuffer) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    visualData.SetIndexBuffer(indexBuffer);
}

Rendering::ConstVertexBufferSharedPtr Rendering::VisualImpl::GetConstVertexBuffer() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return visualData.GetConstVertexBuffer();
}

void Rendering::VisualImpl::SetVertexBuffer(const VertexBufferSharedPtr& vertexBuffer) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    visualData.SetVertexBuffer(vertexBuffer);
}

Rendering::VertexFormatSharedPtr Rendering::VisualImpl::GetVertexFormat() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return visualData.GetVertexFormat();
}

void Rendering::VisualImpl::SetVertexFormat(const VertexFormatSharedPtr& vertexFormat) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    visualData.SetVertexFormat(vertexFormat);
}

void Rendering::VisualImpl::SetVisualEffect(const VisualEffectSharedPtr& aVisualEffect) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    visualEffect.object = aVisualEffect;
}

Rendering::ConstVisualEffectSharedPtr Rendering::VisualImpl::GetConstVisualEffect() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return visualEffect.object;
}

Rendering::VisualEffectSharedPtr Rendering::VisualImpl::GetVisualEffect() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return visualEffect.object;
}

void Rendering::VisualImpl::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    visualData.Load(source);
    source.ReadAggregate(modelBound);
    source.ReadObjectAssociated(visualEffect);
}

void Rendering::VisualImpl::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    visualData.Save(target);
    target.WriteAggregate(modelBound);
    target.WriteObjectAssociated(visualEffect);
}

int Rendering::VisualImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = visualData.GetStreamingSize();

    size += RENDERING_STREAM_SIZE(modelBound);
    size += RENDERING_STREAM_SIZE(visualEffect);

    return size;
}

void Rendering::VisualImpl::Register(ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    visualData.Register(target);
    target.Register(visualEffect);
}

void Rendering::VisualImpl::Link(ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    visualData.Link(source);
    source.ResolveLink(visualEffect);
}

CoreTools::ObjectSharedPtr Rendering::VisualImpl::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    if (auto object = visualData.GetObjectByName(name);
        !object->IsNullObject())
    {
        return object;
    }

    else
    {
        return visualEffect->GetObjectByName(name);
    }
}

Rendering::VisualImpl::ObjectSharedPtrContainer Rendering::VisualImpl::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto visualDataObjects = visualData.GetAllObjectsByName(name);
    const auto visualEffectObjects = visualEffect->GetAllObjectsByName(name);

    ObjectSharedPtrContainer entirelyObjects{};

    entirelyObjects.insert(entirelyObjects.end(), visualDataObjects.begin(), visualDataObjects.end());
    entirelyObjects.insert(entirelyObjects.end(), visualEffectObjects.begin(), visualEffectObjects.end());

    return entirelyObjects;
}

CoreTools::ConstObjectSharedPtr Rendering::VisualImpl::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (auto object = visualData.GetConstObjectByName(name);
        !object->IsNullObject())
    {
        return object;
    }

    else
    {
        return visualEffect->GetConstObjectByName(name);
    }
}

Rendering::VisualImpl::ConstObjectSharedPtrContainer Rendering::VisualImpl::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto visualDataObjects = visualData.GetAllConstObjectsByName(name);
    const auto visualEffectObjects = visualEffect->GetAllConstObjectsByName(name);

    ConstObjectSharedPtrContainer entirelyObjects{};

    entirelyObjects.insert(entirelyObjects.end(), visualDataObjects.begin(), visualDataObjects.end());
    entirelyObjects.insert(entirelyObjects.end(), visualEffectObjects.begin(), visualEffectObjects.end());

    return entirelyObjects;
}

void Rendering::VisualImpl::UpdateModelBound()
{
    RENDERING_CLASS_IS_VALID_9;

    const VisualData::DataFormatTypeContainer required{ DataFormatType::R32G32B32Float, DataFormatType::R32G32B32A32Float };

    const auto positions = visualData.GetConstChannel(VertexFormatFlags::Semantic::Position, 0, required);

    const auto vertexBuffer = visualData.GetConstVertexBuffer();

    const auto numElements = vertexBuffer->GetNumElements();
    const auto vertexSize = vertexBuffer->GetElementSize();

    modelBound.ComputeFromData(numElements, vertexSize, positions);
}

void Rendering::VisualImpl::UpdateModelNormals()
{
    RENDERING_CLASS_IS_VALID_9;

    // 获取顶点位置。
    const VisualData::DataFormatTypeContainer required{ DataFormatType::R32G32B32Float, DataFormatType::R32G32B32A32Float };

    const auto positions = visualData.GetConstChannel(VertexFormatFlags::Semantic::Position, 0, required);

    // 获取顶点法线。
    const auto normals = visualData.GetChannel(VertexFormatFlags::Semantic::Normal, 0, required);

    // 获取三角形基本体。
    const auto primitiveType = visualData.GetPrimitiveType();
    if ((primitiveType & IndexFormatType::HasTriangles) == IndexFormatType::Zero)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("没有为点或线段基本体定义法线向量。"))
    }

    const auto vertexBuffer = visualData.GetConstVertexBuffer();
    const auto indexBuffer = visualData.GetIndexBuffer();

    const auto numVertices = vertexBuffer->GetNumElements();
    const auto stride = vertexBuffer->GetElementSize();

    const auto dataSize = CoreTools::GetStreamSize<float>();
    const auto difference = stride - dataSize * Vector3::pointSize;
    if (difference < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("步进值错误。"))
    }

    ClearNormals(normals, numVertices, difference);
    SetNormals(positions, normals, primitiveType, *indexBuffer, stride);
    NormalizeNormals(normals, numVertices, stride);
}

void Rendering::VisualImpl::ClearNormals(SpanIterator normals, const int numVertices, const int difference)
{
    for (auto i = 0; i < numVertices; ++i)
    {
        normals.Increase(0.0f);
        normals.Increase(0.0f);
        normals.Increase(0.0f);

        if (0 < difference)
        {
            normals += difference;
        }
    }
}

void Rendering::VisualImpl::SetNormals(const ConstSpanIterator& positions, SpanIterator normals, IndexFormatType primitiveType, const IndexBuffer& indexBuffer, int stride)
{
    const auto numTriangles = indexBuffer.GetNumPrimitives();
    const auto isIndexed = indexBuffer.IsIndexed();
    for (auto i = 0; i < numTriangles; ++i)
    {
        // 获取三角形的顶点索引。
        IndexBuffer::TriangleType triangle{};
        if (isIndexed)
        {
            triangle = indexBuffer.GetTriangle(i);
        }
        else if (primitiveType == IndexFormatType::TriangleMesh)
        {
            triangle = { 3 * i, 3 * i + 1, 3 * i + 2 };
        }
        else  // primitiveType == TriStrip
        {
            const auto offset = i & 1;
            triangle = { i + offset, i + 1 + offset, i + 2 - offset };
        }

        const auto index0 = std::get<0>(triangle) * stride;
        const auto index1 = std::get<1>(triangle) * stride;
        const auto index2 = std::get<2>(triangle) * stride;

        // 获取顶点位置。
        const Vector3 position0{ positions.GetValue<float, Vector3::pointSize>(index0) };
        const Vector3 position1{ positions.GetValue<float, Vector3::pointSize>(index1) };
        const Vector3 position2{ positions.GetValue<float, Vector3::pointSize>(index2) };

        // 计算三角形法线。此法线的长度用于法线的加权和。
        const auto edge1 = position1 - position0;
        const auto edge2 = position2 - position0;
        const auto normal = Mathematics::Vector3ToolsF::CrossProduct(edge1, edge2);

        // 将三角形法线与顶点的法线和相加。
        Vector3 normal0{ normals.GetValue<float, Vector3::pointSize>(index0) };
        Vector3 normal1{ normals.GetValue<float, Vector3::pointSize>(index1) };
        Vector3 normal2{ normals.GetValue<float, Vector3::pointSize>(index2) };

        normal0 += normal;
        normal1 += normal;
        normal2 += normal;

        normals.SetValue<float, Vector3::pointSize>(index0, normal0.GetCoordinate());
        normals.SetValue<float, Vector3::pointSize>(index1, normal1.GetCoordinate());
        normals.SetValue<float, Vector3::pointSize>(index2, normal2.GetCoordinate());
    }
}

void Rendering::VisualImpl::NormalizeNormals(SpanIterator normals, int numVertices, int stride)
{
    // 顶点法线必须是单位长度向量。
    for (auto i = 0; i < numVertices; ++i)
    {
        const auto index = i * stride;

        Vector3 normal{ normals.GetValue<float, Vector3::pointSize>(index) };

        if (!normal.IsZero())
        {
            normal.Normalize();
        }

        normals.SetValue<float, Vector3::pointSize>(index, normal.GetCoordinate());
    }
}