///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/21 13:06)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ELLIPSE2_ELLIPSE2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ELLIPSE2_ELLIPSE2_ACHIEVE_H

#include "StaticFindIntersectorEllipse2Ellipse2.h"
#include "StaticTestIntersectorBox2Box2Detail.h"
#include "Detail/StaticFindIntersectorEllipse2Ellipse2ImplDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/PolynomialRoots.h"

template <typename Real>
Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::StaticFindIntersectorEllipse2Ellipse2(const Ellipse2& ellipse0, const Ellipse2& ellipse1, const Real epsilon)
    : ParentType{ epsilon }, m_Impl{ std::make_shared<ImplType>(ellipse0, ellipse1) }
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Ellipse2<Real> Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::GetEllipse0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetEllipse0();
}

template <typename Real>
const Mathematics::Ellipse2<Real> Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::GetEllipse1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetEllipse1();
}

template <typename Real>
int Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetQuantity();
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetPoint(index);
}

template <typename Real>
const Mathematics::Ellipse2<Real> Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::GetIntersectionEllipse() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetIntersectionEllipse();
}

template <typename Real>
bool Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::IsTransverseIntersection(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->IsTransverseIntersection(index);
}

template <typename Real>
void Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::Find()
{
    auto ellipse0 = GetEllipse0();
    auto ellipse1 = GetEllipse1();

    // 测试椭圆包围盒的相交。 这是一种快速尝试。
    Box2<Real> box0{ ellipse0.GetCenter(), ellipse0.GetAxis0(), ellipse0.GetAxis1(), ellipse0.GetExtent0(), ellipse0.GetExtent1() };
    Box2<Real> box1{ ellipse1.GetCenter(), ellipse1.GetAxis0(), ellipse1.GetAxis1(), ellipse1.GetExtent0(), ellipse1.GetExtent1() };

    StaticTestIntersectorBox2Box2<Real> staticTestIntersectorBox2Box2{ box0, box1 };
    if (!staticTestIntersectorBox2Box2.IsIntersection())
    {
        // 包围盒不重叠，椭圆也不重叠。
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    /// 计算四次多项式，其根导致椭圆相交的，然后计算其根。
    auto poly = GetQuartic(ellipse0, ellipse1);
    PolynomialRoots<Real> polynomialRoots{ Math::GetZeroTolerance() };
    if (!polynomialRoots.FindBisection(poly, m_Impl->GetDigitsAccuracy()) ||
        polynomialRoots.GetCount() == 0)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    /// 计算s = sin(angle)和c = cos(angle)的多项式的系数，然后将ellipse0和ellipse1相关联，仿射变换为一个圆。
    /// 多项式为d0 + d1 * c + d2 * s + d3 * c^2 + d4 * c * s + d5 * s^2 = 0其中c^2 + s^2 = 1。
    auto center0MinusCenter1 = ellipse0.GetCenter() - ellipse1.GetCenter();
    const auto matrix1 = ellipse1.GetMatrix();
    const auto matrix1Center0MinusCenter1 = matrix1 * center0MinusCenter1;
    const auto matrix1Axis0 = matrix1 * ellipse0.GetAxis0();
    const auto matrix1Axis1 = matrix1 * ellipse0.GetAxis1();

    const CoeffType coeff{ Vector2DTools::DotProduct(matrix1Center0MinusCenter1, center0MinusCenter1) - Math::GetValue(1),
                           (Math::GetValue(2)) * ellipse0.GetExtent0() * Vector2DTools::DotProduct(matrix1Axis0, center0MinusCenter1),
                           (Math::GetValue(2)) * ellipse0.GetExtent1() * Vector2DTools::DotProduct(matrix1Axis1, center0MinusCenter1),
                           ellipse0.GetExtent0() * ellipse0.GetExtent0() * Vector2DTools::DotProduct(matrix1Axis0, ellipse0.GetAxis0()),
                           (Math::GetValue(2)) * ellipse0.GetExtent0() * ellipse0.GetExtent1() * Vector2DTools::DotProduct(matrix1Axis0, ellipse0.GetAxis1()),
                           ellipse0.GetExtent1() * ellipse0.GetExtent1() * Vector2DTools::DotProduct(matrix1Axis1, ellipse0.GetAxis1()) };

    /// 求解二次方，保存这些值以供以后测试接近零和根部抛光的程度。
    auto ellipse0Coefficients = ellipse0.ToCoefficients();
    auto ellipse1Coefficients = ellipse1.ToCoefficients();
    auto qp0 = ellipse0Coefficients.GetCoefficients();
    auto qp1 = ellipse1Coefficients.GetCoefficients();

    constexpr auto measurementSize = 8;
    using MeasurementContainer = std::array<Measurement, measurementSize>;

    MeasurementContainer measure{};  // 储存 <x,y,sqrt(Q0^2 + S1^2)>

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

    auto indexX = 0;
    for (auto begin = polynomialRoots.GetBegin(); begin != polynomialRoots.GetEnd(); ++begin)
    {
        Vector2D point{ Math::GetValue(0), *begin };

        PolynomialRoots<Real> roots{ Math::GetZeroTolerance() };
        Polynomial<Real> polynomial{ 2 };
        polynomial[0] = qp0[0] + point[1] * (qp0[2] + point[1] * qp0[5]);
        polynomial[1] = qp0[1] + point[1] * qp0[4];
        polynomial[2] = qp0[3];
        if (!roots.FindBisection(polynomial, m_Impl->GetDigitsAccuracy()))
        {
            continue;
        }

        auto indexY = 0;
        for (auto arBegin = roots.GetBegin(); arBegin != roots.GetEnd(); ++arBegin)
        {
            point[0] = *arBegin;

            const auto index = indexX + 2 * indexY;
            measure[index] = RefinePoint(coeff, point);

            ++indexY;
        }

        ++indexX;
    }
    std::sort(measure.begin(), measure.end());

    auto quantity = 0;
    for (auto i = 0; i < measurementSize; ++i)
    {
        if (measure[i].m_Norm < Math::GetZeroTolerance())
        {
            auto find = 0;

            for (; find < quantity; ++find)
            {
                auto diff = measure[i].m_Angle0 - measure[find].m_Angle0;
                if (Math::FAbs(diff) < Math::GetZeroTolerance())
                {
                    break;
                }
            }
            if (find == quantity)
            {
                m_Impl->AddIntersection(measure[i].m_Point, measure[i].m_Transverse);

                if (++quantity == 4)
                {
                    break;
                }
            }
        }
    }

#include STSTEM_WARNING_POP

    if (quantity == 0)
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Point);
    }
}

template <typename Real>
Mathematics::Polynomial<Real> Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::GetQuartic(const Ellipse2& ellipse0, const Ellipse2& ellipse1)
{
    auto ellipse2Coefficients0 = ellipse0.ToCoefficients();
    auto ellipse2Coefficients1 = ellipse1.ToCoefficients();
    auto p0 = ellipse2Coefficients0.GetCoefficients();
    auto p1 = ellipse2Coefficients1.GetCoefficients();

    // 多项式是
    //   P0 = a0 + a1 * x + a2 * y + a3 * x^2 + a4 * x * y + a5 * y^2
    //      = (a0 + a2 * y + a5 * y^2) + (a1 + a4 * y) * x + (a3) * x^2
    //      = u0(y) + u1(y) * x + u2(y) * x^2
    //   P1 = b0 + b1 * x + b2 * y + b3 * x^2 + b4 * x * y + b5 * y^2
    //      = (b0 + b2 * y + b5 * y^2) + (b1 + b4 * y)*x + (b3) * x^2
    //      = v0(y) + v1(y) * x + v2(y) * x^2
    // 当求解方程P0(x,y) = 0和P1(x,y) = 0时，Bezout行列式消除变量x。
    // 我们有
    //   0 = P0 = u0 + u1 * x + u2 * x^2
    //   0 = P1 = v0 + v1 * x + v2 * x^2
    //   0 = v2 * P0 - u2 * P1 = (u0 * v2 - u2 * v0) + (u1 * v2 - u2 * v1) * x
    //   0 = v1 * P0 - u1 * P1 = (u0 * v1 - u1 * v0) + (u2 * v1 - u1 * v2) * x^2
    // 对x求解方程0 = v2 * P0 - u2 * P1并代入其他方程式，简化为
    //   Q(y) = (u0 * v1 - v1 * u0) * (u1 * v2 - u2 * v1) - (u0 * v2 - u2 * v0)^2 = 0
    //        = c0 + c1 * y + c2 * y^2 + c3 * y^3 + c4 * y^4
    // 为各种索引i和j定义dij = ai * bj - aj * bi。 例如，d01 = a0 * b1 - b1 * a0。 Q（y）的系数为
    //   c0 = d01 * d13 - d30^2
    //   c1 = d01 * d43 + (d04 + d21) * d13 - 2 * d30 * d32
    //   c2 = (d04 + d21) * d43 + (d24 + d51) * d13 - 2 * d30 * d35 - d32^2
    //   c3 = (d24 + d51) * d43 + d54 * d13 - 2 * d32 * d35
    //   c4 = d54 * d43 - d35^2

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    auto d01 = p0[0] * p1[1] - p0[1] * p1[0];
    auto d04 = p0[0] * p1[4] - p0[4] * p1[0];
    auto d13 = p0[1] * p1[3] - p0[3] * p1[1];
    auto d21 = p0[2] * p1[1] - p0[1] * p1[2];
    auto d24 = p0[2] * p1[4] - p0[4] * p1[2];
    auto d30 = p0[3] * p1[0] - p0[0] * p1[3];
    auto d32 = p0[3] * p1[2] - p0[2] * p1[3];
    auto d35 = p0[3] * p1[5] - p0[5] * p1[3];
    auto d43 = p0[4] * p1[3] - p0[3] * p1[4];
    auto d51 = p0[5] * p1[1] - p0[1] * p1[5];
    auto d54 = p0[5] * p1[4] - p0[4] * p1[5];
    auto d04p21 = d04 + d21;
    auto d24p51 = d24 + d51;

#include STSTEM_WARNING_POP

    Polynomial<Real> poly{ 4 };
    poly[0] = d01 * d13 - d30 * d30;
    poly[1] = d01 * d43 + d04p21 * d13 - (Math::GetValue(2)) * d30 * d32;
    poly[2] = d04p21 * d43 + d24p51 * d13 - (Math::GetValue(2)) * d30 * d35 - d32 * d32;
    poly[3] = d24p51 * d43 + d54 * d13 - (Math::GetValue(2)) * d32 * d35;
    poly[4] = d54 * d43 - d35 * d35;

    return poly;
}

template <typename Real>
typename Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::Measurement Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::RefinePoint(const CoeffType& coeff, const Vector2D& point)
{
    auto ellipse0 = GetEllipse0();
    auto ellipse1 = GetEllipse1();

    /// 传入多项式为
    ///  f(angle) = d0 + d1 * c + d2 * s + d3 * c^2 + d4 * c * s + d5 * s^2
    /// 其中s = sin(angle)， c = cos(angle)。 导数是
    ///  f'(angle) = -d1 * s + d2 * c + (d5 - d3) * 2 * c * s + d4 * (c^2 - s^2)

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    auto diff = point - ellipse0.GetCenter();
    auto cos = Vector2DTools::DotProduct(diff, ellipse0.GetAxis0()) / ellipse0.GetExtent0();
    auto sin = Vector2DTools::DotProduct(diff, ellipse0.GetAxis1()) / ellipse0.GetExtent1();
    auto aTan = Math::ATan2(sin, cos);
    auto f0 = coeff[0] + coeff[1] * cos + coeff[2] * sin + coeff[3] * cos * cos + coeff[4] * cos * sin + coeff[5] * sin * sin;
    auto df0 = -coeff[1] * sin + coeff[2] * cos + (Math::GetValue(2)) * (coeff[5] - coeff[3]) * cos * sin + coeff[4] * (cos * cos - sin * sin);

    auto a1 = Math::GetValue(0);

    /// f0值应与q1相匹配（在浮点舍入误差内）。 尝试使用二等分将f0强制为零。
    /// 这需要找到一个角度，使得相应的函数值的符号与f0相反。
    /// 如果搜索失败，则输入点要么是切线相交，要么根本不是相交。
    auto maxIterations = 32;
    auto i = 0;
    for (; i < maxIterations; ++i)
    {
        a1 = aTan - f0 / df0;
        cos = Math::Cos(a1);
        sin = Math::Sin(a1);
        auto f1 = coeff[0] + coeff[1] * cos + coeff[2] * sin + coeff[3] * cos * cos + coeff[4] * cos * sin + coeff[5] * sin * sin;

        if (f0 * f1 < Math::GetValue(0))
        {
            // 切换到二等分。
            break;
        }

        auto df1 = -coeff[1] * sin + coeff[2] * cos + (Math::GetValue(2)) * (coeff[5] - coeff[3]) * cos * sin + coeff[4] * (cos * cos - sin * sin);

        if (df1 * df0 < Math::GetValue(0))
        {
            // 尝试更陡的斜率在寻找一个符号相反值的希望值。
            df0 *= Math::GetValue(2);
            continue;
        }

        if (Math::FAbs(f1) < Math::FAbs(f0))
        {
            /// 我们找不到相反的值，但是新函数的值接近于零，因此请尝试使用新值。
            aTan = a1;
            f0 = f1;
            df0 = df1;
        }
    }

    auto angle = aTan;
    auto transverse = false;
    if (i < maxIterations)
    {
        // 应用二等分。 确定迭代次数以获取10位精度。
        auto value0 = Math::Log(Math::FAbs(a1 - aTan));
        auto value1 = (static_cast<Real>(m_Impl->GetDigitsAccuracy())) * Math::Log(Math::GetValue(10));
        auto arg = (value0 + value1) / Math::Log(Math::GetValue(2));
        maxIterations = static_cast<int>(arg + Math::GetRational(1, 2));
        for (i = 0; i < maxIterations; ++i)
        {
            angle = (Math::GetRational(1, 2)) * (aTan + a1);
            cos = Math::Cos(angle);
            sin = Math::Sin(angle);
            auto f1 = coeff[0] + coeff[1] * cos + coeff[2] * sin + coeff[3] * cos * cos + coeff[4] * cos * sin + coeff[5] * sin * sin;

            auto product = f0 * f1;
            if (product < Math::GetValue(0))
            {
                a1 = angle;
            }
            else if (Math::GetValue(0) < product)
            {
                aTan = angle;
                f0 = f1;
            }
            else
            {
                break;
            }
        }
        transverse = true;
    }
    else
    {
        transverse = false;
    }

#include STSTEM_WARNING_POP

    Measurement measure{};

    measure.m_Point = ellipse0.GetCenter() + ellipse0.GetExtent0() * cos * ellipse0.GetAxis0() + ellipse0.GetExtent1() * sin * ellipse0.GetAxis1();
    measure.m_Q0 = ellipse0.Evaluate(point);
    measure.m_Q1 = ellipse1.Evaluate(point);
    measure.m_Angle0 = angle;
    measure.m_Norm = Math::Sqrt(measure.m_Q0 * measure.m_Q0 + measure.m_Q1 * measure.m_Q1);
    measure.m_Transverse = transverse;

    return measure;
}

// IntrEllipse2Ellipse2::Measurement

template <typename Real>
Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::Measurement::Measurement() noexcept
    : m_Point{ Math::sm_MaxReal, Math::sm_MaxReal }, m_Q0{ Math::sm_MaxReal }, m_Q1{ Math::sm_MaxReal }, m_Norm{ Math::sm_MaxReal }, m_Angle0{ Math::sm_MaxReal }, m_Transverse{ false }
{
}

template <typename Real>
bool Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::Measurement::operator<(const Measurement& measure) const noexcept
{
    if (m_Transverse == measure.m_Transverse)
    {
        return m_Norm < measure.m_Norm;
    }
    else
    {
        return m_Transverse;
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ELLIPSE2_ELLIPSE2_ACHIEVE_H