/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/02/03 18:20)

#ifndef MATHEMATICS_ALGEBRA_QUATERNION_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_QUATERNION_ACHIEVE_H

#include "Matrix3.h"
#include "Quaternion.h"
#include "QuaternionFactorDetail.h"
#include "QuaternionSwingTwistDetail.h"
#include "Vector/Vector3Detail.h"
#include "Vector/VectorDetail.h"
#include "Vector3ToolsDetail.h"
#include "Vector4Detail.h"
#include "Vector4ToolsDetail.h"
#include "Flags/QuaternionFlags.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Estimate/ChebyshevRatioDetail.h"

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real>::Quaternion(const Matrix3& matrix)
    : w{}, x{}, y{}, z{}
{
    FromRotationMatrix(matrix);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Quaternion<Real>::FromRotationMatrix(const Matrix3& matrix)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    /// 算法在Ken Shoemake的文章，在1987年SIGGRAPH课程文章“四元微积分和快速动画”。
    const auto trace = matrix.template GetValue<0, 0>() + matrix.template GetValue<1, 1>() + matrix.template GetValue<2, 2>();

    if (Math::GetValue(0) < trace)
    {
        // |w| > 1/2, 可能选择 w > 1/2
        auto root = Math::Sqrt(trace + Math::GetValue(1));  // 2w

        w = Math::GetRational(1, 2) * root;
        root = Math::GetRational(1, 2) / root;  // 1 / (4w)
        x = (matrix.template GetValue<2, 1>() - matrix.template GetValue<1, 2>()) * root;
        y = (matrix.template GetValue<0, 2>() - matrix.template GetValue<2, 0>()) * root;
        z = (matrix.template GetValue<1, 0>() - matrix.template GetValue<0, 1>()) * root;
    }
    else
    {
        constexpr auto indexSize = System::EnumCastUnderlying(PointIndex::Z);

        /// |w| <= 1 / 2
        auto index0 = 0;
        auto maxValue = matrix.template GetValue<0, 0>();
        if (maxValue < matrix.template GetValue<1, 1>())
        {
            index0 = 1;
            maxValue = matrix.template GetValue<1, 1>();
        }

        if (maxValue < matrix.template GetValue<2, 2>())
        {
            index0 = 2;
            maxValue = matrix.template GetValue<2, 2>();
        }

        const auto index1 = (index0 + 1) % indexSize;
        const auto index2 = (index1 + 1) % indexSize;

        auto root = Math::Sqrt(maxValue - matrix(index1, index1) - matrix(index2, index2) + Math::GetValue(1));

        (*this)[index0 + 1] = Math::GetRational(1, 2) * root;
        root = Math::GetRational(1, 2) / root;
        w = (matrix(index2, index1) - matrix(index1, index2)) * root;
        (*this)[index1 + 1] = (matrix(index1, index0) + matrix(index0, index1)) * root;
        (*this)[index2 + 1] = (matrix(index2, index0) + matrix(index0, index2)) * root;
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real>::Quaternion(const Vector3& axis, Real angle) noexcept(gAssert < 1 || gMathematicsAssert < 1)
    : w{}, x{}, y{}, z{}
{
    MATHEMATICS_ASSERTION_1(axis.IsNormalize(), "axis必须是单位向量！");

    FromAxisAngle(axis, angle);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Quaternion<Real>::FromAxisAngle(const Vector3& axis, Real angle) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_1(axis.IsNormalize(), "axis必须是单位向量！");

    /// 代表旋转的四元数是
    ///   q = cos(A/2) + sin(A/2) * (x * i + y * j + z * k)

    const auto halfAngle = Math::GetRational(1, 2) * angle;

    const auto sinValue = Math::Sin(halfAngle);

    w = Math::Cos(halfAngle);
    x = sinValue * axis.GetX();
    y = sinValue * axis.GetY();
    z = sinValue * axis.GetZ();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real>::Quaternion(const ContainerType& rotationColumn)
    : w{}, x{}, y{}, z{}
{
    if (rotationColumn.size() != zIndex)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("数据大小错误！"s))
    }

    FromRotationColumnVector3(rotationColumn);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Quaternion<Real>::FromRotationColumnVector3(const ContainerType& rotationColumn)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (rotationColumn.size() != zIndex)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("数据大小错误！"s))
    }

    FromRotationMatrix(Matrix3{ rotationColumn, MatrixMajorFlags::Column });
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Quaternion<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
const Real& Mathematics::Quaternion<Real>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    switch (System::UnderlyingCastEnum<PointIndex>(index))
    {
        case PointIndex::X:
            return x;
        case PointIndex::Y:
            return y;
        case PointIndex::Z:
            return z;
        case PointIndex::W:
            return w;
        default:
            break;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引错误！"s))
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real& Mathematics::Quaternion<Real>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Quaternion<Real>::GetW() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return w;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Quaternion<Real>::GetX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return x;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Quaternion<Real>::GetY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return y;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Quaternion<Real>::GetZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return z;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Quaternion<Real>::SetW(Real aW) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    w = aW;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Quaternion<Real>::SetX(Real aX) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x = aX;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Quaternion<Real>::SetY(Real aY) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    y = aY;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Quaternion<Real>::SetZ(Real aZ) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    z = aZ;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real>& Mathematics::Quaternion<Real>::operator*=(const Quaternion& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    *this = *this * rhs;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::operator+() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::operator-() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Quaternion{ -w, -x, -y, -z };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real>& Mathematics::Quaternion<Real>::operator+=(const Quaternion& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    w += rhs.w;
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real>& Mathematics::Quaternion<Real>::operator-=(const Quaternion& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    w -= rhs.w;
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real>& Mathematics::Quaternion<Real>::operator*=(Real scalar) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    w *= scalar;
    x *= scalar;
    y *= scalar;
    z *= scalar;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real>& Mathematics::Quaternion<Real>::operator/=(Real scalar) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (Math::FAbs(scalar) <= Math::GetZeroTolerance())
    {
        w = Real{};
        x = Real{};
        y = Real{};
        z = Real{};
    }
    else
    {
        w /= scalar;
        x /= scalar;
        y /= scalar;
        z /= scalar;
    }

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Quaternion<Real>::Matrix3 Mathematics::Quaternion<Real>::ToRotationMatrix() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto twoX = Math::GetValue(2) * x;
    const auto twoY = Math::GetValue(2) * y;
    const auto twoZ = Math::GetValue(2) * z;
    const auto twoWX = twoX * w;
    const auto twoWY = twoY * w;
    const auto twoWZ = twoZ * w;
    const auto twoXX = twoX * x;
    const auto twoXY = twoY * x;
    const auto twoXZ = twoZ * x;
    const auto twoYY = twoY * y;
    const auto twoYZ = twoZ * y;
    const auto twoZZ = twoZ * z;

    return Matrix3{ Math::GetValue(1) - (twoYY + twoZZ),
                    twoXY - twoWZ,
                    twoXZ + twoWY,
                    twoXY + twoWZ,
                    Math::GetValue(1) - (twoXX + twoZZ),
                    twoYZ - twoWX,
                    twoXZ - twoWY,
                    twoYZ + twoWX,
                    Math::GetValue(1) - (twoXX + twoYY) };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Quaternion<Real>::ContainerType Mathematics::Quaternion<Real>::ToRotationColumnVector3() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto matrix = ToRotationMatrix();

    ContainerType container{};

    for (auto column = 0; column < Matrix3::vectorSize; ++column)
    {
        container.emplace_back(matrix(Vector3::xIndex, column), matrix(Vector3::yIndex, column), matrix(Vector3::zIndex, column));
    }

    MATHEMATICS_ASSERTION_1(container.size() == Matrix3::vectorSize, "返回的向量大小错误！");

    return container;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Quaternion<Real>::Vector3 Mathematics::Quaternion<Real>::ToAxis() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    /// 代表旋转的四元数是
    ///   q = cos(A/2) + sin(A/2) * (x*i + y*j + z*k)

    const auto squareLength = x * x + y * y + z * z;

    if (Math::GetZeroTolerance() < squareLength)
    {
        const auto invLength = Math::InvSqrt(squareLength);

        return Vector3{ x * invLength, y * invLength, z * invLength };
    }
    else
    {
        /// 角度是 0 (2 * pi的模), 所以任何轴都行。
        return Vector3::GetUnitX();
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Quaternion<Real>::ToAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto squareLength = x * x + y * y + z * z;

    if (Math::GetZeroTolerance() < squareLength)
    {
        return Math::GetValue(2) * Math::ACos(w);
    }
    else
    {
        return Math::GetValue(0);
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Quaternion<Real>::AxisAngle Mathematics::Quaternion<Real>::ToAngleAxis() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return AxisAngle{ ToAngle(), ToAxis() };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Quaternion<Real>::Length() const noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Math::Sqrt(SquaredLength());
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Quaternion<Real>::SquaredLength() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Dot(*this, *this);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Quaternion<Real>::Normalize(Real epsilon) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto length = Length();

    if (epsilon < length)
    {
        (*this) /= length;
    }
    else
    {
        w = Math::GetValue(0);
        x = Math::GetValue(0);
        y = Math::GetValue(0);
        z = Math::GetValue(0);
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::Inverse() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto norm = SquaredLength();

    if (Math::GetZeroTolerance() < norm)
    {
        return Conjugate() / norm;
    }
    else
    {
        return Quaternion{};
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::Conjugate() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Quaternion{ w, -x, -y, -z };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::Exp() const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    MATHEMATICS_ASSERTION_1(Math::FAbs(w) <= Math::GetZeroTolerance(), "四元数w必须等于0！");

    /// 如果 q = A * (x*i+y*j+z*k) 这里 (x,y,z) 是单位长度，然后
    /// exp(q) = cos(A) + sin(A)*(x*i+y*j+z*k)。
    /// 如果 sin(A) 是接近为零,
    /// 使用 exp(q) = cos(A) + A*(x*i+y*j+z*k) 因为 A/sin(A) 趋向于 1。

    Quaternion result{};

    const auto angle = Math::Sqrt(x * x + y * y + z * z);

    const auto sinValue = Math::Sin(angle);
    result.w = Math::Cos(angle);

    if (Math::GetZeroTolerance() <= Math::FAbs(sinValue))
    {
        const auto coefficient = sinValue / angle;

        result.x = coefficient * x;
        result.y = coefficient * y;
        result.z = coefficient * z;
    }
    else
    {
        result.x = x;
        result.y = y;
        result.z = z;
    }

    return result;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::Log() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    /// 如果 q = cos(A) + sin(A) * (x*i+y*j+z*k) 这里 (x,y,z) 是单位长度,
    /// 然后 log(q) = A * (x*i+y*j+z*k)。
    /// 如果 sin(A) 是接近零，
    /// 使用 log(q) = sin(A) * (x*i+y*j+z*k)
    /// 因为 A/sin(A) 趋向于 1。

    Quaternion result{ Math::GetValue(0), GetX(), GetY(), GetZ() };

    if (Math::FAbs(w) < Math::GetValue(1))
    {
        const auto angle = Math::ACos(w);
        const auto sinValue = Math::Sin(angle);
        if (Math::GetZeroTolerance() <= Math::FAbs(sinValue))
        {
            const auto coefficient = angle / sinValue;

            result.x = coefficient * x;
            result.y = coefficient * y;
            result.z = coefficient * z;

            return result;
        }
    }

    return result;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Quaternion<Real>::Vector3 Mathematics::Quaternion<Real>::Rotate(const Vector3& uVector) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    const Vector3 vVector{ x, y, z };

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    const Vector3 vVector{ -x, -y, -z };

#endif  // !MATHEMATICS_USE_MATRIX_VECTOR

    const auto t = Math::GetValue(2) * Vector3Tools::CrossProduct(vVector, uVector);

    const auto rotatedU = uVector + w * t + Vector3Tools::CrossProduct(vVector, t);

    return rotatedU;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Quaternion<Real>::Vector4 Mathematics::Quaternion<Real>::Rotate(const Vector4& uVector) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    const Vector4 vVector{ x, y, z, Real{} };

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    const Vector4 vVector{ -x, -y, -z, Real{} };

#endif  // !MATHEMATICS_USE_MATRIX_VECTOR

    const auto t = Math::GetValue(2) * Vector4Tools::CrossProduct(vVector, uVector);

    const auto rotatedU = uVector + w * t + Vector4Tools::CrossProduct(vVector, t);

    return rotatedU;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Quaternion<Real>::AlgebraVector3 Mathematics::Quaternion<Real>::Rotate(const AlgebraVector3& uVector) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    const AlgebraVector3 vVector{ x, y, z };

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    const AlgebraVector3 vVector{ -x, -y, -z };

#endif  // !MATHEMATICS_USE_MATRIX_VECTOR

    const auto t = Math::GetValue(2) * Cross(vVector, uVector);

    const auto rotatedU = uVector + w * t + Cross(vVector, t);

    return rotatedU;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Quaternion<Real>::AlgebraVector4 Mathematics::Quaternion<Real>::Rotate(const AlgebraVector4& uVector) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    const AlgebraVector4 vVector{ x, y, z, Real{} };

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    const AlgebraVector4 vVector{ -x, -y, -z, Real{} };

#endif  // !MATHEMATICS_USE_MATRIX_VECTOR

    const auto t = Math::GetValue(2) * Cross(vVector, uVector);

    const auto rotatedU = uVector + w * t + Cross(vVector, t);

    return rotatedU;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Quaternion<Real>::SlerpChebyshevRatio(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto cosA = Dot(quaternion0, quaternion1);
    auto sign = NumericalValueSymbol::Zero;
    if (Math::GetValue(0) <= cosA)
    {
        sign = NumericalValueSymbol::Positive;
    }
    else
    {
        cosA = -cosA;
        sign = NumericalValueSymbol::Negative;
    }

    using System::operator*;

    const auto result = ChebyshevRatios<Real>(t, cosA);
    *this = quaternion0 * result.at(0) + quaternion1 * (sign * result.at(1));
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Quaternion<Real>::SlerpChebyshevRatioRestricted(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto cosA = Dot(quaternion0, quaternion1);

    const auto result = ChebyshevRatiosUsingCosAngle<Real>(t, cosA);
    *this = quaternion0 * result.at(0) + quaternion1 * result.at(1);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Quaternion<Real>::SlerpChebyshevRatioRestrictedPreprocessed(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1, Real cosA)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto result = ChebyshevRatiosUsingCosAngle<Real>(t, cosA);

    *this = quaternion0 * result.at(0) + quaternion1 * result.at(1);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Quaternion<Real>::SlerpChebyshevRatioRestrictedPreprocessedHalf(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1, const Quaternion& quaternionHalf, Real cosAHalf)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto twoT = Math::GetValue(2) * t;
    if (twoT <= Math::GetValue(1))
    {
        const auto result = ChebyshevRatiosUsingCosAngle<Real>(twoT, cosAHalf);
        *this = quaternion0 * result.at(0) + quaternionHalf * result.at(1);
    }
    else
    {
        const auto result = ChebyshevRatiosUsingCosAngle<Real>(twoT - Math::GetValue(1), cosAHalf);
        *this = quaternionHalf * result.at(0) + quaternion1 * result.at(1);
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Quaternion<Real>::Slerp(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1)
{
    auto cosA = Dot(quaternion0, quaternion1);
    Real sign{};
    if (Real{} <= cosA)
    {
        sign = Math::GetValue(1);
    }
    else
    {
        cosA = -cosA;
        sign = Math::GetValue(-1);
    }

    const auto chebyshevRatios = ChebyshevRatiosUsingCosAngle(t, cosA);

    *this = quaternion0 * chebyshevRatios.at(0) + quaternion1 * (sign * chebyshevRatios.at(1));
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Quaternion<Real>::SlerpExtraSpins(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1, int extraSpins) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto cosValue = Dot(quaternion0, quaternion1);
    const auto angle = Math::ACos(cosValue);

    if (Math::GetZeroTolerance() <= Math::FAbs(angle))
    {
        const auto sinValue = Math::Sin(angle);
        const auto phase = Math::GetPI() * extraSpins * t;

        const auto coefficient0 = Math::Sin((Math::GetValue(1) - t) * angle - phase) / sinValue;
        const auto coefficient1 = Math::Sin(t * angle + phase) / sinValue;

        w = coefficient0 * quaternion0.w + coefficient1 * quaternion1.w;
        x = coefficient0 * quaternion0.x + coefficient1 * quaternion1.x;
        y = coefficient0 * quaternion0.y + coefficient1 * quaternion1.y;
        z = coefficient0 * quaternion0.z + coefficient1 * quaternion1.z;
    }
    else
    {
        *this = quaternion0;
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Quaternion<Real>::IsNormalize(Real epsilon) const noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto length = Length();

    if (epsilon < length)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Quaternion<Real>::Intermediate(const Quaternion& quaternion0, const Quaternion& quaternion1, const Quaternion& quaternion2)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_1(quaternion0.IsNormalize() && quaternion1.IsNormalize() && quaternion2.IsNormalize(),
                            "quaternion0、quaternion1、quaternion2必须都是单位长度！");

    const auto quaternion1Conjugate = quaternion1.Conjugate();
    const auto p0 = quaternion1Conjugate * quaternion0;
    const auto p2 = quaternion1Conjugate * quaternion2;

    const auto arg = -Math::GetRational(1, 4) * (p0.Log() + p2.Log());

    *this = quaternion1 * arg.Exp();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Quaternion<Real>::Squad(Real t, const Quaternion& q0, const Quaternion& a0, const Quaternion& a1, const Quaternion& q1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto slerpT = Math::GetValue(2) * t * (Math::GetValue(1) - t);

    Quaternion slerpP{};
    slerpP.Slerp(t, q0, q1);

    Quaternion slerpQ{};
    slerpQ.Slerp(t, a0, a1);

    Slerp(slerpT, slerpP, slerpQ);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Quaternion<Real>::Align(const Vector3& vector0, const Vector3& vector1, Real epsilon)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_1(vector0.IsNormalize(epsilon) && vector1.IsNormalize(epsilon), "vector0和vector1必须是单位向量！");

    /// 如果vector0和vector1是不平行的，
    /// 旋转的轴是单位长度的向量
    /// U = Cross(vector0,vector1)/Length(Cross(vector0,vector1))。
    /// 旋转角度A为vector0和vector1之间的角度。
    /// 旋转的四元数为q = cos(A/2) + sin(A/2) * (ux * i + uy * j + uz * k)，
    /// 其中U = (ux,uy,uz)。
    ///
    /// (1) 与其提取A = acos(Dot(vector0,vector1))，
    ///     乘以1/2，然后计算sin(A/2)和cos(A/2)，
    ///     我们减少计算成本去计算平分线
    ///     B = (vector0 + vector1)/Length(vector0 + vector1)，
    ///     从而cos(A/2) =  Dot(vector0,B)。
    ///
    /// (2) 旋转轴为U = Cross(vector0,B)/Length(Cross(vector0,B))，
    ///     但 Length(Cross(vector0,B)) =
    ///     Length(vector0) * Length(B) * sin(A/2) = sin(A/2)，
    ///     在这种情况下，sin(A/2) * (ux * i + uy * j + uz * k) = (cx * i + cy * j + cz * k)，
    ///     其中C = Cross(vector0,B)。
    ///
    /// 如果vector0 = vector1，
    /// 则B = vector0， cos(A/2) = 1, and U = (0,0,0)。
    /// 如果vector0 = -vector1，则B = 0。
    /// 在这种情况下，A = pi和垂直于vector0的任何轴都可以被用作旋转轴。

    auto bisector = vector0 + vector1;
    if (Math::Approximate(Vector3Tools::GetLength(bisector), Math::GetValue(0), epsilon))
    {
        bisector.ZeroOut();
    }
    else
    {
        bisector.Normalize(epsilon);
    }

    const auto cosHalfAngle = Vector3Tools::DotProduct(vector0, bisector);

    w = cosHalfAngle;

    if (!Math::Approximate(cosHalfAngle, Math::GetValue(0), epsilon))
    {
        const auto cross = Vector3Tools::CrossProduct(vector0, bisector);
        x = cross.GetX();
        y = cross.GetY();
        z = cross.GetZ();
    }
    else
    {
        if (Math::FAbs(vector0.GetY()) <= Math::FAbs(vector0.GetX()))
        {
            /// V1.x或V1.z是最大规模的组成部分。
            auto invLength = Math::InvSqrt(vector0.GetX() * vector0.GetX() + vector0.GetZ() * vector0.GetZ());
            x = -vector0.GetZ() * invLength;
            y = Math::GetValue(0);
            z = +vector0.GetX() * invLength;
        }
        else
        {
            /// V1.y或V1.z是最大规模的组成部分。
            auto invLength = Math::InvSqrt(vector0.GetY() * vector0.GetY() + vector0.GetZ() * vector0.GetZ());
            x = Math::GetValue(0);
            y = +vector0.GetZ() * invLength;
            z = -vector0.GetY() * invLength;
        }
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Quaternion<Real>::QuaternionSwingTwist Mathematics::Quaternion<Real>::DecomposeTwistTimesSwing(const Vector3& vector, Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto rotate = Rotate(vector);
    Quaternion swing{};
    swing.Align(vector, rotate, epsilon);
    const auto twist = (*this) * swing.Conjugate();

    return QuaternionSwingTwist{ swing, twist };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Quaternion<Real>::QuaternionSwingTwist Mathematics::Quaternion<Real>::DecomposeSwingTimesTwist(const Vector3& vector, Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto rotate = Rotate(vector);
    Quaternion swing{};
    swing.Align(vector, rotate, epsilon);
    const auto twist = swing.Conjugate() * (*this);

    return QuaternionSwingTwist{ swing, twist };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestX() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetClosest(QuaternionClosestAxis::X);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestY() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetClosest(QuaternionClosestAxis::Y);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestZ() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetClosest(QuaternionClosestAxis::Z);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosest(QuaternionClosestAxis axis) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto axisIndex = System::EnumCastUnderlying(axis);

    Quaternion quaternion{};
    const auto p0 = w;
    const auto p1 = (*this)[axisIndex];
    const auto sqrLength = p0 * p0 + p1 * p1;
    if (Math::GetZeroTolerance() < sqrLength)
    {
        /// 唯一的最近点。
        const auto invLength = Math::InvSqrt(sqrLength);
        quaternion.SetW(p0 * invLength);
        quaternion[axisIndex] = p1 * invLength;
    }
    else
    {
        /// 无穷多解，选择theta = 0。
        quaternion.SetW(Math::GetValue(1));
        quaternion[axisIndex] = Math::GetValue(0);
    }

    return quaternion;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestXY() const noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto det = w * z - x * y;

    if (Math::FAbs(det) < Math::GetRational(1, 2) - Math::GetZeroTolerance())
    {
        auto discriminant = Math::GetValue(1) - Math::GetValue(4) * det * det;
        discriminant = Math::Sqrt(Math::FAbs(discriminant));

        const auto a = w * x + y * z;
        const auto b = w * w - x * x + y * y - z * z;

        auto c0 = Math::GetValue(0);
        auto s0 = Math::GetValue(0);

        if (Math::GetValue(0) <= b)
        {
            c0 = Math::GetRational(1, 2) * (discriminant + b);
            s0 = a;
        }
        else
        {
            c0 = a;
            s0 = Math::GetRational(1, 2) * (discriminant - b);
        }

        auto invLength = Math::InvSqrt(c0 * c0 + s0 * s0);
        c0 *= invLength;
        s0 *= invLength;

        auto c1 = w * c0 + x * s0;
        auto s1 = y * c0 + z * s0;
        invLength = Math::InvSqrt(c1 * c1 + s1 * s1);
        c1 *= invLength;
        s1 *= invLength;

        return Quaternion{ c0 * c1, s0 * c1, c0 * s1, s0 * s1 };
    }
    else
    {
        const auto invLength = Math::InvSqrt(Math::FAbs(det));

        return Quaternion{ w * invLength, x * invLength, Math::GetValue(0), Math::GetValue(0) };
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestYX() const noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const Quaternion alt{ w, x, y, -z };

    auto quaternion = alt.GetClosestXY();
    quaternion.SetZ(-quaternion.GetZ());

    return quaternion;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestZX() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const Quaternion alt{ w, x, z, y };

    auto quaternion = alt.GetClosestXY();
    std::swap(quaternion[Quaternion::yIndex], quaternion[Quaternion::zIndex]);

    return quaternion;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestXZ() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const Quaternion alt{ w, x, -z, y };

    auto quaternion = alt.GetClosestXY();

    const auto save = quaternion[yIndex];
    quaternion[yIndex] = quaternion[zIndex];
    quaternion[zIndex] = -save;

    return quaternion;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestYZ() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const Quaternion alt{ w, y, z, x };

    auto quaternion = alt.GetClosestXY();
    const auto save = quaternion[zIndex];
    quaternion[zIndex] = quaternion[yIndex];
    quaternion[yIndex] = quaternion[xIndex];
    quaternion[xIndex] = save;

    return quaternion;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestZY() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const Quaternion alt{ w, y, z, -x };

    auto quaternion = alt.GetClosestXY();
    const auto save = quaternion[zIndex];
    quaternion[zIndex] = quaternion[yIndex];
    quaternion[yIndex] = quaternion[xIndex];
    quaternion[xIndex] = -save;

    return quaternion;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Quaternion<Real>::QuaternionFactor Mathematics::Quaternion<Real>::FactorXYZ() const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return QuaternionFactor{ *this, QuaternionFactorFlags::XYZ };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Quaternion<Real>::QuaternionFactor Mathematics::Quaternion<Real>::FactorXZY() const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return QuaternionFactor{ *this, QuaternionFactorFlags::XZY };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Quaternion<Real>::QuaternionFactor Mathematics::Quaternion<Real>::FactorYZX() const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return QuaternionFactor{ *this, QuaternionFactorFlags::YZX };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Quaternion<Real>::QuaternionFactor Mathematics::Quaternion<Real>::FactorYXZ() const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return QuaternionFactor{ *this, QuaternionFactorFlags::YXZ };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Quaternion<Real>::QuaternionFactor Mathematics::Quaternion<Real>::FactorZXY() const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return QuaternionFactor{ *this, QuaternionFactorFlags::ZXY };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Quaternion<Real>::QuaternionFactor Mathematics::Quaternion<Real>::FactorZYX() const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return QuaternionFactor{ *this, QuaternionFactorFlags::ZYX };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestX(const QuaternionConstraints& xCon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetClosest(QuaternionClosestAxis::X, xCon);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestY(const QuaternionConstraints& yCon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetClosest(QuaternionClosestAxis::Y, yCon);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestZ(const QuaternionConstraints& zCon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetClosest(QuaternionClosestAxis::Z, zCon);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosest(QuaternionClosestAxis axis, const QuaternionConstraints& con) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    /// 各元素初始化为零
    Quaternion quaternion{};

    auto p0 = w;
    auto p1 = (*this)[System::EnumCastUnderlying(axis)];
    const auto sqrLength = p0 * p0 + p1 * p1;
    if (Math::GetZeroTolerance() < sqrLength)
    {
        const auto invLength = Math::InvSqrt(sqrLength);
        p0 *= invLength;
        p1 *= invLength;
        if (con.IsValid(p0, p1))
        {
            /// 最大值出现在内部点
            quaternion.SetW(p0);
            quaternion[System::EnumCastUnderlying(axis)] = p1;
        }
        else
        {
            /// 最大值出现在边界点
            auto cosValueMin = con.GetCosMinAngle();
            auto sinValueMin = con.GetSinMinAngle();
            auto dotMinAngle = p0 * cosValueMin + p1 * sinValueMin;
            if (dotMinAngle < Math::GetValue(0))
            {
                cosValueMin = -cosValueMin;
                sinValueMin = -sinValueMin;
                dotMinAngle = -dotMinAngle;
            }

            auto cosValueMax = con.GetCosMaxAngle();
            auto sinValueMax = con.GetSinMaxAngle();
            auto dotMaxAngle = p0 * cosValueMax + p1 * sinValueMax;
            if (dotMaxAngle < Math::GetValue(0))
            {
                cosValueMax = -cosValueMax;
                sinValueMax = -sinValueMax;
                dotMaxAngle = -dotMaxAngle;
            }

            if (dotMinAngle <= dotMaxAngle)
            {
                quaternion.SetW(cosValueMax);
                quaternion[System::EnumCastUnderlying(axis)] = sinValueMax;
            }
            else
            {
                quaternion.SetW(cosValueMin);
                quaternion[System::EnumCastUnderlying(axis)] = sinValueMin;
            }
        }
    }
    else
    {
        /// 无穷多解，选择一个满足的角度约束。
        quaternion.SetW(con.GetCosAvrAngle());
        quaternion[System::EnumCastUnderlying(axis)] = con.GetSinAvrAngle();
    }

    return quaternion;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestXY(const QuaternionConstraints& xCon, const QuaternionConstraints& yCon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto det = w * z - x * y;

    if (Math::FAbs(det) < Math::GetRational(1, 2) - Math::GetZeroTolerance())
    {
        const auto discriminant = Math::Sqrt(Math::FAbs(Math::GetValue(1) - Math::GetValue(4) * det * det));
        const auto a = w * x + y * z;
        const auto b = w * w - x * x + y * y - z * z;

        Real c0{};
        Real s0{};

        if (Math::GetValue(0) <= b)
        {
            c0 = Math::GetRational(1, 2) * (discriminant + b);
            s0 = a;
        }
        else
        {
            c0 = a;
            s0 = Math::GetRational(1, 2) * (discriminant - b);
        }

        auto invLength = Math::InvSqrt(c0 * c0 + s0 * s0);
        c0 *= invLength;
        s0 *= invLength;

        auto c1 = w * c0 + x * s0;
        auto s1 = y * c0 + z * s0;
        invLength = Math::InvSqrt(c1 * c1 + s1 * s1);
        c1 *= invLength;
        s1 *= invLength;

        if (xCon.IsValid(c0, s0) && yCon.IsValid(c1, s1))
        {
            /// 最大值发生在内部点。
            return Quaternion{ c0 * c1, s0 * c1, c0 * s1, s0 * s1 };
        }
        else
        {
            /// 最大值出现在边界点。
            Quaternion r{ xCon.GetCosMinAngle(), xCon.GetSinMinAngle(), Math::GetValue(0), Math::GetValue(0) };
            Quaternion rInv{ xCon.GetCosMinAngle(), -xCon.GetSinMinAngle(), Math::GetValue(0), Math::GetValue(0) };
            auto prod = rInv * (*this);
            auto prodClosest = prod.GetClosest(QuaternionClosestAxis::Y, yCon);
            auto dotOptAngle = Dot(prod, prodClosest);
            auto quaternion = r * prodClosest;

            r = Quaternion(xCon.GetCosMaxAngle(), xCon.GetSinMaxAngle(), Math::GetValue(0), Math::GetValue(0));
            rInv = Quaternion(xCon.GetCosMaxAngle(), -xCon.GetSinMaxAngle(), Math::GetValue(0), Math::GetValue(0));
            prod = rInv * (*this);
            prodClosest = prod.GetClosest(QuaternionClosestAxis::Y, yCon);
            auto dotAngle = Dot(prod, prodClosest);
            if (dotOptAngle < dotAngle)
            {
                quaternion = r * prodClosest;
                dotOptAngle = dotAngle;
            }

            r = Quaternion{ yCon.GetCosMinAngle(), Math::GetValue(0), yCon.GetSinMinAngle(), Math::GetValue(0) };
            rInv = Quaternion{ yCon.GetCosMinAngle(), Math::GetValue(0), -yCon.GetSinMinAngle(), Math::GetValue(0) };
            prod = (*this) * rInv;
            prodClosest = prod.GetClosest(QuaternionClosestAxis::X, xCon);
            dotAngle = Dot(prod, prodClosest);
            if (dotOptAngle < dotAngle)
            {
                quaternion = prodClosest * r;
                dotOptAngle = dotAngle;
            }

            r = Quaternion{ yCon.GetCosMaxAngle(), Math::GetValue(0), yCon.GetSinMaxAngle(), Math::GetValue(0) };
            rInv = Quaternion{ yCon.GetCosMaxAngle(), Math::GetValue(0), -yCon.GetSinMaxAngle(), Math::GetValue(0) };
            prod = (*this) * rInv;
            prodClosest = prod.GetClosest(QuaternionClosestAxis::X, xCon);
            dotAngle = Dot(prod, prodClosest);
            if (dotOptAngle < dotAngle)
            {
                quaternion = prodClosest * r;
                dotOptAngle = dotAngle;
            }

            return quaternion;
        }
    }
    else
    {
        /// 无穷多解，选择一个满足约束的角度。
        auto c0 = Math::GetValue(0);
        auto s0 = Math::GetValue(0);
        auto c1 = Math::GetValue(0);
        auto s1 = Math::GetValue(0);

        if (Math::GetValue(0) < det)
        {
            const auto minAngle = xCon.GetMinAngle() - yCon.GetMaxAngle();
            const auto maxAngle = xCon.GetMaxAngle() - yCon.GetMinAngle();
            const QuaternionConstraints con{ minAngle, maxAngle };

            const auto closest = GetClosest(QuaternionClosestAxis::X, con);

            auto angle = Math::ATan2(closest.GetX(), closest.GetW());
            if (angle < minAngle || maxAngle < angle)
            {
                angle -= (Math::GetValue(0) <= closest.GetX() ? Math::GetPI() : -Math::GetPI());

                MATHEMATICS_ASSERTION_1(minAngle <= angle && angle <= maxAngle, "angle的值必须在minAngle和maxAngle之间！");
            }

            if (angle <= xCon.GetMaxAngle() - yCon.GetMaxAngle())
            {
                c1 = yCon.GetCosMaxAngle();
                s1 = yCon.GetSinMaxAngle();
                angle = yCon.GetMaxAngle() + angle;
                c0 = Math::Cos(angle);
                s0 = Math::Sin(angle);
            }
            else
            {
                c0 = xCon.GetCosMaxAngle();
                s0 = xCon.GetSinMaxAngle();
                angle = xCon.GetMaxAngle() - angle;
                c1 = Math::Cos(angle);
                s1 = Math::Sin(angle);
            }
        }
        else
        {
            const auto minAngle = xCon.GetMinAngle() + yCon.GetMinAngle();
            const auto maxAngle = xCon.GetMaxAngle() + yCon.GetMaxAngle();
            const QuaternionConstraints con{ minAngle, maxAngle };

            const auto closest = GetClosest(QuaternionClosestAxis::X, con);

            auto angle = Math::ATan2(closest.GetX(), closest.GetW());
            if (angle < minAngle || maxAngle < angle)
            {
                angle -= (Math::GetValue(0) <= closest.GetX() ? Math::GetPI() : -Math::GetPI());

                MATHEMATICS_ASSERTION_1(minAngle <= angle && angle <= maxAngle, "angle的值必须在minAngle和maxAngle之间！");
            }

            if (xCon.GetMinAngle() + yCon.GetMaxAngle() <= angle)
            {
                c1 = yCon.GetCosMaxAngle();
                s1 = yCon.GetSinMaxAngle();
                angle = angle - yCon.GetMaxAngle();
                c0 = Math::Cos(angle);
                s0 = Math::Sin(angle);
            }
            else
            {
                c0 = xCon.GetCosMaxAngle();
                s0 = xCon.GetSinMaxAngle();
                angle = angle - xCon.GetMaxAngle();
                c1 = Math::Cos(angle);
                s1 = Math::Sin(angle);
            }
        }

        Quaternion quaternion{ c0 * c1, s0 * c1, c0 * s1, s0 * s1 };

        if (Dot(*this, quaternion) < Math::GetValue(0))
        {
            quaternion = -quaternion;
        }

        return quaternion;
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestYX(const QuaternionConstraints& yCon, const QuaternionConstraints& xCon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const Quaternion alt{ w, x, y, -z };

    auto quaternion = alt.GetClosestXY(xCon, yCon);
    quaternion.SetZ(-quaternion.GetZ());

    return quaternion;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestZX(const QuaternionConstraints& zCon, const QuaternionConstraints& xCon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto det = w * y - x * z;

    if (Math::FAbs(det) < Math::GetRational(1, 2) - Math::GetZeroTolerance())
    {
        const auto discriminant = Math::Sqrt(Math::FAbs(Math::GetValue(1) - Math::GetValue(4) * det * det));

        const auto a = w * z + x * y;
        const auto b = w * w + x * x - y * y - z * z;

        auto c2 = Math::GetValue(0);
        auto s2 = Math::GetValue(0);

        if (Math::GetValue(0) <= b)
        {
            c2 = Math::GetRational(1, 2) * (discriminant + b);
            s2 = a;
        }
        else
        {
            c2 = a;
            s2 = Math::GetRational(1, 2) * (discriminant - b);
        }

        auto invLength = Math::InvSqrt(c2 * c2 + s2 * s2);
        c2 *= invLength;
        s2 *= invLength;

        auto c0 = w * c2 + z * s2;
        auto s0 = x * c2 + y * s2;
        invLength = Math::InvSqrt(c0 * c0 + s0 * s0);
        c0 *= invLength;
        s0 *= invLength;

        if (zCon.IsValid(c2, s2) && xCon.IsValid(c0, s0))
        {
            /// 最大值发生在内部点。
            return Quaternion{ c2 * c0, c2 * s0, s2 * s0, s2 * c0 };
        }
        else
        {
            /// 最大值出现在边界点。
            Quaternion r{ zCon.GetCosMinAngle(), Math::GetValue(0), Math::GetValue(0), zCon.GetSinMinAngle() };
            Quaternion rInv{ zCon.GetCosMinAngle(), Math::GetValue(0), Math::GetValue(0), -zCon.GetSinMinAngle() };
            auto prod = rInv * (*this);
            auto prodClosest = prod.GetClosest(QuaternionClosestAxis::X, xCon);
            auto dotOptAngle = Dot(prod, prodClosest);
            auto quaternion = r * prodClosest;

            r = Quaternion{ zCon.GetCosMaxAngle(), Math::GetValue(0), Math::GetValue(0), zCon.GetSinMaxAngle() };
            rInv = Quaternion{ zCon.GetCosMaxAngle(), Math::GetValue(0), Math::GetValue(0), -zCon.GetSinMaxAngle() };
            prod = rInv * (*this);
            prodClosest = prod.GetClosest(QuaternionClosestAxis::X, xCon);
            auto dotAngle = Dot(prod, prodClosest);
            if (dotOptAngle < dotAngle)
            {
                quaternion = r * prodClosest;
                dotOptAngle = dotAngle;
            }

            r = Quaternion{ xCon.GetCosMinAngle(), xCon.GetSinMinAngle(), Math::GetValue(0), Math::GetValue(0) };
            rInv = Quaternion{ xCon.GetCosMinAngle(), -xCon.GetSinMinAngle(), Math::GetValue(0), Math::GetValue(0) };
            prod = (*this) * rInv;
            prodClosest = prod.GetClosest(QuaternionClosestAxis::Z, zCon);
            dotAngle = Dot(prod, prodClosest);
            if (dotAngle > dotOptAngle)
            {
                quaternion = prodClosest * r;
                dotOptAngle = dotAngle;
            }

            r = Quaternion{ xCon.GetCosMaxAngle(), xCon.GetSinMaxAngle(), Math::GetValue(0), Math::GetValue(0) };
            rInv = Quaternion{ xCon.GetCosMaxAngle(), -xCon.GetSinMaxAngle(), Math::GetValue(0), Math::GetValue(0) };
            prod = (*this) * rInv;
            prodClosest = prod.GetClosest(QuaternionClosestAxis::Z, zCon);
            dotAngle = Dot(prod, prodClosest);
            if (dotOptAngle < dotAngle)
            {
                quaternion = prodClosest * r;
                dotOptAngle = dotAngle;
            }

            return quaternion;
        }
    }
    else
    {
        /// 无穷多解，选择一个满足约束的角度。
        auto c0 = Math::GetValue(0);
        auto s0 = Math::GetValue(0);
        auto c2 = Math::GetValue(0);
        auto s2 = Math::GetValue(0);

        if (Math::GetValue(0) < det)
        {
            const auto minAngle = xCon.GetMinAngle() - zCon.GetMaxAngle();
            const auto maxAngle = xCon.GetMaxAngle() - zCon.GetMinAngle();
            const QuaternionConstraints con{ minAngle, maxAngle };

            const auto closest = GetClosest(QuaternionClosestAxis::X, con);

            auto angle = Math::ATan2(closest.GetX(), closest.GetW());
            if (angle < minAngle || maxAngle < angle)
            {
                angle -= (Math::GetValue(0) <= closest.GetX() ? Math::GetPI() : -Math::GetPI());

                MATHEMATICS_ASSERTION_1(minAngle <= angle && angle <= maxAngle, "angle的值必须在minAngle和maxAngle之间！");
            }

            if (angle <= xCon.GetMaxAngle() - zCon.GetMaxAngle())
            {
                c2 = zCon.GetCosMaxAngle();
                s2 = zCon.GetSinMaxAngle();
                angle = zCon.GetMaxAngle() + angle;
                c0 = Math::Cos(angle);
                s0 = Math::Sin(angle);
            }
            else
            {
                c0 = xCon.GetCosMaxAngle();
                s0 = xCon.GetSinMaxAngle();
                angle = xCon.GetMaxAngle() - angle;
                c2 = Math::Cos(angle);
                s2 = Math::Sin(angle);
            }
        }
        else
        {
            const auto minAngle = xCon.GetMinAngle() + zCon.GetMinAngle();
            const auto maxAngle = xCon.GetMaxAngle() + zCon.GetMaxAngle();
            const QuaternionConstraints con{ minAngle, maxAngle };

            const auto closest = GetClosest(QuaternionClosestAxis::X, con);

            auto angle = Math::ATan2(closest.GetX(), closest.GetW());
            if (angle < minAngle || maxAngle < angle)
            {
                angle -= (Math::GetValue(0) <= closest.GetX() ? Math::GetPI() : -Math::GetPI());

                MATHEMATICS_ASSERTION_1(minAngle <= angle && angle <= maxAngle, "angle的值必须在minAngle和maxAngle之间！");
            }

            if (xCon.GetMinAngle() + zCon.GetMaxAngle() <= angle)
            {
                c2 = zCon.GetCosMaxAngle();
                s2 = zCon.GetSinMaxAngle();
                angle = angle - zCon.GetMaxAngle();
                c0 = Math::Cos(angle);
                s0 = Math::Sin(angle);
            }
            else
            {
                c0 = xCon.GetCosMaxAngle();
                s0 = xCon.GetSinMaxAngle();
                angle = angle - xCon.GetMaxAngle();
                c2 = Math::Cos(angle);
                s2 = Math::Sin(angle);
            }
        }

        Quaternion quaternion{ c2 * c0, c2 * s0, s2 * s0, s2 * c0 };

        if (Dot(*this, quaternion) < Math::GetValue(0))
        {
            quaternion = -quaternion;
        }

        return quaternion;
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestXZ(const QuaternionConstraints& xCon, const QuaternionConstraints& zCon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const Quaternion alt{ w, x, -y, z };

    auto quaternion = alt.GetClosestZX(zCon, xCon);
    quaternion.SetY(-quaternion.GetY());

    return quaternion;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestZY(const QuaternionConstraints& zCon, const QuaternionConstraints& yCon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto det = w * x + y * z;

    if (Math::FAbs(det) < Math::GetRational(1, 2) - Math::GetZeroTolerance())
    {
        const auto discriminant = Math::Sqrt(Math::FAbs(Math::GetValue(1) - Math::GetValue(4) * det * det));

        const auto a = w * z - x * y;
        const auto b = w * w - x * x + y * y - z * z;

        auto c2 = Math::GetValue(0);
        auto s2 = Math::GetValue(0);

        if (Math::GetValue(0) <= b)
        {
            c2 = Math::GetRational(1, 2) * (discriminant + b);
            s2 = a;
        }
        else
        {
            c2 = a;
            s2 = Math::GetRational(1, 2) * (discriminant - b);
        }
        auto invLength = Math::InvSqrt(c2 * c2 + s2 * s2);
        c2 *= invLength;
        s2 *= invLength;

        auto c1 = w * c2 + z * s2;
        auto s1 = y * c2 - x * s2;
        invLength = Math::InvSqrt(c1 * c1 + s1 * s1);
        c1 *= invLength;
        s1 *= invLength;

        if (zCon.IsValid(c2, s2) && yCon.IsValid(c1, s1))
        {
            /// 最大值发生在内部点。
            return Quaternion{ c2 * c1, -s2 * s1, c2 * s1, s2 * c1 };
        }
        else
        {
            /// 最大值出现在边界点。
            Quaternion r{ zCon.GetCosMinAngle(), Math::GetValue(0), Math::GetValue(0), zCon.GetSinMinAngle() };
            Quaternion rInv{ zCon.GetCosMinAngle(), Math::GetValue(0), Math::GetValue(0), -zCon.GetSinMinAngle() };
            auto prod = rInv * (*this);
            auto prodClosest = prod.GetClosest(QuaternionClosestAxis::Y, yCon);
            auto dotOptAngle = Dot(prod, prodClosest);
            auto quaternion = r * prodClosest;

            r = Quaternion{ zCon.GetCosMaxAngle(), Math::GetValue(0), Math::GetValue(0), zCon.GetSinMaxAngle() };
            rInv = Quaternion{ zCon.GetCosMaxAngle(), Math::GetValue(0), Math::GetValue(0), -zCon.GetSinMaxAngle() };
            prod = rInv * (*this);
            prodClosest = prod.GetClosest(QuaternionClosestAxis::Y, yCon);
            auto dotAngle = Dot(prod, prodClosest);
            if (dotOptAngle < dotAngle)
            {
                quaternion = r * prodClosest;
                dotOptAngle = dotAngle;
            }

            r = Quaternion{ yCon.GetCosMinAngle(), Math::GetValue(0), yCon.GetSinMinAngle(), Math::GetValue(0) };
            rInv = Quaternion{ yCon.GetCosMinAngle(), Math::GetValue(0), -yCon.GetSinMinAngle(), Math::GetValue(0) };
            prod = (*this) * rInv;
            prodClosest = prod.GetClosest(QuaternionClosestAxis::Z, zCon);
            dotAngle = Dot(prod, prodClosest);
            if (dotOptAngle < dotAngle)
            {
                quaternion = prodClosest * r;
                dotOptAngle = dotAngle;
            }

            r = Quaternion{ yCon.GetCosMaxAngle(), Math::GetValue(0), yCon.GetSinMaxAngle(), Math::GetValue(0) };
            rInv = Quaternion{ yCon.GetCosMaxAngle(), Math::GetValue(0), -yCon.GetSinMaxAngle(), Math::GetValue(0) };
            prod = (*this) * rInv;
            prodClosest = prod.GetClosest(QuaternionClosestAxis::Z, zCon);
            dotAngle = Dot(prod, prodClosest);
            if (dotOptAngle < dotAngle)
            {
                quaternion = prodClosest * r;
                dotOptAngle = dotAngle;
            }

            return quaternion;
        }
    }
    else
    {
        /// 无穷多解，选择一个满足约束的角度。
        auto c1 = Math::GetValue(0);
        auto s1 = Math::GetValue(0);
        auto c2 = Math::GetValue(0);
        auto s2 = Math::GetValue(0);

        if (det < Math::GetValue(0))
        {
            const auto minAngle = yCon.GetMinAngle() - zCon.GetMaxAngle();
            const auto maxAngle = yCon.GetMaxAngle() - zCon.GetMinAngle();
            const QuaternionConstraints con{ minAngle, maxAngle };

            const auto closest = GetClosest(QuaternionClosestAxis::Y, con);

            auto angle = Math::ATan2(closest.GetY(), closest.GetW());
            if (angle < minAngle || maxAngle < angle)
            {
                angle -= (Math::GetValue(0) <= closest.GetY() ? Math::GetPI() : -Math::GetPI());

                MATHEMATICS_ASSERTION_1(minAngle <= angle && angle <= maxAngle, "angle的值必须在minAngle和maxAngle之间！");
            }

            if (angle <= yCon.GetMaxAngle() - zCon.GetMaxAngle())
            {
                c2 = zCon.GetCosMaxAngle();
                s2 = zCon.GetSinMaxAngle();
                angle = zCon.GetMaxAngle() + angle;
                c1 = Math::Cos(angle);
                s1 = Math::Sin(angle);
            }
            else
            {
                c1 = yCon.GetCosMaxAngle();
                s1 = yCon.GetSinMaxAngle();
                angle = yCon.GetMaxAngle() - angle;
                c2 = Math::Cos(angle);
                s2 = Math::Sin(angle);
            }
        }
        else
        {
            const auto minAngle = yCon.GetMinAngle() + zCon.GetMinAngle();
            const auto maxAngle = yCon.GetMaxAngle() + zCon.GetMaxAngle();
            const QuaternionConstraints con{ minAngle, maxAngle };

            const auto closest = GetClosest(QuaternionClosestAxis::Y, con);

            auto angle = Math::ATan2(closest.GetY(), closest.GetW());
            if (angle < minAngle || maxAngle < angle)
            {
                angle -= (Math::GetValue(0) <= closest.GetY() ? Math::GetPI() : -Math::GetPI());

                MATHEMATICS_ASSERTION_1(minAngle <= angle && angle <= maxAngle, "angle的值必须在minAngle和maxAngle之间！");
            }

            if (yCon.GetMinAngle() + zCon.GetMaxAngle() <= angle)
            {
                c2 = zCon.GetCosMaxAngle();
                s2 = zCon.GetSinMaxAngle();
                angle = angle - zCon.GetMaxAngle();
                c1 = Math::Cos(angle);
                s1 = Math::Sin(angle);
            }
            else
            {
                c1 = yCon.GetCosMaxAngle();
                s1 = yCon.GetSinMaxAngle();
                angle = angle - yCon.GetMaxAngle();
                c2 = Math::Cos(angle);
                s2 = Math::Sin(angle);
            }
        }

        Quaternion quaternion{ c2 * c1, -s2 * s1, c2 * s1, s2 * c1 };

        if (Dot(*this, quaternion) < Math::GetValue(0))
        {
            quaternion = -quaternion;
        }

        return quaternion;
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestYZ(const QuaternionConstraints& yCon, const QuaternionConstraints& zCon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const Quaternion alt{ w, -x, y, z };

    auto quaternion = alt.GetClosestZY(zCon, yCon);
    quaternion.SetX(-quaternion.GetX());

    return quaternion;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Quaternion<Real>::ArrayType Mathematics::Quaternion<Real>::GetCoordinate() const noexcept
{
    return ArrayType{ GetW(), GetX(), GetY(), GetZ() };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Quaternion<Real>::SetCoordinate(const ArrayType& coordinate) noexcept
{
    SetW(coordinate.at(System::EnumCastUnderlying(PointIndex::W)));
    SetX(coordinate.at(System::EnumCastUnderlying(PointIndex::X)));
    SetY(coordinate.at(System::EnumCastUnderlying(PointIndex::Y)));
    SetZ(coordinate.at(System::EnumCastUnderlying(PointIndex::Z)));
}

#endif  // MATHEMATICS_ALGEBRA_QUATERNION_ACHIEVE_H
