///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 11:00)

#ifndef MATHEMATICS_ALGEBRA_QUATERNION_CONSTRAINTS_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_QUATERNION_CONSTRAINTS_ACHIEVE_H

#include "QuaternionConstraints.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::QuaternionConstraints<Real>::QuaternionConstraints(Real minAngle, Real maxAngle) noexcept
    : minAngle{ minAngle },
      maxAngle{ maxAngle },
      cosMinAngle{ MathType::Cos(minAngle) },
      sinMinAngle{ MathType::Sin(minAngle) },
      cosMaxAngle{ MathType::Cos(maxAngle) },
      sinMaxAngle{ MathType::Sin(maxAngle) },
      diffCosMaxMin{ cosMaxAngle - cosMinAngle },
      diffSinMaxMin{ sinMaxAngle - sinMinAngle },
      avrAngle{ MathType::GetRational(1, 2) * (minAngle + maxAngle) },
      cosAvrAngle{ MathType::Cos(avrAngle) },
      sinAvrAngle{ MathType::Sin(avrAngle) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::QuaternionConstraints<Real>::IsValid() const noexcept
{
    if (-MathType::GetHalfPI() <= minAngle && minAngle <= MathType::GetHalfPI() && minAngle <= maxAngle && maxAngle <= MathType::GetHalfPI())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::QuaternionConstraints<Real>::IsValid(Real x, Real y) const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_1(MathType::Approximate(MathType::Sqrt(x * x + y * y), MathType::GetValue(1)), "(x,y)�����ǵ�λ���ȣ�");

    // ����(x,y)�Ƿ�����Լ��������
    auto xm = x - cosMinAngle;
    auto ym = y - sinMinAngle;
    if (ym * diffCosMaxMin <= xm * diffSinMaxMin)
    {
        return true;
    }

    // ����(-x,-y)�Ƿ�����Լ��������
    auto xp = x + cosMinAngle;
    auto yp = y + sinMinAngle;
    if (xp * diffSinMaxMin <= yp * diffCosMaxMin)
    {
        return true;
    }

    return false;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::QuaternionConstraints<Real>::GetCosMinAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return cosMinAngle;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::QuaternionConstraints<Real>::GetSinMinAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return sinMinAngle;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::QuaternionConstraints<Real>::GetCosMaxAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return cosMaxAngle;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::QuaternionConstraints<Real>::GetSinMaxAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return sinMaxAngle;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::QuaternionConstraints<Real>::GetCosAvrAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return cosAvrAngle;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::QuaternionConstraints<Real>::GetSinAvrAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return sinAvrAngle;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::QuaternionConstraints<Real>::GetMinAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return minAngle;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::QuaternionConstraints<Real>::GetMaxAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return maxAngle;
}

#endif  // MATHEMATICS_ALGEBRA_QUATERNION_CONSTRAINTS_ACHIEVE_H
