/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/04 13:36)

#include "Rendering/RenderingExport.h"

#include "Visual.h"
#include "Flags/VisualFlags.h"
#include "Detail/VisualImpl.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/Vector3Tools.h"
#include "Mathematics/Distance/Distance3D/DistanceLine3Segment3Detail.h"
#include "Mathematics/Distance/Distance3D/DistancePoint3Line3Detail.h"
#include "Mathematics/Distance/DistanceResultDetail.h"
#include "Mathematics/Intersection/Intersection3D/StaticFindIntersectorLine3Triangle3Detail.h"
#include "Mathematics/Objects3D/Triangle3Detail.h"
#include "Rendering/Picking/PickRecord.h"
#include "Rendering/Resources/Flags/DataFormatType.h"
#include "Rendering/Visibility/Culler.h"

#include <thread>

using System::operator&;

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Visual)

CORE_TOOLS_RTTI_DEFINE(Rendering, Visual);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Visual);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, Visual);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, Visual)

Rendering::Visual::Visual(const std::string& name)
    : ParentType{ name }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Visual::Visual(const std::string& name, Visual& visual)
    : ParentType{ name }, impl{ visual.GetVertexBuffer(), visual.GetIndexBuffer() }
{
    ClassType::UpdateModelSpace(VisualUpdateType::ModelBoundOnly);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Visual::Visual(const std::string& name, const VertexBufferSharedPtr& vertexBuffer, const IndexBufferSharedPtr& indexBuffer)
    : ParentType{ name }, impl{ vertexBuffer, indexBuffer }
{
    ClassType::UpdateModelSpace(VisualUpdateType::ModelBoundOnly);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Visual::Visual(const std::string& name, const VertexBufferSharedPtr& vertexBuffer, const IndexBufferSharedPtr& indexBuffer, const VisualEffectSharedPtr& visualEffect)
    : ParentType{ name }, impl{ vertexBuffer, indexBuffer, visualEffect }
{
    ClassType::UpdateModelSpace(VisualUpdateType::ModelBoundOnly);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Visual)

Rendering::IndexFormatType Rendering::Visual::GetPrimitiveType() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetPrimitiveType();
}

void Rendering::Visual::SetVertexBuffer(const VertexBufferSharedPtr& vertexBuffer) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetVertexBuffer(vertexBuffer);
}

Rendering::ConstVertexBufferSharedPtr Rendering::Visual::GetConstVertexBuffer() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetConstVertexBuffer();
}

Rendering::VertexBufferSharedPtr Rendering::Visual::GetVertexBuffer() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetVertexBuffer();
}

void Rendering::Visual::SetIndexBuffer(const IndexBufferSharedPtr& indexBuffer) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetIndexBuffer(indexBuffer);
}

Rendering::ConstIndexBufferSharedPtr Rendering::Visual::GetConstIndexBuffer() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetConstIndexBuffer();
}

Rendering::IndexBufferSharedPtr Rendering::Visual::GetIndexBuffer() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetIndexBuffer();
}

const Mathematics::BoundingSphereF& Rendering::Visual::GetModelBound() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetModelBound();
}

Rendering::Visual::BoundingSphere& Rendering::Visual::GetModelBound() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetModelBound();
}

void Rendering::Visual::UpdateModelSpace(VisualUpdateType type)
{
    System::UnusedFunction(type);

    UpdateModelBound();
}

void Rendering::Visual::SetVisualEffect(const VisualEffectSharedPtr& visualEffect) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetVisualEffect(visualEffect);
}

Rendering::ConstVisualEffectSharedPtr Rendering::Visual::GetConstVisualEffect() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetConstVisualEffect();
}

Rendering::Visual::VisualEffectSharedPtr Rendering::Visual::GetVisualEffect() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetVisualEffect();
}

void Rendering::Visual::UpdateWorldBound()
{
    RENDERING_CLASS_IS_VALID_1;

    const auto worldTransform = GetWorldTransform();
    const auto worldBound = impl->UpdateWorldBound(worldTransform);

    SetWorldBound(worldBound);
}

void Rendering::Visual::UpdateModelBound()
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->UpdateModelBound();
}

void Rendering::Visual::UpdateModelNormals()
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->UpdateModelNormals();
}

void Rendering::Visual::GetVisibleSet(Culler& culler, const CameraSharedPtr& camera, bool noCull)
{
    RENDERING_CLASS_IS_VALID_1;

    System::UnusedFunction(camera, noCull);

    culler.Insert(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()));
}

Rendering::Visual::Visual(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Visual::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::Visual::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto registerId = ParentType::Register(target);

    if (registerId != 0)
    {
        impl->Register(target);
    }

    return registerId;
}

void Rendering::Visual::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Visual::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);

    impl->Link(source);
}

void Rendering::Visual::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::Visual::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

Rendering::ControllerInterface::ControllerSharedPtr Rendering::Visual::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

CoreTools::ObjectInterface::ObjectInterfaceSharedPtr Rendering::Visual::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return Clone();
}

Rendering::PickRecordContainer Rendering::Visual::ExecuteRecursive(const APoint& origin, const AVector& direction, float tMin, float tMax, int numThreads, float maxDistance)
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto container = PickRecordContainer::Create();

    if (const auto worldBound = GetWorldBound();
        worldBound.TestIntersection(origin, direction, tMin, tMax))
    {
        const auto inverseWorldMatrix = GetWorldTransform().GetInverseMatrix();

        auto lineDirection = (inverseWorldMatrix * direction).GetVector3();
        lineDirection.Normalize();
        const Line3 line{ (inverseWorldMatrix * origin).GetVector3(), lineDirection };

        const auto vertexBuffer = GetVertexBuffer();
        const VertexBuffer::DataFormatTypeContainer required{ DataFormatType::R32G32B32A32Float, DataFormatType::R32G32B32Float };

        const auto positions = vertexBuffer->GetChannel(VertexFormatFlags::Semantic::Position, 0, required);

        const auto vStride = vertexBuffer->GetElementSize();
        const auto indexBuffer = GetIndexBuffer();
        const auto primitiveType = indexBuffer->GetPrimitiveType();
        if ((primitiveType & IndexFormatType::HasTriangles) != IndexFormatType::None)
        {
            container.InsertPickRecord(PickTriangles(positions, vStride, indexBuffer, line, numThreads, tMin, tMax, origin));
        }
        else if ((primitiveType & IndexFormatType::HasSegments) != IndexFormatType::None)
        {
            container.InsertPickRecord(PickSegments(positions, vStride, *indexBuffer, line, tMin, tMax, maxDistance, origin));
        }
        else if ((primitiveType & IndexFormatType::HasPoints) != IndexFormatType::None)
        {
            container.InsertPickRecord(PickPoints(positions, vStride, *indexBuffer, line, tMin, tMax, maxDistance, origin));
        }
    }

    return container;
}

Rendering::PickRecordContainer Rendering::Visual::PickTriangles(const SpanIterator& positions,
                                                                int vStride,
                                                                const IndexBufferSharedPtr& indexBuffer,
                                                                const Line3& line,
                                                                int numThreads,
                                                                float tMin,
                                                                float tMax,
                                                                const APoint& origin)
{
    auto container = PickRecordContainer::Create();

    auto const firstTriangle = indexBuffer->GetFirstPrimitive();
    auto const numTriangles = indexBuffer->GetNumActivePrimitives();
    numThreads = std::min(numTriangles, numThreads);

    if (1 < numThreads)
    {
        const auto numPerThread = numTriangles / numThreads;
        std::vector<int> iMin{};
        std::vector<int> iMax{};
        for (auto t = 0; t < numThreads; ++t)
        {
            iMin.emplace_back(firstTriangle + t * numPerThread);
            iMax.emplace_back(iMin.at(t) + numPerThread - 1);
        }
        const auto endIndex = numThreads - 1;
        iMax.at(endIndex) = firstTriangle + numTriangles - 1;

        std::vector<std::thread> process{};
        std::vector threadOutputs(numThreads, PickRecordContainer::Create());
        for (auto t = 0; t < numThreads; ++t)
        {
            const auto i0 = iMin.at(t);
            const auto i1 = iMax.at(t);
            process.emplace_back(std::thread([this, t, positions, vStride, indexBuffer, line, i0, i1, tMin, tMax, origin, &threadOutputs]() {
                PickTriangles(positions, vStride, *indexBuffer, line, i0, i1, tMin, tMax, threadOutputs.at(t), origin);
            }));
        }

        for (auto t = 0; t < numThreads; ++t)
        {
            process.at(t).join();
            container.InsertPickRecord(threadOutputs.at(t));
        }
    }
    else
    {
        PickTriangles(positions, vStride, *indexBuffer, line, firstTriangle, firstTriangle + numTriangles - 1, tMin, tMax, container, origin);
    }

    return container;
}

void Rendering::Visual::PickTriangles(const SpanIterator& positions,
                                      int vStride,
                                      const IndexBuffer& indexBuffer,
                                      const Line3& line,
                                      int i0,
                                      int i1,
                                      float tMin,
                                      float tMax,
                                      PickRecordContainer& output,
                                      const APoint& origin)
{
    const auto isIndexed = indexBuffer.IsIndexed();
    const auto primitiveType = indexBuffer.GetPrimitiveType();
    for (auto i = i0; i <= i1; ++i)
    {
        auto v0 = 0;
        auto v1 = 0;
        auto v2 = 0;
        if (isIndexed)
        {
            const auto triangleType = indexBuffer.GetTriangle(i);

            v0 = get<0>(triangleType);
            v1 = get<1>(triangleType);
            v2 = get<2>(triangleType);
        }
        else if (primitiveType == IndexFormatType::TriangleMesh)
        {
            v0 = 3 * i;
            v1 = v0 + 1;
            v2 = v0 + 2;
        }
        else  // primitiveType == IndexFormatType::TriangleStrip
        {
            const auto offset = (i & 1);
            v0 = i + offset;
            v1 = i + 1 + offset;
            v2 = i + 2 - offset;
        }

        const auto p0 = positions.GetValue<float, 3>(v0 * vStride);
        const auto p1 = positions.GetValue<float, 3>(v1 * vStride);
        const auto p2 = positions.GetValue<float, 3>(v2 * vStride);

        const Triangle3 triangle{ Vector3{ p0 }, Vector3{ p1 }, Vector3{ p2 } };

        if (Mathematics::StaticFindIntersectorLine3Triangle3 query{ line, triangle };
            query.IsIntersection() && tMin <= query.GetLineParameter() && query.GetLineParameter() <= tMax)
        {
            APoint linePoint{ query.GetPoint() };

            linePoint = GetWorldTransform() * linePoint;

            PickRecord record{ boost::polymorphic_pointer_cast<Visual>(shared_from_this()),
                               primitiveType,
                               i,
                               PickRecord::VertexIndexType{ v0, v1, v2 },
                               query.GetLineParameter(),
                               linePoint,
                               PickRecord::BarycentricType{ query.GetTriangleBary0(), query.GetTriangleBary1(), query.GetTriangleBary2() },
                               linePoint,
                               (linePoint - origin).Length(),
                               (linePoint - origin).Length(),
                               (linePoint - linePoint).Length() };

            output.InsertPickRecord(record);
        }
    }
}

Rendering::PickRecordContainer Rendering::Visual::PickSegments(const SpanIterator& positions,
                                                               int vStride,
                                                               const IndexBuffer& indexBuffer,
                                                               const Line3& line,
                                                               float tMin,
                                                               float tMax,
                                                               float maxDistance,
                                                               const APoint& origin)
{
    auto container = PickRecordContainer::Create();

    const auto firstSegment = indexBuffer.GetFirstPrimitive();
    const auto numSegments = indexBuffer.GetNumActivePrimitives();
    const auto isIndexed = indexBuffer.IsIndexed();
    const auto primitiveType = indexBuffer.GetPrimitiveType();
    for (auto i = firstSegment; i < firstSegment + numSegments; ++i)
    {
        auto v0 = 0;
        auto v1 = 0;
        if (isIndexed)
        {
            const auto segmentType = indexBuffer.GetSegment(i);

            v0 = get<0>(segmentType);
            v1 = get<1>(segmentType);
        }
        else if (primitiveType == IndexFormatType::PolygonSegmentDisjoint)
        {
            v0 = 2 * i;
            v1 = v0 + 1;
        }
        else  // primitiveType == IndexFormatType::PolygonSegmentContiguous
        {
            v0 = i;
            v1 = v0 + 1;
        }
        const auto p0 = positions.GetValue<float, 3>(v0 * vStride);
        const auto p1 = positions.GetValue<float, 3>(v1 * vStride);

        const Segment3 segment{ Vector3{ p0 }, Vector3{ p1 } };

        Mathematics::DistanceLine3Segment3 query{ line, segment };

        if (const auto result = query.GetSquared();
            result.GetDistance() <= maxDistance && tMin <= result.GetLhsParameter() && result.GetLhsParameter() <= tMax)
        {
            const APoint linePoint{ result.GetLhsClosestPoint() };
            const APoint primitivePoint{ result.GetRhsClosestPoint() };

            PickRecord record{ boost::polymorphic_pointer_cast<Visual>(shared_from_this()),
                               primitiveType,
                               i,
                               PickRecord::VertexIndexType{ v0, v1, -1 },
                               result.GetLhsParameter(),
                               linePoint,
                               PickRecord::BarycentricType{ 1.0f - result.GetRhsParameter(), result.GetRhsParameter(), 0.0f },
                               primitivePoint,
                               (linePoint - origin).Length(),
                               (primitivePoint - origin).Length(),
                               (linePoint - primitivePoint).Length() };

            container.InsertPickRecord(record);
        }
    }

    return container;
}

Rendering::PickRecordContainer Rendering::Visual::PickPoints(const SpanIterator& positions,
                                                             int vStride,
                                                             const IndexBuffer& indexBuffer,
                                                             const Line3& line,
                                                             float tMin,
                                                             float tMax,
                                                             float maxDistance,
                                                             const APoint& origin)
{
    auto container = PickRecordContainer::Create();

    const auto firstPoint = indexBuffer.GetFirstPrimitive();
    const auto numPoints = indexBuffer.GetNumActivePrimitives();
    const auto isIndexed = indexBuffer.IsIndexed();
    for (auto i = firstPoint; i < firstPoint + numPoints; ++i)
    {
        auto v = 0;
        if (isIndexed)
        {
            v = indexBuffer.GetPoint(i);
        }
        else
        {
            v = i;
        }

        const auto p = positions.GetValue<float, 3>(v * vStride);

        Mathematics::DistancePoint3Line3 query{ Vector3{ p }, line };

        if (const auto result = query.GetSquared();
            result.GetDistance() <= maxDistance && tMin <= result.GetLhsParameter() && result.GetLhsParameter() <= tMax)
        {
            APoint linePoint{ result.GetRhsClosestPoint() };
            APoint primitivePoint{ p };

            linePoint = GetWorldTransform() * linePoint;
            primitivePoint = GetWorldTransform() * primitivePoint;

            PickRecord record{ boost::polymorphic_pointer_cast<Visual>(shared_from_this()),
                               IndexFormatType::PolygonPoint,
                               i,
                               PickRecord::VertexIndexType{ v, -1, -1 },
                               result.GetLhsParameter(),
                               APoint{ result.GetRhsClosestPoint() },
                               PickRecord::BarycentricType{ 1.0f, 0.0f, 0.0f },
                               APoint{ p },
                               (linePoint - origin).Length(),
                               (primitivePoint - origin).Length(),
                               (linePoint - primitivePoint).Length() };

            container.InsertPickRecord(record);
        }
    }

    return container;
}