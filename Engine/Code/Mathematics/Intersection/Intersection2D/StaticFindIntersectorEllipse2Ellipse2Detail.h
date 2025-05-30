///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 17:28)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ELLIPSE2_ELLIPSE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ELLIPSE2_ELLIPSE2_DETAIL_H

#include "StaticFindIntersectorEllipse2Ellipse2.h"
#include "StaticTestIntersectorBox2Box2Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/PolynomialRoots.h"

template <typename Real>
Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::StaticFindIntersectorEllipse2Ellipse2(const Ellipse2Type& ellipse0, const Ellipse2Type& ellipse1, const Real epsilon)
    : ParentType{ epsilon }, ellipse0{ ellipse0 }, ellipse1{ ellipse1 }, point{}, transverse{}, digitsAccuracy{ 10 }
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Ellipse2<Real> Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::GetEllipse0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ellipse0;
}

template <typename Real>
Mathematics::Ellipse2<Real> Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::GetEllipse1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ellipse1;
}

template <typename Real>
int Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(point.size());
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point.at(index);
}

template <typename Real>
Mathematics::Ellipse2<Real> Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::GetIntersectionEllipse() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ellipse0;
}

template <typename Real>
bool Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::IsTransverseIntersection(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return transverse.at(index);
}

template <typename Real>
void Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::Find()
{
    // 测试椭圆包围盒的相交。 这是一种快速尝试。
    const Box2<Real> box0{ ellipse0.GetCenter(), ellipse0.GetAxis0(), ellipse0.GetAxis1(), ellipse0.GetExtent0(), ellipse0.GetExtent1() };
    const Box2<Real> box1{ ellipse1.GetCenter(), ellipse1.GetAxis0(), ellipse1.GetAxis1(), ellipse1.GetExtent0(), ellipse1.GetExtent1() };

    if (StaticTestIntersectorBox2Box2<Real> staticTestIntersectorBox2Box2{ box0, box1 };
        !staticTestIntersectorBox2Box2.IsIntersection())
    {
        // 包围盒不重叠，椭圆也不重叠。
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    /// 计算四次多项式，其根导致椭圆相交的，然后计算其根。
    auto poly = GetQuartic(ellipse0, ellipse1);
    PolynomialRoots<Real> polynomialRoots{ MathType::GetZeroTolerance() };
    if (!polynomialRoots.FindBisection(poly, digitsAccuracy) || polynomialRoots.GetCount() == 0)
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

    const CoeffType coeff{ Vector2ToolsType::DotProduct(matrix1Center0MinusCenter1, center0MinusCenter1) - MathType::GetValue(1),
                           (MathType::GetValue(2))*ellipse0.GetExtent0() * Vector2ToolsType::DotProduct(matrix1Axis0, center0MinusCenter1),
                           (MathType::GetValue(2))*ellipse0.GetExtent1() * Vector2ToolsType::DotProduct(matrix1Axis1, center0MinusCenter1),
                           ellipse0.GetExtent0() * ellipse0.GetExtent0() * Vector2ToolsType::DotProduct(matrix1Axis0, ellipse0.GetAxis0()),
                           (MathType::GetValue(2))*ellipse0.GetExtent0() * ellipse0.GetExtent1() * Vector2ToolsType::DotProduct(matrix1Axis0, ellipse0.GetAxis1()),
                           ellipse0.GetExtent1() * ellipse0.GetExtent1() * Vector2ToolsType::DotProduct(matrix1Axis1, ellipse0.GetAxis1()) };

    /// 求解二次方，保存这些值以供以后测试接近零和根部抛光的程度。
    auto ellipse0Coefficients = ellipse0.ToCoefficients();
    auto ellipse1Coefficients = ellipse1.ToCoefficients();
    auto qp0 = ellipse0Coefficients.GetCoefficients();
    auto qp1 = ellipse1Coefficients.GetCoefficients();

    constexpr auto measurementSize = 8;
    using MeasurementContainer = std::array<Measurement, measurementSize>;

    MeasurementContainer measure{};  // 储存 <x,y,sqrt(Q0^2 + S1^2)>

    auto indexX = 0;
    for (auto begin = polynomialRoots.GetBegin(); begin != polynomialRoots.GetEnd(); ++begin)
    {
        Vector2 vector2{ MathType::GetValue(0), *begin };

        PolynomialRoots<Real> roots{ MathType::GetZeroTolerance() };
        Polynomial<Real> polynomial{ 2 };
        polynomial[0] = qp0.at(0) + vector2[1] * (qp0.at(2) + vector2[1] * qp0.at(5));
        polynomial[1] = qp0.at(1) + vector2[1] * qp0.at(4);
        polynomial[2] = qp0.at(3);
        if (!roots.FindBisection(polynomial, digitsAccuracy))
        {
            continue;
        }

        auto indexY = 0;
        for (auto arBegin = roots.GetBegin(); arBegin != roots.GetEnd(); ++arBegin)
        {
            vector2[0] = *arBegin;

            const auto index = indexX + 2 * indexY;
            measure.at(index) = RefinePoint(coeff, vector2);

            ++indexY;
        }

        ++indexX;
    }
    std::sort(measure.begin(), measure.end());

    auto quantity = 0;
    for (auto i = 0; i < measurementSize; ++i)
    {
        if (measure.at(i).norm < MathType::GetZeroTolerance())
        {
            auto find = 0;

            for (; find < quantity; ++find)
            {
                if (auto diff = measure.at(i).angle0 - measure.at(find).angle0;
                    MathType::FAbs(diff) < MathType::GetZeroTolerance())
                {
                    break;
                }
            }

            if (find == quantity)
            {
                transverse.at(point.size()) = measure.at(i).transverse;
                point.emplace_back(measure.at(i).point);

                if (++quantity == 4)
                {
                    break;
                }
            }
        }
    }

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
Mathematics::Polynomial<Real> Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::GetQuartic(const Ellipse2Type& ellipse0, const Ellipse2Type& ellipse1)
{
    const auto ellipse2Coefficients0 = ellipse0.ToCoefficients();
    const auto ellipse2Coefficients1 = ellipse1.ToCoefficients();
    const auto p0 = ellipse2Coefficients0.GetCoefficients();
    const auto p1 = ellipse2Coefficients1.GetCoefficients();

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

    const auto d01 = p0.at(0) * p1.at(1) - p0.at(1) * p1.at(0);
    const auto d04 = p0.at(0) * p1.at(4) - p0.at(4) * p1.at(0);
    const auto d13 = p0.at(1) * p1.at(3) - p0.at(3) * p1.at(1);
    const auto d21 = p0.at(2) * p1.at(1) - p0.at(1) * p1.at(2);
    const auto d24 = p0.at(2) * p1.at(4) - p0.at(4) * p1.at(2);
    const auto d30 = p0.at(3) * p1.at(0) - p0.at(0) * p1.at(3);
    const auto d32 = p0.at(3) * p1.at(2) - p0.at(2) * p1.at(3);
    const auto d35 = p0.at(3) * p1.at(5) - p0.at(5) * p1.at(3);
    const auto d43 = p0.at(4) * p1.at(3) - p0.at(3) * p1.at(4);
    const auto d51 = p0.at(5) * p1.at(1) - p0.at(1) * p1.at(5);
    const auto d54 = p0.at(5) * p1.at(4) - p0.at(4) * p1.at(5);
    const auto d04p21 = d04 + d21;
    const auto d24p51 = d24 + d51;

    Polynomial<Real> poly{ 4 };
    poly[0] = d01 * d13 - d30 * d30;
    poly[1] = d01 * d43 + d04p21 * d13 - (MathType::GetValue(2))*d30 * d32;
    poly[2] = d04p21 * d43 + d24p51 * d13 - (MathType::GetValue(2))*d30 * d35 - d32 * d32;
    poly[3] = d24p51 * d43 + d54 * d13 - (MathType::GetValue(2))*d32 * d35;
    poly[4] = d54 * d43 - d35 * d35;

    return poly;
}

template <typename Real>
typename Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::Measurement Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::RefinePoint(const CoeffType& coeff, const Vector2Type& vector2)
{
    /// 传入多项式为
    ///  f(angle) = d0 + d1 * c + d2 * s + d3 * c^2 + d4 * c * s + d5 * s^2
    /// 其中s = sin(angle)， c = cos(angle)。 导数是
    ///  f'(angle) = -d1 * s + d2 * c + (d5 - d3) * 2 * c * s + d4 * (c^2 - s^2)

    auto diff = vector2 - ellipse0.GetCenter();
    auto cos = Vector2ToolsType::DotProduct(diff, ellipse0.GetAxis0()) / ellipse0.GetExtent0();
    auto sin = Vector2ToolsType::DotProduct(diff, ellipse0.GetAxis1()) / ellipse0.GetExtent1();
    auto aTan = MathType::ATan2(sin, cos);
    auto f0 = coeff.at(0) + coeff.at(1) * cos + coeff.at(2) * sin + coeff.at(3) * cos * cos + coeff.at(4) * cos * sin + coeff.at(5) * sin * sin;
    auto df0 = -coeff.at(1) * sin + coeff.at(2) * cos + (MathType::GetValue(2)) * (coeff.at(5) - coeff.at(3)) * cos * sin + coeff.at(4) * (cos * cos - sin * sin);

    auto a1 = MathType::GetValue(0);

    /// f0值应与q1相匹配（在浮点舍入误差内）。 尝试使用二等分将f0强制为零。
    /// 这需要找到一个角度，使得相应的函数值的符号与f0相反。
    /// 如果搜索失败，则输入点要么是切线相交，要么根本不是相交。
    auto maxIterations = 32;
    auto i = 0;
    for (; i < maxIterations; ++i)
    {
        a1 = aTan - f0 / df0;
        cos = MathType::Cos(a1);
        sin = MathType::Sin(a1);
        auto f1 = coeff.at(0) + coeff.at(1) * cos + coeff.at(2) * sin + coeff.at(3) * cos * cos + coeff.at(4) * cos * sin + coeff.at(5) * sin * sin;

        if (f0 * f1 < MathType::GetValue(0))
        {
            // 切换到二等分。
            break;
        }

        auto df1 = -coeff.at(1) * sin + coeff.at(2) * cos + (MathType::GetValue(2)) * (coeff.at(5) - coeff.at(3)) * cos * sin + coeff.at(4) * (cos * cos - sin * sin);

        if (df1 * df0 < MathType::GetValue(0))
        {
            // 尝试更陡的斜率在寻找一个符号相反值的希望值。
            df0 *= MathType::GetValue(2);
            continue;
        }

        if (MathType::FAbs(f1) < MathType::FAbs(f0))
        {
            /// 我们找不到相反的值，但是新函数的值接近于零，因此请尝试使用新值。
            aTan = a1;
            f0 = f1;
            df0 = df1;
        }
    }

    auto angle = aTan;
    auto transverseResult = false;
    if (i < maxIterations)
    {
        // 应用二等分。 确定迭代次数以获取10位精度。
        auto value0 = MathType::Log(MathType::FAbs(a1 - aTan));
        auto value1 = (static_cast<Real>(digitsAccuracy)) * MathType::Log(MathType::GetValue(10));
        auto arg = (value0 + value1) / MathType::Log(MathType::GetValue(2));
        maxIterations = static_cast<int>(arg + MathType::GetRational(1, 2));
        for (i = 0; i < maxIterations; ++i)
        {
            angle = (MathType::GetRational(1, 2)) * (aTan + a1);
            cos = MathType::Cos(angle);
            sin = MathType::Sin(angle);
            auto f1 = coeff.at(0) + coeff.at(1) * cos + coeff.at(2) * sin + coeff.at(3) * cos * cos + coeff.at(4) * cos * sin + coeff.at(5) * sin * sin;

            auto product = f0 * f1;
            if (product < MathType::GetValue(0))
            {
                a1 = angle;
            }
            else if (MathType::GetValue(0) < product)
            {
                aTan = angle;
                f0 = f1;
            }
            else
            {
                break;
            }
        }
        transverseResult = true;
    }
    else
    {
        transverseResult = false;
    }

    Measurement measure{};

    measure.point = ellipse0.GetCenter() + ellipse0.GetExtent0() * cos * ellipse0.GetAxis0() + ellipse0.GetExtent1() * sin * ellipse0.GetAxis1();
    measure.q0 = ellipse0.Evaluate(vector2);
    measure.q1 = ellipse1.Evaluate(vector2);
    measure.angle0 = angle;
    measure.norm = MathType::Sqrt(measure.q0 * measure.q0 + measure.q1 * measure.q1);
    measure.transverse = transverseResult;

    return measure;
}

// IntrEllipse2Ellipse2::Measurement

template <typename Real>
Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::Measurement::Measurement() noexcept
    : point{ MathType::maxReal, MathType::maxReal }, q0{ MathType::maxReal }, q1{ MathType::maxReal }, norm{ MathType::maxReal }, angle0{ MathType::maxReal }, transverse{ false }
{
}

template <typename Real>
bool Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::Measurement::operator<(const Measurement& measure) const noexcept
{
    if (transverse == measure.transverse)
    {
        return norm < measure.norm;
    }
    else
    {
        return transverse;
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ELLIPSE2_ELLIPSE2_DETAIL_H