///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/03 17:15)

#include "Rendering/RenderingExport.h"

#include "PickRecord.h"
#include "PickRecordContainer.h"
#include "Triangles.h"
#include "Detail/NormalDerivatives.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Intersection/Intersection3D/StaticFindIntersectorLine3Triangle3Detail.h"
#include "Mathematics/Objects3D/Line3Detail.h"
#include "Mathematics/Objects3D/Triangle3Detail.h"
#include "Rendering/Renderers/RendererManager.h"

using std::vector;

CORE_TOOLS_RTTI_DEFINE(Rendering, Triangles);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Triangles);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, Triangles);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, Triangles);

Rendering::Triangles::Triangles(VisualPrimitiveType type)
    : ParentType{ type }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Triangles::Triangles(VisualPrimitiveType type, const VertexFormatSharedPtr& vertexformat, const VertexBufferSharedPtr& vertexbuffer, const IndexBufferSharedPtr& indexbuffer)
    : ParentType{ type, vertexformat, vertexbuffer, indexbuffer }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Triangles)

Rendering::TrianglePosition Rendering::Triangles::GetModelTriangle(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto triangleIndex = GetTriangle(index);
    const auto firstIndex = triangleIndex.GetFirstIndex();
    const auto secondIndex = triangleIndex.GetSecondIndex();
    const auto thirdIndex = triangleIndex.GetThirdIndex();

    TrianglePosition trianglePosition{ APoint{}, APoint{}, APoint{} };

    return trianglePosition;
}

Rendering::TrianglePosition Rendering::Triangles::GetWorldTriangle(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto trianglePosition = GetModelTriangle(index);

    const auto firstPosition = GetWorldTransform() * trianglePosition.GetFirstPosition();
    const auto secondPosition = GetWorldTransform() * trianglePosition.GetSecondPosition();
    const auto thirdPosition = GetWorldTransform() * trianglePosition.GetThirdPosition();

    return TrianglePosition{ firstPosition, secondPosition, thirdPosition };
}

int Rendering::Triangles::GetNumVertices() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return GetConstVertexBuffer()->GetNumElements();
}

Rendering::Triangles::Vector3D Rendering::Triangles::GetPosition(int vertexIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto index = GetConstVertexFormat()->GetIndex(VertexFormatFlags::Semantic::Position);
    if (0 <= index)
    {
        auto positions = GetConstVertexBuffer()->GetData(GetConstVertexFormat()->GetOffset(index));
        auto stride = GetConstVertexFormat()->GetStride();
        const auto index0 = vertexIndex * stride;

        positions += index0;

        return Vector3D{ positions.Increase<float>(), positions.Increase<float>(), positions.Increase<float>() };
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("GetPosition 错误！"s));
    }
}

void Rendering::Triangles::UpdateModelSpace(VisualUpdateType type)
{
    RENDERING_CLASS_IS_VALID_1;

    UpdateModelBound();

    if (type == VisualUpdateType::ModelBoundOnly)
    {
        return;
    }

    RENDERER_MANAGE_SINGLETON.UpdateAll(GetConstVertexBuffer());
}

// private
void Rendering::Triangles::UpdateModelNormals(MAYBE_UNUSED const VertexBuffer& vertexBufferAccessor) noexcept
{
}

// private
void Rendering::Triangles::UpdateModelTangentsUseGeometry(const VertexBuffer& vertexBufferAccessor)
{
    // 计算矩阵的法线的导数。
    NormalDerivatives normalDerivatives{ vertexBufferAccessor };

    const auto numTriangles = GetNumTriangles();

    for (auto index = 0; index < numTriangles; ++index)
    {
        // 获取三角形的顶点索引。
        const auto triangleIndex = GetTriangle(index);

        normalDerivatives.ComputeEdge(triangleIndex);
    }

    normalDerivatives.ComputeNormalDerivativesMatrix();

    normalDerivatives.ComputeTangentAndBinormal();
}

// private
void Rendering::Triangles::UpdateModelTangentsUseTextureCoords(MAYBE_UNUSED const VertexBuffer& vertexBufferAccessor)
{
    const auto numTriangles = GetNumTriangles();
    for (auto index = 0; index < numTriangles; ++index)
    {
        // 得到三角形顶点的位置,法线,切线和纹理坐标。
        const auto triangleIndex = GetTriangle(index);

        vector<APoint> localPosition(3);
        vector<AVector> localNormal(3, Mathematics::AVectorF::GetZero());
        vector<AVector> localTangent(3, Mathematics::AVectorF::GetZero());
        vector<Vector2D> localTextureCoord(3);

        for (auto current = 0; current < 3; ++current)
        {
            const auto& currLocTangent = localTangent.at(current);
            if (!Approximate(currLocTangent, Mathematics::AVectorF::GetZero()))
            {
                // 这个顶点已被访问。
                continue;
            }

            // 计算顶点的切线空间。
            const auto& normalVector = localNormal.at(current);
            const auto prev = ((current + 2) % 3);
            const auto next = ((current + 1) % 3);

            auto tangentVector = ComputeTangent(localPosition.at(current),
                                                localTextureCoord.at(current),
                                                localPosition.at(next),
                                                localTextureCoord.at(next),
                                                localPosition.at(prev),
                                                localTextureCoord.at(prev));

            // 投影T到切平面投影表面法线N,然后使其单位长度
            tangentVector -= Dot(normalVector, tangentVector) * normalVector;
            tangentVector.Normalize();

            // 计算双切线B,另一个切线垂直于T。
            const auto bitangentVector = UnitCross(normalVector, tangentVector);

            const auto currentTriangleIndex = triangleIndex[current];
        }
    }
}

// private
Rendering::Triangles::AVector Rendering::Triangles::ComputeTangent(const APoint& position0, const Vector2D& textureCoord0, const APoint& position1, const Vector2D& textureCoord1, const APoint& position2, const Vector2D& textureCoord2)
{
    // 计算顶点P0位置的变化。
    const auto differenceP1P0 = position1 - position0;
    const auto differenceP2P0 = position2 - position0;

    if (Mathematics::MathF::FAbs(differenceP1P0.Length()) < Mathematics::MathF::GetZeroTolerance() ||
        Mathematics::MathF::FAbs(differenceP2P0.Length()) < Mathematics::MathF::GetZeroTolerance())
    {
        // 这个三角形是非常小的，称之为退化退化三角形。
        return Mathematics::AVectorF::GetZero();
    }

    // 计算顶点P0纹理坐标在边缘P1-P0的方向上的变化。
    auto differenceU1U0 = textureCoord1[0] - textureCoord0[0];
    auto differenceV1V0 = textureCoord1[1] - textureCoord0[1];
    if (Mathematics::MathF::FAbs(differenceV1V0) < Mathematics::MathF::GetZeroTolerance())
    {
        // 三角形实际上在纹理坐标v上没有变化。
        if (Mathematics::MathF::FAbs(differenceU1U0) < Mathematics::MathF::GetZeroTolerance())
        {
            // 三角形实际上在纹理坐标u上没有变化。
            // 由于纹理坐标不改变这个三角形，把它当作一个退化参数曲面。
            return Mathematics::AVectorF::GetZero();
        }

        // 变化在所有u上是有效，所以设置切向量为T = dP / du。
        return differenceP1P0 / differenceU1U0;
    }

    // 计算顶点P0纹理坐标在边缘P2-P0的方向上的变化。
    auto differenceU2U0 = textureCoord2[0] - textureCoord0[0];
    auto differenceV2V0 = textureCoord2[1] - textureCoord0[1];
    auto det = differenceV1V0 * differenceU2U0 - differenceV2V0 * differenceU1U0;
    if (Mathematics::MathF::FAbs(det) < Mathematics::MathF::GetZeroTolerance())
    {
        // 三角形顶点是共线的参数空间，所以把它当作一个退化参数曲面。
        return Mathematics::AVectorF::GetZero();
    }

    // 三角形顶点是不共线的参数空间，所以选择切线为
    // dP / du = (dv1 * dP2 - dv2 * dP1) / (dv1 * du2 - dv2 * du1)
    return (differenceV1V0 * differenceP2P0 - differenceV2V0 * differenceP1P0) / det;
}

Rendering::PickRecordContainer Rendering::Triangles::ExecuteRecursive(const APoint& origin, const AVector& direction, float tMin, float tMax) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto container = PickRecordContainer::Create();

    if (GetWorldBound().TestIntersection(origin, direction, tMin, tMax))
    {
        // 将线性组件转换到模型空间坐标。
        const auto worldInverseTransform = GetWorldTransform().GetInverseTransform();
        const auto modelOriginPoint = worldInverseTransform * origin;
        const auto modelOrigin = modelOriginPoint.GetVector3();

        const auto modelDirectionVector = worldInverseTransform * direction;
        const auto modelDirection = modelDirectionVector.GetVector3();

        const Line3 line{ modelOrigin, modelDirection };

        // 计算模型空间三角形的相交。
        const auto numTriangles = GetNumTriangles();
        for (auto i = 0; i < numTriangles; ++i)
        {
            try
            {
                const auto triangleIndex = GetTriangle(i);

                const Triangle3 triangle{ Vector3D{}, Vector3D{}, Vector3D{} };

                Mathematics::StaticFindIntersectorLine3Triangle3<float> intersector{ line, triangle };

                if (intersector.IsIntersection() &&
                    tMin <= intersector.GetLineParameter() &&
                    intersector.GetLineParameter() <= tMax)
                {
                    auto record = PickRecord::Create();

                    record.SetIntersected(boost::polymorphic_pointer_cast<const ClassType>(shared_from_this()));
                    record.SetParameter(intersector.GetLineParameter());
                    record.SetTriangle(i);
                    record.SetBary(intersector.GetTriangleBary0(), intersector.GetTriangleBary1());

                    container.InsertPickRecord(record);
                }
            }
            catch (const CoreTools::Error& error)
            {
                LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
                    << error
                    << LOG_SINGLETON_TRIGGER_ASSERT;
            }
        }
    }

    return container;
}
