///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/18 13:30)

#ifndef MATHEMATICS_OBJECTS3D_TETRAHEDRON3_IMPL_H
#define MATHEMATICS_OBJECTS3D_TETRAHEDRON3_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Objects3D/Plane3.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE Tetrahedron3Impl final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Tetrahedron3Impl<Real>;
        using Math = Math<Real>;
        using Plane3 = Plane3<Real>;
        using Vector3D = Vector3D<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using ContainerType = std::vector<Vector3D>;
        using IndicesType = std::vector<int>;
        using PlaneContainerType = std::vector<Plane3>;

    public:
        // 该四面体被表示为四个顶点的数组：V0，V1，V2和V3。
        // 顶点被排序，使得由四面体外的观察者观察时，
        // 三角形的面是被逆时针排序的三角形：
        //   面 0 = <V[0],V[2],V[1]>
        //   面 1 = <V[0],V[1],V[3]>
        //   面 2 = <V[0],V[3],V[2]>
        //   面 3 = <V[1],V[2],V[3]>

        Tetrahedron3Impl(const Vector3D& vertex0, const Vector3D& vertex1,
                         const Vector3D& vertex2, const Vector3D& vertex3) noexcept;

        explicit Tetrahedron3Impl(const ContainerType& vertex);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector3D GetVertex(int index) const;
        void SetVertex(int index, const Vector3D& vertex);

        // 获取顶点索引在指定的面。
        [[nodiscard]] static IndicesType GetFaceIndices(int face);

        // 构造四面体面的平面。
        // 该四面具有外部指向的法向量。
        // 平面索引是同前面的GetFaceIndices返回的索引相同。
        [[nodiscard]] PlaneContainerType GetPlanes() const;

    private:
        constexpr static auto sm_VertexSize = 4;

        using ArrayType = std::array<Vector3D, sm_VertexSize>;

    private:
        ArrayType m_Vertex;
    };
}

#endif  // MATHEMATICS_OBJECTS3D_TETRAHEDRON3_IMPL_H
