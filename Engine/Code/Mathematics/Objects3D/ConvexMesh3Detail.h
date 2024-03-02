///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/22 19:15)

#ifndef MATHEMATICS_OBJECTS_3D_CONVEX_MESH3_DETAIL_H
#define MATHEMATICS_OBJECTS_3D_CONVEX_MESH3_DETAIL_H

#include "ConvexMesh3.h"
#include "Flags/ConvexMesh3Type.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::ConvexMesh3<Real>::ConvexMesh3() noexcept
    : configuration{ ConvexMesh3Type::Empty },
      vertices{},
      triangles{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::ConvexMesh3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::ConvexMesh3Type Mathematics::ConvexMesh3<Real>::GetConfiguration() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return configuration;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::ConvexMesh3<Real>::VertexContainer Mathematics::ConvexMesh3<Real>::GetVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return vertices;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::ConvexMesh3<Real>::TriangleContainer Mathematics::ConvexMesh3<Real>::GetTriangles() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return triangles;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::ConvexMesh3<Real>::SetConfiguration(ConvexMesh3Type aConfiguration) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    configuration = aConfiguration;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::ConvexMesh3<Real>::SetVertices(const VertexContainer& aVertices)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    vertices = aVertices;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::ConvexMesh3<Real>::SetTriangles(const TriangleContainer& aTriangles)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    triangles = aTriangles;
}

#endif  // MATHEMATICS_OBJECTS_3D_CONVEX_MESH3_DETAIL_H
