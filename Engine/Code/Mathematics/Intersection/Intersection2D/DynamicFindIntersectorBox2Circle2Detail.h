///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 19:24)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX2_CIRCLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX2_CIRCLE2_DETAIL_H

#include "DynamicFindIntersectorBox2Circle2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Distance/Distance2D/DistancePoint2Box2Detail.h"

template <typename Real>
Mathematics::DynamicFindIntersectorBox2Circle2<Real>::DynamicFindIntersectorBox2Circle2(const Box2& box, const Circle2& circle, Real tmax, const Vector2& lhsVelocity, const Vector2& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, box{ box }, circle{ circle }, contactPoint{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DynamicFindIntersectorBox2Circle2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Box2<Real> Mathematics::DynamicFindIntersectorBox2Circle2<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return box;
}

template <typename Real>
Mathematics::Circle2<Real> Mathematics::DynamicFindIntersectorBox2Circle2<Real>::GetCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return circle;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::DynamicFindIntersectorBox2Circle2<Real>::GetContactPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return contactPoint;
}

template <typename Real>
Mathematics::DynamicFindIntersectorBox2Circle2<Real>::RegionInfo::RegionInfo(IntersectingType type, Real x, Real y) noexcept
    : type{ type }, x{ x }, y{ y }
{
}

template <typename Real>
Mathematics::DynamicFindIntersectorBox2Circle2<Real>::RegionInfo::RegionInfo(IntersectingType type) noexcept
    : type{ type }, x{}, y{}
{
}

template <typename Real>
void Mathematics::DynamicFindIntersectorBox2Circle2<Real>::Find()
{
    // 将圆心转换为盒坐标。
    const auto centerDiff = circle.GetCenter() - box.GetCenter();
    const auto velocityDiff = this->GetRhsVelocity() - this->GetLhsVelocity();
    const auto centerDotX = Vector2Tools<Real>::DotProduct(centerDiff, box.GetAxis0());
    const auto centerDotY = Vector2Tools<Real>::DotProduct(centerDiff, box.GetAxis1());
    const auto velocityDotX = Vector2Tools<Real>::DotProduct(velocityDiff, box.GetAxis0());
    const auto velocityDotY = Vector2Tools<Real>::DotProduct(velocityDiff, box.GetAxis1());
    const auto extent0 = box.GetExtent0();
    const auto extent1 = box.GetExtent1();

    auto type = IntersectingType::NoIntersection;
    auto indexX = Math::GetValue(0);
    auto indexY = Math::GetValue(0);

    if (centerDotX < -extent0)
    {
        if (centerDotY < -extent1)
        {
            // 区域 Rmm
            const auto regionInfo = TestVertexRegion(centerDotX, centerDotY, velocityDotX, velocityDotY, extent0, extent1);
            type = regionInfo.type;
            indexX = regionInfo.x;
            indexY = regionInfo.y;
        }
        else if (centerDotY <= extent1)
        {
            // 区域 Rmz
            const auto regionInfo = TestEdgeRegion(centerDotX, centerDotY, velocityDotX, velocityDotY, extent0, extent1);
            type = regionInfo.type;
            indexX = regionInfo.x;
            indexY = regionInfo.y;
        }
        else
        {
            // 区域 Rmp
            const auto regionInfo = TestVertexRegion(centerDotX, -centerDotY, velocityDotX, -velocityDotY, extent0, extent1);
            type = regionInfo.type;
            indexX = regionInfo.x;
            indexY = -regionInfo.y;
        }
    }
    else if (centerDotX <= extent0)
    {
        if (centerDotY < -extent1)
        {
            // 区域 Rzm
            const auto regionInfo = TestEdgeRegion(centerDotY, centerDotX, velocityDotY, velocityDotX, extent1, extent0);
            type = regionInfo.type;
            indexX = regionInfo.y;
            indexY = regionInfo.x;
        }
        else if (centerDotY <= extent1)
        {
            // 区域 Rzz:
            // 圆圈已经与盒子相交了。 使用圆心作为交点，但通过返回“其他”交点，可以使调用者知道对象重叠。
            this->SetContactTime(Math::GetValue(0));
            contactPoint = circle.GetCenter();
            this->SetIntersectionType(IntersectionType::Other);
            return;
        }
        else
        {
            // 区域 Rzp
            const auto regionInfo = TestEdgeRegion(-centerDotY, centerDotX, -velocityDotY, velocityDotX, extent1, extent0);
            type = regionInfo.type;
            indexX = regionInfo.y;
            indexY = -regionInfo.x;
        }
    }
    else
    {
        if (centerDotY < -extent1)
        {
            // 区域 Rpm
            const auto regionInfo = TestVertexRegion(-centerDotX, centerDotY, -velocityDotX, velocityDotY, extent0, extent1);
            type = regionInfo.type;
            indexX = -regionInfo.x;
            indexY = regionInfo.y;
        }
        else if (centerDotY <= extent1)
        {
            // 区域 Rpz
            const auto regionInfo = TestEdgeRegion(-centerDotX, centerDotY, -velocityDotX, velocityDotY, extent0, extent1);
            type = regionInfo.type;
            indexX = -regionInfo.x;
            indexY = regionInfo.y;
        }
        else
        {
            // 区域 Rpp
            const auto regionInfo = TestVertexRegion(-centerDotX, -centerDotY, -velocityDotX, -velocityDotY, extent0, extent1);
            type = regionInfo.type;
            indexX = -regionInfo.x;
            indexY = -regionInfo.y;
        }
    }

    if (type != IntersectingType::Intersect || this->GetTMax() < this->GetContactTime())
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
    else
    {
        contactPoint = box.GetCenter() + indexX * box.GetAxis0() + indexY * box.GetAxis1();
        this->SetIntersectionType(IntersectionType::Point);
    }
}

template <typename Real>
typename Mathematics::DynamicFindIntersectorBox2Circle2<Real>::RegionInfo Mathematics::DynamicFindIntersectorBox2Circle2<Real>::TestVertexRegion(Real centerDotX, Real centerDotY, Real velocityDotX, Real velocityDotY, Real extent0, Real extent1) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    auto dx = centerDotX + extent0;
    auto dy = centerDotY + extent1;
    auto radiusSqr = circle.GetRadius() * circle.GetRadius();
    auto diff = dx * dx + dy * dy - radiusSqr;
    if (diff <= Math::GetValue(0))
    {
        // 圆圈已经与盒子相交了。
        this->SetContactTime(Math::GetValue(0));
        return RegionInfo{ IntersectingType::Initially };
    }

    auto dot = velocityDotX * dx + velocityDotY * dy;
    if (Math::GetValue(0) <= dot)
    {
        // 圆圈未移向盒子。
        return RegionInfo{ IntersectingType::NoIntersection };
    }

    auto dotPerp = velocityDotX * dy - velocityDotY * dx;
    auto indexX = Math::GetValue(0);
    auto indexY = Math::GetValue(0);

    if (Math::GetValue(0) <= dotPerp)
    {
        // 潜在接触在左边缘。
        if (dotPerp <= circle.GetRadius() * velocityDotY)
        {
            // 左下角是第一个接触点。
            auto velocitySqr = velocityDotX * velocityDotX + velocityDotY * velocityDotY;
            auto inv = Math::InvSqrt(Math::FAbs(dot * dot - velocitySqr * diff));
            this->SetContactTime(diff * inv / (Math::GetValue(1) - dot * inv));

            return RegionInfo{ IntersectingType::Intersect, -extent0, -extent1 };
        }

        if (velocityDotX <= Math::GetValue(0))
        {
            // 经过角，离开盒子。
            return RegionInfo{ IntersectingType::NoIntersection };
        }

        auto velocitySqr = velocityDotX * velocityDotX + velocityDotY * velocityDotY;
        dy = centerDotY - extent1;
        dotPerp = velocityDotX * dy - velocityDotY * dx;
        if (Math::GetValue(0) <= dotPerp && radiusSqr * velocitySqr < dotPerp * dotPerp)
        {
            // 圆圈未命中盒子。
            return RegionInfo{ IntersectingType::NoIntersection, indexX, indexY };
        }

        // 圆圈将与盒子相交。 用x = xmin确定第一次接触的时间和位置。
        indexX = -extent0;

        if (dotPerp <= circle.GetRadius() * velocityDotY)
        {
            // 第一次接触在盒子的左边缘。
            this->SetContactTime(-(dx + circle.GetRadius()) / velocityDotX);
            indexY = centerDotY + this->GetContactTime() * velocityDotY;
        }
        else
        {
            // 盒子的左上角的第一个接触点。
            dot = velocityDotX * dx + velocityDotY * dy;
            diff = dx * dx + dy * dy - radiusSqr;
            auto inv = Math::InvSqrt(Math::FAbs(dot * dot - velocitySqr * diff));
            this->SetContactTime(diff * inv / (Math::GetValue(1) - dot * inv));
            indexY = extent1;
        }
    }
    else
    {
        // 上底部边缘潜在接触。
        if (-dotPerp <= circle.GetRadius() * velocityDotX)
        {
            // 左下角是第一个接触点。

            auto velocitySqr = velocityDotX * velocityDotX + velocityDotY * velocityDotY;
            auto inv = Math::InvSqrt(Math::FAbs(dot * dot - velocitySqr * diff));
            this->SetContactTime(diff * inv / (Math::GetValue(1) - dot * inv));

            return RegionInfo{ IntersectingType::Intersect, -extent0, -extent1 };
        }

        if (velocityDotY <= Math::GetValue(0))
        {
            // 经过角，离开盒子。
            return RegionInfo{ IntersectingType::NoIntersection, indexX, indexY };
        }

        auto velocitySqr = velocityDotX * velocityDotX + velocityDotY * velocityDotY;
        dx = centerDotX - extent0;
        dotPerp = velocityDotX * dy - velocityDotY * dx;
        if (Math::GetValue(0) <= -dotPerp && radiusSqr * velocitySqr < dotPerp * dotPerp)
        {
            // 圆圈未命中盒子。
            return RegionInfo{ IntersectingType::NoIntersection, indexX, indexY };
        }

        // 圆将与盒子相交。 确定第一次接触的时间和地点，y = ymin。
        indexY = -extent1;

        if (-dotPerp <= circle.GetRadius() * velocityDotX)
        {
            // 盒子底部边缘的第一次接触。
            this->SetContactTime(-(dy + circle.GetRadius()) / velocityDotY);
            indexX = centerDotX + this->GetContactTime() * velocityDotX;
        }
        else
        {
            // 第一次接触在盒子的右下角。
            dot = velocityDotX * dx + velocityDotY * dy;
            diff = dx * dx + dy * dy - radiusSqr;
            auto inv = Math::InvSqrt(Math::FAbs(dot * dot - velocitySqr * diff));
            this->SetContactTime(diff * inv / (Math::GetValue(1) - dot * inv));
            indexX = extent0;
        }
    }

    return RegionInfo{ IntersectingType::Intersect, indexX, indexY };
}

template <typename Real>
typename Mathematics::DynamicFindIntersectorBox2Circle2<Real>::RegionInfo Mathematics::DynamicFindIntersectorBox2Circle2<Real>::TestEdgeRegion(Real centerDotX, Real centerDotY, Real velocityDotX, Real velocityDotY, Real extent0, Real extent1) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    auto indexX = Math::GetValue(0);
    auto indexY = Math::GetValue(0);
    auto dx = centerDotX + extent0;
    auto xSignedDist = dx + circle.GetRadius();
    if (Math::GetValue(0) <= xSignedDist)
    {
        // 圆圈已经与盒子相交了。
        this->SetContactTime(Math::GetValue(0));

        return RegionInfo{ IntersectingType::Initially, indexX, indexY };
    }

    if (velocityDotX <= Math::GetValue(0))
    {
        // 圆圈未移向盒子。
        return RegionInfo{ IntersectingType::NoIntersection, indexX, indexY };
    }

    auto radiusSqr = circle.GetRadius() * circle.GetRadius();
    auto velocitySqr = velocityDotX * velocityDotX + velocityDotY * velocityDotY;

    if (Math::GetValue(0) <= velocityDotY)
    {
        auto dy = centerDotY - extent1;
        auto dotPerp = velocityDotX * dy - velocityDotY * dx;
        if (Math::GetValue(0) <= dotPerp && radiusSqr * velocitySqr < dotPerp * dotPerp)
        {
            // 圆圈未命中盒子。
            return RegionInfo{ IntersectingType::NoIntersection, indexX, indexY };
        }

        // 圆圈将与盒子相交。 用x = xmin确定第一次接触的时间和位置。
        indexX = -extent0;

        if (dotPerp <= circle.GetRadius() * velocityDotY)
        {
            // 第一次接触在盒子的左边缘。
            this->SetContactTime(-xSignedDist / velocityDotX);
            indexY = centerDotY + this->GetContactTime() * velocityDotY;
        }
        else
        {
            // 第一次接触在盒子的一角。
            auto dot = velocityDotX * dx + velocityDotY * dy;
            auto diff = dx * dx + dy * dy - radiusSqr;
            auto inv = Math::InvSqrt(Math::FAbs(dot * dot - velocitySqr * diff));
            this->SetContactTime(diff * inv / (Math::GetValue(1) - dot * inv));
            indexY = extent1;
        }
    }
    else
    {
        auto dy = centerDotY + extent1;
        auto dotPerp = velocityDotX * dy - velocityDotY * dx;
        if (dotPerp <= Math::GetValue(0) && radiusSqr * velocitySqr < dotPerp * dotPerp)
        {
            // 圆圈未命中盒子。
            return RegionInfo{ IntersectingType::NoIntersection, indexX, indexY };
        }

        // 圆圈将与盒子相交。 确定第一次接触的地方，x = xmin。
        indexX = -extent0;

        if (dotPerp >= circle.GetRadius() * velocityDotY)
        {
            // 第一次接触在盒子的左边缘。
            this->SetContactTime(-xSignedDist / velocityDotX);
            indexY = centerDotY + this->GetContactTime() * velocityDotY;
        }
        else
        {
            // 第一次接触在盒子的一角。
            auto dot = velocityDotX * dx + velocityDotY * dy;
            auto diff = dx * dx + dy * dy - radiusSqr;
            auto inv = Math::InvSqrt(Math::FAbs(dot * dot - velocitySqr * diff));
            this->SetContactTime(diff * inv / (Math::GetValue(1) - dot * inv));
            indexY = -extent1;
        }
    }

    return RegionInfo{ IntersectingType::Intersect, indexX, indexY };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX2_CIRCLE2_DETAIL_H