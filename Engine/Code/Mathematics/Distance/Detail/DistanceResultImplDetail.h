///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 15:12)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RESULT_IMPL_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_RESULT_IMPL_DETAIL_H

#include "DistanceResultImpl.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real, typename Vector>
Mathematics::DistanceResultImpl<Real, Vector>::DistanceResultImpl(Real distance) noexcept
    : distance{ distance }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, typename Vector>
bool Mathematics::DistanceResultImpl<Real, Vector>::IsValid() const noexcept
{
    if (Math::GetValue(0) <= distance)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename Vector>
Real Mathematics::DistanceResultImpl<Real, Vector>::GetDistance() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return distance;
}

template <typename Real, typename Vector>
Real Mathematics::DistanceResultImpl<Real, Vector>::GetContactTime() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Math::GetValue(0);
}

template <typename Real, typename Vector>
Vector Mathematics::DistanceResultImpl<Real, Vector>::GetLhsClosestPoint() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return GetLhsClosestPoint(0);
}

template <typename Real, typename Vector>
Vector Mathematics::DistanceResultImpl<Real, Vector>::GetRhsClosestPoint() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return GetRhsClosestPoint(0);
}

template <typename Real, typename Vector>
Vector Mathematics::DistanceResultImpl<Real, Vector>::GetLhsClosestPoint([[maybe_unused]] int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    THROW_EXCEPTION(SYSTEM_TEXT("距离结果不包含最近相交点！\n"s));
}

template <typename Real, typename Vector>
Vector Mathematics::DistanceResultImpl<Real, Vector>::GetRhsClosestPoint([[maybe_unused]] int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    THROW_EXCEPTION(SYSTEM_TEXT("距离结果不包含最近相交点！\n"s));
}

template <typename Real, typename Vector>
int Mathematics::DistanceResultImpl<Real, Vector>::GetLhsClosestPointSize() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    CoreTools::DisableNoexcept();

    return closestPointZeroSize;
}

template <typename Real, typename Vector>
int Mathematics::DistanceResultImpl<Real, Vector>::GetRhsClosestPointSize() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    CoreTools::DisableNoexcept();

    return closestPointZeroSize;
}

template <typename Real, typename Vector>
void Mathematics::DistanceResultImpl<Real, Vector>::SetDistance(Real newDistance) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    distance = newDistance;
}

template <typename Real, typename Vector>
void Mathematics::DistanceResultImpl<Real, Vector>::SetSqrtDistance(Real newDistance) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    SetDistance(Math::Sqrt(newDistance));
}

template <typename Real, typename Vector>
void Mathematics::DistanceResultImpl<Real, Vector>::SetContactTime([[maybe_unused]] Real contactTime)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    THROW_EXCEPTION(SYSTEM_TEXT("距离结果不包含接触时间！\n"s));
}

template <typename Real, typename Vector>
Real Mathematics::DistanceResultImpl<Real, Vector>::GetLhsParameter() const
{
    MATHEMATICS_CLASS_IS_VALID_1;

    THROW_EXCEPTION(SYSTEM_TEXT("距离结果不包含接触参数！\n"s));
}

template <typename Real, typename Vector>
Real Mathematics::DistanceResultImpl<Real, Vector>::GetRhsParameter() const
{
    MATHEMATICS_CLASS_IS_VALID_1;

    THROW_EXCEPTION(SYSTEM_TEXT("距离结果不包含接触参数！\n"s));
}

template <typename Real, typename Vector>
bool Mathematics::DistanceResultImpl<Real, Vector>::IsHaveContactTime() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return false;
}

template <typename Real, typename Vector>
typename Mathematics::DistanceResultImpl<Real, Vector>::ImplTypeSharedPtr Mathematics::DistanceResultImpl<Real, Vector>::Clone() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RESULT_IMPL_DETAIL_H
