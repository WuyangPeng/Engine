///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/16 15:02)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_MULTIPLE_CURVE2_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_MULTIPLE_CURVE2_DETAIL_H

#include "MultipleCurve2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <gsl/util>

template <typename Real>
Mathematics::MultipleCurve2<Real>::MultipleCurve2(int numSegments, const std::vector<Real>& times)
    : ParentType{ times.at(0), times.at(numSegments) },
      numSegments{ numSegments },
      times{ times },
      lengths{},
      accumLengths{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::MultipleCurve2<Real>::IsValid() const noexcept
{
    return ParentType::IsValid();
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::MultipleCurve2<Real>::GetSegments() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numSegments;
}

template <typename Real>
std::vector<Real> Mathematics::MultipleCurve2<Real>::GetTimes() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return times;
}

template <typename Real>
Real Mathematics::MultipleCurve2<Real>::GetTimes(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return times.at(index);
}

template <typename Real>
void Mathematics::MultipleCurve2<Real>::GetKeyInfo(Real t, int& key, Real& dt) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (t <= times.at(0))
    {
        key = 0;
        dt = Math<Real>::GetValue(0);
    }
    else if (t >= times.at(numSegments))
    {
        key = numSegments - 1;
        dt = times.at(numSegments) - times.at(gsl::narrow_cast<size_t>(numSegments) - 1);
    }
    else
    {
        for (auto i = 0; i < numSegments; ++i)
        {
            if (t < times.at(gsl::narrow_cast<size_t>(i) + 1))
            {
                key = i;
                dt = t - times.at(i);
                break;
            }
        }
    }
}

template <typename Real>
void Mathematics::MultipleCurve2<Real>::InitializeLength() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    lengths.resize(numSegments);
    accumLengths.resize(numSegments);

    for (auto key = 0; key < numSegments; ++key)
    {
        lengths.at(key) = GetLengthKey(key, Math<Real>::GetValue(0), times.at(gsl::narrow_cast<size_t>(key) + 1) - times.at(key));
    }

    accumLengths.at(0) = lengths.at(0);
    for (auto key = 1; key < numSegments; ++key)
    {
        accumLengths.at(key) = accumLengths.at(gsl::narrow_cast<size_t>(key) - 1) + lengths.at(key);
    }
}

template <typename Real>
Real Mathematics::MultipleCurve2<Real>::GetLength(Real t0, Real t1) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    MATHEMATICS_ASSERTION_0(this->GetMinTime() <= t0 && t0 <= this->GetMaxTime(), "无效输入。\n");
    MATHEMATICS_ASSERTION_0(this->GetMinTime() <= t1 && t1 <= this->GetMaxTime(), "无效输入。\n");
    MATHEMATICS_ASSERTION_0(t0 <= t1, "无效输入。\n");

    if (lengths.empty())
    {
        InitializeLength();
    }

    auto key0 = 0;
    auto key1 = 0;
    Real dt0{};
    Real dt1{};
    GetKeyInfo(t0, key0, dt0);
    GetKeyInfo(t1, key1, dt1);

    Real length{};
    if (key0 < key1)
    {
        length = Math<Real>::GetValue(0);
        for (auto i = key0 + 1; i < key1; ++i)
        {
            length += lengths.at(i);
        }

        length += GetLengthKey(key0, dt0, times.at(gsl::narrow_cast<size_t>(key0) + 1) - times.at(key0));

        length += GetLengthKey(key1, Math<Real>::GetValue(0), dt1);
    }
    else
    {
        length = GetLengthKey(key0, dt0, dt1);
    }

    return length;
}

template <typename Real>
Real Mathematics::MultipleCurve2<Real>::GetTime(Real length, int iterations, Real tolerance) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (lengths.empty())
    {
        InitializeLength();
    }

    if (length <= Math<Real>::GetValue(0))
    {
        return this->GetMinTime();
    }

    if (length >= accumLengths.at(gsl::narrow_cast<size_t>(numSegments) - 1))
    {
        return this->GetMaxTime();
    }

    auto key = 0;
    for (; key < numSegments; ++key)
    {
        if (length < accumLengths.at(key))
        {
            break;
        }
    }
    if (key >= numSegments)
    {
        return times.at(numSegments);
    }

    Real len0{};
    Real len1{};
    if (key == 0)
    {
        len0 = length;
        len1 = accumLengths.at(0);
    }
    else
    {
        len0 = length - accumLengths.at(gsl::narrow_cast<size_t>(key) - 1);
        len1 = accumLengths.at(key) - accumLengths.at(gsl::narrow_cast<size_t>(key) - 1);
    }

    auto dt1 = times.at(gsl::narrow_cast<size_t>(key) + 1) - times.at(key);
    auto dt0 = dt1 * len0 / len1;

    auto lower = Math<Real>::GetValue(0);
    auto upper = dt1;

    for (auto i = 0; i < iterations; ++i)
    {
        auto difference = GetLengthKey(key, Math<Real>::GetValue(0), dt0) - len0;
        if (Math<Real>::FAbs(difference) <= tolerance)
        {
            return times.at(key) + dt0;
        }

        auto dt0Candidate = dt0 - difference / GetSpeedKey(key, dt0);

        if (difference > Math<Real>::GetValue(0))
        {
            upper = dt0;
            if (dt0Candidate <= lower)
            {
                dt0 = Math<Real>::GetRational(1, 2) * (upper + lower);
            }
            else
            {
                dt0 = dt0Candidate;
            }
        }
        else
        {
            lower = dt0;
            if (dt0Candidate >= upper)
            {
                dt0 = Math<Real>::GetRational(1, 2) * (upper + lower);
            }
            else
            {
                dt0 = dt0Candidate;
            }
        }
    }

    return times.at(key) + dt0;
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_MULTIPLE_CURVE2_DETAIL_H