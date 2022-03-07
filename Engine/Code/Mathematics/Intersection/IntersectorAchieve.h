///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/23 10:47)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR_ACHIEVE_H

#include "Intersector.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, template <typename> class Vector>
Mathematics::Intersector<Real, Vector>::Intersector(const Real epsilon) noexcept
    : intersectionType{ IntersectionType::Empty }, epsilon{ epsilon }
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
    if (Math::GetValue(0) <= epsilon)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, template <typename> class Vector>
Mathematics::IntersectionType Mathematics::Intersector<Real, Vector>::GetIntersectionType() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return intersectionType;
}

template <typename Real, template <typename> class Vector>
Real Mathematics::Intersector<Real, Vector>::GetEpsilon() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return epsilon;
}

template <typename Real, template <typename> class Vector>
bool Mathematics::Intersector<Real, Vector>::IsIntersection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return intersectionType != IntersectionType::Empty;
}

template <typename Real, template <typename> class Vector>
void Mathematics::Intersector<Real, Vector>::SetIntersectionType(IntersectionType newIntersectionType) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    intersectionType = newIntersectionType;
}

template <typename Real, template <typename> class Vector>
void Mathematics::Intersector<Real, Vector>::Swap(Intersector& rhs) noexcept
{
    std::swap(intersectionType, rhs.intersectionType);
    std::swap(epsilon, rhs.epsilon);
}

#endif  // MATHEMATICS_INTERSECTION_INTERSECTOR_ACHIEVE_H