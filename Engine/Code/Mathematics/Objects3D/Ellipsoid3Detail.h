/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 10:38)

#ifndef MATHEMATICS_OBJECTS_3D_ELLIPSOID3_DETAIL_H
#define MATHEMATICS_OBJECTS_3D_ELLIPSOID3_DETAIL_H

#include "Ellipsoid3.h"
#include "Ellipsoid3CoefficientsDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::Ellipsoid3<Real>::Ellipsoid3(const Vector3& center,
                                          const Vector3& axis0,
                                          const Vector3& axis1,
                                          const Vector3& axis2,
                                          const Real extent0,
                                          const Real extent1,
                                          const Real extent2,
                                          const Real epsilon) noexcept
    : center{ center }, axis{ axis0, axis1, axis2 }, extent{ extent0, extent1, extent2 }, epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Ellipsoid3<Real>::Ellipsoid3(const Ellipsoid3Coefficients& coefficients, const Real epsilon)
    : center{}, axis{ Vector3::GetUnitX(), Vector3::GetUnitY(), Vector3::GetUnitZ() }, extent{}, epsilon{ epsilon }
{
    FromCoefficients(coefficients, epsilon);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Ellipsoid3<Real>::IsValid() const noexcept
{
    try
    {
    #include SYSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26446)

        if (axis[0].IsNormalize(epsilon) &&
            axis[1].IsNormalize(epsilon) &&
            axis[2].IsNormalize(epsilon) &&
            -epsilon <= extent[0] &&
            -epsilon <= extent[1] &&
            -epsilon <= extent[2] &&
            MathType::GetValue(0) <= epsilon)

    #include SYSTEM_WARNING_POP
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Ellipsoid3<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return center;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Ellipsoid3<Real>::GetAxis0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return axis[0];

#include SYSTEM_WARNING_POP
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Ellipsoid3<Real>::GetAxis1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return axis[1];

#include SYSTEM_WARNING_POP
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Ellipsoid3<Real>::GetAxis2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return axis[2];

#include SYSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::Ellipsoid3<Real>::GetExtent0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return extent[0];

#include SYSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::Ellipsoid3<Real>::GetExtent1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return extent[1];

#include SYSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::Ellipsoid3<Real>::GetExtent2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return extent[2];

#include SYSTEM_WARNING_POP
}

template <typename Real>
Mathematics::Matrix3<Real> Mathematics::Ellipsoid3<Real>::GetMatrix() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto ratio0 = GetAxis0() / GetExtent0();
    const auto ratio1 = GetAxis1() / GetExtent1();
    const auto ratio2 = GetAxis2() / GetExtent2();

    return Matrix3{ ratio0, ratio0 } + Matrix3{ ratio1, ratio1 } + Matrix3{ ratio2, ratio2 };
}

template <typename Real>
Mathematics::Matrix3<Real> Mathematics::Ellipsoid3<Real>::GetMatrixInverse() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto ratio0 = GetAxis0() * GetExtent0();
    const auto ratio1 = GetAxis1() * GetExtent1();
    const auto ratio2 = GetAxis2() * GetExtent2();

    return Matrix3{ ratio0, ratio0 } + Matrix3{ ratio1, ratio1 } + Matrix3{ ratio2, ratio2 };
}

template <typename Real>
typename Mathematics::Ellipsoid3<Real>::Ellipsoid3Coefficients Mathematics::Ellipsoid3<Real>::ToCoefficients() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const Matrix3 matrix{ GetMatrix() };
    const Vector3 vector{ MathType::GetValue(-2) * (matrix * center) };
    const auto constants = matrix.QuadraticForm(center, center) - MathType::GetValue(1);

    return Ellipsoid3Coefficients{ matrix, vector, constants };
}

template <typename Real>
void Mathematics::Ellipsoid3<Real>::FromCoefficients(const Ellipsoid3Coefficients& coefficients, const Real newEpsilon)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    epsilon = newEpsilon;

    const auto matrix = coefficients.GetMatrix();
    const auto vector = coefficients.GetVector();
    const auto constants = coefficients.GetConstants();

    // 计算的中心 K = -A^{-1}*B/2.
    const auto invMatrix = matrix.Inverse(epsilon);

    center = MathType::GetRational(-1, 2) * (invMatrix * vector);

    // 计算 B^T*A^{-1}*B/4 - C = K^T*A*K - C = -K^T*B/2 - C。
    auto rightSide = MathType::GetRational(-1, 2) * Vector3Tools::DotProduct(center, vector) - constants;
    if (MathType::FAbs(rightSide) < epsilon)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("除零错误！"s));
    }

    // 计算 M = A/(K^T*A*K - C)
    const auto eigenSystemMatrix = matrix / rightSide;

    // 分解因子 M = Real*D*Real^T.
    const auto eigenDecomposition = eigenSystemMatrix.EigenDecomposition(epsilon);

    const auto diagonal = eigenDecomposition.GetDiagonal();
    const auto rotation = eigenDecomposition.GetRotation();

    for (auto i = 0; i < Vector3::pointSize; ++i)
    {
        auto eigenValue = diagonal(i, i);

        if (eigenValue <= epsilon)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("除零错误！"s));
        }

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

        extent[i] = MathType::InvSqrt(eigenValue);

        axis[i] = Vector3{ rotation(0, i), rotation(1, i), rotation(2, i) };

#include SYSTEM_WARNING_POP
    }
}

template <typename Real>
Real Mathematics::Ellipsoid3<Real>::Evaluate(const Vector3& point) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto diff = point - center;
    const auto ratio0 = Vector3Tools::DotProduct(GetAxis0(), diff) / GetExtent0();
    const auto ratio1 = Vector3Tools::DotProduct(GetAxis1(), diff) / GetExtent1();
    const auto ratio2 = Vector3Tools::DotProduct(GetAxis2(), diff) / GetExtent2();
    const auto value = ratio0 * ratio0 + ratio1 * ratio1 + ratio2 * ratio2 - MathType::GetValue(1);

    return value;
}

template <typename Real>
bool Mathematics::Ellipsoid3<Real>::Contains(const Vector3& point) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Evaluate(point) <= epsilon;
}

template <typename Real>
Mathematics::Ellipsoid3<Real> Mathematics::Ellipsoid3<Real>::GetMove(Real t, const Vector3& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Ellipsoid3{ GetCenter() + t * velocity,
                       GetAxis0(),
                       GetAxis1(),
                       GetAxis2(),
                       GetExtent0(),
                       GetExtent1(),
                       GetExtent2(),
                       epsilon };
}

template <typename Real>
bool Mathematics::Approximate(const Ellipsoid3<Real>& lhs, const Ellipsoid3<Real>& rhs, Real epsilon)
{
    return Vector2Tools<Real>::Approximate(lhs.GetCenter(), rhs.GetCenter(), epsilon) &&
           Vector2Tools<Real>::Approximate(lhs.GetAxis0(), rhs.GetAxis0(), epsilon) &&
           Vector2Tools<Real>::Approximate(lhs.GetAxis1(), rhs.GetAxis1(), epsilon) &&
           Vector2Tools<Real>::Approximate(lhs.GetAxis2(), rhs.GetAxis2(), epsilon) &&
           Math<Real>::Approximate(lhs.GetExtent0(), rhs.GetExtent0(), epsilon) &&
           Math<Real>::Approximate(lhs.GetExtent1(), rhs.GetExtent1(), epsilon) &&
           Math<Real>::Approximate(lhs.GetExtent2(), rhs.GetExtent2(), epsilon);
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const Ellipsoid3<Real>& ellipsoid)
{
    outFile << "center="
            << ellipsoid.GetCenter()
            << ",axis0="
            << ellipsoid.GetAxis0()
            << ",axis1="
            << ellipsoid.GetAxis1()
            << ",axis2="
            << ellipsoid.GetAxis2()
            << ",extent0="
            << ellipsoid.GetExtent0()
            << ",extent1="
            << ellipsoid.GetExtent1()
            << ",extent2="
            << ellipsoid.GetExtent2();

    return outFile;
}

#endif  // MATHEMATICS_OBJECTS_3D_ELLIPSOID3_DETAIL_H
