///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/17 17:07)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_ACHIEVE_H

#include "DynamicFindIntersectorTriangle2Triangle2.h"
#include "StaticFindIntersectorTriangle2Triangle2Detail.h"
#include "Detail/FindIntersectorTriangle2Triangle2ImplDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/StaticFindIntersector1.h"

template <typename Real>
Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::DynamicFindIntersectorTriangle2Triangle2(const Triangle2& triangle0, const Triangle2& triangle1, Real tmax, const Vector2D& velocity0, const Vector2D& velocity1, const Real epsilon)
    : ParentType{ tmax, velocity0, velocity1, epsilon }, m_Impl{ std::make_shared<ImplType>(triangle0, triangle1) }
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Triangle2<Real> Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::GetTriangle0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetTriangle0();
}

template <typename Real>
const Mathematics::Triangle2<Real> Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::GetTriangle1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetTriangle1();
}

template <typename Real>
int Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetQuantity();
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetPoint(index);
}

template <typename Real>
void Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::Find()
{
    const auto& triangle0 = m_Impl->GetTriangle0();
    const auto& triangle1 = m_Impl->GetTriangle1();

    // 好像V0三角形是固定的，而V1三角形是移动的。
    auto velocityDiff = this->GetRhsVelocity() - this->GetLhsVelocity();

    IntersectInfo intersectInfo{};

    const auto vertex0 = triangle0.GetVertex();
    const auto vertex1 = triangle1.GetVertex();

    // 处理V0三角形的边缘。
    for (auto i0 = 1, i1 = 2, i2 = 0; i2 < sm_Size; i0 = i1, i1 = i2++)
    {
        const auto& vertor1 = vertex0.at(i1);
        const auto& vertor2 = vertex0.at(i2);

        // 测试轴 V0[i1] + t * perp(V0[i2] - V0[i1]), perp(x,y) = (y,-x).
        const Vector2D axis{ vertor2.GetY() - vertor1.GetY(), vertor1.GetX() - vertor2.GetX() };
        auto speed = Vector2DTools::DotProduct(axis, velocityDiff);

        const auto cfg0 = ComputeTwo(vertex0, axis, i0, i1, i2);
        const auto cfg1 = ComputeThree(vertex1, axis, vertor1);

        intersectInfo = NoIntersect(cfg0, cfg1, this->GetTMax(), speed);
        if (intersectInfo.m_Result)
        {
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // 处理V1三角形的边缘。
    for (auto i0 = 1, i1 = 2, i2 = 0; i2 < sm_Size; i0 = i1, i1 = i2++)
    {
        const auto& vertor1 = vertex1.at(i1);
        const auto& vertor2 = vertex1.at(i2);

        // 测试轴 V1[i1] + t*perp(V1[i2]-V1[i1]), perp(x,y) = (y,-x).

        const Vector2D axis{ vertor2.GetY() - vertor1.GetY(), vertor1.GetX() - vertor2.GetX() };
        auto speed = Vector2DTools::DotProduct(axis, velocityDiff);

        const auto cfg1 = ComputeTwo(vertex1, axis, i0, i1, i2);
        const auto cfg0 = ComputeThree(vertex0, axis, vertor1);

        intersectInfo = NoIntersect(cfg0, cfg1, this->GetTMax(), speed);
        if (intersectInfo.m_Result)
        {
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // 将三角形移动到第一个接触点。
    const Vector2DContainer moveV0{ vertex0.at(0) + intersectInfo.m_TFirst * this->GetLhsVelocity(),
                                    vertex0.at(1) + intersectInfo.m_TFirst * this->GetLhsVelocity(),
                                    vertex0.at(2) + intersectInfo.m_TFirst * this->GetLhsVelocity() };
    const Vector2DContainer moveV1{ vertex1.at(0) + intersectInfo.m_TFirst * this->GetRhsVelocity(),
                                    vertex1.at(1) + intersectInfo.m_TFirst * this->GetRhsVelocity(),
                                    vertex1.at(2) + intersectInfo.m_TFirst * this->GetRhsVelocity() };

    m_Impl->SetPoint(GetIntersection(intersectInfo.m_TCfg0, intersectInfo.m_TCfg1, intersectInfo.m_Side, moveV0, moveV1));

    this->SetContactTime(intersectInfo.m_TFirst);
    if (0 < m_Impl->GetQuantity())
    {
        this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

template <typename Real>
typename Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::Configuration Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::ComputeTwo(const Intersection& vertex, const Vector2D& axis, int i0, int i1, int i2)
{
    Configuration cfg{};

    cfg.m_Map = ProjectionMap::M12;
    cfg.m_Index = decltype(cfg.m_Index){ i0, i1, i2 };
    cfg.m_Min = Vector2DTools::DotProduct(axis, (vertex.at(i0) - vertex.at(i1)));
    cfg.m_Max = Math::GetValue(0);

    return cfg;
}

template <typename Real>
typename Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::Configuration Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::ComputeThree(const Intersection& vertex, const Vector2D& axis, const Vector2D& point)
{
    Configuration cfg{};

    auto d0 = Vector2DTools::DotProduct(axis, (vertex.at(0) - point));
    auto d1 = Vector2DTools::DotProduct(axis, (vertex.at(1) - point));
    auto d2 = Vector2DTools::DotProduct(axis, (vertex.at(2) - point));

    /// 每当映射值为M12或M21时，请确保m_aiIndex[...]是（0,1,2）的偶数排列。 这需要确保重叠边缘的交点得到正确计算。

    if (d0 <= d1)
    {
        if (d1 <= d2)  // d0 <= d1 <= d2
        {
            if (d0 != d1)
            {
                cfg.m_Map = (d1 != d2 ? ProjectionMap::M11 : ProjectionMap::M12);
            }
            else
            {
                cfg.m_Map = ProjectionMap::M21;
            }

            cfg.m_Index = decltype(cfg.m_Index){ 0, 1, 2 };

            cfg.m_Min = d0;
            cfg.m_Max = d2;
        }
        else if (d0 <= d2)  // d0 <= d2 < d1
        {
            if (d0 != d2)
            {
                cfg.m_Map = ProjectionMap::M11;

                cfg.m_Index = decltype(cfg.m_Index){ 0, 2, 1 };
            }
            else
            {
                cfg.m_Map = ProjectionMap::M21;

                cfg.m_Index = decltype(cfg.m_Index){ 2, 0, 1 };
            }

            cfg.m_Min = d0;
            cfg.m_Max = d1;
        }
        else  // d2 < d0 <= d1
        {
            cfg.m_Map = (d0 != d1 ? ProjectionMap::M12 : ProjectionMap::M11);

            cfg.m_Index = decltype(cfg.m_Index){ 2, 0, 1 };

            cfg.m_Min = d2;
            cfg.m_Max = d1;
        }
    }
    else
    {
        if (d2 <= d1)  // d2 <= d1 < d0
        {
            if (d2 != d1)
            {
                cfg.m_Map = ProjectionMap::M11;

                cfg.m_Index = decltype(cfg.m_Index){ 2, 1, 0 };
            }
            else
            {
                cfg.m_Map = ProjectionMap::M21;

                cfg.m_Index = decltype(cfg.m_Index){ 1, 2, 0 };
            }

            cfg.m_Min = d2;
            cfg.m_Max = d0;
        }
        else if (d2 <= d0)  // d1 < d2 <= d0
        {
            cfg.m_Map = (d2 != d0 ? ProjectionMap::M11 : ProjectionMap::M12);

            cfg.m_Index = decltype(cfg.m_Index){ 1, 2, 0 };

            cfg.m_Min = d1;
            cfg.m_Max = d0;
        }
        else  // d1 < d0 < d2
        {
            cfg.m_Map = ProjectionMap::M11;

            cfg.m_Index = decltype(cfg.m_Index){ 1, 0, 1 };

            cfg.m_Min = d1;
            cfg.m_Max = d2;
        }
    }

    return cfg;
}

template <typename Real>
typename Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::IntersectInfo Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::NoIntersect(const Configuration& cfg0, const Configuration& cfg1, Real tmax, Real speed) noexcept
{
    IntersectInfo intersectInfo{};

    if (cfg1.m_Max < cfg0.m_Min)
    {
        // V1间隔最初位于V0间隔的左侧。
        if (speed <= Math::GetValue(0))
        {
            // 间隔分开。
            intersectInfo.m_Result = true;
            return intersectInfo;
        }

        // 第一次更新。
        auto invSpeed = (Math::GetValue(1)) / speed;
        auto t = (cfg0.m_Min - cfg1.m_Max) * invSpeed;
        if (intersectInfo.m_TFirst < t)
        {
            intersectInfo.m_TFirst = t;
            intersectInfo.m_Side = SideType::Left;
            intersectInfo.m_TCfg0 = cfg0;
            intersectInfo.m_TCfg1 = cfg1;
        }

        // 测试是否超过时间间隔。
        if (tmax < intersectInfo.m_TFirst)
        {
            intersectInfo.m_Result = true;
            return intersectInfo;
        }

        // 更新 last time.
        t = (cfg0.m_Max - cfg1.m_Min) * invSpeed;
        if (t < intersectInfo.m_TLast)
        {
            intersectInfo.m_TLast = t;
        }

        // 测试分离。
        if (intersectInfo.m_TLast < intersectInfo.m_TFirst)
        {
            intersectInfo.m_Result = true;
            return intersectInfo;
        }
    }
    else if (cfg0.m_Max < cfg1.m_Min)
    {
        // V1间隔最初位于V0间隔的右侧。
        if (Math::GetValue(0) <= speed)
        {
            // 间隔分开。
            intersectInfo.m_Result = true;
            return intersectInfo;
        }

        // 更新 first time.
        auto invSpeed = (Math::GetValue(1)) / speed;
        auto t = (cfg0.m_Max - cfg1.m_Min) * invSpeed;
        if (intersectInfo.m_TFirst < t)
        {
            intersectInfo.m_TFirst = t;
            intersectInfo.m_Side = SideType::Right;
            intersectInfo.m_TCfg0 = cfg0;
            intersectInfo.m_TCfg1 = cfg1;
        }

        // 测试是否超过时间间隔。
        if (tmax < intersectInfo.m_TFirst)
        {
            intersectInfo.m_Result = true;
            return intersectInfo;
        }

        // 更新 last time.
        t = (cfg0.m_Min - cfg1.m_Max) * invSpeed;
        if (t < intersectInfo.m_TLast)
        {
            intersectInfo.m_TLast = t;
        }

        // 测试分离。.
        if (intersectInfo.m_TLast < intersectInfo.m_TFirst)
        {
            intersectInfo.m_Result = true;
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
            auto t = (cfg0.m_Max - cfg1.m_Min) * invSpeed;
            if (t < intersectInfo.m_TLast)
            {
                intersectInfo.m_TLast = t;
            }

            // 测试分离。
            if (intersectInfo.m_TLast < intersectInfo.m_TFirst)
            {
                intersectInfo.m_Result = true;
                return intersectInfo;
            }
        }
        else if (speed < Math::GetValue(0))
        {
            // 更新 last time.
            auto invSpeed = (Math::GetValue(1)) / speed;
            auto t = (cfg0.m_Min - cfg1.m_Max) * invSpeed;
            if (t < intersectInfo.m_TLast)
            {
                intersectInfo.m_TLast = t;
            }

            // 测试分离。
            if (intersectInfo.m_TLast < intersectInfo.m_TFirst)
            {
                intersectInfo.m_Result = true;
                return intersectInfo;
            }
        }
    }

    return intersectInfo;
}

template <typename Real>
Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::IntersectInfo::IntersectInfo() noexcept
    : m_Result{}, m_Side{ SideType::None }, m_TCfg0{}, m_TCfg1{}, m_TFirst{}, m_TLast{ Math::sm_MaxReal }
{
}

template <typename Real>
Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::IntersectInfo::IntersectInfo(bool result, SideType side, const Configuration& tCfg0, const Configuration& tCfg1, Real tFirst, Real tLast) noexcept
    : m_Result{ result }, m_Side{ side }, m_TCfg0{ tCfg0 }, m_TCfg1{ tCfg1 }, m_TFirst{ tFirst }, m_TLast{ tLast }
{
}

template <typename Real>
typename Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::Intersection Mathematics::DynamicFindIntersectorTriangle2Triangle2<Real>::GetIntersection(const Configuration& cfg0, const Configuration& cfg1, SideType side, const Vector2DContainer& moveV0, const Vector2DContainer& moveV1)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    Intersection result{};

    // V1间隔接触右侧的V0间隔。
    if (side == SideType::Right)
    {
        if (cfg0.m_Map == ProjectionMap::M21 || cfg0.m_Map == ProjectionMap::M11)
        {
            result.emplace_back(moveV0.at(cfg0.m_Index[2]));
        }
        else if (cfg1.m_Map == ProjectionMap::M12 || cfg1.m_Map == ProjectionMap::M11)
        {
            result.emplace_back(moveV1.at(cfg1.m_Index[0]));
        }
        else  // cfg0.Map == M12 && cfg1.Map == M21 （边缘重叠）
        {
            const auto& origin = moveV0.at(cfg0.m_Index[1]);
            auto edge = moveV0.at(cfg0.m_Index[2]) - origin;
            auto invEdgeDotEdge = (Math::GetValue(1)) / Vector2DTools::DotProduct(edge, edge);
            auto diff1 = moveV1.at(cfg1.m_Index[1]) - origin;
            auto edgeMin = Vector2DTools::DotProduct(edge, diff1) * invEdgeDotEdge;
            auto diff0 = moveV1.at(cfg1.m_Index[0]) - origin;
            auto edgeMax = Vector2DTools::DotProduct(edge, diff0) * invEdgeDotEdge;
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
        if (cfg1.m_Map == ProjectionMap::M21 || cfg1.m_Map == ProjectionMap::M11)
        {
            result.emplace_back(moveV1.at(cfg1.m_Index[2]));
        }
        else if (cfg0.m_Map == ProjectionMap::M12 || cfg0.m_Map == ProjectionMap::M11)
        {
            result.emplace_back(moveV0.at(cfg0.m_Index[0]));
        }
        else  // cfg1.Map == M12 && cfg0.Map == M21 （边缘重叠）
        {
            const auto& origin = moveV1.at(cfg1.m_Index[1]);
            auto edge = moveV1.at(cfg1.m_Index[2]) - origin;
            auto invEdgeDotEdge = (Math::GetValue(1)) / Vector2DTools::DotProduct(edge, edge);
            auto diff1 = moveV0.at(cfg0.m_Index[1]) - origin;
            auto edgeMin = Vector2DTools::DotProduct(edge, diff1) * invEdgeDotEdge;
            auto diff0 = moveV0.at(cfg0.m_Index[0]) - origin;
            auto edgeMax = Vector2DTools::DotProduct(edge, diff0) * invEdgeDotEdge;
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
        Triangle2 tri0{ moveV0[0], moveV0[1], moveV0[2] };
        Triangle2 tri1{ moveV1[0], moveV1[1], moveV1[2] };
        StaticFindIntersectorTriangle2Triangle2<Real> staticFindIntersectorTriangle2Triangle2{ tri0, tri1 };

        const auto quantity = staticFindIntersectorTriangle2Triangle2.GetQuantity();
        for (auto i = 0; i < quantity; ++i)
        {
            result.emplace_back(staticFindIntersectorTriangle2Triangle2.GetPoint(i));
        }
    }

    return result;

#include STSTEM_WARNING_POP
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_ACHIEVE_H