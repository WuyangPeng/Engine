///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/10 15:59)

#ifndef MATHEMATICS_ALGEBRA_QUATERNION_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_QUATERNION_ACHIEVE_H

#include "Matrix3.h"
#include "Quaternion.h"
#include "QuaternionSwingTwistDetail.h"
#include "Vector3DTools.h"
#include "Flags/QuaternionFlags.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"

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

    // �㷨��Ken Shoemake�����£���1987��SIGGRAPH�γ����¡���Ԫ΢���ֺͿ��ٶ�������

    auto trace = matrix.GetValue<0, 0>() + matrix.GetValue<1, 1>() + matrix.GetValue<2, 2>();

    if (Math::GetValue(0) < trace)
    {
        // |w| > 1/2, ����ѡ�� w > 1/2
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
Mathematics::Quaternion<Real>::Quaternion(const Vector3D& axis, Real angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
    : m_W{}, m_X{}, m_Y{}, m_Z{}
{
    MATHEMATICS_ASSERTION_1(axis.IsNormalize(), "axis�����ǵ�λ������");

    FromAxisAngle(axis, angle);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
void Mathematics::Quaternion<Real>::FromAxisAngle(const Vector3D& axis, Real angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_1(axis.IsNormalize(), "axis�����ǵ�λ������");

    // ������ת����Ԫ����
    //   q = cos(A/2) + sin(A/2) * (x * i + y * j + z * k)

    auto halfAngle = Math::GetRational(1, 2) * angle;

    auto sinValue = Math::Sin(halfAngle);
    m_W = Math::Cos(halfAngle);

    m_X = sinValue * axis.GetX();
    m_Y = sinValue * axis.GetY();
    m_Z = sinValue * axis.GetZ();
}

template <typename Real>
Mathematics::Quaternion<Real>::Quaternion(const ContainerType& rotationColumn)
    : m_W{}, m_X{}, m_Y{}, m_Z{}
{
    if (rotationColumn.size() != sm_Z)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���ݴ�С����"s));
    }

    FromRotationColumnVector3D(rotationColumn);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
void Mathematics::Quaternion<Real>::FromRotationColumnVector3D(const ContainerType& rotationColumn)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (rotationColumn.size() != sm_Z)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���ݴ�С����"s));
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

    THROW_EXCEPTION(SYSTEM_TEXT("��������"s));
}

template <typename Real>
Real& Mathematics::Quaternion<Real>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_0(0 <= index && index < sm_EntrySize, "��������");

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
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::operator-() const noexcept
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
Mathematics::Quaternion<Real>& Mathematics::Quaternion<Real>::operator/=(Real scalar) noexcept
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
typename const Mathematics::Quaternion<Real>::Matrix3 Mathematics::Quaternion<Real>::ToRotationMatrix() const noexcept
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

    return Matrix3{ Math::GetValue(1) - (twoYY + twoZZ), twoXY - twoWZ, twoXZ + twoWY,
                    twoXY + twoWZ, Math::GetValue(1) - (twoXX + twoZZ), twoYZ - twoWX,
                    twoXZ - twoWY, twoYZ + twoWX, Math::GetValue(1) - (twoXX + twoYY) };
}

template <typename Real>
typename const Mathematics::Quaternion<Real>::ContainerType Mathematics::Quaternion<Real>::ToRotationColumnVector3D() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto matrix = ToRotationMatrix();

    ContainerType container{};

    for (auto column = 0; column < Matrix3::sm_Z; ++column)
    {
        container.emplace_back(matrix(Vector3D::sm_X, column), matrix(Vector3D::sm_Y, column), matrix(Vector3D::sm_Z, column));
    }

    MATHEMATICS_ASSERTION_1(container.size() == Matrix3::sm_Z, "���ص�������С����");

    return container;
}

template <typename Real>
typename const Mathematics::Quaternion<Real>::Vector3D Mathematics::Quaternion<Real>::ToAxis() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    // ������ת����Ԫ����
    //   q = cos(A/2) + sin(A/2) * (x*i + y*j + z*k)

    auto sqrareLength = m_X * m_X + m_Y * m_Y + m_Z * m_Z;

    if (Math::GetZeroTolerance() < sqrareLength)
    {
        auto invLength = Math::InvSqrt(sqrareLength);

        return Vector3D{ m_X * invLength, m_Y * invLength, m_Z * invLength };
    }
    else
    {
        // �Ƕ��� 0 (2 * pi��ģ), �����κ��ᶼ�С�
        return Vector3D::GetUnitX();
    }
}

template <typename Real>
Real Mathematics::Quaternion<Real>::ToAngle() const noexcept
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
typename const Mathematics::Quaternion<Real>::Matrix3Extract Mathematics::Quaternion<Real>::ToAngleAxis() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix3Extract{ ToAngle(), ToAxis() };
}

template <typename Real>
Real Mathematics::Quaternion<Real>::Length() const noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
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
void Mathematics::Quaternion<Real>::Normalize(Real epsilon) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
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
        MATHEMATICS_ASSERTION_1(false, "��Ԫ�����򻯴���");

        m_W = Math::GetValue(0);
        m_X = Math::GetValue(0);
        m_Y = Math::GetValue(0);
        m_Z = Math::GetValue(0);
    }
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::Inverse() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto norm = SquaredLength();

    if (Math::GetZeroTolerance() < norm)
    {
        return Quaternion{ m_W / norm, -m_X / norm, -m_Y / norm, -m_Z / norm };
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "����һ����Ч�Ľ������Ǵ���");

        return Quaternion{};
    }
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::Conjugate() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Quaternion{ m_W, -m_X, -m_Y, -m_Z };
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::Exp() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    MATHEMATICS_ASSERTION_1(Math::FAbs(m_W) <= Math::GetZeroTolerance(), "��Ԫ��w�������0��");

    // ��� q = A * (x*i+y*j+z*k) ���� (x,y,z) �ǵ�λ���ȣ�Ȼ��
    // exp(q) = cos(A) + sin(A)*(x*i+y*j+z*k)��
    // ��� sin(A) �ǽӽ�Ϊ��,
    // ʹ�� exp(q) = cos(A) + A*(x*i+y*j+z*k) ��Ϊ A/sin(A) ������ 1��

    Quaternion result{};

    auto angle = Math::Sqrt(m_X * m_X + m_Y * m_Y + m_Z * m_Z);

    auto sinValue = Math::Sin(angle);
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
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::Log() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    // ��� q = cos(A) + sin(A) * (x*i+y*j+z*k) ���� (x,y,z) �ǵ�λ����,
    // Ȼ�� log(q) = A * (x*i+y*j+z*k)��
    // ��� sin(A) �ǽӽ��㣬
    // ʹ�� log(q) = sin(A) * (x*i+y*j+z*k)
    // ��Ϊ A/sin(A) ������ 1��

    Quaternion result{ *this };
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
typename const Mathematics::Quaternion<Real>::Vector3D Mathematics::Quaternion<Real>::Rotate(const Vector3D& vector) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    // ����һ������u = (x0,y0,z0)�͵�λ���ȵ���Ԫ��q = <w,x,y,z>
    // ����v = (x1,y1,z1)��������uʹ��q��תΪv = q * u * q^{-1}��
    // ����*��ʾ��Ԫ���˷�������u����Ϊ��Ԫ��<0,x0,y0,z0>��
    // ��Ҫע�����q^{-1} = <w,-x,-y,-z>��
    // ����û�������Ĺ���ȥȡq���档

    // ����
    //   q * u * q^{-1} = q * <0,x0,y0,z0> * q^{-1}
    //     = q * (x0 * i + y0 * j + z0 * k) * q^{-1}
    //     = x0 * (q * i * q^{-1}) + y0 * (q * j * q^{-1}) + z0 * (q * k * q^{-1})
    //
    // �Ǽ�����Quaternion<Real>::ToRotationMatrix����ת������С�
    // ����v�������Ϊ������u����ת����ĳ˻���
    // ��ˣ���ת�������Ԫ����ʾ��
    // ��Ҫ�Ⱦ�����ٵĿռ�͸����ʱ����������ת���������
    // ���͵Ŀռ䡪��ʱ��Ȩ�⡭��

    const auto matrix = ToRotationMatrix();

    return matrix * vector;
}

template <typename Real>
void Mathematics::Quaternion<Real>::Slerp(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1) noexcept
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
void Mathematics::Quaternion<Real>::SlerpExtraSpins(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1, int extraSpins) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto cosValue = Dot(quaternion0, quaternion1);
    auto angle = Math::ACos(cosValue);

    if (Math::GetZeroTolerance() <= Math::FAbs(angle))
    {
        auto sinValue = Math::Sin(angle);
        auto phase = Math::GetPI() * extraSpins * t;

        auto coeff0 = Math::Sin((Math::GetValue(1) - t) * angle - phase) / sinValue;
        auto coeff1 = Math::Sin(t * angle + phase) / sinValue;

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
bool Mathematics::Quaternion<Real>::IsNormalize(Real epsilon) const noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto length = Length();

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
                            "quaternion0��quaternion1��quaternion2���붼�ǵ�λ���ȣ�");

    const auto quaternion1Conjugate = quaternion1.Conjugate();
    const auto p0 = quaternion1Conjugate * quaternion0;
    const auto p2 = quaternion1Conjugate * quaternion2;

    auto arg = -Math::GetRational(1, 4) * (p0.Log() + p2.Log());

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
void Mathematics::Quaternion<Real>::Align(const Vector3D& vector0, const Vector3D& vector1, Real epsilon)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_1(vector0.IsNormalize(epsilon) && vector1.IsNormalize(epsilon), "vector0��vector1�����ǵ�λ������");

    // ���vector0��vector1�ǲ�ƽ�еģ�
    // ��ת�����ǵ�λ���ȵ�����
    // U = Cross(vector0,vector1)/Length(Cross(vector0,vector1))��
    // ��ת�Ƕ�AΪvector0��vector1֮��ĽǶȡ�
    // ��ת����Ԫ��Ϊq = cos(A/2) + sin(A/2) * (ux * i + uy * j + uz * k)��
    // ����U = (ux,uy,uz)��
    //
    // (1) ������ȡA = acos(Dot(vector0,vector1))��
    //     ����1/2��Ȼ�����sin(A/2)��cos(A/2)��
    //     ���Ǽ��ټ���ɱ�ȥ����ƽ����
    //     B = (vector0 + vector1)/Length(vector0 + vector1)��
    //     �Ӷ�cos(A/2) =  Dot(vector0,B)��
    //
    // (2) ��ת��ΪU = Cross(vector0,B)/Length(Cross(vector0,B))��
    //     �� Length(Cross(vector0,B)) =
    //     Length(vector0) * Length(B) * sin(A/2) = sin(A/2)��
    //     ����������£�sin(A/2) * (ux * i + uy * j + uz * k) = (cx * i + cy * j + cz * k)��
    //     ����C = Cross(vector0,B)��
    //
    // ���vector0 = vector1��
    // ��B = vector0�� cos(A/2) = 1, and U = (0,0,0)��
    // ���vector0 = -vector1����B = 0��
    // ����������£�A = pi�ʹ�ֱ��vector0���κ��ᶼ���Ա�������ת�ᡣ

    auto bisector = vector0 + vector1;
    if (Math::Approximate(Vector3DTools::VectorMagnitude(bisector), Math::GetValue(0), epsilon))
    {
        bisector.ZeroOut();
    }
    else
    {
        bisector.Normalize(epsilon);
    }

    auto cosHalfAngle = Vector3DTools::DotProduct(vector0, bisector);

    m_W = cosHalfAngle;

    if (!Math::Approximate(cosHalfAngle, Math::GetValue(0), epsilon))
    {
        const auto cross = Vector3DTools::CrossProduct(vector0, bisector);
        m_X = cross.GetX();
        m_Y = cross.GetY();
        m_Z = cross.GetZ();
    }
    else
    {
        if (Math::FAbs(vector0.GetY()) <= Math::FAbs(vector0.GetX()))
        {
            // V1.x��V1.z������ģ����ɲ��֡�
            auto invLength = Math::InvSqrt(vector0.GetX() * vector0.GetX() + vector0.GetZ() * vector0.GetZ());
            m_X = -vector0.GetZ() * invLength;
            m_Y = Math::GetValue(0);
            m_Z = +vector0.GetX() * invLength;
        }
        else
        {
            // V1.y��V1.z������ģ����ɲ��֡�
            auto invLength = Math::InvSqrt(vector0.GetY() * vector0.GetY() + vector0.GetZ() * vector0.GetZ());
            m_X = Math::GetValue(0);
            m_Y = +vector0.GetZ() * invLength;
            m_Z = -vector0.GetY() * invLength;
        }
    }
}

template <typename Real>
typename const Mathematics::Quaternion<Real>::QuaternionSwingTwist Mathematics::Quaternion<Real>::DecomposeTwistTimesSwing(const Vector3D& vector, Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto rotate = Rotate(vector);
    Quaternion swing{};
    swing.Align(vector, rotate, epsilon);
    const auto twist = (*this) * swing.Conjugate();

    return QuaternionSwingTwist{ swing, twist };
}

template <typename Real>
typename const Mathematics::Quaternion<Real>::QuaternionSwingTwist Mathematics::Quaternion<Real>::DecomposeSwingTimesTwist(const Vector3D& vector, Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto rotate = Rotate(vector);
    Quaternion swing{};
    swing.Align(vector, rotate, epsilon);
    const auto twist = swing.Conjugate() * (*this);

    return QuaternionSwingTwist{ swing, twist };
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestX() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetClosest(QuaternionClosestAxis::X);
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestY() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetClosest(QuaternionClosestAxis::Y);
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestZ() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetClosest(QuaternionClosestAxis::Z);
}

// private
template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosest(QuaternionClosestAxis axis) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto axisIndex = System::EnumCastUnderlying(axis);

    // �ʵ��ķ���������ں���������á�
    Quaternion quaternion{};
    const auto p0 = m_W;
    const auto p1 = (*this)[axisIndex];
    const auto sqrLength = p0 * p0 + p1 * p1;
    if (Math::GetZeroTolerance() < sqrLength)
    {
        // Ψһ������㡣
        auto invLength = Math::InvSqrt(sqrLength);
        quaternion.SetW(p0 * invLength);
        quaternion[axisIndex] = p1 * invLength;
    }
    else
    {
        // �����⣬ѡ��theta = 0��
        quaternion.SetW(Math::GetValue(1));
        quaternion[axisIndex] = Math::GetValue(0);
    }

    return quaternion;
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestXY() const noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
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
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestYX() const noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const Quaternion alt{ m_W, m_X, m_Y, -m_Z };

    auto quaternion = alt.GetClosestXY();
    quaternion.SetZ(-quaternion.GetZ());

    return quaternion;
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestZX() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const Quaternion alt{ m_W, m_X, m_Z, m_Y };

    auto quaternion = alt.GetClosestXY();
    std::swap(quaternion[Quaternion::sm_Y], quaternion[Quaternion::sm_Z]);

    return quaternion;
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestXZ() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const Quaternion alt{ m_W, m_X, -m_Z, m_Y };

    auto quaternion = alt.GetClosestXY();

    const auto save = quaternion[Quaternion::sm_Y];
    quaternion[Quaternion::sm_Y] = quaternion[Quaternion::sm_Z];
    quaternion[Quaternion::sm_Z] = -save;

    return quaternion;
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestYZ() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const Quaternion alt{ m_W, m_Y, m_Z, m_X };

    auto quaternion = alt.GetClosestXY();
    const auto save = quaternion[Quaternion::sm_Z];
    quaternion[Quaternion::sm_Z] = quaternion[Quaternion::sm_Y];
    quaternion[Quaternion::sm_Y] = quaternion[Quaternion::sm_X];
    quaternion[Quaternion::sm_X] = save;

    return quaternion;
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestZY() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const Quaternion alt{ m_W, m_Y, m_Z, -m_X };

    auto quaternion = alt.GetClosestXY();
    const auto save = quaternion[Quaternion::sm_Z];
    quaternion[Quaternion::sm_Z] = quaternion[Quaternion::sm_Y];
    quaternion[Quaternion::sm_Y] = quaternion[Quaternion::sm_X];
    quaternion[Quaternion::sm_X] = -save;

    return quaternion;
}

template <typename Real>
typename const Mathematics::Quaternion<Real>::QuaternionFactor Mathematics::Quaternion<Real>::FactorXYZ() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return QuaternionFactor{ *this, QuaternionFactorFlags::XYZ };
}

template <typename Real>
typename const Mathematics::Quaternion<Real>::QuaternionFactor Mathematics::Quaternion<Real>::FactorXZY() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return QuaternionFactor{ *this, QuaternionFactorFlags::XZY };
}

template <typename Real>
typename const Mathematics::Quaternion<Real>::QuaternionFactor Mathematics::Quaternion<Real>::FactorYZX() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return QuaternionFactor{ *this, QuaternionFactorFlags::YZX };
}

template <typename Real>
typename const Mathematics::Quaternion<Real>::QuaternionFactor Mathematics::Quaternion<Real>::FactorYXZ() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return QuaternionFactor{ *this, QuaternionFactorFlags::YXZ };
}

template <typename Real>
typename const Mathematics::Quaternion<Real>::QuaternionFactor Mathematics::Quaternion<Real>::FactorZXY() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return QuaternionFactor{ *this, QuaternionFactorFlags::ZXY };
}

template <typename Real>
typename const Mathematics::Quaternion<Real>::QuaternionFactor Mathematics::Quaternion<Real>::FactorZYX() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return QuaternionFactor{ *this, QuaternionFactorFlags::ZYX };
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestX(const QuaternionConstraints& xCon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetClosest(QuaternionClosestAxis::X, xCon);
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestY(const QuaternionConstraints& yCon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetClosest(QuaternionClosestAxis::Y, yCon);
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestZ(const QuaternionConstraints& zCon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetClosest(QuaternionClosestAxis::Z, zCon);
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosest(QuaternionClosestAxis axis, const QuaternionConstraints& con) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    // ��Ԫ�س�ʼ��Ϊ��
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
            // ���ֵ�������ڲ���
            quaternion.SetW(p0);
            quaternion[System::EnumCastUnderlying(axis)] = p1;
        }
        else
        {
            // ���ֵ�����ڱ߽��
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
        // �����⣬ѡ��һ������ĽǶ�Լ����
        quaternion.SetW(con.GetCosAvrAngle());
        quaternion[System::EnumCastUnderlying(axis)] = con.GetSinAvrAngle();
    }

    return quaternion;
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestXY(const QuaternionConstraints& xCon, const QuaternionConstraints& yCon) const
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
            // ���ֵ�������ڲ��㡣
            return Quaternion{ c0 * c1, s0 * c1, c0 * s1, s0 * s1 };
        }
        else
        {
            // ���ֵ�����ڱ߽�㡣
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
        // �����⣬ѡ��һ������Լ���ĽǶȡ�
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

                MATHEMATICS_ASSERTION_1(minAngle <= angle && angle <= maxAngle, "angle��ֵ������minAngle��maxAngle֮�䣡");
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

                MATHEMATICS_ASSERTION_1(minAngle <= angle && angle <= maxAngle, "angle��ֵ������minAngle��maxAngle֮�䣡");
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
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestYX(const QuaternionConstraints& yCon, const QuaternionConstraints& xCon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const Quaternion alt{ m_W, m_X, m_Y, -m_Z };

    auto quaternion = alt.GetClosestXY(xCon, yCon);
    quaternion.SetZ(-quaternion.GetZ());

    return quaternion;
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestZX(const QuaternionConstraints& zCon, const QuaternionConstraints& xCon) const
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
            // ���ֵ�������ڲ��㡣
            return Quaternion{ c2 * c0, c2 * s0, s2 * s0, s2 * c0 };
        }
        else
        {
            // ���ֵ�����ڱ߽�㡣
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
        // �����⣬ѡ��һ������Լ���ĽǶȡ�
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

                MATHEMATICS_ASSERTION_1(minAngle <= angle && angle <= maxAngle, "angle��ֵ������minAngle��maxAngle֮�䣡");
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

                MATHEMATICS_ASSERTION_1(minAngle <= angle && angle <= maxAngle, "angle��ֵ������minAngle��maxAngle֮�䣡");
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
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestXZ(const QuaternionConstraints& xCon, const QuaternionConstraints& zCon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const Quaternion alt{ m_W, m_X, -m_Y, m_Z };

    auto quaternion = alt.GetClosestZX(zCon, xCon);
    quaternion.SetY(-quaternion.GetY());

    return quaternion;
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestZY(const QuaternionConstraints& zCon, const QuaternionConstraints& yCon) const
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
            // ���ֵ�������ڲ��㡣
            return Quaternion{ c2 * c1, -s2 * s1, c2 * s1, s2 * c1 };
        }
        else
        {
            // ���ֵ�����ڱ߽�㡣
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
        /// �����⣬ѡ��һ������Լ���ĽǶȡ�
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

                MATHEMATICS_ASSERTION_1(minAngle <= angle && angle <= maxAngle, "angle��ֵ������minAngle��maxAngle֮�䣡");
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

                MATHEMATICS_ASSERTION_1(minAngle <= angle && angle <= maxAngle, "angle��ֵ������minAngle��maxAngle֮�䣡");
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
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>::GetClosestYZ(const QuaternionConstraints& yCon, const QuaternionConstraints& zCon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const Quaternion alt{ m_W, -m_X, m_Y, m_Z };

    auto quaternion = alt.GetClosestZY(zCon, yCon);
    quaternion.SetX(-quaternion.GetX());

    return quaternion;
}

template <typename T>
const typename Mathematics::Quaternion<T>::ArrayType Mathematics::Quaternion<T>::GetCoordinate() const noexcept
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
