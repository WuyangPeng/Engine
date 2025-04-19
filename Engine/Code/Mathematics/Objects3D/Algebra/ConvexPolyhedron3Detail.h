///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/23 13:16)

#ifndef MATHEMATICS_OBJECTS_3D_ALGEBRA_CONVEX_POLYHEDRON3_DETAIL_H
#define MATHEMATICS_OBJECTS_3D_ALGEBRA_CONVEX_POLYHEDRON3_DETAIL_H

#include "ConvexPolyhedron3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Vector/VectorDetail.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::Algebra::ConvexPolyhedron3<Real>::ConvexPolyhedron3() noexcept
    : vertices{}, indices{}, planes{}, alignedBox{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::Algebra::ConvexPolyhedron3<Real>::ConvexPolyhedron3(VerticesType vertices, IndicesType indices, bool wantPlanes, bool wantAlignedBox)
    : vertices{ std::move(vertices) }, indices{ std::move(indices) }, planes{}, alignedBox{}
{
    if (4 <= this->vertices.size() && 12 <= this->indices.size())
    {
        if (wantPlanes)
        {
            GeneratePlanes();
        }

        if (wantAlignedBox)
        {
            GenerateAlignedBox();
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("ConvexPolyhedron3 输入参数不符合条件。"))
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::ConvexPolyhedron3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::ConvexPolyhedron3<Real>::VerticesType Mathematics::Algebra::ConvexPolyhedron3<Real>::GetVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return vertices;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::ConvexPolyhedron3<Real>::IndicesType Mathematics::Algebra::ConvexPolyhedron3<Real>::GetIndices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return indices;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::ConvexPolyhedron3<Real>::PlanesType Mathematics::Algebra::ConvexPolyhedron3<Real>::GetPlanes() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return planes;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::ConvexPolyhedron3<Real>::AlignedBox3Type Mathematics::Algebra::ConvexPolyhedron3<Real>::GetAlignedBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return alignedBox;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::ConvexPolyhedron3<Real>::SetVertices(const VerticesType& aVertices, bool wantPlanes, bool wantAlignedBox)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (4 <= aVertices.size())
    {
        vertices = aVertices;

        if (wantPlanes)
        {
            GeneratePlanes();
        }

        if (wantAlignedBox)
        {
            GenerateAlignedBox();
        }
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::ConvexPolyhedron3<Real>::SetIndices(const IndicesType& aIndices, bool wantPlanes, bool wantAlignedBox)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (12 <= aIndices.size())
    {
        indices = aIndices;

        if (wantPlanes)
        {
            GeneratePlanes();
        }

        if (wantAlignedBox)
        {
            GenerateAlignedBox();
        }
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::ConvexPolyhedron3<Real>::GeneratePlanes()
{
    if (!vertices.empty() && !indices.empty())
    {
        const auto numTriangles = boost::numeric_cast<int>(indices.size()) / 3;
        planes.resize(numTriangles);
        for (auto t = 0, i = 0; t < numTriangles; ++t)
        {
            const auto& v0 = vertices.at(indices.at(i++));
            const auto& v1 = vertices.at(indices.at(i++));
            const auto& v2 = vertices.at(indices.at(i++));
            const auto e1 = v1 - v0;
            const auto e2 = v2 - v0;
            const auto n = Cross(e1, e2);

            planes.at(t) = HomogeneousLift(n, -Dot(n, v0));
        }
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::ConvexPolyhedron3<Real>::GenerateAlignedBox()
{
    if (!vertices.empty() && !indices.empty())
    {
        Vector3Type min{};
        Vector3Type max{};
        if (ComputeExtremes(boost::numeric_cast<int>(vertices.size()), vertices, min, max))
        {
            alignedBox.Set(min, max);
        }
        else
        {
            THROW_EXCEPTION(SYSTEM_TEXT("alignedBox 设置失败。"))
        }
    }
}

#endif  // MATHEMATICS_OBJECTS_3D_ALGEBRA_CONVEX_POLYHEDRON3_DETAIL_H
