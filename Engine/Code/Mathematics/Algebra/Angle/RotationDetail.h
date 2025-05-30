﻿///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/18 17:26)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_ROTATION_DETAIL_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_ROTATION_DETAIL_H

#include "AxisAngleDetail.h"
#include "EulerAnglesDetail.h"
#include "Rotation.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Flags/RotationType.h"
#include "Mathematics/Algebra/Matrix/MatrixDetail.h"
#include "Mathematics/Algebra/QuaternionDetail.h"

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Rotation<N, Real>::Rotation(const MatrixType& matrix) noexcept
    : rotationType{ RotationType::IsMatrix },
      matrix{ matrix },
      quaternion{},
      axisAngle{},
      eulerAngles{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Rotation<N, Real>::Rotation(const QuaternionType& quaternion) noexcept
    : rotationType{ RotationType::IsQuaternion },
      matrix{},
      quaternion{ quaternion },
      axisAngle{},
      eulerAngles{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Rotation<N, Real>::Rotation(const AxisAngleType& axisAngle) noexcept
    : rotationType{ RotationType::IsAxisAngle },
      matrix{},
      quaternion{},
      axisAngle{ axisAngle },
      eulerAngles{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Rotation<N, Real>::Rotation(const EulerAnglesType& eulerAngles) noexcept
    : rotationType{ RotationType::IsEulerAngles },
      matrix{},
      quaternion{},
      axisAngle{},
      eulerAngles{ eulerAngles }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::Rotation<N, Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Rotation<N, Real>::operator Mathematics::Algebra::Matrix<N, N, Real>()
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    switch (rotationType)
    {
        case RotationType::IsMatrix:
            break;
        case RotationType::IsQuaternion:
            this->Convert(quaternion, matrix);
            break;
        case RotationType::IsAxisAngle:
            this->Convert(axisAngle, matrix);
            break;
        case RotationType::IsEulerAngles:
            this->Convert(eulerAngles, matrix);
            break;
        default:
            break;
    }

    return matrix;
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Rotation<N, Real>::operator Mathematics::Quaternion<Real>()
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    switch (rotationType)
    {
        case RotationType::IsMatrix:
            this->Convert(matrix, quaternion);
            break;
        case RotationType::IsQuaternion:
            break;
        case RotationType::IsAxisAngle:
            this->Convert(axisAngle, quaternion);
            break;
        case RotationType::IsEulerAngles:
            this->Convert(eulerAngles, quaternion);
            break;
        default:
            break;
    }

    return quaternion;
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Rotation<N, Real>::operator Mathematics::Algebra::AxisAngle<N, Real>()
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    switch (rotationType)
    {
        case RotationType::IsMatrix:
            this->Convert(matrix, axisAngle);
            break;
        case RotationType::IsQuaternion:
            this->Convert(quaternion, axisAngle);
            break;
        case RotationType::IsAxisAngle:
            break;
        case RotationType::IsEulerAngles:
            this->Convert(eulerAngles, axisAngle);
            break;
        default:
            break;
    }

    return axisAngle;
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::Rotation<N, Real>::EulerAnglesType Mathematics::Algebra::Rotation<N, Real>::operator()(int axis0, int axis1, int axis2)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    eulerAngles.SetAxis(axis0, axis1, axis2);

    switch (rotationType)
    {
        case RotationType::IsMatrix:
            this->Convert(matrix, eulerAngles);
            break;
        case RotationType::IsQuaternion:
            this->Convert(quaternion, eulerAngles);
            break;
        case RotationType::IsAxisAngle:
            this->Convert(axisAngle, eulerAngles);
            break;
        case RotationType::IsEulerAngles:
            break;
        default:
            break;
    }

    return eulerAngles;
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Rotation<N, Real>::Convert(const MatrixType& matrix, QuaternionType& quaternion)
{
    const auto r22 = matrix(2, 2);
    if (r22 <= Real{})  /// x^2 + y^2 >= z^2 + w^2
    {
        const auto dif10 = matrix(1, 1) - matrix(0, 0);
        const auto oneMinusR22 = MathType::GetValue(1) - r22;
        if (dif10 <= Real{})  /// x^2 >= y^2
        {
            const auto fourXSqr = oneMinusR22 - dif10;
            const auto inverse4X = MathType::GetRational(1, 2) / MathType::Sqrt(fourXSqr);

            quaternion[QuaternionType::xIndex] = fourXSqr * inverse4X;
            quaternion[QuaternionType::yIndex] = (matrix(0, 1) + matrix(1, 0)) * inverse4X;
            quaternion[QuaternionType::zIndex] = (matrix(0, 2) + matrix(2, 0)) * inverse4X;

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

            quaternion[QuaternionType::wIndex] = (matrix(2, 1) - matrix(1, 2)) * inverse4X;

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

            quaternion[Quaternion::wIndex] = (matrix(1, 2) - matrix(2, 1)) * inverse4X;

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
        }
        else  /// y^2 >= x^2
        {
            const auto fourYSqr = oneMinusR22 + dif10;
            const auto inverse4Y = MathType::GetRational(1, 2) / MathType::Sqrt(fourYSqr);

            quaternion[QuaternionType::xIndex] = (matrix(0, 1) + matrix(1, 0)) * inverse4Y;
            quaternion[QuaternionType::yIndex] = fourYSqr * inverse4Y;
            quaternion[QuaternionType::zIndex] = (matrix(1, 2) + matrix(2, 1)) * inverse4Y;

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

            quaternion[QuaternionType::wIndex] = (matrix(0, 2) - matrix(2, 0)) * inverse4Y;

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

            quaternion[Quaternion::wIndex] = (matrix(2, 0) - matrix(0, 2)) * inverse4Y;

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
        }
    }
    else  /// z^2 + w^2 >= x^2 + y^2
    {
        const auto sum10 = matrix(1, 1) + matrix(0, 0);
        const auto onePlusR22 = MathType::GetValue(1) + r22;
        if (sum10 <= Real{})  /// z^2 >= w^2
        {
            const auto fourZSqr = onePlusR22 - sum10;
            const auto inverse4Z = MathType::GetRational(1, 2) / MathType::Sqrt(fourZSqr);
            quaternion[QuaternionType::xIndex] = (matrix(0, 2) + matrix(2, 0)) * inverse4Z;
            quaternion[QuaternionType::yIndex] = (matrix(1, 2) + matrix(2, 1)) * inverse4Z;
            quaternion[QuaternionType::zIndex] = fourZSqr * inverse4Z;

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

            quaternion[QuaternionType::wIndex] = (matrix(1, 0) - matrix(0, 1)) * inverse4Z;

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

            quaternion[Quaternion::wIndex] = (matrix(0, 1) - matrix(1, 0)) * inverse4Z;

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
        }
        else  /// w^2 >= z^2
        {
            const auto fourWSqr = onePlusR22 + sum10;
            const auto inverse4W = MathType::GetRational(1, 2) / MathType::Sqrt(fourWSqr);

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

            quaternion[QuaternionType::xIndex] = (matrix(2, 1) - matrix(1, 2)) * inverse4W;
            quaternion[QuaternionType::yIndex] = (matrix(0, 2) - matrix(2, 0)) * inverse4W;
            quaternion[QuaternionType::zIndex] = (matrix(1, 0) - matrix(0, 1)) * inverse4W;

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

            quaternion[Quaternion::xIndex] = (matrix(1, 2) - matrix(2, 1)) * inverse4W;
            quaternion[Quaternion::yIndex] = (matrix(2, 0) - matrix(0, 2)) * inverse4W;
            quaternion[Quaternion::zIndex] = (matrix(0, 1) - matrix(1, 0)) * inverse4W;

#endif  // MATHEMATICS_USE_MATRIX_VECTOR

            quaternion[QuaternionType::wIndex] = fourWSqr * inverse4W;
        }
    }
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Rotation<N, Real>::Convert(const MatrixType& matrix, AxisAngleType& axisAngle)
{
    const auto trace = matrix(0, 0) + matrix(1, 1) + matrix(2, 2);
    constexpr auto half = MathType::GetRational(1, 2);
    const auto cs = half * (trace - MathType::GetValue(1));

    axisAngle.SetAngle(MathType::ACos(cs));  // 角度以[0,pi]为单位
    axisAngle.MakeAxisZero();

    if (Real{} < axisAngle.GetAngle())
    {
        if (axisAngle.GetAngle() < MathType::GetPI())
        {
            // 角度在(0,pi).
#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

            typename AxisAngleType::VectorType axis{};

            axis[0] = matrix(2, 1) - matrix(1, 2);
            axis[1] = matrix(0, 2) - matrix(2, 0);
            axis[2] = matrix(1, 0) - matrix(0, 1);

            Normalize(axis);

            axisAngle.SetAxis(axis);

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

            typename AxisAngle::Vector axis{};

            axis[0] = matrix(1, 2) - matrix(2, 1);
            axis[1] = matrix(2, 0) - matrix(0, 2);
            axis[2] = matrix(0, 1) - matrix(1, 0);

            Normalize(axis);

            axisAngle.SetAxis(axis);

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
        }
        else
        {
            /// 角度为pi，在这种情况下R是对称的，
            /// R+I = 2*(I+S^2) = 2*U*U^T，
            /// 其中U = (u0,u1,u2)是旋转轴的单位长度方向。
            /// 确定R+I的最大对角线条目，并归一化相应的行以产生U。
            /// 对于所选对角线d，u[d]上的符号无关紧要，因为R(U,pi) = R(-U,pi)。
            typename AxisAngleType::VectorType axis{};

            if (matrix(1, 1) <= matrix(0, 0))
            {
                if (matrix(2, 2) <= matrix(0, 0))
                {
                    /// r00是最大对角线项
                    axis[0] = matrix(0, 0) + MathType::GetValue(1);
                    axis[1] = half * (matrix(0, 1) + matrix(1, 0));
                    axis[2] = half * (matrix(0, 2) + matrix(2, 0));
                }
                else
                {
                    // r22是最大对角线项
                    axis[0] = half * (matrix(2, 0) + matrix(0, 2));
                    axis[1] = half * (matrix(2, 1) + matrix(1, 2));
                    axis[2] = matrix(2, 2) + MathType::GetValue(1);
                }
            }
            else
            {
                if (matrix(2, 2) <= matrix(1, 1))
                {
                    // r11是最大对角线项
                    axis[0] = half * (matrix(1, 0) + matrix(0, 1));
                    axis[1] = matrix(1, 1) + MathType::GetValue(1);
                    axis[2] = half * (matrix(1, 2) + matrix(2, 1));
                }
                else
                {
                    // r22是最大对角线项
                    axis[0] = half * (matrix(2, 0) + matrix(0, 2));
                    axis[1] = half * (matrix(2, 1) + matrix(1, 2));
                    axis[2] = matrix(2, 2) + MathType::GetValue(1);
                }
            }

            Normalize(axis);
            axisAngle.SetAxis(axis);
        }
    }
    else
    {
        /// 角度为0，矩阵为单位。
        /// 任何轴都可以工作，因此选择Unit(0)轴。
        axisAngle.SetAxis(AxisAngleType::VectorType::GetUnit(0));
    }
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Rotation<N, Real>::Convert(const MatrixType& matrix, EulerAnglesType& eulerAngles)
{
    if (eulerAngles.AxisIsEffective())
    {
        const auto axis0 = eulerAngles.GetAxis(0);
        const auto axis1 = eulerAngles.GetAxis(1);
        const auto axis2 = eulerAngles.GetAxis(2);

        if (axis0 != axis2)
        {
#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

            /// 将(0,1,2), (1,2,0)和(2,0,1)映射到+1。
            /// 将(0,2,1), (2,1,0)和(1,0,2)映射到-1。
            const auto parity = (((axis2 | (axis1 << 2)) >> axis0) & 1);
            const auto symbol = (parity & 1 ? MathType::GetValue(-1) : MathType::GetValue(1));

            if (matrix(axis2, axis0) < MathType::GetValue(1))
            {
                if (MathType::GetValue(-1) < matrix(axis2, axis0))
                {
                    const auto angle2 = MathType::ATan2(symbol * matrix(axis1, axis0), matrix(axis0, axis0));
                    const auto angle1 = MathType::ASin(-symbol * matrix(axis2, axis0));
                    const auto angle0 = MathType::ATan2(symbol * matrix(axis2, axis1), matrix(axis2, axis2));

                    eulerAngles.SetAngle(angle0, angle1, angle2);
                    eulerAngles.SetEulerResult(EulerResult::Unique);
                }
                else
                {
                    constexpr auto angle2 = Real{};
                    const auto angle1 = symbol * MathType::GetHalfPI();
                    const auto angle0 = MathType::ATan2(-symbol * matrix(axis1, axis2), matrix(axis1, axis1));

                    eulerAngles.SetAngle(angle0, angle1, angle2);
                    eulerAngles.SetEulerResult(EulerResult::NotUniqueDifference);
                }
            }
            else
            {
                constexpr auto angle2 = Real{};
                const auto angle1 = symbol * MathType::GetHalfPI();
                const auto angle0 = MathType::ATan2(-symbol * matrix(axis1, axis2), matrix(axis1, axis1));

                eulerAngles.SetAngle(angle0, angle1, angle2);
                eulerAngles.SetEulerResult(EulerResult::NotUniqueSum);
            }

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

            /// 将(0,1,2), (1,2,0)和(2,0,1)映射到+1。
            /// 将(0,2,1), (2,1,0)和(1,0,2)映射到-1。
            const auto parity = (((axis0 | (axis1 << 2)) >> axis2) & 1);
            const auto symbol = (parity & 1 ? MathType::GetValue(1) : MathType::GetValue(-1));

            if (matrix(axis0, axis2) < MathType::GetValue(1))
            {
                if (MathType::GetValue(-1) < matrix(axis0, axis2))
                {
                    const auto angle0 = MathType::ATan2(symbol * matrix(axis1, axis2), matrix(axis2, axis2));
                    const auto angle1 = MathType::ASin(-symbol * matrix(axis0, axis2));
                    const auto angle2 = MathType::ATan2(symbol * matrix(axis0, axis1), matrix(axis0, axis0));

                    eulerAngles.SetAngle(angle0, angle1, angle2);
                    eulerAngles.SetEulerResult(EulerResult::Unique);
                }
                else
                {
                    constexpr auto angle0 = Real{};
                    const auto angle1 = symbol * MathType::GetHalfPI();
                    const auto angle2 = MathType::ATan2(-symbol * matrix(axis1, axis0), matrix(axis1, axis1));

                    eulerAngles.SetAngle(angle0, angle1, angle2);
                    eulerAngles.SetEulerResult(EulerResult::NotUniqueDifference);
                }
            }
            else
            {
                constexpr auto angle0 = Real{};
                const auto angle1 = symbol * MathType::GetHalfPI();
                const auto angle2 = MathType::ATan2(-symbol * matrix(axis1, axis0), matrix(axis1, axis1));

                eulerAngles.SetAngle(angle0, angle1, angle2);
                eulerAngles.SetEulerResult(EulerResult::NotUniqueSum);
            }

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
        }
        else
        {
#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

            /// 将(0,2,0), (1,0,1)和(2,1,2)映射到+1。
            /// 将(0,1,0), (1,2,1)和(2,0,2)映射到-1。
            const auto b0 = 3 - axis1 - axis2;
            const auto parity = (((b0 | (axis1 << 2)) >> axis2) & 1);
            const auto symbol = (parity & 1 ? MathType::GetValue(1) : MathType::GetValue(-1));

            if (matrix(axis2, axis2) < MathType::GetValue(1))
            {
                if (MathType::GetValue(-1) < matrix(axis2, axis2))
                {
                    const auto angle2 = MathType::ATan2(matrix(axis1, axis2), symbol * matrix(b0, axis2));
                    const auto angle1 = MathType::ACos(matrix(axis2, axis2));
                    const auto angle0 = MathType::ATan2(matrix(axis2, axis1), -symbol * matrix(axis2, b0));

                    eulerAngles.SetAngle(angle0, angle1, angle2);
                    eulerAngles.SetEulerResult(EulerResult::Unique);
                }
                else
                {
                    constexpr auto angle2 = Real{};
                    constexpr auto angle1 = MathType::GetPI();
                    const auto angle0 = MathType::ATan2(symbol * matrix(axis1, b0), matrix(axis1, axis1));

                    eulerAngles.SetAngle(angle0, angle1, angle2);
                    eulerAngles.SetEulerResult(EulerResult::NotUniqueDifference);
                }
            }
            else
            {
                constexpr auto angle2 = Real{};
                constexpr auto angle1 = Real{};
                const auto angle0 = MathType::ATan2(symbol * matrix(axis1, b0), matrix(axis1, axis1));

                eulerAngles.SetAngle(angle0, angle1, angle2);
                eulerAngles.SetEulerResult(EulerResult::NotUniqueSum);
            }

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

            /// 将(0,2,0), (1,0,1)和(2,1,2)映射到-1。
            /// 将(0,1,0), (1,2,1)和(2,0,2)映射到+1。
            const auto b2 = 3 - axis0 - axis1;
            const auto parity = (((b2 | (axis1 << 2)) >> axis0) & 1);
            const auto symbol = (parity & 1 ? MathType::GetValue(-1) : MathType::GetValue(1));

            if (matrix(axis0, axis0) < MathType::GetValue(1))
            {
                if (MathType::GetValue(-1) < matrix(axis0, axis0))
                {
                    const auto angle0 = MathType::ATan2(matrix(axis1, axis0), symbol * matrix(b2, axis0));
                    const auto angle1 = MathType::ACos(matrix(axis0, axis0));
                    const auto angle2 = MathType::ATan2(matrix(axis0, axis1), -symbol * matrix(axis0, b2));

                    eulerAngles.SetAngle(angle0, angle1, angle2);
                    eulerAngles.SetEulerResult(EulerResult::Unique);
                }
                else
                {
                    constexpr auto angle0 = Real{};
                    constexpr auto angle1 = MathType::GetPI();
                    const auto angle2 = MathType::ATan2(symbol * matrix(axis1, b2), matrix(axis1, axis1));

                    eulerAngles.SetAngle(angle0, angle1, angle2);
                    eulerAngles.SetEulerResult(EulerResult::NotUniqueDifference);
                }
            }
            else
            {
                constexpr auto angle0 = Real{};
                constexpr auto angle1 = Real{};
                const auto angle2 = MathType::ATan2(symbol * matrix(axis1, b2), matrix(axis1, axis1));

                eulerAngles.SetAngle(angle0, angle1, angle2);
                eulerAngles.SetEulerResult(EulerResult::NotUniqueSum);
            }

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
        }
    }
    else
    {
        /// 角度无效。
        eulerAngles.SetAngle(Real{}, Real{}, Real{});
        eulerAngles.SetEulerResult(EulerResult::Invalid);
    }
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Rotation<N, Real>::Convert(const QuaternionType& quaternion, MatrixType& matrix)
{
    matrix.MakeIdentity();

    const auto twoX = MathType::GetValue(2) * quaternion[QuaternionType::xIndex];
    const auto twoY = MathType::GetValue(2) * quaternion[QuaternionType::yIndex];
    const auto twoZ = MathType::GetValue(2) * quaternion[QuaternionType::zIndex];
    const auto twoXX = twoX * quaternion[QuaternionType::xIndex];
    const auto twoXY = twoX * quaternion[QuaternionType::yIndex];
    const auto twoXZ = twoX * quaternion[QuaternionType::zIndex];
    const auto twoXW = twoX * quaternion[QuaternionType::wIndex];
    const auto twoYY = twoY * quaternion[QuaternionType::yIndex];
    const auto twoYZ = twoY * quaternion[QuaternionType::zIndex];
    const auto twoYW = twoY * quaternion[QuaternionType::wIndex];
    const auto twoZZ = twoZ * quaternion[QuaternionType::zIndex];
    const auto twoZW = twoZ * quaternion[QuaternionType::wIndex];

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    matrix(0, 0) = MathType::GetValue(1) - twoYY - twoZZ;
    matrix(0, 1) = twoXY - twoZW;
    matrix(0, 2) = twoXZ + twoYW;
    matrix(1, 0) = twoXY + twoZW;
    matrix(1, 1) = MathType::GetValue(1) - twoXX - twoZZ;
    matrix(1, 2) = twoYZ - twoXW;
    matrix(2, 0) = twoXZ - twoYW;
    matrix(2, 1) = twoYZ + twoXW;
    matrix(2, 2) = MathType::GetValue(1) - twoXX - twoYY;

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    matrix(0, 0) = MathType::GetValue(1) - twoYY - twoZZ;
    matrix(1, 0) = twoXY - twoZW;
    matrix(2, 0) = twoXZ + twoYW;
    matrix(0, 1) = twoXY + twoZW;
    matrix(1, 1) = MathType::GetValue(1) - twoXX - twoZZ;
    matrix(2, 1) = twoYZ - twoXW;
    matrix(0, 2) = twoXZ - twoYW;
    matrix(1, 2) = twoYZ + twoXW;
    matrix(2, 2) = MathType::GetValue(1) - twoXX - twoYY;

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Rotation<N, Real>::Convert(const QuaternionType& quaternion, AxisAngleType& axisAngle)
{
    const auto axisSqrLen = quaternion[QuaternionType::xIndex] * quaternion[QuaternionType::xIndex] + quaternion[QuaternionType::yIndex] * quaternion[QuaternionType::yIndex] + quaternion[QuaternionType::zIndex] * quaternion[QuaternionType::zIndex];
    if (MathType::GetValue(0) < axisSqrLen)
    {
#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

        const auto adjust = MathType::GetValue(1) / MathType::Sqrt(axisSqrLen);

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

        const auto adjust = MathType::GetValue(-1) / MathType::Sqrt(axisSqrLen);

#endif  // MATHEMATICS_USE_MATRIX_VECTOR

        typename AxisAngleType::VectorType axis{};
        axis[0] = quaternion[QuaternionType::xIndex] * adjust;
        axis[1] = quaternion[QuaternionType::yIndex] * adjust;
        axis[2] = quaternion[QuaternionType::zIndex] * adjust;

        const auto angle = MathType::GetValue(2) * MathType::ACos(quaternion[QuaternionType::wIndex]);

        axisAngle.SetAxis(axis);
        axisAngle.SetAngle(angle);
    }
    else
    {
        /// 角度为0（模2*pi）。
        /// 任何轴都可以工作，因此选择Unit(0)轴。
        axisAngle.SetAxis(AxisAngleType::VectorType::GetUnit(0));
        axisAngle.SetAngle(Real{});
    }
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Rotation<N, Real>::Convert(const QuaternionType& quaternion, EulerAnglesType& eulerAngles)
{
    MatrixType matrix{};

    Convert(quaternion, matrix);
    Convert(matrix, eulerAngles);
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Rotation<N, Real>::Convert(const AxisAngleType& axisAngle, MatrixType& matrix)
{
    matrix.MakeIdentity();

    const auto cs = std::cos(axisAngle.GetAngle());
    const auto sn = std::sin(axisAngle.GetAngle());
    const auto axis = axisAngle.GetAxis();
    const auto oneMinusCos = MathType::GetValue(1) - cs;
    const auto x0Sqr = axis[0] * axis[0];
    const auto x1Sqr = axis[1] * axis[1];
    const auto x2Sqr = axis[2] * axis[2];
    const auto x0X1M = axis[0] * axis[1] * oneMinusCos;
    const auto x0X2M = axis[0] * axis[2] * oneMinusCos;
    const auto x1X2M = axis[1] * axis[2] * oneMinusCos;
    const auto x0Sin = axis[0] * sn;
    const auto x1Sin = axis[1] * sn;
    const auto x2Sin = axis[2] * sn;

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    matrix(0, 0) = x0Sqr * oneMinusCos + cs;
    matrix(0, 1) = x0X1M - x2Sin;
    matrix(0, 2) = x0X2M + x1Sin;
    matrix(1, 0) = x0X1M + x2Sin;
    matrix(1, 1) = x1Sqr * oneMinusCos + cs;
    matrix(1, 2) = x1X2M - x0Sin;
    matrix(2, 0) = x0X2M - x1Sin;
    matrix(2, 1) = x1X2M + x0Sin;
    matrix(2, 2) = x2Sqr * oneMinusCos + cs;

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    matrix(0, 0) = x0Sqr * oneMinusCos + cs;
    matrix(1, 0) = x0X1M - x2Sin;
    matrix(2, 0) = x0X2M + x1Sin;
    matrix(0, 1) = x0X1M + x2Sin;
    matrix(1, 1) = x1Sqr * oneMinusCos + cs;
    matrix(2, 1) = x1X2M - x0Sin;
    matrix(0, 2) = x0X2M - x1Sin;
    matrix(1, 2) = x1X2M + x0Sin;
    matrix(2, 2) = x2Sqr * oneMinusCos + cs;

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Rotation<N, Real>::Convert(const AxisAngleType& axisAngle, QuaternionType& quaternion)
{
#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    const auto halfAngle = MathType::GetRational(1, 2) * axisAngle.GetAngle();

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    const auto halfAngle = MathType::GetRational(-1, 2) * axisAngle.GetAngle();

#endif  // MATHEMATICS_USE_MATRIX_VECTOR

    const auto sn = MathType::Sin(halfAngle);
    const auto axis = axisAngle.GetAxis();

    quaternion[QuaternionType::xIndex] = sn * axis[0];
    quaternion[QuaternionType::yIndex] = sn * axis[1];
    quaternion[QuaternionType::zIndex] = sn * axis[2];
    quaternion[QuaternionType::wIndex] = MathType::Cos(halfAngle);
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Rotation<N, Real>::Convert(const AxisAngleType& axisAngle, EulerAnglesType& eulerAngles)
{
    QuaternionType quaternion{};

    Convert(axisAngle, quaternion);
    Convert(quaternion, eulerAngles);
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Rotation<N, Real>::Convert(const EulerAnglesType& eulerAngles, MatrixType& matrix)
{
    if (eulerAngles.AxisIsEffective())
    {
        MatrixType r0{};
        MatrixType r1{};
        MatrixType r2{};

        Convert(AxisAngle(Vector<N, Real>::GetUnit(eulerAngles.GetAxis(0)), eulerAngles.GetAngle(0)), r0);
        Convert(AxisAngle(Vector<N, Real>::GetUnit(eulerAngles.GetAxis(1)), eulerAngles.GetAngle(1)), r1);
        Convert(AxisAngle(Vector<N, Real>::GetUnit(eulerAngles.GetAxis(2)), eulerAngles.GetAngle(2)), r2);

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

        matrix = r2 * r1 * r0;

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

        matrix = r0 * r1 * r2;

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
    }
    else
    {
        // 角度无效。
        matrix.MakeIdentity();
    }
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Rotation<N, Real>::Convert(const EulerAnglesType& eulerAngles, QuaternionType& quaternion)
{
    MatrixType matrix{};

    Convert(eulerAngles, matrix);
    Convert(matrix, quaternion);
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Rotation<N, Real>::Convert(const EulerAnglesType& eulerAngles, AxisAngleType& axisAngle)
{
    QuaternionType quaternion{};

    Convert(eulerAngles, quaternion);
    Convert(quaternion, axisAngle);
}

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_ROTATION_DETAIL_H
