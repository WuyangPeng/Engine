///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/20 14:07)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RESLUT_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_RESLUT_DETAIL_H

#include "DistanceResult.h"
#include "Detail/DistanceResultFactoryDetail.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real, typename Vector>
Mathematics::DistanceResult<Real, Vector>::DistanceResult(Real distance)
    : impl{ CoreTools::ImplCreateUseFactory::Default, distance }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, typename Vector>
Mathematics::DistanceResult<Real, Vector>::DistanceResult(Real distance, Real contactTime)
    : impl{ CoreTools::ImplCreateUseFactory::Default, distance, contactTime }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, typename Vector>
Mathematics::DistanceResult<Real, Vector>::DistanceResult(Real distance, Real contactTime, const Vector& lhsClosestPoint, const Vector& rhsClosestPoint)
    : impl{ CoreTools::ImplCreateUseFactory::Default, distance, contactTime, lhsClosestPoint, rhsClosestPoint }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, typename Vector>
Mathematics::DistanceResult<Real, Vector>::DistanceResult(Real distance, Real contactTime, const ClosestPoints& lhsClosestPoints, const ClosestPoints& rhsClosestPoints)
    : impl{ CoreTools::ImplCreateUseFactory::Default, distance, contactTime, lhsClosestPoints, rhsClosestPoints }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, typename Vector>
Mathematics::DistanceResult<Real, Vector>::DistanceResult(Real distance, Real contactTime, const Vector& lhsClosestPoint, const Vector& rhsClosestPoint, Real lhsParameter, Real rhsParameter)
    : impl{ CoreTools::ImplCreateUseFactory::Default, distance, contactTime, lhsClosestPoint, rhsClosestPoint, lhsParameter, rhsParameter }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, typename Vector>
bool Mathematics::DistanceResult<Real, Vector>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename Vector>
typename Mathematics::DistanceResult<Real, Vector>::SharedPtr Mathematics::DistanceResult<Real, Vector>::Clone(const ImplType& impl)
{
    return impl.Clone();
}

template <typename Real, typename Vector>
Real Mathematics::DistanceResult<Real, Vector>::GetDistance() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetDistance();
}

template <typename Real, typename Vector>
Real Mathematics::DistanceResult<Real, Vector>::GetContactTime() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetContactTime();
}

template <typename Real, typename Vector>
Vector Mathematics::DistanceResult<Real, Vector>::GetLhsClosestPoint() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetLhsClosestPoint();
}

template <typename Real, typename Vector>
Vector Mathematics::DistanceResult<Real, Vector>::GetRhsClosestPoint() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetRhsClosestPoint();
}

template <typename Real, typename Vector>
Vector Mathematics::DistanceResult<Real, Vector>::GetLhsClosestPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetLhsClosestPoint(index);
}

template <typename Real, typename Vector>
Vector Mathematics::DistanceResult<Real, Vector>::GetRhsClosestPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetRhsClosestPoint(index);
}

template <typename Real, typename Vector>
int Mathematics::DistanceResult<Real, Vector>::GetLhsClosestPointSize() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetLhsClosestPointSize();
}

template <typename Real, typename Vector>
int Mathematics::DistanceResult<Real, Vector>::GetRhsClosestPointSize() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetRhsClosestPointSize();
}

template <typename Real, typename Vector>
Real Mathematics::DistanceResult<Real, Vector>::GetLhsParameter() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetLhsParameter();
}

template <typename Real, typename Vector>
Real Mathematics::DistanceResult<Real, Vector>::GetRhsParameter() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetRhsParameter();
}

template <typename Real, typename Vector>
void Mathematics::DistanceResult<Real, Vector>::SetDistance(Real distance)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    return impl->SetDistance(distance);
}

template <typename Real, typename Vector>
void Mathematics::DistanceResult<Real, Vector>::SetSqrtDistance(Real distance)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    return impl->SetSqrtDistance(distance);
}

template <typename Real, typename Vector>
void Mathematics::DistanceResult<Real, Vector>::SetContactTime(Real contactTime)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (impl.GetConstImpl()->isHaveContactTime())
    {
        impl->SetContactTime(contactTime);
    }
    else
    {
        const auto distance = impl.GetConstImpl()->GetDistance();

        impl = DistanceResultFactory<Real, Vector>::Create(distance, contactTime);
    }
}

template <typename Real, typename Vector>
void Mathematics::DistanceResult<Real, Vector>::Set(Real distance, Real contactTime)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    SetContactTime(contactTime);
    SetDistance(distance);
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RESLUT_DETAIL_H
