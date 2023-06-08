///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/05/31 14:23)

#ifndef MATHEMATICS_ALGEBRA_A_QUATERNION_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_A_QUATERNION_ACHIEVE_H

#include "AQuaternion.h"
#include "AVector.h"
#include "AVectorDetail.h"
#include "Matrix.h"
#include "MatrixDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::AQuaternion<Real>::AQuaternion(const ArrayType& coordinate) noexcept
    : w{ coordinate.at(System::EnumCastUnderlying(PointIndex::W)) },
      x{ coordinate.at(System::EnumCastUnderlying(PointIndex::X)) },
      y{ coordinate.at(System::EnumCastUnderlying(PointIndex::Y)) },
      z{ coordinate.at(System::EnumCastUnderlying(PointIndex::Z)) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::AQuaternion<Real>::AQuaternion(const Matrix& matrix)
    : w{}, x{}, y{}, z{}
{
    FromRotationMatrix(matrix);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::AQuaternion<Real>::FromRotationMatrix(const Matrix& matrix)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    // 算法在Ken Shoemake的文章，在1987年SIGGRAPH课程文章“四元微积分和快速动画”。

    const auto trace = matrix.GetValue<0>() + matrix.GetValue<5>() + matrix.GetValue<10>();

    if (Math::GetValue(0) < trace)
    {
        // |w| > 1/2, 可能选择 w > 1/2
        auto root = Math::Sqrt(trace + Math::GetValue(1));  // 2w

        w = Math::GetRational(1, 2) * root;
        root = Math::GetRational(1, 2) / root;  // 1 / (4w)
        x = (matrix.GetValue<9>() - matrix.GetValue<6>()) * root;
        y = (matrix.GetValue<2>() - matrix.GetValue<8>()) * root;
        z = (matrix.GetValue<4>() - matrix.GetValue<1>()) * root;
    }
    else
    {
        constexpr auto indexSize = System::EnumCastUnderlying(PointIndex::Z);

        // |w| <= 1 / 2
        auto index0 = 0;
        auto maxValue = matrix.GetValue<0>();
        if (maxValue < matrix.GetValue<5>())
        {
            index0 = 1;
            maxValue = matrix.GetValue<5>();
        }
        if (maxValue < matrix.GetValue<10>())
        {
            index0 = 2;
            maxValue = matrix.GetValue<10>();
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
Mathematics::AQuaternion<Real>::AQuaternion(const AVector& axis, Real angle) noexcept(gAssert < 1 || gMathematicsAssert < 1)
    : w{}, x{}, y{}, z{}
{
    MATHEMATICS_ASSERTION_1(axis.IsNormalize(), "axis必须是单位向量！");

    FromAxisAngle(axis, angle);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::AQuaternion<Real>::FromAxisAngle(const AVector& axis, Real angle) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_1(axis.IsNormalize(), "axis必须是单位向量！");

    // 代表旋转的四元数是
    // q = cos(A/2) + sin(A/2) * (x * i + y * j + z * k)

    const auto halfAngle = Math::GetRational(1, 2) * angle;

    const auto sinValue = Math::Sin(halfAngle);
    w = Math::Cos(halfAngle);

    x = sinValue * axis.GetX();
    y = sinValue * axis.GetY();
    z = sinValue * axis.GetZ();
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::AQuaternion<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
const Real& Mathematics::AQuaternion<Real>::operator[](int index) const
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
Real& Mathematics::AQuaternion<Real>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::AQuaternion<Real>::GetW() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return w;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::AQuaternion<Real>::GetX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return x;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::AQuaternion<Real>::GetY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return y;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::AQuaternion<Real>::GetZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return z;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::AQuaternion<Real>::SetW(Real aW) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    w = aW;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::AQuaternion<Real>::SetX(Real aX) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x = aX;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::AQuaternion<Real>::SetY(Real aY) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    y = aY;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::AQuaternion<Real>::SetZ(Real aZ) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    z = aZ;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::AQuaternion<Real>& Mathematics::AQuaternion<Real>::operator*=(const AQuaternion& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    *this = *this * rhs;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::AQuaternion<Real> Mathematics::AQuaternion<Real>::operator-() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return AQuaternion{ -w, -x, -y, -z };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::AQuaternion<Real>& Mathematics::AQuaternion<Real>::operator+=(const AQuaternion& rhs) noexcept
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
Mathematics::AQuaternion<Real>& Mathematics::AQuaternion<Real>::operator-=(const AQuaternion& rhs) noexcept
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
Mathematics::AQuaternion<Real>& Mathematics::AQuaternion<Real>::operator*=(Real scalar) noexcept
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
Mathematics::AQuaternion<Real>& Mathematics::AQuaternion<Real>::operator/=(Real scalar) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (Math::FAbs(scalar) <= Math::GetZeroTolerance())
    {
        MATHEMATICS_ASSERTION_1(false, "除零错误！");

        w = Math::maxReal;
        x = Math::maxReal;
        y = Math::maxReal;
        z = Math::maxReal;
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
typename Mathematics::AQuaternion<Real>::Matrix Mathematics::AQuaternion<Real>::ToRotationMatrix() const noexcept
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

    return Matrix{ Math::GetValue(1) - (twoYY + twoZZ),
                   twoXY - twoWZ,
                   twoXZ + twoWY,
                   Math::GetValue(0),

                   twoXY + twoWZ,
                   Math::GetValue(1) - (twoXX + twoZZ),
                   twoYZ - twoWX,
                   Math::GetValue(0),

                   twoXZ - twoWY,
                   twoYZ + twoWX,
                   Math::GetValue(1) - (twoXX + twoYY),
                   Math::GetValue(0),

                   Math::GetValue(0),
                   Math::GetValue(0),
                   Math::GetValue(0),
                   Math::GetValue(1) };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::AQuaternion<Real>::AVector Mathematics::AQuaternion<Real>::ToAxis() const noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    // 代表旋转的四元数是
    // q = cos(A/2) + sin(A/2) * (x*i + y*j + z*k)

    const auto squareLength = x * x + y * y + z * z;

    if (Math::GetZeroTolerance() < squareLength)
    {
        const auto invLength = Math::InvSqrt(squareLength);

        return AVector{ x * invLength, y * invLength, z * invLength };
    }
    else
    {
        // 角度是 0 (2 * pi的模), 所以任何轴都行。
        return AVector::GetUnitX();
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics ::AQuaternion<Real>::ToAngle() const noexcept
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
Real Mathematics::AQuaternion<Real>::Length() const noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Math::Sqrt(SquaredLength());
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::AQuaternion<Real>::SquaredLength() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return w * w + x * x + y * y + z * z;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::AQuaternion<Real>::Normalize(Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto length = Length();

    if (epsilon < length)
    {
        w /= length;
        x /= length;
        y /= length;
        z /= length;
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "四元数正则化错误！");

        w = Math::GetValue(0);
        x = Math::GetValue(0);
        y = Math::GetValue(0);
        z = Math::GetValue(0);
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::AQuaternion<Real>::IsNormalize(Real epsilon) const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto length = Length();

    if (Math::FAbs(length - Math::GetValue(1)) <= epsilon)
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
Mathematics::AQuaternion<Real> Mathematics::AQuaternion<Real>::Inverse() const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto norm = SquaredLength();

    if (Math::GetZeroTolerance() < norm)
    {
        return AQuaternion{ w / norm, -x / norm, -y / norm, -z / norm };
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "返回一个无效的结果来标记错误！");

        return AQuaternion{};
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::AQuaternion<Real> Mathematics::AQuaternion<Real>::Conjugate() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return AQuaternion{ w, -x, -y, -z };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::AQuaternion<Real> Mathematics::AQuaternion<Real>::Exp() const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    MATHEMATICS_ASSERTION_1(Math::FAbs(w) <= Math::GetZeroTolerance(), "四元数w必须等于0！");

    // 如果 q = A * (x * i + y * j + z * k) 这里 (x,y,z) 是单位长度，然后
    // exp(q) = cos(A) + sin(A) * (x * i + y * j + z * k)。
    // 如果 sin(A) 是接近为零,
    // 使用 exp(q) = cos(A) + A * (x * i + y * j + z * k) 因为 A/sin(A) 趋向于 1。

    AQuaternion result{};

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
Mathematics::AQuaternion<Real> Mathematics::AQuaternion<Real>::Log() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    // 如果 q = cos(A) + sin(A) * (x * i + y * j + z * k) 这里 (x,y,z) 是单位长度,
    // 然后 log(q) = A * (x * i + y * j + z * k)。
    // 如果 sin(A) 是接近零，
    // 使用 log(q) = sin(A) * (x * i + y * j + z * k)
    // 因为 A/sin(A) 趋向于 1。

    AQuaternion result{ *this };
    result.w = Math::GetValue(0);

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
typename Mathematics::AQuaternion<Real>::AVector Mathematics::AQuaternion<Real>::Rotate(const AVector& vector) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    // 给定一个向量u = (x0,y0,z0)和单位长度的四元数q = <w,x,y,z>
    // 向量v = (x1,y1,z1)，它代表u使用q旋转为v = q * u * q^{-1}，
    // 其中*表示四元数乘法和其中u被视为四元数<0,x0,y0,z0>。
    // 需要注意的是q^{-1} = <w,-x,-y,-z>，
    // 所以没有真正的工作去取q的逆。

    // 现在
    // q * u * q^{-1} = q * <0,x0,y0,z0> * q^{-1}
    //                = q * (x0 * i + y0 * j + z0 * k) * q^{-1}
    //                = x0 * (q * i * q^{-1}) + y0 * (q * j * q^{-1}) + z0 * (q * k * q^{-1})
    //
    // 是计算在HQuaternion<Real>::ToRotationMatrix中旋转矩阵的列。
    // 向量v被获得作为与向量u与旋转矩阵的乘积。
    // 因此，旋转矩阵的四元数表示，需要比矩阵较少的空间和更多的时间来计算旋转后的向量。
    // 典型的空间——时间权衡……

    const auto matrix = ToRotationMatrix();

    return matrix * vector;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::AQuaternion<Real>::Slerp(Real t, const AQuaternion& quaternion0, const AQuaternion& quaternion1) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto cosValue = Dot(quaternion0, quaternion1);
    const auto angle = Math::ACos(cosValue);

    if (Math::GetZeroTolerance() <= Math::FAbs(angle))
    {
        const auto sinValue = Math::Sin(angle);
        const auto tAngle = t * angle;
        const auto coefficient0 = Math::Sin(angle - tAngle) / sinValue;
        const auto coefficient1 = Math::Sin(tAngle) / sinValue;

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
requires std::is_arithmetic_v<Real>
void Mathematics::AQuaternion<Real>::Intermediate(const AQuaternion& quaternion0, const AQuaternion& quaternion1, const AQuaternion& quaternion2)
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
void Mathematics::AQuaternion<Real>::Squad(Real t, const AQuaternion& q0, const AQuaternion& a0, const AQuaternion& a1, const AQuaternion& q1) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto slerpT = Math::GetValue(2) * t * (Math::GetValue(1) - t);

    AQuaternion slerpP{};
    slerpP.Slerp(t, q0, q1);

    AQuaternion slerpQ{};
    slerpQ.Slerp(t, a0, a1);

    Slerp(slerpT, slerpP, slerpQ);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::AQuaternion<Real>::ArrayType Mathematics::AQuaternion<Real>::GetCoordinate() const noexcept
{
    return ArrayType{ GetW(), GetX(), GetY(), GetZ() };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::AQuaternion<Real>::Set(const ArrayType& coordinate) noexcept
{
    SetW(coordinate.at(System::EnumCastUnderlying(PointIndex::W)));
    SetX(coordinate.at(System::EnumCastUnderlying(PointIndex::X)));
    SetY(coordinate.at(System::EnumCastUnderlying(PointIndex::Y)));
    SetZ(coordinate.at(System::EnumCastUnderlying(PointIndex::Z)));
}

#endif  // MATHEMATICS_ALGEBRA_A_QUATERNION_ACHIEVE_H
