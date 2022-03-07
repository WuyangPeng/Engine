///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/20 15:54)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_CONTACT_TIME_RESULT_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_CONTACT_TIME_RESULT_DETAIL_H

#include "DistanceContactTimeResult.h"
#include "DistanceResultImplDetail.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename Real, typename Vector>
Mathematics::DistanceContactTimeResult<Real, Vector>::DistanceContactTimeResult(Real distance, Real contactTime) noexcept
    : ParentType{ distance }, contactTime{ contactTime }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#include STSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename Vector>
bool Mathematics::DistanceContactTimeResult<Real, Vector>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename Vector>
Real Mathematics::DistanceContactTimeResult<Real, Vector>::GetContactTime() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return contactTime;
}

template <typename Real, typename Vector>
void Mathematics::DistanceContactTimeResult<Real, Vector>::SetContactTime(Real newContactTime) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    contactTime = newContactTime;
}

template <typename Real, typename Vector>
typename Mathematics::DistanceContactTimeResult<Real, Vector>::ImplTypeSharedPtr Mathematics::DistanceContactTimeResult<Real, Vector>::Clone() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

template <typename Real, typename Vector>
bool Mathematics::DistanceContactTimeResult<Real, Vector>::isHaveContactTime() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return true;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_CONTACT_TIME_RESULT_DETAIL_H
