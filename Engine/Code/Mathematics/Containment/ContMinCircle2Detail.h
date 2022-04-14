///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/11 10:40)

#ifndef MATHEMATICS_CONTAINMENT_CONT_MIN_CIRCLE2_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_MIN_CIRCLE2_DETAIL_H

#include "ContMinCircle2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"

template <typename Real>
Mathematics::ContMinCircle2<Real>::ContMinCircle2(const std::vector<Vector2<Real>>& points, Circle2<Real>& minimal, Real epsilon)
    : epsilon{ epsilon }, update{ nullptr, &ContMinCircle2<Real>::UpdateSupport1, &ContMinCircle2<Real>::UpdateSupport2, &ContMinCircle2<Real>::UpdateSupport3 }
{
    const auto numPoints = boost::numeric_cast<int>(points.size());
    Support support{};
    Real distDiff{};

    if (numPoints >= 1)
    {
        std::vector<Vector2<Real>> permuted(numPoints);

        for (auto i = 0; i < numPoints; ++i)
        {
            permuted.at(i) = points.at(i);
        }

        for (auto i = numPoints - 1; i > 0; --i)
        {
            const auto j = rand() % (i + 1);
            if (j != i)
            {
                Vector2<Real> save = permuted.at(i);
                permuted.at(i) = permuted.at(j);
                permuted.at(j) = save;
            }
        }

        minimal = ExactCircle1(permuted.at(0));
        support.quantity = 1;
        support.index.at(0) = 0;

        for (auto i = 1 % numPoints, n = 0; i != n; i = (i + 1) % numPoints)
        {
            if (!support.Contains(i, permuted, epsilon))
            {
                if (!Contains(permuted.at(i), minimal, distDiff))
                {
                    auto updateFunction = update.at(support.quantity);
                    if (updateFunction != nullptr)
                    {
                        Circle2<Real> circle{};
                        circle = (this->*updateFunction)(i, permuted, support);
                        if (circle.GetRadius() > minimal.GetRadius())
                        {
                            minimal = circle;
                            n = i;
                        }
                    }
                }
            }
        }
    }
    else
    {
        MATHEMATICS_ASSERTION_0(false, "输入必须包含点。\n");
    }

    minimal.SetCircle(minimal.GetCenter(), Math<Real>::Sqrt(minimal.GetRadius()));

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::ContMinCircle2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::ContMinCircle2<Real>::Contains(const Vector2<Real>& point, const Circle2<Real>& circle, Real& distDiff)
{
    auto diff = point - circle.GetCenter();
    auto test = Vector2Tools<Real>::GetLengthSquared(diff);

    distDiff = test - circle.GetRadius();

    return distDiff <= Math<Real>::GetValue(0);
}

template <typename Real>
Mathematics::Circle2<Real> Mathematics::ContMinCircle2<Real>::ExactCircle1(const Vector2<Real>& p) noexcept
{
    Circle2<Real> minimal{ p, Math<Real>::GetValue(0) };

    return minimal;
}

template <typename Real>
Mathematics::Circle2<Real> Mathematics::ContMinCircle2<Real>::ExactCircle2(const Vector2<Real>& p0, const Vector2<Real>& p1)
{
    auto diff = p1 - p0;
    Circle2<Real> minimal{ Math<Real>::GetRational(1, 2) * (p0 + p1), Math<Real>::GetRational(1, 4) * Vector2Tools<Real>::GetLengthSquared(diff) };

    return minimal;
}

template <typename Real>
Mathematics::Circle2<Real> Mathematics::ContMinCircle2<Real>::ExactCircle3(const Vector2<Real>& p0, const Vector2<Real>& p1, const Vector2<Real>& p2)
{
    auto e10 = p1 - p0;
    auto e20 = p2 - p0;

    std::array<std::array<Real, 2>, 2> a{ std::array<Real, 2>{ e10.GetX(), e10.GetY() }, std::array<Real, 2>{ e20.GetX(), e20.GetY() } };

    Vector2 b{ Math<Real>::GetRational(1, 2) * Vector2Tools<Real>::GetLengthSquared(e10),
               Math<Real>::GetRational(1, 2) * Vector2Tools<Real>::GetLengthSquared(e20) };

    auto det = a.at(0).at(0) * a.at(1).at(1) - a.at(0).at(1) * a.at(1).at(0);

    Vector2<Real> center{};
    Real radius{};
    if (Math<Real>::FAbs(det) > epsilon)
    {
        auto invDet = (Math<Real>::GetValue(1)) / det;
        Vector2<Real> q{};
        q.SetX((a.at(1).at(1) * b[0] - a.at(0).at(1) * b[1]) * invDet);
        q.SetY((a.at(0).at(0) * b[1] - a.at(1).at(0) * b[0]) * invDet);
        center = p0 + q;
        radius = Vector2Tools<Real>::GetLengthSquared(q);
    }
    else
    {
        center = Vector2<Real>::GetZero();
        radius = Math<Real>::maxReal;
    }

    Circle2<Real> minimal{ center, radius };

    return minimal;
}

template <typename Real>
Mathematics::Circle2<Real> Mathematics::ContMinCircle2<Real>::UpdateSupport1(int i, const std::vector<Vector2<Real>>& permuted, Support& support)
{
    const auto& p0 = permuted.at(support.index.at(0));
    const auto& p1 = permuted.at(i);

    auto minimal = ExactCircle2(p0, p1);
    support.quantity = 2;
    support.index.at(1) = i;

    return minimal;
}

template <typename Real>
Mathematics::Circle2<Real> Mathematics::ContMinCircle2<Real>::UpdateSupport2(int i, const std::vector<Vector2<Real>>& permuted, Support& support)
{
    std::array<Vector2<Real>, 2> point{ permuted.at(support.index.at(0)), permuted.at(support.index.at(1)) };
    const auto& p2 = permuted.at(i);

    constexpr auto numType2 = 2;
    const std::array<std::array<int, 2>, numType2> type2 = { std::array<int, 2>{ 0, 1 }, std::array<int, 2>{ 1, 0 } };

    constexpr auto numType3 = 1;

    std::array<Circle2<Real>, numType2 + numType3> circle{};
    auto indexCircle = 0;
    auto minRSqr = Math<Real>::maxReal;
    auto indexMinRSqr = -1;
    Real distDiff{};
    auto minDistDiff = Math<Real>::maxReal;
    auto indexMinDistDiff = -1;

    for (auto j = 0; j < numType2; ++j, ++indexCircle)
    {
        circle.at(indexCircle) = ExactCircle2(point.at(type2.at(j).at(0)), p2);
        if (circle.at(indexCircle).GetRadius() < minRSqr)
        {
            if (Contains(point.at(type2.at(j).at(1)), circle.at(indexCircle), distDiff))
            {
                minRSqr = circle.at(indexCircle).GetRadius();
                indexMinRSqr = indexCircle;
            }
            else if (distDiff < minDistDiff)
            {
                minDistDiff = distDiff;
                indexMinDistDiff = indexCircle;
            }
        }
    }

    circle.at(indexCircle) = ExactCircle3(point.at(0), point.at(1), p2);
    if (circle.at(indexCircle).GetRadius() < minRSqr)
    {
        minRSqr = circle.at(indexCircle).GetRadius();
        indexMinRSqr = indexCircle;
    }

    if (indexMinRSqr == -1)
    {
        indexMinRSqr = indexMinDistDiff;
    }

    auto minimal = circle.at(indexMinRSqr);
    switch (indexMinRSqr)
    {
        case 0:
            support.index.at(1) = i;
            break;
        case 1:
            support.index.at(0) = i;
            break;
        case 2:
            support.quantity = 3;
            support.index.at(2) = i;
            break;
        default:
            break;
    }

    return minimal;
}

template <typename Real>
Mathematics::Circle2<Real> Mathematics::ContMinCircle2<Real>::UpdateSupport3(int i, const std::vector<Vector2<Real>>& permuted, Support& support)
{
    std::array<Vector2<Real>, 3> point{ permuted.at(support.index.at(0)), permuted.at(support.index.at(1)), permuted.at(support.index.at(2)) };

    const auto& p3 = permuted.at(i);

    constexpr auto numType2 = 3;
    const std::array<std::array<int, 3>, numType2> type2{ std::array<int, 3>{ 0, 1, 2 }, std::array<int, 3>{ 1, 0, 2 }, std::array<int, 3>{ 2, 0, 1 } };

    constexpr auto numType3 = 3;
    const std::array<std::array<int, 3>, numType3> type3{ std::array<int, 3>{ 0, 1, 2 }, std::array<int, 3>{ 0, 2, 1 }, std::array<int, 3>{ 1, 2, 0 } };

    std::array<Circle2<Real>, numType2 + numType3> circle{};

    auto indexCircle = 0;
    auto minRSqr = Math<Real>::maxReal;
    auto indexMinRSqr = -1;
    Real distDiff{};
    auto minDistDiff = Math<Real>::maxReal;
    auto indexMinDistDiff = -1;

    for (auto j = 0; j < numType2; ++j, ++indexCircle)
    {
        circle.at(indexCircle) = ExactCircle2(point.at(type2.at(j).at(0)), p3);
        if (circle.at(indexCircle).GetRadius() < minRSqr)
        {
            if (Contains(point.at(type2.at(j).at(1)), circle.at(indexCircle), distDiff) && Contains(point.at(type2.at(j).at(2)), circle.at(indexCircle), distDiff))
            {
                minRSqr = circle.at(indexCircle).GetRadius();
                indexMinRSqr = indexCircle;
            }
            else if (distDiff < minDistDiff)
            {
                minDistDiff = distDiff;
                indexMinDistDiff = indexCircle;
            }
        }
    }

    for (auto j = 0; j < numType3; ++j, ++indexCircle)
    {
        circle.at(indexCircle) = ExactCircle3(point.at(type3.at(j).at(0)), point.at(type3.at(j).at(1)), p3);
        if (circle.at(indexCircle).GetRadius() < minRSqr)
        {
            if (Contains(point.at(type3.at(j).at(2)), circle.at(indexCircle), distDiff))
            {
                minRSqr = circle.at(indexCircle).GetRadius();
                indexMinRSqr = indexCircle;
            }
            else if (distDiff < minDistDiff)
            {
                minDistDiff = distDiff;
                indexMinDistDiff = indexCircle;
            }
        }
    }

    if (indexMinRSqr == -1)
    {
        indexMinRSqr = indexMinDistDiff;
    }

    auto minimal = circle.at(indexMinRSqr);

    switch (indexMinRSqr)
    {
        case 0:
            support.quantity = 2;
            support.index.at(1) = i;
            break;
        case 1:
            support.quantity = 2;
            support.index.at(0) = i;
            break;
        case 2:
            support.quantity = 2;
            support.index.at(0) = support.index.at(2);
            support.index.at(1) = i;
            break;
        case 3:
            support.index.at(2) = i;
            break;
        case 4:
            support.index.at(1) = i;
            break;
        case 5:
            support.index.at(0) = i;
            break;
        default:
            break;
    }

    return minimal;
}

template <typename Real>
bool Mathematics::ContMinCircle2<Real>::Support::Contains(int pointIndex, const std::vector<Vector2<Real>>& points, Real epsilon) const
{
    for (auto i = 0; i < quantity; ++i)
    {
        auto diff = points.at(pointIndex) - points.at(index.at(i));
        if (Vector2Tools<Real>::GetLengthSquared(diff) < epsilon)
        {
            return true;
        }
    }

    return false;
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_MIN_CIRCLE2_DETAIL_H