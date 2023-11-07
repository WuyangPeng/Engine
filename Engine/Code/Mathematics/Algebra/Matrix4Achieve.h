///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 10:37)

#ifndef MATHEMATICS_ALGEBRA_MATRIX4_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_MATRIX4_ACHIEVE_H

#include "Matrix3Detail.h"
#include "Matrix4.h"
#include "Vector3Tools.h"
#include "Vector4.h"
#include "Vector4Tools.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/NumericalAnalysis/GaussianEliminationDetail.h"

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix4<Real>::Matrix4(const ContainerType& entry, MatrixMajorFlags majorFlag)
    : x{}, y{}, z{}, w{}
{
    if (entry.size() != matrixSize)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���ݴ�С����"s));
    }

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    if (majorFlag == MatrixMajorFlags::Row)
    {
        x.SetCoordinate(entry[0], entry[1], entry[2], entry[3]);
        y.SetCoordinate(entry[4], entry[5], entry[6], entry[7]);
        z.SetCoordinate(entry[8], entry[9], entry[10], entry[11]);
        w.SetCoordinate(entry[12], entry[13], entry[14], entry[15]);
    }
    else
    {
        x.SetCoordinate(entry[0], entry[4], entry[8], entry[12]);
        y.SetCoordinate(entry[1], entry[5], entry[9], entry[13]);
        z.SetCoordinate(entry[2], entry[6], entry[10], entry[14]);
        w.SetCoordinate(entry[3], entry[7], entry[11], entry[15]);
    }

#include SYSTEM_WARNING_POP

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Matrix4<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix4<Real>::MakeZero() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x.ZeroOut();
    y.ZeroOut();
    z.ZeroOut();
    w.ZeroOut();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix4<Real>::MakeIdentity() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x = Vector4::GetUnitX();
    y = Vector4::GetUnitY();
    z = Vector4::GetUnitZ();
    w = Vector4::GetUnitW();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
const Mathematics::Vector4<Real>& Mathematics::Matrix4<Real>::operator[](int row) const
{
    MATHEMATICS_CLASS_IS_VALID_9;

    switch (System::UnderlyingCastEnum<VectorIndex>(row))
    {
        case VectorIndex::X:
            return x;
        case VectorIndex::Y:
            return y;
        case VectorIndex::Z:
            return z;
        case VectorIndex::W:
            return w;
        default:
            break;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("��������"s))
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector4<Real>& Mathematics::Matrix4<Real>::operator[](int row)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(Mathematics::Vector4<Real>, row);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
const Real& Mathematics::Matrix4<Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_0(xIndex <= row && row < vectorSize, "row��������");
    MATHEMATICS_ASSERTION_0(Vector4::xIndex <= column && column < Vector4::pointSize, "column��������");

    return (*this)[row][column];
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real& Mathematics::Matrix4<Real>::operator()(int row, int column)
{
    MATHEMATICS_CLASS_IS_VALID_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, column));

#include SYSTEM_WARNING_POP
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix4<Real> Mathematics::Matrix4<Real>::operator-() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix4<Real>{ -x.GetX(),
                          -x.GetY(),
                          -x.GetZ(),
                          -x.GetW(),
                          -y.GetX(),
                          -y.GetY(),
                          -y.GetZ(),
                          -y.GetW(),
                          -z.GetX(),
                          -z.GetY(),
                          -z.GetZ(),
                          -z.GetW(),
                          -w.GetX(),
                          -w.GetY(),
                          -w.GetZ(),
                          -w.GetW() };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix4<Real>& Mathematics::Matrix4<Real>::operator+=(const Matrix4& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    w += rhs.w;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix4<Real>& Mathematics::Matrix4<Real>::operator-=(const Matrix4& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    w -= rhs.w;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix4<Real>& Mathematics::Matrix4<Real>::operator*=(Real scalar) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x *= scalar;
    y *= scalar;
    z *= scalar;
    w *= scalar;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix4<Real>& Mathematics::Matrix4<Real>::operator/=(Real scalar) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x /= scalar;
    y /= scalar;
    z /= scalar;
    w /= scalar;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Matrix4<Real>::QuadraticForm(const Vector4& lhs, const Vector4& rhs) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return Vector4Tools::DotProduct(lhs, (*this) * rhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix4<Real> Mathematics::Matrix4<Real>::Transpose() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix4{ GetValue<0, 0>(),
                    GetValue<1, 0>(),
                    GetValue<2, 0>(),
                    GetValue<3, 0>(),
                    GetValue<0, 1>(),
                    GetValue<1, 1>(),
                    GetValue<2, 1>(),
                    GetValue<3, 1>(),
                    GetValue<0, 2>(),
                    GetValue<1, 2>(),
                    GetValue<2, 2>(),
                    GetValue<3, 2>(),
                    GetValue<0, 3>(),
                    GetValue<1, 3>(),
                    GetValue<2, 3>(),
                    GetValue<3, 3>() };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix4<Real>& Mathematics::Matrix4<Real>::operator*=(const Matrix4& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    *this = *this * rhs;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix4<Real> Mathematics::Matrix4<Real>::GaussianEliminationInverse(Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (GaussianElimination<Real> gaussianElimination{ vectorSize, GetContainer(), true, epsilon };
        gaussianElimination.IsInverse())
    {
        return Matrix4{ gaussianElimination.GetInverse(), MatrixMajorFlags::Row };
    }
    else
    {
        MATHEMATICS_ASSERTION_0(false, "�þ��󲻴��������");

        return GetZero();
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Matrix4<Real>::GaussianEliminationDeterminant(Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    GaussianElimination<Real> gaussianElimination{ vectorSize, GetContainer(), false, epsilon };

    return gaussianElimination.GetDeterminant();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix4<Real> Mathematics::Matrix4<Real>::Inverse(Real epsilon) const
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
requires std::is_arithmetic_v<Real>
Mathematics::Matrix4<Real> Mathematics::Matrix4<Real>::Adjoint() const noexcept
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

    return Matrix4{ GetValue<1, 1>() * b5 - GetValue<1, 2>() * b4 + GetValue<1, 3>() * b3,
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
requires std::is_arithmetic_v<Real>
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

    const auto det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;

    return det;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix4<Real>::MakeObliqueProjection(const Vector3& normal, const Vector3& origin, const Vector3& direction) noexcept(gAssert < 1 || gMathematicsAssert < 1)
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

    const auto dotNormalDirection = Vector3Tools::DotProduct(normal, direction);
    const auto dotNormalOrigin = Vector3Tools::DotProduct(normal, origin);

    x.SetCoordinate(direction.GetX() * normal.GetX() - dotNormalDirection,
                    direction.GetX() * normal.GetY(),
                    direction.GetX() * normal.GetZ(),
                    -dotNormalOrigin * direction.GetX());
    y.SetCoordinate(direction.GetY() * normal.GetX(),
                    direction.GetY() * normal.GetY() - dotNormalDirection,
                    direction.GetY() * normal.GetZ(),
                    -dotNormalOrigin * direction.GetY());
    z.SetCoordinate(direction.GetZ() * normal.GetX(),
                    direction.GetZ() * normal.GetY(),
                    direction.GetZ() * normal.GetZ() - dotNormalDirection,
                    -dotNormalOrigin * direction.GetZ());
    w.SetCoordinate(Math::GetValue(0), Math::GetValue(0), Math::GetValue(0), -dotNormalDirection);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix4<Real>::MakePerspectiveProjection(const Vector3& normal, const Vector3& origin, const Vector3& eye)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_1(normal.IsNormalize(), "normal�����ǵ�λ������");

    //     +-                                                             -+
    // M = | Dot(N,E - P) * I - E * N^T    -(Dot(N,E - P)*I - E * N^T) * E |
    //     |        -N^t                      Dot(N,E)                     |
    //     +-                                                             -+
    //
    // ����EΪ�۵㣬PΪƽ���ϵ�һ���㣬��N�ǵ�λ���ȵ�ƽ�淨�ߡ�

    const auto dotNormalDirection = Vector3Tools::DotProduct(normal, eye - origin);

    x.SetCoordinate(dotNormalDirection - eye.GetX() * normal.GetX(),
                    -eye.GetX() * normal.GetY(),
                    -eye.GetX() * normal.GetZ(),
                    -(GetValue<0, 0>() * eye.GetX() + GetValue<0, 1>() * eye.GetY() + GetValue<0, 2>() * eye.GetZ()));
    y.SetCoordinate(-eye.GetY() * normal.GetX(),
                    dotNormalDirection - eye.GetY() * normal.GetY(),
                    -eye.GetY() * normal.GetZ(),
                    -(GetValue<1, 0>() * eye.GetX() + GetValue<1, 1>() * eye.GetY() + GetValue<1, 2>() * eye.GetZ()));
    z.SetCoordinate(-eye.GetZ() * normal.GetX(),
                    -eye.GetZ() * normal.GetY(),
                    dotNormalDirection - eye.GetZ() * normal.GetZ(),
                    -(GetValue<2, 0>() * eye.GetX() + GetValue<2, 1>() * eye.GetY() + GetValue<2, 2>() * eye.GetZ()));
    w.SetCoordinate(-normal.GetX(), -normal.GetY(), -normal.GetZ(), Vector3Tools::DotProduct(eye, normal));
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix4<Real>::MakeReflection(const Vector3& normal, const Vector3& origin) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_1(normal.IsNormalize(), "normal�����ǵ�λ������");

    //     +-                         -+
    // M = | I-2*N*N^T    2*Dot(N,P)*N |
    //     |     0^T            1      |
    //     +-                         -+
    //
    // ����P��ƽ���ϵĵ㣬N��һ����λ���ȵ�ƽ�淨�ߡ�

    const auto twoDotNormalOrigin = Math::GetValue(2) * Vector3Tools::DotProduct(normal, origin);

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
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix4<Real>::MakeFrustumMatrix44(Real left, Real right, Real bottom, Real top, Real nearDistance, Real farDistance) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto width = right - left;
    const auto height = top - bottom;
    const auto depth = farDistance - nearDistance;

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
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix4<Real>::MakePerspectiveMatrix44(Real fieldOfViewY, Real aspect, Real nearDistance, Real farDistance) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto angle = fieldOfViewY / Math::GetValue(2);
    // �Ƕ�ת���ɻ���
    angle *= Math::GetDegreeToRadian();

    const auto cot = Math::Cos(angle) / Math::Sin(angle);

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
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix4<Real>::MakeOrthoMatrix44(Real left, Real right, Real bottom, Real top, Real nearDistance, Real farDistance) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto width = right - left;
    const auto height = top - bottom;
    const auto depth = farDistance - nearDistance;

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
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix4<Real>::MakeOrthoNormalMatrix44(const Vector3& xDirection, const Vector3& yDirection, const Vector3& zDirection) noexcept(gAssert < 1 || gMathematicsAssert < 1)
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

template <typename Real>
requires std::is_arithmetic_v<Real>
const typename Mathematics::Matrix4<Real>::ArrayType Mathematics::Matrix4<Real>::GetCoordinate() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ArrayType{ x.GetX(),
                      x.GetY(),
                      x.GetZ(),
                      x.GetW(),
                      y.GetX(),
                      y.GetY(),
                      y.GetZ(),
                      y.GetW(),
                      z.GetX(),
                      z.GetY(),
                      z.GetZ(),
                      z.GetW(),
                      w.GetX(),
                      w.GetY(),
                      w.GetZ(),
                      w.GetW() };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Matrix4<Real>::ContainerType Mathematics::Matrix4<Real>::GetContainer() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ContainerType{ x.GetX(),
                          x.GetY(),
                          x.GetZ(),
                          x.GetW(),
                          y.GetX(),
                          y.GetY(),
                          y.GetZ(),
                          y.GetW(),
                          z.GetX(),
                          z.GetY(),
                          z.GetZ(),
                          z.GetW(),
                          w.GetX(),
                          w.GetY(),
                          w.GetZ(),
                          w.GetW() };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Matrix4<Real>::Set(const ArrayType& coordinate)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto index = 0;
    for (auto value : coordinate)
    {
        (*this)(index / vectorSize, index % Vector4::pointSize) = value;

        ++index;
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix3<Real> Mathematics::Matrix4<Real>::Project() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Matrix3 result{ MatrixInitType::Zero };

    for (auto r = 0; r < Matrix3::vectorSize; ++r)
    {
        for (auto c = 0; c < Matrix3::vectorSize; ++c)
        {
            result(r, c) = (*this)(r, c);
        }
    }

    return result;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Matrix4<Real>::Trace() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetValue<0, 0>() + GetValue<1, 1>() + GetValue<2, 2>() + GetValue<3, 3>();
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX4_ACHIEVE_H