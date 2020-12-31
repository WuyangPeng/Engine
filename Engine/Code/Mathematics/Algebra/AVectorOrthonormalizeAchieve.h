///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/03 18:27)

#ifndef MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMALIZE_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMALIZE_ACHIEVE_H

#include "AVectorDetail.h"
#include "AVectorOrthonormalize.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::AVectorOrthonormalize<Real>::AVectorOrthonormalize(const AVector& lhs, const AVector& mhs, const AVector& rhs, const Real epsilon)
    : m_UVector{ lhs }, m_VVector{ mhs }, m_WVector{ rhs }, m_Epsilon{ epsilon }
{
    Generate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::AVectorOrthonormalize<Real>::AVectorOrthonormalize(const std::vector<AVector> vectors, const Real epsilon)
    : m_UVector{ vectors.at(0) }, m_VVector{ vectors.at(1) }, m_WVector{ vectors.at(2) }, m_Epsilon{ epsilon }
{
    Generate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::AVectorOrthonormalize<Real>::Generate()
{
    // �����������v0��v1��v2����Gram-Schmidt������������ʸ��u0��u1��u2���£�
    //   u0 = v0 / |v0|
    //   u1 = (v1 - (u0 * v1)u0) / |v1 - (u0 * v1)u0|
    //   u2 = (v2 - (u0 * v2)u0 - (u1 * v2)u1) / |v2 - (u0 * v2)u0 - (u1 * v2)u1|
    //
    // ����|A|��ʾ����A�ĳ��Ⱥ�A * B��ʾ����A��B�ĵ��

    // ���� u0
    m_UVector.Normalize(m_Epsilon);

    // ���� u1
    auto dotUV = Dot(m_UVector, m_VVector);
    m_VVector -= dotUV * m_UVector;
    m_VVector.Normalize(m_Epsilon);

    // ���� u2
    auto dotVW = Dot(m_VVector, m_WVector);
    auto dotUW = Dot(m_UVector, m_WVector);
    m_WVector -= dotUW * m_UVector + dotVW * m_VVector;
    m_WVector.Normalize(m_Epsilon);
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::AVectorOrthonormalize<Real>::IsValid() const noexcept
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
const typename Mathematics::AVectorOrthonormalize<Real>::AVector Mathematics::AVectorOrthonormalize<Real>::GetUVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_UVector;
}

template <typename Real>
const typename Mathematics::AVectorOrthonormalize<Real>::AVector Mathematics::AVectorOrthonormalize<Real>::GetVVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_VVector;
}

template <typename Real>
const typename Mathematics::AVectorOrthonormalize<Real>::AVector Mathematics::AVectorOrthonormalize<Real>::GetWVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_WVector;
}

#endif  // MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMALIZE_ACHIEVE_H