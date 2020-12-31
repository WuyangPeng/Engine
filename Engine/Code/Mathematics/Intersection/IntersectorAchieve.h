///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/16 10:17)
///
#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR_ACHIEVE_H

#include "Intersector.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, template <typename> class Vector>
Mathematics::Intersector<Real, Vector>::Intersector(const Real epsilon) noexcept
    : m_IntersectionType{ IntersectionType::Empty }, m_Epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, template <typename> class Vector>
Mathematics::Intersector<Real, Vector>::~Intersector() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, template <typename> class Vector>
bool Mathematics::Intersector<Real, Vector>::IsValid() const noexcept
{
    if (Math::GetValue(0) <= m_Epsilon)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real, template <typename> class Vector>
Mathematics::IntersectionType Mathematics::Intersector<Real, Vector>::GetIntersectionType() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_IntersectionType;
}

template <typename Real, template <typename> class Vector>
Real Mathematics::Intersector<Real, Vector>::GetEpsilon() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Epsilon;
}

template <typename Real, template <typename> class Vector>
bool Mathematics::Intersector<Real, Vector>::IsIntersection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_IntersectionType != IntersectionType::Empty;
}

template <typename Real, template <typename> class Vector>
void Mathematics::Intersector<Real, Vector>::SetIntersectionType(IntersectionType intersectionType) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_IntersectionType = intersectionType;
}

template <typename Real, template <typename> class Vector>
void Mathematics::Intersector<Real, Vector>::Swap(Intersector& rhs) noexcept
{
    std::swap(m_IntersectionType, rhs.m_IntersectionType);
    std::swap(m_Epsilon, rhs.m_Epsilon);
}

#endif  // MATHEMATICS_INTERSECTION_INTERSECTOR_ACHIEVE_H