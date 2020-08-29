//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.0 (2020/08/29 0:09)

#ifndef MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMA_BASIS_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMA_BASIS_ACHIEVE_H

#include "AVectorDetail.h"
#include "AVectorOrthonormalBasis.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::AVectorOrthonormalBasis<Real>::AVectorOrthonormalBasis(const AVector& nonzeroVector, bool isUnit, const Real epsilon)
    : m_IsUnit{ isUnit }, m_UVector{}, m_VVector{}, m_WVector{ nonzeroVector }, m_Epsilon{ epsilon }
{
    MATHEMATICS_ASSERTION_1(!nonzeroVector.IsZero(m_Epsilon), "输入必须是非零向量！");

    Generate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::AVectorOrthonormalBasis<Real>::Generate()
{
    if (!m_IsUnit)
    {
        m_WVector.Normalize(m_Epsilon);
    }

    if (Math::FAbs(m_WVector.GetY() <= Math::FAbs(m_WVector.GetX())))
    {
        GenerateOnXOrZIsMax();
    }
    else
    {
        GenerateOnYOrZIsMax();
    }
}

template <typename Real>
void Mathematics::AVectorOrthonormalBasis<Real>::GenerateOnXOrZIsMax()
{
    // unitVector.x或unitVector.z是最大量级的分量，交换他们
    auto invLength = Math::InvSqrt(m_WVector.GetX() * m_WVector.GetX() + m_WVector.GetZ() * m_WVector.GetZ());

    m_UVector = AVector{ -m_WVector.GetZ() * invLength, Math::GetValue(0), m_WVector.GetX() * invLength };
    m_VVector = AVector{ m_WVector.GetY() * m_UVector.GetZ(), m_WVector.GetZ() * m_UVector.GetX() - m_WVector.GetX() * m_UVector.GetZ(), -m_WVector.GetY() * m_UVector.GetX() };
}

template <typename Real>
void Mathematics::AVectorOrthonormalBasis<Real>::GenerateOnYOrZIsMax()
{
    // unitVector.y或unitVector.z是最大量级的分量，交换他们
    auto invLength = Math::InvSqrt(m_WVector.GetY() * m_WVector.GetY() + m_WVector.GetZ() * m_WVector.GetZ());

    m_UVector = AVector{ Math::GetValue(0), m_WVector.GetZ() * invLength, -m_WVector.GetY() * invLength };
    m_VVector = AVector{ m_WVector.GetY() * m_UVector.GetZ() - m_WVector.GetZ() * m_UVector.GetY(), -m_WVector.GetX() * m_UVector.GetZ(), m_WVector.GetX() * m_UVector.GetY() };
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::AVectorOrthonormalBasis<Real>::IsValid() const noexcept
{
    try
    {
        if (Math::FAbs(Dot(m_UVector, m_VVector)) <= m_Epsilon &&
            Math::FAbs(Dot(m_UVector, m_WVector)) <= m_Epsilon &&
            Math::FAbs(Dot(m_VVector, m_WVector)) <= m_Epsilon &&
            m_UVector.IsNormalize(m_Epsilon) && m_VVector.IsNormalize(m_Epsilon) && m_WVector.IsNormalize(m_Epsilon))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        return false;
    }
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::AVectorOrthonormalBasis<Real>::AVector Mathematics::AVectorOrthonormalBasis<Real>::GetUVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_UVector;
}

template <typename Real>
const typename Mathematics::AVectorOrthonormalBasis<Real>::AVector Mathematics::AVectorOrthonormalBasis<Real>::GetVVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_VVector;
}

template <typename Real>
const typename Mathematics::AVectorOrthonormalBasis<Real>::AVector Mathematics::AVectorOrthonormalBasis<Real>::GetWVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_WVector;
}

#endif  // MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMA_BASIS_ACHIEVE_H