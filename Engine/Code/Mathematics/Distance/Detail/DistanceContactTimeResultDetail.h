///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/04 18:52)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_CONTACT_TIME_RESULT_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_CONTACT_TIME_RESULT_DETAIL_H

#include "DistanceContactTimeResult.h"
#include "DistanceResultImplDetail.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)
template <typename Real, typename Vector>
Mathematics::DistanceContactTimeResult<Real, Vector>::DistanceContactTimeResult(Real distance, Real contactTime) noexcept
    : ParentType{ distance }, m_ContactTime{ contactTime }
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

    return m_ContactTime;
}

template <typename Real, typename Vector>
void Mathematics::DistanceContactTimeResult<Real, Vector>::SetContactTime(Real contactTime) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_ContactTime = contactTime;
}

template <typename Real, typename Vector>
typename Mathematics::DistanceContactTimeResult<Real, Vector>::ImplTypePtr Mathematics::DistanceContactTimeResult<Real, Vector>::Clone() const
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
