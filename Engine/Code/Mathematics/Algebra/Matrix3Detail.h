// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.2.5 (2020/03/19 13:10)

#ifndef MATHEMATICS_ALGEBRA_MATRIX3_DETAIL_H
#define MATHEMATICS_ALGEBRA_MATRIX3_DETAIL_H

#include "AVector.h"
#include "AlgebraTraits.h"
#include "EulerDetail.h"
#include "Matrix3.h"
#include "Matrix3ExtractDetail.h"
#include "TridiagonalizeDetail.h"
#include "Vector3D.h"
#include "Vector3DTools.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Noexcept.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

template <typename Real>
const Mathematics::Matrix3<Real> Mathematics::Matrix3<Real>::sm_Zero{ MatrixInitType::Zero };

template <typename Real>
const Mathematics::Matrix3<Real> Mathematics::Matrix3<Real>::sm_Identity{ MatrixInitType::Identity };

template <typename Real>
Mathematics::Matrix3<Real>::Matrix3(MatrixInitType flag)
    : m_Entry{}
{
    if (flag == MatrixInitType::Identity)
    {
        MakeIdentity();
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix3<Real>::Matrix3(Real member00, Real member01, Real member02,
                                    Real member10, Real member11, Real member12,
                                    Real member20, Real member21, Real member22) noexcept
    : m_Entry{ member00, member01, member02, member10, member11, member12, member20, member21, member22 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix3<Real>::Matrix3(const std::vector<Real>& entry, MatrixMajorFlags majorFlag)
    : m_Entry{}
{
    MATHEMATICS_ASSERTION_0(entry.size() == 9, "数据大小错误！");

    if (majorFlag == MatrixMajorFlags::Row)
    {
        m_Entry(0, 0) = entry[0];
        m_Entry(0, 1) = entry[1];
        m_Entry(0, 2) = entry[2];
        m_Entry(1, 0) = entry[3];
        m_Entry(1, 1) = entry[4];
        m_Entry(1, 2) = entry[5];
        m_Entry(2, 0) = entry[6];
        m_Entry(2, 1) = entry[7];
        m_Entry(2, 2) = entry[8];
    }
    else
    {
        m_Entry(0, 0) = entry[0];
        m_Entry(0, 1) = entry[3];
        m_Entry(0, 2) = entry[6];
        m_Entry(1, 0) = entry[1];
        m_Entry(1, 1) = entry[4];
        m_Entry(1, 2) = entry[7];
        m_Entry(2, 0) = entry[2];
        m_Entry(2, 1) = entry[5];
        m_Entry(2, 2) = entry[8];
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix3<Real>::Matrix3(const Vector3D& firstVector, const Vector3D& secondVector, const Vector3D& thirdVector, MatrixMajorFlags majorFlag)
    : m_Entry()
{
    if (majorFlag == MatrixMajorFlags::Row)
    {
        m_Entry(0, 0) = firstVector[0];
        m_Entry(0, 1) = firstVector[1];
        m_Entry(0, 2) = firstVector[2];
        m_Entry(1, 0) = secondVector[0];
        m_Entry(1, 1) = secondVector[1];
        m_Entry(1, 2) = secondVector[2];
        m_Entry(2, 0) = thirdVector[0];
        m_Entry(2, 1) = thirdVector[1];
        m_Entry(2, 2) = thirdVector[2];
    }
    else
    {
        m_Entry(0, 0) = firstVector[0];
        m_Entry(0, 1) = secondVector[0];
        m_Entry(0, 2) = thirdVector[0];
        m_Entry(1, 0) = firstVector[1];
        m_Entry(1, 1) = secondVector[1];
        m_Entry(1, 2) = thirdVector[1];
        m_Entry(2, 0) = firstVector[2];
        m_Entry(2, 1) = secondVector[2];
        m_Entry(2, 2) = thirdVector[2];
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix3<Real>::Matrix3(const std::vector<Vector3D>& vectors, MatrixMajorFlags majorFlag)
    : m_Entry{}
{
    MATHEMATICS_ASSERTION_0(vectors.size() == 3, "数据大小错误！");

    if (majorFlag == MatrixMajorFlags::Row)
    {
        m_Entry(0, 0) = vectors[0][0];
        m_Entry(0, 1) = vectors[0][1];
        m_Entry(0, 2) = vectors[0][2];
        m_Entry(1, 0) = vectors[1][0];
        m_Entry(1, 1) = vectors[1][1];
        m_Entry(1, 2) = vectors[1][2];
        m_Entry(2, 0) = vectors[2][0];
        m_Entry(2, 1) = vectors[2][1];
        m_Entry(2, 2) = vectors[2][2];
    }
    else
    {
        m_Entry(0, 0) = vectors[0][0];
        m_Entry(0, 1) = vectors[1][0];
        m_Entry(0, 2) = vectors[2][0];
        m_Entry(1, 0) = vectors[0][1];
        m_Entry(1, 1) = vectors[1][1];
        m_Entry(1, 2) = vectors[2][1];
        m_Entry(2, 0) = vectors[0][2];
        m_Entry(2, 1) = vectors[1][2];
        m_Entry(2, 2) = vectors[2][2];
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix3<Real>::Matrix3(Real member00, Real member11, Real member22)
    : m_Entry{ member00, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0), member11, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0), member22 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix3<Real>::Matrix3(const Vector3D& axis, Real angle)
    : m_Entry{}
{
    MakeRotation(axis, angle);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix3<Real>::Matrix3(MatrixRotationAxis axis, Real angle)
    : m_Entry{}
{
    MakeRotation(axis, angle);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix3<Real>::Matrix3(const Vector3D& firstVector, const Vector3D& secondVector)
    : m_Entry{}
{
    MakeTensorProduct(firstVector, secondVector);

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
void Mathematics::Matrix3<Real>::MakeZero()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Entry(0, 0) = Math::GetValue(0);
    m_Entry(0, 1) = Math::GetValue(0);
    m_Entry(0, 2) = Math::GetValue(0);
    m_Entry(1, 0) = Math::GetValue(0);
    m_Entry(1, 1) = Math::GetValue(0);
    m_Entry(1, 2) = Math::GetValue(0);
    m_Entry(2, 0) = Math::GetValue(0);
    m_Entry(2, 1) = Math::GetValue(0);
    m_Entry(2, 2) = Math::GetValue(0);
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeIdentity()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Entry(0, 0) = Math::GetValue(1);
    m_Entry(0, 1) = Math::GetValue(0);
    m_Entry(0, 2) = Math::GetValue(0);
    m_Entry(1, 0) = Math::GetValue(0);
    m_Entry(1, 1) = Math::GetValue(1);
    m_Entry(1, 2) = Math::GetValue(0);
    m_Entry(2, 0) = Math::GetValue(0);
    m_Entry(2, 1) = Math::GetValue(0);
    m_Entry(2, 2) = Math::GetValue(1);
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeDiagonal(Real member00, Real member11, Real member22)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Entry(0, 0) = member00;
    m_Entry(0, 1) = Math::GetValue(0);
    m_Entry(0, 2) = Math::GetValue(0);
    m_Entry(1, 0) = Math::GetValue(0);
    m_Entry(1, 1) = member11;
    m_Entry(1, 2) = Math::GetValue(0);
    m_Entry(2, 0) = Math::GetValue(0);
    m_Entry(2, 1) = Math::GetValue(0);
    m_Entry(2, 2) = member22;
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeRotation(const Vector3D& axis, Real angle)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto cosValue = Math::Cos(angle);
    auto sinValue = Math::Sin(angle);
    auto oneMinusCos = Math::GetValue(1) - cosValue;

    auto xAxisSquare = axis[0] * axis[0];
    auto yAxisSquare = axis[1] * axis[1];
    auto zAxisSquare = axis[2] * axis[2];

    auto xAxisSquareMultipliedOneMinusCos = xAxisSquare * oneMinusCos;
    auto yAxisSquareMultipliedOneMinusCos = yAxisSquare * oneMinusCos;
    auto zAxisSquareMultipliedOneMinusCos = zAxisSquare * oneMinusCos;

    auto xym = axis[0] * axis[1] * oneMinusCos;
    auto xzm = axis[0] * axis[2] * oneMinusCos;
    auto yzm = axis[1] * axis[2] * oneMinusCos;

    auto xSin = axis[0] * sinValue;
    auto ySin = axis[1] * sinValue;
    auto zSin = axis[2] * sinValue;

    m_Entry(0, 0) = xAxisSquareMultipliedOneMinusCos + cosValue;
    m_Entry(0, 1) = xym - zSin;
    m_Entry(0, 2) = xzm + ySin;
    m_Entry(1, 0) = xym + zSin;
    m_Entry(1, 1) = yAxisSquareMultipliedOneMinusCos + cosValue;
    m_Entry(1, 2) = yzm - xSin;
    m_Entry(2, 0) = xzm - ySin;
    m_Entry(2, 1) = yzm + xSin;
    m_Entry(2, 2) = zAxisSquareMultipliedOneMinusCos + cosValue;
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeRotation(MatrixRotationAxis axis, Real angle)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    auto cosValue = Math::Cos(angle);
    auto sinValue = Math::Sin(angle);

    switch (axis)
    {
    case MatrixRotationAxis::X:
    {
        m_Entry(0, 0) = Math::GetValue(1);
        m_Entry(0, 1) = Math::GetValue(0);
        m_Entry(0, 2) = Math::GetValue(0);
        m_Entry(1, 0) = Math::GetValue(0);
        m_Entry(1, 1) = cosValue;
        m_Entry(1, 2) = -sinValue;
        m_Entry(2, 0) = Math::GetValue(0);
        m_Entry(2, 1) = sinValue;
        m_Entry(2, 2) = cosValue;

        break;
    }

    case MatrixRotationAxis::Y:
    {
        m_Entry(0, 0) = cosValue;
        m_Entry(0, 1) = Math::GetValue(0);
        m_Entry(0, 2) = sinValue;
        m_Entry(1, 0) = Math::GetValue(0);
        m_Entry(1, 1) = Math::GetValue(1);
        m_Entry(1, 2) = Math::GetValue(0);
        m_Entry(2, 0) = -sinValue;
        m_Entry(2, 1) = Math::GetValue(0);
        m_Entry(2, 2) = cosValue;

        break;
    }

    case MatrixRotationAxis::Z:
    {
        m_Entry(0, 0) = cosValue;
        m_Entry(0, 1) = -sinValue;
        m_Entry(0, 2) = Math::GetValue(0);
        m_Entry(1, 0) = sinValue;
        m_Entry(1, 1) = cosValue;
        m_Entry(1, 2) = Math::GetValue(0);
        m_Entry(2, 0) = Math::GetValue(0);
        m_Entry(2, 1) = Math::GetValue(0);
        m_Entry(2, 2) = Math::GetValue(1);

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
void Mathematics::Matrix3<Real>::MakeTensorProduct(const Vector3D& firstVector, const Vector3D& secondVector)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Entry(0, 0) = firstVector[0] * secondVector[0];
    m_Entry(0, 1) = firstVector[0] * secondVector[1];
    m_Entry(0, 2) = firstVector[0] * secondVector[2];
    m_Entry(1, 0) = firstVector[1] * secondVector[0];
    m_Entry(1, 1) = firstVector[1] * secondVector[1];
    m_Entry(1, 2) = firstVector[1] * secondVector[2];
    m_Entry(2, 0) = firstVector[2] * secondVector[0];
    m_Entry(2, 1) = firstVector[2] * secondVector[1];
    m_Entry(2, 2) = firstVector[2] * secondVector[2];
}

template <typename Real>
const Real* Mathematics::Matrix3<Real>::operator[](int row) const
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_0(0 <= row && row < 3, "索引错误！");

    return m_Entry[row];
}

template <typename Real>
Real* Mathematics::Matrix3<Real>::operator[](int row)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_0(0 <= row && row < 3, "索引错误！");

    return m_Entry[row];
}

template <typename Real>
const Real& Mathematics::Matrix3<Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_0(0 <= row && row < 3, "索引错误！");
    MATHEMATICS_ASSERTION_0(0 <= column && column < 3, "索引错误！");

    return m_Entry(row, column);
}

template <typename Real>
Real& Mathematics::Matrix3<Real>::operator()(int row, int column)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_0(0 <= row && row < 3, "索引错误！");
    MATHEMATICS_ASSERTION_0(0 <= column && column < 3, "索引错误！");

    return m_Entry(row, column);
}

template <typename Real>
const Mathematics::Matrix3<Real> Mathematics::Matrix3<Real>::operator-() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix3<Real>{ -m_Entry(0, 0), -m_Entry(0, 1), -m_Entry(0, 2), -m_Entry(1, 0), -m_Entry(1, 1),
                          -m_Entry(1, 2), -m_Entry(2, 0), -m_Entry(2, 1), -m_Entry(2, 2) };
}

template <typename Real>
Mathematics::Matrix3<Real>& Mathematics::Matrix3<Real>::operator+=(const Matrix3& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Entry(0, 0) += rhs.m_Entry(0, 0);
    m_Entry(0, 1) += rhs.m_Entry(0, 1);
    m_Entry(0, 2) += rhs.m_Entry(0, 2);
    m_Entry(1, 0) += rhs.m_Entry(1, 0);
    m_Entry(1, 1) += rhs.m_Entry(1, 1);
    m_Entry(1, 2) += rhs.m_Entry(1, 2);
    m_Entry(2, 0) += rhs.m_Entry(2, 0);
    m_Entry(2, 1) += rhs.m_Entry(2, 1);
    m_Entry(2, 2) += rhs.m_Entry(2, 2);

    return *this;
}

template <typename Real>
Mathematics::Matrix3<Real>& Mathematics::Matrix3<Real>::operator-=(const Matrix3& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Entry(0, 0) -= rhs.m_Entry(0, 0);
    m_Entry(0, 1) -= rhs.m_Entry(0, 1);
    m_Entry(0, 2) -= rhs.m_Entry(0, 2);
    m_Entry(1, 0) -= rhs.m_Entry(1, 0);
    m_Entry(1, 1) -= rhs.m_Entry(1, 1);
    m_Entry(1, 2) -= rhs.m_Entry(1, 2);
    m_Entry(2, 0) -= rhs.m_Entry(2, 0);
    m_Entry(2, 1) -= rhs.m_Entry(2, 1);
    m_Entry(2, 2) -= rhs.m_Entry(2, 2);

    return *this;
}

template <typename Real>
Mathematics::Matrix3<Real>& Mathematics::Matrix3<Real>::operator*=(Real scalar)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Entry(0, 0) *= scalar;
    m_Entry(0, 1) *= scalar;
    m_Entry(0, 2) *= scalar;
    m_Entry(1, 0) *= scalar;
    m_Entry(1, 1) *= scalar;
    m_Entry(1, 2) *= scalar;
    m_Entry(2, 0) *= scalar;
    m_Entry(2, 1) *= scalar;
    m_Entry(2, 2) *= scalar;

    return *this;
}

template <typename Real>
Mathematics::Matrix3<Real>& Mathematics::Matrix3<Real>::operator/=(Real scalar)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (Math::GetZeroTolerance() < Math::FAbs(scalar))
    {
        m_Entry(0, 0) /= scalar;
        m_Entry(0, 1) /= scalar;
        m_Entry(0, 2) /= scalar;
        m_Entry(1, 0) /= scalar;
        m_Entry(1, 1) /= scalar;
        m_Entry(1, 2) /= scalar;
        m_Entry(2, 0) /= scalar;
        m_Entry(2, 1) /= scalar;
        m_Entry(2, 2) /= scalar;
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "除零错误！");

        m_Entry(0, 0) = Math::sm_MaxReal;
        m_Entry(0, 1) = Math::sm_MaxReal;
        m_Entry(0, 2) = Math::sm_MaxReal;
        m_Entry(1, 0) = Math::sm_MaxReal;
        m_Entry(1, 1) = Math::sm_MaxReal;
        m_Entry(1, 2) = Math::sm_MaxReal;
        m_Entry(2, 0) = Math::sm_MaxReal;
        m_Entry(2, 1) = Math::sm_MaxReal;
        m_Entry(2, 2) = Math::sm_MaxReal;
    }

    return *this;
}

template <typename Real>
Real Mathematics::Matrix3<Real>::QuadraticForm(const Vector3D& lhs, const Vector3D& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Vector3DTools::DotProduct(lhs, (*this) * rhs);
}

template <typename Real>
const Mathematics::Matrix3<Real> Mathematics::Matrix3<Real>::Transpose() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix3<Real>{ m_Entry(0, 0), m_Entry(1, 0), m_Entry(2, 0),
                          m_Entry(0, 1), m_Entry(1, 1), m_Entry(2, 1),
                          m_Entry(0, 2), m_Entry(1, 2), m_Entry(2, 2) };
}

template <typename Real>
Mathematics::Matrix3<Real>& Mathematics::Matrix3<Real>::operator*=(const Matrix3& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    *this = *this * rhs;

    return *this;
}

template <typename Real>
const Mathematics::Matrix3<Real> Mathematics::Matrix3<Real>::TimesDiagonal(const Vector3D& diagonal) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix3<Real>{ m_Entry(0, 0) * diagonal[0], m_Entry(0, 1) * diagonal[1], m_Entry(0, 2) * diagonal[2],
                          m_Entry(1, 0) * diagonal[0], m_Entry(1, 1) * diagonal[1], m_Entry(1, 2) * diagonal[2],
                          m_Entry(2, 0) * diagonal[0], m_Entry(2, 1) * diagonal[1], m_Entry(2, 2) * diagonal[2] };
}

template <typename Real>
const Mathematics::Matrix3<Real> Mathematics::Matrix3<Real>::DiagonalTimes(const Vector3D& diagonal) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix3<Real>{ m_Entry(0, 0) * diagonal[0], m_Entry(0, 1) * diagonal[0], m_Entry(0, 2) * diagonal[0],
                          m_Entry(1, 0) * diagonal[1], m_Entry(1, 1) * diagonal[1], m_Entry(1, 2) * diagonal[1],
                          m_Entry(2, 0) * diagonal[2], m_Entry(2, 1) * diagonal[2], m_Entry(2, 2) * diagonal[2] };
}

template <typename Real>
const Mathematics::Matrix3<Real> Mathematics::Matrix3<Real>::Inverse(const Real epsilon) const
{
    // 使用辅助因子求一个3x3矩阵的逆。
    // 这比使用高斯消元法更快，因为循环的开销相当于一个方法。
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    // 计算伴随矩阵。
    auto adjoint = Adjoint();

    auto det = m_Entry(0, 0) * adjoint.m_Entry(0, 0) + m_Entry(0, 1) * adjoint.m_Entry(1, 0) + m_Entry(0, 2) * adjoint.m_Entry(2, 0);

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

        return sm_Zero;
    }
}

template <typename Real>
const Mathematics::Matrix3<Real> Mathematics::Matrix3<Real>::Adjoint() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix3<Real>{ m_Entry(1, 1) * m_Entry(2, 2) - m_Entry(1, 2) * m_Entry(2, 1), m_Entry(0, 2) * m_Entry(2, 1) - m_Entry(0, 1) * m_Entry(2, 2),
                          m_Entry(0, 1) * m_Entry(1, 2) - m_Entry(0, 2) * m_Entry(1, 1), m_Entry(1, 2) * m_Entry(2, 0) - m_Entry(1, 0) * m_Entry(2, 2),
                          m_Entry(0, 0) * m_Entry(2, 2) - m_Entry(0, 2) * m_Entry(2, 0), m_Entry(0, 2) * m_Entry(1, 0) - m_Entry(0, 0) * m_Entry(1, 2),
                          m_Entry(1, 0) * m_Entry(2, 1) - m_Entry(1, 1) * m_Entry(2, 0), m_Entry(0, 1) * m_Entry(2, 0) - m_Entry(0, 0) * m_Entry(2, 1),
                          m_Entry(0, 0) * m_Entry(1, 1) - m_Entry(0, 1) * m_Entry(1, 0) };
}

template <typename Real>
Real Mathematics::Matrix3<Real>::Determinant() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto column00 = m_Entry(1, 1) * m_Entry(2, 2) - m_Entry(1, 2) * m_Entry(2, 1);
    auto column10 = m_Entry(1, 2) * m_Entry(2, 0) - m_Entry(1, 0) * m_Entry(2, 2);
    auto column20 = m_Entry(1, 0) * m_Entry(2, 1) - m_Entry(1, 1) * m_Entry(2, 0);

    return m_Entry(0, 0) * column00 + m_Entry(0, 1) * column10 + m_Entry(0, 2) * column20;
}

// private
template <typename Real>
Real Mathematics::Matrix3<Real>::ExtractAngle() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto trace = m_Entry(0, 0) + m_Entry(1, 1) + m_Entry(2, 2);
    auto cosValue = static_cast<Real>(0.5) * (trace - Math::GetValue(1));

    return Math::ACos(cosValue);  // angle范围在 [0,PI]
}

template <typename Real>
typename const Mathematics::Matrix3<Real>::Matrix3Extract Mathematics::Matrix3<Real>::ExtractAngleAxis() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    // 设(x,y,z)是单位长度的轴和A是一个旋转角。
    // 旋转矩阵Real = I + sin(A)*P + (1-cos(A))*P^2，其中I是单位矩阵和
    //       +-        -+
    //   P = |  0 -z +y |
    //       | +z  0 -x |
    //       | -y +x  0 |
    //       +-        -+
    //
    // 如果A > 0时，Real表示绕轴线从观看轴矢量的末端朝向原点的的感觉逆时针旋转。
    // 一些代数将证明
    //
    //   cos(A) = (trace(Real)-1)/2  和  Real - Real^t = 2*sin(A)*P
    //
    // 倘若A = pi，Real-Real^t = 0，这使我们无法通过P来提取轴
    // 取而代之的主意是，Real = I+2*P^2当A = pi，因此P^2 = (Real-I)/2。
    // P^2的对角元素为x^2-1， y^2-1和z^2-1。
    // 我们能够解出轴(x,y,z)
    // 因为角度是pi，你选择的平方根的标志的符号并不要紧。

    auto angle = ExtractAngle();  // angle范围在 [0,PI]
    Vector3D axis;

    if (Math::GetZeroTolerance() < angle)
    {
        axis = Vector3D{ m_Entry(2, 1) - m_Entry(1, 2), m_Entry(0, 2) - m_Entry(2, 0), m_Entry(1, 0) - m_Entry(0, 1) };

        if (Math::GetZeroTolerance() * Math::GetZeroTolerance() < Vector3DTools::VectorMagnitudeSquared(axis))
        {
            axis.Normalize();
        }
        else
        {
            // 角度是 PI
            if (m_Entry(1, 1) <= m_Entry(0, 0) && m_Entry(2, 2) <= m_Entry(0, 0))
            {
                // r11 <= r00

                // r00是最大对角线条款
                auto axisX = (static_cast<Real>(0.5) * Math::Sqrt(Math::GetValue(1) + m_Entry(0, 0) - m_Entry(1, 1) - m_Entry(2, 2)));

                auto halfInverse = static_cast<Real>(0.5) / axisX;

                axis = Vector3D{ axisX, halfInverse * m_Entry(0, 1), halfInverse * m_Entry(0, 2) };
            }
            else if (m_Entry(0, 0) < m_Entry(1, 1) && m_Entry(2, 2) <= m_Entry(1, 1))
            {
                // r00 < r11

                // r11是最大对角线条款
                auto axisY = (static_cast<Real>(0.5) * Math::Sqrt(Math::GetValue(1) + m_Entry(1, 1) - m_Entry(0, 0) - m_Entry(2, 2)));

                auto halfInverse = static_cast<Real>(0.5) / axisY;

                axis = Vector3D{ halfInverse * m_Entry(0, 1), axisY, halfInverse * m_Entry(1, 2) };
            }
            else
            {
                // r22是最大对角线条款
                auto axisZ = (static_cast<Real>(0.5) * Math::Sqrt(Math::GetValue(1) + m_Entry(2, 2) - m_Entry(0, 0) - m_Entry(1, 1)));

                auto halfInverse = static_cast<Real>(0.5) / axisZ;

                axis = Vector3D{ halfInverse * m_Entry(0, 2), halfInverse * m_Entry(1, 2), axisZ };
            }
        }
    }
    else
    {
        // 角度为0的矩阵是单位矩阵。
        // 所有轴都可以工作，因此只需使用x轴。
        axis = Vector3D::sm_UnitX;
    }

    return Matrix3Extract{ angle, axis };
}

template <typename Real>
typename const Mathematics::Matrix3<Real>::Vector3D Mathematics::Matrix3<Real>::ExtractAxis() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto extract = ExtractAngleAxis();

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
    //   q1 = (m1-(q0*m1)q0) / |m1-(q0*m1)q0|
    //   q2 = (m2-(q0*m2)q0-(q1*m2)q1) / |m2-(q0*m2)q0-(q1*m2)q1|
    // 其中|V|表示向量V的长度和A * B表示向量A和B的点积

    // 计算 q0.
    auto invLength = Math::InvSqrt(m_Entry(0, 0) * m_Entry(0, 0) + m_Entry(1, 0) * m_Entry(1, 0) + m_Entry(2, 0) * m_Entry(2, 0));

    m_Entry(0, 0) *= invLength;
    m_Entry(1, 0) *= invLength;
    m_Entry(2, 0) *= invLength;

    // 计算 q1.
    auto dot0 = m_Entry(0, 0) * m_Entry(0, 1) + m_Entry(1, 0) * m_Entry(1, 1) + m_Entry(2, 0) * m_Entry(2, 1);

    m_Entry(0, 1) -= dot0 * m_Entry(0, 0);
    m_Entry(1, 1) -= dot0 * m_Entry(1, 0);
    m_Entry(2, 1) -= dot0 * m_Entry(2, 0);

    invLength = Math::InvSqrt(m_Entry(0, 1) * m_Entry(0, 1) + m_Entry(1, 1) * m_Entry(1, 1) + m_Entry(2, 1) * m_Entry(2, 1));

    m_Entry(0, 1) *= invLength;
    m_Entry(1, 1) *= invLength;
    m_Entry(2, 1) *= invLength;

    // 计算 q2
    auto dot1 = m_Entry(0, 1) * m_Entry(0, 2) + m_Entry(1, 1) * m_Entry(1, 2) + m_Entry(2, 1) * m_Entry(2, 2);

    auto dot2 = m_Entry(0, 0) * m_Entry(0, 2) + m_Entry(1, 0) * m_Entry(1, 2) + m_Entry(2, 0) * m_Entry(2, 2);

    m_Entry(0, 2) -= dot2 * m_Entry(0, 0) + dot1 * m_Entry(0, 1);
    m_Entry(1, 2) -= dot2 * m_Entry(1, 0) + dot1 * m_Entry(1, 1);
    m_Entry(2, 2) -= dot2 * m_Entry(2, 0) + dot1 * m_Entry(2, 1);

    invLength = Math::InvSqrt(m_Entry(0, 2) * m_Entry(0, 2) + m_Entry(1, 2) * m_Entry(1, 2) + m_Entry(2, 2) * m_Entry(2, 2));

    m_Entry(0, 2) *= invLength;
    m_Entry(1, 2) *= invLength;
    m_Entry(2, 2) *= invLength;
}

template <typename Real>
typename const Mathematics::Matrix3<Real>::Matrix3EigenDecomposition Mathematics::Matrix3<Real>::EigenDecomposition(const Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    MATHEMATICS_ASSERTION_1(Math::FAbs(m_Entry(0, 1) - m_Entry(1, 0)) <= epsilon &&
                                Math::FAbs(m_Entry(0, 2) - m_Entry(2, 0)) <= epsilon &&
                                Math::FAbs(m_Entry(1, 2) - m_Entry(2, 1)) <= epsilon,
                            "矩阵必须是对称矩阵。");

    // 系数 M = Real*D*Real^T。
    // Real的列是特征向量。D的对角元素为相应的特征值。
    Tridiagonalize<Real> tridiagonalize{ *this };

    auto reflection = tridiagonalize.IsReflection();
    auto rotation = tridiagonalize.GetRotation();
    auto diagonal = tridiagonalize.GetDiagonal();

    // 特征值按递增顺序排序，d0 <= d1 <= d2。这是一个插入排序。
    if (diagonal[1] < diagonal[0])
    {
        // 交换 d0 和 d1.
        std::swap(diagonal[0], diagonal[1]);

        // 交换 V0 和 V1.
        for (auto i = 0; i < 3; ++i)
        {
            std::swap(rotation.m_Entry(i, 0), rotation.m_Entry(i, 1));
        }
        reflection = !reflection;
    }

    if (diagonal[2] < diagonal[1])
    {
        // 交换 d1 和 d2.
        std::swap(diagonal[1], diagonal[2]);

        // 交换 V1 和 V2.
        for (auto i = 0; i < 3; ++i)
        {
            std::swap(rotation.m_Entry(i, 1), rotation.m_Entry(i, 2));
        }
        reflection = !reflection;
    }

    if (diagonal[1] < diagonal[0])
    {
        // 交换 d0 和 d1.
        std::swap(diagonal[0], diagonal[1]);

        // 交换 V0 和 V1.
        for (auto i = 0; i < 3; ++i)
        {
            std::swap(rotation.m_Entry(i, 0), rotation.m_Entry(i, 1));
        }
        reflection = !reflection;
    }

    Matrix3 diagonalMatrix{ diagonal[0], diagonal[1], diagonal[2] };

    if (reflection)
    {
        // 这对角矩阵M正交变换是一种反射。
        // 通过改变最后一列的符号使特征向量符合右手系统。
        rotation.m_Entry(0, 2) = -rotation.m_Entry(0, 2);
        rotation.m_Entry(1, 2) = -rotation.m_Entry(1, 2);
        rotation.m_Entry(2, 2) = -rotation.m_Entry(2, 2);
    }

    return Matrix3EigenDecomposition{ rotation, diagonalMatrix, epsilon };
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeEuler(const Euler& euler)
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
void Mathematics::Matrix3<Real>::MakeEulerXYZ(Real xAngle, Real yAngle, Real zAngle)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    Matrix3 xMat{ MatrixRotationAxis::X, xAngle };
    Matrix3 yMat{ MatrixRotationAxis::Y, yAngle };
    Matrix3 zMat{ MatrixRotationAxis::Z, zAngle };

    *this = xMat * (yMat * zMat);
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeEulerXZY(Real xAngle, Real zAngle, Real yAngle)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    Matrix3 xMat{ MatrixRotationAxis::X, xAngle };
    Matrix3 zMat{ MatrixRotationAxis::Z, zAngle };
    Matrix3 yMat{ MatrixRotationAxis::Y, yAngle };

    *this = xMat * (zMat * yMat);
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeEulerYXZ(Real yAngle, Real xAngle, Real zAngle)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    Matrix3 yMat{ MatrixRotationAxis::Y, yAngle };
    Matrix3 xMat{ MatrixRotationAxis::X, xAngle };
    Matrix3 zMat{ MatrixRotationAxis::Z, zAngle };

    *this = yMat * (xMat * zMat);
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeEulerYZX(Real yAngle, Real zAngle, Real xAngle)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    Matrix3 yMat{ MatrixRotationAxis::Y, yAngle };
    Matrix3 zMat{ MatrixRotationAxis::Z, zAngle };
    Matrix3 xMat{ MatrixRotationAxis::X, xAngle };

    *this = yMat * (zMat * xMat);
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeEulerZXY(Real zAngle, Real xAngle, Real yAngle)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    Matrix3 zMat{ MatrixRotationAxis::Z, zAngle };
    Matrix3 xMat{ MatrixRotationAxis::X, xAngle };
    Matrix3 yMat{ MatrixRotationAxis::Y, yAngle };

    *this = zMat * (xMat * yMat);
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeEulerZYX(Real zAngle, Real yAngle, Real xAngle)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const Matrix3 zMat{ MatrixRotationAxis::Z, zAngle };
    const Matrix3 yMat{ MatrixRotationAxis::Y, yAngle };
    const Matrix3 xMat{ MatrixRotationAxis::X, xAngle };

    *this = zMat * (yMat * xMat);
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeEulerXYX(Real x0Angle, Real yAngle, Real x1Angle)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    Matrix3 x0Mat{ MatrixRotationAxis::X, x0Angle };
    Matrix3 yMat{ MatrixRotationAxis::Y, yAngle };
    Matrix3 x1Mat{ MatrixRotationAxis::X, x1Angle };

    *this = x0Mat * (yMat * x1Mat);
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeEulerXZX(Real x0Angle, Real zAngle, Real x1Angle)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    Matrix3 x0Mat{ MatrixRotationAxis::X, x0Angle };
    Matrix3 zMat{ MatrixRotationAxis::Z, zAngle };
    Matrix3 x1Mat{ MatrixRotationAxis::X, x1Angle };

    *this = x0Mat * (zMat * x1Mat);
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeEulerYXY(Real y0Angle, Real xAngle, Real y1Angle)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    Matrix3 y0Mat{ MatrixRotationAxis::Y, y0Angle };
    Matrix3 xMat{ MatrixRotationAxis::X, xAngle };
    Matrix3 y1Mat{ MatrixRotationAxis::Y, y1Angle };

    *this = y0Mat * (xMat * y1Mat);
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeEulerYZY(Real y0Angle, Real zAngle, Real y1Angle)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    Matrix3 y0Mat{ MatrixRotationAxis::Y, y0Angle };
    Matrix3 zMat{ MatrixRotationAxis::Z, zAngle };
    Matrix3 y1Mat{ MatrixRotationAxis::Y, y1Angle };

    *this = y0Mat * (zMat * y1Mat);
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeEulerZXZ(Real z0Angle, Real xAngle, Real z1Angle)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    Matrix3 z0Mat{ MatrixRotationAxis::Z, z0Angle };
    Matrix3 xMat{ MatrixRotationAxis::X, xAngle };
    Matrix3 z1Mat{ MatrixRotationAxis::Z, z1Angle };

    *this = z0Mat * (xMat * z1Mat);
}

template <typename Real>
void Mathematics::Matrix3<Real>::MakeEulerZYZ(Real z0Angle, Real yAngle, Real z1Angle)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    Matrix3 z0Mat{ MatrixRotationAxis::Z, z0Angle };
    Matrix3 yMat{ MatrixRotationAxis::Y, yAngle };
    Matrix3 z1Mat{ MatrixRotationAxis::Z, z1Angle };

    *this = z0Mat * (yMat * z1Mat);
}

template <typename Real>
typename const Mathematics::Matrix3<Real>::Euler Mathematics::Matrix3<Real>::ExtractEulerXYZ() const
{
    // +-           -+   +-                                        -+
    // | r00 r01 r02 |   |  cy*cz           -cy*sz            sy    |
    // | r10 r11 r12 | = |  cz*sx*sy+cx*sz   cx*cz-sx*sy*sz  -cy*sx |
    // | r20 r21 r22 |   | -cx*cz*sy+sx*sz   cz*sx+cx*sy*sz   cx*cy |
    // +-           -+   +-                                        -+
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (m_Entry(0, 2) < Math::GetValue(1) - Math::GetZeroTolerance())
    {
        if (-Math::GetValue(1) + Math::GetZeroTolerance() < m_Entry(0, 2))
        {
            // y_angle = asin(r02)
            // x_angle = atan2(-r12,r22)
            // z_angle = atan2(-r01,r00)
            auto yAngle = Math::ASin(m_Entry(0, 2));
            auto xAngle = Math::ATan2(-m_Entry(1, 2), m_Entry(2, 2));
            auto zAngle = Math::ATan2(-m_Entry(0, 1), m_Entry(0, 0));

            return Euler{ ExtractEulerResultType::Unique, ExtractEulerResultOrder::XYZ, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }
        else
        {
            // y_angle = -pi/2
            // z_angle - x_angle = atan2(r10,r11)
            // 警告。该解不是唯一的。选择z_angle = 0.
            auto yAngle = -Math::GetHalfPI();
            auto xAngle = -Math::ATan2(m_Entry(1, 0), m_Entry(1, 1));
            auto zAngle = Math::GetValue(0);

            return Euler{ ExtractEulerResultType::Difference, ExtractEulerResultOrder::XYZ, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }
    }
    else
    {
        // y_angle = +pi/2
        // z_angle + x_angle = atan2(r10,r11)
        // 警告。该解不是唯一的。选择z_angle = 0.
        auto yAngle = Math::GetHalfPI();
        auto xAngle = Math::ATan2(m_Entry(1, 0), m_Entry(1, 1));
        auto zAngle = Math::GetValue(0);

        return Euler{ ExtractEulerResultType::Sum, ExtractEulerResultOrder::XYZ, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
    }
}

template <typename Real>
typename const Mathematics::Matrix3<Real>::Euler Mathematics::Matrix3<Real>::ExtractEulerXZY() const
{
    // +-           -+   +-                                        -+
    // | r00 r01 r02 |   |  cy*cz           -sz      cz*sy          |
    // | r10 r11 r12 | = |  sx*sy+cx*cy*sz   cx*cz  -cy*sx+cx*sy*sz |
    // | r20 r21 r22 |   | -cx*sy+cy*sx*sz   cz*sx   cx*cy+sx*sy*sz |
    // +-           -+   +-                                        -+
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (m_Entry(0, 1) < Math::GetValue(1) - Math::GetZeroTolerance())
    {
        if (-Math::GetValue(1) + Math::GetZeroTolerance() < m_Entry(0, 1))
        {
            // z_angle = asin(-r01)
            // x_angle = atan2(r21,r11)
            // y_angle = atan2(r02,r00)
            auto zAngle = Math::ASin(-m_Entry(0, 1));
            auto xAngle = Math::ATan2(m_Entry(2, 1), m_Entry(1, 1));
            auto yAngle = Math::ATan2(m_Entry(0, 2), m_Entry(0, 0));

            return Euler{ ExtractEulerResultType::Unique, ExtractEulerResultOrder::XZY, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }
        else
        {
            // z_angle = +pi/2
            // y_angle - x_angle = atan2(-r20,r22)
            // 警告。该解不是唯一的。选择y_angle = 0.
            auto zAngle = Math::GetHalfPI();
            auto xAngle = -Math::ATan2(-m_Entry(2, 0), m_Entry(2, 2));
            auto yAngle = Math::GetValue(0);

            return Euler{ ExtractEulerResultType::Difference, ExtractEulerResultOrder::XZY, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }
    }
    else
    {
        // z_angle = -pi/2
        // y_angle + x_angle = atan2(-r20,r22)
        // 警告。该解不是唯一的。选择y_angle = 0.
        auto zAngle = -Math::GetHalfPI();
        auto xAngle = Math::ATan2(-m_Entry(2, 0), m_Entry(2, 2));
        auto yAngle = Math::GetValue(0);

        return Euler{ ExtractEulerResultType::Sum, ExtractEulerResultOrder::XZY, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
    }
}

template <typename Real>
typename const Mathematics::Matrix3<Real>::Euler Mathematics::Matrix3<Real>::ExtractEulerYXZ() const
{
    // +-           -+   +-                                       -+
    // | r00 r01 r02 |   |  cy*cz+sx*sy*sz  cz*sx*sy-cy*sz   cx*sy |
    // | r10 r11 r12 | = |  cx*sz           cx*cz           -sx    |
    // | r20 r21 r22 |   | -cz*sy+cy*sx*sz  cy*cz*sx+sy*sz   cx*cy |
    // +-           -+   +-                                       -+

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (m_Entry(1, 2) < Math::GetValue(1) - Math::GetZeroTolerance())
    {
        if (-Math::GetValue(1) + Math::GetZeroTolerance() < m_Entry(1, 2))
        {
            // x_angle = asin(-r12)
            // y_angle = atan2(r02,r22)
            // z_angle = atan2(r10,r11)
            auto xAngle = Math::ASin(-m_Entry(1, 2));
            auto yAngle = Math::ATan2(m_Entry(0, 2), m_Entry(2, 2));
            auto zAngle = Math::ATan2(m_Entry(1, 0), m_Entry(1, 1));

            return Euler{ ExtractEulerResultType::Unique, ExtractEulerResultOrder::YXZ, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }
        else
        {
            // x_angle = +pi/2
            // z_angle - y_angle = atan2(-r01,r00)
            // 警告。该解不是唯一的。选择 z_angle = 0.
            auto xAngle = Math::GetHalfPI();
            auto yAngle = -Math::ATan2(-m_Entry(0, 1), m_Entry(0, 0));
            auto zAngle = Math::GetValue(0);

            return Euler{ ExtractEulerResultType::Difference, ExtractEulerResultOrder::YXZ, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }
    }
    else
    {
        // x_angle = -pi/2
        // z_angle + y_angle = atan2(-r01,r00)
        // 警告。该解不是唯一的。选择z_angle = 0.
        auto xAngle = -Math::GetHalfPI();
        auto yAngle = Math::ATan2(-m_Entry(0, 1), m_Entry(0, 0));
        auto zAngle = Math::GetValue(0);

        return Euler{ ExtractEulerResultType::Sum, ExtractEulerResultOrder::YXZ, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
    }
}

template <typename Real>
typename const Mathematics::Matrix3<Real>::Euler Mathematics::Matrix3<Real>::ExtractEulerYZX() const
{
    // +-           -+   +-                                       -+
    // | r00 r01 r02 |   |  cy*cz  sx*sy-cx*cy*sz   cx*sy+cy*sx*sz |
    // | r10 r11 r12 | = |  sz     cx*cz           -cz*sx          |
    // | r20 r21 r22 |   | -cz*sy  cy*sx+cx*sy*sz   cx*cy-sx*sy*sz |
    // +-           -+   +-                                       -+

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (m_Entry(1, 0) < Math::GetValue(1) - Math::GetZeroTolerance())
    {
        if (-Math::GetValue(1) + Math::GetZeroTolerance() < m_Entry(1, 0))
        {
            // z_angle = asin(r10)
            // y_angle = atan2(-r20,r00)
            // x_angle = atan2(-r12,r11)
            auto zAngle = Math::ASin(m_Entry(1, 0));
            auto yAngle = Math::ATan2(-m_Entry(2, 0), m_Entry(0, 0));
            auto xAngle = Math::ATan2(-m_Entry(1, 2), m_Entry(1, 1));

            return Euler{ ExtractEulerResultType::Unique, ExtractEulerResultOrder::YZX, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }
        else
        {
            // z_angle = -pi/2
            // x_angle - y_angle = atan2(r21,r22)
            // 警告。该解不是唯一的。选择 x_angle = 0.

            auto zAngle = -Math::GetHalfPI();
            auto yAngle = -Math::ATan2(m_Entry(2, 1), m_Entry(2, 2));
            auto xAngle = Math::GetValue(0);

            return Euler{ ExtractEulerResultType::Difference, ExtractEulerResultOrder::YZX, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }
    }
    else
    {
        // z_angle = +pi/2
        // x_angle + y_angle = atan2(r21,r22)
        // 警告。该解不是唯一的。选择 x_angle = 0.

        auto zAngle = Math::GetHalfPI();
        auto yAngle = Math::ATan2(m_Entry(2, 1), m_Entry(2, 2));
        auto xAngle = Math::GetValue(0);

        return Euler{ ExtractEulerResultType::Sum, ExtractEulerResultOrder::YZX, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
    }
}

template <typename Real>
typename const Mathematics::Matrix3<Real>::Euler Mathematics::Matrix3<Real>::ExtractEulerZXY() const
{
    // +-           -+   +-                                        -+
    // | r00 r01 r02 |   |  cy*cz-sx*sy*sz  -cx*sz   cz*sy+cy*sx*sz |
    // | r10 r11 r12 | = |  cz*sx*sy+cy*sz   cx*cz  -cy*cz*sx+sy*sz |
    // | r20 r21 r22 |   | -cx*sy            sx      cx*cy          |
    // +-           -+   +-                                        -+

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (m_Entry(2, 1) < Math::GetValue(1) - Math::GetZeroTolerance())
    {
        if (-Math::GetValue(1) + Math::GetZeroTolerance() < m_Entry(2, 1))
        {
            // x_angle = asin(r21)
            // z_angle = atan2(-r01,r11)
            // y_angle = atan2(-r20,r22)

            auto xAngle = Math::ASin(m_Entry(2, 1));
            auto zAngle = Math::ATan2(-m_Entry(0, 1), m_Entry(1, 1));
            auto yAngle = Math::ATan2(-m_Entry(2, 0), m_Entry(2, 2));

            return Euler{ ExtractEulerResultType::Unique, ExtractEulerResultOrder::ZXY, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }
        else
        {
            // x_angle = -pi/2
            // y_angle - z_angle = atan2(r02,r00)
            // 警告。该解不是唯一的。选择 y_angle = 0.

            auto xAngle = -Math::GetHalfPI();
            auto zAngle = -Math::ATan2(m_Entry(0, 2), m_Entry(0, 0));
            auto yAngle = Math::GetValue(0);

            return Euler{ ExtractEulerResultType::Difference, ExtractEulerResultOrder::ZXY, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }
    }
    else
    {
        // x_angle = +pi/2
        // y_angle + z_angle = atan2(r02,r00)
        // 警告。该解不是唯一的。选择 y_angle = 0.

        auto xAngle = Math::GetHalfPI();
        auto zAngle = Math::ATan2(m_Entry(0, 2), m_Entry(0, 0));
        auto yAngle = Math::GetValue(0);

        return Euler{ ExtractEulerResultType::Sum, ExtractEulerResultOrder::ZXY, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
    }
}

template <typename Real>
typename const Mathematics::Matrix3<Real>::Euler Mathematics::Matrix3<Real>::ExtractEulerZYX() const  
{
    // +-           -+   +-                                      -+
    // | r00 r01 r02 |   |  cy*cz  cz*sx*sy-cx*sz  cx*cz*sy+sx*sz |
    // | r10 r11 r12 | = |  cy*sz  cx*cz+sx*sy*sz -cz*sx+cx*sy*sz |
    // | r20 r21 r22 |   | -sy     cy*sx           cx*cy          |
    // +-           -+   +-                                      -+

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (m_Entry(2, 0) < Math::GetValue(1) - Math::GetZeroTolerance())
    {
        if (-Math::GetValue(1) + Math::GetZeroTolerance() < m_Entry(2, 0))
        {
            // y_angle = asin(-r20)
            // z_angle = atan2(r10,r00)
            // x_angle = atan2(r21,r22)

            auto yAngle = Math::ASin(-m_Entry(2, 0));
            auto zAngle = Math::ATan2(m_Entry(1, 0), m_Entry(0, 0));
            auto xAngle = Math::ATan2(m_Entry(2, 1), m_Entry(2, 2));

            return Euler{ ExtractEulerResultType::Unique, ExtractEulerResultOrder::ZYX, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }
        else
        {
            // y_angle = +pi/2
            // x_angle - z_angle = atan2(r01,r02)
            // 警告。该解不是唯一的。选择 x_angle = 0.

            auto yAngle = Math::GetHalfPI();
            auto zAngle = -Math::ATan2(m_Entry(0, 1), m_Entry(0, 2));
            auto xAngle = Math::GetValue(0);

            return Euler{ ExtractEulerResultType::Difference, ExtractEulerResultOrder::ZYX, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }
    }
    else
    {
        // y_angle = -pi/2
        // x_angle + z_angle = atan2(-r01,-r02)
        // 警告。该解不是唯一的。选择 x_angle = 0;

        auto yAngle = -Math::GetHalfPI();
        auto zAngle = Math::ATan2(-m_Entry(0, 1), -m_Entry(0, 2));
        auto xAngle = Math::GetValue(0);

        return Euler{ ExtractEulerResultType::Sum, ExtractEulerResultOrder::ZYX, xAngle, yAngle, zAngle, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
    }
}

template <typename Real>
typename const Mathematics::Matrix3<Real>::Euler Mathematics::Matrix3<Real>::ExtractEulerXYX() const
{
    // +-           -+   +-                                                -+
    // | r00 r01 r02 |   |  cy      sy*sx1               sy*cx1             |
    // | r10 r11 r12 | = |  sy*sx0  cx0*cx1-cy*sx0*sx1  -cy*cx1*sx0-cx0*sx1 |
    // | r20 r21 r22 |   | -sy*cx0  cx1*sx0+cy*cx0*sx1   cy*cx0*cx1-sx0*sx1 |
    // +-           -+   +-                                                -+

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (m_Entry(0, 0) < Math::GetValue(1) - Math::GetZeroTolerance())
    {
        if (-Math::GetValue(1) + Math::GetZeroTolerance() < m_Entry(0, 0))
        {
            // y_angle  = acos(r00)
            // x0_angle = atan2(r10,-r20)
            // x1_angle = atan2(r01,r02)

            auto yAngle = Math::ACos(m_Entry(0, 0));
            auto x0Angle = Math::ATan2(m_Entry(1, 0), -m_Entry(2, 0));
            auto x1Angle = Math::ATan2(m_Entry(0, 1), m_Entry(0, 2));

            return Euler{ ExtractEulerResultType::Unique, ExtractEulerResultOrder::XYX, x0Angle, yAngle, Math::GetValue(0), x1Angle, Math::GetValue(0), Math::GetValue(0) };
        }
        else
        {
            // 该解不是唯一的:  x1_angle - x0_angle = atan2(-r12,r11)

            auto yAngle = Math::GetPI();
            auto x0Angle = -Math::ATan2(-m_Entry(1, 2), m_Entry(1, 1));
            auto x1Angle = Math::GetValue(0);

            return Euler{ ExtractEulerResultType::Difference, ExtractEulerResultOrder::XYX, x0Angle, yAngle, Math::GetValue(0), x1Angle, Math::GetValue(0), Math::GetValue(0) };
        }
    }
    else
    {
        // 该解不是唯一的:  x1_angle + x0_angle = atan2(-r12,r11)
        auto yAngle = Math::GetValue(0);
        auto x0Angle = Math::ATan2(-m_Entry(1, 2), m_Entry(1, 1));
        auto x1Angle = Math::GetValue(0);

        return Euler{ ExtractEulerResultType::Sum, ExtractEulerResultOrder::XYX, x0Angle, yAngle, Math::GetValue(0), x1Angle, Math::GetValue(0), Math::GetValue(0) };
    }
}

template <typename Real>
typename const Mathematics::Matrix3<Real>::Euler Mathematics::Matrix3<Real>::ExtractEulerXZX() const
{
    // +-           -+   +-                                                -+
    // | r00 r01 r02 |   | cz      -sz*cx1               sz*sx1             |
    // | r10 r11 r12 | = | sz*cx0   cz*cx0*cx1-sx0*sx1  -cx1*sx0-cz*cx0*sx1 |
    // | r20 r21 r22 |   | sz*sx0   cz*cx1*sx0+cx0*sx1   cx0*cx1-cz*sx0*sx1 |
    // +-           -+   +-                                                -+

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (m_Entry(0, 0) < Math::GetValue(1) - Math::GetZeroTolerance())
    {
        if (-Math::GetValue(1) + Math::GetZeroTolerance() < m_Entry(0, 0))
        {
            // z_angle  = acos(r00)
            // x0_angle = atan2(r20,r10)
            // x1_angle = atan2(r02,-r01)

            auto zAngle = Math::ACos(m_Entry(0, 0));
            auto x0Angle = Math::ATan2(m_Entry(2, 0), m_Entry(1, 0));
            auto x1Angle = Math::ATan2(m_Entry(0, 2), -m_Entry(0, 1));

            return Euler{ ExtractEulerResultType::Unique, ExtractEulerResultOrder::XZX, x0Angle, Math::GetValue(0), zAngle, x1Angle, Math::GetValue(0), Math::GetValue(0) };
        }
        else
        {
            // 该解不是唯一的:  x1_angle - x0_angle = atan2(r21,r22)

            auto zAngle = Math::GetPI();
            auto x0Angle = -Math::ATan2(m_Entry(2, 1), m_Entry(2, 2));
            auto x1Angle = Math::GetValue(0);

            return Euler{ ExtractEulerResultType::Difference, ExtractEulerResultOrder::XZX, x0Angle, Math::GetValue(0), zAngle, x1Angle, Math::GetValue(0), Math::GetValue(0) };
        }
    }
    else
    {
        // 该解不是唯一的: x1_angle + x0_angle = atan2(r21,r22)

        auto zAngle = Math::GetValue(0);
        auto x0Angle = Math::ATan2(m_Entry(2, 1), m_Entry(2, 2));
        auto x1Angle = Math::GetValue(0);

        return Euler{ ExtractEulerResultType::Sum, ExtractEulerResultOrder::XZX, x0Angle, Math::GetValue(0), zAngle, x1Angle, Math::GetValue(0), Math::GetValue(0) };
    }
}

template <typename Real>
typename const Mathematics::Matrix3<Real>::Euler Mathematics::Matrix3<Real>::ExtractEulerYXY() const
{
    // +-           -+   +-                                                -+
    // | r00 r01 r02 |   |  cy0*cy1-cx*sy0*sy1  sx*sy0   cx*cy1*sy0+cy0*sy1 |
    // | r10 r11 r12 | = |  sx*sy1              cx      -sx*cy1             |
    // | r20 r21 r22 |   | -cy1*sy0-cx*cy0*sy1  sx*cy0   cx*cy0*cy1-sy0*sy1 |
    // +-           -+   +-                                                -+

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (m_Entry(1, 1) < Math::GetValue(1) - Math::GetZeroTolerance())
    {
        if (-Math::GetValue(1) + Math::GetZeroTolerance() < m_Entry(1, 1))
        {
            // x_angle  = acos(r11)
            // y0_angle = atan2(r01,r21)
            // y1_angle = atan2(r10,-r12)

            auto xAngle = Math::ACos(m_Entry(1, 1));
            auto y0Angle = Math::ATan2(m_Entry(0, 1), m_Entry(2, 1));
            auto y1Angle = Math::ATan2(m_Entry(1, 0), -m_Entry(1, 2));

            return Euler{ ExtractEulerResultType::Unique, ExtractEulerResultOrder::YXY, xAngle, y0Angle, Math::GetValue(0), Math::GetValue(0), y1Angle, Math::GetValue(0) };
        }
        else
        {
            // 该解不是唯一的:  y1_angle - y0_angle = atan2(r02,r00)

            auto xAngle = Math::GetPI();
            auto y0Angle = -Math::ATan2(m_Entry(0, 2), m_Entry(0, 0));
            auto y1Angle = Math::GetValue(0);

            return Euler{ ExtractEulerResultType::Difference, ExtractEulerResultOrder::YXY, xAngle, y0Angle, Math::GetValue(0), Math::GetValue(0), y1Angle, Math::GetValue(0) };
        }
    }
    else
    {
        // 该解不是唯一的: y1_angle + y0_angle = atan2(r02,r00)

        auto xAngle = Math::GetValue(0);
        auto y0Angle = Math::ATan2(m_Entry(0, 2), m_Entry(0, 0));
        auto y1Angle = Math::GetValue(0);

        return Euler{ ExtractEulerResultType::Sum, ExtractEulerResultOrder::YXY, xAngle, y0Angle, Math::GetValue(0), Math::GetValue(0), y1Angle, Math::GetValue(0) };
    }
}

template <typename Real>
typename const Mathematics::Matrix3<Real>::Euler Mathematics::Matrix3<Real>::ExtractEulerYZY() const
{
    // +-           -+   +-                                                -+
    // | r00 r01 r02 |   |  cz*cy0*cy1-sy0*sy1  -sz*cy0  cy1*sy0+cz*cy0*sy1 |
    // | r10 r11 r12 | = |  sz*cy1               cz      sz*sy1             |
    // | r20 r21 r22 |   | -cz*cy1*sy0-cy0*sy1   sz*sy0  cy0*cy1-cz*sy0*sy1 |
    // +-           -+   +-                                                -+

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (m_Entry(1, 1) < Math::GetValue(1) - Math::GetZeroTolerance())
    {
        if (-Math::GetValue(1) + Math::GetZeroTolerance() < m_Entry(1, 1))
        {
            // z_angle  = acos(r11)
            // y0_angle = atan2(r21,-r01)
            // y1_angle = atan2(r12,r10)

            auto zAngle = Math::ACos(m_Entry(1, 1));
            auto y0Angle = Math::ATan2(m_Entry(2, 1), -m_Entry(0, 1));
            auto y1Angle = Math::ATan2(m_Entry(1, 2), m_Entry(1, 0));

            return Euler{ ExtractEulerResultType::Unique, ExtractEulerResultOrder::YZY, Math::GetValue(0), y0Angle, zAngle, Math::GetValue(0), y1Angle, Math::GetValue(0) };
        }
        else
        {
            // 该解不是唯一的:  y1_angle - y0_angle = atan2(-r20,r22)

            auto zAngle = Math::GetPI();
            auto y0Angle = -Math::ATan2(-m_Entry(2, 0), m_Entry(2, 2));
            auto y1Angle = Math::GetValue(0);

            return Euler{ ExtractEulerResultType::Difference, ExtractEulerResultOrder::YZY, Math::GetValue(0), y0Angle, zAngle, Math::GetValue(0), y1Angle, Math::GetValue(0) };
        }
    }
    else
    {
        // 该解不是唯一的:  y1_angle + y0_angle = atan2(-r20,r22)

        auto zAngle = Math::GetValue(0);
        auto y0Angle = Math::ATan2(-m_Entry(2, 0), m_Entry(2, 2));
        auto y1Angle = Math::GetValue(0);

        return Euler{ ExtractEulerResultType::Sum, ExtractEulerResultOrder::YZY, Math::GetValue(0), y0Angle, zAngle, Math::GetValue(0), y1Angle, Math::GetValue(0) };
    }
}

template <typename Real>
typename const Mathematics::Matrix3<Real>::Euler Mathematics::Matrix3<Real>::ExtractEulerZXZ() const
{
    // +-           -+   +-                                                -+
    // | r00 r01 r02 |   | cz0*cz1-cx*sz0*sz1  -cx*cz1*sz0-cz0*sz1   sx*sz0 |
    // | r10 r11 r12 | = | cz1*sz0+cx*cz0*sz1   cx*cz0*cz1-sz0*sz1  -sz*cz0 |
    // | r20 r21 r22 |   | sx*sz1               sx*cz1               cx     |
    // +-           -+   +-                                                -+

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (m_Entry(2, 2) < Math::GetValue(1) - Math::GetZeroTolerance())
    {
        if (-Math::GetValue(1) + Math::GetZeroTolerance() < m_Entry(2, 2))
        {
            // x_angle  = acos(r22)
            // z0_angle = atan2(r02,-r12)
            // z1_angle = atan2(r20,r21)

            auto xAngle = Math::ACos(m_Entry(2, 2));
            auto z0Angle = Math::ATan2(m_Entry(0, 2), -m_Entry(1, 2));
            auto z1Angle = Math::ATan2(m_Entry(2, 0), m_Entry(2, 1));

            return Euler{ ExtractEulerResultType::Unique, ExtractEulerResultOrder::ZXZ, xAngle, Math::GetValue(0), z0Angle, Math::GetValue(0), Math::GetValue(0), z1Angle };
        }
        else
        {
            // 该解不是唯一的:  z1_angle - z0_angle = atan2(-r01,r00)

            auto xAngle = Math::GetPI();
            auto z0Angle = -Math::ATan2(-m_Entry(0, 1), m_Entry(0, 0));
            auto z1Angle = Math::GetValue(0);

            return Euler{ ExtractEulerResultType::Difference, ExtractEulerResultOrder::ZXZ, xAngle, Math::GetValue(0), z0Angle, Math::GetValue(0), Math::GetValue(0), z1Angle };
        }
    }
    else
    {
        // 该解不是唯一的: z1_angle + z0_angle = atan2(-r01,r00)

        auto xAngle = Math::GetValue(0);
        auto z0Angle = Math::ATan2(-m_Entry(0, 1), m_Entry(0, 0));
        auto z1Angle = Math::GetValue(0);

        return Euler{ ExtractEulerResultType::Sum, ExtractEulerResultOrder::ZXZ, xAngle, Math::GetValue(0), z0Angle, Math::GetValue(0), Math::GetValue(0), z1Angle };
    }
}

template <typename Real>
typename const Mathematics::Matrix3<Real>::Euler Mathematics::Matrix3<Real>::ExtractEulerZYZ() const
{
    // +-           -+   +-                                                -+
    // | r00 r01 r02 |   |  cy*cz0*cz1-sz0*sz1  -cz1*sz0-cy*cz0*sz1  sy*cz0 |
    // | r10 r11 r12 | = |  cy*cz1*sz0+cz0*sz1   cz0*cz1-cy*sz0*sz1  sy*sz0 |
    // | r20 r21 r22 |   | -sy*cz1               sy*sz1              cy     |
    // +-           -+   +-                                                -+

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (m_Entry(2, 2) < Math::GetValue(1) - Math::GetZeroTolerance())
    {
        if (-Math::GetValue(1) + Math::GetZeroTolerance() < m_Entry(2, 2))
        {
            // y_angle  = acos(r22)
            // z0_angle = atan2(r12,r02)
            // z1_angle = atan2(r21,-r20)

            auto yAngle = Math::ACos(m_Entry(2, 2));
            auto z0Angle = Math::ATan2(m_Entry(1, 2), m_Entry(0, 2));
            auto z1Angle = Math::ATan2(m_Entry(2, 1), -m_Entry(2, 0));

            return Euler{ ExtractEulerResultType::Unique, ExtractEulerResultOrder::ZYZ, Math::GetValue(0), yAngle, z0Angle, Math::GetValue(0), Math::GetValue(0), z1Angle };
        }
        else  // r22 = -1
        {
            // 该解不是唯一的:  z1_angle - z0_angle = atan2(r10,r11)

            auto yAngle = Math::GetPI();
            auto z0Angle = -Math::ATan2(m_Entry(1, 0), m_Entry(1, 1));
            auto z1Angle = Math::GetValue(0);

            return Euler{ ExtractEulerResultType::Difference, ExtractEulerResultOrder::ZYZ, Math::GetValue(0), yAngle, z0Angle, Math::GetValue(0), Math::GetValue(0), z1Angle };
        }
    }
    else  // r22 = +1
    {
        // 该解不是唯一的: z1_angle + z0_angle = atan2(r10,r11)

        auto yAngle = Math::GetValue(0);
        auto z0Angle = Math::ATan2(m_Entry(1, 0), m_Entry(1, 1));
        auto z1Angle = Math::GetValue(0);

        return Euler{ ExtractEulerResultType::Sum, ExtractEulerResultOrder::ZYZ, Math::GetValue(0), yAngle, z0Angle, Math::GetValue(0), Math::GetValue(0), z1Angle };
    }
}

template <typename Real>
void Mathematics::Matrix3<Real>::Slerp(Real t, const Matrix3& firstRot, const Matrix3& secondRot)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto prod = TransposeTimes(firstRot, secondRot);

    auto extract = prod.ExtractAngleAxis();

    auto axis = extract.GetAxis();
    auto angle = extract.GetAngle();

    MakeRotation(axis, t * angle);

    *this = firstRot * (*this);
}

template <typename T>
const typename Mathematics::Matrix3<T>::ArrayType Mathematics::Matrix3<T>::GetCoordinate() const noexcept
{
    return m_Entry.GetCoordinate();
}

template <typename T>
void Mathematics::Matrix3<T>::Set(const ArrayType& coordinate)  
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
    for (int i = 0; i < sm_MatrixSize; ++i)
    {
        m_Entry(i / 3, i % 3) = coordinate[i];
    }
#include STSTEM_WARNING_POP
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics ::operator*(const Vector3D<Real>& vector, const Matrix3<Real>& matrix)
{
    return Vector3D<Real>{ vector[0] * matrix(0, 0) + vector[1] * matrix(1, 0) + vector[2] * matrix(2, 0),
                           vector[0] * matrix(0, 1) + vector[1] * matrix(1, 1) + vector[2] * matrix(2, 1),
                           vector[0] * matrix(0, 2) + vector[1] * matrix(1, 2) + vector[2] * matrix(2, 2) };
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics ::operator*(const Matrix3<Real>& matrix, const Vector3D<Real>& vector)
{
    return Vector3D<Real>{ matrix(0, 0) * vector[0] + matrix(0, 1) * vector[1] + matrix(0, 2) * vector[2],
                           matrix(1, 0) * vector[0] + matrix(1, 1) * vector[1] + matrix(1, 2) * vector[2],
                           matrix(2, 0) * vector[0] + matrix(2, 1) * vector[1] + matrix(2, 2) * vector[2] };
}

template <typename Real>
const Mathematics::Matrix3<Real> Mathematics ::operator*(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs)
{
    // A * B
    return Matrix3<Real>{ lhs(0, 0) * rhs(0, 0) + lhs(0, 1) * rhs(1, 0) + lhs(0, 2) * rhs(2, 0),
                          lhs(0, 0) * rhs(0, 1) + lhs(0, 1) * rhs(1, 1) + lhs(0, 2) * rhs(2, 1),
                          lhs(0, 0) * rhs(0, 2) + lhs(0, 1) * rhs(1, 2) + lhs(0, 2) * rhs(2, 2),
                          lhs(1, 0) * rhs(0, 0) + lhs(1, 1) * rhs(1, 0) + lhs(1, 2) * rhs(2, 0),
                          lhs(1, 0) * rhs(0, 1) + lhs(1, 1) * rhs(1, 1) + lhs(1, 2) * rhs(2, 1),
                          lhs(1, 0) * rhs(0, 2) + lhs(1, 1) * rhs(1, 2) + lhs(1, 2) * rhs(2, 2),
                          lhs(2, 0) * rhs(0, 0) + lhs(2, 1) * rhs(1, 0) + lhs(2, 2) * rhs(2, 0),
                          lhs(2, 0) * rhs(0, 1) + lhs(2, 1) * rhs(1, 1) + lhs(2, 2) * rhs(2, 1),
                          lhs(2, 0) * rhs(0, 2) + lhs(2, 1) * rhs(1, 2) + lhs(2, 2) * rhs(2, 2) };
}

template <typename Real>
const Mathematics::Matrix3<Real> Mathematics ::TransposeTimes(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs)
{
    // A^T * B
    return Matrix3<Real>{ lhs(0, 0) * rhs(0, 0) + lhs(1, 0) * rhs(1, 0) + lhs(2, 0) * rhs(2, 0),
                          lhs(0, 0) * rhs(0, 1) + lhs(1, 0) * rhs(1, 1) + lhs(2, 0) * rhs(2, 1),
                          lhs(0, 0) * rhs(0, 2) + lhs(1, 0) * rhs(1, 2) + lhs(2, 0) * rhs(2, 2),
                          lhs(0, 1) * rhs(0, 0) + lhs(1, 1) * rhs(1, 0) + lhs(2, 1) * rhs(2, 0),
                          lhs(0, 1) * rhs(0, 1) + lhs(1, 1) * rhs(1, 1) + lhs(2, 1) * rhs(2, 1),
                          lhs(0, 1) * rhs(0, 2) + lhs(1, 1) * rhs(1, 2) + lhs(2, 1) * rhs(2, 2),
                          lhs(0, 2) * rhs(0, 0) + lhs(1, 2) * rhs(1, 0) + lhs(2, 2) * rhs(2, 0),
                          lhs(0, 2) * rhs(0, 1) + lhs(1, 2) * rhs(1, 1) + lhs(2, 2) * rhs(2, 1),
                          lhs(0, 2) * rhs(0, 2) + lhs(1, 2) * rhs(1, 2) + lhs(2, 2) * rhs(2, 2) };
}

template <typename Real>
const Mathematics::Matrix3<Real> Mathematics ::TimesTranspose(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs)
{
    // A * B^T
    return Matrix3<Real>{ lhs(0, 0) * rhs(0, 0) + lhs(0, 1) * rhs(0, 1) + lhs(0, 2) * rhs(0, 2),
                          lhs(0, 0) * rhs(1, 0) + lhs(0, 1) * rhs(1, 1) + lhs(0, 2) * rhs(1, 2),
                          lhs(0, 0) * rhs(2, 0) + lhs(0, 1) * rhs(2, 1) + lhs(0, 2) * rhs(2, 2),
                          lhs(1, 0) * rhs(0, 0) + lhs(1, 1) * rhs(0, 1) + lhs(1, 2) * rhs(0, 2),
                          lhs(1, 0) * rhs(1, 0) + lhs(1, 1) * rhs(1, 1) + lhs(1, 2) * rhs(1, 2),
                          lhs(1, 0) * rhs(2, 0) + lhs(1, 1) * rhs(2, 1) + lhs(1, 2) * rhs(2, 2),
                          lhs(2, 0) * rhs(0, 0) + lhs(2, 1) * rhs(0, 1) + lhs(2, 2) * rhs(0, 2),
                          lhs(2, 0) * rhs(1, 0) + lhs(2, 1) * rhs(1, 1) + lhs(2, 2) * rhs(1, 2),
                          lhs(2, 0) * rhs(2, 0) + lhs(2, 1) * rhs(2, 1) + lhs(2, 2) * rhs(2, 2) };
}

template <typename Real>
const Mathematics::Matrix3<Real> Mathematics ::TransposeTimesTranspose(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs)
{
    // A^T * B^T
    return Matrix3<Real>{ lhs(0, 0) * rhs(0, 0) + lhs(1, 0) * rhs(0, 1) + lhs(2, 0) * rhs(0, 2),
                          lhs(0, 0) * rhs(1, 0) + lhs(1, 0) * rhs(1, 1) + lhs(2, 0) * rhs(1, 2),
                          lhs(0, 0) * rhs(2, 0) + lhs(1, 0) * rhs(2, 1) + lhs(2, 0) * rhs(2, 2),
                          lhs(0, 1) * rhs(0, 0) + lhs(1, 1) * rhs(0, 1) + lhs(2, 1) * rhs(0, 2),
                          lhs(0, 1) * rhs(1, 0) + lhs(1, 1) * rhs(1, 1) + lhs(2, 1) * rhs(1, 2),
                          lhs(0, 1) * rhs(2, 0) + lhs(1, 1) * rhs(2, 1) + lhs(2, 1) * rhs(2, 2),
                          lhs(0, 2) * rhs(0, 0) + lhs(1, 2) * rhs(0, 1) + lhs(2, 2) * rhs(0, 2),
                          lhs(0, 2) * rhs(1, 0) + lhs(1, 2) * rhs(1, 1) + lhs(2, 2) * rhs(1, 2),
                          lhs(0, 2) * rhs(2, 0) + lhs(1, 2) * rhs(2, 1) + lhs(2, 2) * rhs(2, 2) };
}

template <typename Real>
bool Mathematics ::Approximate(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs, const Real epsilon)
{
    for (auto row = 0; row < 3; ++row)
    {
        for (auto column = 0; column < 3; ++column)
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
bool Mathematics ::Approximate(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs)
{
    return Approximate(lhs, rhs, Math<Real>::GetZeroTolerance());
}

template <typename Real>
std::ostream& Mathematics ::operator<<(std::ostream& outFile, const Matrix3<Real>& matrix)
{
    for (auto row = 0; row < 3; ++row)
    {
        for (auto column = 0; column < 3; ++column)
        {
            outFile << matrix(row, column) << "　";
        }
    }

    return outFile;
}

#include STSTEM_WARNING_POP

#endif  // MATHEMATICS_ALGEBRA_MATRIX3_DETAIL_H
