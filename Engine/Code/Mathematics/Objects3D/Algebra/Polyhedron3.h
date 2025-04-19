///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/26 16:21)

#ifndef MATHEMATICS_OBJECTS_3D_ALGEBRA_POLYHEDRON3_H
#define MATHEMATICS_OBJECTS_3D_ALGEBRA_POLYHEDRON3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector/Vector3.h"

#include <set>

/// Polyhedron3对象表示一个简单的多面体。
/// 'vertexPool'数组可以包含多于定义多面体所需的点，
/// 这允许顶点池与多个多面体关联。
/// 因此，程序员必须确保顶点池在任何依赖于该池的Polyhedron3对象存在期间都持续存在。
/// 多面体索引的数量为'numIndices'，必须大于等于6。
/// 'indices'数组引用'vertexPool'中形成三角形面的点，
/// 因此，'numIndices'必须是3的倍数。
/// 顶点的数量是'indices'中唯一元素的数量，并在构造过程中确定。
/// 程序员应确保多面体是简单的。
/// 无论多面体的三角形是顺时针还是逆时针，几何查询都是有效的。
///
/// 注意：不提供比较运算符。相等多面体的语义复杂且（目前）没有用处。
/// 顶点池可以不同，索引不匹配，但它们引用的顶点可以匹配。
/// 即使有共享的顶点池，索引也可以被排列，
/// 导致在抽象上相同的多面体，但数据结构不匹配。
namespace Mathematics::Algebra
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class Polyhedron3
    {
    public:
        using ClassType = Polyhedron3<Real>;

        using MathType = Math<Real>;
        using Vector3Type = Vector3<Real>;
        using VertexPool = std::vector<Vector3Type>;
        using ConstVertexPoolSharedPtr = std::shared_ptr<const VertexPool>;
        using ConstVertexPoolWeakPtr = std::weak_ptr<const VertexPool>;
        using UniqueIndices = std::set<int>;
        using Indices = std::vector<int>;

    public:
        /// 构造函数在满足以下条件时成功执行：
        /// 'numIndices >= 12'（至少4个三角形），
        /// 'vertexPool'和'indices'不为空；
        /// 我们无法测试输入数组中是否有有效的元素数量。
        /// 'indices'会被复制，但'vertexPool'不会被复制。
        /// 如果构造函数失败，则抛出异常。
        Polyhedron3(const ConstVertexPoolSharedPtr& vertexPool,
                    const Indices& indices,
                    bool counterClockwise);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstVertexPoolSharedPtr GetVertexPool() const;
        NODISCARD UniqueIndices GetUniqueIndices() const;
        NODISCARD Indices GetIndices() const;
        NODISCARD bool CounterClockwise() const noexcept;

        /// 几何查询。
        NODISCARD Vector3Type ComputeVertexAverage() const;
        NODISCARD Real ComputeSurfaceArea() const;
        NODISCARD Real ComputeVolume() const;

    private:
        ConstVertexPoolWeakPtr vertexPool;
        UniqueIndices uniqueIndices;
        Indices indices;
        bool counterClockwise;
    };
}

#endif  // MATHEMATICS_OBJECTS_3D_ALGEBRA_POLYHEDRON3_H
