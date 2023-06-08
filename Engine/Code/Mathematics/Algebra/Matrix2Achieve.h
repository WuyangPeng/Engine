///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/05/31 16:30)

#ifndef MATHEMATICS_ALGEBRA_MATRIX2_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_MATRIX2_ACHIEVE_H

#include "AVector.h"
#include "Matrix2.h"
#include "Matrix2EigenDecompositionDetail.h"
#include "Matrix3Detail.h"
#include "Vector2.h"
#include "Vector2Tools.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/NumericalAnalysis/GaussianEliminationDetail.h"

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix2<Real>::Matrix2(const ContainerType& entry, MatrixMajorFlags majorFlag)
    : x{}, y{}
{
    if (entry.size() != matrixSize)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���ݴ�С����"s))
    }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    if (majorFlag == MatrixMajorFlags::Row)
    {
        x.SetCoordinate(entry[0], entry[1]);
        y.SetCoordinate(entry[2], entry[3]);
    }
    else
    {
        x.SetCoordinate(entry[0], entry[2]);
        y.SetCoordinate(entry[1], entry[3]);
    }

#include STSTEM_WARNING_POP

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix2<Real>::Matrix2(const Vector2& vector0, const Vector2& vector1, MatrixMajorFlags majorFlag)
    : x{}, y{}
{
    if (majorFlag == MatrixMajorFlags::Row)
    {
        x = vector0;
        y = vector1;
    }
    else
    {
        x.SetCoordinate(vector0[xIndex], vector1[xIndex]);
        y.SetCoordinate(vector0[yIndex], vector1[yIndex]);
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix2<Real>::Matrix2(const Vector2ContainerType& vectors, MatrixMajorFlags majorFlag)
    : x{}, y{}
{
    if (vectors.size() != vectorSize)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���ݴ�С����"s))
    }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    if (majorFlag == MatrixMajorFlags::Row)
    {
        x = vectors[xIndex];
        y = vectors[yIndex];
    }
    else
    {
        x.SetCoordinate(vectors[xIndex].GetX(), vectors[yIndex].GetX());
        y.SetCoordinate(vectors[xIndex].GetY(), vectors[yIndex].GetY());
    }

#include STSTEM_WARNING_POP

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix2<Real>::Matrix2(Real angle) noexcept
    : x{}, y{}
{
    MakeRotation(angle);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix2<Real>::Matrix2(const Vector2& vector0, const Vector2& vector1) noexcept
    : x{}, y{}
{
    MakeTensorProduct(vector0, vector1);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Matrix2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix2<Real>::MakeZero() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x.ZeroOut();
    y.ZeroOut();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix2<Real>::MakeIdentity() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x = Vector2::GetUnitX();
    y = Vector2::GetUnitY();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix2<Real>::MakeDiagonal(Real member00, Real member11) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x.SetCoordinate(member00, Math::GetValue(0));
    y.SetCoordinate(Math::GetValue(0), member11);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix2<Real>::MakeRotation(Real angle) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x.SetCoordinate(Math::Cos(angle), -Math::Sin(angle));
    y.SetCoordinate(-x.GetY(), x.GetX());
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix2<Real>::MakeTensorProduct(const Vector2& lhs, const Vector2& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x.SetCoordinate(lhs.GetX() * rhs.GetX(), lhs.GetX() * rhs.GetY());
    y.SetCoordinate(lhs.GetY() * rhs.GetX(), lhs.GetY() * rhs.GetY());
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix2<Real> Mathematics::Matrix2<Real>::operator-() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix2<Real>{ -x.GetX(), -x.GetY(), -y.GetX(), -y.GetY() };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
const Mathematics::Vector2<Real>& Mathematics::Matrix2<Real>::operator[](int row) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    switch (System::UnderlyingCastEnum<VectorIndex>(row))
    {
        case Matrix2::VectorIndex::X:
            return x;
        case Matrix2::VectorIndex::Y:
            return y;
        default:
            break;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("��������"s))
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector2<Real>& Mathematics::Matrix2<Real>::operator[](int row)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(Mathematics::Vector2<Real>, row);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
const Real& Mathematics::Matrix2<Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    MATHEMATICS_ASSERTION_0(xIndex <= row && row < vectorSize, "row��������");
    MATHEMATICS_ASSERTION_0(Vector2::xIndex <= column && column < Vector2::pointSize, "column��������");

    return (*this)[row][column];
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real& Mathematics::Matrix2<Real>::operator()(int row, int column)
{
    MATHEMATICS_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, column));

#include STSTEM_WARNING_POP
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix2<Real>& Mathematics::Matrix2<Real>::operator+=(const Matrix2& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x += rhs.x;
    y += rhs.y;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix2<Real>& Mathematics::Matrix2<Real>::operator-=(const Matrix2& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x -= rhs.x;
    y -= rhs.y;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix2<Real>& Mathematics::Matrix2<Real>::operator*=(Real scalar) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x *= scalar;
    y *= scalar;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix2<Real>& Mathematics::Matrix2<Real>::operator/=(Real scalar) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x /= scalar;
    y /= scalar;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Matrix2<Real>::QuadraticForm(const Vector2& lhs, const Vector2& rhs) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Vector2Tools::DotProduct(lhs, (*this) * rhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix2<Real> Mathematics::Matrix2<Real>::Transpose() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix2{ x.GetX(), y.GetX(), x.GetY(), y.GetY() };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix2<Real>& Mathematics::Matrix2<Real>::operator*=(const Matrix2& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    *this = *this * rhs;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix2<Real> Mathematics::Matrix2<Real>::Inverse(Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    // ���ڳ�������epsilon�������epsilon��ͬ�������ȳ���ˡ�
    const auto inv = 1 / Determinant();

    if (epsilon < Math::FAbs(inv))
    {
        return Adjoint() * inv;
    }
    else
    {
        MATHEMATICS_ASSERTION_0(false, "�þ��󲻴��������");

        return GetZero();
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix2<Real> Mathematics::Matrix2<Real>::GaussianEliminationInverse(Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (GaussianElimination<Real> gaussianElimination{ vectorSize, GetContainer(), true, epsilon };
        gaussianElimination.IsInverse())
    {
        return Matrix2{ gaussianElimination.GetInverse(), MatrixMajorFlags::Row };
    }
    else
    {
        MATHEMATICS_ASSERTION_0(false, "�þ��󲻴��������");

        return GetZero();
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Matrix2<Real>::GaussianEliminationDeterminant(Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    GaussianElimination<Real> gaussianElimination{ vectorSize, GetContainer(), false, epsilon };

    return gaussianElimination.GetDeterminant();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix2<Real> Mathematics::Matrix2<Real>::Adjoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix2{ y.GetY(), -x.GetY(), -y.GetX(), x.GetX() };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Matrix2<Real>::Determinant() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return x.GetX() * y.GetY() - x.GetY() * y.GetX();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Matrix2<Real>::ExtractAngle() const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    MATHEMATICS_ASSERTION_1(Math::FAbs(GetValue<0, 0>() - GetValue<1, 1>()) <= Math::GetZeroTolerance(), "�þ�������ת����");
    MATHEMATICS_ASSERTION_1(Math::FAbs(GetValue<0, 1>() + GetValue<1, 0>()) <= Math::GetZeroTolerance(), "�þ�������ת����");
    MATHEMATICS_ASSERTION_1(Math::FAbs(GetValue<0, 0>() * GetValue<1, 1>() - GetValue<0, 1>() * GetValue<1, 0>() - Math::GetValue(1)) <= Math::GetZeroTolerance(), "�þ�������ת����");

    return Math::ATan2(GetValue<1, 0>(), GetValue<0, 0>());
}

template <typename Real>
requires std::is_arithmetic_v<Real>
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
    MATHEMATICS_ASSERTION_1(Math::FAbs(GetValue<0, 0>() * GetValue<1, 1>() - GetValue<0, 1>() * GetValue<1, 0>() - Math::GetValue(1)) <= Math::GetZeroTolerance(), "�þ�������ת����");

    MATHEMATICS_CLASS_IS_VALID_9;

    // ���� q0.
    auto invLength = Math::InvSqrt(GetValue<0, 0>() * GetValue<0, 0>() + GetValue<1, 0>() * GetValue<1, 0>());

    (*this)(0, 0) *= invLength;
    (*this)(1, 0) *= invLength;

    // ���� q1.
    const auto dot = GetValue<0, 0>() * GetValue<0, 1>() + GetValue<1, 0>() * GetValue<1, 1>();

    (*this)(0, 1) -= dot * GetValue<0, 0>();
    (*this)(1, 1) -= dot * GetValue<1, 0>();

    invLength = Math::InvSqrt(GetValue<0, 1>() * GetValue<0, 1>() + GetValue<1, 1>() * GetValue<1, 1>());

    (*this)(0, 1) *= invLength;
    (*this)(1, 1) *= invLength;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Matrix2<Real>::Matrix2EigenDecomposition Mathematics::Matrix2<Real>::EigenDecomposition(Real epsilon) const noexcept(gAssert < 1 || gMathematicsAssert < 1)
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

    const auto trace = GetValue<0, 0>() + GetValue<1, 1>();
    const auto difference = GetValue<0, 0>() - GetValue<1, 1>();
    const auto discr = Math::Sqrt(difference * difference + (Math::GetValue(4) * GetValue<0, 1>() * GetValue<0, 1>()));

    const auto eigenvalue0 = Math::GetRational(1, 2) * (trace - discr);
    const auto eigenvalue1 = Math::GetRational(1, 2) * (trace + discr);
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

    const auto invLength = Math::InvSqrt(cosValue * cosValue + sinValue * sinValue);
    cosValue *= invLength;
    sinValue *= invLength;

    const Matrix2 rotation{ cosValue, -sinValue, sinValue, cosValue };

    return Matrix2EigenDecomposition{ rotation, diagonal, epsilon };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Matrix2<Real>::ArrayType Mathematics::Matrix2<Real>::GetCoordinate() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ArrayType{ x.GetX(), x.GetY(), y.GetX(), y.GetY() };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Matrix2<Real>::ContainerType Mathematics::Matrix2<Real>::GetContainer() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ContainerType{ x.GetX(), x.GetY(), y.GetX(), y.GetY() };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix2<Real>::Set(const ArrayType& coordinate)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto index = 0;
    for (auto value : coordinate)
    {
        (*this)(index / vectorSize, index % Vector2::pointSize) = value;

        ++index;
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix3<Real> Mathematics::Matrix2<Real>::Lift() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Matrix3 result{ MatrixInitType::Identity };

    for (auto r = 0; r < vectorSize; ++r)
    {
        for (auto c = 0; c < vectorSize; ++c)
        {
            result(r, c) = (*this)(r, c);
        }
    }
    return result;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Matrix2<Real>::Trace() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetValue<0, 0>() + GetValue<1, 1>();
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX2_ACHIEVE_H