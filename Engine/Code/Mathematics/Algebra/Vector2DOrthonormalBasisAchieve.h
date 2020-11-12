///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/12 12:54)

#ifndef MATHEMATICS_ALGEBRA_VECTOR_2D_ORTHONORMA_BASIS_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_VECTOR_2D_ORTHONORMA_BASIS_ACHIEVE_H

#include "Vector2D.h"
#include "Vector2DOrthonormalBasis.h"
#include "Vector2DTools.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Vector2DOrthonormalBasis<Real>::Vector2DOrthonormalBasis(const Vector2D& nonzeroVector, const Real epsilon) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
    : m_UVector{ nonzeroVector }, m_VVector{}, m_Epsilon{ epsilon }
{
    MATHEMATICS_ASSERTION_1(!nonzeroVector.IsZero(m_Epsilon), "输入必须是非零向量！");

    Generate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::Vector2DOrthonormalBasis<Real>::Generate() noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    m_UVector.Normalize(m_Epsilon);
    m_VVector = Vector2DTools::GetPerp(m_UVector);
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Vector2DOrthonormalBasis<Real>::IsValid() const noexcept
{
    try
    {
        if (Math::FAbs(Vector2DTools::DotProduct(m_UVector, m_VVector)) <= m_Epsilon &&
            m_UVector.IsNormalize(m_Epsilon) && m_VVector.IsNormalize(m_Epsilon))
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
const typename Mathematics::Vector2DOrthonormalBasis<Real>::Vector2D Mathematics::Vector2DOrthonormalBasis<Real>::GetUVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_UVector;
}

template <typename Real>
const typename Mathematics::Vector2DOrthonormalBasis<Real>::Vector2D Mathematics::Vector2DOrthonormalBasis<Real>::GetVVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_VVector;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_2D_ORTHONORMA_BASIS_ACHIEVE_H