///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/07 17:01)

#ifndef MATHEMATICS_ALGEBRA_MATRIX3_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_MATRIX3_ACHIEVE_H

#include "AVector.h"
#include "EulerDetail.h"
#include "Matrix2Detail.h"
#include "Matrix3.h"
#include "Matrix3ExtractDetail.h"
#include "Matrix4Detail.h"
#include "TridiagonalizeDetail.h"
#include "Vector3.h"
#include "Vector3Tools.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/NumericalAnalysis/GaussianEliminationDetail.h"

template <typename Real>
Mathematics::Matrix3<Real>::Matrix3(const ContainerType& entry, MatrixMajorFlags majorFlag)
    : m_X{}, m_Y{}, m_Z{}
{
    if (entry.size() != matrixSize)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("数据大小错误！"s));
    }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    if (majorFlag == MatrixMajorFlags::Row)
    {
        m_X.SetCoordinate(entry[0], entry[1], entry[2]);
        m_Y.SetCoordinate(entry[3], entry[4], entry[5]);
        m_Z.SetCoordinate(entry[6], entry[7], entry[8]);
    }
    else
    {
        m_X.SetCoordinate(entry[0], entry[3], entry[6]);
        m_Y.SetCoordinate(entry[1], entry[4], entry[7]);
        m_Z.SetCoordinate(entry[2], entry[5], entry[8]);
    }

#include STSTEM_WARNING_POP

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix3<Real>::Matrix3(const Vector3& vector0, const Vector3& vector1, const Vector3& vector2, MatrixMajorFlags majorFlag)
    : m_X{}, m_Y{}, m_Z{}
{
    if (majorFlag == MatrixMajorFlags::Row)
    {
        m_X = vector0;
        m_Y = vector1;
        m_Z = vector2;
    }
    else
    {
        m_X.SetCoordinate(vector0[xIndex], vector1[xIndex], vector2[xIndex]);
        m_Y.SetCoordinate(vector0[yIndex], vector1[yIndex], vector2[yIndex]);
        m_Z.SetCoordinate(vector0[zIndex], vector1[zIndex], vector2[zIndex]);
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix3<Real>::Matrix3(const Vector3ContainerType& vectors, MatrixMajorFlags majorFlag)
    : m_X{}, m_Y{}, m_Z{}
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
        m_Z = vectors[zIndex];
    }
    else
    {
        m_X.SetCoordinate(vectors[xIndex].GetX(), vectors[yIndex].GetX(), vectors[zIndex].GetX());
        m_Y.SetCoordinate(vectors[xIndex].GetY(), vectors[yIndex].GetY(), vectors[zIndex].GetY());
        m_Z.SetCoordinate(vectors[xIndex].GetZ(), vectors[yIndex].GetZ(), vectors[zIndex].GetZ());
    }

#include STSTEM_WARNING_POP

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix3<Real>::Matrix3(const Vector3& axis, Real angle) noexcept
    : m_X{}, m_Y{}, m_Z{}
{
    MakeRotation(axis, angle);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix3<Real>::Matrix3(MatrixRotationAxis axis, Real angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
    : m_X{}, m_Y{}, m_Z{}
{
    MakeRotation(axis, angle);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix3<Real>::Matrix3(const Vector3& vector0, const Vector3& vector1) noexcept
    : m_X{}, m_Y{}, m_Z{}
{
    MakeTensorProduct(vector0, vector1);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Matrix3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::Matrix3<Real>::MakeZero() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X.ZeroOut();
    m_Y.ZeroOut();
    m_Z.ZeroOut();
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeIdentity() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X = Vector3::GetUnitX();
    m_Y = Vector3::GetUnitY();
    m_Z = Vector3::GetUnitZ();
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeDiagonal(Real member00, Real member11, Real member22) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X.SetCoordinate(member00, Math::GetValue(0), Math::GetValue(0));
    m_Y.SetCoordinate(Math::GetValue(0), member11, Math::GetValue(0));
    m_Z.SetCoordinate(Math::GetValue(0), Math::GetValue(0), member22);
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeRotation(const Vector3& axis, Real angle) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto cosValue = Math::Cos(angle);
    const auto sinValue = Math::Sin(angle);
    const auto oneMinusCos = Math::GetValue(1) - cosValue;

    const auto xAxisSquare = axis.GetX() * axis.GetX();
    const auto yAxisSquare = axis.GetY() * axis.GetY();
    const auto zAxisSquare = axis.GetZ() * axis.GetZ();

    const auto xAxisSquareMultipliedOneMinusCos = xAxisSquare * oneMinusCos;
    const auto yAxisSquareMultipliedOneMinusCos = yAxisSquare * oneMinusCos;
    const auto zAxisSquareMultipliedOneMinusCos = zAxisSquare * oneMinusCos;

    const auto xym = axis.GetX() * axis.GetY() * oneMinusCos;
    const auto xzm = axis.GetX() * axis.GetZ() * oneMinusCos;
    const auto yzm = axis.GetY() * axis.GetZ() * oneMinusCos;

    const auto xSin = axis.GetX() * sinValue;
    const auto ySin = axis.GetY() * sinValue;
    const auto zSin = axis.GetZ() * sinValue;

    m_X.SetCoordinate(xAxisSquareMultipliedOneMinusCos + cosValue, xym - zSin, xzm + ySin);
    m_Y.SetCoordinate(xym + zSin, yAxisSquareMultipliedOneMinusCos + cosValue, yzm - xSin);
    m_Z.SetCoordinate(xzm - ySin, yzm + xSin, zAxisSquareMultipliedOneMinusCos + cosValue);
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeRotation(MatrixRotationAxis axis, Real angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto cosValue = Math::Cos(angle);
    const auto sinValue = Math::Sin(angle);

    switch (axis)
    {
        case MatrixRotationAxis::X:
        {
            m_X = Vector3::GetUnitX();
            m_Y.SetCoordinate(Math::GetValue(0), cosValue, -sinValue);
            m_Z.SetCoordinate(Math::GetValue(0), sinValue, cosValue);

            break;
        }

        case MatrixRotationAxis::Y:
        {
            m_X.SetCoordinate(cosValue, Math::GetValue(0), sinValue);
            m_Y = Vector3::GetUnitY();
            m_Z.SetCoordinate(-sinValue, Math::GetValue(0), cosValue);

            break;
        }

        case MatrixRotationAxis::Z:
        {
            m_X.SetCoordinate(cosValue, -sinValue, Math::GetValue(0));
            m_Y.SetCoordinate(sinValue, cosValue, Math::GetValue(0));
            m_Z = Vector3::GetUnitZ();

            break;
        }
        default:
        {
            MATHEMATICS_ASSERTION_1(false, "错误的枚举值！");
            break;
        }
    }
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeTensorProduct(const Vector3& vector0, const Vector3& vector1) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X.SetCoordinate(vector0.GetX() * vector1.GetX(), vector0.GetX() * vector1.GetY(), vector0.GetX() * vector1.GetZ());
    m_Y.SetCoordinate(vector0.GetY() * vector1.GetX(), vector0.GetY() * vector1.GetY(), vector0.GetY() * vector1.GetZ());
    m_Z.SetCoordinate(vector0.GetZ() * vector1.GetX(), vector0.GetZ() * vector1.GetY(), vector0.GetZ() * vector1.GetZ());
}

template <typename Real>
const Mathematics::Vector3<Real>& Mathematics::Matrix3<Real>::operator[](int row) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    switch (System::UnderlyingCastEnum<VectorIndex>(row))
    {
        case Matrix3::VectorIndex::X:
            return m_X;
        case Matrix3::VectorIndex::Y:
            return m_Y;
        case Matrix3::VectorIndex::Z:
            return m_Z;
        default:
            break;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引错误！"s));
}

template <typename Real>
Mathematics::Vector3<Real>& Mathematics::Matrix3<Real>::operator[](int row)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(Mathematics::Vector3<Real>, row);
}

template <typename Real>
const Real& Mathematics::Matrix3<Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    MATHEMATICS_ASSERTION_0(xIndex <= row && row < vectorSize, "row索引错误！");
    MATHEMATICS_ASSERTION_0(Vector3::xIndex <= column && column < Vector3::pointSize, "column索引错误！");

    return (*this)[row][column];
}

template <typename Real>
Real& Mathematics::Matrix3<Real>::operator()(int row, int column)
{
    MATHEMATICS_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, column));

#include STSTEM_WARNING_POP
}

template <typename Real>
Mathematics::Matrix3<Real> Mathematics::Matrix3<Real>::operator-() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix3{ -m_X.GetX(),
                    -m_X.GetY(),
                    -m_X.GetZ(),
                    -m_Y.GetX(),
                    -m_Y.GetY(),
                    -m_Y.GetZ(),
                    -m_Z.GetX(),
                    -m_Z.GetY(),
                    -m_Z.GetZ() };
}

template <typename Real>
Mathematics::Matrix3<Real>& Mathematics::Matrix3<Real>::operator+=(const Matrix3& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X += rhs.m_X;
    m_Y += rhs.m_Y;
    m_Z += rhs.m_Z;

    return *this;
}

template <typename Real>
Mathematics::Matrix3<Real>& Mathematics::Matrix3<Real>::operator-=(const Matrix3& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X -= rhs.m_X;
    m_Y -= rhs.m_Y;
    m_Z -= rhs.m_Z;

    return *this;
}

template <typename Real>
Mathematics::Matrix3<Real>& Mathematics::Matrix3<Real>::operator*=(Real scalar) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X *= scalar;
    m_Y *= scalar;
    m_Z *= scalar;

    return *this;
}

template <typename Real>
Mathematics::Matrix3<Real>& Mathematics::Matrix3<Real>::operator/=(Real scalar) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X /= scalar;
    m_Y /= scalar;
    m_Z /= scalar;

    return *this;
}

template <typename Real>
Real Mathematics::Matrix3<Real>::QuadraticForm(const Vector3& lhs, const Vector3& rhs) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Vector3Tools::DotProduct(lhs, (*this) * rhs);
}

template <typename Real>
Mathematics::Matrix3<Real> Mathematics::Matrix3<Real>::Transpose() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix3<Real>{ GetValue<0, 0>(),
                          GetValue<1, 0>(),
                          GetValue<2, 0>(),
                          GetValue<0, 1>(),
                          GetValue<1, 1>(),
                          GetValue<2, 1>(),
                          GetValue<0, 2>(),
                          GetValue<1, 2>(),
                          GetValue<2, 2>() };
}

template <typename Real>
Mathematics::Matrix3<Real>& Mathematics::Matrix3<Real>::operator*=(const Matrix3& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    *this = *this * rhs;

    return *this;
}

template <typename Real>
Mathematics::Matrix3<Real> Mathematics::Matrix3<Real>::TimesDiagonal(const Vector3& diagonal) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix3<Real>{ GetValue<0, 0>() * diagonal.GetX(),
                          GetValue<0, 1>() * diagonal.GetY(),
                          GetValue<0, 2>() * diagonal.GetZ(),
                          GetValue<1, 0>() * diagonal.GetX(),
                          GetValue<1, 1>() * diagonal.GetY(),
                          GetValue<1, 2>() * diagonal.GetZ(),
                          GetValue<2, 0>() * diagonal.GetX(),
                          GetValue<2, 1>() * diagonal.GetY(),
                          GetValue<2, 2>() * diagonal.GetZ() };
}

template <typename Real>
Mathematics::Matrix3<Real> Mathematics::Matrix3<Real>::DiagonalTimes(const Vector3& diagonal) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix3<Real>{ GetValue<0, 0>() * diagonal.GetX(),
                          GetValue<0, 1>() * diagonal.GetX(),
                          GetValue<0, 2>() * diagonal.GetX(),
                          GetValue<1, 0>() * diagonal.GetY(),
                          GetValue<1, 1>() * diagonal.GetY(),
                          GetValue<1, 2>() * diagonal.GetY(),
                          GetValue<2, 0>() * diagonal.GetZ(),
                          GetValue<2, 1>() * diagonal.GetZ(),
                          GetValue<2, 2>() * diagonal.GetZ() };
}

template <typename Real>
Mathematics::Matrix3<Real> Mathematics::Matrix3<Real>::GaussianEliminationInverse(const Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    GaussianElimination<Real> gaussianElimination{ vectorSize, GetContainer(), true, epsilon };

    if (gaussianElimination.IsInverse())
    {
        return Matrix3{ gaussianElimination.GetInverse(), MatrixMajorFlags::Row };
    }
    else
    {
        MATHEMATICS_ASSERTION_0(false, "该矩阵不存在逆矩阵！");

        return GetZero();
    }
}

template <typename Real>
Real Mathematics::Matrix3<Real>::GaussianEliminationDeterminant(const Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    GaussianElimination<Real> gaussianElimination{ vectorSize, GetContainer(), false, epsilon };

    return gaussianElimination.GetDeterminant();
}

template <typename Real>
Mathematics::Matrix3<Real> Mathematics::Matrix3<Real>::Inverse(const Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    // 使用辅助因子求一个3x3矩阵的逆。
    // 这比使用高斯消元法更快，因为循环的开销相当于一个方法。

    // 计算伴随矩阵。
    auto adjoint = Adjoint();

    const auto det = GetValue<0, 0>() * adjoint.GetValue<0, 0>() + GetValue<0, 1>() * adjoint.GetValue<1, 0>() + GetValue<0, 2>() * adjoint.GetValue<2, 0>();

    if (epsilon < Math::FAbs(det))
    {
        // 除零错误使用的epsilon和这里的epsilon不同，
        // 所以使用先求倒数，再乘。
        adjoint *= (1 / det);

        return adjoint;
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "该矩阵不存在逆矩阵！");

        return GetZero();
    }
}

template <typename Real>
Mathematics::Matrix3<Real> Mathematics::Matrix3<Real>::Adjoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix3<Real>{ GetValue<1, 1>() * GetValue<2, 2>() - GetValue<1, 2>() * GetValue<2, 1>(),
                          GetValue<0, 2>() * GetValue<2, 1>() - GetValue<0, 1>() * GetValue<2, 2>(),
                          GetValue<0, 1>() * GetValue<1, 2>() - GetValue<0, 2>() * GetValue<1, 1>(),

                          GetValue<1, 2>() * GetValue<2, 0>() - GetValue<1, 0>() * GetValue<2, 2>(),
                          GetValue<0, 0>() * GetValue<2, 2>() - GetValue<0, 2>() * GetValue<2, 0>(),
                          GetValue<0, 2>() * GetValue<1, 0>() - GetValue<0, 0>() * GetValue<1, 2>(),

                          GetValue<1, 0>() * GetValue<2, 1>() - GetValue<1, 1>() * GetValue<2, 0>(),
                          GetValue<0, 1>() * GetValue<2, 0>() - GetValue<0, 0>() * GetValue<2, 1>(),
                          GetValue<0, 0>() * GetValue<1, 1>() - GetValue<0, 1>() * GetValue<1, 0>() };
}

template <typename Real>
Real Mathematics::Matrix3<Real>::Determinant() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto column00 = GetValue<1, 1>() * GetValue<2, 2>() - GetValue<1, 2>() * GetValue<2, 1>();
    const auto column10 = GetValue<1, 2>() * GetValue<2, 0>() - GetValue<1, 0>() * GetValue<2, 2>();
    const auto column20 = GetValue<1, 0>() * GetValue<2, 1>() - GetValue<1, 1>() * GetValue<2, 0>();

    return GetValue<0, 0>() * column00 + GetValue<0, 1>() * column10 + GetValue<0, 2>() * column20;
}

// private
template <typename Real>
Real Mathematics::Matrix3<Real>::ExtractAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto trace = GetValue<0, 0>() + GetValue<1, 1>() + GetValue<2, 2>();
    const auto cosValue = Math::GetRational(1, 2) * (trace - Math::GetValue(1));

    return Math::ACos(cosValue);  // angle范围在 [0,PI]
}

template <typename Real>
typename Mathematics::Matrix3<Real>::Matrix3Extract Mathematics::Matrix3<Real>::ExtractAngleAxis() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    // 设(x,y,z)是单位长度的轴和A是一个旋转角。
    // 旋转矩阵Real = I + sin(A) * P + (1 - cos(A)) * P^2，其中I是单位矩阵和
    //       +-        -+
    //   P = |  0 -z +y |
    //       | +z  0 -x |
    //       | -y +x  0 |
    //       +-        -+
    //
    // 如果A > 0时，Real表示绕轴线从观看轴矢量的末端朝向原点的的感觉逆时针旋转。
    // 一些代数将证明
    //
    //   cos(A) = (trace(Real) - 1) / 2  和  Real - Real^t = 2 * sin(A) * P
    //
    // 倘若A = pi，Real - Real^t = 0，这使我们无法通过P来提取轴
    // 取而代之的主意是，Real = I + 2 * P^2当A = pi，因此P^2 = (Real - I) / 2。
    // P^2的对角元素为x^2 - 1， y^2 - 1和z^2 - 1。
    // 我们能够解出轴(x,y,z)
    // 因为角度是pi，你选择的平方根的标志的符号并不要紧。

    const auto angle = ExtractAngle();  // angle范围在 [0,PI]

    if (Math::GetZeroTolerance() < angle)
    {
        Vector3 axis{ GetValue<2, 1>() - GetValue<1, 2>(),
                      GetValue<0, 2>() - GetValue<2, 0>(),
                      GetValue<1, 0>() - GetValue<0, 1>() };

        if (Math::GetZeroTolerance() * Math::GetZeroTolerance() < Vector3Tools::GetLengthSquared(axis))
        {
            axis.Normalize();
        }
        else
        {
            // 角度是 PI
            if (GetValue<1, 1>() <= GetValue<0, 0>() && GetValue<2, 2>() <= GetValue<0, 0>())
            {
                // r11 <= r00

                // r00是最大对角线项
                auto axisX = Math::GetRational(1, 2) * Math::Sqrt(Math::GetValue(1) + GetValue<0, 0>() - GetValue<1, 1>() - GetValue<2, 2>());

                const auto halfInverse = Math::GetRational(1, 2) / axisX;

                axis = Vector3{ axisX, halfInverse * GetValue<0, 1>(), halfInverse * GetValue<0, 2>() };
            }
            else if (GetValue<0, 0>() < GetValue<1, 1>() && GetValue<2, 2>() <= GetValue<1, 1>())
            {
                // r00 < r11

                // r11是最大对角线项
                auto axisY = Math::GetRational(1, 2) * Math::Sqrt(Math::GetValue(1) + GetValue<1, 1>() - GetValue<0, 0>() - GetValue<2, 2>());

                const auto halfInverse = Math::GetRational(1, 2) / axisY;

                axis = Vector3{ halfInverse * GetValue<0, 1>(), axisY, halfInverse * GetValue<1, 2>() };
            }
            else
            {
                // r22是最大对角线项
                auto axisZ = Math::GetRational(1, 2) * Math::Sqrt(Math::GetValue(1) + GetValue<2, 2>() - GetValue<0, 0>() - GetValue<1, 1>());

                const auto halfInverse = Math::GetRational(1, 2) / axisZ;

                axis = Vector3{ halfInverse * GetValue<0, 2>(), halfInverse * GetValue<1, 2>(), axisZ };
            }
        }

        return Matrix3Extract{ angle, axis };
    }
    else
    {
        // 角度为0的矩阵是单位矩阵。所有轴都可以工作，因此只需使用x轴。
        return Matrix3Extract{ angle, Vector3::GetUnitX() };
    }
}

template <typename Real>
typename Mathematics::Matrix3<Real>::Vector3 Mathematics::Matrix3<Real>::ExtractAxis() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto extract = ExtractAngleAxis();

    return extract.GetAxis();
}

template <typename Real>
void Mathematics::Matrix3<Real>::Orthonormalize()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    // 算法采用Gram-Schmidt正交。
    // 如果'this'矩阵为M = [m0|m1|m2]，然后输出正交矩阵Q = [q0|q1|q2]
    //
    //   q0 = m0 / |m0|
    //   q1 = (m1 - (q0 * m1)q0) / |m1 - (q0 * m1)q0|
    //   q2 = (m2 - (q0 * m2)q0 - (q1 * m2)q1) / |m2 - (q0 * m2)q0 - (q1 * m2)q1|
    // 其中|V|表示向量V的长度和A * B表示向量A和B的点积

    // 计算 q0.
    auto invLength = Math::InvSqrt(GetValue<0, 0>() * GetValue<0, 0>() + GetValue<1, 0>() * GetValue<1, 0>() + GetValue<2, 0>() * GetValue<2, 0>());

    (*this)(0, 0) *= invLength;
    (*this)(1, 0) *= invLength;
    (*this)(2, 0) *= invLength;

    // 计算 q1.
    auto dot0 = GetValue<0, 0>() * GetValue<0, 1>() + GetValue<1, 0>() * GetValue<1, 1>() + GetValue<2, 0>() * GetValue<2, 1>();

    (*this)(0, 1) -= dot0 * GetValue<0, 0>();
    (*this)(1, 1) -= dot0 * GetValue<1, 0>();
    (*this)(2, 1) -= dot0 * GetValue<2, 0>();

    invLength = Math::InvSqrt(GetValue<0, 1>() * GetValue<0, 1>() + GetValue<1, 1>() * GetValue<1, 1>() + GetValue<2, 1>() * GetValue<2, 1>());

    (*this)(0, 1) *= invLength;
    (*this)(1, 1) *= invLength;
    (*this)(2, 1) *= invLength;

    // 计算 q2
    auto dot1 = GetValue<0, 1>() * GetValue<0, 2>() + GetValue<1, 1>() * GetValue<1, 2>() + GetValue<2, 1>() * GetValue<2, 2>();

    auto dot2 = GetValue<0, 0>() * GetValue<0, 2>() + GetValue<1, 0>() * GetValue<1, 2>() + GetValue<2, 0>() * GetValue<2, 2>();

    (*this)(0, 2) -= dot2 * GetValue<0, 0>() + dot1 * GetValue<0, 1>();
    (*this)(1, 2) -= dot2 * GetValue<1, 0>() + dot1 * GetValue<1, 1>();
    (*this)(2, 2) -= dot2 * GetValue<2, 0>() + dot1 * GetValue<2, 1>();

    invLength = Math::InvSqrt(GetValue<0, 2>() * GetValue<0, 2>() + GetValue<1, 2>() * GetValue<1, 2>() + GetValue<2, 2>() * GetValue<2, 2>());

    (*this)(0, 2) *= invLength;
    (*this)(1, 2) *= invLength;
    (*this)(2, 2) *= invLength;
}

template <typename Real>
typename Mathematics::Matrix3<Real>::Matrix3EigenDecomposition Mathematics::Matrix3<Real>::EigenDecomposition(const Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    MATHEMATICS_ASSERTION_1(Math::FAbs(GetValue<0, 1>() - GetValue<1, 0>()) <= epsilon, "矩阵必须是对称矩阵。");
    MATHEMATICS_ASSERTION_1(Math::FAbs(GetValue<0, 2>() - GetValue<2, 0>()) <= epsilon, "矩阵必须是对称矩阵。");
    MATHEMATICS_ASSERTION_1(Math::FAbs(GetValue<1, 2>() - GetValue<2, 1>()) <= epsilon, "矩阵必须是对称矩阵。");

    // 系数 M = Real * D * Real^T。
    // Real的列是特征向量。D的对角元素为相应的特征值。
    const Tridiagonalize<Real> tridiagonalize{ *this };

    auto reflection = tridiagonalize.IsReflection();
    auto rotation = tridiagonalize.GetRotation();
    auto diagonal = tridiagonalize.GetDiagonal();

    // 特征值按递增顺序排序，d0 <= d1 <= d2。这是一个插入排序。
    if (diagonal.GetY() < diagonal.GetX())
    {
        // 交换 d0 和 d1.
        std::swap(diagonal[0], diagonal[1]);

        // 交换 V0 和 V1.
        for (auto i = 0; i < vectorSize; ++i)
        {
            std::swap(rotation(i, 0), rotation(i, 1));
        }
        reflection = !reflection;
    }

    if (diagonal.GetZ() < diagonal.GetY())
    {
        // 交换 d1 和 d2.
        std::swap(diagonal[1], diagonal[2]);

        // 交换 V1 和 V2.
        for (auto i = 0; i < vectorSize; ++i)
        {
            std::swap(rotation(i, 1), rotation(i, 2));
        }
        reflection = !reflection;
    }

    if (diagonal.GetY() < diagonal.GetX())
    {
        // 交换 d0 和 d1.
        std::swap(diagonal[0], diagonal[1]);

        // 交换 V0 和 V1.
        for (auto i = 0; i < vectorSize; ++i)
        {
            std::swap(rotation(i, 0), rotation(i, 1));
        }
        reflection = !reflection;
    }

    const Matrix3 diagonalMatrix{ diagonal.GetX(), diagonal.GetY(), diagonal.GetZ() };

    if (reflection)
    {
        // 这对角矩阵M正交变换是一种反射。通过改变最后一列的符号使特征向量符合右手系统。
        rotation(0, 2) = -rotation.GetValue<0, 2>();
        rotation(1, 2) = -rotation.GetValue<1, 2>();
        rotation(2, 2) = -rotation.GetValue<2, 2>();
    }

    return Matrix3EigenDecomposition{ rotation, diagonalMatrix, epsilon };
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeEuler(const Euler& euler) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    switch (euler.GetOrder())
    {
        case ExtractEulerResultOrder::XYZ:
            MakeEulerXYZ(euler.GetX0Angle(), euler.GetY0Angle(), euler.GetZ0Angle());
            break;
        case ExtractEulerResultOrder::XZY:
            MakeEulerXYZ(euler.GetX0Angle(), euler.GetZ0Angle(), euler.GetY0Angle());
            break;
        case ExtractEulerResultOrder::YXZ:
            MakeEulerXYZ(euler.GetY0Angle(), euler.GetX0Angle(), euler.GetZ0Angle());
            break;
        case ExtractEulerResultOrder::YZX:
            MakeEulerXYZ(euler.GetY0Angle(), euler.GetZ0Angle(), euler.GetX0Angle());
            break;
        case ExtractEulerResultOrder::ZXY:
            MakeEulerXYZ(euler.GetZ0Angle(), euler.GetX0Angle(), euler.GetY0Angle());
            break;
        case ExtractEulerResultOrder::ZYX:
            MakeEulerXYZ(euler.GetZ0Angle(), euler.GetY0Angle(), euler.GetX0Angle());
            break;
        case ExtractEulerResultOrder::XYX:
            MakeEulerXYZ(euler.GetX0Angle(), euler.GetY0Angle(), euler.GetX1Angle());
            break;
        case ExtractEulerResultOrder::XZX:
            MakeEulerXYZ(euler.GetX0Angle(), euler.GetZ0Angle(), euler.GetX1Angle());
            break;
        case ExtractEulerResultOrder::YXY:
            MakeEulerXYZ(euler.GetY0Angle(), euler.GetX0Angle(), euler.GetY1Angle());
            break;
        case ExtractEulerResultOrder::YZY:
            MakeEulerXYZ(euler.GetY0Angle(), euler.GetZ0Angle(), euler.GetY1Angle());
            break;
        case ExtractEulerResultOrder::ZXZ:
            MakeEulerXYZ(euler.GetZ0Angle(), euler.GetX0Angle(), euler.GetZ1Angle());
            break;
        case ExtractEulerResultOrder::ZYZ:
            MakeEulerXYZ(euler.GetZ0Angle(), euler.GetY0Angle(), euler.GetZ1Angle());
            break;
        default:
            break;
    }
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeEulerXYZ(Real xAngle, Real yAngle, Real zAngle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const Matrix3 xMat{ MatrixRotationAxis::X, xAngle };
    const Matrix3 yMat{ MatrixRotationAxis::Y, yAngle };
    const Matrix3 zMat{ MatrixRotationAxis::Z, zAngle };

    *this = xMat * (yMat * zMat);
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeEulerXZY(Real xAngle, Real zAngle, Real yAngle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const Matrix3 xMat{ MatrixRotationAxis::X, xAngle };
    const Matrix3 zMat{ MatrixRotationAxis::Z, zAngle };
    const Matrix3 yMat{ MatrixRotationAxis::Y, yAngle };

    *this = xMat * (zMat * yMat);
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeEulerYXZ(Real yAngle, Real xAngle, Real zAngle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const Matrix3 yMat{ MatrixRotationAxis::Y, yAngle };
    const Matrix3 xMat{ MatrixRotationAxis::X, xAngle };
    const Matrix3 zMat{ MatrixRotationAxis::Z, zAngle };

    *this = yMat * (xMat * zMat);
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeEulerYZX(Real yAngle, Real zAngle, Real xAngle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const Matrix3 yMat{ MatrixRotationAxis::Y, yAngle };
    const Matrix3 zMat{ MatrixRotationAxis::Z, zAngle };
    const Matrix3 xMat{ MatrixRotationAxis::X, xAngle };

    *this = yMat * (zMat * xMat);
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeEulerZXY(Real zAngle, Real xAngle, Real yAngle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const Matrix3 zMat{ MatrixRotationAxis::Z, zAngle };
    const Matrix3 xMat{ MatrixRotationAxis::X, xAngle };
    const Matrix3 yMat{ MatrixRotationAxis::Y, yAngle };

    *this = zMat * (xMat * yMat);
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeEulerZYX(Real zAngle, Real yAngle, Real xAngle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const Matrix3 zMat{ MatrixRotationAxis::Z, zAngle };
    const Matrix3 yMat{ MatrixRotationAxis::Y, yAngle };
    const Matrix3 xMat{ MatrixRotationAxis::X, xAngle };

    *this = zMat * (yMat * xMat);
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeEulerXYX(Real x0Angle, Real yAngle, Real x1Angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const Matrix3 x0Mat{ MatrixRotationAxis::X, x0Angle };
    const Matrix3 yMat{ MatrixRotationAxis::Y, yAngle };
    const Matrix3 x1Mat{ MatrixRotationAxis::X, x1Angle };

    *this = x0Mat * (yMat * x1Mat);
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeEulerXZX(Real x0Angle, Real zAngle, Real x1Angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const Matrix3 x0Mat{ MatrixRotationAxis::X, x0Angle };
    const Matrix3 zMat{ MatrixRotationAxis::Z, zAngle };
    const Matrix3 x1Mat{ MatrixRotationAxis::X, x1Angle };

    *this = x0Mat * (zMat * x1Mat);
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeEulerYXY(Real y0Angle, Real xAngle, Real y1Angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const Matrix3 y0Mat{ MatrixRotationAxis::Y, y0Angle };
    const Matrix3 xMat{ MatrixRotationAxis::X, xAngle };
    const Matrix3 y1Mat{ MatrixRotationAxis::Y, y1Angle };

    *this = y0Mat * (xMat * y1Mat);
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeEulerYZY(Real y0Angle, Real zAngle, Real y1Angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const Matrix3 y0Mat{ MatrixRotationAxis::Y, y0Angle };
    const Matrix3 zMat{ MatrixRotationAxis::Z, zAngle };
    const Matrix3 y1Mat{ MatrixRotationAxis::Y, y1Angle };

    *this = y0Mat * (zMat * y1Mat);
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeEulerZXZ(Real z0Angle, Real xAngle, Real z1Angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const Matrix3 z0Mat{ MatrixRotationAxis::Z, z0Angle };
    const Matrix3 xMat{ MatrixRotationAxis::X, xAngle };
    const Matrix3 z1Mat{ MatrixRotationAxis::Z, z1Angle };

    *this = z0Mat * (xMat * z1Mat);
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeEulerZYZ(Real z0Angle, Real yAngle, Real z1Angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const Matrix3 z0Mat{ MatrixRotationAxis::Z, z0Angle };
    const Matrix3 yMat{ MatrixRotationAxis::Y, yAngle };
    const Matrix3 z1Mat{ MatrixRotationAxis::Z, z1Angle };

    *this = z0Mat * (yMat * z1Mat);
}

template <typename Real>
typename Mathematics::Matrix3<Real>::Euler Mathematics::Matrix3<Real>::ExtractEulerXYZ() const noexcept
{
    // +-           -+   +-                                        -+
    // | r00 r01 r02 |   |  cy*cz           -cy*sz            sy    |
    // | r10 r11 r12 | = |  cz*sx*sy+cx*sz   cx*cz-sx*sy*sz  -cy*sx |
    // | r20 r21 r22 |   | -cx*cz*sy+sx*sz   cz*sx+cx*sy*sz   cx*cy |
    // +-           -+   +-                                        -+
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (GetValue<0, 2>() < Math::GetValue(1) - Math::GetZeroTolerance())
    {
        if (Math::GetValue(-1) + Math::GetZeroTolerance() < GetValue<0, 2>())
        {
            // y_angle = asin(r02)
            // x_angle = atan2(-r12,r22)
            // z_angle = atan2(-r01,r00)
            const auto yAngle = Math::ASin(GetValue<0, 2>());
            const auto xAngle = Math::ATan2(-GetValue<1, 2>(), GetValue<2, 2>());
            const auto zAngle = Math::ATan2(-GetValue<0, 1>(), GetValue<0, 0>());

            return Euler{ ExtractEulerResultType::Unique, ExtractEulerResultOrder::XYZ, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }
        else
        {
            // y_angle = -pi/2
            // z_angle - x_angle = atan2(r10,r11)
            // 警告。该解不是唯一的。选择z_angle = 0.
            constexpr auto yAngle = -Math::GetHalfPI();
            const auto xAngle = -Math::ATan2(GetValue<1, 0>(), GetValue<1, 1>());
            constexpr auto zAngle = Math::GetValue(0);

            return Euler{ ExtractEulerResultType::Difference, ExtractEulerResultOrder::XYZ, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }
    }
    else
    {
        // y_angle = +pi/2
        // z_angle + x_angle = atan2(r10,r11)
        // 警告。该解不是唯一的。选择z_angle = 0.
        constexpr auto yAngle = Math::GetHalfPI();
        const auto xAngle = Math::ATan2(GetValue<1, 0>(), GetValue<1, 1>());
        constexpr auto zAngle = Math::GetValue(0);

        return Euler{ ExtractEulerResultType::Sum, ExtractEulerResultOrder::XYZ, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
    }
}

template <typename Real>
typename Mathematics::Matrix3<Real>::Euler Mathematics::Matrix3<Real>::ExtractEulerXZY() const noexcept
{
    // +-           -+   +-                                        -+
    // | r00 r01 r02 |   |  cy*cz           -sz      cz*sy          |
    // | r10 r11 r12 | = |  sx*sy+cx*cy*sz   cx*cz  -cy*sx+cx*sy*sz |
    // | r20 r21 r22 |   | -cx*sy+cy*sx*sz   cz*sx   cx*cy+sx*sy*sz |
    // +-           -+   +-                                        -+
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (GetValue<0, 1>() < Math::GetValue(1) - Math::GetZeroTolerance())
    {
        if (Math::GetValue(-1) + Math::GetZeroTolerance() < GetValue<0, 1>())
        {
            // z_angle = asin(-r01)
            // x_angle = atan2(r21,r11)
            // y_angle = atan2(r02,r00)
            const auto zAngle = Math::ASin(-GetValue<0, 1>());
            const auto xAngle = Math::ATan2(GetValue<2, 1>(), GetValue<1, 1>());
            const auto yAngle = Math::ATan2(GetValue<0, 2>(), GetValue<0, 0>());

            return Euler{ ExtractEulerResultType::Unique, ExtractEulerResultOrder::XZY, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }
        else
        {
            // z_angle = +pi/2
            // y_angle - x_angle = atan2(-r20,r22)
            // 警告。该解不是唯一的。选择y_angle = 0.
            constexpr auto zAngle = Math::GetHalfPI();
            const auto xAngle = -Math::ATan2(-GetValue<2, 0>(), GetValue<2, 2>());
            constexpr auto yAngle = Math::GetValue(0);

            return Euler{ ExtractEulerResultType::Difference, ExtractEulerResultOrder::XZY, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }
    }
    else
    {
        // z_angle = -pi/2
        // y_angle + x_angle = atan2(-r20,r22)
        // 警告。该解不是唯一的。选择y_angle = 0.
        constexpr auto zAngle = -Math::GetHalfPI();
        const auto xAngle = Math::ATan2(-GetValue<2, 0>(), GetValue<2, 2>());
        constexpr auto yAngle = Math::GetValue(0);

        return Euler{ ExtractEulerResultType::Sum, ExtractEulerResultOrder::XZY, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
    }
}

template <typename Real>
typename Mathematics::Matrix3<Real>::Euler Mathematics::Matrix3<Real>::ExtractEulerYXZ() const noexcept
{
    // +-           -+   +-                                       -+
    // | r00 r01 r02 |   |  cy*cz+sx*sy*sz  cz*sx*sy-cy*sz   cx*sy |
    // | r10 r11 r12 | = |  cx*sz           cx*cz           -sx    |
    // | r20 r21 r22 |   | -cz*sy+cy*sx*sz  cy*cz*sx+sy*sz   cx*cy |
    // +-           -+   +-                                       -+

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (GetValue<1, 2>() < Math::GetValue(1) - Math::GetZeroTolerance())
    {
        if (Math::GetValue(-1) + Math::GetZeroTolerance() < GetValue<1, 2>())
        {
            // x_angle = asin(-r12)
            // y_angle = atan2(r02,r22)
            // z_angle = atan2(r10,r11)
            const auto xAngle = Math::ASin(-GetValue<1, 2>());
            const auto yAngle = Math::ATan2(GetValue<0, 2>(), GetValue<2, 2>());
            const auto zAngle = Math::ATan2(GetValue<1, 0>(), GetValue<1, 1>());

            return Euler{ ExtractEulerResultType::Unique, ExtractEulerResultOrder::YXZ, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }
        else
        {
            // x_angle = +pi/2
            // z_angle - y_angle = atan2(-r01,r00)
            // 警告。该解不是唯一的。选择 z_angle = 0.
            constexpr auto xAngle = Math::GetHalfPI();
            const auto yAngle = -Math::ATan2(-GetValue<0, 1>(), GetValue<0, 0>());
            constexpr auto zAngle = Math::GetValue(0);

            return Euler{ ExtractEulerResultType::Difference, ExtractEulerResultOrder::YXZ, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }
    }
    else
    {
        // x_angle = -pi/2
        // z_angle + y_angle = atan2(-r01,r00)
        // 警告。该解不是唯一的。选择z_angle = 0.
        constexpr auto xAngle = -Math::GetHalfPI();
        const auto yAngle = Math::ATan2(-GetValue<0, 1>(), GetValue<0, 0>());
        constexpr auto zAngle = Math::GetValue(0);

        return Euler{ ExtractEulerResultType::Sum, ExtractEulerResultOrder::YXZ, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
    }
}

template <typename Real>
typename Mathematics::Matrix3<Real>::Euler Mathematics::Matrix3<Real>::ExtractEulerYZX() const noexcept
{
    // +-           -+   +-                                       -+
    // | r00 r01 r02 |   |  cy*cz  sx*sy-cx*cy*sz   cx*sy+cy*sx*sz |
    // | r10 r11 r12 | = |  sz     cx*cz           -cz*sx          |
    // | r20 r21 r22 |   | -cz*sy  cy*sx+cx*sy*sz   cx*cy-sx*sy*sz |
    // +-           -+   +-                                       -+

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (GetValue<1, 0>() < Math::GetValue(1) - Math::GetZeroTolerance())
    {
        if (Math::GetValue(-1) + Math::GetZeroTolerance() < GetValue<1, 0>())
        {
            // z_angle = asin(r10)
            // y_angle = atan2(-r20,r00)
            // x_angle = atan2(-r12,r11)
            const auto zAngle = Math::ASin(GetValue<1, 0>());
            const auto yAngle = Math::ATan2(-GetValue<2, 0>(), GetValue<0, 0>());
            const auto xAngle = Math::ATan2(-GetValue<1, 2>(), GetValue<1, 1>());

            return Euler{ ExtractEulerResultType::Unique, ExtractEulerResultOrder::YZX, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }
        else
        {
            // z_angle = -pi/2
            // x_angle - y_angle = atan2(r21,r22)
            // 警告。该解不是唯一的。选择 x_angle = 0.

            constexpr auto zAngle = -Math::GetHalfPI();
            const auto yAngle = -Math::ATan2(GetValue<2, 1>(), GetValue<2, 2>());
            constexpr auto xAngle = Math::GetValue(0);

            return Euler{ ExtractEulerResultType::Difference, ExtractEulerResultOrder::YZX, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }
    }
    else
    {
        // z_angle = +pi/2
        // x_angle + y_angle = atan2(r21,r22)
        // 警告。该解不是唯一的。选择 x_angle = 0.

        constexpr auto zAngle = Math::GetHalfPI();
        const auto yAngle = Math::ATan2(GetValue<2, 1>(), GetValue<2, 2>());
        constexpr auto xAngle = Math::GetValue(0);

        return Euler{ ExtractEulerResultType::Sum, ExtractEulerResultOrder::YZX, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
    }
}

template <typename Real>
typename Mathematics::Matrix3<Real>::Euler Mathematics::Matrix3<Real>::ExtractEulerZXY() const noexcept
{
    // +-           -+   +-                                        -+
    // | r00 r01 r02 |   |  cy*cz-sx*sy*sz  -cx*sz   cz*sy+cy*sx*sz |
    // | r10 r11 r12 | = |  cz*sx*sy+cy*sz   cx*cz  -cy*cz*sx+sy*sz |
    // | r20 r21 r22 |   | -cx*sy            sx      cx*cy          |
    // +-           -+   +-                                        -+

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (GetValue<2, 1>() < Math::GetValue(1) - Math::GetZeroTolerance())
    {
        if (Math::GetValue(-1) + Math::GetZeroTolerance() < GetValue<2, 1>())
        {
            // x_angle = asin(r21)
            // z_angle = atan2(-r01,r11)
            // y_angle = atan2(-r20,r22)

            const auto xAngle = Math::ASin(GetValue<2, 1>());
            const auto zAngle = Math::ATan2(-GetValue<0, 1>(), GetValue<1, 1>());
            const auto yAngle = Math::ATan2(-GetValue<2, 0>(), GetValue<2, 2>());

            return Euler{ ExtractEulerResultType::Unique, ExtractEulerResultOrder::ZXY, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }
        else
        {
            // x_angle = -pi/2
            // y_angle - z_angle = atan2(r02,r00)
            // 警告。该解不是唯一的。选择 y_angle = 0.

            constexpr auto xAngle = -Math::GetHalfPI();
            const auto zAngle = -Math::ATan2(GetValue<0, 2>(), GetValue<0, 0>());
            constexpr auto yAngle = Math::GetValue(0);

            return Euler{ ExtractEulerResultType::Difference, ExtractEulerResultOrder::ZXY, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }
    }
    else
    {
        // x_angle = +pi/2
        // y_angle + z_angle = atan2(r02,r00)
        // 警告。该解不是唯一的。选择 y_angle = 0.

        constexpr auto xAngle = Math::GetHalfPI();
        const auto zAngle = Math::ATan2(GetValue<0, 2>(), GetValue<0, 0>());
        constexpr auto yAngle = Math::GetValue(0);

        return Euler{ ExtractEulerResultType::Sum, ExtractEulerResultOrder::ZXY, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
    }
}

template <typename Real>
typename Mathematics::Matrix3<Real>::Euler Mathematics::Matrix3<Real>::ExtractEulerZYX() const noexcept
{
    // +-           -+   +-                                      -+
    // | r00 r01 r02 |   |  cy*cz  cz*sx*sy-cx*sz  cx*cz*sy+sx*sz |
    // | r10 r11 r12 | = |  cy*sz  cx*cz+sx*sy*sz -cz*sx+cx*sy*sz |
    // | r20 r21 r22 |   | -sy     cy*sx           cx*cy          |
    // +-           -+   +-                                      -+

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (GetValue<2, 0>() < Math::GetValue(1) - Math::GetZeroTolerance())
    {
        if (Math::GetValue(-1) + Math::GetZeroTolerance() < GetValue<2, 0>())
        {
            // y_angle = asin(-r20)
            // z_angle = atan2(r10,r00)
            // x_angle = atan2(r21,r22)

            const auto yAngle = Math::ASin(-GetValue<2, 0>());
            const auto zAngle = Math::ATan2(GetValue<1, 0>(), GetValue<0, 0>());
            const auto xAngle = Math::ATan2(GetValue<2, 1>(), GetValue<2, 2>());

            return Euler{ ExtractEulerResultType::Unique, ExtractEulerResultOrder::ZYX, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }
        else
        {
            // y_angle = +pi/2
            // x_angle - z_angle = atan2(r01,r02)
            // 警告。该解不是唯一的。选择 x_angle = 0.

            constexpr auto yAngle = Math::GetHalfPI();
            const auto zAngle = -Math::ATan2(GetValue<0, 1>(), GetValue<0, 2>());
            constexpr auto xAngle = Math::GetValue(0);

            return Euler{ ExtractEulerResultType::Difference, ExtractEulerResultOrder::ZYX, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }
    }
    else
    {
        // y_angle = -pi/2
        // x_angle + z_angle = atan2(-r01,-r02)
        // 警告。该解不是唯一的。选择 x_angle = 0;

        constexpr auto yAngle = -Math::GetHalfPI();
        const auto zAngle = Math::ATan2(-GetValue<0, 1>(), -GetValue<0, 2>());
        constexpr auto xAngle = Math::GetValue(0);

        return Euler{ ExtractEulerResultType::Sum, ExtractEulerResultOrder::ZYX, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
    }
}

template <typename Real>
typename Mathematics::Matrix3<Real>::Euler Mathematics::Matrix3<Real>::ExtractEulerXYX() const noexcept
{
    // +-           -+   +-                                                -+
    // | r00 r01 r02 |   |  cy      sy*sx1               sy*cx1             |
    // | r10 r11 r12 | = |  sy*sx0  cx0*cx1-cy*sx0*sx1  -cy*cx1*sx0-cx0*sx1 |
    // | r20 r21 r22 |   | -sy*cx0  cx1*sx0+cy*cx0*sx1   cy*cx0*cx1-sx0*sx1 |
    // +-           -+   +-                                                -+

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (GetValue<0, 0>() < Math::GetValue(1) - Math::GetZeroTolerance())
    {
        if (Math::GetValue(-1) + Math::GetZeroTolerance() < GetValue<0, 0>())
        {
            // y_angle  = acos(r00)
            // x0_angle = atan2(r10,-r20)
            // x1_angle = atan2(r01,r02)

            const auto yAngle = Math::ACos(GetValue<0, 0>());
            const auto x0Angle = Math::ATan2(GetValue<1, 0>(), -GetValue<2, 0>());
            const auto x1Angle = Math::ATan2(GetValue<0, 1>(), GetValue<0, 2>());

            return Euler{ ExtractEulerResultType::Unique, ExtractEulerResultOrder::XYX, x0Angle, yAngle, Math::GetValue(0), x1Angle, Math::GetValue(0), Math::GetValue(0) };
        }
        else
        {
            // 该解不是唯一的:  x1_angle - x0_angle = atan2(-r12,r11)

            constexpr auto yAngle = Math::GetPI();
            const auto x0Angle = -Math::ATan2(-GetValue<1, 2>(), GetValue<1, 1>());
            constexpr auto x1Angle = Math::GetValue(0);

            return Euler{ ExtractEulerResultType::Difference, ExtractEulerResultOrder::XYX, x0Angle, yAngle, Math::GetValue(0), x1Angle, Math::GetValue(0), Math::GetValue(0) };
        }
    }
    else
    {
        // 该解不是唯一的:  x1_angle + x0_angle = atan2(-r12,r11)
        constexpr auto yAngle = Math::GetValue(0);
        const auto x0Angle = Math::ATan2(-GetValue<1, 2>(), GetValue<1, 1>());
        constexpr auto x1Angle = Math::GetValue(0);

        return Euler{ ExtractEulerResultType::Sum, ExtractEulerResultOrder::XYX, x0Angle, yAngle, Math::GetValue(0), x1Angle, Math::GetValue(0), Math::GetValue(0) };
    }
}

template <typename Real>
typename Mathematics::Matrix3<Real>::Euler Mathematics::Matrix3<Real>::ExtractEulerXZX() const noexcept
{
    // +-           -+   +-                                                -+
    // | r00 r01 r02 |   | cz      -sz*cx1               sz*sx1             |
    // | r10 r11 r12 | = | sz*cx0   cz*cx0*cx1-sx0*sx1  -cx1*sx0-cz*cx0*sx1 |
    // | r20 r21 r22 |   | sz*sx0   cz*cx1*sx0+cx0*sx1   cx0*cx1-cz*sx0*sx1 |
    // +-           -+   +-                                                -+

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (GetValue<0, 0>() < Math::GetValue(1) - Math::GetZeroTolerance())
    {
        if (Math::GetValue(-1) + Math::GetZeroTolerance() < GetValue<0, 0>())
        {
            // z_angle  = acos(r00)
            // x0_angle = atan2(r20,r10)
            // x1_angle = atan2(r02,-r01)

            const auto zAngle = Math::ACos(GetValue<0, 0>());
            const auto x0Angle = Math::ATan2(GetValue<2, 0>(), GetValue<1, 0>());
            const auto x1Angle = Math::ATan2(GetValue<0, 2>(), -GetValue<0, 1>());

            return Euler{ ExtractEulerResultType::Unique, ExtractEulerResultOrder::XZX, x0Angle, Math::GetValue(0), zAngle, x1Angle, Math::GetValue(0), Math::GetValue(0) };
        }
        else
        {
            // 该解不是唯一的:  x1_angle - x0_angle = atan2(r21,r22)

            constexpr auto zAngle = Math::GetPI();
            const auto x0Angle = -Math::ATan2(GetValue<2, 1>(), GetValue<2, 2>());
            constexpr auto x1Angle = Math::GetValue(0);

            return Euler{ ExtractEulerResultType::Difference, ExtractEulerResultOrder::XZX, x0Angle, Math::GetValue(0), zAngle, x1Angle, Math::GetValue(0), Math::GetValue(0) };
        }
    }
    else
    {
        // 该解不是唯一的: x1_angle + x0_angle = atan2(r21,r22)

        constexpr auto zAngle = Math::GetValue(0);
        const auto x0Angle = Math::ATan2(GetValue<2, 1>(), GetValue<2, 2>());
        constexpr auto x1Angle = Math::GetValue(0);

        return Euler{ ExtractEulerResultType::Sum, ExtractEulerResultOrder::XZX, x0Angle, Math::GetValue(0), zAngle, x1Angle, Math::GetValue(0), Math::GetValue(0) };
    }
}

template <typename Real>
typename Mathematics::Matrix3<Real>::Euler Mathematics::Matrix3<Real>::ExtractEulerYXY() const noexcept
{
    // +-           -+   +-                                                -+
    // | r00 r01 r02 |   |  cy0*cy1-cx*sy0*sy1  sx*sy0   cx*cy1*sy0+cy0*sy1 |
    // | r10 r11 r12 | = |  sx*sy1              cx      -sx*cy1             |
    // | r20 r21 r22 |   | -cy1*sy0-cx*cy0*sy1  sx*cy0   cx*cy0*cy1-sy0*sy1 |
    // +-           -+   +-                                                -+

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (GetValue<1, 1>() < Math::GetValue(1) - Math::GetZeroTolerance())
    {
        if (Math::GetValue(-1) + Math::GetZeroTolerance() < GetValue<1, 1>())
        {
            // x_angle  = acos(r11)
            // y0_angle = atan2(r01,r21)
            // y1_angle = atan2(r10,-r12)

            const auto xAngle = Math::ACos(GetValue<1, 1>());
            const auto y0Angle = Math::ATan2(GetValue<0, 1>(), GetValue<2, 1>());
            const auto y1Angle = Math::ATan2(GetValue<1, 0>(), -GetValue<1, 2>());

            return Euler{ ExtractEulerResultType::Unique, ExtractEulerResultOrder::YXY, xAngle, y0Angle, Math::GetValue(0), Math::GetValue(0), y1Angle, Math::GetValue(0) };
        }
        else
        {
            // 该解不是唯一的:  y1_angle - y0_angle = atan2(r02,r00)

            constexpr auto xAngle = Math::GetPI();
            const auto y0Angle = -Math::ATan2(GetValue<0, 2>(), GetValue<0, 0>());
            constexpr auto y1Angle = Math::GetValue(0);

            return Euler{ ExtractEulerResultType::Difference, ExtractEulerResultOrder::YXY, xAngle, y0Angle, Math::GetValue(0), Math::GetValue(0), y1Angle, Math::GetValue(0) };
        }
    }
    else
    {
        // 该解不是唯一的: y1_angle + y0_angle = atan2(r02,r00)

        constexpr auto xAngle = Math::GetValue(0);
        const auto y0Angle = Math::ATan2(GetValue<0, 2>(), GetValue<0, 0>());
        constexpr auto y1Angle = Math::GetValue(0);

        return Euler{ ExtractEulerResultType::Sum, ExtractEulerResultOrder::YXY, xAngle, y0Angle, Math::GetValue(0), Math::GetValue(0), y1Angle, Math::GetValue(0) };
    }
}

template <typename Real>
typename Mathematics::Matrix3<Real>::Euler Mathematics::Matrix3<Real>::ExtractEulerYZY() const noexcept
{
    // +-           -+   +-                                                -+
    // | r00 r01 r02 |   |  cz*cy0*cy1-sy0*sy1  -sz*cy0  cy1*sy0+cz*cy0*sy1 |
    // | r10 r11 r12 | = |  sz*cy1               cz      sz*sy1             |
    // | r20 r21 r22 |   | -cz*cy1*sy0-cy0*sy1   sz*sy0  cy0*cy1-cz*sy0*sy1 |
    // +-           -+   +-                                                -+

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (GetValue<1, 1>() < Math::GetValue(1) - Math::GetZeroTolerance())
    {
        if (Math::GetValue(-1) + Math::GetZeroTolerance() < GetValue<1, 1>())
        {
            // z_angle  = acos(r11)
            // y0_angle = atan2(r21,-r01)
            // y1_angle = atan2(r12,r10)

            const auto zAngle = Math::ACos(GetValue<1, 1>());
            const auto y0Angle = Math::ATan2(GetValue<2, 1>(), -GetValue<0, 1>());
            const auto y1Angle = Math::ATan2(GetValue<1, 2>(), GetValue<1, 0>());

            return Euler{ ExtractEulerResultType::Unique, ExtractEulerResultOrder::YZY, Math::GetValue(0), y0Angle, zAngle, Math::GetValue(0), y1Angle, Math::GetValue(0) };
        }
        else
        {
            // 该解不是唯一的:  y1_angle - y0_angle = atan2(-r20,r22)

            constexpr auto zAngle = Math::GetPI();
            const auto y0Angle = -Math::ATan2(-GetValue<2, 0>(), GetValue<2, 2>());
            constexpr auto y1Angle = Math::GetValue(0);

            return Euler{ ExtractEulerResultType::Difference, ExtractEulerResultOrder::YZY, Math::GetValue(0), y0Angle, zAngle, Math::GetValue(0), y1Angle, Math::GetValue(0) };
        }
    }
    else
    {
        // 该解不是唯一的:  y1_angle + y0_angle = atan2(-r20,r22)

        constexpr auto zAngle = Math::GetValue(0);
        const auto y0Angle = Math::ATan2(-GetValue<2, 0>(), GetValue<2, 2>());
        constexpr auto y1Angle = Math::GetValue(0);

        return Euler{ ExtractEulerResultType::Sum, ExtractEulerResultOrder::YZY, Math::GetValue(0), y0Angle, zAngle, Math::GetValue(0), y1Angle, Math::GetValue(0) };
    }
}

template <typename Real>
typename Mathematics::Matrix3<Real>::Euler Mathematics::Matrix3<Real>::ExtractEulerZXZ() const noexcept
{
    // +-           -+   +-                                                -+
    // | r00 r01 r02 |   | cz0*cz1-cx*sz0*sz1  -cx*cz1*sz0-cz0*sz1   sx*sz0 |
    // | r10 r11 r12 | = | cz1*sz0+cx*cz0*sz1   cx*cz0*cz1-sz0*sz1  -sz*cz0 |
    // | r20 r21 r22 |   | sx*sz1               sx*cz1               cx     |
    // +-           -+   +-                                                -+

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (GetValue<2, 2>() < Math::GetValue(1) - Math::GetZeroTolerance())
    {
        if (Math::GetValue(-1) + Math::GetZeroTolerance() < GetValue<2, 2>())
        {
            // x_angle  = acos(r22)
            // z0_angle = atan2(r02,-r12)
            // z1_angle = atan2(r20,r21)

            const auto xAngle = Math::ACos(GetValue<2, 2>());
            const auto z0Angle = Math::ATan2(GetValue<0, 2>(), -GetValue<1, 2>());
            const auto z1Angle = Math::ATan2(GetValue<2, 0>(), GetValue<2, 1>());

            return Euler{ ExtractEulerResultType::Unique, ExtractEulerResultOrder::ZXZ, xAngle, Math::GetValue(0), z0Angle, Math::GetValue(0), Math::GetValue(0), z1Angle };
        }
        else
        {
            // 该解不是唯一的:  z1_angle - z0_angle = atan2(-r01,r00)

            constexpr auto xAngle = Math::GetPI();
            const auto z0Angle = -Math::ATan2(-GetValue<0, 1>(), GetValue<0, 0>());
            constexpr auto z1Angle = Math::GetValue(0);

            return Euler{ ExtractEulerResultType::Difference, ExtractEulerResultOrder::ZXZ, xAngle, Math::GetValue(0), z0Angle, Math::GetValue(0), Math::GetValue(0), z1Angle };
        }
    }
    else
    {
        // 该解不是唯一的: z1_angle + z0_angle = atan2(-r01,r00)

        constexpr auto xAngle = Math::GetValue(0);
        const auto z0Angle = Math::ATan2(-GetValue<0, 1>(), GetValue<0, 0>());
        constexpr auto z1Angle = Math::GetValue(0);

        return Euler{ ExtractEulerResultType::Sum, ExtractEulerResultOrder::ZXZ, xAngle, Math::GetValue(0), z0Angle, Math::GetValue(0), Math::GetValue(0), z1Angle };
    }
}

template <typename Real>
typename Mathematics::Matrix3<Real>::Euler Mathematics::Matrix3<Real>::ExtractEulerZYZ() const noexcept
{
    // +-           -+   +-                                                -+
    // | r00 r01 r02 |   |  cy*cz0*cz1-sz0*sz1  -cz1*sz0-cy*cz0*sz1  sy*cz0 |
    // | r10 r11 r12 | = |  cy*cz1*sz0+cz0*sz1   cz0*cz1-cy*sz0*sz1  sy*sz0 |
    // | r20 r21 r22 |   | -sy*cz1               sy*sz1              cy     |
    // +-           -+   +-                                                -+

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (GetValue<2, 2>() < Math::GetValue(1) - Math::GetZeroTolerance())
    {
        if (Math::GetValue(-1) + Math::GetZeroTolerance() < GetValue<2, 2>())
        {
            // y_angle  = acos(r22)
            // z0_angle = atan2(r12,r02)
            // z1_angle = atan2(r21,-r20)

            const auto yAngle = Math::ACos(GetValue<2, 2>());
            const auto z0Angle = Math::ATan2(GetValue<1, 2>(), GetValue<0, 2>());
            const auto z1Angle = Math::ATan2(GetValue<2, 1>(), -GetValue<2, 0>());

            return Euler{ ExtractEulerResultType::Unique, ExtractEulerResultOrder::ZYZ, Math::GetValue(0), yAngle, z0Angle, Math::GetValue(0), Math::GetValue(0), z1Angle };
        }
        else  // r22 = -1
        {
            // 该解不是唯一的:  z1_angle - z0_angle = atan2(r10,r11)

            constexpr auto yAngle = Math::GetPI();
            const auto z0Angle = -Math::ATan2(GetValue<1, 0>(), GetValue<1, 1>());
            constexpr auto z1Angle = Math::GetValue(0);

            return Euler{ ExtractEulerResultType::Difference, ExtractEulerResultOrder::ZYZ, Math::GetValue(0), yAngle, z0Angle, Math::GetValue(0), Math::GetValue(0), z1Angle };
        }
    }
    else  // r22 = +1
    {
        // 该解不是唯一的: z1_angle + z0_angle = atan2(r10,r11)

        constexpr auto yAngle = Math::GetValue(0);
        const auto z0Angle = Math::ATan2(GetValue<1, 0>(), GetValue<1, 1>());
        constexpr auto z1Angle = Math::GetValue(0);

        return Euler{ ExtractEulerResultType::Sum, ExtractEulerResultOrder::ZYZ, Math::GetValue(0), yAngle, z0Angle, Math::GetValue(0), Math::GetValue(0), z1Angle };
    }
}

template <typename Real>
void Mathematics::Matrix3<Real>::Slerp(Real t, const Matrix3& rot0, const Matrix3& rot1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto prod = TransposeTimes(rot0, rot1);

    const auto extract = prod.ExtractAngleAxis();

    const auto axis = extract.GetAxis();
    const auto angle = extract.GetAngle();

    MakeRotation(axis, t * angle);

    *this = rot0 * (*this);
}

template <typename T>
typename Mathematics::Matrix3<T>::ArrayType Mathematics::Matrix3<T>::GetCoordinate() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ArrayType{ m_X.GetX(),
                      m_X.GetY(),
                      m_X.GetZ(),
                      m_Y.GetX(),
                      m_Y.GetY(),
                      m_Y.GetZ(),
                      m_Z.GetX(),
                      m_Z.GetY(),
                      m_Z.GetZ() };
}

template <typename Real>
typename Mathematics::Matrix3<Real>::ContainerType Mathematics::Matrix3<Real>::GetContainer() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ContainerType{ m_X.GetX(),
                          m_X.GetY(),
                          m_X.GetZ(),
                          m_Y.GetX(),
                          m_Y.GetY(),
                          m_Y.GetZ(),
                          m_Z.GetX(),
                          m_Z.GetY(),
                          m_Z.GetZ() };
}

template <typename T>
void Mathematics::Matrix3<T>::Set(const ArrayType& coordinate)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto index = 0;
    for (auto value : coordinate)
    {
        (*this)(index / vectorSize, index % Vector3::pointSize) = value;

        ++index;
    }
}

template <typename Real>
Mathematics::Matrix4<Real> Mathematics::Matrix3<Real>::Lift() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Matrix4 result{ MatrixInitType::Identity };

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
Mathematics::Matrix2<Real> Mathematics::Matrix3<Real>::Project() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Matrix2 result{ MatrixInitType::Zero };

    for (auto r = 0; r < Matrix2::vectorSize; ++r)
    {
        for (auto c = 0; c < Matrix2::vectorSize; ++c)
        {
            result(r, c) = (*this)(r, c);
        }
    }

    return result;
}

template <typename Real>
Real Mathematics::Matrix3<Real>::Trace() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetValue<0, 0>() + GetValue<1, 1>() + GetValue<2, 2>();
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX3_ACHIEVE_H
