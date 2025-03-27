///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/27 20:13)

#ifndef MATHEMATICS_OBJECTS_3D_ALGEBRA_TORUS3_DETAIL_H
#define MATHEMATICS_OBJECTS_3D_ALGEBRA_TORUS3_DETAIL_H

#include "Torus3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector/Vector3Detail.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::Algebra::Torus3<Real>::Torus3() noexcept
    : center{},
      direction0{ MathType::GetValue(1), MathType::GetValue(0), MathType::GetValue(0) },
      direction1{ MathType::GetValue(0), MathType::GetValue(1), MathType::GetValue(0) },
      normal{ MathType::GetValue(0), MathType::GetValue(0), MathType::GetValue(1) },
      radius0{ MathType::GetValue(2) },
      radius1{ MathType::GetValue(1) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::Algebra::Torus3<Real>::Torus3(Vector3 center, Vector3 direction0, Vector3 direction1, Vector3 normal, Real radius0, Real radius1) noexcept
    : center{ center },
      direction0{ direction0 },
      direction1{ direction1 },
      normal{ normal },
      radius0{ radius0 },
      radius1{ radius1 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::Torus3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::Torus3<Real>::EvaluateResult Mathematics::Algebra::Torus3<Real>::Evaluate(Real u, Real v, int maxOrder) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    EvaluateResult jet{};

    /// 计算位置。
    const auto csu = std::cos(u);
    const auto snu = std::sin(u);
    const auto csv = std::cos(v);
    const auto snv = std::sin(v);
    const auto r1Csv = radius1 * csv;
    const auto r1Snv = radius1 * snv;
    const auto r0Pr1Csv = radius0 + r1Csv;
    const auto combo0 = csu * direction0 + snu * direction1;
    const auto r0Pr1CsvCombo0 = r0Pr1Csv * combo0;
    const auto r1SnvNormal = r1Snv * normal;
    jet.emplace_back(center + r0Pr1CsvCombo0 + r1SnvNormal);

    if (maxOrder >= 1)
    {
        /// 计算一阶导数。
        const auto combo1 = -snu * direction0 + csu * direction1;
        jet.emplace_back(r0Pr1Csv * combo1);
        jet.emplace_back(-r1Snv * combo0 + r1Csv * normal);

        if (maxOrder == 2)
        {
            /// 计算二阶导数。
            jet.emplace_back(-r0Pr1CsvCombo0);
            jet.emplace_back(-r1Snv * combo1);
            jet.emplace_back(-r1Csv * combo0 - r1SnvNormal);
        }
    }

    return jet;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Torus3<Real>::GetParameters(const Vector3& x, Real& u, Real& v) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto delta = x - center;

    // (r0 + r1*cos(v))*cos(u)
    const auto dot0 = Dot(direction0, delta);

    // (r0 + r1*cos(v))*sin(u)
    const auto dot1 = Dot(direction1, delta);

    // r1*sin(v)
    const auto dot2 = Dot(normal, delta);

    // r1*cos(v)
    const auto r1Csv = MathType::Sqrt(dot0 * dot0 + dot1 * dot1) - radius0;

    u = MathType::ATan2(dot1, dot0);
    v = MathType::ATan2(dot2, r1Csv);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::Torus3<Real>::Vector3 Mathematics::Algebra::Torus3<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return center;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Torus3<Real>::SetCenter(const Vector3& aCenter) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    center = aCenter;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::Torus3<Real>::Vector3 Mathematics::Algebra::Torus3<Real>::GetDirection0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return direction0;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Torus3<Real>::SetDirection0(const Vector3& aDirection0) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    direction0 = aDirection0;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::Torus3<Real>::Vector3 Mathematics::Algebra::Torus3<Real>::GetDirection1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return direction1;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Torus3<Real>::SetDirection1(const Vector3& aDirection1) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    direction1 = aDirection1;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::Torus3<Real>::Vector3 Mathematics::Algebra::Torus3<Real>::GetNormal() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return normal;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Torus3<Real>::SetNormal(const Vector3& aNormal) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    normal = aNormal;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::Algebra::Torus3<Real>::GetRadius0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return radius0;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Torus3<Real>::SetRadius0(Real aRadius0) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    radius0 = aRadius0;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::Algebra::Torus3<Real>::GetRadius1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return radius1;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Torus3<Real>::SetRadius1(Real aRadius1) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    radius1 = aRadius1;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::operator==(const Torus3<Real>& lhs, const Torus3<Real>& rhs)
{
    return lhs.GetCenter() == rhs.GetCenter() &&
           lhs.GetDirection0() == rhs.GetDirection0() &&
           lhs.GetDirection1() == rhs.GetDirection1() &&
           lhs.GetNormal() == rhs.GetNormal() &&
           lhs.GetRadius0() == rhs.GetRadius0() &&
           lhs.GetRadius1() == rhs.GetRadius1();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::operator!=(const Torus3<Real>& lhs, const Torus3<Real>& rhs)
{
    return !(lhs == rhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::operator<(const Torus3<Real>& lhs, const Torus3<Real>& rhs)
{
    if (lhs.GetCenter() < rhs.GetCenter())
    {
        return true;
    }

    if (rhs.GetCenter() < lhs.GetCenter())
    {
        return false;
    }

    if (lhs.GetDirection0() < rhs.GetDirection0())
    {
        return true;
    }

    if (rhs.GetDirection0() < lhs.GetDirection0())
    {
        return false;
    }

    if (lhs.GetDirection1() < rhs.GetDirection1())
    {
        return true;
    }

    if (rhs.GetDirection1() < lhs.GetDirection1())
    {
        return false;
    }

    if (lhs.GetNormal() < rhs.GetNormal())
    {
        return true;
    }

    if (rhs.GetNormal() < lhs.GetNormal())
    {
        return false;
    }

    if (lhs.GetRadius0() < rhs.GetRadius0())
    {
        return true;
    }

    if (rhs.GetRadius0() < lhs.GetRadius0())
    {
        return false;
    }

    return lhs.GetRadius1() < rhs.GetRadius1();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::operator<=(const Torus3<Real>& lhs, const Torus3<Real>& rhs)
{
    return !(rhs < lhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::operator>(const Torus3<Real>& lhs, const Torus3<Real>& rhs)
{
    return rhs < lhs;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::operator>=(const Torus3<Real>& lhs, const Torus3<Real>& rhs)
{
    return !(lhs < rhs);
}

#endif  // MATHEMATICS_OBJECTS_3D_ALGEBRA_TORUS3_DETAIL_H
