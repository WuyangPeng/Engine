///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/07 13:53)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_ACHIEVE_H

#include "DynamicFindIntersectorTriangle3Box3.h"
#include "FindContactSetDetail.h"
#include "FindIntersectorAxisDetail.h"
#include "IntersectorConfigurationDetail.h"
#include "Detail/DynamicFindIntersectorTriangle3Box3ImplDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/Flags/ContactSide.h"

template <typename Real>
Mathematics::DynamicFindIntersectorTriangle3Box3<Real>::DynamicFindIntersectorTriangle3Box3(const Triangle3& triangle, const Box3& box, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, m_Impl{ std::make_shared<ImplType>(triangle, box) }
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DynamicFindIntersectorTriangle3Box3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::DynamicFindIntersectorTriangle3Box3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetTriangle();
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DynamicFindIntersectorTriangle3Box3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetBox();
}

template <typename Real>
void Mathematics::DynamicFindIntersectorTriangle3Box3<Real>::Find()
{
    auto tMax = this->GetTMax();
    const auto lhsVelocity = this->GetLhsVelocity();
    const auto rhsVelocity = this->GetRhsVelocity();
    auto triangle = m_Impl->GetTriangle();
    auto box = m_Impl->GetBox();

    // 好像三角形是静止的，盒子在移动。
    auto relVelocity = rhsVelocity - lhsVelocity;

    // 测试三角形法线
    using EdgeType = std::array<Vector3D, 3>;
    EdgeType edge{ triangle.GetVertex(1) - triangle.GetVertex(0),
                   triangle.GetVertex(2) - triangle.GetVertex(1),
                   triangle.GetVertex(0) - triangle.GetVertex(2) };
    const auto triangleNorm = Vector3DTools::CrossProduct(edge.at(0), edge.at(1));
    this->SetContactTime(Math::GetValue(0));

    FindIntersectorAxis<Real> intersector{ triangleNorm, triangle, box, relVelocity, tMax };
    auto tLast = intersector.GetTLast();
    auto triangleContact = intersector.GetCfgFinal0();
    auto boxContact = intersector.GetCfgFinal1();
    auto side = intersector.Getside();
    auto contactTime = intersector.GetTFirst();

    if (!intersector.GetResult())
    {
        this->SetContactTime(contactTime);
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // 三角形共面而不垂直于框
    auto coplanar = -1;

    for (auto i = 0; i < 3; ++i)
    {
        const auto axis = box.GetAxis(i);

        FindIntersectorAxis<Real> findIntersectorAxis{ axis, triangle, box, relVelocity, tMax };
        tLast = findIntersectorAxis.GetTLast();
        triangleContact = findIntersectorAxis.GetCfgFinal0();
        boxContact = findIntersectorAxis.GetCfgFinal1();
        side = findIntersectorAxis.Getside();
        contactTime = findIntersectorAxis.GetTFirst();

        if (!findIntersectorAxis.GetResult())
        {
            this->SetContactTime(contactTime);
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }

        // 测试轴是否平行于三角形法线。 测试为：sin(Angle(normal,axis)) < epsilon
        auto triangleNormDotAxis = Vector3DTools::DotProduct(triangleNorm, axis);
        auto triangleNormDotTriangleNorm = Vector3DTools::VectorMagnitudeSquared(triangleNorm);
        auto axisDotAxis = Vector3DTools::VectorMagnitudeSquared(axis);
        auto sinValue = Math::Sqrt(Math::FAbs(Math::GetValue(1) - triangleNormDotAxis * triangleNormDotAxis / (triangleNormDotTriangleNorm * axisDotAxis)));
        if (sinValue < Math::GetZeroTolerance())
        {
            coplanar = i;
        }
    }

    if (coplanar == -1)
    {
        // 测试三角形穿过盒面。
        for (auto i0 = 0; i0 < 3; ++i0)
        {
            for (auto i1 = 0; i1 < 3; ++i1)
            {
                const auto axis = Vector3DTools::CrossProduct(edge.at(i0), box.GetAxis(i1));
                FindIntersectorAxis<Real> findIntersectorAxis{ axis, triangle, box, relVelocity, tMax };
                tLast = findIntersectorAxis.GetTLast();
                triangleContact = findIntersectorAxis.GetCfgFinal0();
                boxContact = findIntersectorAxis.GetCfgFinal1();
                side = findIntersectorAxis.Getside();
                contactTime = findIntersectorAxis.GetTFirst();

                if (!findIntersectorAxis.GetResult())
                {
                    this->SetContactTime(contactTime);
                    this->SetIntersectionType(IntersectionType::Empty);
                    return;
                }
            }
        }
    }
    else
    {
        // 测试三角形穿过盒轴。
        for (auto i = 0; i < 3; ++i)
        {
            const auto axis = Vector3DTools::CrossProduct(edge.at(i), triangleNorm);
            FindIntersectorAxis<Real> findIntersectorAxis{ axis, triangle, box, relVelocity, tMax };
            tLast = findIntersectorAxis.GetTLast();
            triangleContact = findIntersectorAxis.GetCfgFinal0();
            boxContact = findIntersectorAxis.GetCfgFinal1();
            side = findIntersectorAxis.Getside();
            contactTime = findIntersectorAxis.GetTFirst();

            if (!findIntersectorAxis.GetResult())
            {
                this->SetContactTime(contactTime);
                this->SetIntersectionType(IntersectionType::Empty);
                return;
            }
        }
    }

    // 测试向量穿过盒面。
    for (auto i = 0; i < 3; ++i)
    {
        const auto axis = Vector3DTools::CrossProduct(relVelocity, box.GetAxis(i));

        FindIntersectorAxis<Real> findIntersectorAxis{ axis, triangle, box, relVelocity, tMax };
        tLast = findIntersectorAxis.GetTLast();
        triangleContact = findIntersectorAxis.GetCfgFinal0();
        boxContact = findIntersectorAxis.GetCfgFinal1();
        side = findIntersectorAxis.Getside();
        contactTime = findIntersectorAxis.GetTFirst();

        if (!findIntersectorAxis.GetResult())
        {
            this->SetContactTime(contactTime);
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    if (contactTime < Math::GetValue(0) || side == ContactSide::None)
    {
        this->SetContactTime(contactTime);
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    FindContactSet<Real> findContactSet{ triangle, box, side, triangleContact, boxContact, lhsVelocity, rhsVelocity, contactTime };
    m_Impl->SetPoint(findContactSet.GetPoint());

    this->SetContactTime(contactTime);
    this->SetIntersectionType(IntersectionType::Other);
}

template <typename Real>
int Mathematics::DynamicFindIntersectorTriangle3Box3<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetQuantity();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorTriangle3Box3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetPoint(index);
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_ACHIEVE_H