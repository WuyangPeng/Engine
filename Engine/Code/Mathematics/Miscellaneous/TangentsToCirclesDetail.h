///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/24 22:10)

#ifndef MATHEMATICS_MISCELLANEOUS_TANGENTS_TO_CIRCLES_DETAIL_H
#define MATHEMATICS_MISCELLANEOUS_TANGENTS_TO_CIRCLES_DETAIL_H

#include "TangentsToCircles.h"

#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Objects2D/Circle2Detail.h"
#include "Mathematics/Objects2D/Line2Detail.h"

template <typename Real>
void GetDirections(const Mathematics::Vector2<Real>& w, Real a, Mathematics::Vector2<Real>& dir0, Mathematics::Vector2<Real>& dir1)
{
    using Mathematics::Math;

    auto a2 = a * a;
    auto wx2 = w.GetX() * w.GetX();
    auto wy2 = w.GetY() * w.GetY();
    auto c2 = wx2 + wy2;
    auto minusHalfInvC2 = Math<Real>::GetRational(1, 2) / c2;

    if (Math<Real>::FAbs(w.GetX()) >= Math<Real>::FAbs(w.GetY()))
    {
        auto c0 = a2 - wx2;
        auto c1 = -(Math<Real>::GetValue(2)) * a * w.GetY();
        auto discr = c1 * c1 - (Math<Real>::GetValue(4)) * c0 * c2;
        auto root = Math<Real>::Sqrt(Math<Real>::FAbs(discr));
        auto inv = (Math<Real>::GetValue(1)) / w.GetX();
        dir0[1] = (c1 + root) * minusHalfInvC2;
        dir0[0] = (a - w.GetY() * dir0.GetY()) * inv;
        dir1[1] = (c1 - root) * minusHalfInvC2;
        dir1[0] = (a - w.GetY() * dir1.GetY()) * inv;
    }
    else
    {
        auto c0 = a2 - wy2;
        auto c1 = -(Math<Real>::GetValue(2)) * a * w.GetX();
        auto discr = c1 * c1 - (Math<Real>::GetValue(4)) * c0 * c2;
        auto root = Math<Real>::Sqrt(Math<Real>::FAbs(discr));
        auto inv = (Math<Real>::GetValue(1)) / w.GetY();
        dir0[0] = (c1 + root) * minusHalfInvC2;
        dir0[1] = (a - w.GetX() * dir0.GetX()) * inv;
        dir1[0] = (c1 - root) * minusHalfInvC2;
        dir1[1] = (a - w.GetX() * dir1.GetX()) * inv;
    }
}

template <typename Real>
bool Mathematics::TangentsToCircles<Real>::GetTangentsToCircles(const Circle2<Real>& circle0, const Circle2<Real>& circle1, std::array<Line2<Real>, 4>& line)
{
    auto w = circle1.GetCenter() - circle0.GetCenter();
    auto wLenSqr = Vector2Tools<Real>::GetLengthSquared(w);
    auto rSum = circle0.GetRadius() + circle1.GetRadius();
    if (wLenSqr <= rSum * rSum)
    {
        return false;
    }

    auto r0Sqr = circle0.GetRadius() * circle0.GetRadius();

    auto rDiff = circle1.GetRadius() - circle0.GetRadius();
    if (Math<Real>::FAbs(rDiff) >= Math<Real>::GetZeroTolerance())
    {
        auto r1Sqr = circle1.GetRadius() * circle1.GetRadius();
        auto c0 = -r0Sqr;
        auto c1 = (Math<Real>::GetValue(2)) * r0Sqr;
        auto c2 = circle1.GetRadius() * circle1.GetRadius() - r0Sqr;
        auto minusHalfInvC2 = Math<Real>::GetRational(-1, 2) / c2;
        auto discr = Math<Real>::FAbs(c1 * c1 - (Math<Real>::GetValue(4)) * c0 * c2);
        auto root = Math<Real>::Sqrt(discr);

        auto s = (c1 + root) * minusHalfInvC2;
        line.at(0).SetOrigin(circle0.GetCenter() + s * w);
        line.at(1).SetOrigin(line.at(0).GetOrigin());
        Real a{};
        if (s >= Math<Real>::GetRational(1, 2))
        {
            auto tmp = Math<Real>::FAbs(wLenSqr - r0Sqr / (s * s));
            a = Math<Real>::Sqrt(tmp);
        }
        else
        {
            auto oneMinusS = Math<Real>::GetValue(1) - s;
            auto tmp = Math<Real>::FAbs(wLenSqr - r1Sqr / (oneMinusS * oneMinusS));
            a = Math<Real>::Sqrt(tmp);
        }
        Vector2<Real> direction0{};
        Vector2<Real> direction1{};
        GetDirections(w, a, direction0, direction1);
        line.at(0).SetDirection(direction0);
        line.at(1).SetDirection(direction1);

        s = (c1 - root) * minusHalfInvC2;
        line.at(2).SetOrigin(circle0.GetCenter() + s * w);
        line.at(3).SetOrigin(line.at(2).GetOrigin());
        if (s >= Math<Real>::GetRational(1, 2))
        {
            auto tmp = Math<Real>::FAbs(wLenSqr - r0Sqr / (s * s));
            a = Math<Real>::Sqrt(tmp);
        }
        else
        {
            auto oneMinusS = Math<Real>::GetValue(1) - s;
            auto tmp = Math<Real>::FAbs(wLenSqr - r1Sqr / (oneMinusS * oneMinusS));
            a = Math<Real>::Sqrt(tmp);
        }

        Vector2<Real> direction2{};
        Vector2<Real> direction3{};
        GetDirections(w, a, direction2, direction3);
        line.at(2).SetDirection(direction2);
        line.at(3).SetDirection(direction3);
    }
    else
    {
        auto mid = (Math<Real>::GetRational(1, 2)) * (circle0.GetCenter() + circle1.GetCenter());

        auto tmp = Math<Real>::FAbs(wLenSqr - (Math<Real>::GetValue(4)) * r0Sqr);
        auto a = Math<Real>::Sqrt(tmp);
        Vector2<Real> direction0{};
        Vector2<Real> direction1{};
        GetDirections(w, a, direction0, direction1);
        line.at(0).SetDirection(direction0);
        line.at(1).SetDirection(direction1);
        line.at(0).SetOrigin(mid);
        line.at(1).SetOrigin(mid);

        w /= Math<Real>::Sqrt(wLenSqr);

        line.at(2).SetOrigin(Vector2<Real>(mid.GetX() + circle0.GetRadius() * w.GetY(), mid.GetY() - circle0.GetRadius() * w.GetX()));
        line.at(2).SetDirection(w);
        line.at(3).SetOrigin(Vector2<Real>(mid.GetX() - circle0.GetRadius() * w.GetY(), mid.GetY() + circle0.GetRadius() * w.GetX()));
        line.at(3).SetDirection(w);
    }

    return true;
}

#endif  // MATHEMATICS_MISCELLANEOUS_TANGENTS_TO_CIRCLES_DETAIL_H