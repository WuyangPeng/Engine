// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/22 18:28)
#include "Rendering/RenderingExport.h"

#include "PickRecord.h"
#include "PickRecordContainer.h"
#include "Triangles.h"
#include "Detail/NormalDerivatives.h"
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
#include "Rendering/Resources/VertexBufferAccessorDetail.h"

using std::vector;
#include "System/Helper/PragmaWarning.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26451)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26490)
#if defined(TCRE_USE_MSVC)
    #pragma warning(disable : 6305)
#endif  // TCRE_USE_MSVC
#include SYSTEM_WARNING_DISABLE(26490)
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

const Rendering::TrianglePosition Rendering::Triangles::GetModelTriangle(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto triangleIndex = GetTriangle(index);
    const auto firstIndex = triangleIndex.GetFirstIndex();
    const auto secondIndex = triangleIndex.GetSecondIndex();
    const auto thirdIndex = triangleIndex.GetThirdIndex();

    VertexBufferAccessor vertexBufferAccessor{ GetConstVertexFormat(), GetConstVertexBuffer() };

    TrianglePosition trianglePosition{ vertexBufferAccessor.GetPosition<APoint>(firstIndex),
                                       vertexBufferAccessor.GetPosition<APoint>(secondIndex),
                                       vertexBufferAccessor.GetPosition<APoint>(thirdIndex) };

    return trianglePosition;
}

const Rendering::TrianglePosition Rendering::Triangles::GetWorldTriangle(int index) const
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

    auto index = GetConstVertexFormat()->GetIndex(VertexFormatFlags::AttributeUsage::Position);
    if (0 <= index)
    {
        auto positions = GetConstVertexBuffer()->GetReadOnlyData() + GetConstVertexFormat()->GetOffset(index);
        auto stride = GetConstVertexFormat()->GetStride();
        auto firstPosition = reinterpret_cast<const float*>(positions + vertexIndex * stride);
        auto secondPosition = firstPosition + sizeof(float);
        auto thirdPosition = secondPosition + sizeof(float);

        return Vector3D{ *firstPosition, *secondPosition, *thirdPosition };
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("GetPosition ����"s));
    }
}

void Rendering::Triangles::UpdateModelSpace(VisualUpdateType type)
{
    ;

    UpdateModelBound();

    if (type == VisualUpdateType::ModelBoundOnly)
    {
        return;
    }

    VertexBufferAccessor vertexBufferAccessor{ *this };
    if (vertexBufferAccessor.HasNormal())
    {
        UpdateModelNormals(vertexBufferAccessor);
    }

    if (type != VisualUpdateType::Normals)
    {
        if (vertexBufferAccessor.HasTangent() || vertexBufferAccessor.HasBinormal())
        {
            if (type == VisualUpdateType::UseGeometry)
            {
                UpdateModelTangentsUseGeometry(vertexBufferAccessor);
            }
            else
            {
                UpdateModelTangentsUseTextureCoords(vertexBufferAccessor);
            }
        }
    }

    RENDERER_MANAGE_SINGLETON.UpdateAll(GetConstVertexBuffer().get());
}

// private
void Rendering::Triangles::UpdateModelNormals(const VertexBufferAccessor& vertexBufferAccessor)
{
    // �Ӱ��������ƽ���Ȩƽ�����㷨�ߡ�
    GetVertexBuffer()->ClearModelNormals(vertexBufferAccessor);

    const auto numTriangles = GetNumTriangles();
    for (auto index = 0; index < numTriangles; ++index)
    {
        // ��ȡ�����εĶ���������
        const auto triangleIndex = GetTriangle(index);

        // ��ȡ����λ��
        const auto position0 = vertexBufferAccessor.GetPosition<APoint>(triangleIndex.GetFirstIndex());
        const auto position1 = vertexBufferAccessor.GetPosition<APoint>(triangleIndex.GetSecondIndex());
        const auto position2 = vertexBufferAccessor.GetPosition<APoint>(triangleIndex.GetThirdIndex());

        // ���������η��ߡ�������ߵĳ���Ϊ���ߵļ�Ȩ�͡�
        const auto triangleEdge1 = position1 - position0;
        const auto triangleEdge2 = position2 - position0;
        const auto triangleNormal = Cross(triangleEdge1, triangleEdge2);

        // ��������η��ߵ����㷨�ߺ͡�
        GetVertexBuffer()->AddTriangleNormal(vertexBufferAccessor, triangleIndex.GetFirstIndex(), triangleNormal);
        GetVertexBuffer()->AddTriangleNormal(vertexBufferAccessor, triangleIndex.GetSecondIndex(), triangleNormal);
        GetVertexBuffer()->AddTriangleNormal(vertexBufferAccessor, triangleIndex.GetThirdIndex(), triangleNormal);
    }

    // ���㷨�߱����ǵ�λ���ȵ�������
    GetVertexBuffer()->NormalizeModelNormals(vertexBufferAccessor);
}

// private
void Rendering::Triangles::UpdateModelTangentsUseGeometry(const VertexBufferAccessor& vertexBufferAccessor)
{
    // �������ķ��ߵĵ�����
    NormalDerivatives normalDerivatives{ vertexBufferAccessor };

    const auto numTriangles = GetNumTriangles();

    for (auto index = 0; index < numTriangles; ++index)
    {
        // ��ȡ�����εĶ���������
        const auto triangleIndex = GetTriangle(index);

        normalDerivatives.ComputeEdge(triangleIndex);
    }

    normalDerivatives.ComputeNormalDerivativesMatrix();

    normalDerivatives.ComputeTangentAndBinormal();

    const auto numVertices = vertexBufferAccessor.GetNumVertices();
    for (auto index = 0; index < numVertices; ++index)
    {
        if (vertexBufferAccessor.HasTangent())
        {
            const auto tangent = normalDerivatives.GetTangent(index);
            GetVertexBuffer()->SetTriangleTangent(vertexBufferAccessor, index, tangent);
        }

        if (vertexBufferAccessor.HasBinormal())
        {
            const auto binormal = normalDerivatives.GetBinormal(index);
            GetVertexBuffer()->SetTriangleBinormal(vertexBufferAccessor, index, binormal);
        }
    }
}

// private
void Rendering::Triangles::UpdateModelTangentsUseTextureCoords(const VertexBufferAccessor& vertexBufferAccessor)
{
    // ÿ��������Զ�η���,����ֻ�ڵ�һ�η���ʱ�������߿ռ䡣
    // ʹ����������Ϊ��־��������������
    const auto hasTangent = vertexBufferAccessor.HasTangent();

    if (hasTangent)
    {
        GetVertexBuffer()->ClearTangent(vertexBufferAccessor);
    }
    else
    {
        GetVertexBuffer()->ClearBinormal(vertexBufferAccessor);
    }

    const auto numTriangles = GetNumTriangles();
    for (auto index = 0; index < numTriangles; ++index)
    {
        // �õ������ζ����λ��,����,���ߺ��������ꡣ
        const auto triangleIndex = GetTriangle(index);

        vector<APoint> localPosition(3);
        vector<AVector> localNormal(3, Mathematics::AVectorF::GetZero());
        vector<AVector> localTangent(3, Mathematics::AVectorF::GetZero());
        vector<Vector2D> localTextureCoord(3);

        for (auto current = 0; current < 3; ++current)
        {
            const auto currentTriangleIndex = triangleIndex[current];
            localPosition[current] = vertexBufferAccessor.GetPosition<APoint>(currentTriangleIndex);
            localNormal[current] = vertexBufferAccessor.GetNormal<AVector>(currentTriangleIndex);
            localTangent[current] = (hasTangent ? vertexBufferAccessor.GetTangent<AVector>(currentTriangleIndex) : vertexBufferAccessor.GetBinormal<AVector>(currentTriangleIndex));
            localTextureCoord[current] = vertexBufferAccessor.GetTextureCoord<Vector2D>(0, currentTriangleIndex);
        }

        for (auto current = 0; current < 3; ++current)
        {
            const auto& currLocTangent = localTangent[current];
            if (!Approximate(currLocTangent, Mathematics::AVectorF::GetZero()))
            {
                // ��������ѱ����ʡ�
                continue;
            }

            // ���㶥������߿ռ䡣
            const auto& normalVector = localNormal[current];
            const auto prev = ((current + 2) % 3);
            const auto next = ((current + 1) % 3);

            auto tangentVector = ComputeTangent(localPosition[current], localTextureCoord[current],
                                                localPosition[next], localTextureCoord[next],
                                                localPosition[prev], localTextureCoord[prev]);

            // ͶӰT����ƽ��ͶӰ���淨��N,Ȼ��ʹ�䵥λ����
            tangentVector -= Dot(normalVector, tangentVector) * normalVector;
            tangentVector.Normalize();

            // ����˫����B,��һ�����ߴ�ֱ��T��
            const auto bitangentVector = UnitCross(normalVector, tangentVector);

            const auto currentTriangleIndex = triangleIndex[current];
            if (vertexBufferAccessor.HasTangent())
            {
                localTangent[current] = tangentVector;

                if (vertexBufferAccessor.HasBinormal())
                {
                    GetVertexBuffer()->SetTriangleTangent(vertexBufferAccessor, currentTriangleIndex, bitangentVector);
                }
            }
            else
            {
                GetVertexBuffer()->SetTriangleBinormal(vertexBufferAccessor, currentTriangleIndex, tangentVector);
            }
        }
    }
}

// private
const Rendering::Triangles::AVector Rendering::Triangles::ComputeTangent(const APoint& position0, const Vector2D& textureCoord0, const APoint& position1, const Vector2D& textureCoord1, const APoint& position2, const Vector2D& textureCoord2)
{
    // ���㶥��P0λ�õı仯��
    const auto differenceP1P0 = position1 - position0;
    const auto differenceP2P0 = position2 - position0;

    if (Mathematics::MathF::FAbs(differenceP1P0.Length()) < Mathematics::MathF::GetZeroTolerance() ||
        Mathematics::MathF::FAbs(differenceP2P0.Length()) < Mathematics::MathF::GetZeroTolerance())
    {
        // ����������Ƿǳ�С�ģ���֮Ϊ�˻��˻������Ρ�
        return Mathematics::AVectorF::GetZero();
    }

    // ���㶥��P0���������ڱ�ԵP1-P0�ķ����ϵı仯��
    auto differenceU1U0 = textureCoord1[0] - textureCoord0[0];
    auto differenceV1V0 = textureCoord1[1] - textureCoord0[1];
    if (Mathematics::MathF::FAbs(differenceV1V0) < Mathematics::MathF::GetZeroTolerance())
    {
        // ������ʵ��������������v��û�б仯��
        if (Mathematics::MathF::FAbs(differenceU1U0) < Mathematics::MathF::GetZeroTolerance())
        {
            // ������ʵ��������������u��û�б仯��
            // �����������겻�ı���������Σ���������һ���˻��������档
            return Mathematics::AVectorF::GetZero();
        }

        // �仯������u������Ч����������������ΪT = dP / du��
        return differenceP1P0 / differenceU1U0;
    }

    // ���㶥��P0���������ڱ�ԵP2-P0�ķ����ϵı仯��
    auto differenceU2U0 = textureCoord2[0] - textureCoord0[0];
    auto differenceV2V0 = textureCoord2[1] - textureCoord0[1];
    auto det = differenceV1V0 * differenceU2U0 - differenceV2V0 * differenceU1U0;
    if (Mathematics::MathF::FAbs(det) < Mathematics::MathF::GetZeroTolerance())
    {
        // �����ζ����ǹ��ߵĲ����ռ䣬���԰�������һ���˻��������档
        return Mathematics::AVectorF::GetZero();
    }

    // �����ζ����ǲ����ߵĲ����ռ䣬����ѡ������Ϊ
    // dP / du = (dv1 * dP2 - dv2 * dP1) / (dv1 * du2 - dv2 * du1)
    return (differenceV1V0 * differenceP2P0 - differenceV2V0 * differenceP1P0) / det;
}

Rendering::PickRecordContainer Rendering::Triangles::ExecuteRecursive(const APoint& origin, const AVector& direction, float tMin, float tMax) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto container = PickRecordContainer::Create();

    if (GetWorldBound().TestIntersection(origin, direction, tMin, tMax))
    {
        // ���������ת����ģ�Ϳռ����ꡣ
        const auto worldInverseTransform = GetWorldTransform().GetInverseTransform();
        const auto modelOriginPoint = worldInverseTransform * origin;
        const auto modelOrigin = modelOriginPoint.GetVector3();

        const auto modelDirectionVector = worldInverseTransform * direction;
        const auto modelDirection = modelDirectionVector.GetVector3();

        const Line3 line{ modelOrigin, modelDirection };

        // ��ȡλ�����ݡ�
        VertexBufferAccessor vertexBufferAccessor{ GetConstVertexFormat(), GetConstVertexBuffer() };

        // ����ģ�Ϳռ������ε��ཻ��
        const auto numTriangles = GetNumTriangles();
        for (auto i = 0; i < numTriangles; ++i)
        {
            try
            {
                const auto triangleIndex = GetTriangle(i);

                auto vertex0 = vertexBufferAccessor.GetPosition<Vector3D>(triangleIndex.GetFirstIndex());
                auto vertex1 = vertexBufferAccessor.GetPosition<Vector3D>(triangleIndex.GetSecondIndex());
                auto vertex2 = vertexBufferAccessor.GetPosition<Vector3D>(triangleIndex.GetThirdIndex());
                const Triangle3 triangle{ vertex0, vertex1, vertex2 };

                Mathematics::StaticFindIntersectorLine3Triangle3<float> intersector{ line, triangle };

                if (intersector.IsIntersection() && tMin <= intersector.GetLineParameter() &&
                    intersector.GetLineParameter() <= tMax)  //&& SMART_POINTER_SINGLETON.IsSmartPointer(this))
                {
                    auto record = PickRecord::Create();

                    record.SetIntersected(ConstSpatialSharedPtr(this));
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
                    << CoreTools::LogAppenderIOManageSign::TriggerAssert
                    << CoreTools::LogAppenderIOManageSign::Refresh;
            }
        }
    }

    return container;
}

#include STSTEM_WARNING_POP