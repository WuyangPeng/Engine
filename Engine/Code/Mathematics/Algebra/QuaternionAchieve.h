///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/08 14:01)

#ifndef MATHEMATICS_ALGEBRA_QUATERNION_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_QUATERNION_ACHIEVE_H

#include "Matrix3.h"
#include "Quaternion.h"
#include "QuaternionFactorDetail.h"
#include "QuaternionSwingTwistDetail.h"
#include "Vector3Tools.h"
#include "Vector4Detail.h"
#include "Flags/QuaternionFlags.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/ChebyshevRatioDetail.h"

template <typename Real>
Mathematics::Quaternion<Real>::Quaternion(const Matrix3& matrix)
    : m_W{}, m_X{}, m_Y{}, m_Z{}
{
    FromRotationMatrix(matrix);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
void Mathematics::Quaternion<Real>::FromRotationMatrix(const Matrix3& matrix)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    // 算法在Ken Shoemake的文章，在1987年SIGGRAPH课程文章“四元微积分和快速动画”。
    const auto trace = matrix.GetValue<0, 0>() + matrix.GetValue<1, 1>() + matrix.GetValue<2, 2>();

    if (Math::GetValue(0) < trace)
    {
        // |w| > 1/2, 可能选择 w > 1/2
        auto root = Math::Sqrt(trace + Math::GetValue(1));  // 2w

        m_W = Math::GetRational(1, 2) * root;
        root = Math::GetRational(1, 2) / root;  // 1 / (4w)
        m_X = (matrix.GetValue<2, 1>() - matrix.GetValue<1, 2>()) * root;
        m_Y = (matrix.GetValue<0, 2>() - matrix.GetValue<2, 0>()) * root;
        m_Z = (matrix.GetValue<1, 0>() - matrix.GetValue<0, 1>()) * root;
    }
    else
    {
        constexpr auto indexSize = System::EnumCastUnderlying(PointIndex::Z);

        // |w| <= 1 / 2
        auto index0 = 0;
        auto maxValue = matrix.GetValue<0, 0>();
        if (maxValue < matrix.GetValue<1, 1>())
        {
            index0 = 1;
            maxValue = matrix.GetValue<1, 1>();
        }

        if (maxValue < matrix.GetValue<2, 2>())
        {
            index0 = 2;
            maxValue = matrix.GetValue<2, 2>();
        }

        const auto index1 = (index0 + 1) % indexSize;
        const auto index2 = (index1 + 1) % indexSize;

        auto root = Math::Sqrt(maxValue - matrix(index1, index1) - matrix(index2, index2) + Math::GetValue(1));

        (*this)[index0 + 1] = Math::GetRational(1, 2) * root;
        root = Math::GetRational(1, 2) / root;
        m_W = (matrix(index2, index1) - matrix(index1, index2)) * root;
        (*this)[index1 + 1] = (matrix(index1, index0) + matrix(index0, index1)) * root;
        (*this)[index2 + 1] = (matrix(index2, index0) + matrix(index0, index2)) * root;
    }
}

template <typename Real>
Mathematics::Quaternion<Real>::Quaternion(const Vector3& axis, Real angle) noexcept(gAssert < 1 || gMathematicsAssert < 1)
    : m_W{}, m_X{}, m_Y{}, m_Z{}
{
    MATHEMATICS_ASSERTION_1(axis.IsNormalize(), "axis必须是单位向量！");

    FromAxisAngle(axis, angle);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
void Mathematics::Quaternion<Real>::FromAxisAngle(const Vector3& axis, Real angle) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_1(axis.IsNormalize(), "axis必须是单位向量！");

    // 代表旋转的四元数是
    //   q = cos(A/2) + sin(A/2) * (x * i + y * j + z * k)

    const auto halfAngle = Math::GetRational(1, 2) * angle;

    const auto sinValue = Math::Sin(halfAngle);

    m_W = Math::Cos(halfAngle);
    m_X = sinValue * axis.GetX();
    m_Y = sinValue * axis.GetY();
    m_Z = sinValue * axis.GetZ();
}

template <typename Real>
Mathematics::Quaternion<Real>::Quaternion(const ContainerType& rotationColumn)
    : m_W{}, m_X{}, m_Y{}, m_Z{}
{
    if (rotationColumn.size() != zIndex)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("数据大小错误！"s));
    }

    FromRotationColumnVector3(rotationColumn);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
void Mathematics::Quaternion<Real>::FromRotationColumnVector3(const ContainerType& rotationColumn)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (rotationColumn.size() != zIndex)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("数据大小错误！"s));
    }

    FromRotationMatrix(Matrix3{ rotationColumn, MatrixMajorFlags::Column });
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Quaternion<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Real& Mathematics::Quaternion<Real>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    switch (System::UnderlyingCastEnum<PointIndex>(index))
    {
        case PointIndex::X:
            return m_X;
        case PointIndex::Y:
            return m_Y;
        case PointIndex::Z:
            return m_Z;
        case PointIndex::W:
            return m_W;
        default:
            break;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引错误！"s));
}

template <typename Real>
Real& Mathematics::Quaternion<Real>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
Real Mathematics::Quaternion<Real>::GetW() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_W;
}

template <typename Real>
Real Mathematics::Quaternion<Real>::GetX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_X;
}

template <typename Real>
Real Mathematics::Quaternion<Real>::GetY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Y;
}

template <typename Real>
Real Mathematics::Quaternion<Real>::GetZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Z;
}

template <typename Real>
void Mathematics::Quaternion<Real>::SetW(Real w) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_W = w;
}

template <typename Real>
void Mathematics::Quaternion<Real>::SetX(Real x) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X = x;
}

template <typename Real>
void Mathematics::Quaternion<Real>::SetY(Real y) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Y = y;
}

template <typename Real>
void Mathematics::Quaternion<Real>::SetZ(Real z) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Z = z;
}

template <typename Real>
Mathematics::Quaternion<Real>& Mathematics::Quaternion<Real>::operator*=(const Quaternion& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    *this = *this * rhs;

    return *this;
}

template <typename Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::operator-() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Quaternion{ -m_W, -m_X, -m_Y, -m_Z };
}

template <typename Real>
Mathematics::Quaternion<Real>& Mathematics::Quaternion<Real>::operator+=(const Quaternion& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_W += rhs.m_W;
    m_X += rhs.m_X;
    m_Y += rhs.m_Y;
    m_Z += rhs.m_Z;

    return *this;
}

template <typename Real>
Mathematics::Quaternion<Real>& Mathematics::Quaternion<Real>::operator-=(const Quaternion& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_W -= rhs.m_W;
    m_X -= rhs.m_X;
    m_Y -= rhs.m_Y;
    m_Z -= rhs.m_Z;

    return *this;
}

template <typename Real>
Mathematics::Quaternion<Real>& Mathematics::Quaternion<Real>::operator*=(Real scalar) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_W *= scalar;
    m_X *= scalar;
    m_Y *= scalar;
    m_Z *= scalar;

    return *this;
}

template <typename Real>
Mathematics::Quaternion<Real>& Mathematics::Quaternion<Real>::operator/=(Real scalar) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (Math::FAbs(scalar) <= Math::GetZeroTolerance())
    {
        MATHEMATICS_ASSERTION_1(false, "除零错误！");

        m_W = Math::maxReal;
        m_X = Math::maxReal;
        m_Y = Math::maxReal;
        m_Z = Math::maxReal;
    }
    else
    {
        m_W /= scalar;
        m_X /= scalar;
        m_Y /= scalar;
        m_Z /= scalar;
    }

    return *this;
}

template <typename Real>
typename Mathematics::Quaternion<Real>::Matrix3 Mathematics::Quaternion<Real>::ToRotationMatrix() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto twoX = Math::GetValue(2) * m_X;
    const auto twoY = Math::GetValue(2) * m_Y;
    const auto twoZ = Math::GetValue(2) * m_Z;
    const auto twoWX = twoX * m_W;
    const auto twoWY = twoY * m_W;
    const auto twoWZ = twoZ * m_W;
    const auto twoXX = twoX * m_X;
    const auto twoXY = twoY * m_X;
    const auto twoXZ = twoZ * m_X;
    const auto twoYY = twoY * m_Y;
    const auto twoYZ = twoZ * m_Y;
    const auto twoZZ = twoZ * m_Z;

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
typename Mathematics::Quaternion<Real>::Vector3 Mathematics::Quaternion<Real>::ToAxis() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    // 代表旋转的四元数是
    //   q = cos(A/2) + sin(A/2) * (x*i + y*j + z*k)

    const auto sqrareLength = m_X * m_X + m_Y * m_Y + m_Z * m_Z;

    if (Math::GetZeroTolerance() < sqrareLength)
    {
        const auto invLength = Math::InvSqrt(sqrareLength);

        return Vector3{ m_X * invLength, m_Y * invLength, m_Z * invLength };
    }
    else
    {
        // 角度是 0 (2 * pi的模), 所以任何轴都行。
        return Vector3::GetUnitX();
    }
}

template <typename Real>
Real Mathematics::Quaternion<Real>::ToAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto sqrareLength = m_X * m_X + m_Y * m_Y + m_Z * m_Z;

    if (Math::GetZeroTolerance() < sqrareLength)
    {
        return Math::GetValue(2) * Math::ACos(m_W);
    }
    else
    {
        return Math::GetValue(0);
    }
}

template <typename Real>
typename Mathematics::Quaternion<Real>::Matrix3Extract Mathematics::Quaternion<Real>::ToAngleAxis() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix3Extract{ ToAngle(), ToAxis() };
}

template <typename Real>
Real Mathematics::Quaternion<Real>::Length() const noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Math::Sqrt(SquaredLength());
}

template <typename Real>
Real Mathematics::Quaternion<Real>::SquaredLength() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_W * m_W + m_X * m_X + m_Y * m_Y + m_Z * m_Z;
}

template <typename Real>
void Mathematics::Quaternion<Real>::Normalize(Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto length = Length();

    if (epsilon < length)
    {
        m_W /= length;
        m_X /= length;
        m_Y /= length;
        m_Z /= length;
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "四元数正则化错误！");

        m_W = Math::GetValue(0);
        m_X = Math::GetValue(0);
        m_Y = Math::GetValue(0);
        m_Z = Math::GetValue(0);
    }
}

template <typename Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::Inverse() const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto norm = SquaredLength();

    if (Math::GetZeroTolerance() < norm)
    {
        return Quaternion{ m_W / norm, -m_X / norm, -m_Y / norm, -m_Z / norm };
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "返回一个无效的结果来标记错误！");

        return Quaternion{};
    }
}

template <typename Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::Conjugate() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Quaternion{ m_W, -m_X, -m_Y, -m_Z };
}

template <typename Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::Exp() const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    MATHEMATICS_ASSERTION_1(Math::FAbs(m_W) <= Math::GetZeroTolerance(), "四元数w必须等于0！");

    // 如果 q = A * (x*i+y*j+z*k) 这里 (x,y,z) 是单位长度，然后
    // exp(q) = cos(A) + sin(A)*(x*i+y*j+z*k)。
    // 如果 sin(A) 是接近为零,
    // 使用 exp(q) = cos(A) + A*(x*i+y*j+z*k) 因为 A/sin(A) 趋向于 1。

    Quaternion result{};

    const auto angle = Math::Sqrt(m_X * m_X + m_Y * m_Y + m_Z * m_Z);

    const auto sinValue = Math::Sin(angle);
    result.m_W = Math::Cos(angle);

    if (Math::GetZeroTolerance() <= Math::FAbs(sinValue))
    {
        auto coeff = sinValue / angle;

        result.m_X = coeff * m_X;
        result.m_Y = coeff * m_Y;
        result.m_Z = coeff * m_Z;
    }
    else
    {
        result.m_X = m_X;
        result.m_Y = m_Y;
        result.m_Z = m_Z;
    }

    return result;
}

template <typename Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::Log() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    // 如果 q = cos(A) + sin(A) * (x*i+y*j+z*k) 这里 (x,y,z) 是单位长度,
    // 然后 log(q) = A * (x*i+y*j+z*k)。
    // 如果 sin(A) 是接近零，
    // 使用 log(q) = sin(A) * (x*i+y*j+z*k)
    // 因为 A/sin(A) 趋向于 1。

    Quaternion result{ Math::GetValue(0), GetX(), GetY(), GetZ() };

    if (Math::FAbs(m_W) < Math::GetValue(1))
    {
        const auto angle = Math::ACos(m_W);
        const auto sinValue = Math::Sin(angle);
        if (Math::GetZeroTolerance() <= Math::FAbs(sinValue))
        {
            const auto coeff = angle / sinValue;

            result.m_X = coeff * m_X;
            result.m_Y = coeff * m_Y;
            result.m_Z = coeff * m_Z;

            return result;
        }
    }

    return result;
}

template <typename Real>
typename Mathematics::Quaternion<Real>::Vector3 Mathematics::Quaternion<Real>::Rotate(const Vector3& vector) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    // 给定一个向量u = (x0,y0,z0)和单位长度的四元数q = <w,x,y,z>
    // 向量v = (x1,y1,z1)，它代表u使用q旋转为v = q * u * q^{-1}，
    // 其中*表示四元数乘法和其中u被视为四元数<0,x0,y0,z0>。
    // 需要注意的是q^{-1} = <w,-x,-y,-z>，
    // 所以没有真正的工作去取q的逆。

    // 现在
    //   q * u * q^{-1} = q * <0,x0,y0,z0> * q^{-1}
    //     = q * (x0 * i + y0 * j + z0 * k) * q^{-1}
    //     = x0 * (q * i * q^{-1}) + y0 * (q * j * q^{-1}) + z0 * (q * k * q^{-1})
    //
    // 是计算在Quaternion<Real>::ToRotationMatrix中旋转矩阵的列。
    // 向量v被获得作为与向量u与旋转矩阵的乘积。
    // 因此，旋转矩阵的四元数表示，
    // 需要比矩阵较少的空间和更多的时间来计算旋转后的向量。
    // 典型的空间——时间权衡……

#if 1

    const auto matrix = ToRotationMatrix();

    return matrix * vector;

#else  // !1

    const Quaternion input{ vector.GetX(), vector.GetY(), vector.GetZ(), Math::GetValue(0) };

    const auto output = (*this) * input * Conjugate();

    return Vector3{ output.GetX(), output.GetY(), output.GetZ() };

#endif  // 1
}

template <typename Real>
typename Mathematics::Quaternion<Real>::Vector4 Mathematics::Quaternion<Real>::Rotate(const Vector4& vector) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const Quaternion input{ vector.GetX(), vector.GetY(), vector.GetZ(), Math::GetValue(0) };

    const auto output = (*this) * input * Conjugate();

    return Vector4{ output.GetX(), output.GetY(), output.GetZ(), Math::GetValue(0) };
}

template <typename Real>
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

    const auto result = ChebyshevRatio<Real>::Get(t, cosA);
    *this = quaternion0 * result[0] + quaternion1 * (sign * result[1]);
}

template <typename Real>
void Mathematics::Quaternion<Real>::SlerpChebyshevRatioRestricted(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto cosA = Dot(quaternion0, quaternion1);

    const auto result = ChebyshevRatio<Real>::Get(t, cosA);
    *this = quaternion0 * result[0] + quaternion1 * result[1];
}

template <typename Real>
void Mathematics::Quaternion<Real>::SlerpChebyshevRatioRestrictedPreprocessed(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1, Real cosA)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto result = ChebyshevRatio<Real>::Get(t, cosA);
    *this = quaternion0 * result[0] + quaternion1 * result[1];
}

template <typename Real>
void Mathematics::Quaternion<Real>::SlerpChebyshevRatioRestrictedPreprocessedHalf(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1, const Quaternion& quaternionHalf, Real cosAHalf)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto twoT = Math::GetValue(2) * t;
    if (twoT <= Math::GetValue(1))
    {
        const auto result = ChebyshevRatio<Real>::Get(twoT, cosAHalf);
        *this = quaternion0 * result[0] + quaternionHalf * result[1];
    }
    else
    {
        const auto result = ChebyshevRatio<Real>::Get(twoT - Math::GetValue(1), cosAHalf);
        *this = quaternionHalf * result[0] + quaternion1 * result[1];
    }
}

template <typename Real>
void Mathematics::Quaternion<Real>::Slerp(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1) noexcept
{
    const auto cosValue = Dot(quaternion0, quaternion1);
    const auto angle = Math::ACos(cosValue);

    if (Math::GetZeroTolerance() <= Math::FAbs(angle))
    {
        const auto sinValue = Math::Sin(angle);
        const auto tAngle = t * angle;
        const auto coeff0 = Math::Sin(angle - tAngle) / sinValue;
        const auto coeff1 = Math::Sin(tAngle) / sinValue;

        m_W = coeff0 * quaternion0.m_W + coeff1 * quaternion1.m_W;
        m_X = coeff0 * quaternion0.m_X + coeff1 * quaternion1.m_X;
        m_Y = coeff0 * quaternion0.m_Y + coeff1 * quaternion1.m_Y;
        m_Z = coeff0 * quaternion0.m_Z + coeff1 * quaternion1.m_Z;
    }
    else
    {
        *this = quaternion0;
    }
}

template <typename Real>
void Mathematics::Quaternion<Real>::SlerpExtraSpins(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1, int extraSpins) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto cosValue = Dot(quaternion0, quaternion1);
    const auto angle = Math::ACos(cosValue);

    if (Math::GetZeroTolerance() <= Math::FAbs(angle))
    {
        const auto sinValue = Math::Sin(angle);
        const auto phase = Math::GetPI() * extraSpins * t;

        const auto coeff0 = Math::Sin((Math::GetValue(1) - t) * angle - phase) / sinValue;
        const auto coeff1 = Math::Sin(t * angle + phase) / sinValue;

        m_W = coeff0 * quaternion0.m_W + coeff1 * quaternion1.m_W;
        m_X = coeff0 * quaternion0.m_X + coeff1 * quaternion1.m_X;
        m_Y = coeff0 * quaternion0.m_Y + coeff1 * quaternion1.m_Y;
        m_Z = coeff0 * quaternion0.m_Z + coeff1 * quaternion1.m_Z;
    }
    else
    {
        *this = quaternion0;
    }
}

template <typename Real>
bool Mathematics::Quaternion<Real>::IsNormalize(Real epsilon) const noexcept(gAssert < 3 || gMathematicsAssert < 3)
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
void Mathematics::Quaternion<Real>::Squad(Real t, const Quaternion& q0, const Quaternion& a0, const Quaternion& a1, const Quaternion& q1) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto slerpT = Math::GetValue(2) * t * (Math::GetValue(1) - t);

    Quaternion slerpP{};
    slerpP.Slerp(t, q0, q1);

    Quaternion slerpQ{};
    slerpQ.Slerp(t, a0, a1);

    Slerp(slerpT, slerpP, slerpQ);
}

template <typename Real>
void Mathematics::Quaternion<Real>::Align(const Vector3& vector0, const Vector3& vector1, Real epsilon)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_1(vector0.IsNormalize(epsilon) && vector1.IsNormalize(epsilon), "vector0和vector1必须是单位向量！");

    // 如果vector0和vector1是不平行的，
    // 旋转的轴是单位长度的向量
    // U = Cross(vector0,vector1)/Length(Cross(vector0,vector1))。
    // 旋转角度A为vector0和vector1之间的角度。
    // 旋转的四元数为q = cos(A/2) + sin(A/2) * (ux * i + uy * j + uz * k)，
    // 其中U = (ux,uy,uz)。
    //
    // (1) 与其提取A = acos(Dot(vector0,vector1))，
    //     乘以1/2，然后计算sin(A/2)和cos(A/2)，
    //     我们减少计算成本去计算平分线
    //     B = (vector0 + vector1)/Length(vector0 + vector1)，
    //     从而cos(A/2) =  Dot(vector0,B)。
    //
    // (2) 旋转轴为U = Cross(vector0,B)/Length(Cross(vector0,B))，
    //     但 Length(Cross(vector0,B)) =
    //     Length(vector0) * Length(B) * sin(A/2) = sin(A/2)，
    //     在这种情况下，sin(A/2) * (ux * i + uy * j + uz * k) = (cx * i + cy * j + cz * k)，
    //     其中C = Cross(vector0,B)。
    //
    // 如果vector0 = vector1，
    // 则B = vector0， cos(A/2) = 1, and U = (0,0,0)。
    // 如果vector0 = -vector1，则B = 0。
    // 在这种情况下，A = pi和垂直于vector0的任何轴都可以被用作旋转轴。

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

    m_W = cosHalfAngle;

    if (!Math::Approximate(cosHalfAngle, Math::GetValue(0), epsilon))
    {
        const auto cross = Vector3Tools::CrossProduct(vector0, bisector);
        m_X = cross.GetX();
        m_Y = cross.GetY();
        m_Z = cross.GetZ();
    }
    else
    {
        if (Math::FAbs(vector0.GetY()) <= Math::FAbs(vector0.GetX()))
        {
            // V1.x或V1.z是最大规模的组成部分。
            auto invLength = Math::InvSqrt(vector0.GetX() * vector0.GetX() + vector0.GetZ() * vector0.GetZ());
            m_X = -vector0.GetZ() * invLength;
            m_Y = Math::GetValue(0);
            m_Z = +vector0.GetX() * invLength;
        }
        else
        {
            // V1.y或V1.z是最大规模的组成部分。
            auto invLength = Math::InvSqrt(vector0.GetY() * vector0.GetY() + vector0.GetZ() * vector0.GetZ());
            m_X = Math::GetValue(0);
            m_Y = +vector0.GetZ() * invLength;
            m_Z = -vector0.GetY() * invLength;
        }
    }
}

template <typename Real>
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
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestX() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetClosest(QuaternionClosestAxis::X);
}

template <typename Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestY() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetClosest(QuaternionClosestAxis::Y);
}

template <typename Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestZ() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetClosest(QuaternionClosestAxis::Z);
}

// private
template <typename Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosest(QuaternionClosestAxis axis) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto axisIndex = System::EnumCastUnderlying(axis);

    // 适当的非零分量将在后面进行设置。
    Quaternion quaternion{};
    const auto p0 = m_W;
    const auto p1 = (*this)[axisIndex];
    const auto sqrLength = p0 * p0 + p1 * p1;
    if (Math::GetZeroTolerance() < sqrLength)
    {
        // 唯一的最近点。
        const auto invLength = Math::InvSqrt(sqrLength);
        quaternion.SetW(p0 * invLength);
        quaternion[axisIndex] = p1 * invLength;
    }
    else
    {
        // 无穷多解，选择theta = 0。
        quaternion.SetW(Math::GetValue(1));
        quaternion[axisIndex] = Math::GetValue(0);
    }

    return quaternion;
}

template <typename Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestXY() const noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto det = m_W * m_Z - m_X * m_Y;

    if (Math::FAbs(det) < Math::GetRational(1, 2) - Math::GetZeroTolerance())
    {
        auto discr = Math::GetValue(1) - Math::GetValue(4) * det * det;
        discr = Math::Sqrt(Math::FAbs(discr));

        const auto a = m_W * m_X + m_Y * m_Z;
        const auto b = m_W * m_W - m_X * m_X + m_Y * m_Y - m_Z * m_Z;

        auto c0 = Math::GetValue(0);
        auto s0 = Math::GetValue(0);

        if (Math::GetValue(0) <= b)
        {
            c0 = Math::GetRational(1, 2) * (discr + b);
            s0 = a;
        }
        else
        {
            c0 = a;
            s0 = Math::GetRational(1, 2) * (discr - b);
        }

        auto invLength = Math::InvSqrt(c0 * c0 + s0 * s0);
        c0 *= invLength;
        s0 *= invLength;

        auto c1 = m_W * c0 + m_X * s0;
        auto s1 = m_Y * c0 + m_Z * s0;
        invLength = Math::InvSqrt(c1 * c1 + s1 * s1);
        c1 *= invLength;
        s1 *= invLength;

        return Quaternion{ c0 * c1, s0 * c1, c0 * s1, s0 * s1 };
    }
    else
    {
        const auto invLength = Math::InvSqrt(Math::FAbs(det));

        return Quaternion{ m_W * invLength, m_X * invLength, Math::GetValue(0), Math::GetValue(0) };
    }
}

template <typename Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestYX() const noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const Quaternion alt{ m_W, m_X, m_Y, -m_Z };

    auto quaternion = alt.GetClosestXY();
    quaternion.SetZ(-quaternion.GetZ());

    return quaternion;
}

template <typename Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestZX() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const Quaternion alt{ m_W, m_X, m_Z, m_Y };

    auto quaternion = alt.GetClosestXY();
    std::swap(quaternion[Quaternion::yIndex], quaternion[Quaternion::zIndex]);

    return quaternion;
}

template <typename Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestXZ() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const Quaternion alt{ m_W, m_X, -m_Z, m_Y };

    auto quaternion = alt.GetClosestXY();

    const auto save = quaternion[Quaternion::yIndex];
    quaternion[Quaternion::yIndex] = quaternion[Quaternion::zIndex];
    quaternion[Quaternion::zIndex] = -save;

    return quaternion;
}

template <typename Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestYZ() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const Quaternion alt{ m_W, m_Y, m_Z, m_X };

    auto quaternion = alt.GetClosestXY();
    const auto save = quaternion[Quaternion::zIndex];
    quaternion[Quaternion::zIndex] = quaternion[Quaternion::yIndex];
    quaternion[Quaternion::yIndex] = quaternion[Quaternion::xIndex];
    quaternion[Quaternion::xIndex] = save;

    return quaternion;
}

template <typename Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestZY() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const Quaternion alt{ m_W, m_Y, m_Z, -m_X };

    auto quaternion = alt.GetClosestXY();
    const auto save = quaternion[Quaternion::zIndex];
    quaternion[Quaternion::zIndex] = quaternion[Quaternion::yIndex];
    quaternion[Quaternion::yIndex] = quaternion[Quaternion::xIndex];
    quaternion[Quaternion::xIndex] = -save;

    return quaternion;
}

template <typename Real>
typename Mathematics::Quaternion<Real>::QuaternionFactor Mathematics::Quaternion<Real>::FactorXYZ() const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return QuaternionFactor{ *this, QuaternionFactorFlags::XYZ };
}

template <typename Real>
typename Mathematics::Quaternion<Real>::QuaternionFactor Mathematics::Quaternion<Real>::FactorXZY() const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return QuaternionFactor{ *this, QuaternionFactorFlags::XZY };
}

template <typename Real>
typename Mathematics::Quaternion<Real>::QuaternionFactor Mathematics::Quaternion<Real>::FactorYZX() const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return QuaternionFactor{ *this, QuaternionFactorFlags::YZX };
}

template <typename Real>
typename Mathematics::Quaternion<Real>::QuaternionFactor Mathematics::Quaternion<Real>::FactorYXZ() const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return QuaternionFactor{ *this, QuaternionFactorFlags::YXZ };
}

template <typename Real>
typename Mathematics::Quaternion<Real>::QuaternionFactor Mathematics::Quaternion<Real>::FactorZXY() const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return QuaternionFactor{ *this, QuaternionFactorFlags::ZXY };
}

template <typename Real>
typename Mathematics::Quaternion<Real>::QuaternionFactor Mathematics::Quaternion<Real>::FactorZYX() const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return QuaternionFactor{ *this, QuaternionFactorFlags::ZYX };
}

template <typename Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestX(const QuaternionConstraints& xCon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetClosest(QuaternionClosestAxis::X, xCon);
}

template <typename Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestY(const QuaternionConstraints& yCon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetClosest(QuaternionClosestAxis::Y, yCon);
}

template <typename Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestZ(const QuaternionConstraints& zCon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetClosest(QuaternionClosestAxis::Z, zCon);
}

template <typename Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosest(QuaternionClosestAxis axis, const QuaternionConstraints& con) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    // 各元素初始化为零
    Quaternion quaternion{};

    auto p0 = m_W;
    auto p1 = (*this)[System::EnumCastUnderlying(axis)];
    const auto sqrLength = p0 * p0 + p1 * p1;
    if (Math::GetZeroTolerance() < sqrLength)
    {
        const auto invLength = Math::InvSqrt(sqrLength);
        p0 *= invLength;
        p1 *= invLength;
        if (con.IsValid(p0, p1))
        {
            // 最大值出现在内部点
            quaternion.SetW(p0);
            quaternion[System::EnumCastUnderlying(axis)] = p1;
        }
        else
        {
            // 最大值出现在边界点
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
        // 无穷多解，选择一个满足的角度约束。
        quaternion.SetW(con.GetCosAvrAngle());
        quaternion[System::EnumCastUnderlying(axis)] = con.GetSinAvrAngle();
    }

    return quaternion;
}

template <typename Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestXY(const QuaternionConstraints& xCon, const QuaternionConstraints& yCon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto det = m_W * m_Z - m_X * m_Y;

    if (Math::FAbs(det) < Math::GetRational(1, 2) - Math::GetZeroTolerance())
    {
        const auto discr = Math::Sqrt(Math::FAbs(Math::GetValue(1) - Math::GetValue(4) * det * det));
        const auto a = m_W * m_X + m_Y * m_Z;
        const auto b = m_W * m_W - m_X * m_X + m_Y * m_Y - m_Z * m_Z;

        Real c0{};
        Real s0{};

        if (Math::GetValue(0) <= b)
        {
            c0 = Math::GetRational(1, 2) * (discr + b);
            s0 = a;
        }
        else
        {
            c0 = a;
            s0 = Math::GetRational(1, 2) * (discr - b);
        }

        auto invLength = Math::InvSqrt(c0 * c0 + s0 * s0);
        c0 *= invLength;
        s0 *= invLength;

        auto c1 = m_W * c0 + m_X * s0;
        auto s1 = m_Y * c0 + m_Z * s0;
        invLength = Math::InvSqrt(c1 * c1 + s1 * s1);
        c1 *= invLength;
        s1 *= invLength;

        if (xCon.IsValid(c0, s0) && yCon.IsValid(c1, s1))
        {
            // 最大值发生在内部点。
            return Quaternion{ c0 * c1, s0 * c1, c0 * s1, s0 * s1 };
        }
        else
        {
            // 最大值出现在边界点。
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
        // 无穷多解，选择一个满足约束的角度。
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
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestYX(const QuaternionConstraints& yCon, const QuaternionConstraints& xCon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const Quaternion alt{ m_W, m_X, m_Y, -m_Z };

    auto quaternion = alt.GetClosestXY(xCon, yCon);
    quaternion.SetZ(-quaternion.GetZ());

    return quaternion;
}

template <typename Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestZX(const QuaternionConstraints& zCon, const QuaternionConstraints& xCon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto det = m_W * m_Y - m_X * m_Z;

    if (Math::FAbs(det) < Math::GetRational(1, 2) - Math::GetZeroTolerance())
    {
        const auto discr = Math::Sqrt(Math::FAbs(Math::GetValue(1) - Math::GetValue(4) * det * det));

        const auto a = m_W * m_Z + m_X * m_Y;
        const auto b = m_W * m_W + m_X * m_X - m_Y * m_Y - m_Z * m_Z;

        auto c2 = Math::GetValue(0);
        auto s2 = Math::GetValue(0);

        if (Math::GetValue(0) <= b)
        {
            c2 = Math::GetRational(1, 2) * (discr + b);
            s2 = a;
        }
        else
        {
            c2 = a;
            s2 = Math::GetRational(1, 2) * (discr - b);
        }

        auto invLength = Math::InvSqrt(c2 * c2 + s2 * s2);
        c2 *= invLength;
        s2 *= invLength;

        auto c0 = m_W * c2 + m_Z * s2;
        auto s0 = m_X * c2 + m_Y * s2;
        invLength = Math::InvSqrt(c0 * c0 + s0 * s0);
        c0 *= invLength;
        s0 *= invLength;

        if (zCon.IsValid(c2, s2) && xCon.IsValid(c0, s0))
        {
            // 最大值发生在内部点。
            return Quaternion{ c2 * c0, c2 * s0, s2 * s0, s2 * c0 };
        }
        else
        {
            // 最大值出现在边界点。
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
        // 无穷多解，选择一个满足约束的角度。
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
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestXZ(const QuaternionConstraints& xCon, const QuaternionConstraints& zCon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const Quaternion alt{ m_W, m_X, -m_Y, m_Z };

    auto quaternion = alt.GetClosestZX(zCon, xCon);
    quaternion.SetY(-quaternion.GetY());

    return quaternion;
}

template <typename Real>
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestZY(const QuaternionConstraints& zCon, const QuaternionConstraints& yCon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto det = m_W * m_X + m_Y * m_Z;

    if (Math::FAbs(det) < Math::GetRational(1, 2) - Math::GetZeroTolerance())
    {
        const auto discr = Math::Sqrt(Math::FAbs(Math::GetValue(1) - Math::GetValue(4) * det * det));

        const auto a = m_W * m_Z - m_X * m_Y;
        const auto b = m_W * m_W - m_X * m_X + m_Y * m_Y - m_Z * m_Z;

        auto c2 = Math::GetValue(0);
        auto s2 = Math::GetValue(0);

        if (Math::GetValue(0) <= b)
        {
            c2 = Math::GetRational(1, 2) * (discr + b);
            s2 = a;
        }
        else
        {
            c2 = a;
            s2 = Math::GetRational(1, 2) * (discr - b);
        }
        auto invLength = Math::InvSqrt(c2 * c2 + s2 * s2);
        c2 *= invLength;
        s2 *= invLength;

        auto c1 = m_W * c2 + m_Z * s2;
        auto s1 = m_Y * c2 - m_X * s2;
        invLength = Math::InvSqrt(c1 * c1 + s1 * s1);
        c1 *= invLength;
        s1 *= invLength;

        if (zCon.IsValid(c2, s2) && yCon.IsValid(c1, s1))
        {
            // 最大值发生在内部点。
            return Quaternion{ c2 * c1, -s2 * s1, c2 * s1, s2 * c1 };
        }
        else
        {
            // 最大值出现在边界点。
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
Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestYZ(const QuaternionConstraints& yCon, const QuaternionConstraints& zCon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const Quaternion alt{ m_W, -m_X, m_Y, m_Z };

    auto quaternion = alt.GetClosestZY(zCon, yCon);
    quaternion.SetX(-quaternion.GetX());

    return quaternion;
}

template <typename T>
typename Mathematics::Quaternion<T>::ArrayType Mathematics::Quaternion<T>::GetCoordinate() const noexcept
{
    return ArrayType{ GetW(), GetX(), GetY(), GetZ() };
}

template <typename T>
void Mathematics::Quaternion<T>::SetCoordinate(const ArrayType& coordinate) noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

    SetW(coordinate[System::EnumCastUnderlying(PointIndex::W)]);
    SetX(coordinate[System::EnumCastUnderlying(PointIndex::X)]);
    SetY(coordinate[System::EnumCastUnderlying(PointIndex::Y)]);
    SetZ(coordinate[System::EnumCastUnderlying(PointIndex::Z)]);

#include STSTEM_WARNING_POP
}

#endif  // MATHEMATICS_ALGEBRA_QUATERNION_ACHIEVE_H
