///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.3 (2022/02/28 19:08)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_DETAIL_H

#include "DynamicFindIntersectorTriangle3Triangle3.h"
#include "StaticFindIntersectorTriangle3Triangle3Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Distance/Distance3D/DistanceSegment3Triangle3Detail.h"
#include "Mathematics/Intersection/Flags/ContactSide.h"
#include "Mathematics/Intersection/Flags/VertexProjectionMap.h"
#include "Mathematics/Intersection/Intersection2D/StaticFindIntersectorSegment2Triangle2Detail.h"
#include "Mathematics/Intersection/Intersection2D/StaticFindIntersectorTriangle2Triangle2Detail.h"
#include "Mathematics/Objects2D/Segment2Detail.h"
#include "Mathematics/Objects2D/Triangle2Detail.h"
#include "Mathematics/Objects3D/Segment3Detail.h"

template <typename Real>
Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::DynamicFindIntersectorTriangle3Triangle3(const Triangle3& triangle0, const Triangle3& triangle1, Real tmax, const Vector3& lhsVelocity, const Vector3& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, triangle0{ triangle0 }, triangle1{ triangle1 }, point{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Triangle3<Real> Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::GetTriangle0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle0;
}

template <typename Real>
Mathematics::Triangle3<Real> Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::GetTriangle1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle1;
}

template <typename Real>
int Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(point.size());
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point.at(index);
}

template <typename Real>
Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::IntersectInfo::IntersectInfo() noexcept
    : result{}, side{ ContactSide::None }, tCfg0{}, tCfg1{}, tFirst{}, tLast{ Math::maxReal }
{
}

template <typename Real>
Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::IntersectInfo::IntersectInfo(bool result, ContactSide side, const Configuration& tCfg0, const Configuration& tCfg1, Real tFirst, Real tLast) noexcept
    : result{ result }, side{ side }, tCfg0{ tCfg0 }, tCfg1{ tCfg1 }, tFirst{ tFirst }, tLast{ tLast }
{
}

template <typename Real>
void Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::Find()
{
    const auto tMax = this->GetTMax();
    const auto lhsVelocity = this->GetLhsVelocity();
    const auto rhsVelocity = this->GetRhsVelocity();

    // �����������0���ٶȡ�
    auto relVelocity = rhsVelocity - lhsVelocity;

    // ����������0�ı�Ե�ͷ��߷���

    Vector3Container edge0{ triangle0.GetVertex(1) - triangle0.GetVertex(0),
                            triangle0.GetVertex(2) - triangle0.GetVertex(1),
                            triangle0.GetVertex(0) - triangle0.GetVertex(2) };
    const auto normal0 = Vector3Tools::UnitCrossProduct(edge0.at(0), edge0.at(1));
    auto intersectInfo = FindOverlap(normal0, tMax, relVelocity);
    if (!intersectInfo.result)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // ����������1�ı�Ե�ͷ��߷���
    Vector3Container edge1{ triangle1.GetVertex(1) - triangle1.GetVertex(0),
                            triangle1.GetVertex(2) - triangle1.GetVertex(1),
                            triangle1.GetVertex(0) - triangle1.GetVertex(2) };
    const auto normal1 = Vector3Tools::UnitCrossProduct(edge1.at(0), edge1.at(1));

    if (Math::FAbs(Vector3Tools::DotProduct(normal0, normal1)) < Math::GetValue(1) - Math::GetZeroTolerance())
    {
        // �����β�ƽ�С�

        // ���� normal1��

        intersectInfo = FindOverlap(normal1, tMax, relVelocity);
        if (!intersectInfo.result)
        {
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }

        // ���� E[i0]xF[i1].
        for (auto i1 = 0; i1 < 3; ++i1)
        {
            for (auto i0 = 0; i0 < 3; ++i0)
            {
                const auto dir = Vector3Tools::UnitCrossProduct(edge0.at(i0), edge1.at(i1));

                intersectInfo = FindOverlap(dir, tMax, relVelocity);
                if (!intersectInfo.result)
                {
                    this->SetIntersectionType(IntersectionType::Empty);
                    return;
                }
            }
        }
    }
    else  // ��������ƽ�еģ�ʵ�����ǹ���ģ���
    {
        // ���� NxE[i0].
        for (auto i = 0; i < 3; ++i)
        {
            const auto dir = Vector3Tools::UnitCrossProduct(normal0, edge0.at(i));

            intersectInfo = FindOverlap(dir, tMax, relVelocity);
            if (!intersectInfo.result)
            {
                this->SetIntersectionType(IntersectionType::Empty);
                return;
            }
        }

        // ���� NxF[i1].
        for (auto i = 0; i < 3; ++i)
        {
            const auto dir = Vector3Tools::UnitCrossProduct(normal1, edge1.at(i));

            intersectInfo = FindOverlap(dir, tMax, relVelocity);
            if (!intersectInfo.result)
            {
                this->SetIntersectionType(IntersectionType::Empty);
                return;
            }
        }
    }

    if (intersectInfo.tFirst <= Math::GetValue(0))
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    this->SetContactTime(intersectInfo.tFirst);

    // ���ҵ�������֮ǰ����һ�ε���U��V
    const Triangle3 moveTriangle0{ triangle0.GetVertex(0) + intersectInfo.tFirst * lhsVelocity,
                                   triangle0.GetVertex(1) + intersectInfo.tFirst * lhsVelocity,
                                   triangle0.GetVertex(2) + intersectInfo.tFirst * lhsVelocity };
    const Triangle3 moveTriangle1{ triangle1.GetVertex(0) + intersectInfo.tFirst * rhsVelocity,
                                   triangle1.GetVertex(1) + intersectInfo.tFirst * rhsVelocity,
                                   triangle1.GetVertex(2) + intersectInfo.tFirst * rhsVelocity };

    FindContactSet(moveTriangle0, moveTriangle1, intersectInfo.side, intersectInfo.tCfg0, intersectInfo.tCfg1);
    this->SetIntersectionType(IntersectionType::Other);
}

template <typename Real>
typename Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::IntersectInfo Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::FindOverlap(const Vector3& axis, Real tmax, const Vector3& velocity)
{
    const auto cfg0 = ProjectOntoAxis(triangle0, axis);
    const auto cfg1 = ProjectOntoAxis(triangle1, axis);
    const auto speed = Vector3Tools::DotProduct(velocity, axis);
    return FindOverlap(tmax, speed, cfg0, cfg1);
}

template <typename Real>
typename Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::Configuration Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::ProjectOntoAxis(const Triangle3& triangle, const Vector3& axis)
{
    Configuration cfg{};

    // ���Ҷ��㵽Ǳ�ڷ������ϵ�ͶӰ��
    const auto d0 = Vector3Tools::DotProduct(axis, triangle.GetVertex(0));
    const auto d1 = Vector3Tools::DotProduct(axis, triangle.GetVertex(1));
    const auto d2 = Vector3Tools::DotProduct(axis, triangle.GetVertex(2));

    // ��ʽ����Ķ����Թ���Configuration����
    if (d0 <= d1)
    {
        if (d1 <= d2)  // D0 <= D1 <= D2
        {
            if (Math::Approximate(d0, d1))
            {
                if (Math::Approximate(d1, d2))
                {
                    cfg.vertexProjectionMap = VertexProjectionMap::M111;
                }
                else
                {
                    cfg.vertexProjectionMap = VertexProjectionMap::M12;
                }
            }
            else  // ( D0 == D1 )
            {
                if (Math::Approximate(d1, d2))
                {
                    cfg.vertexProjectionMap = VertexProjectionMap::M21;
                }
                else
                {
                    cfg.vertexProjectionMap = VertexProjectionMap::M3;
                }
            }
            cfg.index.at(0) = 0;
            cfg.index.at(1) = 1;
            cfg.index.at(2) = 2;
            cfg.min = d0;
            cfg.max = d2;
        }
        else if (d0 <= d2)  // D0 <= D2 < D1
        {
            if (Math::Approximate(d1, d2))
            {
                cfg.vertexProjectionMap = VertexProjectionMap::M111;
                cfg.index.at(0) = 0;
                cfg.index.at(1) = 2;
                cfg.index.at(2) = 1;
            }
            else
            {
                cfg.vertexProjectionMap = VertexProjectionMap::M21;
                cfg.index.at(0) = 2;
                cfg.index.at(1) = 0;
                cfg.index.at(2) = 1;
            }
            cfg.min = d0;
            cfg.max = d1;
        }
        else  // D2 < D0 <= D1
        {
            if (Math::Approximate(d0, d1))
            {
                cfg.vertexProjectionMap = VertexProjectionMap::M111;
            }
            else
            {
                cfg.vertexProjectionMap = VertexProjectionMap::M12;
            }

            cfg.index.at(0) = 2;
            cfg.index.at(1) = 0;
            cfg.index.at(2) = 1;
            cfg.min = d2;
            cfg.max = d1;
        }
    }
    else if (d2 <= d1)  // D2 <= D1 < D0
    {
        if (Math::Approximate(d2, d1))
        {
            cfg.vertexProjectionMap = VertexProjectionMap::M111;
            cfg.index.at(0) = 2;
            cfg.index.at(1) = 1;
            cfg.index.at(2) = 0;
        }
        else
        {
            cfg.vertexProjectionMap = VertexProjectionMap::M21;
            cfg.index.at(0) = 1;
            cfg.index.at(1) = 2;
            cfg.index.at(2) = 0;
        }
        cfg.min = d2;
        cfg.max = d0;
    }
    else if (d2 <= d0)  // D1 < D2 <= D0
    {
        if (Math::Approximate(d2, d0))
        {
            cfg.vertexProjectionMap = VertexProjectionMap::M111;
        }
        else
        {
            cfg.vertexProjectionMap = VertexProjectionMap::M12;
        }

        cfg.index.at(0) = 1;
        cfg.index.at(1) = 2;
        cfg.index.at(2) = 0;
        cfg.min = d1;
        cfg.max = d0;
    }
    else  // D1 < D0 < D2
    {
        cfg.vertexProjectionMap = VertexProjectionMap::M111;
        cfg.index.at(0) = 1;
        cfg.index.at(1) = 0;
        cfg.index.at(2) = 2;
        cfg.min = d1;
        cfg.max = d2;
    }

    return cfg;
}

template <typename Real>
typename Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::IntersectInfo Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::FindOverlap(Real tmax, Real speed, const Configuration& uConfiguration, const Configuration& vConfiguration) noexcept
{
    IntersectInfo intersectInfo{};

    // ���ٷ�������ԡ� uConfiguration��vConfiguration���µ�Ǳ�����ã���intersectInfo����õ����á�

    auto t = Math::GetValue(0);

    if (vConfiguration.max < uConfiguration.min)  // V��U�����
    {
        if (speed <= Math::GetValue(0))  // V��U�ƿ�
        {
            return intersectInfo;
        }

        // ���Ҹ����ϵ��״νӴ���
        t = (uConfiguration.min - vConfiguration.max) / speed;

        // ��������µ�����״νӴ�ʱ�䣬��������ú����á�
        if (intersectInfo.tFirst < t)
        {
            intersectInfo.tFirst = t;
            intersectInfo.side = ContactSide::Left;
            intersectInfo.tCfg0 = uConfiguration;
            intersectInfo.tCfg1 = vConfiguration;
        }

        // �����˳�������ʱ������Ľ��㡣
        if (tmax < intersectInfo.tFirst)
        {
            return intersectInfo;
        }

        // ���Ҹ����ϵ����һ�νӴ�ʱ�䡣
        t = (uConfiguration.max - vConfiguration.min) / speed;
        if (t < intersectInfo.tLast)
        {
            intersectInfo.tLast = t;
        }

        // �����˳�������ʱ����֮ǰ�Ľ��㡣
        if (intersectInfo.tLast < intersectInfo.tFirst)
        {
            return intersectInfo;
        }
    }
    else if (uConfiguration.max < vConfiguration.min)  // V��U���ұ�
    {
        if (Math::GetValue(0) <= speed)  // V��U�ƿ�
        {
            return intersectInfo;
        }

        // ���Ҹ����ϵ��״νӴ���
        t = (uConfiguration.max - vConfiguration.min) / speed;

        // ��������µ�����״νӴ�ʱ�䣬��������ú����á�
        if (intersectInfo.tFirst < t)
        {
            intersectInfo.tFirst = t;
            intersectInfo.side = ContactSide::Right;
            intersectInfo.tCfg0 = uConfiguration;
            intersectInfo.tCfg1 = vConfiguration;
        }

        // �����˳�������ʱ������Ľ��㡣
        if (tmax < intersectInfo.tFirst)
        {
            return intersectInfo;
        }

        // ���Ҹ����ϵ����һ�νӴ�ʱ�䡣
        t = (uConfiguration.min - vConfiguration.max) / speed;
        if (t < intersectInfo.tLast)
        {
            intersectInfo.tLast = t;
        }

        // �����˳�������ʱ����֮ǰ�Ľ��㡣
        if (intersectInfo.tLast < intersectInfo.tFirst)
        {
            return intersectInfo;
        }
    }
    else  // �ص�����ϵ�V��U
    {
        if (Math::GetValue(0) < speed)
        {
            // ���Ҹ����ϵ����һ�νӴ�ʱ�䡣
            t = (uConfiguration.max - vConfiguration.min) / speed;
            if (t < intersectInfo.tLast)
            {
                intersectInfo.tLast = t;
            }

            // �����˳�������ʱ����֮ǰ�Ľ��㡣
            if (intersectInfo.tLast < intersectInfo.tFirst)
            {
                return intersectInfo;
            }
        }
        else if (speed < Math::GetValue(0))
        {
            // ���Ҹ����ϵ����һ�νӴ�ʱ�䡣
            t = (uConfiguration.min - vConfiguration.max) / speed;
            if (t < intersectInfo.tLast)
            {
                intersectInfo.tLast = t;
            }

            // �����˳�������ʱ����֮ǰ�Ľ��㡣
            if (intersectInfo.tLast < intersectInfo.tFirst)
            {
                return intersectInfo;
            }
        }
    }
    intersectInfo.result = true;

    return intersectInfo;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::FindContactSet(const Triangle3& moveTriangle0, const Triangle3& moveTriangle1, const ContactSide& side, const Configuration& cfg0, const Configuration& cfg1)
{
    if (side == ContactSide::Right)  // ri0��tri1���ұ�
    {
        if (cfg0.vertexProjectionMap == VertexProjectionMap::M21 || cfg0.vertexProjectionMap == VertexProjectionMap::M111)
        {
            // tri0���㴥��tri1
            this->SetIntersectionType(IntersectionType::Point);

            point.emplace_back(moveTriangle0.GetVertex(cfg0.index.at(2)));
        }
        else if (cfg1.vertexProjectionMap == VertexProjectionMap::M12 || cfg1.vertexProjectionMap == VertexProjectionMap::M111)
        {
            // tri1���㴥��tri0
            this->SetIntersectionType(IntersectionType::Point);

            point.emplace_back(moveTriangle1.GetVertex(cfg1.index.at(0)));
        }
        else if (cfg0.vertexProjectionMap == VertexProjectionMap::M12)
        {
            if (cfg1.vertexProjectionMap == VertexProjectionMap::M21)
            {
                // edge0-edge1 �ཻ
                GetEdgeEdgeIntersection(moveTriangle0.GetVertex(cfg0.index.at(1)), moveTriangle0.GetVertex(cfg0.index.at(2)),
                                        moveTriangle1.GetVertex(cfg1.index.at(0)), moveTriangle1.GetVertex(cfg1.index.at(1)));
            }
            else  // cfg1.vertexProjectionMap == m3
            {
                // u��-v�� �ཻ
                GetEdgeFaceIntersection(moveTriangle0.GetVertex(cfg0.index.at(1)), moveTriangle0.GetVertex(cfg0.index.at(2)), moveTriangle1);
            }
        }
        else  // cfg0.vertexProjectionMap == M3
        {
            if (cfg1.vertexProjectionMap == VertexProjectionMap::M21)
            {
                // ��0-��1 �ཻ
                GetEdgeFaceIntersection(moveTriangle1.GetVertex(cfg1.index.at(0)), moveTriangle1.GetVertex(cfg1.index.at(1)), moveTriangle0);
            }
            else  // cfg1.vertexProjectionMap == M3
            {
                // ��0-��1 �ཻ
                const Plane3 plane0{ moveTriangle0.GetVertex(0), moveTriangle0.GetVertex(1), moveTriangle0.GetVertex(2) };
                GetCoplanarIntersection(plane0, moveTriangle0, moveTriangle1);
            }
        }
    }
    else if (side == ContactSide::Left)  // tri1��tri0�����
    {
        if (cfg1.vertexProjectionMap == VertexProjectionMap::M21 || cfg1.vertexProjectionMap == VertexProjectionMap::M111)
        {
            // tri1���㴥��tri0
            this->SetIntersectionType(IntersectionType::Point);

            point.emplace_back(moveTriangle1.GetVertex(cfg1.index.at(2)));
        }
        else if (cfg0.vertexProjectionMap == VertexProjectionMap::M12 || cfg0.vertexProjectionMap == VertexProjectionMap::M111)
        {
            // tri0���㴥��tri1
            this->SetIntersectionType(IntersectionType::Point);

            point.emplace_back(moveTriangle0.GetVertex(cfg0.index.at(0)));
        }
        else if (cfg1.vertexProjectionMap == VertexProjectionMap::M12)
        {
            if (cfg0.vertexProjectionMap == VertexProjectionMap::M21)
            {
                // ��0-��1 �ཻ
                GetEdgeEdgeIntersection(moveTriangle0.GetVertex(cfg0.index.at(0)), moveTriangle0.GetVertex(cfg0.index.at(1)), moveTriangle1.GetVertex(cfg1.index.at(1)), moveTriangle1.GetVertex(cfg1.index.at(2)));
            }
            else  // cfg0.vertexProjectionMap == M3
            {
                // ��1-��0 �ཻ
                GetEdgeFaceIntersection(moveTriangle1.GetVertex(cfg1.index.at(1)), moveTriangle1.GetVertex(cfg1.index.at(2)), moveTriangle0);
            }
        }
        else  // cfg1.vertexProjectionMap == M3
        {
            if (cfg0.vertexProjectionMap == VertexProjectionMap::M21)
            {
                // ��e0-��1 �ཻ
                GetEdgeFaceIntersection(moveTriangle0.GetVertex(cfg0.index.at(0)), moveTriangle0.GetVertex(cfg0.index.at(1)), moveTriangle1);
            }
            else  // cfg0.vertexProjectionMap == M
            {
                // ��0-��1 �ཻ
                const Plane3 plane0{ moveTriangle0.GetVertex(0), moveTriangle0.GetVertex(1), moveTriangle0.GetVertex(2) };
                GetCoplanarIntersection(plane0, moveTriangle0, moveTriangle1);
            }
        }
    }
    else  // side == CS_NONE
    {
        // �������Ѿ��ཻ�ˡ�
        StaticFindIntersectorTriangle3Triangle3<Real> calc{ moveTriangle0, moveTriangle1 };
        const auto result = calc.IsIntersection();
        MATHEMATICS_ASSERTION_0(result, "�����������\n");

        const auto quantity = calc.GetQuantity();
        this->SetIntersectionType(calc.GetIntersectionType());
        for (auto i = 0; i < quantity; ++i)
        {
            point.emplace_back(calc.GetPoint(i));
        }
    }
}

template <typename Real>
void Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::GetCoplanarIntersection(const Plane3& plane, const Triangle3& moveTriangle0, const Triangle3& moveTriangle1)
{
    // ����ƽ�淨������������ƽ����ͶӰ�����Ρ�
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

    using Triangle = std::array<Vector2<Real>, 3>;

    Triangle projectTriangle0Vector{};
    Triangle projectTriangle1Vector{};

    if (maxNormal == 0)
    {
        // ͶӰ��yzƽ���ϡ�
        for (auto i = 0; i < 3; ++i)
        {
            projectTriangle0Vector.at(i).SetCoordinate(moveTriangle0.GetVertex(i).GetY(), moveTriangle0.GetVertex(i).GetZ());
            projectTriangle1Vector.at(i).SetCoordinate(moveTriangle1.GetVertex(i).GetY(), moveTriangle1.GetVertex(i).GetZ());
        }
    }
    else if (maxNormal == 1)
    {
        // ͶӰ��xzƽ���ϡ�
        for (auto i = 0; i < 3; ++i)
        {
            projectTriangle0Vector.at(i).SetCoordinate(moveTriangle0.GetVertex(i).GetX(), moveTriangle0.GetVertex(i).GetZ());
            projectTriangle1Vector.at(i).SetCoordinate(moveTriangle1.GetVertex(i).GetX(), moveTriangle1.GetVertex(i).GetZ());
        }
    }
    else
    {
        // ͶӰ��xyƽ���ϡ�
        for (auto i = 0; i < 3; ++i)
        {
            projectTriangle0Vector.at(i).SetCoordinate(moveTriangle0.GetVertex(i).GetX(), moveTriangle0.GetVertex(i).GetY());
            projectTriangle1Vector.at(i).SetCoordinate(moveTriangle1.GetVertex(i).GetX(), moveTriangle1.GetVertex(i).GetY());
        }
    }

    Triangle2<Real> projectTriangle0{ projectTriangle0Vector.at(0), projectTriangle0Vector.at(1), projectTriangle0Vector.at(2) };
    Triangle2<Real> projectTriangle1{ projectTriangle1Vector.at(0), projectTriangle1Vector.at(1), projectTriangle1Vector.at(2) };

    // 2D�������ཻ������Ҫ��ʱ������

    auto edge0 = projectTriangle0.GetVertex(1) - projectTriangle0.GetVertex(0);
    auto edge1 = projectTriangle0.GetVertex(2) - projectTriangle0.GetVertex(0);
    if (Vector2Tools<Real>::DotPerp(edge0, edge1) < Math::GetValue(0))
    {
        // ��������˳ʱ�뷽������������
        projectTriangle0 = Triangle2<Real>{ projectTriangle0Vector.at(0), projectTriangle0Vector.at(2), projectTriangle0Vector.at(1) };
    }

    edge0 = projectTriangle1.GetVertex(1) - projectTriangle1.GetVertex(0);
    edge1 = projectTriangle1.GetVertex(2) - projectTriangle1.GetVertex(0);
    if (Vector2Tools<Real>::DotPerp(edge0, edge1) < Math::GetValue(0))
    {
        // ��������˳ʱ�뷽������������
        projectTriangle1 = Triangle2<Real>{ projectTriangle1Vector.at(0), projectTriangle1Vector.at(2), projectTriangle1Vector.at(1) };
    }

    StaticFindIntersectorTriangle2Triangle2<Real> intr{ projectTriangle0, projectTriangle1 };
    if (!intr.IsIntersection())
    {
        return;
    }

    // ��2D����ӳ���3D�����οռ䡣
    const auto quantity = intr.GetQuantity();
    if (maxNormal == 0)
    {
        auto invNormalX = (Math::GetValue(1)) / plane.GetNormal().GetX();
        for (auto i = 0; i < quantity; i++)
        {
            Vector3 vertex{ Math::GetValue(0), intr.GetPoint(i).GetX(), intr.GetPoint(i).GetY() };
            vertex.SetX(invNormalX * (plane.GetConstant() - plane.GetNormal().GetY() * vertex.GetY() - plane.GetNormal().GetZ() * vertex.GetZ()));
            point.emplace_back(vertex);
        }
    }
    else if (maxNormal == 1)
    {
        auto invNormalY = (Math::GetValue(1)) / plane.GetNormal().GetY();
        for (auto i = 0; i < quantity; i++)
        {
            Vector3 vertex{ intr.GetPoint(i).GetX(), Math::GetValue(0), intr.GetPoint(i).GetY() };
            vertex.SetY(invNormalY * (plane.GetConstant() - plane.GetNormal().GetX() * vertex.GetX() - plane.GetNormal().GetZ() * vertex.GetZ()));
            point.emplace_back(vertex);
        }
    }
    else
    {
        auto invNormalZ = (Math::GetValue(1)) / plane.GetNormal().GetZ();
        for (auto i = 0; i < quantity; i++)
        {
            Vector3 vertex{ intr.GetPoint(i).GetX(), intr.GetPoint(i).GetY(), Math::GetValue(0) };
            vertex.SetZ(invNormalZ * (plane.GetConstant() - plane.GetNormal().GetX() * vertex.GetX() - plane.GetNormal().GetY() * vertex.GetY()));
            point.emplace_back(vertex);
        }
    }

    this->SetIntersectionType(IntersectionType::Plane);
}

template <typename Real>
void Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::GetEdgeEdgeIntersection(const Vector3& u0, const Vector3& u1, const Vector3& v0, const Vector3& v1)
{
    // ����������Եƽ��ķ��ߡ�
    auto edge0 = u1 - u0;
    auto edge1 = v1 - v0;
    const auto normal = Vector3Tools::CrossProduct(edge0, edge1);

    /// ���U0 + s * (U1 - U0) = V0 + t * (V1 - V0)��
    /// ����֪�����ཻ������[0,1]�е�s��[0,1]�е�t�� ��ˣ�ֻ����s��
    /// ע�⣬s * E0 = D + t * E1������D = V0 - U0��
    /// ���s * N = s * E0xE1 = DxE1��s = N * DxE1 / N * N��
    auto delta = v0 - u0;
    auto s = Vector3Tools::DotProduct(normal, (Vector3Tools::CrossProduct(delta, edge1) / Vector3Tools::GetLengthSquared(normal)));
    if (s < Math::GetValue(0))
    {
        MATHEMATICS_ASSERTION_0(-Math::GetZeroTolerance() <= s, "�����sֵ��\n");
        s = Math::GetValue(0);
    }
    else if (Math::GetValue(1) < s)
    {
        MATHEMATICS_ASSERTION_0(s <= Math::GetValue(1) + Math::GetZeroTolerance(), "�����sֵ��\n");
        s = Math::GetValue(1);
    }

    this->SetIntersectionType(IntersectionType::Point);

    point.emplace_back(u0 + s * edge0);

    // �����Ե��ƽ�е���ô�죿
}

template <typename Real>
void Mathematics::DynamicFindIntersectorTriangle3Triangle3<Real>::GetEdgeFaceIntersection(const Vector3& u0, const Vector3& u1, const Triangle3& triangle)
{
    // ���������ε�ƽ�档
    const auto vertex = triangle.GetVertex(0);
    const auto edge0 = triangle.GetVertex(1) - vertex;
    const auto edge1 = triangle.GetVertex(2) - vertex;
    const auto normal = Vector3Tools::UnitCrossProduct(edge0, edge1);

    const auto Vector3OrthonormalBasis = Vector3Tools::GenerateComplementBasis(normal);
    const auto dir0 = Vector3OrthonormalBasis.GetUVector();
    const auto dir1 = Vector3OrthonormalBasis.GetVVector();

    // ����Ե�˵�ͶӰ��ƽ���ϡ�

    auto diff = u0 - vertex;
    const Vector2<Real> projectU0{ Vector3Tools::DotProduct(dir0, diff), Vector3Tools::DotProduct(dir1, diff) };

    diff = u1 - vertex;
    const Vector2<Real> projectU1{ Vector3Tools::DotProduct(dir0, diff), Vector3Tools::DotProduct(dir1, diff) };

    const Segment2<Real> projectSegment{ projectU0, projectU1 };

    // ���������ε�ƽ�����ꡣ
    using Triangle = std::array<Vector2<Real>, 3>;
    Triangle projectTriangleVector{ Vector2<Real>::GetZero(),
                                    Vector2<Real>(Vector2Tools<Real>::DotProduct(dir0, edge0), Vector2Tools<Real>::DotProduct(dir1, edge0)),
                                    Vector2<Real>(Vector2Tools<Real>::DotProduct(dir0, edge1), Vector2Tools<Real>::DotProduct(dir1, edge1)) };

    const Triangle2<Real> projectTriangle{ projectTriangleVector.at(0), projectTriangleVector.at(1), projectTriangleVector.at(2) };

    // ���㽻����
    StaticFindIntersectorSegment2Triangle2<Real> calc{ projectSegment, projectTriangle };
    if (calc.IsIntersection())
    {
        const auto quantity = calc.GetQuantity();
        for (auto i = 0; i < quantity; ++i)
        {
            auto proj = calc.GetPoint(i);
            point.emplace_back(vertex + proj[0] * dir0 + proj[1] * dir1);
        }
    }
    else
    {
        /// ������һ������㡣 ���п��ܵ��������������Ҳ������� ʹ�ý�����3D��������������³���ԡ�
        const Segment3<Real> seg{ u0, u1 };
        DistanceSegment3Triangle3<Real> dcalc{ seg, triangle };

        // ���ǲ���Ҫ���룬����������Ҫ��λ��ӽ���ĸ����á�

        auto parameter = dcalc.GetSquared().GetLhsParameter();

        point.emplace_back(seg.GetCenterPoint() + parameter * seg.GetDirection());
    }

    this->SetIntersectionType((GetQuantity() == 2 ? IntersectionType::Segment : IntersectionType::Point));
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_DETAIL_H