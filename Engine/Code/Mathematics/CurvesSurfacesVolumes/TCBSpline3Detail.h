///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/17 21:20)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_TCB_SPLINE3_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_TCB_SPLINE3_DETAIL_H

#include "TCBSpline3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/NumericalAnalysis/RombergIntegralDetail.h"

template <typename Real>
Mathematics::TCBSpline3<Real>::TCBSpline3(int numSegments,
                                          const std::vector<Real>& times,
                                          const std::vector<Vector3<Real>>& points,
                                          const std::vector<Real>& tension,
                                          const std::vector<Real>& continuity,
                                          const std::vector<Real>& bias)
    : MultipleCurve3<Real>(numSegments, times),
      points{ points },
      tension{ tension },
      continuity{ continuity },
      bias{ bias },
      a(numSegments),
      b(numSegments),
      c(numSegments),
      d(numSegments)
{
    MATHEMATICS_ASSERTION_0(numSegments >= 3, "未有足够的线段。\n");

    ComputePoly(0, 0, 1, 2);

    for (auto i = 1; i < numSegments - 1; ++i)
    {
        ComputePoly(i - 1, i, i + 1, i + 2);
    }

    ComputePoly(numSegments - 2, numSegments - 1, numSegments, numSegments);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::TCBSpline3<Real>::IsValid() const noexcept
{
    return ParentType::IsValid();
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
std::vector<Mathematics::Vector3<Real>> Mathematics::TCBSpline3<Real>::GetPoints() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return points;
}

template <typename Real>
std::vector<Real> Mathematics::TCBSpline3<Real>::GetTensions() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return tension;
}

template <typename Real>
std::vector<Real> Mathematics::TCBSpline3<Real>::GetContinuities() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return continuity;
}

template <typename Real>
std::vector<Real> Mathematics::TCBSpline3<Real>::GetBiases() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return bias;
}

template <typename Real>
void Mathematics::TCBSpline3<Real>::ComputePoly(int i0, int i1, int i2, int i3)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto diff = points.at(i2) - points.at(i1);
    auto dt = this->GetTimes(i2) - this->GetTimes(i1);

    auto oneMinusT0 = Math<Real>::GetValue(1) - tension.at(i1);
    auto oneMinusC0 = Math<Real>::GetValue(1) - continuity.at(i1);
    auto onePlusC0 = Math<Real>::GetValue(1) + continuity.at(i1);
    auto oneMinusB0 = Math<Real>::GetValue(1) - bias.at(i1);
    auto onePlusB0 = Math<Real>::GetValue(1) + bias.at(i1);
    auto adj0 = (Math<Real>::GetValue(2)) * dt / (this->GetTimes(i2) - this->GetTimes(i0));
    auto out0 = Math<Real>::GetRational(1, 2) * adj0 * oneMinusT0 * onePlusC0 * onePlusB0;
    auto out1 = Math<Real>::GetRational(1, 2) * adj0 * oneMinusT0 * oneMinusC0 * oneMinusB0;

    auto tOut = out1 * diff + out0 * (points.at(i1) - points.at(i0));

    auto oneMinusT1 = Math<Real>::GetValue(1) - tension.at(i2);
    auto oneMinusC1 = Math<Real>::GetValue(1) - continuity.at(i2);
    auto onePlusC1 = Math<Real>::GetValue(1) + continuity.at(i2);
    auto oneMinusB1 = Math<Real>::GetValue(1) - bias.at(i2);
    auto onePlusB1 = Math<Real>::GetValue(1) + bias.at(i2);
    auto adj1 = (Math<Real>::GetValue(2)) * dt / (this->GetTimes(i3) - this->GetTimes(i1));
    auto in0 = Math<Real>::GetRational(1, 2) * adj1 * oneMinusT1 * oneMinusC1 * onePlusB1;
    auto in1 = Math<Real>::GetRational(1, 2) * adj1 * oneMinusT1 * onePlusC1 * oneMinusB1;

    auto tIn = in1 * (points.at(i3) - points.at(i2)) + in0 * diff;

    a.at(i1) = points.at(i1);
    b.at(i1) = tOut;
    c.at(i1) = (Math<Real>::GetValue(3)) * diff - (Math<Real>::GetValue(2)) * tOut - tIn;
    d.at(i1) = (Math<Real>::GetValue(-2)) * diff + tOut + tIn;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::TCBSpline3<Real>::GetPosition(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto key = 0;
    Real dt{};
    this->GetKeyInfo(t, key, dt);
    dt /= (this->GetTimes(key + 1) - this->GetTimes(key));

    return a.at(key) + dt * (b.at(key) + dt * (c.at(key) + dt * d.at(key)));
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::TCBSpline3<Real>::GetFirstDerivative(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto key = 0;
    Real dt{};
    this->GetKeyInfo(t, key, dt);
    dt /= (this->GetTimes(key + 1) - this->GetTimes(key));

    return b.at(key) + dt * (c.at(key) * (Math<Real>::GetValue(2)) + d.at(key) * ((Math<Real>::GetValue(3)) * dt));
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::TCBSpline3<Real>::GetSecondDerivative(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto key = 0;
    Real dt{};
    this->GetKeyInfo(t, key, dt);
    dt /= (this->GetTimes(key + 1) - this->GetTimes(key));

    return c.at(key) * (Math<Real>::GetValue(2)) + d.at(key) * (Math<Real>::GetValue(6) * dt);
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::TCBSpline3<Real>::GetThirdDerivative(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto key = 0;
    Real dt{};
    this->GetKeyInfo(t, key, dt);
    dt /= (this->GetTimes(key + 1) - this->GetTimes(key));

    return Math<Real>::GetValue(6) * d.at(key);
}

template <typename Real>
Real Mathematics::TCBSpline3<Real>::GetSpeedKey(int key, Real t) const
{
    const auto velocity = b.at(key) + t * (c.at(key) * (Math<Real>::GetValue(2)) + d.at(key) * ((Math<Real>::GetValue(3)) * t));

    return Vector3Tools<Real>::GetLength(velocity);
}

template <typename Real>
Real Mathematics::TCBSpline3<Real>::GetLengthKey(int key, Real t0, Real t1) const
{
    const SplineKey data{ this, key };

    return RombergIntegral<Real, SplineKey>(8, t0, t1, GetSpeedWithDataKey, &data).GetValue();
}

template <typename Real>
Real Mathematics::TCBSpline3<Real>::GetSpeedWithDataKey(Real t, const SplineKey* data)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (data != nullptr)
    {
        return data->spline->GetSpeedKey(data->key, t);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("data指针为空。"));
    }
}

// TCBSpline3::SplineKey

template <typename Real>
Mathematics::TCBSpline3<Real>::SplineKey::SplineKey(const TCBSpline3* spline, int key) noexcept
    : spline{ spline }, key{ key }
{
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_TCB_SPLINE3_DETAIL_H