///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/06 13:17)

#ifndef MATHEMATICS_ALGEBRA_MATRIX2_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_MATRIX2_ACHIEVE_H

#include "AVector.h"
#include "Matrix2.h"
#include "Vector2D.h"
#include "Vector2DTools.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::Matrix2<Real>::Matrix2(const ContainerType& entry, MatrixMajorFlags majorFlag)
    : m_X{}, m_Y{}
{
    if (entry.size() != sm_MatrixSize)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���ݴ�С����"s));
    }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    if (majorFlag == MatrixMajorFlags::Row)
    {
        m_X.SetCoordinate(entry[0], entry[1]);
        m_Y.SetCoordinate(entry[2], entry[3]);
    }
    else
    {
        m_X.SetCoordinate(entry[0], entry[2]);
        m_Y.SetCoordinate(entry[1], entry[3]);
    }
#include STSTEM_WARNING_POP

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix2<Real>::Matrix2(const Vector2D& vector0, const Vector2D& vector1, MatrixMajorFlags majorFlag)
    : m_X{}, m_Y{}
{
    if (majorFlag == MatrixMajorFlags::Row)
    {
        m_X = vector0;
        m_Y = vector1;
    }
    else
    {
        m_X.SetCoordinate(vector0[sm_X], vector1[sm_X]);
        m_Y.SetCoordinate(vector0[sm_Y], vector1[sm_Y]);
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix2<Real>::Matrix2(const Vector2DContainerType& vectors, MatrixMajorFlags majorFlag)
    : m_X{}, m_Y{}
{
    if (vectors.size() != sm_VectorSize)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���ݴ�С����"s));
    }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    if (majorFlag == MatrixMajorFlags::Row)
    {
        m_X = vectors[sm_X];
        m_Y = vectors[sm_Y];
    }
    else
    {
        m_X.SetCoordinate(vectors[sm_X].GetX(), vectors[sm_Y].GetX());
        m_Y.SetCoordinate(vectors[sm_X].GetY(), vectors[sm_Y].GetY());
    }
#include STSTEM_WARNING_POP

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix2<Real>::Matrix2(Real angle) noexcept
    : m_X{}, m_Y{}
{
    MakeRotation(angle);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix2<Real>::Matrix2(const Vector2D& vector0, const Vector2D& vector1) noexcept
    : m_X{}, m_Y{}
{
    MakeTensorProduct(vector0, vector1);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Matrix2<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::Matrix2<Real>::MakeZero() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X.ZeroOut();
    m_Y.ZeroOut();
}

template <typename Real>
void Mathematics::Matrix2<Real>::MakeIdentity() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X = Vector2D::GetUnitX();
    m_Y = Vector2D::GetUnitY();
}

template <typename Real>
void Mathematics::Matrix2<Real>::MakeDiagonal(Real member00, Real member11) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X.SetCoordinate(member00, Math::GetValue(0));
    m_Y.SetCoordinate(Math::GetValue(0), member11);
}

template <typename Real>
void Mathematics::Matrix2<Real>::MakeRotation(Real angle) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X.SetCoordinate(Math::Cos(angle), -Math::Sin(angle));
    m_Y.SetCoordinate(-m_X.GetY(), m_X.GetY());
}

template <typename Real>
void Mathematics::Matrix2<Real>::MakeTensorProduct(const Vector2D& lhs, const Vector2D& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X.SetCoordinate(lhs.GetX() * rhs.GetX(), lhs.GetX() * rhs.GetY());
    m_Y.SetCoordinate(lhs.GetY() * rhs.GetX(), lhs.GetY() * rhs.GetY());
}

template <typename Real>
const Mathematics::Matrix2<Real> Mathematics::Matrix2<Real>::operator-() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix2<Real>{ -m_X.GetX(), -m_X.GetY(), -m_Y.GetX(), -m_Y.GetY() };
}

template <typename Real>
const Mathematics::Vector2D<Real>& Mathematics::Matrix2<Real>::operator[](int row) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    switch (System::UnderlyingCastEnum<VectorIndex>(row))
    {
        case Matrix2::VectorIndex::X:
            return m_X;
        case Matrix2::VectorIndex::Y:
            return m_Y;
        default:
            break;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("��������"s));
}

template <typename Real>
Mathematics::Vector2D<Real>& Mathematics::Matrix2<Real>::operator[](int row)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_0(sm_X <= row && row < sm_VectorSize, "��������");

    return OPERATOR_SQUARE_BRACKETS(Mathematics::Vector2D<Real>, row);
}

template <typename Real>
const Real& Mathematics::Matrix2<Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (*this)[row][column];
}

template <typename Real>
Real& Mathematics::Matrix2<Real>::operator()(int row, int column)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_0(sm_X <= row && row < sm_VectorSize, "row��������");
    MATHEMATICS_ASSERTION_0(Vector2D::sm_X <= column && column < Vector2D::sm_PointSize, "column��������");

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)
    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, column));
#include STSTEM_WARNING_POP
}

template <typename Real>
Mathematics::Matrix2<Real>& Mathematics::Matrix2<Real>::operator+=(const Matrix2& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X += rhs.m_X;
    m_Y += rhs.m_Y;

    return *this;
}

template <typename Real>
Mathematics::Matrix2<Real>& Mathematics::Matrix2<Real>::operator-=(const Matrix2& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X -= rhs.m_X;
    m_Y -= rhs.m_Y;

    return *this;
}

template <typename Real>
Mathematics::Matrix2<Real>& Mathematics::Matrix2<Real>::operator*=(Real scalar) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X *= scalar;
    m_Y *= scalar;

    return *this;
}

template <typename Real>
Mathematics::Matrix2<Real>& Mathematics::Matrix2<Real>::operator/=(Real scalar) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X /= scalar;
    m_Y /= scalar;

    return *this;
}

template <typename Real>
Real Mathematics::Matrix2<Real>::QuadraticForm(const Vector2D& lhs, const Vector2D& rhs) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Vector2DTools::DotProduct(lhs, (*this) * rhs);
}

template <typename Real>
const Mathematics::Matrix2<Real> Mathematics::Matrix2<Real>::Transpose() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix2<Real>{ m_X.GetX(), m_Y.GetX(), m_X.GetY(), m_Y.GetY() };
}

template <typename Real>
Mathematics::Matrix2<Real>& Mathematics::Matrix2<Real>::operator*=(const Matrix2& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    *this = *this * rhs;

    return *this;
}

template <typename Real>
const Mathematics::Matrix2<Real> Mathematics::Matrix2<Real>::Inverse(const Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto det = Determinant();

    if (epsilon < Math::FAbs(det))
    {
        // ���ڳ�������epsilon�������epsilon��ͬ�������ȳ���ˡ�
        return Adjoint() * (1 / det);
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "�þ��󲻴��������");

        return GetZero();
    }
}

template <typename Real>
const Mathematics::Matrix2<Real> Mathematics::Matrix2<Real>::Adjoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix2{ m_Y.GetY(), -m_X.GetY(), -m_Y.GetX(), m_X.GetX() };
}

template <typename Real>
Real Mathematics::Matrix2<Real>::Determinant() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_X.GetX() * m_Y.GetY() - m_X.GetY() * m_Y.GetX();
}

template <typename Real>
Real Mathematics::Matrix2<Real>::ExtractAngle() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    MATHEMATICS_ASSERTION_1(Math::FAbs(GetValue<0, 0>() - GetValue<1, 1>()) <= Math::GetZeroTolerance(), "�þ�������ת����");
    MATHEMATICS_ASSERTION_1(Math::FAbs(GetValue<0, 1>() + GetValue<1, 0>()) <= Math::GetZeroTolerance(), "�þ�������ת����");
    MATHEMATICS_ASSERTION_1(Math::FAbs(GetValue<0, 0>() * GetValue<1, 1>() - GetValue<0, 1>() * GetValue<1, 0>() - Math::GetValue(1)) <= Math::GetZeroTolerance(),
                            "�þ�������ת����");

    return Math::ATan2(GetValue<1, 0>(), GetValue<0, 0>());
}

template <typename Real>
void Mathematics::Matrix2<Real>::Orthonormalize()
{
    // �㷨����Gram-Schmidt������
    // ���'this'����ΪM = [m0|m1]��Ȼ�������������Q = [q0|q1]
    //
    //   q0 = m0 / |m0|
    //   q1 = (m1 - (q0 * m1)q0) / |m1 - (q0 * m1)q0|
    // ����|V|��ʾ����V�ĳ��Ⱥ�A * B��ʾ����A��B�ĵ��

    MATHEMATICS_ASSERTION_1(Math::FAbs(GetValue<0, 0>() - GetValue<1, 1>()) <= Math::GetZeroTolerance(), "�þ�������ת����");
    MATHEMATICS_ASSERTION_1(Math::FAbs(GetValue<0, 1>() + GetValue<1, 0>()) <= Math::GetZeroTolerance(), "�þ�������ת����");
    MATHEMATICS_ASSERTION_1(Math::FAbs(GetValue<0, 0>() * GetValue<1, 1>() - GetValue<0, 1>() * GetValue<1, 0>() - Math::GetValue(1)) <= Math::GetZeroTolerance(),
                            "�þ�������ת����");

    MATHEMATICS_CLASS_IS_VALID_9;

    // ���� q0.
    auto invLength = Math::InvSqrt(GetValue<0, 0>() * GetValue<0, 0>() + GetValue<1, 0>() * GetValue<1, 0>());

    (*this)(0, 0) *= invLength;
    (*this)(1, 0) *= invLength;

    // ���� q1.
    auto dot = GetValue<0, 0>() * GetValue<0, 1>() + GetValue<1, 0>() * GetValue<1, 1>();

    (*this)(0, 1) -= dot * GetValue<0, 0>();
    (*this)(1, 1) -= dot * GetValue<1, 0>();

    invLength = Math::InvSqrt(GetValue<0, 1>() * GetValue<0, 1>() + GetValue<1, 1>() * GetValue<1, 1>());

    (*this)(0, 1) *= invLength;
    (*this)(1, 1) *= invLength;
}

template <typename Real>
typename const Mathematics::Matrix2<Real>::Matrix2EigenDecomposition Mathematics::Matrix2<Real>::EigenDecomposition(const Real epsilon) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    MATHEMATICS_ASSERTION_1(Math::FAbs(GetValue<0, 1>() - GetValue<1, 0>()) <= epsilon, "��������ǶԳƾ���");

    auto sum = Math::FAbs(GetValue<0, 0>()) + Math::FAbs(GetValue<1, 1>());

    if (Math::FAbs(Math::FAbs(GetValue<0, 1>()) + sum - sum) < epsilon)
    {
        // ���� M �ǶԽǾ��������������룩��
        const Matrix2<Real> rotation{ MatrixInitType::Identity };
        const Matrix2<Real> diagonal{ GetValue<0, 0>(), GetValue<1, 1>() };

        return Matrix2EigenDecomposition{ rotation, diagonal, epsilon };
    }

    auto trace = GetValue<0, 0>() + GetValue<1, 1>();
    auto difference = GetValue<0, 0>() - GetValue<1, 1>();
    auto discr = Math::Sqrt(difference * difference + (Math::GetValue(4) * GetValue<0, 1>() * GetValue<0, 1>()));

    auto eigenvalue0 = Math::GetRational(1, 2) * (trace - discr);
    auto eigenvalue1 = Math::GetRational(1, 2) * (trace + discr);
    const Matrix2<Real> diagonal{ eigenvalue0, eigenvalue1 };

    Real cosValue{};
    Real sinValue{};
    if (Math::GetValue(0) <= difference)
    {
        cosValue = GetValue<0, 1>();
        sinValue = eigenvalue0 - GetValue<0, 0>();
    }
    else
    {
        cosValue = eigenvalue0 - GetValue<1, 1>();
        sinValue = GetValue<0, 1>();
    }

    auto invLength = Math::InvSqrt(cosValue * cosValue + sinValue * sinValue);
    cosValue *= invLength;
    sinValue *= invLength;

    const Matrix2<Real> rotation{ cosValue, -sinValue, sinValue, cosValue };

    return Matrix2EigenDecomposition{ rotation, diagonal, epsilon };
}

template <typename Real>
const typename Mathematics::Matrix2<Real>::ArrayType Mathematics::Matrix2<Real>::GetCoordinate() const noexcept
{
    return ArrayType{ m_X.GetX(), m_X.GetY(), m_Y.GetX(), m_Y.GetY() };
}

template <typename Real>
void Mathematics::Matrix2<Real>::Set(const ArrayType& coordinate)
{
    auto index = 0;
    for (auto value : coordinate)
    {
        (*this)(index / sm_VectorSize, index % Vector2D::sm_PointSize) = value;

        ++index;
    }
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX2_ACHIEVE_H