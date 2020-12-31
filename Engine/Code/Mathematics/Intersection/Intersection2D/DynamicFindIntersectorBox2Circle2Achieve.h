///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/17 14:44)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX2_CIRCLE2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX2_CIRCLE2_ACHIEVE_H

#include "DynamicFindIntersectorBox2Circle2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Distance/Distance2D/DistancePoint2Box2Detail.h"

template <typename Real>
Mathematics::DynamicFindIntersectorBox2Circle2<Real>::DynamicFindIntersectorBox2Circle2(const Box2& box, const Circle2& circle, Real tmax, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, m_Box{ box }, m_Circle{ circle }, m_ContactPoint{}
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
const Mathematics::Box2<Real> Mathematics::DynamicFindIntersectorBox2Circle2<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Box;
}

template <typename Real>
const Mathematics::Circle2<Real> Mathematics::DynamicFindIntersectorBox2Circle2<Real>::GetCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Circle;
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::DynamicFindIntersectorBox2Circle2<Real>::GetContactPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_ContactPoint;
}

template <typename Real>
Mathematics::DynamicFindIntersectorBox2Circle2<Real>::RegionInfo::RegionInfo(IntersectingType type, Real x, Real y) noexcept
    : m_Type{ type }, m_X{ x }, m_Y{ y }
{
}

template <typename Real>
Mathematics::DynamicFindIntersectorBox2Circle2<Real>::RegionInfo::RegionInfo(IntersectingType type) noexcept
    : m_Type{ type }, m_X{}, m_Y{}
{
}

template <typename Real>
void Mathematics::DynamicFindIntersectorBox2Circle2<Real>::Find()
{
    // ��Բ��ת��Ϊ�����ꡣ
    auto centerDiff = m_Circle.GetCenter() - m_Box.GetCenter();
    auto velocityDiff = this->GetRhsVelocity() - this->GetLhsVelocity();
    auto centerDotX = Vector2DTools<Real>::DotProduct(centerDiff, m_Box.GetAxis0());
    auto centerDotY = Vector2DTools<Real>::DotProduct(centerDiff, m_Box.GetAxis1());
    auto velocityDotX = Vector2DTools<Real>::DotProduct(velocityDiff, m_Box.GetAxis0());
    auto velocityDotY = Vector2DTools<Real>::DotProduct(velocityDiff, m_Box.GetAxis1());
    auto extent0 = m_Box.GetExtent0();
    auto extent1 = m_Box.GetExtent1();

    auto type = IntersectingType::NoIntersection;
    auto indexX = Math::GetValue(0);
    auto indexY = Math::GetValue(0);

    if (centerDotX < -extent0)
    {
        if (centerDotY < -extent1)
        {
            // ���� Rmm
            const auto regionInfo = TestVertexRegion(centerDotX, centerDotY, velocityDotX, velocityDotY, extent0, extent1);
            type = regionInfo.m_Type;
            indexX = regionInfo.m_X;
            indexY = regionInfo.m_Y;
        }
        else if (centerDotY <= extent1)
        {
            // ���� Rmz
            const auto regionInfo = TestEdgeRegion(centerDotX, centerDotY, velocityDotX, velocityDotY, extent0, extent1);
            type = regionInfo.m_Type;
            indexX = regionInfo.m_X;
            indexY = regionInfo.m_Y;
        }
        else
        {
            // ���� Rmp
            const auto regionInfo = TestVertexRegion(centerDotX, -centerDotY, velocityDotX, -velocityDotY, extent0, extent1);
            type = regionInfo.m_Type;
            indexX = regionInfo.m_X;
            indexY = -regionInfo.m_Y;
        }
    }
    else if (centerDotX <= extent0)
    {
        if (centerDotY < -extent1)
        {
            // ���� Rzm
            const auto regionInfo = TestEdgeRegion(centerDotY, centerDotX, velocityDotY, velocityDotX, extent1, extent0);
            type = regionInfo.m_Type;
            indexX = regionInfo.m_Y;
            indexY = regionInfo.m_X;
        }
        else if (centerDotY <= extent1)
        {
            // ���� Rzz:
            // ԲȦ�Ѿ�������ཻ�ˡ� ʹ��Բ����Ϊ���㣬��ͨ�����ء����������㣬����ʹ������֪�������ص���
            this->SetContactTime(Math::GetValue(0));
            m_ContactPoint = m_Circle.GetCenter();
            this->SetIntersectionType(IntersectionType::Other);
            return;
        }
        else
        {
            // ���� Rzp
            const auto regionInfo = TestEdgeRegion(-centerDotY, centerDotX, -velocityDotY, velocityDotX, extent1, extent0);
            type = regionInfo.m_Type;
            indexX = regionInfo.m_Y;
            indexY = -regionInfo.m_X;
        }
    }
    else
    {
        if (centerDotY < -extent1)
        {
            // ���� Rpm
            const auto regionInfo = TestVertexRegion(-centerDotX, centerDotY, -velocityDotX, velocityDotY, extent0, extent1);
            type = regionInfo.m_Type;
            indexX = -regionInfo.m_X;
            indexY = regionInfo.m_Y;
        }
        else if (centerDotY <= extent1)
        {
            // ���� Rpz
            const auto regionInfo = TestEdgeRegion(-centerDotX, centerDotY, -velocityDotX, velocityDotY, extent0, extent1);
            type = regionInfo.m_Type;
            indexX = -regionInfo.m_X;
            indexY = regionInfo.m_Y;
        }
        else
        {
            // ���� Rpp
            const auto regionInfo = TestVertexRegion(-centerDotX, -centerDotY, -velocityDotX, -velocityDotY, extent0, extent1);
            type = regionInfo.m_Type;
            indexX = -regionInfo.m_X;
            indexY = -regionInfo.m_Y;
        }
    }

    if (type != IntersectingType::Intersect || this->GetTMax() < this->GetContactTime())
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
    else
    {
        m_ContactPoint = m_Box.GetCenter() + indexX * m_Box.GetAxis0() + indexY * m_Box.GetAxis1();
        this->SetIntersectionType(IntersectionType::Point);
    }
}

template <typename Real>
typename Mathematics::DynamicFindIntersectorBox2Circle2<Real>::RegionInfo Mathematics::DynamicFindIntersectorBox2Circle2<Real>::TestVertexRegion(Real centerDotX, Real centerDotY, Real velocityDotX, Real velocityDotY, Real extent0, Real extent1) noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    auto dx = centerDotX + extent0;
    auto dy = centerDotY + extent1;
    auto radiusSqr = m_Circle.GetRadius() * m_Circle.GetRadius();
    auto diff = dx * dx + dy * dy - radiusSqr;
    if (diff <= Math::GetValue(0))
    {
        // ԲȦ�Ѿ�������ཻ�ˡ�
        this->SetContactTime(Math::GetValue(0));
        return RegionInfo{ IntersectingType::Initially };
    }

    auto dot = velocityDotX * dx + velocityDotY * dy;
    if (Math::GetValue(0) <= dot)
    {
        // ԲȦδ������ӡ�
        return RegionInfo{ IntersectingType::NoIntersection };
    }

    auto dotPerp = velocityDotX * dy - velocityDotY * dx;
    auto indexX = Math::GetValue(0);
    auto indexY = Math::GetValue(0);

    if (Math::GetValue(0) <= dotPerp)
    {
        // Ǳ�ڽӴ������Ե��
        if (dotPerp <= m_Circle.GetRadius() * velocityDotY)
        {
            // ���½��ǵ�һ���Ӵ��㡣
            auto velocitySqr = velocityDotX * velocityDotX + velocityDotY * velocityDotY;
            auto inv = Math::InvSqrt(Math::FAbs(dot * dot - velocitySqr * diff));
            this->SetContactTime(diff * inv / (Math::GetValue(1) - dot * inv));

            return RegionInfo{ IntersectingType::Intersect, -extent0, -extent1 };
        }

        if (velocityDotX <= Math::GetValue(0))
        {
            // �����ǣ��뿪���ӡ�
            return RegionInfo{ IntersectingType::NoIntersection };
        }

        auto velocitySqr = velocityDotX * velocityDotX + velocityDotY * velocityDotY;
        dy = centerDotY - extent1;
        dotPerp = velocityDotX * dy - velocityDotY * dx;
        if (Math::GetValue(0) <= dotPerp && radiusSqr * velocitySqr < dotPerp * dotPerp)
        {
            // ԲȦδ���к��ӡ�
            return RegionInfo{ IntersectingType::NoIntersection, indexX, indexY };
        }

        // ԲȦ��������ཻ�� ��x = xminȷ����һ�νӴ���ʱ���λ�á�
        indexX = -extent0;

        if (dotPerp <= m_Circle.GetRadius() * velocityDotY)
        {
            // ��һ�νӴ��ں��ӵ����Ե��
            this->SetContactTime(-(dx + m_Circle.GetRadius()) / velocityDotX);
            indexY = centerDotY + this->GetContactTime() * velocityDotY;
        }
        else
        {
            // ���ӵ����Ͻǵĵ�һ���Ӵ��㡣
            dot = velocityDotX * dx + velocityDotY * dy;
            diff = dx * dx + dy * dy - radiusSqr;
            auto inv = Math::InvSqrt(Math::FAbs(dot * dot - velocitySqr * diff));
            this->SetContactTime(diff * inv / (Math::GetValue(1) - dot * inv));
            indexY = extent1;
        }
    }
    else
    {
        // �ϵײ���ԵǱ�ڽӴ���
        if (-dotPerp <= m_Circle.GetRadius() * velocityDotX)
        {
            // ���½��ǵ�һ���Ӵ��㡣

            auto velocitySqr = velocityDotX * velocityDotX + velocityDotY * velocityDotY;
            auto inv = Math::InvSqrt(Math::FAbs(dot * dot - velocitySqr * diff));
            this->SetContactTime(diff * inv / (Math::GetValue(1) - dot * inv));

            return RegionInfo{ IntersectingType::Intersect, -extent0, -extent1 };
        }

        if (velocityDotY <= Math::GetValue(0))
        {
            // �����ǣ��뿪���ӡ�
            return RegionInfo{ IntersectingType::NoIntersection, indexX, indexY };
        }

        auto velocitySqr = velocityDotX * velocityDotX + velocityDotY * velocityDotY;
        dx = centerDotX - extent0;
        dotPerp = velocityDotX * dy - velocityDotY * dx;
        if (Math::GetValue(0) <= -dotPerp && radiusSqr * velocitySqr < dotPerp * dotPerp)
        {
            // ԲȦδ���к��ӡ�
            return RegionInfo{ IntersectingType::NoIntersection, indexX, indexY };
        }

        // Բ��������ཻ�� ȷ����һ�νӴ���ʱ��͵ص㣬y = ymin��
        indexY = -extent1;

        if (-dotPerp <= m_Circle.GetRadius() * velocityDotX)
        {
            // ���ӵײ���Ե�ĵ�һ�νӴ���
            this->SetContactTime(-(dy + m_Circle.GetRadius()) / velocityDotY);
            indexX = centerDotX + this->GetContactTime() * velocityDotX;
        }
        else
        {
            // ��һ�νӴ��ں��ӵ����½ǡ�
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
typename Mathematics::DynamicFindIntersectorBox2Circle2<Real>::RegionInfo Mathematics::DynamicFindIntersectorBox2Circle2<Real>::TestEdgeRegion(Real centerDotX, Real centerDotY, Real velocityDotX, Real velocityDotY, Real extent0, Real extent1) noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    auto indexX = Math::GetValue(0);
    auto indexY = Math::GetValue(0);
    auto dx = centerDotX + extent0;
    auto xSignedDist = dx + m_Circle.GetRadius();
    if (Math::GetValue(0) <= xSignedDist)
    {
        // ԲȦ�Ѿ�������ཻ�ˡ�
        this->SetContactTime(Math::GetValue(0));

        return RegionInfo{ IntersectingType::Initially, indexX, indexY };
    }

    if (velocityDotX <= Math::GetValue(0))
    {
        // ԲȦδ������ӡ�
        return RegionInfo{ IntersectingType::NoIntersection, indexX, indexY };
    }

    auto radiusSqr = m_Circle.GetRadius() * m_Circle.GetRadius();
    auto velocitySqr = velocityDotX * velocityDotX + velocityDotY * velocityDotY;

    if (Math::GetValue(0) <= velocityDotY)
    {
        auto dy = centerDotY - extent1;
        auto dotPerp = velocityDotX * dy - velocityDotY * dx;
        if (Math::GetValue(0) <= dotPerp && radiusSqr * velocitySqr < dotPerp * dotPerp)
        {
            // ԲȦδ���к��ӡ�
            return RegionInfo{ IntersectingType::NoIntersection, indexX, indexY };
        }

        // ԲȦ��������ཻ�� ��x = xminȷ����һ�νӴ���ʱ���λ�á�
        indexX = -extent0;

        if (dotPerp <= m_Circle.GetRadius() * velocityDotY)
        {
            // ��һ�νӴ��ں��ӵ����Ե��
            this->SetContactTime(-xSignedDist / velocityDotX);
            indexY = centerDotY + this->GetContactTime() * velocityDotY;
        }
        else
        {
            // ��һ�νӴ��ں��ӵ�һ�ǡ�
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
            // ԲȦδ���к��ӡ�
            return RegionInfo{ IntersectingType::NoIntersection, indexX, indexY };
        }

        // ԲȦ��������ཻ�� ȷ����һ�νӴ��ĵط���x = xmin��
        indexX = -extent0;

        if (dotPerp >= m_Circle.GetRadius() * velocityDotY)
        {
            // ��һ�νӴ��ں��ӵ����Ե��
            this->SetContactTime(-xSignedDist / velocityDotX);
            indexY = centerDotY + this->GetContactTime() * velocityDotY;
        }
        else
        {
            // ��һ�νӴ��ں��ӵ�һ�ǡ�
            auto dot = velocityDotX * dx + velocityDotY * dy;
            auto diff = dx * dx + dy * dy - radiusSqr;
            auto inv = Math::InvSqrt(Math::FAbs(dot * dot - velocitySqr * diff));
            this->SetContactTime(diff * inv / (Math::GetValue(1) - dot * inv));
            indexY = -extent1;
        }
    }

    return RegionInfo{ IntersectingType::Intersect, indexX, indexY };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX2_CIRCLE2_ACHIEVE_H