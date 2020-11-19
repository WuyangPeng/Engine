///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/06 0:22)

#ifndef MATHEMATICS_ALGEBRA_MATRIX4_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_MATRIX4_ACHIEVE_H

#include "Matrix4.h"
#include "Vector3DTools.h"
#include "Vector4D.h"
#include "Vector4DTools.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::Matrix4<Real>::Matrix4(const ContainerType& entry, MatrixMajorFlags majorFlag)
    : m_X{}, m_Y{}, m_Z{}, m_W{}
{
    if (entry.size() != sm_MatrixSize)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���ݴ�С����"s));
    }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    if (majorFlag == MatrixMajorFlags::Row)
    {
        m_X.SetCoordinate(entry[0], entry[1], entry[2], entry[3]);
        m_Y.SetCoordinate(entry[4], entry[5], entry[6], entry[7]);
        m_Z.SetCoordinate(entry[8], entry[9], entry[10], entry[11]);
        m_W.SetCoordinate(entry[12], entry[13], entry[14], entry[15]);
    }
    else
    {
        m_X.SetCoordinate(entry[0], entry[4], entry[8], entry[12]);
        m_Y.SetCoordinate(entry[1], entry[5], entry[9], entry[13]);
        m_Z.SetCoordinate(entry[2], entry[6], entry[10], entry[14]);
        m_W.SetCoordinate(entry[3], entry[7], entry[11], entry[15]);
    }
#include STSTEM_WARNING_POP

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Matrix4<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::Matrix4<Real>::MakeZero() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X.ZeroOut();
    m_Y.ZeroOut();
    m_Z.ZeroOut();
    m_W.ZeroOut();
}

template <typename Real>
void Mathematics::Matrix4<Real>::MakeIdentity() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X = Vector4D::GetUnitX();
    m_Y = Vector4D::GetUnitY();
    m_Z = Vector4D::GetUnitZ();
    m_W = Vector4D::GetUnitW();
}

template <typename Real>
const Mathematics::Vector4D<Real>& Mathematics::Matrix4<Real>::operator[](int row) const
{
    MATHEMATICS_CLASS_IS_VALID_9;

    switch (System::UnderlyingCastEnum<VectorIndex>(row))
    {
        case VectorIndex::X:
            return m_X;
        case VectorIndex::Y:
            return m_Y;
        case VectorIndex::Z:
            return m_Z;
        case VectorIndex::W:
            return m_W;
        default:
            break;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("��������"s));
}

template <typename Real>
Mathematics::Vector4D<Real>& Mathematics::Matrix4<Real>::operator[](int row)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_0(0 <= row && row < sm_VectorSize, "��������");

    return OPERATOR_SQUARE_BRACKETS(Mathematics::Vector4D<Real>, row);
}

template <typename Real>
const Real& Mathematics::Matrix4<Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return (*this)[row][column];
}

template <typename Real>
Real& Mathematics::Matrix4<Real>::operator()(int row, int column)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_0(sm_X <= row && row < sm_VectorSize, "row��������");
    MATHEMATICS_ASSERTION_0(Vector4D::sm_X <= column && column < Vector4D::sm_PointSize, "column��������");

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)
    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, column));
#include STSTEM_WARNING_POP
}

template <typename Real>
const Mathematics::Matrix4<Real> Mathematics::Matrix4<Real>::operator-() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix4<Real>{ -m_X.GetX(), -m_X.GetY(), -m_X.GetZ(), -m_X.GetW(),
                          -m_Y.GetX(), -m_Y.GetY(), -m_Y.GetZ(), -m_Y.GetW(),
                          -m_Z.GetX(), -m_Z.GetY(), -m_Z.GetZ(), -m_Z.GetW(),
                          -m_W.GetX(), -m_W.GetY(), -m_W.GetZ(), -m_W.GetW() };
}

template <typename Real>
Mathematics::Matrix4<Real>& Mathematics::Matrix4<Real>::operator+=(const Matrix4& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X += rhs.m_X;
    m_Y += rhs.m_Y;
    m_Z += rhs.m_Z;
    m_W += rhs.m_W;

    return *this;
}

template <typename Real>
Mathematics::Matrix4<Real>& Mathematics::Matrix4<Real>::operator-=(const Matrix4& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X -= rhs.m_X;
    m_Y -= rhs.m_Y;
    m_Z -= rhs.m_Z;
    m_W -= rhs.m_W;

    return *this;
}

template <typename Real>
Mathematics::Matrix4<Real>& Mathematics::Matrix4<Real>::operator*=(Real scalar) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X *= scalar;
    m_Y *= scalar;
    m_Z *= scalar;
    m_W *= scalar;

    return *this;
}

template <typename Real>
Mathematics::Matrix4<Real>& Mathematics::Matrix4<Real>::operator/=(Real scalar) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X /= scalar;
    m_Y /= scalar;
    m_Z /= scalar;
    m_W /= scalar;

    return *this;
}

template <typename Real>
Real Mathematics::Matrix4<Real>::QuadraticForm(const Vector4D& lhs, const Vector4D& rhs) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return Vector4DTools::DotProduct(lhs, (*this) * rhs);
}

template <typename Real>
const Mathematics::Matrix4<Real> Mathematics::Matrix4<Real>::Transpose() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix4<Real>{ GetValue<0, 0>(), GetValue<1, 0>(), GetValue<2, 0>(), GetValue<3, 0>(),
                          GetValue<0, 1>(), GetValue<1, 1>(), GetValue<2, 1>(), GetValue<3, 1>(),
                          GetValue<0, 2>(), GetValue<1, 2>(), GetValue<2, 2>(), GetValue<3, 2>(),
                          GetValue<0, 3>(), GetValue<1, 3>(), GetValue<2, 3>(), GetValue<3, 3>() };
}

template <typename Real>
Mathematics::Matrix4<Real>& Mathematics::Matrix4<Real>::operator*=(const Matrix4& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    *this = *this * rhs;

    return *this;
}

template <typename Real>
const Mathematics::Matrix4<Real> Mathematics::Matrix4<Real>::Inverse(const Real epsilon) const
{
    // ��Ϸ��̾���1 02 isensee������һ���㷨��

    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto a0 = GetValue<0, 0>() * GetValue<1, 1>() - GetValue<0, 1>() * GetValue<1, 0>();
    const auto a1 = GetValue<0, 0>() * GetValue<1, 2>() - GetValue<0, 2>() * GetValue<1, 0>();
    const auto a2 = GetValue<0, 0>() * GetValue<1, 3>() - GetValue<0, 3>() * GetValue<1, 0>();
    const auto a3 = GetValue<0, 1>() * GetValue<1, 2>() - GetValue<0, 2>() * GetValue<1, 1>();
    const auto a4 = GetValue<0, 1>() * GetValue<1, 3>() - GetValue<0, 3>() * GetValue<1, 1>();
    const auto a5 = GetValue<0, 2>() * GetValue<1, 3>() - GetValue<0, 3>() * GetValue<1, 2>();
    const auto b0 = GetValue<2, 0>() * GetValue<3, 1>() - GetValue<2, 1>() * GetValue<3, 0>();
    const auto b1 = GetValue<2, 0>() * GetValue<3, 2>() - GetValue<2, 2>() * GetValue<3, 0>();
    const auto b2 = GetValue<2, 0>() * GetValue<3, 3>() - GetValue<2, 3>() * GetValue<3, 0>();
    const auto b3 = GetValue<2, 1>() * GetValue<3, 2>() - GetValue<2, 2>() * GetValue<3, 1>();
    const auto b4 = GetValue<2, 1>() * GetValue<3, 3>() - GetValue<2, 3>() * GetValue<3, 1>();
    const auto b5 = GetValue<2, 2>() * GetValue<3, 3>() - GetValue<2, 3>() * GetValue<3, 2>();

    const auto det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;
    if (epsilon < Math::FAbs(det))
    {
        Matrix4 adjoint{ GetValue<1, 1>() * b5 - GetValue<1, 2>() * b4 + GetValue<1, 3>() * b3,
                         -GetValue<0, 1>() * b5 + GetValue<0, 2>() * b4 - GetValue<0, 3>() * b3,
                         GetValue<3, 1>() * a5 - GetValue<3, 2>() * a4 + GetValue<3, 3>() * a3,
                         -GetValue<2, 1>() * a5 + GetValue<2, 2>() * a4 - GetValue<2, 3>() * a3,
                         -GetValue<1, 0>() * b5 + GetValue<1, 2>() * b2 - GetValue<1, 3>() * b1,
                         GetValue<0, 0>() * b5 - GetValue<0, 2>() * b2 + GetValue<0, 3>() * b1,
                         -GetValue<3, 0>() * a5 + GetValue<3, 2>() * a2 - GetValue<3, 3>() * a1,
                         GetValue<2, 0>() * a5 - GetValue<2, 2>() * a2 + GetValue<2, 3>() * a1,
                         GetValue<1, 0>() * b4 - GetValue<1, 1>() * b2 + GetValue<1, 3>() * b0,
                         -GetValue<0, 0>() * b4 + GetValue<0, 1>() * b2 - GetValue<0, 3>() * b0,
                         GetValue<3, 0>() * a4 - GetValue<3, 1>() * a2 + GetValue<3, 3>() * a0,
                         -GetValue<2, 0>() * a4 + GetValue<2, 1>() * a2 - GetValue<2, 3>() * a0,
                         -GetValue<1, 0>() * b3 + GetValue<1, 1>() * b1 - GetValue<1, 2>() * b0,
                         GetValue<0, 0>() * b3 - GetValue<0, 1>() * b1 + GetValue<0, 2>() * b0,
                         -GetValue<3, 0>() * a3 + GetValue<3, 1>() * a1 - GetValue<3, 2>() * a0,
                         GetValue<2, 0>() * a3 - GetValue<2, 1>() * a1 + GetValue<2, 2>() * a0 };

        adjoint /= det;

        return adjoint;
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "�þ��󲻴��������");

        return GetZero();
    }
}

template <typename Real>
const Mathematics::Matrix4<Real> Mathematics::Matrix4<Real>::Adjoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto a0 = GetValue<0, 0>() * GetValue<1, 1>() - GetValue<0, 1>() * GetValue<1, 0>();
    const auto a1 = GetValue<0, 0>() * GetValue<1, 2>() - GetValue<0, 2>() * GetValue<1, 0>();
    const auto a2 = GetValue<0, 0>() * GetValue<1, 3>() - GetValue<0, 3>() * GetValue<1, 0>();
    const auto a3 = GetValue<0, 1>() * GetValue<1, 2>() - GetValue<0, 2>() * GetValue<1, 1>();
    const auto a4 = GetValue<0, 1>() * GetValue<1, 3>() - GetValue<0, 3>() * GetValue<1, 1>();
    const auto a5 = GetValue<0, 2>() * GetValue<1, 3>() - GetValue<0, 3>() * GetValue<1, 2>();
    const auto b0 = GetValue<2, 0>() * GetValue<3, 1>() - GetValue<2, 1>() * GetValue<3, 0>();
    const auto b1 = GetValue<2, 0>() * GetValue<3, 2>() - GetValue<2, 2>() * GetValue<3, 0>();
    const auto b2 = GetValue<2, 0>() * GetValue<3, 3>() - GetValue<2, 3>() * GetValue<3, 0>();
    const auto b3 = GetValue<2, 1>() * GetValue<3, 2>() - GetValue<2, 2>() * GetValue<3, 1>();
    const auto b4 = GetValue<2, 1>() * GetValue<3, 3>() - GetValue<2, 3>() * GetValue<3, 1>();
    const auto b5 = GetValue<2, 2>() * GetValue<3, 3>() - GetValue<2, 3>() * GetValue<3, 2>();

    return Matrix4<Real>{ GetValue<1, 1>() * b5 - GetValue<1, 2>() * b4 + GetValue<1, 3>() * b3,
                          -GetValue<0, 1>() * b5 + GetValue<0, 2>() * b4 - GetValue<0, 3>() * b3,
                          GetValue<3, 1>() * a5 - GetValue<3, 2>() * a4 + GetValue<3, 3>() * a3,
                          -GetValue<2, 1>() * a5 + GetValue<2, 2>() * a4 - GetValue<2, 3>() * a3,
                          -GetValue<1, 0>() * b5 + GetValue<1, 2>() * b2 - GetValue<1, 3>() * b1,
                          GetValue<0, 0>() * b5 - GetValue<0, 2>() * b2 + GetValue<0, 3>() * b1,
                          -GetValue<3, 0>() * a5 + GetValue<3, 2>() * a2 - GetValue<3, 3>() * a1,
                          GetValue<2, 0>() * a5 - GetValue<2, 2>() * a2 + GetValue<2, 3>() * a1,
                          GetValue<1, 0>() * b4 - GetValue<1, 1>() * b2 + GetValue<1, 3>() * b0,
                          -GetValue<0, 0>() * b4 + GetValue<0, 1>() * b2 - GetValue<0, 3>() * b0,
                          GetValue<3, 0>() * a4 - GetValue<3, 1>() * a2 + GetValue<3, 3>() * a0,
                          -GetValue<2, 0>() * a4 + GetValue<2, 1>() * a2 - GetValue<2, 3>() * a0,
                          -GetValue<1, 0>() * b3 + GetValue<1, 1>() * b1 - GetValue<1, 2>() * b0,
                          GetValue<0, 0>() * b3 - GetValue<0, 1>() * b1 + GetValue<0, 2>() * b0,
                          -GetValue<3, 0>() * a3 + GetValue<3, 1>() * a1 - GetValue<3, 2>() * a0,
                          GetValue<2, 0>() * a3 - GetValue<2, 1>() * a1 + GetValue<2, 2>() * a0 };
}

template <typename Real>
Real Mathematics::Matrix4<Real>::Determinant() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto a0 = GetValue<0, 0>() * GetValue<1, 1>() - GetValue<0, 1>() * GetValue<1, 0>();
    const auto a1 = GetValue<0, 0>() * GetValue<1, 2>() - GetValue<0, 2>() * GetValue<1, 0>();
    const auto a2 = GetValue<0, 0>() * GetValue<1, 3>() - GetValue<0, 3>() * GetValue<1, 0>();
    const auto a3 = GetValue<0, 1>() * GetValue<1, 2>() - GetValue<0, 2>() * GetValue<1, 1>();
    const auto a4 = GetValue<0, 1>() * GetValue<1, 3>() - GetValue<0, 3>() * GetValue<1, 1>();
    const auto a5 = GetValue<0, 2>() * GetValue<1, 3>() - GetValue<0, 3>() * GetValue<1, 2>();
    const auto b0 = GetValue<2, 0>() * GetValue<3, 1>() - GetValue<2, 1>() * GetValue<3, 0>();
    const auto b1 = GetValue<2, 0>() * GetValue<3, 2>() - GetValue<2, 2>() * GetValue<3, 0>();
    const auto b2 = GetValue<2, 0>() * GetValue<3, 3>() - GetValue<2, 3>() * GetValue<3, 0>();
    const auto b3 = GetValue<2, 1>() * GetValue<3, 2>() - GetValue<2, 2>() * GetValue<3, 1>();
    const auto b4 = GetValue<2, 1>() * GetValue<3, 3>() - GetValue<2, 3>() * GetValue<3, 1>();
    const auto b5 = GetValue<2, 2>() * GetValue<3, 3>() - GetValue<2, 3>() * GetValue<3, 2>();

    auto det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;

    return det;
}

template <typename Real>
void Mathematics::Matrix4<Real>::MakeObliqueProjection(const Vector3D& normal, const Vector3D& origin, const Vector3D& direction) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_1(normal.IsNormalize() && direction.IsNormalize(), "normal��direction�����ǵ�λ������");

    // ͶӰƽ����Dot(N,X-P) = 0 ��
    // ����N��һ��3��1����λ���ȵķ���������
    // P��һ��3��1����ƽ�档
    // ͶӰ����б��ƽ�棬3��1����D����
    // �ض�Dot(N,D)�����㣬��ͶӰ�����塣
    // ����һ��3��1��U�������� U+t*D��ƽ��Ľ����t = -Dot(N,U-P)/Dot(N,D)��
    // Ȼ��
    //
    //   projection(U) = P + [I - D * N^T / Dot(N,D)] * (U - P)
    //
    // һ��4��4����α任������
    //
    //       +-                                   -+
    //   M = | D * N^T - Dot(N,D) * I   -Dot(N,P)D |
    //       |           0^T            -Dot(N,D)  |
    //       +-                                   -+
    //
    // ����M������[U^T 1]^T Ϊ  M * [U^T 1]^T��
    // �þ���ѡ��Ϊÿ��Dot(N,D) < 0ʹ��M[3][3] > 0
    // ��ͶӰ��ƽ���ϵġ�����ࡱ����

    auto dotNormalDirection = Vector3DTools::DotProduct(normal, direction);
    auto dotNormalOrigin = Vector3DTools::DotProduct(normal, origin);

    m_X.SetCoordinate(direction.GetX() * normal.GetX() - dotNormalDirection, direction.GetX() * normal.GetY(),
                      direction.GetX() * normal.GetZ(), -dotNormalOrigin * direction.GetX());
    m_Y.SetCoordinate(direction.GetY() * normal.GetX(), direction.GetY() * normal.GetY() - dotNormalDirection,
                      direction.GetY() * normal.GetZ(), -dotNormalOrigin * direction.GetY());
    m_Z.SetCoordinate(direction.GetZ() * normal.GetX(), direction.GetZ() * normal.GetY(),
                      direction.GetZ() * normal.GetZ() - dotNormalDirection, -dotNormalOrigin * direction.GetZ());
    m_W.SetCoordinate(Math::GetValue(0), Math::GetValue(0), Math::GetValue(0), -dotNormalDirection);
}

template <typename Real>
void Mathematics::Matrix4<Real>::MakePerspectiveProjection(const Vector3D& normal, const Vector3D& origin, const Vector3D& eye)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_1(normal.IsNormalize(), "normal�����ǵ�λ������");

    //     +-                                                             -+
    // M = | Dot(N,E - P) * I - E * N^T    -(Dot(N,E - P)*I - E * N^T) * E |
    //     |        -N^t                      Dot(N,E)                     |
    //     +-                                                             -+normal
    //
    // ����EΪ�۵㣬PΪƽ���ϵ�һ���㣬��N�ǵ�λ���ȵ�ƽ�淨�ߡ�

    auto dotNormalDirection = Vector3DTools::DotProduct(normal, eye - origin);

    m_X.SetCoordinate(dotNormalDirection - eye.GetX() * normal.GetX(), -eye.GetX() * normal.GetY(), -eye.GetX() * normal.GetZ(),
                      -(GetValue<0, 0>() * eye.GetX() + GetValue<0, 1>() * eye.GetY() + GetValue<0, 2>() * eye.GetZ()));
    m_Y.SetCoordinate(-eye.GetY() * normal.GetX(), dotNormalDirection - eye.GetY() * normal.GetY(), -eye.GetY() * normal.GetZ(),
                      -(GetValue<1, 0>() * eye.GetX() + GetValue<1, 1>() * eye.GetY() + GetValue<1, 2>() * eye.GetZ()));
    m_Z.SetCoordinate(-eye.GetZ() * normal.GetX(), -eye.GetZ() * normal.GetY(), dotNormalDirection - eye.GetZ() * normal.GetZ(),
                      -(GetValue<2, 0>() * eye.GetX() + GetValue<2, 1>() * eye.GetY() + GetValue<2, 2>() * eye.GetZ()));
    m_W.SetCoordinate(-normal.GetX(), -normal.GetY(), -normal.GetZ(), Vector3DTools::DotProduct(normal, eye));
}

template <typename Real>
void Mathematics::Matrix4<Real>::MakeReflection(const Vector3D& normal, const Vector3D& origin) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_1(normal.IsNormalize(), "normal�����ǵ�λ������");

    //     +-                         -+
    // M = | I-2*N*N^T    2*Dot(N,P)*N |
    //     |     0^T            1      |
    //     +-                         -+
    //
    // ����P��ƽ���ϵĵ㣬N��һ����λ���ȵ�ƽ�淨�ߡ�

    auto twoDotNormalOrigin = Math::GetValue(2) * Vector3DTools::DotProduct(normal, origin);

    SetValue<0, 0>(Math::GetValue(1) - Math::GetValue(2) * normal.GetX() * normal.GetX());
    SetValue<0, 1>(-Math::GetValue(2) * normal.GetX() * normal.GetY());
    SetValue<0, 2>(-Math::GetValue(2) * normal.GetX() * normal.GetZ());
    SetValue<0, 3>(twoDotNormalOrigin * normal.GetX());

    SetValue<1, 0>(-Math::GetValue(2) * normal.GetY() * normal.GetX());
    SetValue<1, 1>(Math::GetValue(1) - Math::GetValue(2) * normal.GetY() * normal.GetY());
    SetValue<1, 2>(-Math::GetValue(2) * normal.GetY() * normal.GetZ());
    SetValue<1, 3>(twoDotNormalOrigin * normal.GetY());

    SetValue<2, 0>(-Math::GetValue(2) * normal.GetZ() * normal.GetX());
    SetValue<2, 1>(-Math::GetValue(2) * normal.GetZ() * normal.GetY());
    SetValue<2, 2>(Math::GetValue(1) - Math::GetValue(2) * normal.GetZ() * normal.GetZ());
    SetValue<2, 3>(twoDotNormalOrigin * normal.GetZ());

    SetValue<3, 0>(Math::GetValue(0));
    SetValue<3, 1>(Math::GetValue(0));
    SetValue<3, 2>(Math::GetValue(0));
    SetValue<3, 3>(Math::GetValue(1));
}

// ����������ƽ��ͷ����������ң������ף�����Զ��ֵ��ƽ��ͷ��߽硣
template <typename Real>
void Mathematics::Matrix4<Real>::MakeFrustumMatrix44(Real left, Real right, Real bottom, Real top, Real nearDistance, Real farDistance) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto width = right - left;
    auto height = top - bottom;
    auto depth = farDistance - nearDistance;

    SetValue<0, 0>((Math::GetValue(2) * nearDistance) / width);
    SetValue<0, 1>(Math::GetValue(0));
    SetValue<0, 2>(Math::GetValue(0));
    SetValue<0, 3>(Math::GetValue(0));

    SetValue<1, 0>(Math::GetValue(0));
    SetValue<1, 1>((Math::GetValue(2) * nearDistance) / height);
    SetValue<1, 2>(Math::GetValue(0));
    SetValue<1, 3>(Math::GetValue(0));

    SetValue<2, 0>((right + left) / width);
    SetValue<2, 1>((top + bottom) / height);
    SetValue<2, 2>(-(farDistance + nearDistance) / depth);
    SetValue<2, 3>(-Math::GetValue(1));

    SetValue<3, 0>(Math::GetValue(0));
    SetValue<3, 1>(Math::GetValue(0));
    SetValue<3, 2>(-(Math::GetValue(2) * farDistance * nearDistance) / depth);
    SetValue<3, 3>(Math::GetValue(0));
}

// ����һ��������������Y�����ϵ�������ͼ�Ķ�����Y/X���ݺ�ȣ����ҽ���Զƽ��ľ���
template <typename Real>
void Mathematics::Matrix4<Real>::MakePerspectiveMatrix44(Real fieldOfViewY, Real aspect, Real nearDistance, Real farDistance) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto angle = fieldOfViewY / Math::GetValue(2);
    // �Ƕ�ת���ɻ���
    angle *= Math::GetDegreeToRadian();

    auto cot = Math::Cos(angle) / Math::Sin(angle);

    SetValue<0, 0>(cot / aspect);
    SetValue<0, 1>(Math::GetValue(0));
    SetValue<0, 2>(Math::GetValue(0));
    SetValue<0, 3>(Math::GetValue(0));

    SetValue<1, 0>(Math::GetValue(0));
    SetValue<1, 1>(cot);
    SetValue<1, 2>(Math::GetValue(0));
    SetValue<1, 3>(Math::GetValue(0));

    SetValue<2, 0>(Math::GetValue(0));
    SetValue<2, 1>(Math::GetValue(0));
    SetValue<2, 2>(-(farDistance + nearDistance) / (farDistance - nearDistance));
    SetValue<2, 3>(-Math::GetValue(1));

    SetValue<3, 0>(Math::GetValue(0));
    SetValue<3, 1>(Math::GetValue(0));
    SetValue<3, 2>(-(Math::GetValue(2) * farDistance * nearDistance) / (farDistance - nearDistance));
    SetValue<3, 3>(Math::GetValue(0));
}

// �ɸ�������࣬�Ҳ࣬�ײ�����������ֵ����Զֵ����ƽ��ͷ��߽����������
template <typename Real>
void Mathematics::Matrix4<Real>::MakeOrthoMatrix44(Real left, Real right, Real bottom, Real top, Real nearDistance, Real farDistance) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto width = right - left;
    auto height = top - bottom;
    auto depth = farDistance - nearDistance;

    SetValue<0, 0>(Math::GetValue(2) / width);
    SetValue<0, 1>(Math::GetValue(0));
    SetValue<0, 2>(Math::GetValue(0));
    SetValue<0, 3>(Math::GetValue(0));

    SetValue<1, 0>(Math::GetValue(0));
    SetValue<1, 1>(Math::GetValue(2) / height);
    SetValue<1, 2>(Math::GetValue(0));
    SetValue<1, 3>(Math::GetValue(0));

    SetValue<2, 0>(Math::GetValue(0));
    SetValue<2, 1>(Math::GetValue(0));
    SetValue<2, 2>(-Math::GetValue(2) / depth);
    SetValue<2, 3>(Math::GetValue(0));

    SetValue<3, 0>(-(right + left) / width);
    SetValue<3, 1>(-(top + bottom) / height);
    SetValue<3, 2>(-(farDistance + nearDistance) / depth);
    SetValue<3, 3>(Math::GetValue(1));
}

// ����ʹ��3�������淶�������ķ������
template <typename Real>
void Mathematics::Matrix4<Real>::MakeOrthoNormalMatrix44(const Vector3D& xDirection, const Vector3D& yDirection, const Vector3D& zDirection) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_1(xDirection.IsNormalize() && yDirection.IsNormalize() && zDirection.IsNormalize(), "xDirection��yDirection��zDirection���ǵ�λ������");

    SetValue<0, 0>(xDirection.GetX());
    SetValue<0, 1>(yDirection.GetX());
    SetValue<0, 2>(zDirection.GetX());
    SetValue<0, 3>(Math::GetValue(0));

    SetValue<1, 0>(xDirection.GetY());
    SetValue<1, 1>(yDirection.GetY());
    SetValue<1, 2>(zDirection.GetY());
    SetValue<1, 3>(Math::GetValue(0));

    SetValue<2, 0>(xDirection.GetZ());
    SetValue<2, 1>(yDirection.GetZ());
    SetValue<2, 2>(zDirection.GetZ());
    SetValue<2, 3>(Math::GetValue(0));

    SetValue<3, 0>(Math::GetValue(0));
    SetValue<3, 1>(Math::GetValue(0));
    SetValue<3, 2>(Math::GetValue(0));
    SetValue<3, 3>(Math::GetValue(1));
}

template <typename T>
const typename Mathematics::Matrix4<T>::ArrayType Mathematics::Matrix4<T>::GetCoordinate() const noexcept
{
    return ArrayType{ m_X.GetX(), m_X.GetY(), m_X.GetZ(), m_X.GetW(),
                      m_Y.GetX(), m_Y.GetY(), m_Y.GetZ(), m_Y.GetW(),
                      m_Z.GetX(), m_Z.GetY(), m_Z.GetZ(), m_Z.GetW(),
                      m_W.GetX(), m_W.GetY(), m_W.GetZ(), m_W.GetW() };
}

template <typename T>
void Mathematics::Matrix4<T>::Set(const ArrayType& coordinate)
{
    auto index = 0;
    for (auto value : coordinate)
    {
        (*this)(index / sm_VectorSize, index % Vector4D::sm_PointSize) = value;

        ++index;
    }
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX4_ACHIEVE_H