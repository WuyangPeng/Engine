///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/14 10:21)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_SINGLE_CURVE2_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_SINGLE_CURVE2_DETAIL_H

#include "SingleCurve2.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_SINGLE_CURVE2_DETAIL)

    #include "Mathematics/NumericalAnalysis/RombergIntegralDetail.h"

template <typename Real>
Mathematics::SingleCurve2<Real>::SingleCurve2(Real tmin, Real tmax) noexcept
    : ParentType{ tmin, tmax }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

    #ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::SingleCurve2<Real>::IsValid() const noexcept
{
    return ParentType::IsValid();
}

    #endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::SingleCurve2<Real>::GetSpeedWithData(Real t, const SingleCurve2<Real>* data)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (data != nullptr)
    {
        return data->GetSpeed(t);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("data指针为空。"s));
    }
}

template <typename Real>
Real Mathematics::SingleCurve2<Real>::GetLength(Real t0, Real t1) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    MATHEMATICS_ASSERTION_0(this->GetMinTime() <= t0 && t0 <= this->GetMaxTime(), "无效输入。\n");
    MATHEMATICS_ASSERTION_0(this->GetMinTime() <= t1 && t1 <= this->GetMaxTime(), "无效输入。\n");
    MATHEMATICS_ASSERTION_0(t0 <= t1, "无效输入。\n");

    return RombergIntegral<Real, SingleCurve2>(8, t0, t1, GetSpeedWithData, this).GetValue();
}

template <typename Real>
Real Mathematics::SingleCurve2<Real>::GetTime(Real length, int iterations, Real tolerance) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (length <= Math::GetValue(0))
    {
        return this->GetMinTime();
    }

    if (length >= this->GetTotalLength())
    {
        return this->GetMaxTime();
    }

    auto ratio = length / this->GetTotalLength();
    auto oneMinusRatio = Math::GetValue(1) - ratio;
    auto t = oneMinusRatio * this->GetMinTime() + ratio * this->GetMaxTime();

    auto lower = this->GetMinTime();
    auto upper = this->GetMaxTime();

    for (auto i = 0; i < iterations; ++i)
    {
        auto difference = GetLength(this->GetMinTime(), t) - length;
        if (Math::FAbs(difference) < tolerance)
        {
            return t;
        }

        auto tCandidate = t - difference / this->GetSpeed(t);

        if (difference > Math::GetValue(0))
        {
            upper = t;
            if (tCandidate <= lower)
            {
                t = Math::GetRational(1, 2) * (upper + lower);
            }
            else
            {
                t = tCandidate;
            }
        }
        else
        {
            lower = t;
            if (tCandidate >= upper)
            {
                t = Math::GetRational(1, 2) * (upper + lower);
            }
            else
            {
                t = tCandidate;
            }
        }
    }

    return t;
}

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_SINGLE_CURVE2_DETAIL)

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_SINGLE_CURVE2_DETAIL_H