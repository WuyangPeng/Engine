///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/23 13:16)

#ifndef MATHEMATICS_OBJECTS_3D_ALGEBRA_CONVEX_POLYHEDRON3_H
#define MATHEMATICS_OBJECTS_3D_ALGEBRA_CONVEX_POLYHEDRON3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector/Vector3.h"
#include "Mathematics/Algebra/Vector/Vector4.h"
#include "Mathematics/Primitives/AlignedBox.h"

namespace Mathematics::Algebra
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class ConvexPolyhedron3
    {
    public:
        using ClassType = ConvexPolyhedron3<Real>;

        using AlignedBox3 = AlignedBox3<Real>;
        using Vector3 = Vector3<Real>;
        using Vector4 = Vector4<Real>;
        using VerticesType = std::vector<Vector3>;
        using IndicesType = std::vector<int>;
        using PlanesType = std::vector<Vector4>;

    public:
        /// 此类所代表的凸多面体具有从多面体外部观察时逆时针排列的三角形面。
        /// 没有试图验证多面体是凸的；
        /// 调用方负责强制执行此操作。
        /// 当顶点数量至少为4并且索引数量至少为12时，构造函数成功。
        ///
        /// 为了支持使用凸二次规划制定的几何算法（例如计算从一个点到凸多面体的距离），
        /// 有必要知道面的平面和轴对齐的边界框。
        /// 如果需要面或长方体，请将“true”传递给相应的参数。
        /// 生成平面时，法线不会创建为单位长度，以支持使用精确有理算术的查询。
        /// 如果面的法线为N = (n0,n1,n2) ，并且V是该面的顶点，
        /// 则该平面为Dot(N,X-V) = 0，并存储为Dot(n0,n1,n2,-Dot(N,V))。
        /// 法线被计算为外部指向。
        ConvexPolyhedron3() noexcept;

        ConvexPolyhedron3(VerticesType vertices, IndicesType indices, bool wantPlanes, bool wantAlignedBox);

        CLASS_INVARIANT_DECLARE;

        NODISCARD VerticesType GetVertices() const;
        NODISCARD IndicesType GetIndices() const;
        NODISCARD PlanesType GetPlanes() const;
        NODISCARD AlignedBox3 GetAlignedBox() const noexcept;

        void SetVertices(const VerticesType& aVertices, bool wantPlanes, bool wantAlignedBox);
        void SetIndices(const IndicesType& aIndices, bool wantPlanes, bool wantAlignedBox);

    private:
        /// 如果修改顶点或索引，
        /// 并且希望计算新的平面或对齐的长方体，
        /// 请调用这些函数。
        void GeneratePlanes();

        void GenerateAlignedBox();

    private:
        VerticesType vertices;
        IndicesType indices;
        PlanesType planes;
        AlignedBox3 alignedBox;
    };
}

#endif  // MATHEMATICS_OBJECTS_3D_ALGEBRA_CONVEX_POLYHEDRON3_H
