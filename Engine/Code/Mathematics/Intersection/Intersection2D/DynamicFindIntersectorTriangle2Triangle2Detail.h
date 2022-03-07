///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/23 14:55)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_DETAIL_H

#include "DynamicFindIntersectorTriangle2Triangle2.h"
#include "StaticFindIntersectorTriangle2Triangle2Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/StaticFindIntersector1.h"

template <typename Real>
Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::DynamicFindIntersectorTriangle2Triangle2(const Triangle2& triangle0, const Triangle2& triangle1, Real tmax, const Vector2& velocity0, const Vector2& velocity1, const Real epsilon)
    : ParentType{ tmax, velocity0, velocity1, epsilon }, triangle0{ triangle0 }, triangle1{ triangle1 }, point{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Triangle2<Real> Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::GetTriangle0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle0;
}

template <typename Real>
Mathematics::Triangle2<Real> Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::GetTriangle1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle1;
}

template <typename Real>
int Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(point.size());
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point.at(index);
}

template <typename Real>
void Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::Find()
{
    // 好像V0三角形是固定的，而V1三角形是移动的。
    const auto velocityDiff = this->GetRhsVelocity() - this->GetLhsVelocity();

    IntersectInfo intersectInfo{};

    const auto vertex0 = triangle0.GetVertex();
    const auto vertex1 = triangle1.GetVertex();

    // 处理V0三角形的边缘。
    for (auto i0 = 1, i1 = 2, i2 = 0; i2 < size; i0 = i1, i1 = i2++)
    {
        const auto& vertor1 = vertex0.at(i1);
        const auto& vertor2 = vertex0.at(i2);

        // 测试轴 V0[i1] + t * perp(V0[i2] - V0[i1]), perp(x,y) = (y,-x).
        const Vector2 axis{ vertor2.GetY() - vertor1.GetY(), vertor1.GetX() - vertor2.GetX() };
        const auto speed = Vector2Tools::DotProduct(axis, velocityDiff);

        const auto cfg0 = ComputeTwo(vertex0, axis, i0, i1, i2);
        const auto cfg1 = ComputeThree(vertex1, axis, vertor1);

        intersectInfo = NoIntersect(cfg0, cfg1, this->GetTMax(), speed);
        if (intersectInfo.result)
        {
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // 处理V1三角形的边缘。
    for (auto i0 = 1, i1 = 2, i2 = 0; i2 < size; i0 = i1, i1 = i2++)
    {
        const auto& vertor1 = vertex1.at(i1);
        const auto& vertor2 = vertex1.at(i2);

        // 测试轴 V1[i1] + t*perp(V1[i2]-V1[i1]), perp(x,y) = (y,-x).

        const Vector2 axis{ vertor2.GetY() - vertor1.GetY(), vertor1.GetX() - vertor2.GetX() };
        const auto speed = Vector2Tools::DotProduct(axis, velocityDiff);

        const auto cfg1 = ComputeTwo(vertex1, axis, i0, i1, i2);
        const auto cfg0 = ComputeThree(vertex0, axis, vertor1);

        intersectInfo = NoIntersect(cfg0, cfg1, this->GetTMax(), speed);
        if (intersectInfo.result)
        {
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // 将三角形移动到第一个接触点。
    const Vector2Container moveV0{ vertex0.at(0) + intersectInfo.tFirst * this->GetLhsVelocity(),
                                   vertex0.at(1) + intersectInfo.tFirst * this->GetLhsVelocity(),
                                   vertex0.at(2) + intersectInfo.tFirst * this->GetLhsVelocity() };
    const Vector2Container moveV1{ vertex1.at(0) + intersectInfo.tFirst * this->GetRhsVelocity(),
                                   vertex1.at(1) + intersectInfo.tFirst * this->GetRhsVelocity(),
                                   vertex1.at(2) + intersectInfo.tFirst * this->GetRhsVelocity() };

    point = GetIntersection(intersectInfo.tCfg0, intersectInfo.tCfg1, intersectInfo.side, moveV0, moveV1);

    this->SetContactTime(intersectInfo.tFirst);
    if (0 < GetQuantity())
    {
        this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

template <typename Real>
typename Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::Configuration Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::ComputeTwo(const Intersection& vertex, const Vector2& axis, int i0, int i1, int i2)
{
    Configuration cfg{};

    cfg.projectionMap = ProjectionMap::M12;
    cfg.index = decltype(cfg.index){ i0, i1, i2 };
    cfg.min = Vector2Tools::DotProduct(axis, (vertex.at(i0) - vertex.at(i1)));
    cfg.max = Math::GetValue(0);

    return cfg;
}

template <typename Real>
typename Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::Configuration Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::ComputeThree(const Intersection& vertex, const Vector2& axis, const Vector2& vector)
{
    Configuration cfg{};

    const auto d0 = Vector2Tools::DotProduct(axis, (vertex.at(0) - vector));
    const auto d1 = Vector2Tools::DotProduct(axis, (vertex.at(1) - vector));
    const auto d2 = Vector2Tools::DotProduct(axis, (vertex.at(2) - vector));

    /// 每当映射值为M12或M21时，请确保m_aiIndex[...]是（0,1,2）的偶数排列。 这需要确保重叠边缘的交点得到正确计算。

    if (d0 <= d1)
    {
        if (d1 <= d2)  // d0 <= d1 <= d2
        {
            if (!Math::Approximate(d0, d1))
            {
                cfg.projectionMap = (!Math::Approximate(d1, d2) ? ProjectionMap::M11 : ProjectionMap::M12);
            }
            else
            {
                cfg.projectionMap = ProjectionMap::M21;
            }

            cfg.index = decltype(cfg.index){ 0, 1, 2 };

            cfg.min = d0;
            cfg.max = d2;
        }
        else if (d0 <= d2)  // d0 <= d2 < d1
        {
            if (!Math::Approximate(d0, d2))
            {
                cfg.projectionMap = ProjectionMap::M11;

                cfg.index = decltype(cfg.index){ 0, 2, 1 };
            }
            else
            {
                cfg.projectionMap = ProjectionMap::M21;

                cfg.index = decltype(cfg.index){ 2, 0, 1 };
            }

            cfg.min = d0;
            cfg.max = d1;
        }
        else  // d2 < d0 <= d1
        {
            cfg.projectionMap = (!Math::Approximate(d0, d1) ? ProjectionMap::M12 : ProjectionMap::M11);

            cfg.index = decltype(cfg.index){ 2, 0, 1 };

            cfg.min = d2;
            cfg.max = d1;
        }
    }
    else
    {
        if (d2 <= d1)  // d2 <= d1 < d0
        {
            if (!Math::Approximate(d1, d2))
            {
                cfg.projectionMap = ProjectionMap::M11;

                cfg.index = decltype(cfg.index){ 2, 1, 0 };
            }
            else
            {
                cfg.projectionMap = ProjectionMap::M21;

                cfg.index = decltype(cfg.index){ 1, 2, 0 };
            }

            cfg.min = d2;
            cfg.max = d0;
        }
        else if (d2 <= d0)  // d1 < d2 <= d0
        {
            cfg.projectionMap = (!Math::Approximate(d0, d2) ? ProjectionMap::M11 : ProjectionMap::M12);

            cfg.index = decltype(cfg.index){ 1, 2, 0 };

            cfg.min = d1;
            cfg.max = d0;
        }
        else  // d1 < d0 < d2
        {
            cfg.projectionMap = ProjectionMap::M11;

            cfg.index = decltype(cfg.index){ 1, 0, 1 };

            cfg.min = d1;
            cfg.max = d2;
        }
    }

    return cfg;
}

template <typename Real>
typename Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::IntersectInfo Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::NoIntersect(const Configuration& cfg0, const Configuration& cfg1, Real tmax, Real speed) noexcept
{
    IntersectInfo intersectInfo{};

    if (cfg1.max < cfg0.min)
    {
        // V1间隔最初位于V0间隔的左侧。
        if (speed <= Math::GetValue(0))
        {
            // 间隔分开。
            intersectInfo.result = true;
            return intersectInfo;
        }

        // 第一次更新。
        auto invSpeed = (Math::GetValue(1)) / speed;
        auto t = (cfg0.min - cfg1.max) * invSpeed;
        if (intersectInfo.tFirst < t)
        {
            intersectInfo.tFirst = t;
            intersectInfo.side = SideType::Left;
            intersectInfo.tCfg0 = cfg0;
            intersectInfo.tCfg1 = cfg1;
        }

        // 测试是否超过时间间隔。
        if (tmax < intersectInfo.tFirst)
        {
            intersectInfo.result = true;
            return intersectInfo;
        }

        // 更新 last time.
        t = (cfg0.max - cfg1.min) * invSpeed;
        if (t < intersectInfo.tLast)
        {
            intersectInfo.tLast = t;
        }

        // 测试分离。
        if (intersectInfo.tLast < intersectInfo.tFirst)
        {
            intersectInfo.result = true;
            return intersectInfo;
        }
    }
    else if (cfg0.max < cfg1.min)
    {
        // V1间隔最初位于V0间隔的右侧。
        if (Math::GetValue(0) <= speed)
        {
            // 间隔分开。
            intersectInfo.result = true;
            return intersectInfo;
        }

        // 更新 first time.
        auto invSpeed = (Math::GetValue(1)) / speed;
        auto t = (cfg0.max - cfg1.min) * invSpeed;
        if (intersectInfo.tFirst < t)
        {
            intersectInfo.tFirst = t;
            intersectInfo.side = SideType::Right;
            intersectInfo.tCfg0 = cfg0;
            intersectInfo.tCfg1 = cfg1;
        }

        // 测试是否超过时间间隔。
        if (tmax < intersectInfo.tFirst)
        {
            intersectInfo.result = true;
            return intersectInfo;
        }

        // 更新 last time.
        t = (cfg0.min - cfg1.max) * invSpeed;
        if (t < intersectInfo.tLast)
        {
            intersectInfo.tLast = t;
        }

        // 测试分离。.
        if (intersectInfo.tLast < intersectInfo.tFirst)
        {
            intersectInfo.result = true;
            return intersectInfo;
        }
    }
    else
    {
        // V0间隔和V1间隔最初重叠。
        if (Math::GetValue(0) < speed)
        {
            // 更新 last time.
            auto invSpeed = (Math::GetValue(1)) / speed;
            auto t = (cfg0.max - cfg1.min) * invSpeed;
            if (t < intersectInfo.tLast)
            {
                intersectInfo.tLast = t;
            }

            // 测试分离。
            if (intersectInfo.tLast < intersectInfo.tFirst)
            {
                intersectInfo.result = true;
                return intersectInfo;
            }
        }
        else if (speed < Math::GetValue(0))
        {
            // 更新 last time.
            auto invSpeed = (Math::GetValue(1)) / speed;
            auto t = (cfg0.min - cfg1.max) * invSpeed;
            if (t < intersectInfo.tLast)
            {
                intersectInfo.tLast = t;
            }

            // 测试分离。
            if (intersectInfo.tLast < intersectInfo.tFirst)
            {
                intersectInfo.result = true;
                return intersectInfo;
            }
        }
    }

    return intersectInfo;
}

template <typename Real>
Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::IntersectInfo::IntersectInfo() noexcept
    : result{}, side{ SideType::None }, tCfg0{}, tCfg1{}, tFirst{}, tLast{ Math::maxReal }
{
}

template <typename Real>
Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::IntersectInfo::IntersectInfo(bool result, SideType side, const Configuration& tCfg0, const Configuration& tCfg1, Real tFirst, Real tLast) noexcept
    : result{ result }, side{ side }, tCfg0{ tCfg0 }, tCfg1{ tCfg1 }, tFirst{ tFirst }, tLast{ tLast }
{
}

template <typename Real>
typename Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::Intersection Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::GetIntersection(const Configuration& cfg0, const Configuration& cfg1, SideType side, const Vector2Container& moveV0, const Vector2Container& moveV1)
{
    Intersection result{};

    // V1间隔接触右侧的V0间隔。
    if (side == SideType::Right)
    {
        if (cfg0.projectionMap == ProjectionMap::M21 || cfg0.projectionMap == ProjectionMap::M11)
        {
            result.emplace_back(moveV0.at(cfg0.index.at(2)));
        }
        else if (cfg1.projectionMap == ProjectionMap::M12 || cfg1.projectionMap == ProjectionMap::M11)
        {
            result.emplace_back(moveV1.at(cfg1.index.at(0)));
        }
        else  // cfg0.Map == M12 && cfg1.Map == M21 （边缘重叠）
        {
            const auto& origin = moveV0.at(cfg0.index.at(1));
            const auto edge = moveV0.at(cfg0.index.at(2)) - origin;
            const auto invEdgeDotEdge = (Math::GetValue(1)) / Vector2Tools::DotProduct(edge, edge);
            const auto diff1 = moveV1.at(cfg1.index.at(1)) - origin;
            const auto edgeMin = Vector2Tools::DotProduct(edge, diff1) * invEdgeDotEdge;
            const auto diff0 = moveV1.at(cfg1.index.at(0)) - origin;
            const auto edgeMax = Vector2Tools::DotProduct(edge, diff0) * invEdgeDotEdge;
            MATHEMATICS_ASSERTION_1(edgeMin <= edgeMax, "意外状况\n");

            StaticFindIntersector1<Real> staticFindIntersector1{ Math::GetValue(0), Math::GetValue(1), edgeMin, edgeMax };
            const auto quantity = staticFindIntersector1.GetNumIntersections();
            MATHEMATICS_ASSERTION_1(0 < quantity, "意外状况\n");

            for (auto i = 0; i < quantity; ++i)
            {
                result.emplace_back(origin + staticFindIntersector1.GetIntersection(i) * edge);
            }
        }
    }
    else if (side == SideType::Left)  // V1间隔接触左侧的V0间隔。
    {
        if (cfg1.projectionMap == ProjectionMap::M21 || cfg1.projectionMap == ProjectionMap::M11)
        {
            result.emplace_back(moveV1.at(cfg1.index.at(2)));
        }
        else if (cfg0.projectionMap == ProjectionMap::M12 || cfg0.projectionMap == ProjectionMap::M11)
        {
            result.emplace_back(moveV0.at(cfg0.index.at(0)));
        }
        else  // cfg1.Map == M12 && cfg0.Map == M21 （边缘重叠）
        {
            const auto& origin = moveV1.at(cfg1.index.at(1));
            const auto edge = moveV1.at(cfg1.index.at(2)) - origin;
            const auto invEdgeDotEdge = (Math::GetValue(1)) / Vector2Tools::DotProduct(edge, edge);
            const auto diff1 = moveV0.at(cfg0.index.at(1)) - origin;
            const auto edgeMin = Vector2Tools::DotProduct(edge, diff1) * invEdgeDotEdge;
            const auto diff0 = moveV0.at(cfg0.index.at(0)) - origin;
            const auto edgeMax = Vector2Tools::DotProduct(edge, diff0) * invEdgeDotEdge;
            MATHEMATICS_ASSERTION_1(edgeMin <= edgeMax, "意外状况\n");

            StaticFindIntersector1<Real> staticFindIntersector1{ Math::GetValue(0), Math::GetValue(1), edgeMin, edgeMax };
            const auto quantity = staticFindIntersector1.GetNumIntersections();
            MATHEMATICS_ASSERTION_1(0 < quantity, "意外状况\n");

            for (auto i = 0; i < quantity; ++i)
            {
                result.emplace_back(origin + staticFindIntersector1.GetIntersection(i) * edge);
            }
        }
    }
    else  // 三角形最初是相交的。
    {
        const Triangle2 tri0{ moveV0.at(0), moveV0.at(1), moveV0.at(2) };
        const Triangle2 tri1{ moveV1.at(0), moveV1.at(1), moveV1.at(2) };
        StaticFindIntersectorTriangle2Triangle2<Real> staticFindIntersectorTriangle2Triangle2{ tri0, tri1 };

        const auto quantity = staticFindIntersectorTriangle2Triangle2.GetQuantity();
        for (auto i = 0; i < quantity; ++i)
        {
            result.emplace_back(staticFindIntersectorTriangle2Triangle2.GetPoint(i));
        }
    }

    return result;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_DETAIL_H