///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/12 14:29)

#ifndef MATHEMATICS_ALGEBRA_VECTOR_2D_ORTHONORMALIZE_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_VECTOR_2D_ORTHONORMALIZE_ACHIEVE_H

#include "Vector2D.h"
#include "Vector2DOrthonormalize.h"
#include "Vector2DTools.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Vector2DOrthonormalize<Real>::Vector2DOrthonormalize(const Vector2D& lhs, const Vector2D& rhs, const Real epsilon)
    : m_UVector{ lhs }, m_VVector{ rhs }, m_Epsilon{ epsilon }
{
    Generate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::Vector2DOrthonormalize<Real>::Generate()
{
    // 如果输入向量v0和v1，则Gram-Schmidt正交向量产生矢量u0和u1如下，
    //
    //   u0 = v0 / |v0|
    //   u1 = (v1 - (u0 * v1)u0) / |v1 - (u0 * v1)u0|
    //
    // 其中|A|表示向量A的长度和A * B表示向量A和B的点积

    // 计算 u0.
    m_UVector.Normalize(m_Epsilon);

    // 计算 u1.
    auto dot = Vector2DTools::DotProduct(m_UVector, m_VVector);

    MATHEMATICS_ASSERTION_1(m_Epsilon < Math::FAbs(dot), "输入向量必须是线性无关的！");

    m_VVector -= m_UVector * dot;
    m_VVector.Normalize(m_Epsilon);
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Vector2DOrthonormalize<Real>::IsValid() const noexcept
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
const Mathematics::Vector2D<Real> Mathematics::Vector2DOrthonormalize<Real>::GetUVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_UVector;
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Vector2DOrthonormalize<Real>::GetVVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_VVector;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_2D_ORTHONORMALIZE_ACHIEVE_H