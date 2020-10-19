// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.2.5 (2020/03/19 13:26)

#ifndef MATHEMATICS_ALGEBRA_MATRIX4_DETAIL_H
#define MATHEMATICS_ALGEBRA_MATRIX4_DETAIL_H

#include "AlgebraTraits.h"
#include "Matrix4.h"
#include "Vector3DTools.h"
#include "Vector4D.h"
#include "Vector4DTools.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

template <typename Real>
const Mathematics::Matrix4<Real> Mathematics::Matrix4<Real>::sm_Zero{ MatrixInitType::Zero };

template <typename Real>
const Mathematics::Matrix4<Real> Mathematics::Matrix4<Real>::sm_Identity{ MatrixInitType::Identity };

template <typename Real>
Mathematics::Matrix4<Real>::Matrix4(MatrixInitType flag)
    : m_Entry{}
{
    if (flag == MatrixInitType::Identity)
    {
        MakeIdentity();
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix4<Real>::Matrix4(Real member00, Real member01, Real member02, Real member03,
                                    Real member10, Real member11, Real member12, Real member13,
                                    Real member20, Real member21, Real member22, Real member23,
                                    Real member30, Real member31, Real member32, Real member33)
    : m_Entry{ member00, member01, member02, member03,
               member10, member11, member12, member13,
               member20, member21, member22, member23,
               member30, member31, member32, member33 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix4<Real>::Matrix4(const std::vector<Real>& entry, MatrixMajorFlags majorFlag)
    : m_Entry{}
{
    MATHEMATICS_ASSERTION_0(entry.size() == 16, "数据大小错误！");

    if (majorFlag == MatrixMajorFlags::Row)
    {
        m_Entry(0, 0) = entry[0];
        m_Entry(0, 1) = entry[1];
        m_Entry(0, 2) = entry[2];
        m_Entry(0, 3) = entry[3];
        m_Entry(1, 0) = entry[4];
        m_Entry(1, 1) = entry[5];
        m_Entry(1, 2) = entry[6];
        m_Entry(1, 3) = entry[7];
        m_Entry(2, 0) = entry[8];
        m_Entry(2, 1) = entry[9];
        m_Entry(2, 2) = entry[10];
        m_Entry(2, 3) = entry[11];
        m_Entry(3, 0) = entry[12];
        m_Entry(3, 1) = entry[13];
        m_Entry(3, 2) = entry[14];
        m_Entry(3, 3) = entry[15];
    }
    else
    {
        m_Entry(0, 0) = entry[0];
        m_Entry(0, 1) = entry[4];
        m_Entry(0, 2) = entry[8];
        m_Entry(0, 3) = entry[12];
        m_Entry(1, 0) = entry[1];
        m_Entry(1, 1) = entry[5];
        m_Entry(1, 2) = entry[9];
        m_Entry(1, 3) = entry[13];
        m_Entry(2, 0) = entry[2];
        m_Entry(2, 1) = entry[6];
        m_Entry(2, 2) = entry[10];
        m_Entry(2, 3) = entry[14];
        m_Entry(3, 0) = entry[3];
        m_Entry(3, 1) = entry[7];
        m_Entry(3, 2) = entry[11];
        m_Entry(3, 3) = entry[15];
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Matrix4<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::Matrix4<Real>::MakeZero()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Entry(0, 0) = Math::GetValue(0);
    m_Entry(0, 1) = Math::GetValue(0);
    m_Entry(0, 2) = Math::GetValue(0);
    m_Entry(0, 3) = Math::GetValue(0);
    m_Entry(1, 0) = Math::GetValue(0);
    m_Entry(1, 1) = Math::GetValue(0);
    m_Entry(1, 2) = Math::GetValue(0);
    m_Entry(1, 3) = Math::GetValue(0);
    m_Entry(2, 0) = Math::GetValue(0);
    m_Entry(2, 1) = Math::GetValue(0);
    m_Entry(2, 2) = Math::GetValue(0);
    m_Entry(2, 3) = Math::GetValue(0);
    m_Entry(3, 0) = Math::GetValue(0);
    m_Entry(3, 1) = Math::GetValue(0);
    m_Entry(3, 2) = Math::GetValue(0);
    m_Entry(3, 3) = Math::GetValue(0);
}

template <typename Real>
void Mathematics::Matrix4<Real>::MakeIdentity()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Entry(0, 0) = Math::GetValue(1);
    m_Entry(0, 1) = Math::GetValue(0);
    m_Entry(0, 2) = Math::GetValue(0);
    m_Entry(0, 3) = Math::GetValue(0);
    m_Entry(1, 0) = Math::GetValue(0);
    m_Entry(1, 1) = Math::GetValue(1);
    m_Entry(1, 2) = Math::GetValue(0);
    m_Entry(1, 3) = Math::GetValue(0);
    m_Entry(2, 0) = Math::GetValue(0);
    m_Entry(2, 1) = Math::GetValue(0);
    m_Entry(2, 2) = Math::GetValue(1);
    m_Entry(2, 3) = Math::GetValue(0);
    m_Entry(3, 0) = Math::GetValue(0);
    m_Entry(3, 1) = Math::GetValue(0);
    m_Entry(3, 2) = Math::GetValue(0);
    m_Entry(3, 3) = Math::GetValue(1);
}

template <typename Real>
const Real* Mathematics::Matrix4<Real>::operator[](int row) const
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_0(0 <= row && row < 4, "索引错误！");

    return m_Entry[row];
}

template <typename Real>
Real* Mathematics::Matrix4<Real>::operator[](int row)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_0(0 <= row && row < 4, "索引错误！");

    return m_Entry[row];
}

template <typename Real>
const Real& Mathematics::Matrix4<Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_0(0 <= row && row < 4, "索引错误！");
    MATHEMATICS_ASSERTION_0(0 <= column && column < 4, "索引错误！");

    return m_Entry(row, column);
}

template <typename Real>
Real& Mathematics::Matrix4<Real>::operator()(int row, int column)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_0(0 <= row && row < 4, "索引错误！");
    MATHEMATICS_ASSERTION_0(0 <= column && column < 4, "索引错误！");

    return m_Entry(row, column);
}

template <typename Real>
const Mathematics::Matrix4<Real> Mathematics::Matrix4<Real>::operator-() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix4<Real>{ -m_Entry(0, 0), -m_Entry(0, 1), -m_Entry(0, 2), -m_Entry(0, 3),
                          -m_Entry(1, 0), -m_Entry(1, 1), -m_Entry(1, 2), -m_Entry(1, 3),
                          -m_Entry(2, 0), -m_Entry(2, 1), -m_Entry(2, 2), -m_Entry(2, 3),
                          -m_Entry(3, 0), -m_Entry(3, 1), -m_Entry(3, 2), -m_Entry(3, 3) };
}

template <typename Real>
Mathematics::Matrix4<Real>& Mathematics::Matrix4<Real>::operator+=(const Matrix4& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Entry(0, 0) += rhs.m_Entry(0, 0);
    m_Entry(0, 1) += rhs.m_Entry(0, 1);
    m_Entry(0, 2) += rhs.m_Entry(0, 2);
    m_Entry(0, 3) += rhs.m_Entry(0, 3);
    m_Entry(1, 0) += rhs.m_Entry(1, 0);
    m_Entry(1, 1) += rhs.m_Entry(1, 1);
    m_Entry(1, 2) += rhs.m_Entry(1, 2);
    m_Entry(1, 3) += rhs.m_Entry(1, 3);
    m_Entry(2, 0) += rhs.m_Entry(2, 0);
    m_Entry(2, 1) += rhs.m_Entry(2, 1);
    m_Entry(2, 2) += rhs.m_Entry(2, 2);
    m_Entry(2, 3) += rhs.m_Entry(2, 3);
    m_Entry(3, 0) += rhs.m_Entry(3, 0);
    m_Entry(3, 1) += rhs.m_Entry(3, 1);
    m_Entry(3, 2) += rhs.m_Entry(3, 2);
    m_Entry(3, 3) += rhs.m_Entry(3, 3);

    return *this;
}

template <typename Real>
Mathematics::Matrix4<Real>& Mathematics::Matrix4<Real>::operator-=(const Matrix4& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Entry(0, 0) -= rhs.m_Entry(0, 0);
    m_Entry(0, 1) -= rhs.m_Entry(0, 1);
    m_Entry(0, 2) -= rhs.m_Entry(0, 2);
    m_Entry(0, 3) -= rhs.m_Entry(0, 3);
    m_Entry(1, 0) -= rhs.m_Entry(1, 0);
    m_Entry(1, 1) -= rhs.m_Entry(1, 1);
    m_Entry(1, 2) -= rhs.m_Entry(1, 2);
    m_Entry(1, 3) -= rhs.m_Entry(1, 3);
    m_Entry(2, 0) -= rhs.m_Entry(2, 0);
    m_Entry(2, 1) -= rhs.m_Entry(2, 1);
    m_Entry(2, 2) -= rhs.m_Entry(2, 2);
    m_Entry(2, 3) -= rhs.m_Entry(2, 3);
    m_Entry(3, 0) -= rhs.m_Entry(3, 0);
    m_Entry(3, 1) -= rhs.m_Entry(3, 1);
    m_Entry(3, 2) -= rhs.m_Entry(3, 2);
    m_Entry(3, 3) -= rhs.m_Entry(3, 3);

    return *this;
}

template <typename Real>
Mathematics::Matrix4<Real>& Mathematics::Matrix4<Real>::operator*=(Real scalar)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Entry(0, 0) *= scalar;
    m_Entry(0, 1) *= scalar;
    m_Entry(0, 2) *= scalar;
    m_Entry(0, 3) *= scalar;
    m_Entry(1, 0) *= scalar;
    m_Entry(1, 1) *= scalar;
    m_Entry(1, 2) *= scalar;
    m_Entry(1, 3) *= scalar;
    m_Entry(2, 0) *= scalar;
    m_Entry(2, 1) *= scalar;
    m_Entry(2, 2) *= scalar;
    m_Entry(2, 3) *= scalar;
    m_Entry(3, 0) *= scalar;
    m_Entry(3, 1) *= scalar;
    m_Entry(3, 2) *= scalar;
    m_Entry(3, 3) *= scalar;

    return *this;
}

template <typename Real>
Mathematics::Matrix4<Real>& Mathematics::Matrix4<Real>::operator/=(Real scalar)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (Math::GetZeroTolerance() < Math::FAbs(scalar))
    {
        m_Entry(0, 0) /= scalar;
        m_Entry(0, 1) /= scalar;
        m_Entry(0, 2) /= scalar;
        m_Entry(0, 3) /= scalar;
        m_Entry(1, 0) /= scalar;
        m_Entry(1, 1) /= scalar;
        m_Entry(1, 2) /= scalar;
        m_Entry(1, 3) /= scalar;
        m_Entry(2, 0) /= scalar;
        m_Entry(2, 1) /= scalar;
        m_Entry(2, 2) /= scalar;
        m_Entry(2, 3) /= scalar;
        m_Entry(3, 0) /= scalar;
        m_Entry(3, 1) /= scalar;
        m_Entry(3, 2) /= scalar;
        m_Entry(3, 3) /= scalar;
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "除零错误！");

        m_Entry(0, 0) = Math::sm_MaxReal;
        m_Entry(0, 1) = Math::sm_MaxReal;
        m_Entry(0, 2) = Math::sm_MaxReal;
        m_Entry(0, 3) = Math::sm_MaxReal;
        m_Entry(1, 0) = Math::sm_MaxReal;
        m_Entry(1, 1) = Math::sm_MaxReal;
        m_Entry(1, 2) = Math::sm_MaxReal;
        m_Entry(1, 3) = Math::sm_MaxReal;
        m_Entry(2, 0) = Math::sm_MaxReal;
        m_Entry(2, 1) = Math::sm_MaxReal;
        m_Entry(2, 2) = Math::sm_MaxReal;
        m_Entry(2, 3) = Math::sm_MaxReal;
        m_Entry(3, 0) = Math::sm_MaxReal;
        m_Entry(3, 1) = Math::sm_MaxReal;
        m_Entry(3, 2) = Math::sm_MaxReal;
        m_Entry(3, 3) = Math::sm_MaxReal;
    }

    return *this;
}

template <typename Real>
Real Mathematics::Matrix4<Real>::QuadraticForm(const Vector4D& lhs, const Vector4D& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return Vector4DTools::DotProduct(lhs, (*this) * rhs);
}

template <typename Real>
const Mathematics::Matrix4<Real> Mathematics::Matrix4<Real>::Transpose() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix4<Real>{ m_Entry(0, 0), m_Entry(1, 0), m_Entry(2, 0), m_Entry(3, 0),
                          m_Entry(0, 1), m_Entry(1, 1), m_Entry(2, 1), m_Entry(3, 1),
                          m_Entry(0, 2), m_Entry(1, 2), m_Entry(2, 2), m_Entry(3, 2),
                          m_Entry(0, 3), m_Entry(1, 3), m_Entry(2, 3), m_Entry(3, 3) };
}

template <typename Real>
Mathematics::Matrix4<Real>& Mathematics::Matrix4<Real>::operator*=(const Matrix4& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    *this = *this * rhs;

    return *this;
}

template <typename Real>
const Mathematics::Matrix4<Real> Mathematics::Matrix4<Real>::Inverse(const Real epsilon) const
{
    // 游戏编程精粹1 02 isensee存在另一种算法。

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto a0 = m_Entry(0, 0) * m_Entry(1, 1) - m_Entry(0, 1) * m_Entry(1, 0);
    auto a1 = m_Entry(0, 0) * m_Entry(1, 2) - m_Entry(0, 2) * m_Entry(1, 0);
    auto a2 = m_Entry(0, 0) * m_Entry(1, 3) - m_Entry(0, 3) * m_Entry(1, 0);
    auto a3 = m_Entry(0, 1) * m_Entry(1, 2) - m_Entry(0, 2) * m_Entry(1, 1);
    auto a4 = m_Entry(0, 1) * m_Entry(1, 3) - m_Entry(0, 3) * m_Entry(1, 1);
    auto a5 = m_Entry(0, 2) * m_Entry(1, 3) - m_Entry(0, 3) * m_Entry(1, 2);
    auto b0 = m_Entry(2, 0) * m_Entry(3, 1) - m_Entry(2, 1) * m_Entry(3, 0);
    auto b1 = m_Entry(2, 0) * m_Entry(3, 2) - m_Entry(2, 2) * m_Entry(3, 0);
    auto b2 = m_Entry(2, 0) * m_Entry(3, 3) - m_Entry(2, 3) * m_Entry(3, 0);
    auto b3 = m_Entry(2, 1) * m_Entry(3, 2) - m_Entry(2, 2) * m_Entry(3, 1);
    auto b4 = m_Entry(2, 1) * m_Entry(3, 3) - m_Entry(2, 3) * m_Entry(3, 1);
    auto b5 = m_Entry(2, 2) * m_Entry(3, 3) - m_Entry(2, 3) * m_Entry(3, 2);

    auto det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;
    if (epsilon < Math::FAbs(det))
    {
        Matrix4 adjoint{ m_Entry(1, 1) * b5 - m_Entry(1, 2) * b4 + m_Entry(1, 3) * b3,
                         -m_Entry(0, 1) * b5 + m_Entry(0, 2) * b4 - m_Entry(0, 3) * b3,
                         m_Entry(3, 1) * a5 - m_Entry(3, 2) * a4 + m_Entry(3, 3) * a3,
                         -m_Entry(2, 1) * a5 + m_Entry(2, 2) * a4 - m_Entry(2, 3) * a3,
                         -m_Entry(1, 0) * b5 + m_Entry(1, 2) * b2 - m_Entry(1, 3) * b1,
                         m_Entry(0, 0) * b5 - m_Entry(0, 2) * b2 + m_Entry(0, 3) * b1,
                         -m_Entry(3, 0) * a5 + m_Entry(3, 2) * a2 - m_Entry(3, 3) * a1,
                         m_Entry(2, 0) * a5 - m_Entry(2, 2) * a2 + m_Entry(2, 3) * a1,
                         m_Entry(1, 0) * b4 - m_Entry(1, 1) * b2 + m_Entry(1, 3) * b0,
                         -m_Entry(0, 0) * b4 + m_Entry(0, 1) * b2 - m_Entry(0, 3) * b0,
                         m_Entry(3, 0) * a4 - m_Entry(3, 1) * a2 + m_Entry(3, 3) * a0,
                         -m_Entry(2, 0) * a4 + m_Entry(2, 1) * a2 - m_Entry(2, 3) * a0,
                         -m_Entry(1, 0) * b3 + m_Entry(1, 1) * b1 - m_Entry(1, 2) * b0,
                         m_Entry(0, 0) * b3 - m_Entry(0, 1) * b1 + m_Entry(0, 2) * b0,
                         -m_Entry(3, 0) * a3 + m_Entry(3, 1) * a1 - m_Entry(3, 2) * a0,
                         m_Entry(2, 0) * a3 - m_Entry(2, 1) * a1 + m_Entry(2, 2) * a0 };

        adjoint /= det;

        return adjoint;
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "该矩阵不存在逆矩阵！");

        return sm_Zero;
    }
}

template <typename Real>
const Mathematics::Matrix4<Real> Mathematics::Matrix4<Real>::Adjoint() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto a0 = m_Entry(0, 0) * m_Entry(1, 1) - m_Entry(0, 1) * m_Entry(1, 0);
    auto a1 = m_Entry(0, 0) * m_Entry(1, 2) - m_Entry(0, 2) * m_Entry(1, 0);
    auto a2 = m_Entry(0, 0) * m_Entry(1, 3) - m_Entry(0, 3) * m_Entry(1, 0);
    auto a3 = m_Entry(0, 1) * m_Entry(1, 2) - m_Entry(0, 2) * m_Entry(1, 1);
    auto a4 = m_Entry(0, 1) * m_Entry(1, 3) - m_Entry(0, 3) * m_Entry(1, 1);
    auto a5 = m_Entry(0, 2) * m_Entry(1, 3) - m_Entry(0, 3) * m_Entry(1, 2);
    auto b0 = m_Entry(2, 0) * m_Entry(3, 1) - m_Entry(2, 1) * m_Entry(3, 0);
    auto b1 = m_Entry(2, 0) * m_Entry(3, 2) - m_Entry(2, 2) * m_Entry(3, 0);
    auto b2 = m_Entry(2, 0) * m_Entry(3, 3) - m_Entry(2, 3) * m_Entry(3, 0);
    auto b3 = m_Entry(2, 1) * m_Entry(3, 2) - m_Entry(2, 2) * m_Entry(3, 1);
    auto b4 = m_Entry(2, 1) * m_Entry(3, 3) - m_Entry(2, 3) * m_Entry(3, 1);
    auto b5 = m_Entry(2, 2) * m_Entry(3, 3) - m_Entry(2, 3) * m_Entry(3, 2);

    return Matrix4<Real>{ m_Entry(1, 1) * b5 - m_Entry(1, 2) * b4 + m_Entry(1, 3) * b3,
                          -m_Entry(0, 1) * b5 + m_Entry(0, 2) * b4 - m_Entry(0, 3) * b3,
                          m_Entry(3, 1) * a5 - m_Entry(3, 2) * a4 + m_Entry(3, 3) * a3,
                          -m_Entry(2, 1) * a5 + m_Entry(2, 2) * a4 - m_Entry(2, 3) * a3,
                          -m_Entry(1, 0) * b5 + m_Entry(1, 2) * b2 - m_Entry(1, 3) * b1,
                          m_Entry(0, 0) * b5 - m_Entry(0, 2) * b2 + m_Entry(0, 3) * b1,
                          -m_Entry(3, 0) * a5 + m_Entry(3, 2) * a2 - m_Entry(3, 3) * a1,
                          m_Entry(2, 0) * a5 - m_Entry(2, 2) * a2 + m_Entry(2, 3) * a1,
                          m_Entry(1, 0) * b4 - m_Entry(1, 1) * b2 + m_Entry(1, 3) * b0,
                          -m_Entry(0, 0) * b4 + m_Entry(0, 1) * b2 - m_Entry(0, 3) * b0,
                          m_Entry(3, 0) * a4 - m_Entry(3, 1) * a2 + m_Entry(3, 3) * a0,
                          -m_Entry(2, 0) * a4 + m_Entry(2, 1) * a2 - m_Entry(2, 3) * a0,
                          -m_Entry(1, 0) * b3 + m_Entry(1, 1) * b1 - m_Entry(1, 2) * b0,
                          m_Entry(0, 0) * b3 - m_Entry(0, 1) * b1 + m_Entry(0, 2) * b0,
                          -m_Entry(3, 0) * a3 + m_Entry(3, 1) * a1 - m_Entry(3, 2) * a0,
                          m_Entry(2, 0) * a3 - m_Entry(2, 1) * a1 + m_Entry(2, 2) * a0 };
}

template <typename Real>
Real Mathematics::Matrix4<Real>::Determinant() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto a0 = m_Entry(0, 0) * m_Entry(1, 1) - m_Entry(0, 1) * m_Entry(1, 0);
    auto a1 = m_Entry(0, 0) * m_Entry(1, 2) - m_Entry(0, 2) * m_Entry(1, 0);
    auto a2 = m_Entry(0, 0) * m_Entry(1, 3) - m_Entry(0, 3) * m_Entry(1, 0);
    auto a3 = m_Entry(0, 1) * m_Entry(1, 2) - m_Entry(0, 2) * m_Entry(1, 1);
    auto a4 = m_Entry(0, 1) * m_Entry(1, 3) - m_Entry(0, 3) * m_Entry(1, 1);
    auto a5 = m_Entry(0, 2) * m_Entry(1, 3) - m_Entry(0, 3) * m_Entry(1, 2);
    auto b0 = m_Entry(2, 0) * m_Entry(3, 1) - m_Entry(2, 1) * m_Entry(3, 0);
    auto b1 = m_Entry(2, 0) * m_Entry(3, 2) - m_Entry(2, 2) * m_Entry(3, 0);
    auto b2 = m_Entry(2, 0) * m_Entry(3, 3) - m_Entry(2, 3) * m_Entry(3, 0);
    auto b3 = m_Entry(2, 1) * m_Entry(3, 2) - m_Entry(2, 2) * m_Entry(3, 1);
    auto b4 = m_Entry(2, 1) * m_Entry(3, 3) - m_Entry(2, 3) * m_Entry(3, 1);
    auto b5 = m_Entry(2, 2) * m_Entry(3, 3) - m_Entry(2, 3) * m_Entry(3, 2);

    auto det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;

    return det;
}

template <typename Real>
void Mathematics::Matrix4<Real>::MakeObliqueProjection(const Vector3D& normal, const Vector3D& origin, const Vector3D& direction)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_1(normal.IsNormalize() && direction.IsNormalize(), "normal和direction必须是单位向量！");

    // 投影平面是Dot(N,X-P) = 0 ，
    // 其中N是一个3×1个单位长度的法线向量，
    // P是一个3×1点在平面。
    // 投影是倾斜的平面，3×1向量D方向。
    // 必定Dot(N,D)不是零，此投影有意义。
    // 给定一个3×1点U，计算线 U+t*D和平面的交叉点t = -Dot(N,U-P)/Dot(N,D)。
    // 然后，
    //
    //   projection(U) = P + [I - D*N^T/Dot(N,D)]*(U-P)
    //
    // 一个4×4的齐次变换矩阵是
    //
    //       +-                               -+
    //   M = | D*N^T - Dot(N,D)*I   -Dot(N,P)D |
    //       |          0^T          -Dot(N,D) |
    //       +-                               -+
    //
    // 其中M适用于[U^T 1]^T 为  M*[U^T 1]^T。
    // 该矩阵被选择为每当Dot(N,D) < 0使得M[3][3] > 0
    // （投影到平面上的“正面侧”）。

    auto dotNormalDirection = Vector3DTools::DotProduct(normal, direction);
    auto dotNormalOrigin = Vector3DTools::DotProduct(normal, origin);

    m_Entry(0, 0) = direction[0] * normal[0] - dotNormalDirection;
    m_Entry(0, 1) = direction[0] * normal[1];
    m_Entry(0, 2) = direction[0] * normal[2];
    m_Entry(0, 3) = -dotNormalOrigin * direction[0];
    m_Entry(1, 0) = direction[1] * normal[0];
    m_Entry(1, 1) = direction[1] * normal[1] - dotNormalDirection;
    m_Entry(1, 2) = direction[1] * normal[2];
    m_Entry(1, 3) = -dotNormalOrigin * direction[1];
    m_Entry(2, 0) = direction[2] * normal[0];
    m_Entry(2, 1) = direction[2] * normal[1];
    m_Entry(2, 2) = direction[2] * normal[2] - dotNormalDirection;
    m_Entry(2, 3) = -dotNormalOrigin * direction[2];
    m_Entry(3, 0) = Math::GetValue(0);
    m_Entry(3, 1) = Math::GetValue(0);
    m_Entry(3, 2) = Math::GetValue(0);
    m_Entry(3, 3) = -dotNormalDirection;
}

template <typename Real>
void Mathematics::Matrix4<Real>::MakePerspectiveProjection(const Vector3D& normal, const Vector3D& origin, const Vector3D& eye)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_1(normal.IsNormalize(), "normal必须是单位向量！");

    //     +-                                                 -+
    // M = | Dot(N,E-P)*I - E*N^T    -(Dot(N,E-P)*I - E*N^T)*E |
    //     |        -N^t                      Dot(N,E)         |
    //     +-                                                 -+
    //
    // 其中E为眼点，P为平面上的一个点，而N是单位长度的平面法线。

    auto dotNormalDirection = Vector3DTools::DotProduct(normal, eye - origin);

    m_Entry(0, 0) = dotNormalDirection - eye[0] * normal[0];
    m_Entry(0, 1) = -eye[0] * normal[1];
    m_Entry(0, 2) = -eye[0] * normal[2];
    m_Entry(0, 3) = -(m_Entry(0, 0) * eye[0] + m_Entry(0, 1) * eye[1] + m_Entry(0, 2) * eye[2]);
    m_Entry(1, 0) = -eye[1] * normal[0];
    m_Entry(1, 1) = dotNormalDirection - eye[1] * normal[1];
    m_Entry(1, 2) = -eye[1] * normal[2];
    m_Entry(1, 3) = -(m_Entry(1, 0) * eye[0] + m_Entry(1, 1) * eye[1] + m_Entry(1, 2) * eye[2]);
    m_Entry(2, 0) = -eye[2] * normal[0];
    m_Entry(2, 1) = -eye[2] * normal[1];
    m_Entry(2, 2) = dotNormalDirection - eye[2] * normal[2];
    m_Entry(2, 3) = -(m_Entry(2, 0) * eye[0] + m_Entry(2, 1) * eye[1] + m_Entry(2, 2) * eye[2]);
    m_Entry(3, 0) = -normal[0];
    m_Entry(3, 1) = -normal[1];
    m_Entry(3, 2) = -normal[2];
    m_Entry(3, 3) = Vector3DTools::DotProduct(normal, eye);
}

template <typename Real>
void Mathematics::Matrix4<Real>::MakeReflection(const Vector3D& normal, const Vector3D& origin)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_1(normal.IsNormalize(), "normal必须是单位向量！");

    //     +-                         -+
    // M = | I-2*N*N^T    2*Dot(N,P)*N |
    //     |     0^T            1      |
    //     +-                         -+
    //
    // 其中P是平面上的点，N是一个单位长度的平面法线。

    auto twoDotNormalOrigin = static_cast<Real>(2) * Vector3DTools::DotProduct(normal, origin);

    m_Entry(0, 0) = Math::GetValue(1) - static_cast<Real>(2) * normal[0] * normal[0];
    m_Entry(0, 1) = -static_cast<Real>(2) * normal[0] * normal[1];
    m_Entry(0, 2) = -static_cast<Real>(2) * normal[0] * normal[2];
    m_Entry(0, 3) = twoDotNormalOrigin * normal[0];
    m_Entry(1, 0) = -static_cast<Real>(2) * normal[1] * normal[0];
    m_Entry(1, 1) = Math::GetValue(1) - static_cast<Real>(2) * normal[1] * normal[1];
    m_Entry(1, 2) = -static_cast<Real>(2) * normal[1] * normal[2];
    m_Entry(1, 3) = twoDotNormalOrigin * normal[1];
    m_Entry(2, 0) = -static_cast<Real>(2) * normal[2] * normal[0];
    m_Entry(2, 1) = -static_cast<Real>(2) * normal[2] * normal[1];
    m_Entry(2, 2) = Math::GetValue(1) - static_cast<Real>(2) * normal[2] * normal[2];
    m_Entry(2, 3) = twoDotNormalOrigin * normal[2];
    m_Entry(3, 0) = Math::GetValue(0);
    m_Entry(3, 1) = Math::GetValue(0);
    m_Entry(3, 2) = Math::GetValue(0);
    m_Entry(3, 3) = Math::GetValue(1);
}

template <typename Real>
const Mathematics::Vector4D<Real> Mathematics ::operator*(const Matrix4<Real>& matrix, const Vector4D<Real>& vector)
{
    return Vector4D<Real>{ matrix(0, 0) * vector[0] + matrix(0, 1) * vector[1] + matrix(0, 2) * vector[2] + matrix(0, 3) * vector[3],
                           matrix(1, 0) * vector[0] + matrix(1, 1) * vector[1] + matrix(1, 2) * vector[2] + matrix(1, 3) * vector[3],
                           matrix(2, 0) * vector[0] + matrix(2, 1) * vector[1] + matrix(2, 2) * vector[2] + matrix(2, 3) * vector[3],
                           matrix(3, 0) * vector[0] + matrix(3, 1) * vector[1] + matrix(3, 2) * vector[2] + matrix(3, 3) * vector[3] };
}

template <typename Real>
const Mathematics::Vector4D<Real> Mathematics ::operator*(const Vector4D<Real>& vector, const Matrix4<Real>& matrix)
{
    return Vector4D<Real>{ vector[0] * matrix(0, 0) + vector[1] * matrix(1, 0) + vector[2] * matrix(2, 0) + vector[3] * matrix(3, 0),
                           vector[0] * matrix(0, 1) + vector[1] * matrix(1, 1) + vector[2] * matrix(2, 1) + vector[3] * matrix(3, 1),
                           vector[0] * matrix(0, 2) + vector[1] * matrix(1, 2) + vector[2] * matrix(2, 2) + vector[3] * matrix(3, 2),
                           vector[0] * matrix(0, 3) + vector[1] * matrix(1, 3) + vector[2] * matrix(2, 3) + vector[3] * matrix(3, 3) };
}

template <typename Real>
const Mathematics::Matrix4<Real> Mathematics ::operator*(const Matrix4<Real>& lhs, const Matrix4<Real>& rhs)
{
    // A * B
    return Matrix4<Real>{ lhs(0, 0) * rhs(0, 0) + lhs(0, 1) * rhs(1, 0) + lhs(0, 2) * rhs(2, 0) + lhs(0, 3) * rhs(3, 0),
                          lhs(0, 0) * rhs(0, 1) + lhs(0, 1) * rhs(1, 1) + lhs(0, 2) * rhs(2, 1) + lhs(0, 3) * rhs(3, 1),
                          lhs(0, 0) * rhs(0, 2) + lhs(0, 1) * rhs(1, 2) + lhs(0, 2) * rhs(2, 2) + lhs(0, 3) * rhs(3, 2),
                          lhs(0, 0) * rhs(0, 3) + lhs(0, 1) * rhs(1, 3) + lhs(0, 2) * rhs(2, 3) + lhs(0, 3) * rhs(3, 3),
                          lhs(1, 0) * rhs(0, 0) + lhs(1, 1) * rhs(1, 0) + lhs(1, 2) * rhs(2, 0) + lhs(1, 3) * rhs(3, 0),
                          lhs(1, 0) * rhs(0, 1) + lhs(1, 1) * rhs(1, 1) + lhs(1, 2) * rhs(2, 1) + lhs(1, 3) * rhs(3, 1),
                          lhs(1, 0) * rhs(0, 2) + lhs(1, 1) * rhs(1, 2) + lhs(1, 2) * rhs(2, 2) + lhs(1, 3) * rhs(3, 2),
                          lhs(1, 0) * rhs(0, 3) + lhs(1, 1) * rhs(1, 3) + lhs(1, 2) * rhs(2, 3) + lhs(1, 3) * rhs(3, 3),
                          lhs(2, 0) * rhs(0, 0) + lhs(2, 1) * rhs(1, 0) + lhs(2, 2) * rhs(2, 0) + lhs(2, 3) * rhs(3, 0),
                          lhs(2, 0) * rhs(0, 1) + lhs(2, 1) * rhs(1, 1) + lhs(2, 2) * rhs(2, 1) + lhs(2, 3) * rhs(3, 1),
                          lhs(2, 0) * rhs(0, 2) + lhs(2, 1) * rhs(1, 2) + lhs(2, 2) * rhs(2, 2) + lhs(2, 3) * rhs(3, 2),
                          lhs(2, 0) * rhs(0, 3) + lhs(2, 1) * rhs(1, 3) + lhs(2, 2) * rhs(2, 3) + lhs(2, 3) * rhs(3, 3),
                          lhs(3, 0) * rhs(0, 0) + lhs(3, 1) * rhs(1, 0) + lhs(3, 2) * rhs(2, 0) + lhs(3, 3) * rhs(3, 0),
                          lhs(3, 0) * rhs(0, 1) + lhs(3, 1) * rhs(1, 1) + lhs(3, 2) * rhs(2, 1) + lhs(3, 3) * rhs(3, 1),
                          lhs(3, 0) * rhs(0, 2) + lhs(3, 1) * rhs(1, 2) + lhs(3, 2) * rhs(2, 2) + lhs(3, 3) * rhs(3, 2),
                          lhs(3, 0) * rhs(0, 3) + lhs(3, 1) * rhs(1, 3) + lhs(3, 2) * rhs(2, 3) + lhs(3, 3) * rhs(3, 3) };
}

template <typename Real>
const Mathematics::Matrix4<Real> Mathematics ::TransposeTimes(const Matrix4<Real>& lhs, const Matrix4<Real>& rhs)
{
    // A^T * B
    return Matrix4<Real>{ lhs(0, 0) * rhs(0, 0) + lhs(1, 0) * rhs(1, 0) + lhs(2, 0) * rhs(2, 0) + lhs(3, 0) * rhs(3, 0),
                          lhs(0, 0) * rhs(0, 1) + lhs(1, 0) * rhs(1, 1) + lhs(2, 0) * rhs(2, 1) + lhs(3, 0) * rhs(3, 1),
                          lhs(0, 0) * rhs(0, 2) + lhs(1, 0) * rhs(1, 2) + lhs(2, 0) * rhs(2, 2) + lhs(3, 0) * rhs(3, 2),
                          lhs(0, 0) * rhs(0, 3) + lhs(1, 0) * rhs(1, 3) + lhs(2, 0) * rhs(2, 3) + lhs(3, 0) * rhs(3, 3),
                          lhs(0, 1) * rhs(0, 0) + lhs(1, 1) * rhs(1, 0) + lhs(2, 1) * rhs(2, 0) + lhs(3, 1) * rhs(3, 0),
                          lhs(0, 1) * rhs(0, 1) + lhs(1, 1) * rhs(1, 1) + lhs(2, 1) * rhs(2, 1) + lhs(3, 1) * rhs(3, 1),
                          lhs(0, 1) * rhs(0, 2) + lhs(1, 1) * rhs(1, 2) + lhs(2, 1) * rhs(2, 2) + lhs(3, 1) * rhs(3, 2),
                          lhs(0, 1) * rhs(0, 3) + lhs(1, 1) * rhs(1, 3) + lhs(2, 1) * rhs(2, 3) + lhs(3, 1) * rhs(3, 3),
                          lhs(0, 2) * rhs(0, 0) + lhs(1, 2) * rhs(1, 0) + lhs(2, 2) * rhs(2, 0) + lhs(3, 2) * rhs(3, 0),
                          lhs(0, 2) * rhs(0, 1) + lhs(1, 2) * rhs(1, 1) + lhs(2, 2) * rhs(2, 1) + lhs(3, 2) * rhs(3, 1),
                          lhs(0, 2) * rhs(0, 2) + lhs(1, 2) * rhs(1, 2) + lhs(2, 2) * rhs(2, 2) + lhs(3, 2) * rhs(3, 2),
                          lhs(0, 2) * rhs(0, 3) + lhs(1, 2) * rhs(1, 3) + lhs(2, 2) * rhs(2, 3) + lhs(3, 2) * rhs(3, 3),
                          lhs(0, 3) * rhs(0, 0) + lhs(1, 3) * rhs(1, 0) + lhs(2, 3) * rhs(2, 0) + lhs(3, 3) * rhs(3, 0),
                          lhs(0, 3) * rhs(0, 1) + lhs(1, 3) * rhs(1, 1) + lhs(2, 3) * rhs(2, 1) + lhs(3, 3) * rhs(3, 1),
                          lhs(0, 3) * rhs(0, 2) + lhs(1, 3) * rhs(1, 2) + lhs(2, 3) * rhs(2, 2) + lhs(3, 3) * rhs(3, 2),
                          lhs(0, 3) * rhs(0, 3) + lhs(1, 3) * rhs(1, 3) + lhs(2, 3) * rhs(2, 3) + lhs(3, 3) * rhs(3, 3) };
}

template <typename Real>
const Mathematics::Matrix4<Real> Mathematics ::TimesTranspose(const Matrix4<Real>& lhs, const Matrix4<Real>& rhs)
{
    // A * B^T
    return Matrix4<Real>{ lhs(0, 0) * rhs(0, 0) + lhs(0, 1) * rhs(0, 1) + lhs(0, 2) * rhs(0, 2) + lhs(0, 3) * rhs(0, 3),
                          lhs(0, 0) * rhs(1, 0) + lhs(0, 1) * rhs(1, 1) + lhs(0, 2) * rhs(1, 2) + lhs(0, 3) * rhs(1, 3),
                          lhs(0, 0) * rhs(2, 0) + lhs(0, 1) * rhs(2, 1) + lhs(0, 2) * rhs(2, 2) + lhs(0, 3) * rhs(2, 3),
                          lhs(0, 0) * rhs(3, 0) + lhs(0, 1) * rhs(3, 1) + lhs(0, 2) * rhs(3, 2) + lhs(0, 3) * rhs(3, 3),
                          lhs(1, 0) * rhs(0, 0) + lhs(1, 1) * rhs(0, 1) + lhs(1, 2) * rhs(0, 2) + lhs(1, 3) * rhs(0, 3),
                          lhs(1, 0) * rhs(1, 0) + lhs(1, 1) * rhs(1, 1) + lhs(1, 2) * rhs(1, 2) + lhs(1, 3) * rhs(1, 3),
                          lhs(1, 0) * rhs(2, 0) + lhs(1, 1) * rhs(2, 1) + lhs(1, 2) * rhs(2, 2) + lhs(1, 3) * rhs(2, 3),
                          lhs(1, 0) * rhs(3, 0) + lhs(1, 1) * rhs(3, 1) + lhs(1, 2) * rhs(3, 2) + lhs(1, 3) * rhs(3, 3),
                          lhs(2, 0) * rhs(0, 0) + lhs(2, 1) * rhs(0, 1) + lhs(2, 2) * rhs(0, 2) + lhs(2, 3) * rhs(0, 3),
                          lhs(2, 0) * rhs(1, 0) + lhs(2, 1) * rhs(1, 1) + lhs(2, 2) * rhs(1, 2) + lhs(2, 3) * rhs(1, 3),
                          lhs(2, 0) * rhs(2, 0) + lhs(2, 1) * rhs(2, 1) + lhs(2, 2) * rhs(2, 2) + lhs(2, 3) * rhs(2, 3),
                          lhs(2, 0) * rhs(3, 0) + lhs(2, 1) * rhs(3, 1) + lhs(2, 2) * rhs(3, 2) + lhs(2, 3) * rhs(3, 3),
                          lhs(3, 0) * rhs(0, 0) + lhs(3, 1) * rhs(0, 1) + lhs(3, 2) * rhs(0, 2) + lhs(3, 3) * rhs(0, 3),
                          lhs(3, 0) * rhs(1, 0) + lhs(3, 1) * rhs(1, 1) + lhs(3, 2) * rhs(1, 2) + lhs(3, 3) * rhs(1, 3),
                          lhs(3, 0) * rhs(2, 0) + lhs(3, 1) * rhs(2, 1) + lhs(3, 2) * rhs(2, 2) + lhs(3, 3) * rhs(2, 3),
                          lhs(3, 0) * rhs(3, 0) + lhs(3, 1) * rhs(3, 1) + lhs(3, 2) * rhs(3, 2) + lhs(3, 3) * rhs(3, 3) };
}

template <typename Real>
const Mathematics::Matrix4<Real> Mathematics ::TransposeTimesTranspose(const Matrix4<Real>& lhs, const Matrix4<Real>& rhs)
{
    // A^T * B^T
    return Matrix4<Real>{ lhs(0, 0) * rhs(0, 0) + lhs(1, 0) * rhs(0, 1) + lhs(2, 0) * rhs(0, 2) + lhs(3, 0) * rhs(0, 3),
                          lhs(0, 0) * rhs(1, 0) + lhs(1, 0) * rhs(1, 1) + lhs(2, 0) * rhs(1, 2) + lhs(3, 0) * rhs(1, 3),
                          lhs(0, 0) * rhs(2, 0) + lhs(1, 0) * rhs(2, 1) + lhs(2, 0) * rhs(2, 2) + lhs(3, 0) * rhs(2, 3),
                          lhs(0, 0) * rhs(3, 0) + lhs(1, 0) * rhs(3, 1) + lhs(2, 0) * rhs(3, 2) + lhs(3, 0) * rhs(3, 3),
                          lhs(0, 1) * rhs(0, 0) + lhs(1, 1) * rhs(0, 1) + lhs(2, 1) * rhs(0, 2) + lhs(3, 1) * rhs(0, 3),
                          lhs(0, 1) * rhs(1, 0) + lhs(1, 1) * rhs(1, 1) + lhs(2, 1) * rhs(1, 2) + lhs(3, 1) * rhs(1, 3),
                          lhs(0, 1) * rhs(2, 0) + lhs(1, 1) * rhs(2, 1) + lhs(2, 1) * rhs(2, 2) + lhs(3, 1) * rhs(2, 3),
                          lhs(0, 1) * rhs(3, 0) + lhs(1, 1) * rhs(3, 1) + lhs(2, 1) * rhs(3, 2) + lhs(3, 1) * rhs(3, 3),
                          lhs(0, 2) * rhs(0, 0) + lhs(1, 2) * rhs(0, 1) + lhs(2, 2) * rhs(0, 2) + lhs(3, 2) * rhs(0, 3),
                          lhs(0, 2) * rhs(1, 0) + lhs(1, 2) * rhs(1, 1) + lhs(2, 2) * rhs(1, 2) + lhs(3, 2) * rhs(1, 3),
                          lhs(0, 2) * rhs(2, 0) + lhs(1, 2) * rhs(2, 1) + lhs(2, 2) * rhs(2, 2) + lhs(3, 2) * rhs(2, 3),
                          lhs(0, 2) * rhs(3, 0) + lhs(1, 2) * rhs(3, 1) + lhs(2, 2) * rhs(3, 2) + lhs(3, 2) * rhs(3, 3),
                          lhs(0, 3) * rhs(0, 0) + lhs(1, 3) * rhs(0, 1) + lhs(2, 3) * rhs(0, 2) + lhs(3, 3) * rhs(0, 3),
                          lhs(0, 3) * rhs(1, 0) + lhs(1, 3) * rhs(1, 1) + lhs(2, 3) * rhs(1, 2) + lhs(3, 3) * rhs(1, 3),
                          lhs(0, 3) * rhs(2, 0) + lhs(1, 3) * rhs(2, 1) + lhs(2, 3) * rhs(2, 2) + lhs(3, 3) * rhs(2, 3),
                          lhs(0, 3) * rhs(3, 0) + lhs(1, 3) * rhs(3, 1) + lhs(2, 3) * rhs(3, 2) + lhs(3, 3) * rhs(3, 3) };
}

// 创建给定的平截头体矩阵在左，右，顶，底，近，远的值在平截头体边界。
template <typename Real>
void Mathematics::Matrix4<Real>::MakeFrustumMatrix44(Real left, Real right, Real bottom, Real top, Real nearDistance, Real farDistance)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto width = right - left;
    auto height = top - bottom;
    auto depth = farDistance - nearDistance;

    m_Entry(0, 0) = (static_cast<Real>(2) * nearDistance) / width;
    m_Entry(0, 1) = Math::GetValue(0);
    m_Entry(0, 2) = Math::GetValue(0);
    m_Entry(0, 3) = Math::GetValue(0);

    m_Entry(1, 0) = Math::GetValue(0);
    m_Entry(1, 1) = (static_cast<Real>(2) * nearDistance) / height;
    m_Entry(1, 2) = Math::GetValue(0);
    m_Entry(1, 3) = Math::GetValue(0);

    m_Entry(2, 0) = (right + left) / width;
    m_Entry(2, 1) = (top + bottom) / height;
    m_Entry(2, 2) = -(farDistance + nearDistance) / depth;
    m_Entry(2, 3) = -Math::GetValue(1);

    m_Entry(3, 0) = Math::GetValue(0);
    m_Entry(3, 1) = Math::GetValue(0);
    m_Entry(3, 2) = -(static_cast<Real>(2) * farDistance * nearDistance) / depth;
    m_Entry(3, 3) = Math::GetValue(0);
}

// 创建一个立体矩阵给定在Y方向上的领域视图的度数，
// Y/X的纵横比，并且近和远平面的距离
template <typename Real>
void Mathematics::Matrix4<Real>::MakePerspectiveMatrix44(Real fieldOfViewY, Real aspect, Real nearDistance, Real farDistance)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto angle = fieldOfViewY / Math::GetValue(2);
    // 角度转换成弧度
    angle *= Math::GetDegreeToRadian();

    auto cot = Math::Cos(angle) / Math::Sin(angle);

    m_Entry(0, 0) = cot / aspect;
    m_Entry(0, 1) = Math::GetValue(0);
    m_Entry(0, 2) = Math::GetValue(0);
    m_Entry(0, 3) = Math::GetValue(0);

    m_Entry(1, 0) = Math::GetValue(0);
    m_Entry(1, 1) = cot;
    m_Entry(1, 2) = Math::GetValue(0);
    m_Entry(1, 3) = Math::GetValue(0);

    m_Entry(2, 0) = Math::GetValue(0);
    m_Entry(2, 1) = Math::GetValue(0);
    m_Entry(2, 2) = -(farDistance + nearDistance) / (farDistance - nearDistance);
    m_Entry(2, 3) = -Math::GetValue(1);

    m_Entry(3, 0) = Math::GetValue(0);
    m_Entry(3, 1) = Math::GetValue(0);
    m_Entry(3, 2) = -(Math::GetValue(2) * farDistance * nearDistance) / (farDistance - nearDistance);
    m_Entry(3, 3) = Math::GetValue(0);
}

// 由给定的左侧，右侧，底部，顶部，近值，和远值创建平截头体边界的正交矩阵。
template <typename Real>
void Mathematics::Matrix4<Real>::MakeOrthoMatrix44(Real left, Real right, Real bottom, Real top, Real nearDistance, Real farDistance)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto width = right - left;
    auto height = top - bottom;
    auto depth = farDistance - nearDistance;

    m_Entry(0, 0) = Math::GetValue(2) / width;
    m_Entry(0, 1) = Math::GetValue(0);
    m_Entry(0, 2) = Math::GetValue(0);
    m_Entry(0, 3) = Math::GetValue(0);

    m_Entry(1, 0) = Math::GetValue(0);
    m_Entry(1, 1) = Math::GetValue(2) / height;
    m_Entry(1, 2) = Math::GetValue(0);
    m_Entry(1, 3) = Math::GetValue(0);

    m_Entry(2, 0) = Math::GetValue(0);
    m_Entry(2, 1) = Math::GetValue(0);
    m_Entry(2, 2) = -Math::GetValue(2) / depth;
    m_Entry(2, 3) = Math::GetValue(0);

    m_Entry(3, 0) = -(right + left) / width;
    m_Entry(3, 1) = -(top + bottom) / height;
    m_Entry(3, 2) = -(farDistance + nearDistance) / depth;
    m_Entry(3, 3) = Math::GetValue(1);
}

// 创建使用3个基本规范化向量的方向矩阵
template <typename Real>
void Mathematics::Matrix4<Real>::MakeOrthoNormalMatrix44(const Vector3D& xDirection, const Vector3D& yDirection, const Vector3D& zDirection)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_1(xDirection.IsNormalize() && yDirection.IsNormalize() && zDirection.IsNormalize(), "xDirection、yDirection和zDirection不是单位向量！");

    m_Entry(0, 0) = xDirection[0];
    m_Entry(0, 1) = yDirection[0];
    m_Entry(0, 2) = zDirection[0];
    m_Entry(0, 3) = Math::GetValue(0);

    m_Entry(1, 0) = xDirection[1];
    m_Entry(1, 1) = yDirection[1];
    m_Entry(1, 2) = zDirection[1];
    m_Entry(1, 3) = Math::GetValue(0);

    m_Entry(2, 0) = xDirection[2];
    m_Entry(2, 1) = yDirection[2];
    m_Entry(2, 2) = zDirection[2];
    m_Entry(2, 3) = Math::GetValue(0);

    m_Entry(3, 0) = Math::GetValue(0);
    m_Entry(3, 1) = Math::GetValue(0);
    m_Entry(3, 2) = Math::GetValue(0);
    m_Entry(3, 3) = Math::GetValue(1);
}

template <typename T>
const typename Mathematics::Matrix4<T>::ArrayType Mathematics::Matrix4<T>::GetCoordinate() const noexcept
{
    return m_Entry.GetCoordinate();
}

template <typename T>
void Mathematics::Matrix4<T>::Set(const ArrayType& coordinate)  
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    for (int i = 0; i < sm_MatrixSize; ++i)
    {
        m_Entry(i / 4, i % 4) = coordinate[i];
    }
#include STSTEM_WARNING_POP
}

template <typename Real>
bool Mathematics ::Approximate(const Matrix4<Real>& lhs, const Matrix4<Real>& rhs, const Real epsilon)
{
    for (auto row = 0; row < 4; ++row)
    {
        for (auto column = 0; column < 4; ++column)
        {
            if (epsilon < Math<Real>::FAbs(lhs(row, column) - rhs(row, column)))
            {
                return false;
            }
        }
    }

    return true;
}

template <typename Real>
bool Mathematics ::Approximate(const Matrix4<Real>& lhs, const Matrix4<Real>& rhs)
{
    return Approximate(lhs, rhs, Math<Real>::GetZeroTolerance());
}
#include STSTEM_WARNING_POP
#endif  // MATHEMATICS_ALGEBRA_MATRIX4_DETAIL_H