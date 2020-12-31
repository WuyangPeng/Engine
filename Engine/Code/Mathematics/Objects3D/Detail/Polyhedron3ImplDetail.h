///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/17 18:13)

#ifndef MATHEMATICS_OBJECTS3D_POLYHEDRON3_IMPL_DETAIL_H
#define MATHEMATICS_OBJECTS3D_POLYHEDRON3_IMPL_DETAIL_H

#include "Polyhedron3Impl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Algebra/Vector3DTools.h"
#include "Mathematics/Base/MathDetail.h"

#include <gsl/gsl_util>

template <typename Real>
Mathematics::Polyhedron3Impl<Real>::Polyhedron3Impl(const VerticesType& vertices, const IndicesType& indices)
    : m_Vertices{}, m_Indices{}
{
    if (m_Vertices.size() < sm_MinVerticesSize)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("顶点数量不足。"s));
    }

    if (m_Indices.size() % sm_TriangleVertexSize != 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("索引数组无法创建三角形。"s));
    }

    m_Vertices = vertices;
    m_Indices = indices;

    MATHEMATICS_SELF_CLASS_IS_VALID_3;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Polyhedron3Impl<Real>::IsValid() const noexcept
{
    if (sm_MinVerticesSize <= gsl::narrow_cast<int>(m_Vertices.size()) && m_Indices.size() % sm_TriangleVertexSize == 0 &&
        sm_MinVerticesSize <= gsl::narrow_cast<int>(m_Indices.size()) / sm_TriangleVertexSize && IndicesIsValid())
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename Real>
bool Mathematics::Polyhedron3Impl<Real>::IndicesIsValid() const noexcept
{
    for (auto value : m_Indices)
    {
        if (value < 0 || gsl::narrow_cast<int>(m_Vertices.size()) <= value)
        {
            return false;
        }
    }

    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::Polyhedron3Impl<Real>::GetNumVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    return boost::numeric_cast<int>(m_Vertices.size());
}

template <typename Real>
typename const Mathematics::Polyhedron3Impl<Real>::VerticesType Mathematics::Polyhedron3Impl<Real>::GetVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    return m_Vertices;
}

template <typename Real>
const Mathematics::Vector3D<Real>& Mathematics::Polyhedron3Impl<Real>::GetVertex(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    return m_Vertices.at(index);
}

template <typename Real>
int Mathematics::Polyhedron3Impl<Real>::GetNumTriangles() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    return GetNumIndices() / sm_TriangleVertexSize;
}

template <typename Real>
int Mathematics::Polyhedron3Impl<Real>::GetNumIndices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    return boost::numeric_cast<int>(m_Indices.size());
}

template <typename Real>
typename const Mathematics::Polyhedron3Impl<Real>::IndicesType Mathematics::Polyhedron3Impl<Real>::GetIndices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    return m_Indices;
}

template <typename Real>
const typename Mathematics::Polyhedron3Impl<Real>::IndicesType Mathematics::Polyhedron3Impl<Real>::GetTriangle(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    const auto index0 = sm_TriangleVertexSize * index;
    const auto index1 = index0 + 1;
    const auto index2 = index0 + 2;

    return IndicesType{ m_Indices.at(index0), m_Indices.at(index1), m_Indices.at(index2) };
}

template <typename Real>
void Mathematics::Polyhedron3Impl<Real>::SetVertex(int index, const Vector3D& vertex)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    m_Vertices.at(index) = vertex;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Polyhedron3Impl<Real>::ComputeVertexAverage() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    Vector3D average{};

    for (const auto& value : m_Vertices)
    {
        average += value;
    }

    average /= boost::numeric_cast<Real>(m_Vertices.size());

    return average;
}

template <typename Real>
Real Mathematics::Polyhedron3Impl<Real>::ComputeSurfaceArea() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    auto surfaceArea = Math::GetValue(0);

    for (auto i = 0; i < GetNumTriangles(); ++i)
    {
        const auto index0 = sm_TriangleVertexSize * i;
        const auto index1 = index0 + 1;
        const auto index2 = index0 + 2;

        auto v0 = m_Indices.at(index0);
        auto v1 = m_Indices.at(index1);
        auto v2 = m_Indices.at(index2);
        auto edge0 = m_Vertices.at(v1) - m_Vertices.at(v0);
        auto edge1 = m_Vertices.at(v2) - m_Vertices.at(v0);
        const auto cross = Vector3DTools::CrossProduct(edge0, edge1);
        surfaceArea += Vector3DTools::VectorMagnitude(cross);
    }

    surfaceArea *= Math::GetRational(1, 2);

    return surfaceArea;
}

template <typename Real>
Real Mathematics::Polyhedron3Impl<Real>::ComputeVolume() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    auto volume = Math::GetValue(0);

    for (auto i = 0; i < GetNumTriangles(); ++i)
    {
        const auto index0 = sm_TriangleVertexSize * i;
        const auto index1 = index0 + 1;
        const auto index2 = index0 + 2;

        auto v0 = m_Indices.at(index0);
        auto v1 = m_Indices.at(index1);
        auto v2 = m_Indices.at(index2);

        const auto cross = Vector3DTools::CrossProduct(m_Vertices.at(v1), m_Vertices.at(v2));

        volume += Vector3DTools::DotProduct(m_Vertices.at(v0), cross);
    }

    volume /= Math::GetValue(6);

    return volume;
}

#endif  // MATHEMATICS_OBJECTS3D_POLYHEDRON3_IMPL_DETAIL_H
