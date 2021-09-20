///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/08 11:01)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_ACHIEVE_H

#include "DynamicFindIntersectorTriangle3Triangle3.h"
#include "StaticFindIntersectorTriangle3Triangle3Detail.h"
#include "Detail/FindIntersectorTriangle3Triangle3ImplDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2DDetail.h"
#include "Mathematics/Distance/Distance3D/DistanceSegment3Triangle3Detail.h"
#include "Mathematics/Intersection/Flags/ContactSide.h"
#include "Mathematics/Intersection/Flags/VertexProjectionMap.h"
#include "Mathematics/Intersection/Intersection2D/StaticFindIntersectorSegment2Triangle2Detail.h"
#include "Mathematics/Intersection/Intersection2D/StaticFindIntersectorTriangle2Triangle2Detail.h"
#include "Mathematics/Objects2D/Segment2Detail.h"
#include "Mathematics/Objects2D/Triangle2Detail.h"
#include "Mathematics/Objects3D/Segment3Detail.h"

template <typename Real>
Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::DynamicFindIntersectorTriangle3Triangle3(const Triangle3& triangle0, const Triangle3& triangle1, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, impl{  triangle0, triangle1  }
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid()  )
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::GetTriangle0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetTriangle0();
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::GetTriangle1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetTriangle1();
}

template <typename Real>
int Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetQuantity();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetPoint(index);
}

template <typename Real>
Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::IntersectInfo::IntersectInfo() noexcept
    : m_Result{}, m_Side{ ContactSide::None }, m_TCfg0{}, m_TCfg1{}, m_TFirst{}, m_TLast{ Math::sm_MaxReal }
{
}

template <typename Real>
Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::IntersectInfo::IntersectInfo(bool result, ContactSide side, const Configuration& tCfg0, const Configuration& tCfg1, Real tFirst, Real tLast) noexcept
    : m_Result{ result }, m_Side{ side }, m_TCfg0{ tCfg0 }, m_TCfg1{ tCfg1 }, m_TFirst{ tFirst }, m_TLast{ tLast }
{
}

template <typename Real>
void Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::Find()
{
    const auto tMax = this->GetTMax();
    const auto lhsVelocity = this->GetLhsVelocity();
    const auto rhsVelocity = this->GetRhsVelocity();
    const auto triangle0 = impl->GetTriangle0();
    const auto triangle1 = impl->GetTriangle1();

    // 相对于三角形0的速度。
    auto relVelocity = rhsVelocity - lhsVelocity;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    // 计算三角形0的边缘和法线方向。

    Vector3DContainer edge0{ triangle0.GetVertex(1) - triangle0.GetVertex(0),
                             triangle0.GetVertex(2) - triangle0.GetVertex(1),
                             triangle0.GetVertex(0) - triangle0.GetVertex(2) };
    const auto normal0 = Vector3DTools::UnitCrossProduct(edge0[0], edge0[1]);
    auto intersectInfo = FindOverlap(normal0, tMax, relVelocity);
    if (!intersectInfo.m_Result)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // 计算三角形1的边缘和法线方向。
    Vector3DContainer edge1{ triangle1.GetVertex(1) - triangle1.GetVertex(0),
                             triangle1.GetVertex(2) - triangle1.GetVertex(1),
                             triangle1.GetVertex(0) - triangle1.GetVertex(2) };
    const auto normal1 = Vector3DTools::UnitCrossProduct(edge1[0], edge1[1]);

    if (Math::FAbs(Vector3DTools::DotProduct(normal0, normal1)) < Math::GetValue(1) - Math::GetZeroTolerance())
    {
        // 三角形不平行。

        // 方向 normal1。

        intersectInfo = FindOverlap(normal1, tMax, relVelocity);
        if (!intersectInfo.m_Result)
        {
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }

        // 方向 E[i0]xF[i1].
        for (auto i1 = 0; i1 < 3; ++i1)
        {
            for (auto i0 = 0; i0 < 3; ++i0)
            {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26482)
                const auto dir = Vector3DTools::UnitCrossProduct(edge0[i0], edge1[i1]);
#include STSTEM_WARNING_POP

                intersectInfo = FindOverlap(dir, tMax, relVelocity);
                if (!intersectInfo.m_Result)
                {
                    this->SetIntersectionType(IntersectionType::Empty);
                    return;
                }
            }
        }
    }
    else  // 三角形是平行的（实际上是共面的）。
    {
        // 方向 NxE[i0].
        for (auto i = 0; i < 3; ++i)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26482)
            const auto dir = Vector3DTools::UnitCrossProduct(normal0, edge0[i]);
#include STSTEM_WARNING_POP

            intersectInfo = FindOverlap(dir, tMax, relVelocity);
            if (!intersectInfo.m_Result)
            {
                this->SetIntersectionType(IntersectionType::Empty);
                return;
            }
        }

        // 方向 NxF[i1].
        for (auto i = 0; i < 3; ++i)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26482)
            const auto dir = Vector3DTools::UnitCrossProduct(normal1, edge1[i]);
#include STSTEM_WARNING_POP

            intersectInfo = FindOverlap(dir, tMax, relVelocity);
            if (!intersectInfo.m_Result)
            {
                this->SetIntersectionType(IntersectionType::Empty);
                return;
            }
        }
    }

#include STSTEM_WARNING_POP

    if (intersectInfo.m_TFirst <= Math::GetValue(0))
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    this->SetContactTime(intersectInfo.m_TFirst);

    // 在找到触点组之前，第一次调整U和V
    Triangle3 moveTriangle0{ triangle0.GetVertex(0) + intersectInfo.m_TFirst * lhsVelocity,
                             triangle0.GetVertex(1) + intersectInfo.m_TFirst * lhsVelocity,
                             triangle0.GetVertex(2) + intersectInfo.m_TFirst * lhsVelocity };
    Triangle3 moveTriangle1{ triangle1.GetVertex(0) + intersectInfo.m_TFirst * rhsVelocity,
                             triangle1.GetVertex(1) + intersectInfo.m_TFirst * rhsVelocity,
                             triangle1.GetVertex(2) + intersectInfo.m_TFirst * rhsVelocity };

    FindContactSet(moveTriangle0, moveTriangle1, intersectInfo.m_Side, intersectInfo.m_TCfg0, intersectInfo.m_TCfg1);
    this->SetIntersectionType(IntersectionType::Other);
}

template <typename Real>
typename Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::IntersectInfo Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::FindOverlap(const Vector3D& axis, Real tmax, const Vector3D& velocity)
{
    auto triangle0 = impl->GetTriangle0();
    auto triangle1 = impl->GetTriangle1();

    const auto cfg0 = ProjectOntoAxis(triangle0, axis);
    const auto cfg1 = ProjectOntoAxis(triangle1, axis);
    auto speed = Vector3DTools::DotProduct(velocity, axis);
    return FindOverlap(tmax, speed, cfg0, cfg1);
}

template <typename Real>
typename Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::Configuration Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::ProjectOntoAxis(const Triangle3& triangle, const Vector3D& axis)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    Configuration cfg{};

    // 查找顶点到潜在分离轴上的投影。
    auto d0 = Vector3DTools::DotProduct(axis, triangle.GetVertex(0));
    auto d1 = Vector3DTools::DotProduct(axis, triangle.GetVertex(1));
    auto d2 = Vector3DTools::DotProduct(axis, triangle.GetVertex(2));

    // 显式排序的顶点以构造Configuration对象。
    if (d0 <= d1)
    {
        if (d1 <= d2)  // D0 <= D1 <= D2
        {
            if (Math::Approximate(d0, d1))
            {
                if (Math::Approximate(d1, d2))
                {
                    cfg.m_Map = VertexProjectionMap::M111;
                }
                else
                {
                    cfg.m_Map = VertexProjectionMap::M12;
                }
            }
            else  // ( D0 == D1 )
            {
                if (Math::Approximate(d1, d2))
                {
                    cfg.m_Map = VertexProjectionMap::M21;
                }
                else
                {
                    cfg.m_Map = VertexProjectionMap::M3;
                }
            }
            cfg.m_Index[0] = 0;
            cfg.m_Index[1] = 1;
            cfg.m_Index[2] = 2;
            cfg.m_Min = d0;
            cfg.m_Max = d2;
        }
        else if (d0 <= d2)  // D0 <= D2 < D1
        {
            if (Math::Approximate(d1, d2))
            {
                cfg.m_Map = VertexProjectionMap::M111;
                cfg.m_Index[0] = 0;
                cfg.m_Index[1] = 2;
                cfg.m_Index[2] = 1;
            }
            else
            {
                cfg.m_Map = VertexProjectionMap::M21;
                cfg.m_Index[0] = 2;
                cfg.m_Index[1] = 0;
                cfg.m_Index[2] = 1;
            }
            cfg.m_Min = d0;
            cfg.m_Max = d1;
        }
        else  // D2 < D0 <= D1
        {
            if (Math::Approximate(d0, d1))
            {
                cfg.m_Map = VertexProjectionMap::M111;
            }
            else
            {
                cfg.m_Map = VertexProjectionMap::M12;
            }

            cfg.m_Index[0] = 2;
            cfg.m_Index[1] = 0;
            cfg.m_Index[2] = 1;
            cfg.m_Min = d2;
            cfg.m_Max = d1;
        }
    }
    else if (d2 <= d1)  // D2 <= D1 < D0
    {
        if (Math::Approximate(d2, d1))
        {
            cfg.m_Map = VertexProjectionMap::M111;
            cfg.m_Index[0] = 2;
            cfg.m_Index[1] = 1;
            cfg.m_Index[2] = 0;
        }
        else
        {
            cfg.m_Map = VertexProjectionMap::M21;
            cfg.m_Index[0] = 1;
            cfg.m_Index[1] = 2;
            cfg.m_Index[2] = 0;
        }
        cfg.m_Min = d2;
        cfg.m_Max = d0;
    }
    else if (d2 <= d0)  // D1 < D2 <= D0
    {
        if (Math::Approximate(d2, d0))
        {
            cfg.m_Map = VertexProjectionMap::M111;
        }
        else
        {
            cfg.m_Map = VertexProjectionMap::M12;
        }

        cfg.m_Index[0] = 1;
        cfg.m_Index[1] = 2;
        cfg.m_Index[2] = 0;
        cfg.m_Min = d1;
        cfg.m_Max = d0;
    }
    else  // D1 < D0 < D2
    {
        cfg.m_Map = VertexProjectionMap::M111;
        cfg.m_Index[0] = 1;
        cfg.m_Index[1] = 0;
        cfg.m_Index[2] = 2;
        cfg.m_Min = d1;
        cfg.m_Max = d2;
    }

    return cfg;

#include STSTEM_WARNING_POP
}

template <typename Real>
typename Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::IntersectInfo Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::FindOverlap(Real tmax, Real speed, const Configuration& uConfiguration, const Configuration& vConfiguration) noexcept
{
    IntersectInfo intersectInfo{};

    // 等速分离轴测试。 uConfiguration和vConfiguration是新的潜在配置，而intersectInfo是最好的配置。

    auto t = Math::GetValue(0);

    if (vConfiguration.m_Max < uConfiguration.m_Min)  // V在U的左侧
    {
        if (speed <= Math::GetValue(0))  // V从U移开
        {
            return intersectInfo;
        }

        // 查找该轴上的首次接触。
        t = (uConfiguration.m_Min - vConfiguration.m_Max) / speed;

        // 如果这是新的最大首次接触时间，请进行设置和配置。
        if (intersectInfo.m_TFirst < t)
        {
            intersectInfo.m_TFirst = t;
            intersectInfo.m_Side = ContactSide::Left;
            intersectInfo.m_TCfg0 = uConfiguration;
            intersectInfo.m_TCfg1 = vConfiguration;
        }

        // 快速退出：所需时间间隔后的交点。
        if (tmax < intersectInfo.m_TFirst)
        {
            return intersectInfo;
        }

        // 查找该轴上的最后一次接触时间。
        t = (uConfiguration.m_Max - vConfiguration.m_Min) / speed;
        if (t < intersectInfo.m_TLast)
        {
            intersectInfo.m_TLast = t;
        }

        // 快速退出：所需时间间隔之前的交点。
        if (intersectInfo.m_TLast < intersectInfo.m_TFirst)
        {
            return intersectInfo;
        }
    }
    else if (uConfiguration.m_Max < vConfiguration.m_Min)  // V在U的右边
    {
        if (Math::GetValue(0) <= speed)  // V从U移开
        {
            return intersectInfo;
        }

        // 查找该轴上的首次接触。
        t = (uConfiguration.m_Max - vConfiguration.m_Min) / speed;

        // 如果这是新的最大首次接触时间，请进行设置和配置。
        if (intersectInfo.m_TFirst < t)
        {
            intersectInfo.m_TFirst = t;
            intersectInfo.m_Side = ContactSide::Right;
            intersectInfo.m_TCfg0 = uConfiguration;
            intersectInfo.m_TCfg1 = vConfiguration;
        }

        // 快速退出：所需时间间隔后的交点。
        if (tmax < intersectInfo.m_TFirst)
        {
            return intersectInfo;
        }

        // 查找该轴上的最后一次接触时间。
        t = (uConfiguration.m_Min - vConfiguration.m_Max) / speed;
        if (t < intersectInfo.m_TLast)
        {
            intersectInfo.m_TLast = t;
        }

        // 快速退出：所需时间间隔之前的交点。
        if (intersectInfo.m_TLast < intersectInfo.m_TFirst)
        {
            return intersectInfo;
        }
    }
    else  // 重叠间隔上的V和U
    {
        if (Math::GetValue(0) < speed)
        {
            // 查找该轴上的最后一次接触时间。
            t = (uConfiguration.m_Max - vConfiguration.m_Min) / speed;
            if (t < intersectInfo.m_TLast)
            {
                intersectInfo.m_TLast = t;
            }

            // 快速退出：所需时间间隔之前的交点。
            if (intersectInfo.m_TLast < intersectInfo.m_TFirst)
            {
                return intersectInfo;
            }
        }
        else if (speed < Math::GetValue(0))
        {
            // 查找该轴上的最后一次接触时间。
            t = (uConfiguration.m_Min - vConfiguration.m_Max) / speed;
            if (t < intersectInfo.m_TLast)
            {
                intersectInfo.m_TLast = t;
            }

            // 快速退出：所需时间间隔之前的交点。
            if (intersectInfo.m_TLast < intersectInfo.m_TFirst)
            {
                return intersectInfo;
            }
        }
    }
    intersectInfo.m_Result = true;
    return intersectInfo;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::FindContactSet(const Triangle3& triangle0, const Triangle3& triangle1, const ContactSide& side, const Configuration& cfg0, const Configuration& cfg1)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    if (side == ContactSide::Right)  // ri0在tri1的右边
    {
        if (cfg0.m_Map == VertexProjectionMap::M21 || cfg0.m_Map == VertexProjectionMap::M111)
        {
            // tri0单点触摸tri1
            this->SetIntersectionType(IntersectionType::Point);

            impl->AddPoint(triangle0.GetVertex(cfg0.m_Index[2]));
        }
        else if (cfg1.m_Map == VertexProjectionMap::M12 || cfg1.m_Map == VertexProjectionMap::M111)
        {
            // tri1单点触摸tri0
            this->SetIntersectionType(IntersectionType::Point);

            impl->AddPoint(triangle1.GetVertex(cfg1.m_Index[0]));
        }
        else if (cfg0.m_Map == VertexProjectionMap::M12)
        {
            if (cfg1.m_Map == VertexProjectionMap::M21)
            {
                // edge0-edge1 相交
                GetEdgeEdgeIntersection(triangle0.GetVertex(cfg0.m_Index[1]), triangle0.GetVertex(cfg0.m_Index[2]),
                                        triangle1.GetVertex(cfg1.m_Index[0]), triangle1.GetVertex(cfg1.m_Index[1]));
            }
            else  // cfg1.m_Map == m3
            {
                // u边-v面 相交
                GetEdgeFaceIntersection(triangle0.GetVertex(cfg0.m_Index[1]), triangle0.GetVertex(cfg0.m_Index[2]), triangle1);
            }
        }
        else  // cfg0.m_Map == M3
        {
            if (cfg1.m_Map == VertexProjectionMap::M21)
            {
                // 面0-边1 相交
                GetEdgeFaceIntersection(triangle1.GetVertex(cfg1.m_Index[0]), triangle1.GetVertex(cfg1.m_Index[1]), triangle0);
            }
            else  // cfg1.m_Map == M3
            {
                // 面0-面1 相交
                const Plane3 plane0{ triangle0.GetVertex(0), triangle0.GetVertex(1), triangle0.GetVertex(2) };
                GetCoplanarIntersection(plane0, triangle0, triangle1);
            }
        }
    }
    else if (side == ContactSide::Left)  // tri1在tri0的左侧
    {
        if (cfg1.m_Map == VertexProjectionMap::M21 || cfg1.m_Map == VertexProjectionMap::M111)
        {
            // tri1单点触摸tri0
            this->SetIntersectionType(IntersectionType::Point);

            impl->AddPoint(triangle1.GetVertex(cfg1.m_Index[2]));
        }
        else if (cfg0.m_Map == VertexProjectionMap::M12 || cfg0.m_Map == VertexProjectionMap::M111)
        {
            // tri0单点触摸tri1
            this->SetIntersectionType(IntersectionType::Point);

            impl->AddPoint(triangle0.GetVertex(cfg0.m_Index[0]));
        }
        else if (cfg1.m_Map == VertexProjectionMap::M12)
        {
            if (cfg0.m_Map == VertexProjectionMap::M21)
            {
                // 边0-边1 相交
                GetEdgeEdgeIntersection(triangle0.GetVertex(cfg0.m_Index[0]), triangle0.GetVertex(cfg0.m_Index[1]), triangle1.GetVertex(cfg1.m_Index[1]), triangle1.GetVertex(cfg1.m_Index[2]));
            }
            else  // cfg0.m_Map == M3
            {
                // 边1-面0 相交
                GetEdgeFaceIntersection(triangle1.GetVertex(cfg1.m_Index[1]), triangle1.GetVertex(cfg1.m_Index[2]), triangle0);
            }
        }
        else  // cfg1.m_Map == M3
        {
            if (cfg0.m_Map == VertexProjectionMap::M21)
            {
                // 边e0-面1 相交
                GetEdgeFaceIntersection(triangle0.GetVertex(cfg0.m_Index[0]), triangle0.GetVertex(cfg0.m_Index[1]), triangle1);
            }
            else  // cfg0.m_Map == M
            {
                // 面0-面1 相交
                const Plane3 plane0{ triangle0.GetVertex(0), triangle0.GetVertex(1), triangle0.GetVertex(2) };
                GetCoplanarIntersection(plane0, triangle0, triangle1);
            }
        }
    }
    else  // side == CS_NONE
    {
        // 三角形已经相交了。
        StaticFindIntersectorTriangle3Triangle3<Real> calc{ triangle0, triangle1 };
        const auto result = calc.IsIntersection();
        MATHEMATICS_ASSERTION_0(result, "交叉点必须存在\n");

        const auto quantity = calc.GetQuantity();
        this->SetIntersectionType(calc.GetIntersectionType());
        for (auto i = 0; i < quantity; ++i)
        {
            impl->AddPoint(calc.GetPoint(i));
        }
    }

#include STSTEM_WARNING_POP
}

template <typename Real>
void Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::GetCoplanarIntersection(const Plane3& plane, const Triangle3& triangle0, const Triangle3& triangle1)
{
    // 在与平面法线最对齐的坐标平面上投影三角形。
    auto maxNormal = 0;
    auto x = Math::FAbs(plane.GetNormal().GetX());
    auto y = Math::FAbs(plane.GetNormal().GetY());
    if (x < y)
    {
        maxNormal = 1;
        x = y;
    }
    y = Math::FAbs(plane.GetNormal().GetZ());
    if (x < y)
    {
        maxNormal = 2;
    }

    using Triangle2D = std::array<Vector2D<Real>, 3>;

    Triangle2D projectTriangle0Vector{};
    Triangle2D projectTriangle1Vector{};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26482)

    if (maxNormal == 0)
    {
        // 投影到yz平面上。
        for (auto i = 0; i < 3; ++i)
        {
            projectTriangle0Vector[i].SetCoordinate(triangle0.GetVertex(i).GetY(), triangle0.GetVertex(i).GetZ());
            projectTriangle1Vector[i].SetCoordinate(triangle1.GetVertex(i).GetY(), triangle1.GetVertex(i).GetZ());
        }
    }
    else if (maxNormal == 1)
    {
        // 投影到xz平面上。
        for (auto i = 0; i < 3; ++i)
        {
            projectTriangle0Vector[i].SetCoordinate(triangle0.GetVertex(i).GetX(), triangle0.GetVertex(i).GetZ());
            projectTriangle1Vector[i].SetCoordinate(triangle1.GetVertex(i).GetX(), triangle1.GetVertex(i).GetZ());
        }
    }
    else
    {
        // 投影到xy平面上。
        for (auto i = 0; i < 3; ++i)
        {
            projectTriangle0Vector[i].SetCoordinate(triangle0.GetVertex(i).GetX(), triangle0.GetVertex(i).GetY());
            projectTriangle1Vector[i].SetCoordinate(triangle1.GetVertex(i).GetX(), triangle1.GetVertex(i).GetY());
        }
    }
#include STSTEM_WARNING_POP

    Triangle2<Real> projectTriangle0{ projectTriangle0Vector[0], projectTriangle0Vector[1], projectTriangle0Vector[2] };
    Triangle2<Real> projectTriangle1{ projectTriangle1Vector[0], projectTriangle1Vector[1], projectTriangle1Vector[2] };

    // 2D三角形相交例程需要逆时针排序。

    auto edge0 = projectTriangle0.GetVertex(1) - projectTriangle0.GetVertex(0);
    auto edge1 = projectTriangle0.GetVertex(2) - projectTriangle0.GetVertex(0);
    if (Vector2DTools<Real>::DotPerp(edge0, edge1) < Math::GetValue(0))
    {
        // 三角形是顺时针方向，请重新排序。
        projectTriangle0 = Triangle2<Real>{ projectTriangle0Vector[0], projectTriangle0Vector[2], projectTriangle0Vector[1] };
    }

    edge0 = projectTriangle1.GetVertex(1) - projectTriangle1.GetVertex(0);
    edge1 = projectTriangle1.GetVertex(2) - projectTriangle1.GetVertex(0);
    if (Vector2DTools<Real>::DotPerp(edge0, edge1) < Math::GetValue(0))
    {
        // 三角形是顺时针方向，请重新排序。
        projectTriangle1 = Triangle2<Real>{ projectTriangle1Vector[0], projectTriangle1Vector[2], projectTriangle1Vector[1] };
    }

    StaticFindIntersectorTriangle2Triangle2<Real> intr{ projectTriangle0, projectTriangle1 };
    if (!intr.IsIntersection())
    {
        return;
    }

    // 将2D交点映射回3D三角形空间。
    const auto quantity = intr.GetQuantity();
    if (maxNormal == 0)
    {
        auto invNormalX = (Math::GetValue(1)) / plane.GetNormal().GetX();
        for (auto i = 0; i < quantity; i++)
        {
            Vector3D point{ Math::GetValue(0), intr.GetPoint(i).GetX(), intr.GetPoint(i).GetY() };
            point.SetX(invNormalX * (plane.GetConstant() - plane.GetNormal().GetY() * point.GetY() - plane.GetNormal().GetZ() * point.GetZ()));
            impl->AddPoint(point);
        }
    }
    else if (maxNormal == 1)
    {
        auto invNormalY = (Math::GetValue(1)) / plane.GetNormal().GetY();
        for (auto i = 0; i < quantity; i++)
        {
            Vector3D point{ intr.GetPoint(i).GetX(), Math::GetValue(0), intr.GetPoint(i).GetY() };
            point.SetY(invNormalY * (plane.GetConstant() - plane.GetNormal().GetX() * point.GetX() - plane.GetNormal().GetZ() * point.GetZ()));
            impl->AddPoint(point);
        }
    }
    else
    {
        auto invNormalZ = (Math::GetValue(1)) / plane.GetNormal().GetZ();
        for (auto i = 0; i < quantity; i++)
        {
            Vector3D point{ intr.GetPoint(i).GetX(), intr.GetPoint(i).GetY(), Math::GetValue(0) };
            point.SetZ(invNormalZ * (plane.GetConstant() - plane.GetNormal().GetX() * point.GetX() - plane.GetNormal().GetY() * point.GetY()));
            impl->AddPoint(point);
        }
    }

    this->SetIntersectionType(IntersectionType::Plane);
}

template <typename Real>
void Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::GetEdgeEdgeIntersection(const Vector3D& u0, const Vector3D& u1, const Vector3D& v0, const Vector3D& v1)
{
    // 计算两个边缘平面的法线。
    auto edge0 = u1 - u0;
    auto edge1 = v1 - v0;
    const auto normal = Vector3DTools::CrossProduct(edge0, edge1);

    /// 求解U0 + s * (U1 - U0) = V0 + t * (V1 - V0)。
    /// 我们知道边相交，所以[0,1]中的s和[0,1]中的t。 因此，只需解决s。
    /// 注意，s * E0 = D + t * E1，其中D = V0 - U0。
    /// 因此s * N = s * E0xE1 = DxE1且s = N * DxE1 / N * N。
    auto delta = v0 - u0;
    auto s = Vector3DTools::DotProduct(normal, (Vector3DTools::CrossProduct(delta, edge1) / Vector3DTools::VectorMagnitudeSquared(normal)));
    if (s < Math::GetValue(0))
    {
        MATHEMATICS_ASSERTION_0(-Math::GetZeroTolerance() <= s, "意外的s值。\n");
        s = Math::GetValue(0);
    }
    else if (Math::GetValue(1) < s)
    {
        MATHEMATICS_ASSERTION_0(s <= Math::GetValue(1) + Math::GetZeroTolerance(), "意外的s值。\n");
        s = Math::GetValue(1);
    }

    this->SetIntersectionType(IntersectionType::Point);

    impl->AddPoint(u0 + s * edge0);

    // 如果边缘是平行的怎么办？
}

template <typename Real>
void Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::GetEdgeFaceIntersection(const Vector3D& u0, const Vector3D& u1, const Triangle3& triangle)
{
    // 计算三角形的平面。
    const auto point = triangle.GetVertex(0);
    auto edge0 = triangle.GetVertex(1) - point;
    auto edge1 = triangle.GetVertex(2) - point;
    const auto normal = Vector3DTools::UnitCrossProduct(edge0, edge1);

    const auto vector3DOrthonormalBasis = Vector3DTools::GenerateComplementBasis(normal);
    const auto dir0 = vector3DOrthonormalBasis.GetUVector();
    const auto dir1 = vector3DOrthonormalBasis.GetVVector();

    // 将边缘端点投影到平面上。

    auto diff = u0 - point;
    const Vector2D<Real> projectU0{ Vector3DTools::DotProduct(dir0, diff), Vector3DTools::DotProduct(dir1, diff) };

    diff = u1 - point;
    const Vector2D<Real> projectU1{ Vector3DTools::DotProduct(dir0, diff), Vector3DTools::DotProduct(dir1, diff) };

    const Segment2<Real> projectSegment{ projectU0, projectU1 };

    // 计算三角形的平面坐标。
    using Triangle2D = std::array<Vector2D<Real>, 3>;
    Triangle2D projectTriangleVector{ Vector2D<Real>::GetZero(),
                                      Vector2D<Real>(Vector2DTools<Real>::DotProduct(dir0, edge0), Vector2DTools<Real>::DotProduct(dir1, edge0)),
                                      Vector2D<Real>(Vector2DTools<Real>::DotProduct(dir0, edge1), Vector2DTools<Real>::DotProduct(dir1, edge1)) };

    Triangle2<Real> projectTriangle{ projectTriangleVector[0], projectTriangleVector[1], projectTriangleVector[2] };

    // 计算交集。
    StaticFindIntersectorSegment2Triangle2<Real> calc{ projectSegment, projectTriangle };
    if (calc.IsIntersection())
    {
        const auto quantity = calc.GetQuantity();
        for (auto i = 0; i < quantity; ++i)
        {
            auto proj = calc.GetPoint(i);
            impl->AddPoint(point + proj[0] * dir0 + proj[1] * dir1);
        }
    }
    else
    {
        /// 必须有一个交叉点。 最有可能的数字舍入误差导致找不到它。 使用较慢的3D距离计算器以提高鲁棒性。
        const Segment3<Real> seg{ u0, u1 };
        DistanceSegment3Triangle3<Real> dcalc{ seg, triangle };

        // 我们不需要距离，但是我们需要定位最接近点的副作用。

        auto parameter = dcalc.GetSquared().GetLhsParameter();

        impl->AddPoint(seg.GetCenterPoint() + parameter * seg.GetDirection());
    }

    this->SetIntersectionType((impl->GetQuantity() == 2 ? IntersectionType::Segment : IntersectionType::Point));
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_ACHIEVE_H