///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 15:19)

#ifndef MATHEMATICS_OBJECTS_2D_ELLIPSE2_DETAIL_H
#define MATHEMATICS_OBJECTS_2D_ELLIPSE2_DETAIL_H

#include "Ellipse2.h"
#include "Ellipse2CoefficientsDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::Ellipse2<Real>::Ellipse2(const Vector2& center,
                                      const Vector2& axis0,
                                      const Vector2& axis1,
                                      const Real extent0,
                                      const Real extent1,
                                      const Real epsilon) noexcept
    : center{ center }, axis{ axis0, axis1 }, extent{ extent0, extent1 }, epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Ellipse2<Real>::Ellipse2(const Ellipse2Coefficients& coefficients, const Real epsilon)
    : center{}, axis{ Vector2::GetUnitX(), Vector2::GetUnitY() }, extent{}, epsilon{ epsilon }
{
    FromCoefficients(coefficients, epsilon);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Ellipse2<Real>::IsValid() const noexcept
{
    try
    {
    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26446)

        if (axis[0].IsNormalize(epsilon) && axis[1].IsNormalize(epsilon) && -epsilon <= extent[0] && -epsilon <= extent[1])
            return true;
        else
            return false;

    #include STSTEM_WARNING_POP
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Vector2<Real> Mathematics::Ellipse2<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return center;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::Ellipse2<Real>::GetAxis0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return axis[0];

#include STSTEM_WARNING_POP
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::Ellipse2<Real>::GetAxis1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return axis[1];

#include STSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::Ellipse2<Real>::GetExtent0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return extent[0];

#include STSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::Ellipse2<Real>::GetExtent1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return extent[1];

#include STSTEM_WARNING_POP
}

template <typename Real>
Mathematics::Matrix2<Real> Mathematics::Ellipse2<Real>::GetMatrix() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto ratio0 = GetAxis0() / GetExtent0();
    const auto ratio1 = GetAxis1() / GetExtent1();

    return Matrix2{ ratio0, ratio0 } + Matrix2{ ratio1, ratio1 };
}

template <typename Real>
Mathematics::Matrix2<Real> Mathematics::Ellipse2<Real>::GetMatrixInverse() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto ratio0 = GetAxis0() * GetExtent0();
    const auto ratio1 = GetAxis1() * GetExtent1();

    return Matrix2{ ratio0, ratio0 } + Matrix2{ ratio1, ratio1 };
}

template <typename Real>
Mathematics::Ellipse2Coefficients<Real> Mathematics::Ellipse2<Real>::ToCoefficients() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const Matrix2 matrix{ GetMatrix() };
    const Vector2 vector{ Math::GetValue(-2) * (matrix * center) };
    const auto constants = matrix.QuadraticForm(center, center) - Math::GetValue(1);

    return Ellipse2Coefficients{ matrix, vector, constants };
}

template <typename Real>
void Mathematics::Ellipse2<Real>::FromCoefficients(const Ellipse2Coefficients& coefficients, const Real newEpsilon)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    epsilon = newEpsilon;

    const auto matrix = coefficients.GetMatrix();
    const auto vector = coefficients.GetVector();
    const auto constants = coefficients.GetConstants();

    // 计算的中心 K = -A^{-1}*B/2.
    const auto invMatrix = matrix.Inverse(epsilon);

    center = Math::GetRational(-1, 2) * (invMatrix * vector);

    // 计算 B^T*A^{-1}*B/4 - C = K^T*A*K - C = -K^T*B/2 - C.
    const auto rightSide = Math::GetRational(-1, 2) * Vector2Tools::DotProduct(center, vector) - constants;
    if (Math::FAbs(rightSide) < epsilon)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("除零错误！"s));
    }

    // 计算 M = A/(K^T*A*K - C).
    const auto eigenSystemMatrix = matrix / rightSide;

    // 分解因子 M = Real*D*Real^T.
    const auto eigenDecomposition = eigenSystemMatrix.EigenDecomposition(epsilon);

    const auto diagonal = eigenDecomposition.GetDiagonal();
    const auto rotation = eigenDecomposition.GetRotation();

    for (auto i = 0; i < axisSize; ++i)
    {
        const auto eigenValue = diagonal(i, i);

        if (eigenValue <= epsilon)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("除零错误！"s));
        }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

        extent[i] = Math::InvSqrt(eigenValue);

        axis[i] = Vector2(rotation(0, i), rotation(1, i));

#include STSTEM_WARNING_POP
    }
}

template <typename Real>
Real Mathematics::Ellipse2<Real>::Evaluate(const Vector2& point) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto diff = point - center;
    const auto ratio0 = Vector2Tools::DotProduct(GetAxis0(), diff) / GetExtent0();
    const auto ratio1 = Vector2Tools::DotProduct(GetAxis1(), diff) / GetExtent1();
    const auto value = ratio0 * ratio0 + ratio1 * ratio1 - Math::GetValue(1);

    return value;
}

template <typename Real>
bool Mathematics::Ellipse2<Real>::Contains(const Vector2& point) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Evaluate(point) <= epsilon;
}

template <typename Real>
Mathematics::Ellipse2<Real> Mathematics::Ellipse2<Real>::GetMove(Real t, const Vector2& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedCenter = GetCenter() + t * velocity;
    const Ellipse2 movedEllipse{ movedCenter, GetAxis0(), GetAxis1(), GetExtent0(), GetExtent1(), epsilon };

    return movedEllipse;
}

template <typename Real>
bool Mathematics::Approximate(const Ellipse2<Real>& lhs, const Ellipse2<Real>& rhs, Real epsilon)
{
    return Vector2Tools<Real>::Approximate(lhs.GetCenter(), rhs.GetCenter(), epsilon) &&
           Vector2Tools<Real>::Approximate(lhs.GetAxis0(), rhs.GetAxis0(), epsilon) &&
           Vector2Tools<Real>::Approximate(lhs.GetAxis1(), rhs.GetAxis1(), epsilon) &&
           Math<Real>::Approximate(lhs.GetExtent0(), rhs.GetExtent0(), epsilon) &&
           Math<Real>::Approximate(lhs.GetExtent1(), rhs.GetExtent1(), epsilon);
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const Ellipse2<Real>& ellipse)
{
    outFile << "center="
            << ellipse.GetCenter()
            << ",axis0="
            << ellipse.GetAxis0()
            << ",axis1="
            << ellipse.GetAxis1()
            << "extent0="
            << ellipse.GetExtent0()
            << "extent1="
            << ellipse.GetExtent1();

    return outFile;
}

#endif  // MATHEMATICS_OBJECTS_2D_ELLIPSE2_DETAIL_H
