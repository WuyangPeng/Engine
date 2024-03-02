///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/26 17:11)

#ifndef MATHEMATICS_OBJECTS_3D_ALGEBRA_TETRAHEDRON3_H
#define MATHEMATICS_OBJECTS_3D_ALGEBRA_TETRAHEDRON3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector/Vector3.h"
#include "Mathematics/Primitives/Hyperplane.h"

/// 该四面体以一个包含四个顶点的数组表示，
/// V[i]表示0 <= i <= 3。
/// 当从四面体外部的观察者视角观察时，
/// 顶点的顺序使得三角形面按逆时针顺序排列：
/// face 0 = <V[0],V[2],V[1]>, face 1 = <V[0],V[1],V[3]>,face 2 = <V[0],V[3],V[2]> 和 face 3 = <V[1],V[2],V[3]>。
/// 规范的四面体的顶点为V[0] = (0,0,0), V[1] = (1,0,0), V[2] = (0,1,0) 和 V[3] = (0,0,1)。
namespace Mathematics::Algebra
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class Tetrahedron3
    {
    public:
        using ClassType = Tetrahedron3<Real>;

        constexpr static auto vertexSize = 4;

        using Math = Math<Real>;
        using Vector3 = Vector3<Real>;
        using ArrayType = std::array<Vector3, vertexSize>;
        using FaceIndexType = std::array<int, 3>;
        using AllFaceIndexType = std::array<int, 12>;
        using EdgeIndexType = std::array<int, 2>;
        using AllEdgeIndexType = std::array<int, 12>;
        using EdgeAugmentedType = std::array<int, 4>;
        using VertexAugmentedType = std::array<int, 4>;
        using Plane3 = Plane3<Real>;
        using Plane3Container = std::array<Plane3, 4>;

    public:
        /// 默认构造函数将顶点设置为(0,0,0), (1,0,0), (0,1,0) 和 (0,0,1)。
        Tetrahedron3() noexcept;
        Tetrahedron3(const Vector3& v0, const Vector3& v1, const Vector3& v2, const Vector3& v3) noexcept;
        explicit Tetrahedron3(const ArrayType& vertex) noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 获取指定面的顶点索引。输入'face'必须位于{0,1,2,3}中。
        NODISCARD static const FaceIndexType& GetFaceIndices(int face);
        NODISCARD static const AllFaceIndexType& GetAllFaceIndices() noexcept;

        /// 获取指定边的顶点索引。输入'edge'必须位于{0,1,2,3,4,5}中。
        NODISCARD static const EdgeIndexType& GetEdgeIndices(int edge);
        NODISCARD static const AllEdgeIndexType& GetAllEdgeIndices() noexcept;

        /// 获取具有适当排序的相邻索引的边的顶点索引。
        /// 输入'edge'必须位于0,1,2,3,4,5}中。
        /// 输出为{v0,v1,v2,v3}，其中边为{v0,v1}。
        /// 共享边的三角形是{v0，v2，v1}和{v0、v1，v3}。
        NODISCARD static const EdgeAugmentedType& GetEdgeAugmented(int edge);

        /// 获取具有适当排序的相邻索引的顶点的增强索引。
        /// 输入'vertex'必须位于{0,1,2,3}中。
        /// 输出为{v0，v1，v2，v3}，
        /// 其中顶点为v0。
        /// 共享顶点的三角形是{v0,v1,v2}, {v0,v2,v3} 和 {v0,v3,v1}。
        NODISCARD static const VertexAugmentedType& GetVertexAugmented(int vertex);

        /// 计算面法线。
        /// 输入'face'必须在 {0,1,2,3}中，
        /// 并对应于面 {{0,2,1},{0,1,3},{0,3,2},{1,2,3}}。
        NODISCARD Vector3 ComputeFaceNormal(int face) const;

        /// 计算边法线，即面向边的2个法线的平均值。
        /// 输入'edge'必须在{0,1,2,3,4,5}中，
        /// 并对应于边{{0,1},{0,2},{0,3},{1,2},{1,3},{2,3}}。
        NODISCARD Vector3 ComputeEdgeNormal(int edge) const;

        /// 计算顶点法线，即共享该顶点的3个面的法线的平均值。
        /// 输入“顶点”必须在{0,1,2,3}中，并且是四面体顶点数组的索引。
        /// 代数表明，顶点法线是与顶点相对的面的负法线。
        NODISCARD Vector3 ComputeVertexNormal(int vertexIndex) const;

        /// 构造面的平面。
        /// 这些平面具有指向外部的法线向量。
        /// 平面索引与前面提到的面索引相同。
        NODISCARD Plane3Container GetPlanes() const;

        NODISCARD Vector3 ComputeCentroid() const;

        NODISCARD bool Equal(const Tetrahedron3& rhs) const;
        NODISCARD bool Less(const Tetrahedron3& rhs) const;

    private:
        ArrayType vertex;
    };

    /// 与支持排序容器的比较。
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator==(const Tetrahedron3<Real>& lhs, const Tetrahedron3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator!=(const Tetrahedron3<Real>& lhs, const Tetrahedron3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator<(const Tetrahedron3<Real>& lhs, const Tetrahedron3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator<=(const Tetrahedron3<Real>& lhs, const Tetrahedron3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator>(const Tetrahedron3<Real>& lhs, const Tetrahedron3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator>=(const Tetrahedron3<Real>& lhs, const Tetrahedron3<Real>& rhs);
}

#endif  // MATHEMATICS_OBJECTS_3D_ALGEBRA_TETRAHEDRON3_H
