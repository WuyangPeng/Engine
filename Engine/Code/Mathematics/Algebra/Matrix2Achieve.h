///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/07 16:11)

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
Mathematics::Matrix2<Real>::Matrix2(const ContainerType& entry, MatrixMajorFlags majorFlag)
    : m_X{}, m_Y{}
{
    if (entry.size() != matrixSize)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("数据大小错误！"s));
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
Mathematics::Matrix2<Real>::Matrix2(const Vector2& vector0, const Vector2& vector1, MatrixMajorFlags majorFlag)
    : m_X{}, m_Y{}
{
    if (majorFlag == MatrixMajorFlags::Row)
    {
        m_X = vector0;
        m_Y = vector1;
    }
    else
    {
        m_X.SetCoordinate(vector0[xIndex], vector1[xIndex]);
        m_Y.SetCoordinate(vector0[yIndex], vector1[yIndex]);
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix2<Real>::Matrix2(const Vector2ContainerType& vectors, MatrixMajorFlags majorFlag)
    : m_X{}, m_Y{}
{
    if (vectors.size() != vectorSize)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("数据大小错误！"s));
    }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    if (majorFlag == MatrixMajorFlags::Row)
    {
        m_X = vectors[xIndex];
        m_Y = vectors[yIndex];
    }
    else
    {
        m_X.SetCoordinate(vectors[xIndex].GetX(), vectors[yIndex].GetX());
        m_Y.SetCoordinate(vectors[xIndex].GetY(), vectors[yIndex].GetY());
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
Mathematics::Matrix2<Real>::Matrix2(const Vector2& vector0, const Vector2& vector1) noexcept
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

    m_X = Vector2::GetUnitX();
    m_Y = Vector2::GetUnitY();
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
    m_Y.SetCoordinate(-m_X.GetY(), m_X.GetX());
}

template <typename Real>
void Mathematics::Matrix2<Real>::MakeTensorProduct(const Vector2& lhs, const Vector2& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X.SetCoordinate(lhs.GetX() * rhs.GetX(), lhs.GetX() * rhs.GetY());
    m_Y.SetCoordinate(lhs.GetY() * rhs.GetX(), lhs.GetY() * rhs.GetY());
}

template <typename Real>
Mathematics::Matrix2<Real> Mathematics::Matrix2<Real>::operator-() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix2<Real>{ -m_X.GetX(), -m_X.GetY(), -m_Y.GetX(), -m_Y.GetY() };
}

template <typename Real>
const Mathematics::Vector2<Real>& Mathematics::Matrix2<Real>::operator[](int row) const
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

    THROW_EXCEPTION(SYSTEM_TEXT("索引错误！"s));
}

template <typename Real>
Mathematics::Vector2<Real>& Mathematics::Matrix2<Real>::operator[](int row)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(Mathematics::Vector2<Real>, row);
}

template <typename Real>
const Real& Mathematics::Matrix2<Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    MATHEMATICS_ASSERTION_0(xIndex <= row && row < vectorSize, "row索引错误！");
    MATHEMATICS_ASSERTION_0(Vector2::xIndex <= column && column < Vector2::pointSize, "column索引错误！");

    return (*this)[row][column];
}

template <typename Real>
Real& Mathematics::Matrix2<Real>::operator()(int row, int column)
{
    MATHEMATICS_CLASS_IS_VALID_9;

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
Real Mathematics::Matrix2<Real>::QuadraticForm(const Vector2& lhs, const Vector2& rhs) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Vector2Tools::DotProduct(lhs, (*this) * rhs);
}

template <typename Real>
Mathematics::Matrix2<Real> Mathematics::Matrix2<Real>::Transpose() const noexcept
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
Mathematics::Matrix2<Real> Mathematics::Matrix2<Real>::Inverse(const Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    // 由于除零错误的epsilon和这里的epsilon不同，改由先除后乘。
    const auto inv = 1 / Determinant();

    if (epsilon < Math::FAbs(inv))
    {
        return Adjoint() * inv;
    }
    else
    {
        MATHEMATICS_ASSERTION_0(false, "该矩阵不存在逆矩阵！");

        return GetZero();
    }
}

template <typename Real>
Mathematics::Matrix2<Real> Mathematics::Matrix2<Real>::GaussianEliminationInverse(const Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    GaussianElimination<Real> gaussianElimination{ vectorSize, GetContainer(), true, epsilon };

    if (gaussianElimination.IsInverse())
    {
        return Matrix2{ gaussianElimination.GetInverse(), MatrixMajorFlags::Row };
    }
    else
    {
        MATHEMATICS_ASSERTION_0(false, "该矩阵不存在逆矩阵！");

        return GetZero();
    }
}

template <typename Real>
Real Mathematics::Matrix2<Real>::GaussianEliminationDeterminant(const Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    GaussianElimination<Real> gaussianElimination{ vectorSize, GetContainer(), false, epsilon };

    return gaussianElimination.GetDeterminant();
}

template <typename Real>
Mathematics::Matrix2<Real> Mathematics::Matrix2<Real>::Adjoint() const noexcept
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

    MATHEMATICS_ASSERTION_1(Math::FAbs(GetValue<0, 0>() - GetValue<1, 1>()) <= Math::GetZeroTolerance(), "该矩阵不是旋转矩阵！");
    MATHEMATICS_ASSERTION_1(Math::FAbs(GetValue<0, 1>() + GetValue<1, 0>()) <= Math::GetZeroTolerance(), "该矩阵不是旋转矩阵！");
    MATHEMATICS_ASSERTION_1(Math::FAbs(GetValue<0, 0>() * GetValue<1, 1>() - GetValue<0, 1>() * GetValue<1, 0>() - Math::GetValue(1)) <= Math::GetZeroTolerance(),
                            "该矩阵不是旋转矩阵！");

    return Math::ATan2(GetValue<1, 0>(), GetValue<0, 0>());
}

template <typename Real>
void Mathematics::Matrix2<Real>::Orthonormalize()
{
    // 算法采用Gram-Schmidt正交。
    // 如果'this'矩阵为M = [m0|m1]，然后输出正交矩阵Q = [q0|q1]
    //
    //   q0 = m0 / |m0|
    //   q1 = (m1 - (q0 * m1)q0) / |m1 - (q0 * m1)q0|
    // 其中|V|表示向量V的长度和A * B表示向量A和B的点积

    MATHEMATICS_ASSERTION_1(Math::FAbs(GetValue<0, 0>() - GetValue<1, 1>()) <= Math::GetZeroTolerance(), "该矩阵不是旋转矩阵！");
    MATHEMATICS_ASSERTION_1(Math::FAbs(GetValue<0, 1>() + GetValue<1, 0>()) <= Math::GetZeroTolerance(), "该矩阵不是旋转矩阵！");
    MATHEMATICS_ASSERTION_1(Math::FAbs(GetValue<0, 0>() * GetValue<1, 1>() - GetValue<0, 1>() * GetValue<1, 0>() - Math::GetValue(1)) <= Math::GetZeroTolerance(),
                            "该矩阵不是旋转矩阵！");

    MATHEMATICS_CLASS_IS_VALID_9;

    // 计算 q0.
    auto invLength = Math::InvSqrt(GetValue<0, 0>() * GetValue<0, 0>() + GetValue<1, 0>() * GetValue<1, 0>());

    (*this)(0, 0) *= invLength;
    (*this)(1, 0) *= invLength;

    // 计算 q1.
    const auto dot = GetValue<0, 0>() * GetValue<0, 1>() + GetValue<1, 0>() * GetValue<1, 1>();

    (*this)(0, 1) -= dot * GetValue<0, 0>();
    (*this)(1, 1) -= dot * GetValue<1, 0>();

    invLength = Math::InvSqrt(GetValue<0, 1>() * GetValue<0, 1>() + GetValue<1, 1>() * GetValue<1, 1>());

    (*this)(0, 1) *= invLength;
    (*this)(1, 1) *= invLength;
}

template <typename Real>
typename Mathematics::Matrix2<Real>::Matrix2EigenDecomposition Mathematics::Matrix2<Real>::EigenDecomposition(const Real epsilon) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    MATHEMATICS_ASSERTION_1(Math::FAbs(GetValue<0, 1>() - GetValue<1, 0>()) <= epsilon, "矩阵必须是对称矩阵。");

    auto sum = Math::FAbs(GetValue<0, 0>()) + Math::FAbs(GetValue<1, 1>());

    if (Math::FAbs(Math::FAbs(GetValue<0, 1>()) + sum - sum) < epsilon)
    {
        // 矩阵 M 是对角矩阵（数字四舍五入）。
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

    const Matrix2<Real> rotation{ cosValue, -sinValue, sinValue, cosValue };

    return Matrix2EigenDecomposition{ rotation, diagonal, epsilon };
}

template <typename Real>
typename Mathematics::Matrix2<Real>::ArrayType Mathematics::Matrix2<Real>::GetCoordinate() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ArrayType{ m_X.GetX(), m_X.GetY(), m_Y.GetX(), m_Y.GetY() };
}

template <typename Real>
typename Mathematics::Matrix2<Real>::ContainerType Mathematics::Matrix2<Real>::GetContainer() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ContainerType{ m_X.GetX(), m_X.GetY(), m_Y.GetX(), m_Y.GetY() };
}

template <typename Real>
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
Real Mathematics::Matrix2<Real>::Trace() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetValue<0, 0>() + GetValue<1, 1>();
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX2_ACHIEVE_H