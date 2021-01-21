// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/15 10:03)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRAHEDRON3_TETRAHEDRON3_IMPL_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRAHEDRON3_TETRAHEDRON3_IMPL_DETAIL_H

#include "StaticFindIntersectorTetrahedron3Tetrahedron3Impl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorTetrahedron3Tetrahedron3Impl<Real>::StaticFindIntersectorTetrahedron3Tetrahedron3Impl(const Tetrahedron3& tetrahedron0, const Tetrahedron3& tetrahedron1) noexcept
    : m_Tetrahedron0{ tetrahedron0 }, m_Tetrahedron1{ tetrahedron1 }, m_Intersection{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorTetrahedron3Tetrahedron3Impl<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Tetrahedron3<Real> Mathematics::StaticFindIntersectorTetrahedron3Tetrahedron3Impl<Real>::GetTetrahedron0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Tetrahedron0;
}

template <typename Real>
const Mathematics::Tetrahedron3<Real> Mathematics::StaticFindIntersectorTetrahedron3Tetrahedron3Impl<Real>::GetTetrahedron1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Tetrahedron1;
}

template <typename Real>
const typename Mathematics::StaticFindIntersectorTetrahedron3Tetrahedron3Impl<Real>::IntersectionContainer Mathematics::StaticFindIntersectorTetrahedron3Tetrahedron3Impl<Real>::GetIntersection() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Intersection;
}

template <typename Real>
void Mathematics::StaticFindIntersectorTetrahedron3Tetrahedron3Impl<Real>::SetIntersectionContainer(const IntersectionContainer& intersectionContainer)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Intersection = intersectionContainer;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRAHEDRON3_TETRAHEDRON3_IMPL_DETAIL_H