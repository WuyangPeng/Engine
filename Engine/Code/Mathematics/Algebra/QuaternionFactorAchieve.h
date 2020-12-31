///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/10 18:48)

#ifndef MATHEMATICS_ALGEBRA_QUATERNION_FACTOR_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_QUATERNION_FACTOR_ACHIEVE_H

#include "Quaternion.h"
#include "QuaternionFactor.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::QuaternionFactor<Real>::QuaternionFactor(const Quaternion& quaternion, QuaternionFactorFlags flag) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
    : m_Quaternion{ quaternion }, m_SinX{}, m_CosX{}, m_SinY{}, m_CosY{}, m_SinZ{}, m_CosZ{}
{
    switch (flag)
    {
        case QuaternionFactorFlags::XYZ:
            FactorXYZ();
            break;
        case QuaternionFactorFlags::XZY:
            FactorXZY();
            break;
        case QuaternionFactorFlags::YZX:
            FactorYZX();
            break;
        case QuaternionFactorFlags::YXZ:
            FactorYXZ();
            break;
        case QuaternionFactorFlags::ZXY:
            FactorZXY();
            break;
        case QuaternionFactorFlags::ZYX:
            FactorZYX();
            break;
        default:
            MATHEMATICS_ASSERTION_1(false, "错误的枚举值！");
            break;
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::QuaternionFactor<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::QuaternionFactor<Real>::GetSinX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_SinX;
}

template <typename Real>
Real Mathematics::QuaternionFactor<Real>::GetSinY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_SinY;
}

template <typename Real>
Real Mathematics::QuaternionFactor<Real>::GetSinZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_SinZ;
}

template <typename Real>
Real Mathematics::QuaternionFactor<Real>::GetCosX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_CosX;
}

template <typename Real>
Real Mathematics::QuaternionFactor<Real>::GetCosY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_CosY;
}

template <typename Real>
Real Mathematics::QuaternionFactor<Real>::GetCosZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_CosZ;
}

template <typename Real>
void Mathematics::QuaternionFactor<Real>::FactorXYZ() noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    auto a = m_Quaternion.GetW() * m_Quaternion.GetX() - m_Quaternion.GetY() * m_Quaternion.GetZ();
    auto b = Math::GetRational(1, 2) * (m_Quaternion.GetW() * m_Quaternion.GetW() - m_Quaternion.GetX() * m_Quaternion.GetX() - m_Quaternion.GetY() * m_Quaternion.GetY() + m_Quaternion.GetZ() * m_Quaternion.GetZ());

    auto fLength = Math::Sqrt(a * a + b * b);

    if (Math::GetZeroTolerance() < fLength)
    {
        auto sigma0 = a / fLength;
        auto gamma0 = b / fLength;

        if (Math::GetValue(0) <= gamma0)
        {
            m_CosX = Math::Sqrt(Math::GetRational(1, 2) * (Math::GetValue(1) + gamma0));
            m_SinX = Math::GetRational(1, 2) * sigma0 / m_CosX;
        }
        else
        {
            m_SinX = Math::Sqrt(Math::GetRational(1, 2) * (Math::GetValue(1) - gamma0));
            m_CosX = Math::GetRational(1, 2) * sigma0 / m_SinX;
        }

        auto tmp0 = m_CosX * m_Quaternion.GetW() + m_SinX * m_Quaternion.GetX();
        auto tmp1 = m_CosX * m_Quaternion.GetZ() - m_SinX * m_Quaternion.GetY();
        auto invLength = Math::InvSqrt(tmp0 * tmp0 + tmp1 * tmp1);
        m_CosZ = tmp0 * invLength;
        m_SinZ = tmp1 * invLength;

        if (Math::FAbs(m_SinZ) <= Math::FAbs(m_CosZ))
        {
            m_CosY = tmp0 / m_CosZ;
            m_SinY = (m_CosX * m_Quaternion.GetY() + m_SinX * m_Quaternion.GetZ()) / m_CosZ;
        }
        else
        {
            m_CosY = tmp1 / m_CosZ;
            m_SinY = (m_CosX * m_Quaternion.GetX() - m_SinX * m_Quaternion.GetW()) / m_CosZ;
        }
    }
    else
    {
        // 无穷多解。选择其中之一。
        if (Math::GetValue(0) < m_Quaternion.GetW() * m_Quaternion.GetY() + m_Quaternion.GetX() * m_Quaternion.GetZ())
        {
            // p = (p0,p1,p0,p1)
            m_CosX = Math::GetValue(1);
            m_SinX = Math::GetValue(0);
            m_CosY = Math::GetInverseSqrt2();
            m_SinY = Math::GetInverseSqrt2();
            m_CosZ = Math::GetSqrt2() * m_Quaternion.GetW();
            m_SinZ = Math::GetSqrt2() * m_Quaternion.GetX();
        }
        else
        {
            // p = (p0,p1,-p0,-p1)
            m_CosX = Math::GetValue(1);
            m_SinX = Math::GetValue(0);
            m_CosY = Math::GetInverseSqrt2();
            m_SinY = -Math::GetInverseSqrt2();
            m_CosZ = Math::GetSqrt2() * m_Quaternion.GetW();
            m_SinZ = -Math::GetSqrt2() * m_Quaternion.GetX();
        }
    }
}

template <typename Real>
void Mathematics::QuaternionFactor<Real>::FactorXZY() noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    m_Quaternion = Quaternion{ m_Quaternion.GetW(), m_Quaternion.GetX(), m_Quaternion.GetZ(), -m_Quaternion.GetY() };

    FactorXYZ();

    auto temp = m_SinY;
    m_SinY = -m_SinZ;
    m_SinZ = temp;

    std::swap(m_CosY, m_CosZ);
}

template <typename Real>
void Mathematics::QuaternionFactor<Real>::FactorYZX() noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    m_Quaternion = Quaternion{ m_Quaternion.GetW(), -m_Quaternion.GetY(), m_Quaternion.GetZ(), -m_Quaternion.GetX() };

    FactorXYZ();

    auto temp = m_SinZ;
    m_SinZ = m_SinY;
    m_SinY = -m_SinX;
    m_SinX = -temp;

    temp = m_CosZ;
    m_CosZ = m_CosY;
    m_CosY = m_CosX;
    m_CosX = temp;
}

template <typename Real>
void Mathematics::QuaternionFactor<Real>::FactorYXZ() noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    m_Quaternion = Quaternion{ m_Quaternion.GetW(), -m_Quaternion.GetY(), m_Quaternion.GetX(), m_Quaternion.GetZ() };

    FactorXYZ();

    auto temp = m_SinY;
    m_SinY = -m_SinX;
    m_SinX = temp;

    std::swap(m_CosY, m_CosX);
}

template <typename Real>
void Mathematics::QuaternionFactor<Real>::FactorZXY() noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    m_Quaternion = Quaternion{ m_Quaternion.GetW(), -m_Quaternion.GetZ(), m_Quaternion.GetX(), -m_Quaternion.GetY() };

    FactorXYZ();

    auto temp = m_SinZ;
    m_SinZ = -m_SinX;
    m_SinX = m_SinY;
    m_SinY = -temp;

    temp = m_CosZ;
    m_CosZ = m_CosX;
    m_CosX = m_CosY;
    m_CosY = temp;
}

template <typename Real>
void Mathematics::QuaternionFactor<Real>::FactorZYX() noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    m_Quaternion = Quaternion{ m_Quaternion.GetW(), m_Quaternion.GetZ(), -m_Quaternion.GetY(), m_Quaternion.GetX() };

    FactorXYZ();

    auto temp = m_SinZ;
    m_SinZ = m_SinX;
    m_SinX = temp;
    m_SinY = -m_SinY;

    std::swap(m_CosZ, m_CosX);
}

#endif  // MATHEMATICS_ALGEBRA_QUATERNION_FACTOR_ACHIEVE_H
