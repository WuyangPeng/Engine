///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/05 23:54)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RESLUT_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_RESLUT_ACHIEVE_H

#include "DistanceResult.h"
#include "Detail/DistanceResultFactoryDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real, typename Vector>
Mathematics::DistanceResult<Real, Vector>::DistanceResult(Real distance)
    : m_Impl{ DistanceResultFactory<Real, Vector>::Create(distance) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, typename Vector>
Mathematics::DistanceResult<Real, Vector>::DistanceResult(Real distance, Real contactTime)
    : m_Impl{ DistanceResultFactory<Real, Vector>::Create(distance, contactTime) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, typename Vector>
Mathematics::DistanceResult<Real, Vector>::DistanceResult(Real distance, Real contactTime, const Vector& lhsClosestPoint, const Vector& rhsClosestPoint)
    : m_Impl{ DistanceResultFactory<Real, Vector>::Create(distance, contactTime, lhsClosestPoint, rhsClosestPoint) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, typename Vector>
Mathematics::DistanceResult<Real, Vector>::DistanceResult(Real distance, Real contactTime, const ClosestPoints& lhsClosestPoints, const ClosestPoints& rhsClosestPoints)
    : m_Impl{ DistanceResultFactory<Real, Vector>::Create(distance, contactTime, lhsClosestPoints, rhsClosestPoints) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, typename Vector>
Mathematics::DistanceResult<Real, Vector>::DistanceResult(Real distance, Real contactTime, const Vector& lhsClosestPoint, const Vector& rhsClosestPoint, Real lhsParameter, Real rhsParameter)
    : m_Impl{ DistanceResultFactory<Real, Vector>::Create(distance, contactTime, lhsClosestPoint, rhsClosestPoint, lhsParameter, rhsParameter) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename Vector>
bool Mathematics::DistanceResult<Real, Vector>::IsValid() const noexcept
{
    if (m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename Vector>
void Mathematics::DistanceResult<Real, Vector>::Copy()
{
    static_assert(std::is_same_v<ClassShareType::NonConstCopyMember, CoreTools::TrueType>, "It is not allowed to define the Copy function used for copy delayed.");

    MATHEMATICS_CLASS_IS_VALID_1;

    if (1 < m_Impl.use_count())
    {
        m_Impl = m_Impl->Clone();
    }
}

template <typename Real, typename Vector>
Real Mathematics::DistanceResult<Real, Vector>::GetDistance() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetDistance();
}

template <typename Real, typename Vector>
Real Mathematics::DistanceResult<Real, Vector>::GetContactTime() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetContactTime();
}

template <typename Real, typename Vector>
const Vector Mathematics::DistanceResult<Real, Vector>::GetLhsClosestPoint() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetLhsClosestPoint();
}

template <typename Real, typename Vector>
const Vector Mathematics::DistanceResult<Real, Vector>::GetRhsClosestPoint() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetRhsClosestPoint();
}

template <typename Real, typename Vector>
const Vector Mathematics::DistanceResult<Real, Vector>::GetLhsClosestPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetLhsClosestPoint(index);
}

template <typename Real, typename Vector>
const Vector Mathematics::DistanceResult<Real, Vector>::GetRhsClosestPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetRhsClosestPoint(index);
}

template <typename Real, typename Vector>
int Mathematics::DistanceResult<Real, Vector>::GetLhsClosestPointSize() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetLhsClosestPointSize();
}

template <typename Real, typename Vector>
int Mathematics::DistanceResult<Real, Vector>::GetRhsClosestPointSize() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetRhsClosestPointSize();
}

template <typename Real, typename Vector>
Real Mathematics::DistanceResult<Real, Vector>::GetLhsParameter() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetLhsParameter();
}

template <typename Real, typename Vector>
Real Mathematics::DistanceResult<Real, Vector>::GetRhsParameter() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetRhsParameter();
}

template <typename Real, typename Vector>
void Mathematics::DistanceResult<Real, Vector>::SetDistance(Real distance)
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->SetDistance(distance);
}

template <typename Real, typename Vector>
void Mathematics::DistanceResult<Real, Vector>::SetSqrtDistance()
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->SetSqrtDistance();
}

template <typename Real, typename Vector>
void Mathematics::DistanceResult<Real, Vector>::SetContactTime(Real contactTime)
{
    static_assert(std::is_same_v<ClassShareType::NonConstCopyMember, CoreTools::TrueType>, "Non-const copy member functions are forbidden");

    MATHEMATICS_CLASS_IS_VALID_1;

    if (m_Impl->isHaveContactTime())
    {
        Copy();

        m_Impl->SetContactTime(contactTime);
    }
    else
    {
        auto distance = m_Impl->GetDistance();

        m_Impl = DistanceResultFactory<Real, Vector>::Create(distance, contactTime);
    }
}

template <typename Real, typename Vector>
void Mathematics::DistanceResult<Real, Vector>::Set(Real distance, Real contactTime)
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    SetContactTime(contactTime);
    SetDistance(distance);
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RESLUT_ACHIEVE_H
