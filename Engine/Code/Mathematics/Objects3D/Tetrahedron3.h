///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/10 16:53)

#ifndef MATHEMATICS_OBJECTS3D_TETRAHEDRON3_H
#define MATHEMATICS_OBJECTS3D_TETRAHEDRON3_H

#include "Mathematics/MathematicsDll.h"

#include "Plane3.h"
#include "Mathematics/Algebra/Vector3.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Tetrahedron3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Tetrahedron3<Real>;
        using Math = Math<Real>;
        using Plane3 = Plane3<Real>;
        using Vector3 = Vector3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using ContainerType = std::vector<Vector3>;
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

        Tetrahedron3(const Vector3& vertex0,
                     const Vector3& vertex1,
                     const Vector3& vertex2,
                     const Vector3& vertex3) noexcept;

        explicit Tetrahedron3(const ContainerType& container);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector3 GetVertex(int index) const;
        void SetVertex(int index, const Vector3& vertex);

        // 获取顶点索引在指定的面。
        NODISCARD static IndicesType GetFaceIndices(int face);

        // 构造四面体面的平面。
        // 该四面具有外部指向的法向量。
        // 平面索引是同前面的GetFaceIndices返回的索引相同。
        NODISCARD PlaneContainerType GetPlanes() const;

        NODISCARD Tetrahedron3 GetMove(Real t, const Vector3& velocity) const;

    private:
        constexpr static auto vertexSize = 4;

        using ArrayType = std::array<Vector3, vertexSize>;

    private:
        ArrayType vertexs;
    };

    using Tetrahedron3F = Tetrahedron3<float>;
    using Tetrahedron3D = Tetrahedron3<double>;
}

#endif  // MATHEMATICS_OBJECTS3D_TETRAHEDRON3_H
