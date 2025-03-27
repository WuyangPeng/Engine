/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 10:37)

#ifndef MATHEMATICS_OBJECTS_3D_POLYHEDRON3_DETAIL_H
#define MATHEMATICS_OBJECTS_3D_POLYHEDRON3_DETAIL_H

#include "Polyhedron3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Base/MathDetail.h"

#include <gsl/util>

template <typename Real>
Mathematics::Polyhedron3<Real>::Polyhedron3(const VerticesType& vertices, const IndicesType& indices)
    : vertices{ vertices }, indices{ indices }
{
    if (vertices.size() < minVerticesSize)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("顶点数量不足。"s));
    }

    if (indices.size() % triangleVertexSize != 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("索引数组无法创建三角形。"s));
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_3;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Polyhedron3<Real>::IsValid() const noexcept
{
    if (minVerticesSize <= gsl::narrow_cast<int>(vertices.size()) &&
        indices.size() % triangleVertexSize == 0 &&
        minVerticesSize <= gsl::narrow_cast<int>(indices.size()) / triangleVertexSize && IndicesIsValid())
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename Real>
bool Mathematics::Polyhedron3<Real>::IndicesIsValid() const noexcept
{
    for (auto value : indices)
    {
        if (value < 0 || gsl::narrow_cast<int>(vertices.size()) <= value)
        {
            return false;
        }
    }

    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::Polyhedron3<Real>::GetNumVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    return boost::numeric_cast<int>(vertices.size());
}

template <typename Real>
typename Mathematics::Polyhedron3<Real>::VerticesType Mathematics::Polyhedron3<Real>::GetVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    return vertices;
}

template <typename Real>
const Mathematics::Vector3<Real>& Mathematics::Polyhedron3<Real>::GetVertex(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    return vertices.at(index);
}

template <typename Real>
int Mathematics::Polyhedron3<Real>::GetNumTriangles() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    return GetNumIndices() / triangleVertexSize;
}

template <typename Real>
int Mathematics::Polyhedron3<Real>::GetNumIndices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    return boost::numeric_cast<int>(indices.size());
}

template <typename Real>
typename Mathematics::Polyhedron3<Real>::IndicesType Mathematics::Polyhedron3<Real>::GetIndices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    return indices;
}

template <typename Real>
typename Mathematics::Polyhedron3<Real>::IndicesType Mathematics::Polyhedron3<Real>::GetTriangle(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    const auto index0 = triangleVertexSize * index;
    const auto index1 = index0 + 1;
    const auto index2 = index0 + 2;

    return IndicesType{ indices.at(index0), indices.at(index1), indices.at(index2) };
}

template <typename Real>
void Mathematics::Polyhedron3<Real>::SetVertex(int index, const Vector3Type& vertex)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    vertices.at(index) = vertex;
}

template <typename Real>
typename Mathematics::Polyhedron3<Real>::Vector3Type Mathematics::Polyhedron3<Real>::ComputeVertexAverage() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    Vector3Type average{};

    for (const auto& value : vertices)
    {
        average += value;
    }

    average /= boost::numeric_cast<Real>(vertices.size());

    return average;
}

template <typename Real>
Real Mathematics::Polyhedron3<Real>::ComputeSurfaceArea() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    auto surfaceArea = Math::GetValue(0);

    for (auto i = 0; i < GetNumTriangles(); ++i)
    {
        const auto index0 = triangleVertexSize * i;
        const auto index1 = index0 + 1;
        const auto index2 = index0 + 2;

        const auto v0 = indices.at(index0);
        const auto v1 = indices.at(index1);
        const auto v2 = indices.at(index2);
        const auto edge0 = vertices.at(v1) - vertices.at(v0);
        const auto edge1 = vertices.at(v2) - vertices.at(v0);
        const auto cross = Vector3ToolsType::CrossProduct(edge0, edge1);
        surfaceArea += Vector3ToolsType::GetLength(cross);
    }

    surfaceArea *= Math::GetRational(1, 2);

    return surfaceArea;
}

template <typename Real>
Real Mathematics::Polyhedron3<Real>::ComputeVolume() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    auto volume = Math::GetValue(0);

    for (auto i = 0; i < GetNumTriangles(); ++i)
    {
        const auto index0 = triangleVertexSize * i;
        const auto index1 = index0 + 1;
        const auto index2 = index0 + 2;

        const auto v0 = indices.at(index0);
        const auto v1 = indices.at(index1);
        const auto v2 = indices.at(index2);

        const auto cross = Vector3ToolsType::CrossProduct(vertices.at(v1), vertices.at(v2));

        volume += Vector3ToolsType::DotProduct(vertices.at(v0), cross);
    }

    volume /= Math::GetValue(6);

    return volume;
}

#endif  // MATHEMATICS_OBJECTS_3D_POLYHEDRON3_DETAIL_H
