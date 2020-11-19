///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/17 18:08)

#ifndef MATHEMATICS_OBJECTS3D_POLYHEDRON3_IMPL_H
#define MATHEMATICS_OBJECTS3D_POLYHEDRON3_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE Polyhedron3Impl final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Polyhedron3Impl<Real>;
        using Math = Math<Real>;
        using Vector3D = Vector3D<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using VerticesType = std::vector<Vector3D>;
        using IndicesType = std::vector<int>;

    public:
        // �����߸���ȷ���������һ���򵥵Ķ�����
        // ����ά��������������ˣ������ཻ�����˽ṹ����
        // �������棬��������۲�ʱ������ʱ��˳��

        Polyhedron3Impl(const VerticesType& vertices, const IndicesType& indices);

#ifdef OPEN_CLASS_INVARIANT
        CLASS_INVARIANT_DECLARE;
        bool IndicesIsValid() const noexcept;
#endif  // OPEN_CLASS_INVARIANT

        // ֻ����Ա���ʡ�
        [[nodiscard]] int GetNumVertices() const;
        [[nodiscard]] const VerticesType GetVertices() const;
        [[nodiscard]] const Vector3D& GetVertex(int index) const;
        [[nodiscard]] int GetNumTriangles() const;
        [[nodiscard]] int GetNumIndices() const;  // = 3 * numTriangles
        [[nodiscard]] const IndicesType GetIndices() const;
        [[nodiscard]] const IndicesType GetTriangle(int index) const;

        // �������޸ġ������߱���ȷ����������Ȼ�Ǽ򵥶����塣
        void SetVertex(int index, const Vector3D& vertex);

        // �����������������ĸ�����Ϣ��
        [[nodiscard]] const Vector3D ComputeVertexAverage() const;
        [[nodiscard]] Real ComputeSurfaceArea() const;
        [[nodiscard]] Real ComputeVolume() const;

    private:
        constexpr static auto sm_TriangleVertexSize = 3;
        constexpr static auto sm_MinVerticesSize = 4;

    private:
        VerticesType m_Vertices;
        IndicesType m_Indices;
    };
}

#endif  // MATHEMATICS_OBJECTS3D_POLYHEDRON3_IMPL_H
