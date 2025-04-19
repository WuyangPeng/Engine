///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 10:14)

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
Mathematics::AQuaternion<Real>::AQuaternion(const MatrixType& matrix)
    : w{}, x{}, y{}, z{}
{
    FromRotationMatrix(matrix);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::AQuaternion<Real>::FromRotationMatrix(const MatrixType& matrix)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    // �㷨��Ken Shoemake�����£���1987��SIGGRAPH�γ����¡���Ԫ΢���ֺͿ��ٶ�������

    const auto trace = matrix.template GetValue<0>() + matrix.template GetValue<5>() + matrix.template GetValue<10>();

    if (MathType::GetValue(0) < trace)
    {
        // |w| > 1/2, ����ѡ�� w > 1/2
        auto root = MathType::Sqrt(trace + MathType::GetValue(1));  // 2w

        w = MathType::GetRational(1, 2) * root;
        root = MathType::GetRational(1, 2) / root;  // 1 / (4w)
        x = (matrix.template GetValue<9>() - matrix.template GetValue<6>()) * root;
        y = (matrix.template GetValue<2>() - matrix.template GetValue<8>()) * root;
        z = (matrix.template GetValue<4>() - matrix.template GetValue<1>()) * root;
    }
    else
    {
        constexpr auto indexSize = System::EnumCastUnderlying(PointIndex::Z);

        // |w| <= 1 / 2
        auto index0 = 0;
        auto maxValue = matrix.template GetValue<0>();
        if (maxValue < matrix.template GetValue<5>())
        {
            index0 = 1;
            maxValue = matrix.template GetValue<5>();
        }
        if (maxValue < matrix.template GetValue<10>())
        {
            index0 = 2;
            maxValue = matrix.template GetValue<10>();
        }

        const auto index1 = (index0 + 1) % indexSize;
        const auto index2 = (index1 + 1) % indexSize;

        auto root = MathType::Sqrt(maxValue - matrix(index1, index1) - matrix(index2, index2) + MathType::GetValue(1));

        (*this)[index0 + 1] = MathType::GetRational(1, 2) * root;
        root = MathType::GetRational(1, 2) / root;
        w = (matrix(index2, index1) - matrix(index1, index2)) * root;
        (*this)[index1 + 1] = (matrix(index1, index0) + matrix(index0, index1)) * root;
        (*this)[index2 + 1] = (matrix(index2, index0) + matrix(index0, index2)) * root;
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::AQuaternion<Real>::AQuaternion(const AVectorType& axis, Real angle) noexcept(gAssert < 1 || gMathematicsAssert < 1)
    : w{}, x{}, y{}, z{}
{
    MATHEMATICS_ASSERTION_1(axis.IsNormalize(), "axis�����ǵ�λ������");

    FromAxisAngle(axis, angle);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::AQuaternion<Real>::FromAxisAngle(const AVectorType& axis, Real angle) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_1(axis.IsNormalize(), "axis�����ǵ�λ������");

    // ������ת����Ԫ����
    // q = cos(A/2) + sin(A/2) * (x * i + y * j + z * k)

    const auto halfAngle = MathType::GetRational(1, 2) * angle;

    const auto sinValue = MathType::Sin(halfAngle);
    w = MathType::Cos(halfAngle);

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

    THROW_EXCEPTION(SYSTEM_TEXT("��������"s))
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

    if (MathType::FAbs(scalar) <= MathType::GetZeroTolerance())
    {
        MATHEMATICS_ASSERTION_1(false, "�������");

        w = MathType::maxReal;
        x = MathType::maxReal;
        y = MathType::maxReal;
        z = MathType::maxReal;
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
typename Mathematics::AQuaternion<Real>::MatrixType Mathematics::AQuaternion<Real>::ToRotationMatrix() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto twoX = MathType::GetValue(2) * x;
    const auto twoY = MathType::GetValue(2) * y;
    const auto twoZ = MathType::GetValue(2) * z;
    const auto twoWX = twoX * w;
    const auto twoWY = twoY * w;
    const auto twoWZ = twoZ * w;
    const auto twoXX = twoX * x;
    const auto twoXY = twoY * x;
    const auto twoXZ = twoZ * x;
    const auto twoYY = twoY * y;
    const auto twoYZ = twoZ * y;
    const auto twoZZ = twoZ * z;

    return MatrixType{ MathType::GetValue(1) - (twoYY + twoZZ),
                   twoXY - twoWZ,
                   twoXZ + twoWY,
                   MathType::GetValue(0),

                   twoXY + twoWZ,
                   MathType::GetValue(1) - (twoXX + twoZZ),
                   twoYZ - twoWX,
                   MathType::GetValue(0),

                   twoXZ - twoWY,
                   twoYZ + twoWX,
                   MathType::GetValue(1) - (twoXX + twoYY),
                   MathType::GetValue(0),

                   MathType::GetValue(0),
                   MathType::GetValue(0),
                   MathType::GetValue(0),
                   MathType::GetValue(1) };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::AQuaternion<Real>::AVectorType Mathematics::AQuaternion<Real>::ToAxis() const noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    // ������ת����Ԫ����
    // q = cos(A/2) + sin(A/2) * (x*i + y*j + z*k)

    const auto squareLength = x * x + y * y + z * z;

    if (MathType::GetZeroTolerance() < squareLength)
    {
        const auto invLength = MathType::InvSqrt(squareLength);

        return AVectorType{ x * invLength, y * invLength, z * invLength };
    }
    else
    {
        // �Ƕ��� 0 (2 * pi��ģ), �����κ��ᶼ�С�
        return AVectorType::GetUnitX();
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics ::AQuaternion<Real>::ToAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto squareLength = x * x + y * y + z * z;

    if (MathType::GetZeroTolerance() < squareLength)
    {
        return MathType::GetValue(2) * MathType::ACos(w);
    }
    else
    {
        return MathType::GetValue(0);
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::AQuaternion<Real>::Length() const noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return MathType::Sqrt(SquaredLength());
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
        MATHEMATICS_ASSERTION_1(false, "��Ԫ�����򻯴���");

        w = MathType::GetValue(0);
        x = MathType::GetValue(0);
        y = MathType::GetValue(0);
        z = MathType::GetValue(0);
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::AQuaternion<Real>::IsNormalize(Real epsilon) const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto length = Length();

    if (MathType::FAbs(length - MathType::GetValue(1)) <= epsilon)
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

    if (MathType::GetZeroTolerance() < norm)
    {
        return AQuaternion{ w / norm, -x / norm, -y / norm, -z / norm };
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "����һ����Ч�Ľ������Ǵ���");

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
    MATHEMATICS_ASSERTION_1(MathType::FAbs(w) <= MathType::GetZeroTolerance(), "��Ԫ��w�������0��");

    // ��� q = A * (x * i + y * j + z * k) ���� (x,y,z) �ǵ�λ���ȣ�Ȼ��
    // exp(q) = cos(A) + sin(A) * (x * i + y * j + z * k)��
    // ��� sin(A) �ǽӽ�Ϊ��,
    // ʹ�� exp(q) = cos(A) + A * (x * i + y * j + z * k) ��Ϊ A/sin(A) ������ 1��

    AQuaternion result{};

    const auto angle = MathType::Sqrt(x * x + y * y + z * z);

    const auto sinValue = MathType::Sin(angle);
    result.w = MathType::Cos(angle);

    if (MathType::GetZeroTolerance() <= MathType::FAbs(sinValue))
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

    // ��� q = cos(A) + sin(A) * (x * i + y * j + z * k) ���� (x,y,z) �ǵ�λ����,
    // Ȼ�� log(q) = A * (x * i + y * j + z * k)��
    // ��� sin(A) �ǽӽ��㣬
    // ʹ�� log(q) = sin(A) * (x * i + y * j + z * k)
    // ��Ϊ A/sin(A) ������ 1��

    AQuaternion result{ *this };
    result.w = MathType::GetValue(0);

    if (MathType::FAbs(w) < MathType::GetValue(1))
    {
        const auto angle = MathType::ACos(w);
        const auto sinValue = MathType::Sin(angle);
        if (MathType::GetZeroTolerance() <= MathType::FAbs(sinValue))
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
typename Mathematics::AQuaternion<Real>::AVectorType Mathematics::AQuaternion<Real>::Rotate(const AVectorType& vector) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    // ����һ������u = (x0,y0,z0)�͵�λ���ȵ���Ԫ��q = <w,x,y,z>
    // ����v = (x1,y1,z1)��������uʹ��q��תΪv = q * u * q^{-1}��
    // ����*��ʾ��Ԫ���˷�������u����Ϊ��Ԫ��<0,x0,y0,z0>��
    // ��Ҫע�����q^{-1} = <w,-x,-y,-z>��
    // ����û�������Ĺ���ȥȡq���档

    // ����
    // q * u * q^{-1} = q * <0,x0,y0,z0> * q^{-1}
    //                = q * (x0 * i + y0 * j + z0 * k) * q^{-1}
    //                = x0 * (q * i * q^{-1}) + y0 * (q * j * q^{-1}) + z0 * (q * k * q^{-1})
    //
    // �Ǽ�����HQuaternion<Real>::ToRotationMatrix����ת������С�
    // ����v�������Ϊ������u����ת����ĳ˻���
    // ��ˣ���ת�������Ԫ����ʾ����Ҫ�Ⱦ�����ٵĿռ�͸����ʱ����������ת���������
    // ���͵Ŀռ䡪��ʱ��Ȩ�⡭��

    const auto matrix = ToRotationMatrix();

    return matrix * vector;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::AQuaternion<Real>::Slerp(Real t, const AQuaternion& quaternion0, const AQuaternion& quaternion1) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto cosValue = Dot(quaternion0, quaternion1);
    const auto angle = MathType::ACos(cosValue);

    if (MathType::GetZeroTolerance() <= MathType::FAbs(angle))
    {
        const auto sinValue = MathType::Sin(angle);
        const auto tAngle = t * angle;
        const auto coefficient0 = MathType::Sin(angle - tAngle) / sinValue;
        const auto coefficient1 = MathType::Sin(tAngle) / sinValue;

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
                            "quaternion0��quaternion1��quaternion2���붼�ǵ�λ���ȣ�");

    const auto quaternion1Conjugate = quaternion1.Conjugate();
    const auto p0 = quaternion1Conjugate * quaternion0;
    const auto p2 = quaternion1Conjugate * quaternion2;

    const auto arg = -MathType::GetRational(1, 4) * (p0.Log() + p2.Log());
    *this = quaternion1 * arg.Exp();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::AQuaternion<Real>::Squad(Real t, const AQuaternion& q0, const AQuaternion& a0, const AQuaternion& a1, const AQuaternion& q1) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto slerpT = MathType::GetValue(2) * t * (MathType::GetValue(1) - t);

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
