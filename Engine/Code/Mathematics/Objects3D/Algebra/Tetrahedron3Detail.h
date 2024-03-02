///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/26 17:11)

#ifndef MATHEMATICS_OBJECTS_3D_ALGEBRA_TETRAHEDRON3_DETAIL_H
#define MATHEMATICS_OBJECTS_3D_ALGEBRA_TETRAHEDRON3_DETAIL_H

#include "Tetrahedron3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector/Vector3Detail.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::Algebra::Tetrahedron3<Real>::Tetrahedron3() noexcept
    : vertex{ Vector3{}, Vector3{ Math::GetValue(1), Math::GetValue(0), Math::GetValue(0) }, Vector3{ Math::GetValue(0), Math::GetValue(1), Math::GetValue(0) }, Vector3{ Math::GetValue(0), Math::GetValue(0), Math::GetValue(1) } }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::Algebra::Tetrahedron3<Real>::Tetrahedron3(const Vector3& v0, const Vector3& v1, const Vector3& v2, const Vector3& v3) noexcept
    : vertex{ v0, v1, v2, v3 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::Algebra::Tetrahedron3<Real>::Tetrahedron3(const ArrayType& vertex) noexcept
    : vertex{ vertex }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::Tetrahedron3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
const typename Mathematics::Algebra::Tetrahedron3<Real>::FaceIndexType& Mathematics::Algebra::Tetrahedron3<Real>::GetFaceIndices(int face)
{
    static constexpr std::array<FaceIndexType, 4> faceIndices{ { { 0, 2, 1 },
                                                                 { 0, 1, 3 },
                                                                 { 0, 3, 2 },
                                                                 { 1, 2, 3 } } };
    return faceIndices.at(face);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
const typename Mathematics::Algebra::Tetrahedron3<Real>::AllFaceIndexType& Mathematics::Algebra::Tetrahedron3<Real>::GetAllFaceIndices() noexcept
{
    static constexpr AllFaceIndexType allFaceIndices{ 0, 2, 1,
                                                      0, 1, 3,
                                                      0, 3, 2,
                                                      1, 2, 3 };
    return allFaceIndices;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
const typename Mathematics::Algebra::Tetrahedron3<Real>::EdgeIndexType& Mathematics::Algebra::Tetrahedron3<Real>::GetEdgeIndices(int edge)
{
    static constexpr std::array<EdgeIndexType, 6> edgeIndices{ { { 0, 1 },
                                                                 { 0, 2 },
                                                                 { 0, 3 },
                                                                 { 1, 2 },
                                                                 { 1, 3 },
                                                                 { 2, 3 } } };
    return edgeIndices.at(edge);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
const typename Mathematics::Algebra::Tetrahedron3<Real>::AllEdgeIndexType& Mathematics::Algebra::Tetrahedron3<Real>::GetAllEdgeIndices() noexcept
{
    static constexpr AllEdgeIndexType allEdgeIndices{ 0, 1, 0, 2, 0, 3, 1, 2, 1, 3, 2, 3 };

    return allEdgeIndices;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
const typename Mathematics::Algebra::Tetrahedron3<Real>::EdgeAugmentedType& Mathematics::Algebra::Tetrahedron3<Real>::GetEdgeAugmented(int edge)
{
    static std::array<EdgeAugmentedType, 6> edgeAugmented{ { { 0, 1, 2, 3 },
                                                             { 0, 2, 3, 1 },
                                                             { 0, 3, 1, 2 },
                                                             { 1, 2, 0, 3 },
                                                             { 1, 3, 2, 0 },
                                                             { 2, 3, 0, 1 } } };
    return edgeAugmented.at(edge);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
const typename Mathematics::Algebra::Tetrahedron3<Real>::VertexAugmentedType& Mathematics::Algebra::Tetrahedron3<Real>::GetVertexAugmented(int vertex)
{
    static std::array<VertexAugmentedType, 4> vertexAugmented{ { { 0, 1, 3, 2 },
                                                                 { 1, 3, 0, 2 },
                                                                 { 2, 1, 0, 3 },
                                                                 { 3, 2, 0, 1 } } };

    return vertexAugmented.at(vertex);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::Tetrahedron3<Real>::Vector3 Mathematics::Algebra::Tetrahedron3<Real>::ComputeFaceNormal(int face) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    /// 计算面的法线 <v0,v1,v2>。
    const auto& indices = GetFaceIndices(face);

    const auto edge10 = vertex.at(indices.at(1)) - vertex.at(indices.at(0));
    const auto edge20 = vertex.at(indices.at(2)) - vertex.at(indices.at(0));
    const auto normal = UnitCross(edge10, edge20);

    return normal;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::Tetrahedron3<Real>::Vector3 Mathematics::Algebra::Tetrahedron3<Real>::ComputeEdgeNormal(int edge) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    /// 计算边共享的面和的法线的加权平均值。在评论中，
    /// E10 = V[v1]-V[v0], E20 = V[v2]-V[v0], E30 = V[v3]-V[v0] 和
    /// E23 = V[i2]-V[i3]. 未规范化的矢量为
    ///   N = E20 x E10 + E10 x E30
    ///     = E20 x E10 - E30 x E10
    ///     = (E20 - E30) x E10
    ///     = E23 x E10
    const auto& indices = GetEdgeAugmented(edge);

    const auto edge23 = vertex.at(indices.at(2)) - vertex.at(indices.at(3));
    const auto edge10 = vertex.at(indices.at(1)) - vertex.at(indices.at(0));
    const auto normal = UnitCross(edge23, edge10);

    return normal;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::Tetrahedron3<Real>::Vector3 Mathematics::Algebra::Tetrahedron3<Real>::ComputeVertexNormal(int vertexIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    /// 计算面<v0,v1,v2>、<v0,v2,v3>和<v0,v3,v1>的法线的加权平均值。
    /// 在注释中，
    /// E20 = V[v2]-V[v0, E30 = V[v3]-V[v0], E12 = V[v1]-V[v2],
    /// E21 = V[v2]-V[v1] and E31 = V[v3]-V[v1]. 未规范化的向量为：
    ///   N = E10 x E20 + E20 x E30 + E30 x E10
    ///     = E10 x E20 - E30 x E20 + E30 x E10 - E10 x E10
    ///     = E13 x E20 + E31 x E10
    ///     = E13 x E20 - E13 x E10
    ///     = E13 x E21

    const auto& indices = GetVertexAugmented(vertexIndex);

    const auto edge13 = vertex.at(indices.at(1)) - vertex.at(indices.at(3));
    const auto edge21 = vertex.at(indices.at(2)) - vertex.at(indices.at(1));
    const auto normal = UnitCross(edge13, edge21);

    return normal;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::Tetrahedron3<Real>::Plane3Container Mathematics::Algebra::Tetrahedron3<Real>::GetPlanes() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Plane3Container plane{};

    const auto edge10 = vertex.at(1) - vertex.at(0);
    const auto edge20 = vertex.at(2) - vertex.at(0);
    const auto edge30 = vertex.at(3) - vertex.at(0);
    const auto edge21 = vertex.at(2) - vertex.at(1);
    const auto edge31 = vertex.at(3) - vertex.at(1);

    plane.at(0).SetNormal(UnitCross(edge20, edge10));  // <v0,v2,v1>
    plane.at(1).SetNormal(UnitCross(edge10, edge30));  // <v0,v1,v3>
    plane.at(2).SetNormal(UnitCross(edge30, edge20));  // <v0,v3,v2>
    plane.at(3).SetNormal(UnitCross(edge21, edge31));  // <v1,v2,v3>

    const auto det = Dot(edge10, plane.at(3).GetNormal());
    if (det < Real{})
    {
        /// 法线指向内部，反转其方向。
        for (auto i = 0; i < 4; ++i)
        {
            plane.at(i).SetNormal(-plane.at(i).GetNormal());
        }
    }

    for (auto i = 0; i < 4; ++i)
    {
        plane.at(i).SetConstant(Dot(vertex.at(i), plane.at(i).GetNormal()));
    }

    return plane;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::Tetrahedron3<Real>::Vector3 Mathematics::Algebra::Tetrahedron3<Real>::ComputeCentroid() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (vertex.at(0) + vertex.at(1) + vertex.at(2) + vertex.at(3)) * Math::GetRational(1, 4);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::Tetrahedron3<Real>::Equal(const Tetrahedron3& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return vertex == rhs.vertex;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::Tetrahedron3<Real>::Less(const Tetrahedron3& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return vertex < rhs.vertex;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::operator==(const Tetrahedron3<Real>& lhs, const Tetrahedron3<Real>& rhs)
{
    return lhs.Equal(rhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::operator!=(const Tetrahedron3<Real>& lhs, const Tetrahedron3<Real>& rhs)
{
    return !(lhs == rhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::operator<(const Tetrahedron3<Real>& lhs, const Tetrahedron3<Real>& rhs)
{
    return lhs.Less(rhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::operator<=(const Tetrahedron3<Real>& lhs, const Tetrahedron3<Real>& rhs)
{
    return !(rhs < lhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::operator>(const Tetrahedron3<Real>& lhs, const Tetrahedron3<Real>& rhs)
{
    return rhs < lhs;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::operator>=(const Tetrahedron3<Real>& lhs, const Tetrahedron3<Real>& rhs)
{
    return !(lhs < rhs);
}

#endif  // MATHEMATICS_OBJECTS_3D_ALGEBRA_TETRAHEDRON3_DETAIL_H
