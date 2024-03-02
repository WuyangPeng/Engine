///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/26 16:22)

#ifndef MATHEMATICS_OBJECTS_3D_ALGEBRA_POLYHEDRON3_DETAIL_H
#define MATHEMATICS_OBJECTS_3D_ALGEBRA_POLYHEDRON3_DETAIL_H

#include "Polyhedron3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Vector/Vector3Detail.h"
#include "Mathematics/Algebra/Vector/VectorDetail.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::Algebra::Polyhedron3<Real>::Polyhedron3(const ConstVertexPoolSharedPtr& vertexPool, const Indices& indices, bool counterClockwise)
    : vertexPool{ vertexPool },
      uniqueIndices{},
      indices{ indices },
      counterClockwise{ counterClockwise }
{
    if (vertexPool != nullptr && 12 <= indices.size() && (indices.size() % 3) == 0)
    {
        for (const auto element : indices)
        {
            uniqueIndices.emplace(element);
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("遇到无效输入。"))
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::Polyhedron3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::Polyhedron3<Real>::ConstVertexPoolSharedPtr Mathematics::Algebra::Polyhedron3<Real>::GetVertexPool() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto result = vertexPool.lock();

    if (result == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("顶点池已释放。"))
    }

    return result;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::Polyhedron3<Real>::UniqueIndices Mathematics::Algebra::Polyhedron3<Real>::GetUniqueIndices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return uniqueIndices;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::Polyhedron3<Real>::Indices Mathematics::Algebra::Polyhedron3<Real>::GetIndices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return indices;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::Polyhedron3<Real>::CounterClockwise() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return counterClockwise;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::Polyhedron3<Real>::Vector3 Mathematics::Algebra::Polyhedron3<Real>::ComputeVertexAverage() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Vector3 average{};
    const auto vertexPoolSharedPtr = GetVertexPool();

    for (auto index : uniqueIndices)
    {
        average += vertexPoolSharedPtr->at(index);
    }

    average /= boost::numeric_cast<Real>(uniqueIndices.size());

    return average;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::Algebra::Polyhedron3<Real>::ComputeSurfaceArea() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Real surfaceArea{};

    const auto vertexPoolSharedPtr = GetVertexPool();

    const auto numTriangles = boost::numeric_cast<int>(indices.size()) / 3;

    for (auto t = 0; t < numTriangles; ++t)
    {
        const auto index0 = t * 3;
        const auto index1 = index0 + 1;
        const auto index2 = index1 + 1;

        const auto v0 = indices.at(index0);
        const auto v1 = indices.at(index1);
        const auto v2 = indices.at(index2);
        const auto edge0 = vertexPoolSharedPtr->at(v1) - vertexPoolSharedPtr->at(v0);
        const auto edge1 = vertexPoolSharedPtr->at(v2) - vertexPoolSharedPtr->at(v0);
        const auto cross = Cross(edge0, edge1);

        surfaceArea += Length(cross);
    }

    surfaceArea *= Math::GetRational(1, 2);

    return surfaceArea;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::Algebra::Polyhedron3<Real>::ComputeVolume() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Real volume{};
    const auto vertexPoolSharedPtr = GetVertexPool();

    const auto numTriangles = boost::numeric_cast<int>(indices.size()) / 3;

    for (auto t = 0; t < numTriangles; ++t)
    {
        const auto index0 = t * 3;
        const auto index1 = index0 + 1;
        const auto index2 = index1 + 1;

        const auto v0 = indices.at(index0);
        const auto v1 = indices.at(index1);
        const auto v2 = indices.at(index2);
        volume += DotCross(vertexPoolSharedPtr->at(v0), vertexPoolSharedPtr->at(v1), vertexPoolSharedPtr->at(v2));
    }

    volume /= Math::GetValue(6);

    return Math::FAbs(volume);
}

#endif  // MATHEMATICS_OBJECTS_3D_ALGEBRA_POLYHEDRON3_DETAIL_H
