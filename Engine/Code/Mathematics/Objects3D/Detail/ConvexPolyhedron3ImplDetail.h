///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/18 10:19)

#ifndef MATHEMATICS_OBJECTS3D_CONVEX_POLYHEDRON3_IMPL_DETAIL_H
#define MATHEMATICS_OBJECTS3D_CONVEX_POLYHEDRON3_IMPL_DETAIL_H

#include "ConvexPolyhedron3Impl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::ConvexPolyhedron3Impl<Real>::ConvexPolyhedron3Impl(const PlaneContainerType& planes)
    : m_Planes{ planes }, m_SharingTriangles{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::ConvexPolyhedron3Impl<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::ConvexPolyhedron3Impl<Real>::PlaneContainerType Mathematics::ConvexPolyhedron3Impl<Real>::GetPlanes() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Planes;
}

template <typename Real>
const Mathematics::Plane3<Real>& Mathematics::ConvexPolyhedron3Impl<Real>::GetPlane(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Planes.at(index);
}

template <typename Real>
int Mathematics::ConvexPolyhedron3Impl<Real>::GetNumPlane() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(m_Planes.size());
}

template <typename Real>
void Mathematics::ConvexPolyhedron3Impl<Real>::SetVertex(int index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_SharingTriangles.insert(index);
}

template <typename Real>
bool Mathematics::ConvexPolyhedron3Impl<Real>::IsUpdatePlanes() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return !m_SharingTriangles.empty();
}

template <typename Real>
void Mathematics::ConvexPolyhedron3Impl<Real>::ClearSharingTriangles() noexcept
{
    m_SharingTriangles.clear();
}

template <typename Real>
void Mathematics::ConvexPolyhedron3Impl<Real>::UpdatePlane(int index, const Vector3D& origin, const Vector3D& direction)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto plane = m_Planes.at(index);

    plane.SetPlane(direction, origin);
}

template <typename Real>
typename Mathematics::ConvexPolyhedron3Impl<Real>::PlaneContainerTypeConstIter Mathematics::ConvexPolyhedron3Impl<Real>::begin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Planes.begin();
}

template <typename Real>
typename Mathematics::ConvexPolyhedron3Impl<Real>::PlaneContainerTypeConstIter Mathematics::ConvexPolyhedron3Impl<Real>::end() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Planes.end();
}

 template <typename Real>
void Mathematics::ConvexPolyhedron3Impl<Real>::ResetTriangles(int numTriangles)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Planes.resize(numTriangles);

     for (auto i = 0; i < numTriangles; ++i)
    {
        m_SharingTriangles.insert(i);
    }
}

#endif  // MATHEMATICS_OBJECTS3D_CONVEX_POLYHEDRON3_IMPL_DETAIL_H
