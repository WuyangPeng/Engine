///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/12 20:42)

#ifndef MATHEMATICS_ALGEBRA_VECTOR_3D_ORTHONORMALIZE_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_VECTOR_3D_ORTHONORMALIZE_ACHIEVE_H

#include "Vector3D.h"
#include "Vector3DOrthonormalize.h"
#include "Vector3DTools.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Vector3DOrthonormalize<Real>::Vector3DOrthonormalize(const Vector3D& lhs, const Vector3D& mhs, const Vector3D& rhs, const Real epsilon)
    : m_UVector{ lhs }, m_VVector{ mhs }, m_WVector{ rhs }, m_Epsilon{ epsilon }
{
    Generate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Vector3DOrthonormalize<Real>::Vector3DOrthonormalize(const ContainerType& vectors, const Real epsilon)
    : m_UVector{ vectors.at(0) }, m_VVector{ vectors.at(1) }, m_WVector{ vectors.at(2) }, m_Epsilon{ epsilon }
{
    Generate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::Vector3DOrthonormalize<Real>::Generate()
{
    // 如果输入向量v0、v1和v2，则Gram-Schmidt正交向量产生矢量u0、u1和u2如下，
    //   u0 = v0 / |v0|
    //   u1 = (v1 - (u0 * v1)u0) / |v1 - (u0 * v1)u0|
    //   u2 = (v2 - (u0 * v2)u0 - (u1 * v2)u1) /
    //        |v2 - (u0 * v2)u0 - (u1 * v2)u1|
    //
    // 其中|A|表示向量A的长度和A * B表示向量A和B的点积

    // 计算 u0
    m_UVector.Normalize(m_Epsilon);

    // 计算 u1
    auto dotUV = Vector3DTools::DotProduct(m_UVector, m_VVector);

    MATHEMATICS_ASSERTION_1(m_Epsilon < Math::FAbs(dotUV), "输入向量必须是线性无关的！");

    m_VVector -= dotUV * m_UVector;
    m_VVector.Normalize(m_Epsilon);

    // 计算 u2
    auto dotVW = Vector3DTools::DotProduct(m_VVector, m_WVector);
    auto dotUW = Vector3DTools::DotProduct(m_UVector, m_WVector);

    m_WVector -= dotUW * m_UVector + dotVW * m_VVector;
    m_WVector.Normalize(m_Epsilon);
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Vector3DOrthonormalize<Real>::IsValid() const noexcept
{
    try
    {
        if (Math::FAbs(Vector3DTools::DotProduct(m_UVector, m_VVector)) <= m_Epsilon &&
            Math::FAbs(Vector3DTools::DotProduct(m_UVector, m_WVector)) <= m_Epsilon &&
            Math::FAbs(Vector3DTools::DotProduct(m_VVector, m_WVector)) <= m_Epsilon &&
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
const Mathematics::Vector3D<Real> Mathematics::Vector3DOrthonormalize<Real>::GetUVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_UVector;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3DOrthonormalize<Real>::GetVVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_VVector;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3DOrthonormalize<Real>::GetWVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_WVector;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_3D_ORTHONORMALIZE_ACHIEVE_H