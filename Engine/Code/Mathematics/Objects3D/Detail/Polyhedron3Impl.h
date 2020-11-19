///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/17 18:08)

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
        // 调用者负责确保网格代表一个简单的多面体
        // （二维流形与球体的拓扑，非自相交的拓扑结构）。
        // 三角形面，从网格外观察时必须逆时针顺序。

        Polyhedron3Impl(const VerticesType& vertices, const IndicesType& indices);

#ifdef OPEN_CLASS_INVARIANT
        CLASS_INVARIANT_DECLARE;
        bool IndicesIsValid() const noexcept;
#endif  // OPEN_CLASS_INVARIANT

        // 只读成员访问。
        [[nodiscard]] int GetNumVertices() const;
        [[nodiscard]] const VerticesType GetVertices() const;
        [[nodiscard]] const Vector3D& GetVertex(int index) const;
        [[nodiscard]] int GetNumTriangles() const;
        [[nodiscard]] int GetNumIndices() const;  // = 3 * numTriangles
        [[nodiscard]] const IndicesType GetIndices() const;
        [[nodiscard]] const IndicesType GetTriangle(int index) const;

        // 允许顶点修改。调用者必须确保多面体仍然是简单多面体。
        void SetVertex(int index, const Vector3D& vertex);

        // 计算关于所述多面体的各种信息。
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
