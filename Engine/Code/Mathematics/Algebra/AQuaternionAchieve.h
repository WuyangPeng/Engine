///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/03 14:51)

#ifndef MATHEMATICS_ALGEBRA_HQUATERNION_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_HQUATERNION_ACHIEVE_H

#include "AQuaternion.h"
#include "AVector.h"
#include "Matrix.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
template <typename Real>
Mathematics::AQuaternion<Real>::AQuaternion(const ArrayType& coordinate) noexcept
    : m_W{ coordinate[System::EnumCastUnderlying(PointIndex::W)] },
      m_X{ coordinate[System::EnumCastUnderlying(PointIndex::X)] },
      m_Y{ coordinate[System::EnumCastUnderlying(PointIndex::Y)] },
      m_Z{ coordinate[System::EnumCastUnderlying(PointIndex::Z)] }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}
#include STSTEM_WARNING_POP

template <typename Real>
Mathematics::AQuaternion<Real>::AQuaternion(const Matrix& matrix)
    : m_W{}, m_X{}, m_Y{}, m_Z{}
{
    FromRotationMatrix(matrix);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
void Mathematics::AQuaternion<Real>::FromRotationMatrix(const Matrix& matrix)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    // 算法在Ken Shoemake的文章，在1987年SIGGRAPH课程文章“四元微积分和快速动画”。

    auto trace = matrix.GetValue<0>() + matrix.GetValue<5>() + matrix.GetValue<10>();

    if (Math::GetValue(0) < trace)
    {
        // |w| > 1/2, 可能选择 w > 1/2
        auto root = Math::Sqrt(trace + Math::GetValue(1));  // 2w

        m_W = Math::GetRational(1, 2) * root;
        root = Math::GetRational(1, 2) / root;  // 1 / (4w)
        m_X = (matrix.GetValue<9>() - matrix.GetValue<6>()) * root;
        m_Y = (matrix.GetValue<2>() - matrix.GetValue<8>()) * root;
        m_Z = (matrix.GetValue<4>() - matrix.GetValue<1>()) * root;
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
Mathematics::AQuaternion<Real>::AQuaternion(const AVector& axis, Real angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
    : m_W{}, m_X{}, m_Y{}, m_Z{}
{
    MATHEMATICS_ASSERTION_1(axis.IsNormalize(), "axis必须是单位向量！");

    FromAxisAngle(axis, angle);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
void Mathematics::AQuaternion<Real>::FromAxisAngle(const AVector& axis, Real angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_1(axis.IsNormalize(), "axis必须是单位向量！");

    // 代表旋转的四元数是
    //   q = cos(A/2) + sin(A/2) * (x * i + y * j + z * k)

    auto halfAngle = Math::GetRational(1, 2) * angle;

    auto sinValue = Math::Sin(halfAngle);
    m_W = Math::Cos(halfAngle);

    m_X = sinValue * axis.GetX();
    m_Y = sinValue * axis.GetY();
    m_Z = sinValue * axis.GetZ();
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::AQuaternion<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Real& Mathematics::AQuaternion<Real>::operator[](int index) const
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
Real& Mathematics::AQuaternion<Real>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    MATHEMATICS_ASSERTION_0(0 <= index && index < sm_EntrySize, "索引错误！");

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
Real Mathematics::AQuaternion<Real>::GetW() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_W;
}

template <typename Real>
Real Mathematics::AQuaternion<Real>::GetX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_X;
}

template <typename Real>
Real Mathematics::AQuaternion<Real>::GetY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Y;
}

template <typename Real>
Real Mathematics::AQuaternion<Real>::GetZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Z;
}

template <typename Real>
void Mathematics::AQuaternion<Real>::SetW(Real w) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_W = w;
}

template <typename Real>
void Mathematics::AQuaternion<Real>::SetX(Real x) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X = x;
}

template <typename Real>
void Mathematics::AQuaternion<Real>::SetY(Real y) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Y = y;
}

template <typename Real>
void Mathematics::AQuaternion<Real>::SetZ(Real z) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Z = z;
}

template <typename Real>
Mathematics::AQuaternion<Real>& Mathematics::AQuaternion<Real>::operator*=(const AQuaternion& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    *this = *this * rhs;

    return *this;
}

template <typename Real>
const Mathematics::AQuaternion<Real> Mathematics::AQuaternion<Real>::operator-() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return AQuaternion{ -m_W, -m_X, -m_Y, -m_Z };
}

template <typename Real>
Mathematics::AQuaternion<Real>& Mathematics::AQuaternion<Real>::operator+=(const AQuaternion& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_W += rhs.m_W;
    m_X += rhs.m_X;
    m_Y += rhs.m_Y;
    m_Z += rhs.m_Z;

    return *this;
}

template <typename Real>
Mathematics::AQuaternion<Real>& Mathematics::AQuaternion<Real>::operator-=(const AQuaternion& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_W -= rhs.m_W;
    m_X -= rhs.m_X;
    m_Y -= rhs.m_Y;
    m_Z -= rhs.m_Z;

    return *this;
}

template <typename Real>
Mathematics::AQuaternion<Real>& Mathematics::AQuaternion<Real>::operator*=(Real scalar) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_W *= scalar;
    m_X *= scalar;
    m_Y *= scalar;
    m_Z *= scalar;

    return *this;
}

template <typename Real>
Mathematics::AQuaternion<Real>& Mathematics::AQuaternion<Real>::operator/=(Real scalar) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (Math::FAbs(scalar) <= Math::GetZeroTolerance())
    {
        m_W = Math::sm_MaxReal;
        m_X = Math::sm_MaxReal;
        m_Y = Math::sm_MaxReal;
        m_Z = Math::sm_MaxReal;
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
typename const Mathematics::AQuaternion<Real>::Matrix Mathematics::AQuaternion<Real>::ToRotationMatrix() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto twoX = Math::GetValue(2) * m_X;
    auto twoY = Math::GetValue(2) * m_Y;
    auto twoZ = Math::GetValue(2) * m_Z;
    auto twoWX = twoX * m_W;
    auto twoWY = twoY * m_W;
    auto twoWZ = twoZ * m_W;
    auto twoXX = twoX * m_X;
    auto twoXY = twoY * m_X;
    auto twoXZ = twoZ * m_X;
    auto twoYY = twoY * m_Y;
    auto twoYZ = twoZ * m_Y;
    auto twoZZ = twoZ * m_Z;

    return Matrix{ Math::GetValue(1) - (twoYY + twoZZ), twoXY - twoWZ, twoXZ + twoWY, Math::GetValue(0),
                   twoXY + twoWZ, Math::GetValue(1) - (twoXX + twoZZ), twoYZ - twoWX, Math::GetValue(0),
                   twoXZ - twoWY, twoYZ + twoWX, Math::GetValue(1) - (twoXX + twoYY), Math::GetValue(0),
                   Math::GetValue(0), Math::GetValue(0), Math::GetValue(0), Math::GetValue(1) };
}

template <typename Real>
typename const Mathematics::AQuaternion<Real>::AVector Mathematics::AQuaternion<Real>::ToAxis() const noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    // 代表旋转的四元数是
    //   q = cos(A/2) + sin(A/2) * (x*i + y*j + z*k)

    auto sqrareLength = m_X * m_X + m_Y * m_Y + m_Z * m_Z;

    if (Math::GetZeroTolerance() < sqrareLength)
    {
        auto invLength = Math::InvSqrt(sqrareLength);

        return AVector{ m_X * invLength, m_Y * invLength, m_Z * invLength };
    }
    else
    {
        // 角度是 0 (2 * pi的模), 所以任何轴都行。
        return AVector::GetUnitX();
    }
}

template <typename Real>
Real Mathematics ::AQuaternion<Real>::ToAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto sqrareLength = m_X * m_X + m_Y * m_Y + m_Z * m_Z;

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
Real Mathematics::AQuaternion<Real>::Length() const noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Math::Sqrt(SquaredLength());
}

template <typename Real>
Real Mathematics::AQuaternion<Real>::SquaredLength() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_W * m_W + m_X * m_X + m_Y * m_Y + m_Z * m_Z;
}

template <typename Real>
void Mathematics::AQuaternion<Real>::Normalize(Real epsilon) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
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
bool Mathematics::AQuaternion<Real>::IsNormalize(Real epsilon) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
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
const Mathematics::AQuaternion<Real> Mathematics::AQuaternion<Real>::Inverse() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto norm = SquaredLength();

    if (Math::GetZeroTolerance() < norm)
    {
        return AQuaternion{ m_W / norm, -m_X / norm, -m_Y / norm, -m_Z / norm };
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "返回一个无效的结果来标记错误！");

        return AQuaternion{};
    }
}

template <typename Real>
const Mathematics::AQuaternion<Real> Mathematics::AQuaternion<Real>::Conjugate() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return AQuaternion{ m_W, -m_X, -m_Y, -m_Z };
}

template <typename Real>
const Mathematics::AQuaternion<Real> Mathematics::AQuaternion<Real>::Exp() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    MATHEMATICS_ASSERTION_1(Math::FAbs(m_W) <= Math::GetZeroTolerance(), "四元数w必须等于0！");

    // 如果 q = A * (x * i + y * j + z * k) 这里 (x,y,z) 是单位长度，然后
    // exp(q) = cos(A) + sin(A) * (x * i + y * j + z * k)。
    // 如果 sin(A) 是接近为零,
    // 使用 exp(q) = cos(A) + A * (x * i + y * j + z * k) 因为 A/sin(A) 趋向于 1。

    AQuaternion result{};

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
const Mathematics::AQuaternion<Real> Mathematics::AQuaternion<Real>::Log() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    // 如果 q = cos(A) + sin(A) * (x * i + y * j + z * k) 这里 (x,y,z) 是单位长度,
    // 然后 log(q) = A * (x * i + y * j + z * k)。
    // 如果 sin(A) 是接近零，
    // 使用 log(q) = sin(A) * (x * i + y * j + z * k)
    // 因为 A/sin(A) 趋向于 1。

    AQuaternion result{ *this };
    result.m_W = Math::GetValue(0);

    if (Math::FAbs(m_W) < Math::GetValue(1))
    {
        auto angle = Math::ACos(m_W);
        auto sinValue = Math::Sin(angle);
        if (Math::GetZeroTolerance() <= Math::FAbs(sinValue))
        {
            auto coeff = angle / sinValue;

            result.m_X = coeff * m_X;
            result.m_Y = coeff * m_Y;
            result.m_Z = coeff * m_Z;

            return result;
        }
    } 

    return result;
}

template <typename Real>
typename const Mathematics::AQuaternion<Real>::AVector Mathematics::AQuaternion<Real>::Rotate(const AVector& vector) const noexcept
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
    // 是计算在HQuaternion<Real>::ToRotationMatrix中旋转矩阵的列。
    // 向量v被获得作为与向量u与旋转矩阵的乘积。
    // 因此，旋转矩阵的四元数表示，需要比矩阵较少的空间和更多的时间来计算旋转后的向量。
    // 典型的空间——时间权衡……

    const auto matrix = ToRotationMatrix();

    return matrix * vector;
}

template <typename Real>
void Mathematics::AQuaternion<Real>::Slerp(Real t, const AQuaternion& quaternion0, const AQuaternion& quaternion1) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto cosValue = Dot(quaternion0, quaternion1);
    auto angle = Math::ACos(cosValue);

    if (Math::GetZeroTolerance() <= Math::FAbs(angle))
    {
        auto sinValue = Math::Sin(angle);
        auto tAngle = t * angle;
        auto coeff0 = Math::Sin(angle - tAngle) / sinValue;
        auto coeff1 = Math::Sin(tAngle) / sinValue;

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
void Mathematics::AQuaternion<Real>::Intermediate(const AQuaternion& quaternion0, const AQuaternion& quaternion1, const AQuaternion& quaternion2)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_1(quaternion0.IsNormalize() && quaternion1.IsNormalize() && quaternion2.IsNormalize(),
                            "quaternion0、quaternion1、quaternion2必须都是单位长度！");

    const auto quaternion1Conjugate = quaternion1.Conjugate();
    const auto p0 = quaternion1Conjugate * quaternion0;
    const auto p2 = quaternion1Conjugate * quaternion2;

    auto arg = -Math::GetRational(1, 4) * (p0.Log() + p2.Log());
    *this = quaternion1 * arg.Exp();
}

template <typename Real>
void Mathematics::AQuaternion<Real>::Squad(Real t, const AQuaternion& q0, const AQuaternion& a0, const AQuaternion& a1, const AQuaternion& q1) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto slerpT = Math::GetValue(2) * t * (Math::GetValue(1) - t);

    AQuaternion slerpP{};
    slerpP.Slerp(t, q0, q1);

    AQuaternion slerpQ{};
    slerpQ.Slerp(t, a0, a1);

    Slerp(slerpT, slerpP, slerpQ);
}

template <typename T>
const typename Mathematics::AQuaternion<T>::ArrayType Mathematics::AQuaternion<T>::GetCoordinate() const noexcept
{
    return ArrayType{ GetW(), GetX(), GetY(), GetZ() };
}

template <typename T>
void Mathematics::AQuaternion<T>::Set(const ArrayType& coordinate) noexcept
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

#endif  // MATHEMATICS_ALGEBRA_HQUATERNION_ACHIEVE_H
