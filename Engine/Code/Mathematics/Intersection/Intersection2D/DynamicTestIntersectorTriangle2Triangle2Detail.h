///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 19:25)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_DETAIL_H

#include "DynamicTestIntersectorTriangle2Triangle2.h"
#include "StaticFindIntersectorTriangle2Triangle2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicTestIntersectorTriangle2Triangle2<Real>::DynamicTestIntersectorTriangle2Triangle2(const Triangle2& triangle0, const Triangle2& triangle1, Real tmax, const Vector2& velocity0, const Vector2& velocity1, const Real epsilon)
    : ParentType{ tmax, velocity0, velocity1, epsilon }, triangle0{ triangle0 }, triangle1{ triangle1 }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DynamicTestIntersectorTriangle2Triangle2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Triangle2<Real> Mathematics::DynamicTestIntersectorTriangle2Triangle2<Real>::GetTriangle0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle0;
}

template <typename Real>
Mathematics::Triangle2<Real> Mathematics::DynamicTestIntersectorTriangle2Triangle2<Real>::GetTriangle1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle1;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorTriangle2Triangle2<Real>::Test()
{
    // ����V0�������ǹ̶��ģ���V1���������ƶ��ġ�
    const auto velocityDiff = this->GetRhsVelocity() - this->GetLhsVelocity();

    IntersectInfo intersectInfo{};

    const auto vertex0 = triangle0.GetVertex();
    const auto vertex1 = triangle1.GetVertex();

    // ����V0�����εı�Ե��
    for (auto i0 = 1, i1 = 2, i2 = 0; i2 < size; i0 = i1, i1 = i2++)
    {
        const auto& vertor1 = vertex0.at(i1);
        const auto& vertor2 = vertex0.at(i2);

        // ������ V0[i1] + t*perp(V0[i2]-V0[i1]), perp(x,y) = (y,-x).
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

    // ����V1�����εı�Ե��
    for (auto i0 = 1, i1 = 2, i2 = 0; i2 < 3; i0 = i1, i1 = i2++)
    {
        const auto& vertor1 = vertex1.at(i1);
        const auto& vertor2 = vertex1.at(i2);

        // ������ V1[i1] + t*perp(V1[i2]-V1[i1]), perp(x,y) = (y,-x).

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

    this->SetContactTime(intersectInfo.tFirst);
    this->SetIntersectionType(IntersectionType::Point);
}

template <typename Real>
typename Mathematics::DynamicTestIntersectorTriangle2Triangle2<Real>::Configuration Mathematics::DynamicTestIntersectorTriangle2Triangle2<Real>::ComputeTwo(const Intersection& vertex, const Vector2& axis, int i0, int i1, int i2)
{
    Configuration cfg{};

    cfg.projectionMap = ProjectionMap::M12;
    cfg.index = decltype(cfg.index){ i0, i1, i2 };
    cfg.min = Vector2Tools::DotProduct(axis, (vertex.at(i0) - vertex.at(i1)));
    cfg.max = Math::GetValue(0);

    return cfg;
}

template <typename Real>
typename Mathematics::DynamicTestIntersectorTriangle2Triangle2<Real>::Configuration Mathematics::DynamicTestIntersectorTriangle2Triangle2<Real>::ComputeThree(const Intersection& vertex, const Vector2& axis, const Vector2& point)
{
    Configuration cfg{};

    const auto d0 = Vector2Tools::DotProduct(axis, (vertex.at(0) - point));
    const auto d1 = Vector2Tools::DotProduct(axis, (vertex.at(1) - point));
    const auto d2 = Vector2Tools::DotProduct(axis, (vertex.at(2) - point));

    /// ÿ��ӳ��ֵΪM12��M21ʱ����ȷ��m_aiIndex[...]�ǣ�0,1,2����ż�����С� ����Ҫȷ���ص���Ե�Ľ���õ���ȷ���㡣

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
typename Mathematics::DynamicTestIntersectorTriangle2Triangle2<Real>::IntersectInfo Mathematics::DynamicTestIntersectorTriangle2Triangle2<Real>::NoIntersect(const Configuration& cfg0, const Configuration& cfg1, Real tmax, Real speed) noexcept
{
    IntersectInfo intersectInfo{};

    if (cfg1.max < cfg0.min)
    {
        // V1������λ��V0�������ࡣ
        if (speed <= Math::GetValue(0))
        {
            // ����ֿ���
            intersectInfo.result = true;
            return intersectInfo;
        }

        // ��һ�θ��¡�
        auto invSpeed = (Math::GetValue(1)) / speed;
        auto t = (cfg0.min - cfg1.max) * invSpeed;
        if (intersectInfo.tFirst < t)
        {
            intersectInfo.tFirst = t;
            intersectInfo.side = SideType::Left;
            intersectInfo.tCfg0 = cfg0;
            intersectInfo.tCfg1 = cfg1;
        }

        // �����Ƿ񳬹�ʱ������
        if (tmax < intersectInfo.tFirst)
        {
            intersectInfo.result = true;
            return intersectInfo;
        }

        // ���� last time.
        t = (cfg0.max - cfg1.min) * invSpeed;
        if (t < intersectInfo.tLast)
        {
            intersectInfo.tLast = t;
        }

        // ���Է��롣
        if (intersectInfo.tLast < intersectInfo.tFirst)
        {
            intersectInfo.result = true;
            return intersectInfo;
        }
    }
    else if (cfg0.max < cfg1.min)
    {
        // V1������λ��V0������Ҳࡣ
        if (Math::GetValue(0) <= speed)
        {
            // ����ֿ���
            intersectInfo.result = true;
            return intersectInfo;
        }

        // ���� first time.
        auto invSpeed = (Math::GetValue(1)) / speed;
        auto t = (cfg0.max - cfg1.min) * invSpeed;
        if (intersectInfo.tFirst < t)
        {
            intersectInfo.tFirst = t;
            intersectInfo.side = SideType::Right;
            intersectInfo.tCfg0 = cfg0;
            intersectInfo.tCfg1 = cfg1;
        }

        // �����Ƿ񳬹�ʱ������
        if (tmax < intersectInfo.tFirst)
        {
            intersectInfo.result = true;
            return intersectInfo;
        }

        // ���� last time.
        t = (cfg0.min - cfg1.max) * invSpeed;
        if (t < intersectInfo.tLast)
        {
            intersectInfo.tLast = t;
        }

        // ���Է��롣.
        if (intersectInfo.tLast < intersectInfo.tFirst)
        {
            intersectInfo.result = true;
            return intersectInfo;
        }
    }
    else
    {
        // V0�����V1�������ص���
        if (Math::GetValue(0) < speed)
        {
            // ���� last time.
            auto invSpeed = (Math::GetValue(1)) / speed;
            auto t = (cfg0.max - cfg1.min) * invSpeed;
            if (t < intersectInfo.tLast)
            {
                intersectInfo.tLast = t;
            }

            // ���Է��롣
            if (intersectInfo.tLast < intersectInfo.tFirst)
            {
                intersectInfo.result = true;
                return intersectInfo;
            }
        }
        else if (speed < Math::GetValue(0))
        {
            // ���� last time.
            auto invSpeed = (Math::GetValue(1)) / speed;
            auto t = (cfg0.min - cfg1.max) * invSpeed;
            if (t < intersectInfo.tLast)
            {
                intersectInfo.tLast = t;
            }

            // ���Է��롣
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
Mathematics::DynamicTestIntersectorTriangle2Triangle2<Real>::IntersectInfo::IntersectInfo() noexcept
    : result{}, side{ SideType::None }, tCfg0{}, tCfg1{}, tFirst{}, tLast{ Math::maxReal }
{
}

template <typename Real>
Mathematics::DynamicTestIntersectorTriangle2Triangle2<Real>::IntersectInfo::IntersectInfo(bool result, SideType side, const Configuration& tCfg0, const Configuration& tCfg1, Real tFirst, Real tLast) noexcept
    : result{ result }, side{ side }, tCfg0{ tCfg0 }, tCfg1{ tCfg1 }, tFirst{ tFirst }, tLast{ tLast }
{
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_DETAIL_H