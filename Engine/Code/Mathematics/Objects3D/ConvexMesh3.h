///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/22 19:14)

#ifndef MATHEMATICS_OBJECTS_3D_CONVEX_MESH3_H
#define MATHEMATICS_OBJECTS_3D_CONVEX_MESH3_H

#include "Mathematics/MathematicsDll.h"

#include "Objects3DFwd.h"
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector/Vector3.h"

namespace Mathematics
{
    /// ConvexMesh3的客户端负责填充顶点和索引，
    /// 以便生成的网格表示凸多面体。
    ///   1. 多面体必须使用“顶点”的所有元素。
    ///   2. 从多面体外部观察时，三角形面必须具有相同的手征。
    ///      当从多面体外部观察时，它们都是逆时针方向的或都是顺时针方向的。
    ///   3. Real类型必须是支持除法的任意精度类型。
    ///   4. 多面体可以是退化的。下面列出了所有的可能性。
    ///        点:
    ///          vertices.size() == 1, triangles.size() = 0
    ///
    ///        线段:
    ///          vertices.size() == 2, triangles.size() == 0
    ///
    ///        凸多边形:
    ///          vertices.size() >= 3, triangles.size() > 0 并且顶点共面
    ///
    ///       凸多面体:
    ///          vertices.size() >= 3, triangles.size() > 0 并且顶点不共面
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class ConvexMesh3
    {
    public:
        using ClassType = ConvexMesh3<Real>;

        using Vertex = Algebra::Vector3<Real>;
        using Triangle = std::array<int, 3>;
        using VertexContainer = std::vector<Vertex>;
        using TriangleContainer = std::vector<Triangle>;

    public:
        ConvexMesh3() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConvexMesh3Type GetConfiguration() const noexcept;
        NODISCARD VertexContainer GetVertices() const;
        NODISCARD TriangleContainer GetTriangles() const;

        void SetConfiguration(ConvexMesh3Type aConfiguration) noexcept;
        void SetVertices(const VertexContainer& aVertices);
        void SetTriangles(const TriangleContainer& aTriangles);

    private:
        ConvexMesh3Type configuration;
        VertexContainer vertices;
        TriangleContainer triangles;
    };
}

#endif  // MATHEMATICS_OBJECTS_3D_CONVEX_MESH3_H
