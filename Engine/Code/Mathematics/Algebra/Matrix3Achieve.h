///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 10:32)

#ifndef MATHEMATICS_ALGEBRA_MATRIX3_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_MATRIX3_ACHIEVE_H

#include "AVector.h"
#include "AxisAngleDetail.h"
#include "EulerDetail.h"
#include "Matrix2Detail.h"
#include "Matrix3.h"
#include "Matrix4Detail.h"
#include "TridiagonalizeDetail.h"
#include "Vector3Detail.h"
#include "Vector3Tools.h"
#include "Flags/EulerResultType.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/NumericalAnalysis/GaussianEliminationDetail.h"

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix3<Real>::Matrix3(const ContainerType& entry, MatrixMajorFlags majorFlag)
    : x{}, y{}, z{}
{
    if (entry.size() != matrixSize)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("数据大小错误！"s))
    }

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    if (majorFlag == MatrixMajorFlags::Row)
    {
        x.SetCoordinate(entry[0], entry[1], entry[2]);
        y.SetCoordinate(entry[3], entry[4], entry[5]);
        z.SetCoordinate(entry[6], entry[7], entry[8]);
    }
    else
    {
        x.SetCoordinate(entry[0], entry[3], entry[6]);
        y.SetCoordinate(entry[1], entry[4], entry[7]);
        z.SetCoordinate(entry[2], entry[5], entry[8]);
    }

#include SYSTEM_WARNING_POP

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix3<Real>::Matrix3(const Vector3& vector0, const Vector3& vector1, const Vector3& vector2, MatrixMajorFlags majorFlag)
    : x{}, y{}, z{}
{
    if (majorFlag == MatrixMajorFlags::Row)
    {
        x = vector0;
        y = vector1;
        z = vector2;
    }
    else
    {
        x.SetCoordinate(vector0[xIndex], vector1[xIndex], vector2[xIndex]);
        y.SetCoordinate(vector0[yIndex], vector1[yIndex], vector2[yIndex]);
        z.SetCoordinate(vector0[zIndex], vector1[zIndex], vector2[zIndex]);
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix3<Real>::Matrix3(const Vector3ContainerType& vectors, MatrixMajorFlags majorFlag)
    : x{}, y{}, z{}
{
    if (vectors.size() != vectorSize)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("数据大小错误！"s))
    }

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    if (majorFlag == MatrixMajorFlags::Row)
    {
        x = vectors[xIndex];
        y = vectors[yIndex];
        z = vectors[zIndex];
    }
    else
    {
        x.SetCoordinate(vectors[xIndex].GetX(), vectors[yIndex].GetX(), vectors[zIndex].GetX());
        y.SetCoordinate(vectors[xIndex].GetY(), vectors[yIndex].GetY(), vectors[zIndex].GetY());
        z.SetCoordinate(vectors[xIndex].GetZ(), vectors[yIndex].GetZ(), vectors[zIndex].GetZ());
    }

#include SYSTEM_WARNING_POP

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix3<Real>::Matrix3(const Vector3& axis, Real angle) noexcept
    : x{}, y{}, z{}
{
    MakeRotation(axis, angle);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix3<Real>::Matrix3(MatrixRotationAxis axis, Real angle) noexcept(gAssert < 1 || gMathematicsAssert < 1)
    : x{}, y{}, z{}
{
    MakeRotation(axis, angle);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix3<Real>::Matrix3(const Vector3& vector0, const Vector3& vector1) noexcept
    : x{}, y{}, z{}
{
    MakeTensorProduct(vector0, vector1);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Matrix3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix3<Real>::MakeZero() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x.ZeroOut();
    y.ZeroOut();
    z.ZeroOut();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix3<Real>::MakeIdentity() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x = Vector3::GetUnitX();
    y = Vector3::GetUnitY();
    z = Vector3::GetUnitZ();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix3<Real>::MakeDiagonal(Real member00, Real member11, Real member22) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x.SetCoordinate(member00, MathType::GetValue(0), MathType::GetValue(0));
    y.SetCoordinate(MathType::GetValue(0), member11, MathType::GetValue(0));
    z.SetCoordinate(MathType::GetValue(0), MathType::GetValue(0), member22);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix3<Real>::MakeRotation(const Vector3& axis, Real angle) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto cosValue = MathType::Cos(angle);
    const auto sinValue = MathType::Sin(angle);
    const auto oneMinusCos = MathType::GetValue(1) - cosValue;

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

    x.SetCoordinate(xAxisSquareMultipliedOneMinusCos + cosValue, xym - zSin, xzm + ySin);
    y.SetCoordinate(xym + zSin, yAxisSquareMultipliedOneMinusCos + cosValue, yzm - xSin);
    z.SetCoordinate(xzm - ySin, yzm + xSin, zAxisSquareMultipliedOneMinusCos + cosValue);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix3<Real>::MakeRotation(MatrixRotationAxis axis, Real angle) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto cosValue = MathType::Cos(angle);
    const auto sinValue = MathType::Sin(angle);

    switch (axis)
    {
        case MatrixRotationAxis::X:
        {
            x = Vector3::GetUnitX();
            y.SetCoordinate(MathType::GetValue(0), cosValue, -sinValue);
            z.SetCoordinate(MathType::GetValue(0), sinValue, cosValue);

            break;
        }

        case MatrixRotationAxis::Y:
        {
            x.SetCoordinate(cosValue, MathType::GetValue(0), sinValue);
            y = Vector3::GetUnitY();
            z.SetCoordinate(-sinValue, MathType::GetValue(0), cosValue);

            break;
        }

        case MatrixRotationAxis::Z:
        {
            x.SetCoordinate(cosValue, -sinValue, MathType::GetValue(0));
            y.SetCoordinate(sinValue, cosValue, MathType::GetValue(0));
            z = Vector3::GetUnitZ();

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
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix3<Real>::MakeTensorProduct(const Vector3& vector0, const Vector3& vector1) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x.SetCoordinate(vector0.GetX() * vector1.GetX(), vector0.GetX() * vector1.GetY(), vector0.GetX() * vector1.GetZ());
    y.SetCoordinate(vector0.GetY() * vector1.GetX(), vector0.GetY() * vector1.GetY(), vector0.GetY() * vector1.GetZ());
    z.SetCoordinate(vector0.GetZ() * vector1.GetX(), vector0.GetZ() * vector1.GetY(), vector0.GetZ() * vector1.GetZ());
}

template <typename Real>
requires std::is_arithmetic_v<Real>
const Mathematics::Vector3<Real>& Mathematics::Matrix3<Real>::operator[](int row) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    switch (System::UnderlyingCastEnum<VectorIndex>(row))
    {
        case Matrix3::VectorIndex::X:
            return x;
        case Matrix3::VectorIndex::Y:
            return y;
        case Matrix3::VectorIndex::Z:
            return z;
        default:
            break;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引错误！"s))
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real>& Mathematics::Matrix3<Real>::operator[](int row)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(Mathematics::Vector3<Real>, row);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
const Real& Mathematics::Matrix3<Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    MATHEMATICS_ASSERTION_0(xIndex <= row && row < vectorSize, "row索引错误！");
    MATHEMATICS_ASSERTION_0(Vector3::xIndex <= column && column < Vector3::pointSize, "column索引错误！");

    return (*this)[row][column];
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real& Mathematics::Matrix3<Real>::operator()(int row, int column)
{
    MATHEMATICS_CLASS_IS_VALID_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, column));

#include SYSTEM_WARNING_POP
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix3<Real> Mathematics::Matrix3<Real>::operator-() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix3{ -x.GetX(),
                    -x.GetY(),
                    -x.GetZ(),
                    -y.GetX(),
                    -y.GetY(),
                    -y.GetZ(),
                    -z.GetX(),
                    -z.GetY(),
                    -z.GetZ() };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix3<Real>& Mathematics::Matrix3<Real>::operator+=(const Matrix3& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x += rhs.x;
    y += rhs.y;
    z += rhs.z;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix3<Real>& Mathematics::Matrix3<Real>::operator-=(const Matrix3& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix3<Real>& Mathematics::Matrix3<Real>::operator*=(Real scalar) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x *= scalar;
    y *= scalar;
    z *= scalar;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix3<Real>& Mathematics::Matrix3<Real>::operator/=(Real scalar) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x /= scalar;
    y /= scalar;
    z /= scalar;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Matrix3<Real>::QuadraticForm(const Vector3& lhs, const Vector3& rhs) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Vector3ToolsType::DotProduct(lhs, (*this) * rhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
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
requires std::is_arithmetic_v<Real>
Mathematics::Matrix3<Real>& Mathematics::Matrix3<Real>::operator*=(const Matrix3& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    *this = *this * rhs;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
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
requires std::is_arithmetic_v<Real>
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
requires std::is_arithmetic_v<Real>
Mathematics::Matrix3<Real> Mathematics::Matrix3<Real>::GaussianEliminationInverse(Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (GaussianElimination<Real> gaussianElimination{ vectorSize, GetContainer(), true, epsilon };
        gaussianElimination.IsInverse())
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
requires std::is_arithmetic_v<Real>
Real Mathematics::Matrix3<Real>::GaussianEliminationDeterminant(Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    GaussianElimination<Real> gaussianElimination{ vectorSize, GetContainer(), false, epsilon };

    return gaussianElimination.GetDeterminant();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix3<Real> Mathematics::Matrix3<Real>::Inverse(const Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    // 使用辅助因子求一个3x3矩阵的逆。
    // 这比使用高斯消元法更快，因为循环的开销相当于一个方法。

    // 计算伴随矩阵。
    auto adjoint = Adjoint();

    const auto det = GetValue<0, 0>() * adjoint.template GetValue<0, 0>() + GetValue<0, 1>() * adjoint.template GetValue<1, 0>() + GetValue<0, 2>() * adjoint.template GetValue<2, 0>();

    if (epsilon < MathType::FAbs(det))
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
requires std::is_arithmetic_v<Real>
Mathematics::Matrix3<Real> Mathematics::Matrix3<Real>::Adjoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix3{ GetValue<1, 1>() * GetValue<2, 2>() - GetValue<1, 2>() * GetValue<2, 1>(),
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
requires std::is_arithmetic_v<Real>
Real Mathematics::Matrix3<Real>::Determinant() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto column00 = GetValue<1, 1>() * GetValue<2, 2>() - GetValue<1, 2>() * GetValue<2, 1>();
    const auto column10 = GetValue<1, 2>() * GetValue<2, 0>() - GetValue<1, 0>() * GetValue<2, 2>();
    const auto column20 = GetValue<1, 0>() * GetValue<2, 1>() - GetValue<1, 1>() * GetValue<2, 0>();

    return GetValue<0, 0>() * column00 + GetValue<0, 1>() * column10 + GetValue<0, 2>() * column20;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Matrix3<Real>::ExtractAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto trace = GetValue<0, 0>() + GetValue<1, 1>() + GetValue<2, 2>();
    const auto cosValue = MathType::GetRational(1, 2) * (trace - MathType::GetValue(1));

    return MathType::ACos(cosValue);  // angle范围在 [0,PI]
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Matrix3<Real>::Matrix3Extract Mathematics::Matrix3<Real>::ExtractAngleAxis() const noexcept(gAssert < 3 || gMathematicsAssert < 3)
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

    if (MathType::GetZeroTolerance() < angle)
    {
        Vector3 axis{ GetValue<2, 1>() - GetValue<1, 2>(),
                      GetValue<0, 2>() - GetValue<2, 0>(),
                      GetValue<1, 0>() - GetValue<0, 1>() };

        if (MathType::GetZeroTolerance() * MathType::GetZeroTolerance() < Vector3ToolsType::GetLengthSquared(axis))
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
                auto axisX = MathType::GetRational(1, 2) * MathType::Sqrt(MathType::GetValue(1) + GetValue<0, 0>() - GetValue<1, 1>() - GetValue<2, 2>());

                const auto halfInverse = MathType::GetRational(1, 2) / axisX;

                axis = Vector3{ axisX, halfInverse * GetValue<0, 1>(), halfInverse * GetValue<0, 2>() };
            }
            else if (GetValue<0, 0>() < GetValue<1, 1>() && GetValue<2, 2>() <= GetValue<1, 1>())
            {
                // r00 < r11

                // r11是最大对角线项
                auto axisY = MathType::GetRational(1, 2) * MathType::Sqrt(MathType::GetValue(1) + GetValue<1, 1>() - GetValue<0, 0>() - GetValue<2, 2>());

                const auto halfInverse = MathType::GetRational(1, 2) / axisY;

                axis = Vector3{ halfInverse * GetValue<0, 1>(), axisY, halfInverse * GetValue<1, 2>() };
            }
            else
            {
                // r22是最大对角线项
                auto axisZ = MathType::GetRational(1, 2) * MathType::Sqrt(MathType::GetValue(1) + GetValue<2, 2>() - GetValue<0, 0>() - GetValue<1, 1>());

                const auto halfInverse = MathType::GetRational(1, 2) / axisZ;

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
requires std::is_arithmetic_v<Real>
typename Mathematics::Matrix3<Real>::Vector3 Mathematics::Matrix3<Real>::ExtractAxis() const noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto extract = ExtractAngleAxis();

    return extract.GetAxis();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
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
    auto invLength = MathType::InvSqrt(GetValue<0, 0>() * GetValue<0, 0>() + GetValue<1, 0>() * GetValue<1, 0>() + GetValue<2, 0>() * GetValue<2, 0>());

    (*this)(0, 0) *= invLength;
    (*this)(1, 0) *= invLength;
    (*this)(2, 0) *= invLength;

    // 计算 q1.
    auto dot0 = GetValue<0, 0>() * GetValue<0, 1>() + GetValue<1, 0>() * GetValue<1, 1>() + GetValue<2, 0>() * GetValue<2, 1>();

    (*this)(0, 1) -= dot0 * GetValue<0, 0>();
    (*this)(1, 1) -= dot0 * GetValue<1, 0>();
    (*this)(2, 1) -= dot0 * GetValue<2, 0>();

    invLength = MathType::InvSqrt(GetValue<0, 1>() * GetValue<0, 1>() + GetValue<1, 1>() * GetValue<1, 1>() + GetValue<2, 1>() * GetValue<2, 1>());

    (*this)(0, 1) *= invLength;
    (*this)(1, 1) *= invLength;
    (*this)(2, 1) *= invLength;

    // 计算 q2
    auto dot1 = GetValue<0, 1>() * GetValue<0, 2>() + GetValue<1, 1>() * GetValue<1, 2>() + GetValue<2, 1>() * GetValue<2, 2>();

    auto dot2 = GetValue<0, 0>() * GetValue<0, 2>() + GetValue<1, 0>() * GetValue<1, 2>() + GetValue<2, 0>() * GetValue<2, 2>();

    (*this)(0, 2) -= dot2 * GetValue<0, 0>() + dot1 * GetValue<0, 1>();
    (*this)(1, 2) -= dot2 * GetValue<1, 0>() + dot1 * GetValue<1, 1>();
    (*this)(2, 2) -= dot2 * GetValue<2, 0>() + dot1 * GetValue<2, 1>();

    invLength = MathType::InvSqrt(GetValue<0, 2>() * GetValue<0, 2>() + GetValue<1, 2>() * GetValue<1, 2>() + GetValue<2, 2>() * GetValue<2, 2>());

    (*this)(0, 2) *= invLength;
    (*this)(1, 2) *= invLength;
    (*this)(2, 2) *= invLength;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Matrix3<Real>::Matrix3EigenDecompositionType Mathematics::Matrix3<Real>::EigenDecomposition(Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    MATHEMATICS_ASSERTION_1(MathType::FAbs(GetValue<0, 1>() - GetValue<1, 0>()) <= epsilon, "矩阵必须是对称矩阵。");
    MATHEMATICS_ASSERTION_1(MathType::FAbs(GetValue<0, 2>() - GetValue<2, 0>()) <= epsilon, "矩阵必须是对称矩阵。");
    MATHEMATICS_ASSERTION_1(MathType::FAbs(GetValue<1, 2>() - GetValue<2, 1>()) <= epsilon, "矩阵必须是对称矩阵。");

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
        rotation(0, 2) = -rotation.template GetValue<0, 2>();
        rotation(1, 2) = -rotation.template GetValue<1, 2>();
        rotation(2, 2) = -rotation.template GetValue<2, 2>();
    }

    return Matrix3EigenDecompositionType{ rotation, diagonalMatrix, epsilon };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix3<Real>::MakeEuler(const EulerType& euler) noexcept(gAssert < 1 || gMathematicsAssert < 1)
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
requires std::is_arithmetic_v<Real>
typename Mathematics::Matrix3<Real>::EulerType Mathematics::Matrix3<Real>::ExtractEuler(ExtractEulerResultOrder euler) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    switch (euler)
    {
        case ExtractEulerResultOrder::XYZ:
            return ExtractEulerXYZ();
        case ExtractEulerResultOrder::XZY:
            return ExtractEulerXZY();
        case ExtractEulerResultOrder::YXZ:
            return ExtractEulerYXZ();
        case ExtractEulerResultOrder::YZX:
            return ExtractEulerYZX();
        case ExtractEulerResultOrder::ZXY:
            return ExtractEulerZXY();
        case ExtractEulerResultOrder::ZYX:
            return ExtractEulerZYX();
        case ExtractEulerResultOrder::XYX:
            return ExtractEulerXYX();
        case ExtractEulerResultOrder::XZX:
            return ExtractEulerXZX();
        case ExtractEulerResultOrder::YXY:
            return ExtractEulerYXY();
        case ExtractEulerResultOrder::YZY:
            return ExtractEulerYZY();
        case ExtractEulerResultOrder::ZXZ:
            return ExtractEulerZXZ();
        case ExtractEulerResultOrder::ZYZ:
            return ExtractEulerZYZ();
        default:
            return ExtractEulerXYZ();
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix3<Real>::MakeEulerXYZ(Real xAngle, Real yAngle, Real zAngle) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const Matrix3 xMat{ MatrixRotationAxis::X, xAngle };
    const Matrix3 yMat{ MatrixRotationAxis::Y, yAngle };
    const Matrix3 zMat{ MatrixRotationAxis::Z, zAngle };

    *this = xMat * (yMat * zMat);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix3<Real>::MakeEulerXZY(Real xAngle, Real zAngle, Real yAngle) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const Matrix3 xMat{ MatrixRotationAxis::X, xAngle };
    const Matrix3 zMat{ MatrixRotationAxis::Z, zAngle };
    const Matrix3 yMat{ MatrixRotationAxis::Y, yAngle };

    *this = xMat * (zMat * yMat);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix3<Real>::MakeEulerYXZ(Real yAngle, Real xAngle, Real zAngle) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const Matrix3 yMat{ MatrixRotationAxis::Y, yAngle };
    const Matrix3 xMat{ MatrixRotationAxis::X, xAngle };
    const Matrix3 zMat{ MatrixRotationAxis::Z, zAngle };

    *this = yMat * (xMat * zMat);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix3<Real>::MakeEulerYZX(Real yAngle, Real zAngle, Real xAngle) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const Matrix3 yMat{ MatrixRotationAxis::Y, yAngle };
    const Matrix3 zMat{ MatrixRotationAxis::Z, zAngle };
    const Matrix3 xMat{ MatrixRotationAxis::X, xAngle };

    *this = yMat * (zMat * xMat);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix3<Real>::MakeEulerZXY(Real zAngle, Real xAngle, Real yAngle) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const Matrix3 zMat{ MatrixRotationAxis::Z, zAngle };
    const Matrix3 xMat{ MatrixRotationAxis::X, xAngle };
    const Matrix3 yMat{ MatrixRotationAxis::Y, yAngle };

    *this = zMat * (xMat * yMat);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix3<Real>::MakeEulerZYX(Real zAngle, Real yAngle, Real xAngle) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const Matrix3 zMat{ MatrixRotationAxis::Z, zAngle };
    const Matrix3 yMat{ MatrixRotationAxis::Y, yAngle };
    const Matrix3 xMat{ MatrixRotationAxis::X, xAngle };

    *this = zMat * (yMat * xMat);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix3<Real>::MakeEulerXYX(Real x0Angle, Real yAngle, Real x1Angle) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const Matrix3 x0Mat{ MatrixRotationAxis::X, x0Angle };
    const Matrix3 yMat{ MatrixRotationAxis::Y, yAngle };
    const Matrix3 x1Mat{ MatrixRotationAxis::X, x1Angle };

    *this = x0Mat * (yMat * x1Mat);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix3<Real>::MakeEulerXZX(Real x0Angle, Real zAngle, Real x1Angle) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const Matrix3 x0Mat{ MatrixRotationAxis::X, x0Angle };
    const Matrix3 zMat{ MatrixRotationAxis::Z, zAngle };
    const Matrix3 x1Mat{ MatrixRotationAxis::X, x1Angle };

    *this = x0Mat * (zMat * x1Mat);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix3<Real>::MakeEulerYXY(Real y0Angle, Real xAngle, Real y1Angle) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const Matrix3 y0Mat{ MatrixRotationAxis::Y, y0Angle };
    const Matrix3 xMat{ MatrixRotationAxis::X, xAngle };
    const Matrix3 y1Mat{ MatrixRotationAxis::Y, y1Angle };

    *this = y0Mat * (xMat * y1Mat);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix3<Real>::MakeEulerYZY(Real y0Angle, Real zAngle, Real y1Angle) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const Matrix3 y0Mat{ MatrixRotationAxis::Y, y0Angle };
    const Matrix3 zMat{ MatrixRotationAxis::Z, zAngle };
    const Matrix3 y1Mat{ MatrixRotationAxis::Y, y1Angle };

    *this = y0Mat * (zMat * y1Mat);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix3<Real>::MakeEulerZXZ(Real z0Angle, Real xAngle, Real z1Angle) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const Matrix3 z0Mat{ MatrixRotationAxis::Z, z0Angle };
    const Matrix3 xMat{ MatrixRotationAxis::X, xAngle };
    const Matrix3 z1Mat{ MatrixRotationAxis::Z, z1Angle };

    *this = z0Mat * (xMat * z1Mat);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix3<Real>::MakeEulerZYZ(Real z0Angle, Real yAngle, Real z1Angle) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const Matrix3 z0Mat{ MatrixRotationAxis::Z, z0Angle };
    const Matrix3 yMat{ MatrixRotationAxis::Y, yAngle };
    const Matrix3 z1Mat{ MatrixRotationAxis::Z, z1Angle };

    *this = z0Mat * (yMat * z1Mat);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Matrix3<Real>::EulerType Mathematics::Matrix3<Real>::ExtractEulerXYZ() const noexcept
{
    // +-           -+   +-                                        -+
    // | r00 r01 r02 |   |  cy*cz           -cy*sz            sy    |
    // | r10 r11 r12 | = |  cz*sx*sy+cx*sz   cx*cz-sx*sy*sz  -cy*sx |
    // | r20 r21 r22 |   | -cx*cz*sy+sx*sz   cz*sx+cx*sy*sz   cx*cy |
    // +-           -+   +-                                        -+
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (GetValue<0, 2>() < MathType::GetValue(1) - MathType::GetZeroTolerance())
    {
        if (MathType::GetValue(-1) + MathType::GetZeroTolerance() < GetValue<0, 2>())
        {
            // y_angle = asin(r02)
            // x_angle = atan2(-r12,r22)
            // z_angle = atan2(-r01,r00)
            const auto yAngle = MathType::ASin(GetValue<0, 2>());
            const auto xAngle = MathType::ATan2(-GetValue<1, 2>(), GetValue<2, 2>());
            const auto zAngle = MathType::ATan2(-GetValue<0, 1>(), GetValue<0, 0>());

            return EulerType{ EulerResult::Unique, ExtractEulerResultOrder::XYZ, xAngle, yAngle, zAngle, MathType::GetValue(0), MathType::GetValue(0), MathType::GetValue(0) };
        }
        else
        {
            // y_angle = -pi/2
            // z_angle - x_angle = atan2(r10,r11)
            // 警告。该解不是唯一的。选择z_angle = 0.
            constexpr auto yAngle = -MathType::GetHalfPI();
            const auto xAngle = -MathType::ATan2(GetValue<1, 0>(), GetValue<1, 1>());
            constexpr auto zAngle = MathType::GetValue(0);

            return EulerType{ EulerResult::NotUniqueDifference, ExtractEulerResultOrder::XYZ, xAngle, yAngle, zAngle, MathType::GetValue(0), MathType::GetValue(0), MathType::GetValue(0) };
        }
    }
    else
    {
        // y_angle = +pi/2
        // z_angle + x_angle = atan2(r10,r11)
        // 警告。该解不是唯一的。选择z_angle = 0.
        constexpr auto yAngle = MathType::GetHalfPI();
        const auto xAngle = MathType::ATan2(GetValue<1, 0>(), GetValue<1, 1>());
        constexpr auto zAngle = MathType::GetValue(0);

        return EulerType{ EulerResult::NotUniqueSum, ExtractEulerResultOrder::XYZ, xAngle, yAngle, zAngle, MathType::GetValue(0), MathType::GetValue(0), MathType::GetValue(0) };
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Matrix3<Real>::EulerType Mathematics::Matrix3<Real>::ExtractEulerXZY() const noexcept
{
    // +-           -+   +-                                        -+
    // | r00 r01 r02 |   |  cy*cz           -sz      cz*sy          |
    // | r10 r11 r12 | = |  sx*sy+cx*cy*sz   cx*cz  -cy*sx+cx*sy*sz |
    // | r20 r21 r22 |   | -cx*sy+cy*sx*sz   cz*sx   cx*cy+sx*sy*sz |
    // +-           -+   +-                                        -+
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (GetValue<0, 1>() < MathType::GetValue(1) - MathType::GetZeroTolerance())
    {
        if (MathType::GetValue(-1) + MathType::GetZeroTolerance() < GetValue<0, 1>())
        {
            // z_angle = asin(-r01)
            // x_angle = atan2(r21,r11)
            // y_angle = atan2(r02,r00)
            const auto zAngle = MathType::ASin(-GetValue<0, 1>());
            const auto xAngle = MathType::ATan2(GetValue<2, 1>(), GetValue<1, 1>());
            const auto yAngle = MathType::ATan2(GetValue<0, 2>(), GetValue<0, 0>());

            return EulerType{ EulerResult::Unique, ExtractEulerResultOrder::XZY, xAngle, yAngle, zAngle, MathType::GetValue(0), MathType::GetValue(0), MathType::GetValue(0) };
        }
        else
        {
            // z_angle = +pi/2
            // y_angle - x_angle = atan2(-r20,r22)
            // 警告。该解不是唯一的。选择y_angle = 0.
            constexpr auto zAngle = MathType::GetHalfPI();
            const auto xAngle = -MathType::ATan2(-GetValue<2, 0>(), GetValue<2, 2>());
            constexpr auto yAngle = MathType::GetValue(0);

            return EulerType{ EulerResult::NotUniqueDifference, ExtractEulerResultOrder::XZY, xAngle, yAngle, zAngle, MathType::GetValue(0), MathType::GetValue(0), MathType::GetValue(0) };
        }
    }
    else
    {
        // z_angle = -pi/2
        // y_angle + x_angle = atan2(-r20,r22)
        // 警告。该解不是唯一的。选择y_angle = 0.
        constexpr auto zAngle = -MathType::GetHalfPI();
        const auto xAngle = MathType::ATan2(-GetValue<2, 0>(), GetValue<2, 2>());
        constexpr auto yAngle = MathType::GetValue(0);

        return EulerType{ EulerResult::NotUniqueSum, ExtractEulerResultOrder::XZY, xAngle, yAngle, zAngle, MathType::GetValue(0), MathType::GetValue(0), MathType::GetValue(0) };
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Matrix3<Real>::EulerType Mathematics::Matrix3<Real>::ExtractEulerYXZ() const noexcept
{
    // +-           -+   +-                                       -+
    // | r00 r01 r02 |   |  cy*cz+sx*sy*sz  cz*sx*sy-cy*sz   cx*sy |
    // | r10 r11 r12 | = |  cx*sz           cx*cz           -sx    |
    // | r20 r21 r22 |   | -cz*sy+cy*sx*sz  cy*cz*sx+sy*sz   cx*cy |
    // +-           -+   +-                                       -+

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (GetValue<1, 2>() < MathType::GetValue(1) - MathType::GetZeroTolerance())
    {
        if (MathType::GetValue(-1) + MathType::GetZeroTolerance() < GetValue<1, 2>())
        {
            // x_angle = asin(-r12)
            // y_angle = atan2(r02,r22)
            // z_angle = atan2(r10,r11)
            const auto xAngle = MathType::ASin(-GetValue<1, 2>());
            const auto yAngle = MathType::ATan2(GetValue<0, 2>(), GetValue<2, 2>());
            const auto zAngle = MathType::ATan2(GetValue<1, 0>(), GetValue<1, 1>());

            return EulerType{ EulerResult::Unique, ExtractEulerResultOrder::YXZ, xAngle, yAngle, zAngle, MathType::GetValue(0), MathType::GetValue(0), MathType::GetValue(0) };
        }
        else
        {
            // x_angle = +pi/2
            // z_angle - y_angle = atan2(-r01,r00)
            // 警告。该解不是唯一的。选择 z_angle = 0.
            constexpr auto xAngle = MathType::GetHalfPI();
            const auto yAngle = -MathType::ATan2(-GetValue<0, 1>(), GetValue<0, 0>());
            constexpr auto zAngle = MathType::GetValue(0);

            return EulerType{ EulerResult::NotUniqueDifference, ExtractEulerResultOrder::YXZ, xAngle, yAngle, zAngle, MathType::GetValue(0), MathType::GetValue(0), MathType::GetValue(0) };
        }
    }
    else
    {
        // x_angle = -pi/2
        // z_angle + y_angle = atan2(-r01,r00)
        // 警告。该解不是唯一的。选择z_angle = 0.
        constexpr auto xAngle = -MathType::GetHalfPI();
        const auto yAngle = MathType::ATan2(-GetValue<0, 1>(), GetValue<0, 0>());
        constexpr auto zAngle = MathType::GetValue(0);

        return EulerType{ EulerResult::NotUniqueSum, ExtractEulerResultOrder::YXZ, xAngle, yAngle, zAngle, MathType::GetValue(0), MathType::GetValue(0), MathType::GetValue(0) };
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Matrix3<Real>::EulerType Mathematics::Matrix3<Real>::ExtractEulerYZX() const noexcept
{
    // +-           -+   +-                                       -+
    // | r00 r01 r02 |   |  cy*cz  sx*sy-cx*cy*sz   cx*sy+cy*sx*sz |
    // | r10 r11 r12 | = |  sz     cx*cz           -cz*sx          |
    // | r20 r21 r22 |   | -cz*sy  cy*sx+cx*sy*sz   cx*cy-sx*sy*sz |
    // +-           -+   +-                                       -+

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (GetValue<1, 0>() < MathType::GetValue(1) - MathType::GetZeroTolerance())
    {
        if (MathType::GetValue(-1) + MathType::GetZeroTolerance() < GetValue<1, 0>())
        {
            // z_angle = asin(r10)
            // y_angle = atan2(-r20,r00)
            // x_angle = atan2(-r12,r11)
            const auto zAngle = MathType::ASin(GetValue<1, 0>());
            const auto yAngle = MathType::ATan2(-GetValue<2, 0>(), GetValue<0, 0>());
            const auto xAngle = MathType::ATan2(-GetValue<1, 2>(), GetValue<1, 1>());

            return EulerType{ EulerResult::Unique, ExtractEulerResultOrder::YZX, xAngle, yAngle, zAngle, MathType::GetValue(0), MathType::GetValue(0), MathType::GetValue(0) };
        }
        else
        {
            // z_angle = -pi/2
            // x_angle - y_angle = atan2(r21,r22)
            // 警告。该解不是唯一的。选择 x_angle = 0.

            constexpr auto zAngle = -MathType::GetHalfPI();
            const auto yAngle = -MathType::ATan2(GetValue<2, 1>(), GetValue<2, 2>());
            constexpr auto xAngle = MathType::GetValue(0);

            return EulerType{ EulerResult::NotUniqueDifference, ExtractEulerResultOrder::YZX, xAngle, yAngle, zAngle, MathType::GetValue(0), MathType::GetValue(0), MathType::GetValue(0) };
        }
    }
    else
    {
        // z_angle = +pi/2
        // x_angle + y_angle = atan2(r21,r22)
        // 警告。该解不是唯一的。选择 x_angle = 0.

        constexpr auto zAngle = MathType::GetHalfPI();
        const auto yAngle = MathType::ATan2(GetValue<2, 1>(), GetValue<2, 2>());
        constexpr auto xAngle = MathType::GetValue(0);

        return EulerType{ EulerResult::NotUniqueSum, ExtractEulerResultOrder::YZX, xAngle, yAngle, zAngle, MathType::GetValue(0), MathType::GetValue(0), MathType::GetValue(0) };
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Matrix3<Real>::EulerType Mathematics::Matrix3<Real>::ExtractEulerZXY() const noexcept
{
    // +-           -+   +-                                        -+
    // | r00 r01 r02 |   |  cy*cz-sx*sy*sz  -cx*sz   cz*sy+cy*sx*sz |
    // | r10 r11 r12 | = |  cz*sx*sy+cy*sz   cx*cz  -cy*cz*sx+sy*sz |
    // | r20 r21 r22 |   | -cx*sy            sx      cx*cy          |
    // +-           -+   +-                                        -+

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (GetValue<2, 1>() < MathType::GetValue(1) - MathType::GetZeroTolerance())
    {
        if (MathType::GetValue(-1) + MathType::GetZeroTolerance() < GetValue<2, 1>())
        {
            // x_angle = asin(r21)
            // z_angle = atan2(-r01,r11)
            // y_angle = atan2(-r20,r22)

            const auto xAngle = MathType::ASin(GetValue<2, 1>());
            const auto zAngle = MathType::ATan2(-GetValue<0, 1>(), GetValue<1, 1>());
            const auto yAngle = MathType::ATan2(-GetValue<2, 0>(), GetValue<2, 2>());

            return EulerType{ EulerResult::Unique, ExtractEulerResultOrder::ZXY, xAngle, yAngle, zAngle, MathType::GetValue(0), MathType::GetValue(0), MathType::GetValue(0) };
        }
        else
        {
            // x_angle = -pi/2
            // y_angle - z_angle = atan2(r02,r00)
            // 警告。该解不是唯一的。选择 y_angle = 0.

            constexpr auto xAngle = -MathType::GetHalfPI();
            const auto zAngle = -MathType::ATan2(GetValue<0, 2>(), GetValue<0, 0>());
            constexpr auto yAngle = MathType::GetValue(0);

            return EulerType{ EulerResult::NotUniqueDifference, ExtractEulerResultOrder::ZXY, xAngle, yAngle, zAngle, MathType::GetValue(0), MathType::GetValue(0), MathType::GetValue(0) };
        }
    }
    else
    {
        // x_angle = +pi/2
        // y_angle + z_angle = atan2(r02,r00)
        // 警告。该解不是唯一的。选择 y_angle = 0.

        constexpr auto xAngle = MathType::GetHalfPI();
        const auto zAngle = MathType::ATan2(GetValue<0, 2>(), GetValue<0, 0>());
        constexpr auto yAngle = MathType::GetValue(0);

        return EulerType{ EulerResult::NotUniqueSum, ExtractEulerResultOrder::ZXY, xAngle, yAngle, zAngle, MathType::GetValue(0), MathType::GetValue(0), MathType::GetValue(0) };
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Matrix3<Real>::EulerType Mathematics::Matrix3<Real>::ExtractEulerZYX() const noexcept
{
    // +-           -+   +-                                      -+
    // | r00 r01 r02 |   |  cy*cz  cz*sx*sy-cx*sz  cx*cz*sy+sx*sz |
    // | r10 r11 r12 | = |  cy*sz  cx*cz+sx*sy*sz -cz*sx+cx*sy*sz |
    // | r20 r21 r22 |   | -sy     cy*sx           cx*cy          |
    // +-           -+   +-                                      -+

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (GetValue<2, 0>() < MathType::GetValue(1) - MathType::GetZeroTolerance())
    {
        if (MathType::GetValue(-1) + MathType::GetZeroTolerance() < GetValue<2, 0>())
        {
            // y_angle = asin(-r20)
            // z_angle = atan2(r10,r00)
            // x_angle = atan2(r21,r22)

            const auto yAngle = MathType::ASin(-GetValue<2, 0>());
            const auto zAngle = MathType::ATan2(GetValue<1, 0>(), GetValue<0, 0>());
            const auto xAngle = MathType::ATan2(GetValue<2, 1>(), GetValue<2, 2>());

            return EulerType{ EulerResult::Unique, ExtractEulerResultOrder::ZYX, xAngle, yAngle, zAngle, MathType::GetValue(0), MathType::GetValue(0), MathType::GetValue(0) };
        }
        else
        {
            // y_angle = +pi/2
            // x_angle - z_angle = atan2(r01,r02)
            // 警告。该解不是唯一的。选择 x_angle = 0.

            constexpr auto yAngle = MathType::GetHalfPI();
            const auto zAngle = -MathType::ATan2(GetValue<0, 1>(), GetValue<0, 2>());
            constexpr auto xAngle = MathType::GetValue(0);

            return EulerType{ EulerResult::NotUniqueDifference, ExtractEulerResultOrder::ZYX, xAngle, yAngle, zAngle, MathType::GetValue(0), MathType::GetValue(0), MathType::GetValue(0) };
        }
    }
    else
    {
        // y_angle = -pi/2
        // x_angle + z_angle = atan2(-r01,-r02)
        // 警告。该解不是唯一的。选择 x_angle = 0;

        constexpr auto yAngle = -MathType::GetHalfPI();
        const auto zAngle = MathType::ATan2(-GetValue<0, 1>(), -GetValue<0, 2>());
        constexpr auto xAngle = MathType::GetValue(0);

        return EulerType{ EulerResult::NotUniqueSum, ExtractEulerResultOrder::ZYX, xAngle, yAngle, zAngle, MathType::GetValue(0), MathType::GetValue(0), MathType::GetValue(0) };
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Matrix3<Real>::EulerType Mathematics::Matrix3<Real>::ExtractEulerXYX() const noexcept
{
    // +-           -+   +-                                                -+
    // | r00 r01 r02 |   |  cy      sy*sx1               sy*cx1             |
    // | r10 r11 r12 | = |  sy*sx0  cx0*cx1-cy*sx0*sx1  -cy*cx1*sx0-cx0*sx1 |
    // | r20 r21 r22 |   | -sy*cx0  cx1*sx0+cy*cx0*sx1   cy*cx0*cx1-sx0*sx1 |
    // +-           -+   +-                                                -+

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (GetValue<0, 0>() < MathType::GetValue(1) - MathType::GetZeroTolerance())
    {
        if (MathType::GetValue(-1) + MathType::GetZeroTolerance() < GetValue<0, 0>())
        {
            // y_angle  = acos(r00)
            // x0_angle = atan2(r10,-r20)
            // x1_angle = atan2(r01,r02)

            const auto yAngle = MathType::ACos(GetValue<0, 0>());
            const auto x0Angle = MathType::ATan2(GetValue<1, 0>(), -GetValue<2, 0>());
            const auto x1Angle = MathType::ATan2(GetValue<0, 1>(), GetValue<0, 2>());

            return EulerType{ EulerResult::Unique, ExtractEulerResultOrder::XYX, x0Angle, yAngle, MathType::GetValue(0), x1Angle, MathType::GetValue(0), MathType::GetValue(0) };
        }
        else
        {
            // 该解不是唯一的:  x1_angle - x0_angle = atan2(-r12,r11)

            constexpr auto yAngle = MathType::GetPI();
            const auto x0Angle = -MathType::ATan2(-GetValue<1, 2>(), GetValue<1, 1>());
            constexpr auto x1Angle = MathType::GetValue(0);

            return EulerType{ EulerResult::NotUniqueDifference, ExtractEulerResultOrder::XYX, x0Angle, yAngle, MathType::GetValue(0), x1Angle, MathType::GetValue(0), MathType::GetValue(0) };
        }
    }
    else
    {
        // 该解不是唯一的:  x1_angle + x0_angle = atan2(-r12,r11)
        constexpr auto yAngle = MathType::GetValue(0);
        const auto x0Angle = MathType::ATan2(-GetValue<1, 2>(), GetValue<1, 1>());
        constexpr auto x1Angle = MathType::GetValue(0);

        return EulerType{ EulerResult::NotUniqueSum, ExtractEulerResultOrder::XYX, x0Angle, yAngle, MathType::GetValue(0), x1Angle, MathType::GetValue(0), MathType::GetValue(0) };
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Matrix3<Real>::EulerType Mathematics::Matrix3<Real>::ExtractEulerXZX() const noexcept
{
    // +-           -+   +-                                                -+
    // | r00 r01 r02 |   | cz      -sz*cx1               sz*sx1             |
    // | r10 r11 r12 | = | sz*cx0   cz*cx0*cx1-sx0*sx1  -cx1*sx0-cz*cx0*sx1 |
    // | r20 r21 r22 |   | sz*sx0   cz*cx1*sx0+cx0*sx1   cx0*cx1-cz*sx0*sx1 |
    // +-           -+   +-                                                -+

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (GetValue<0, 0>() < MathType::GetValue(1) - MathType::GetZeroTolerance())
    {
        if (MathType::GetValue(-1) + MathType::GetZeroTolerance() < GetValue<0, 0>())
        {
            // z_angle  = acos(r00)
            // x0_angle = atan2(r20,r10)
            // x1_angle = atan2(r02,-r01)

            const auto zAngle = MathType::ACos(GetValue<0, 0>());
            const auto x0Angle = MathType::ATan2(GetValue<2, 0>(), GetValue<1, 0>());
            const auto x1Angle = MathType::ATan2(GetValue<0, 2>(), -GetValue<0, 1>());

            return EulerType{ EulerResult::Unique, ExtractEulerResultOrder::XZX, x0Angle, MathType::GetValue(0), zAngle, x1Angle, MathType::GetValue(0), MathType::GetValue(0) };
        }
        else
        {
            // 该解不是唯一的:  x1_angle - x0_angle = atan2(r21,r22)

            constexpr auto zAngle = MathType::GetPI();
            const auto x0Angle = -MathType::ATan2(GetValue<2, 1>(), GetValue<2, 2>());
            constexpr auto x1Angle = MathType::GetValue(0);

            return EulerType{ EulerResult::NotUniqueDifference, ExtractEulerResultOrder::XZX, x0Angle, MathType::GetValue(0), zAngle, x1Angle, MathType::GetValue(0), MathType::GetValue(0) };
        }
    }
    else
    {
        // 该解不是唯一的: x1_angle + x0_angle = atan2(r21,r22)

        constexpr auto zAngle = MathType::GetValue(0);
        const auto x0Angle = MathType::ATan2(GetValue<2, 1>(), GetValue<2, 2>());
        constexpr auto x1Angle = MathType::GetValue(0);

        return EulerType{ EulerResult::NotUniqueSum, ExtractEulerResultOrder::XZX, x0Angle, MathType::GetValue(0), zAngle, x1Angle, MathType::GetValue(0), MathType::GetValue(0) };
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Matrix3<Real>::EulerType Mathematics::Matrix3<Real>::ExtractEulerYXY() const noexcept
{
    // +-           -+   +-                                                -+
    // | r00 r01 r02 |   |  cy0*cy1-cx*sy0*sy1  sx*sy0   cx*cy1*sy0+cy0*sy1 |
    // | r10 r11 r12 | = |  sx*sy1              cx      -sx*cy1             |
    // | r20 r21 r22 |   | -cy1*sy0-cx*cy0*sy1  sx*cy0   cx*cy0*cy1-sy0*sy1 |
    // +-           -+   +-                                                -+

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (GetValue<1, 1>() < MathType::GetValue(1) - MathType::GetZeroTolerance())
    {
        if (MathType::GetValue(-1) + MathType::GetZeroTolerance() < GetValue<1, 1>())
        {
            // x_angle  = acos(r11)
            // y0_angle = atan2(r01,r21)
            // y1_angle = atan2(r10,-r12)

            const auto xAngle = MathType::ACos(GetValue<1, 1>());
            const auto y0Angle = MathType::ATan2(GetValue<0, 1>(), GetValue<2, 1>());
            const auto y1Angle = MathType::ATan2(GetValue<1, 0>(), -GetValue<1, 2>());

            return EulerType{ EulerResult::Unique, ExtractEulerResultOrder::YXY, xAngle, y0Angle, MathType::GetValue(0), MathType::GetValue(0), y1Angle, MathType::GetValue(0) };
        }
        else
        {
            // 该解不是唯一的:  y1_angle - y0_angle = atan2(r02,r00)

            constexpr auto xAngle = MathType::GetPI();
            const auto y0Angle = -MathType::ATan2(GetValue<0, 2>(), GetValue<0, 0>());
            constexpr auto y1Angle = MathType::GetValue(0);

            return EulerType{ EulerResult::NotUniqueDifference, ExtractEulerResultOrder::YXY, xAngle, y0Angle, MathType::GetValue(0), MathType::GetValue(0), y1Angle, MathType::GetValue(0) };
        }
    }
    else
    {
        // 该解不是唯一的: y1_angle + y0_angle = atan2(r02,r00)

        constexpr auto xAngle = MathType::GetValue(0);
        const auto y0Angle = MathType::ATan2(GetValue<0, 2>(), GetValue<0, 0>());
        constexpr auto y1Angle = MathType::GetValue(0);

        return EulerType{ EulerResult::NotUniqueSum, ExtractEulerResultOrder::YXY, xAngle, y0Angle, MathType::GetValue(0), MathType::GetValue(0), y1Angle, MathType::GetValue(0) };
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Matrix3<Real>::EulerType Mathematics::Matrix3<Real>::ExtractEulerYZY() const noexcept
{
    // +-           -+   +-                                                -+
    // | r00 r01 r02 |   |  cz*cy0*cy1-sy0*sy1  -sz*cy0  cy1*sy0+cz*cy0*sy1 |
    // | r10 r11 r12 | = |  sz*cy1               cz      sz*sy1             |
    // | r20 r21 r22 |   | -cz*cy1*sy0-cy0*sy1   sz*sy0  cy0*cy1-cz*sy0*sy1 |
    // +-           -+   +-                                                -+

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (GetValue<1, 1>() < MathType::GetValue(1) - MathType::GetZeroTolerance())
    {
        if (MathType::GetValue(-1) + MathType::GetZeroTolerance() < GetValue<1, 1>())
        {
            // z_angle  = acos(r11)
            // y0_angle = atan2(r21,-r01)
            // y1_angle = atan2(r12,r10)

            const auto zAngle = MathType::ACos(GetValue<1, 1>());
            const auto y0Angle = MathType::ATan2(GetValue<2, 1>(), -GetValue<0, 1>());
            const auto y1Angle = MathType::ATan2(GetValue<1, 2>(), GetValue<1, 0>());

            return EulerType{ EulerResult::Unique, ExtractEulerResultOrder::YZY, MathType::GetValue(0), y0Angle, zAngle, MathType::GetValue(0), y1Angle, MathType::GetValue(0) };
        }
        else
        {
            // 该解不是唯一的:  y1_angle - y0_angle = atan2(-r20,r22)

            constexpr auto zAngle = MathType::GetPI();
            const auto y0Angle = -MathType::ATan2(-GetValue<2, 0>(), GetValue<2, 2>());
            constexpr auto y1Angle = MathType::GetValue(0);

            return EulerType{ EulerResult::NotUniqueDifference, ExtractEulerResultOrder::YZY, MathType::GetValue(0), y0Angle, zAngle, MathType::GetValue(0), y1Angle, MathType::GetValue(0) };
        }
    }
    else
    {
        // 该解不是唯一的:  y1_angle + y0_angle = atan2(-r20,r22)

        constexpr auto zAngle = MathType::GetValue(0);
        const auto y0Angle = MathType::ATan2(-GetValue<2, 0>(), GetValue<2, 2>());
        constexpr auto y1Angle = MathType::GetValue(0);

        return EulerType{ EulerResult::NotUniqueSum, ExtractEulerResultOrder::YZY, MathType::GetValue(0), y0Angle, zAngle, MathType::GetValue(0), y1Angle, MathType::GetValue(0) };
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Matrix3<Real>::EulerType Mathematics::Matrix3<Real>::ExtractEulerZXZ() const noexcept
{
    // +-           -+   +-                                                -+
    // | r00 r01 r02 |   | cz0*cz1-cx*sz0*sz1  -cx*cz1*sz0-cz0*sz1   sx*sz0 |
    // | r10 r11 r12 | = | cz1*sz0+cx*cz0*sz1   cx*cz0*cz1-sz0*sz1  -sz*cz0 |
    // | r20 r21 r22 |   | sx*sz1               sx*cz1               cx     |
    // +-           -+   +-                                                -+

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (GetValue<2, 2>() < MathType::GetValue(1) - MathType::GetZeroTolerance())
    {
        if (MathType::GetValue(-1) + MathType::GetZeroTolerance() < GetValue<2, 2>())
        {
            // x_angle  = acos(r22)
            // z0_angle = atan2(r02,-r12)
            // z1_angle = atan2(r20,r21)

            const auto xAngle = MathType::ACos(GetValue<2, 2>());
            const auto z0Angle = MathType::ATan2(GetValue<0, 2>(), -GetValue<1, 2>());
            const auto z1Angle = MathType::ATan2(GetValue<2, 0>(), GetValue<2, 1>());

            return EulerType{ EulerResult::Unique, ExtractEulerResultOrder::ZXZ, xAngle, MathType::GetValue(0), z0Angle, MathType::GetValue(0), MathType::GetValue(0), z1Angle };
        }
        else
        {
            // 该解不是唯一的:  z1_angle - z0_angle = atan2(-r01,r00)

            constexpr auto xAngle = MathType::GetPI();
            const auto z0Angle = -MathType::ATan2(-GetValue<0, 1>(), GetValue<0, 0>());
            constexpr auto z1Angle = MathType::GetValue(0);

            return EulerType{ EulerResult::NotUniqueDifference, ExtractEulerResultOrder::ZXZ, xAngle, MathType::GetValue(0), z0Angle, MathType::GetValue(0), MathType::GetValue(0), z1Angle };
        }
    }
    else
    {
        // 该解不是唯一的: z1_angle + z0_angle = atan2(-r01,r00)

        constexpr auto xAngle = MathType::GetValue(0);
        const auto z0Angle = MathType::ATan2(-GetValue<0, 1>(), GetValue<0, 0>());
        constexpr auto z1Angle = MathType::GetValue(0);

        return EulerType{ EulerResult::NotUniqueSum, ExtractEulerResultOrder::ZXZ, xAngle, MathType::GetValue(0), z0Angle, MathType::GetValue(0), MathType::GetValue(0), z1Angle };
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Matrix3<Real>::EulerType Mathematics::Matrix3<Real>::ExtractEulerZYZ() const noexcept
{
    // +-           -+   +-                                                -+
    // | r00 r01 r02 |   |  cy*cz0*cz1-sz0*sz1  -cz1*sz0-cy*cz0*sz1  sy*cz0 |
    // | r10 r11 r12 | = |  cy*cz1*sz0+cz0*sz1   cz0*cz1-cy*sz0*sz1  sy*sz0 |
    // | r20 r21 r22 |   | -sy*cz1               sy*sz1              cy     |
    // +-           -+   +-                                                -+

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (GetValue<2, 2>() < MathType::GetValue(1) - MathType::GetZeroTolerance())
    {
        if (MathType::GetValue(-1) + MathType::GetZeroTolerance() < GetValue<2, 2>())
        {
            // y_angle  = acos(r22)
            // z0_angle = atan2(r12,r02)
            // z1_angle = atan2(r21,-r20)

            const auto yAngle = MathType::ACos(GetValue<2, 2>());
            const auto z0Angle = MathType::ATan2(GetValue<1, 2>(), GetValue<0, 2>());
            const auto z1Angle = MathType::ATan2(GetValue<2, 1>(), -GetValue<2, 0>());

            return EulerType{ EulerResult::Unique, ExtractEulerResultOrder::ZYZ, MathType::GetValue(0), yAngle, z0Angle, MathType::GetValue(0), MathType::GetValue(0), z1Angle };
        }
        else  // r22 = -1
        {
            // 该解不是唯一的:  z1_angle - z0_angle = atan2(r10,r11)

            constexpr auto yAngle = MathType::GetPI();
            const auto z0Angle = -MathType::ATan2(GetValue<1, 0>(), GetValue<1, 1>());
            constexpr auto z1Angle = MathType::GetValue(0);

            return EulerType{ EulerResult::NotUniqueDifference, ExtractEulerResultOrder::ZYZ, MathType::GetValue(0), yAngle, z0Angle, MathType::GetValue(0), MathType::GetValue(0), z1Angle };
        }
    }
    else  // r22 = +1
    {
        // 该解不是唯一的: z1_angle + z0_angle = atan2(r10,r11)

        constexpr auto yAngle = MathType::GetValue(0);
        const auto z0Angle = MathType::ATan2(GetValue<1, 0>(), GetValue<1, 1>());
        constexpr auto z1Angle = MathType::GetValue(0);

        return EulerType{ EulerResult::NotUniqueSum, ExtractEulerResultOrder::ZYZ, MathType::GetValue(0), yAngle, z0Angle, MathType::GetValue(0), MathType::GetValue(0), z1Angle };
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix3<Real>::Slerp(Real t, const Matrix3& rot0, const Matrix3& rot1) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto prod = TransposeTimes(rot0, rot1);

    const auto extract = prod.ExtractAngleAxis();

    const auto axis = extract.GetAxis();
    const auto angle = extract.GetAngle();

    MakeRotation(axis, t * angle);

    *this = rot0 * (*this);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Matrix3<Real>::ArrayType Mathematics::Matrix3<Real>::GetCoordinate() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ArrayType{ x.GetX(),
                      x.GetY(),
                      x.GetZ(),
                      y.GetX(),
                      y.GetY(),
                      y.GetZ(),
                      z.GetX(),
                      z.GetY(),
                      z.GetZ() };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Matrix3<Real>::ContainerType Mathematics::Matrix3<Real>::GetContainer() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ContainerType{ x.GetX(),
                          x.GetY(),
                          x.GetZ(),
                          y.GetX(),
                          y.GetY(),
                          y.GetZ(),
                          z.GetX(),
                          z.GetY(),
                          z.GetZ() };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix3<Real>::Set(const ArrayType& coordinate)
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
requires std::is_arithmetic_v<Real>
Mathematics::Matrix4<Real> Mathematics::Matrix3<Real>::Lift() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Matrix4Type result{ MatrixInitType::Identity };

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
Mathematics::Matrix2<Real> Mathematics::Matrix3<Real>::Project() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Matrix2Type result{ MatrixInitType::Zero };

    for (auto r = 0; r < Matrix2Type::vectorSize; ++r)
    {
        for (auto c = 0; c < Matrix2Type::vectorSize; ++c)
        {
            result(r, c) = (*this)(r, c);
        }
    }

    return result;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Matrix3<Real>::Trace() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetValue<0, 0>() + GetValue<1, 1>() + GetValue<2, 2>();
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX3_ACHIEVE_H
