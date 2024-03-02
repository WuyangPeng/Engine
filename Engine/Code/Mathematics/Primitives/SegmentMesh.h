///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/03/02 21:18)

#ifndef MATHEMATICS_PRIMITIVES_SEGMENT_MESH_H
#define MATHEMATICS_PRIMITIVES_SEGMENT_MESH_H

#include "Mathematics/MathematicsDll.h"

#include "PrimitivesFwd.h"
#include "Mathematics/Algebra/Vector/Vector.h"

namespace Mathematics
{
    /// “顶点”是包含网格顶点的顶点池。
    /// “索引”是指向“顶点”的索引对，
    /// 每一对表示多义段的一段。
    /// 最后一个构造函数不要求顶点池的所有元素都参与到多义段中。
    /// 多义段是不受限制的。
    /// 它们可以形成一个开放的或封闭的多义词段。
    /// 它们可以在线段的内部点相交。
    /// 线段可以退化，从而使其端点相等。
    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    class SegmentMesh
    {
    public:
        using ClassType = SegmentMesh<N, Real>;

        using Vector = Algebra::Vector<N, Real>;
        using VerticesType = std::vector<Vector>;
        using IndicesType = std::vector<std::array<int, 2>>;

    public:
        SegmentMesh() noexcept;

        /// 使用DISJOINT拓扑创建网格。
        explicit SegmentMesh(const VerticesType& vertices);

        /// 创建具有Contiguous拓扑的网格。
        /// 对于ContiguousOpen拓扑，将isOpen设置为“true”，
        /// 对于ContiguousClosed拓扑，将其设置为“false”。
        SegmentMesh(const VerticesType& vertices, bool isOpen);

        /// 创建具有Indexed拓扑的网格。
        /// 如果调用方确定索引满足所有i的indices[i] < vertices.size() ，则将validateIndices设置为'false'。
        /// 否则，请将validateIndices设置为“true”，以便在内部验证顶点。
        SegmentMesh(const VerticesType& vertices,
                    const IndicesType& indices,
                    bool validateIndices);

        CLASS_INVARIANT_DECLARE;

        /// 成员访问。目前，顶点和索引是只读的。
        /// TODO:允许动态创建网格。
        /// 这需要重新设计，也应用于实现三角形网格基元的类似类。
        NODISCARD TopologyType GetTopology() const;

        NODISCARD VerticesType GetVertices() const;
        NODISCARD IndicesType GetIndices() const;

    private:
        TopologyType topology;
        VerticesType vertices;
        IndicesType indices;
    };

    namespace Algebra
    {
        /// 为方便起见，模板别名。
        template <typename Real>
        using SegmentMesh2 = SegmentMesh<2, Real>;

        template <typename Real>
        using SegmentMesh3 = SegmentMesh<3, Real>;
    }
}

#endif  // MATHEMATICS_PRIMITIVES_SEGMENT_MESH_H
