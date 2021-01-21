///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/15 16:30)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE3_TRIANGLE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE3_TRIANGLE3_ACHIEVE_H

#include "DynamicTestIntersectorTriangle3Triangle3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>::DynamicTestIntersectorTriangle3Triangle3(const Triangle3& triangle0, const Triangle3& triangle1, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, m_Triangle0{ triangle0 }, m_Triangle1{ triangle1 }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>::GetTriangle0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Triangle0;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>::GetTriangle1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Triangle1;
}

template <typename Real>
Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>::IntersectInfo::IntersectInfo() noexcept
    : m_Result{}, m_TFirst{}, m_TLast{ Math::sm_MaxReal }
{
}

template <typename Real>
Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>::IntersectInfo::IntersectInfo(bool result, Real tFirst, Real tLast) noexcept
    : m_Result{ result }, m_TFirst{ tFirst }, m_TLast{ tLast }
{
}

template <typename Real>
void Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>::Test()
{
    auto tMax = this->GetTMax();
    const auto velocity0 = this->GetLhsVelocity();
    const auto velocity1 = this->GetRhsVelocity();
    auto tFirst = Math::GetValue(0);

    // 相对于三角形0的速度。
    auto relVelocity = velocity1 - velocity0;

    // 计算三角形0的边缘和法线方向。
    using TriangleType = std::array<Vector3D, 3>;
    TriangleType edge0{ m_Triangle0.GetVertex(1) - m_Triangle0.GetVertex(0),
                        m_Triangle0.GetVertex(2) - m_Triangle0.GetVertex(1),
                        m_Triangle0.GetVertex(0) - m_Triangle0.GetVertex(2) };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    const auto normal0 = Vector3DTools::UnitCrossProduct(edge0[0], edge0[1]);
#include STSTEM_WARNING_POP

    auto intersectInfo = TestOverlap(normal0, tMax, relVelocity);
    tFirst = intersectInfo.m_TFirst;
    if (!intersectInfo.m_Result)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // 计算三角形1的边缘和法线方向。
    TriangleType edge1{ m_Triangle1.GetVertex(1) - m_Triangle1.GetVertex(0),
                        m_Triangle1.GetVertex(2) - m_Triangle1.GetVertex(1),
                        m_Triangle1.GetVertex(0) - m_Triangle1.GetVertex(2) };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    const auto normal1 = Vector3DTools::UnitCrossProduct(edge1[0], edge1[1]);
#include STSTEM_WARNING_POP

    if (Math::FAbs(Vector3DTools::DotProduct(normal0, normal1)) < Math::GetValue(1) - Math::GetZeroTolerance())
    {
        // 三角形不平行。

        // 方向 M.

        intersectInfo = TestOverlap(normal1, tMax, relVelocity);
        tFirst = intersectInfo.m_TFirst;
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
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
                const auto dir = Vector3DTools::UnitCrossProduct(edge0[i0], edge1[i1]);
#include STSTEM_WARNING_POP

                intersectInfo = TestOverlap(dir, tMax, relVelocity);
                tFirst = intersectInfo.m_TFirst;
                if (!intersectInfo.m_Result)
                {
                    this->SetIntersectionType(IntersectionType::Empty);
                    return;
                }
            }
        }
        this->SetIntersectionType(IntersectionType::Other);
    }
    else  //  三角形是平行的（实际上是共面的）
    {
        // 方向 NxE[i0].
        for (auto i = 0; i < 3; ++i)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
            const auto dir = Vector3DTools::UnitCrossProduct(normal0, edge0[i]);
#include STSTEM_WARNING_POP

            intersectInfo = TestOverlap(dir, tMax, relVelocity);
            tFirst = intersectInfo.m_TFirst;
            if (!intersectInfo.m_Result)
            {
                this->SetIntersectionType(IntersectionType::Empty);
                return;
            }
        }

        // 方向 NxF[i1]
        for (auto i = 0; i < 3; ++i)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
            const auto dir = Vector3DTools::UnitCrossProduct(normal1, edge1[i]);
#include STSTEM_WARNING_POP

            intersectInfo = TestOverlap(dir, tMax, relVelocity);
            tFirst = intersectInfo.m_TFirst;
            if (!intersectInfo.m_Result)
            {
                this->SetIntersectionType(IntersectionType::Empty);
                return;
            }
        }
        this->SetIntersectionType(IntersectionType::Plane);
    }

    this->SetContactTime(tFirst);
}

template <typename Real>
typename Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>::IntersectInfo Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>::ProjectOntoAxis(const Triangle3& triangle, const Vector3D& axis)
{
    auto dot0 = Vector3DTools::DotProduct(axis, triangle.GetVertex(0));
    auto dot1 = Vector3DTools::DotProduct(axis, triangle.GetVertex(1));
    auto dot2 = Vector3DTools::DotProduct(axis, triangle.GetVertex(2));

    auto fMin = dot0;
    auto fMax = fMin;

    if (dot1 < fMin)
    {
        fMin = dot1;
    }
    else if (fMax < dot1)
    {
        fMax = dot1;
    }

    if (dot2 < fMin)
    {
        fMin = dot2;
    }
    else if (fMax < dot2)
    {
        fMax = dot2;
    }

    IntersectInfo intersectInfo{ true, fMin, fMax };

    return intersectInfo;
}

template <typename Real>
typename Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>::IntersectInfo Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>::TestOverlap(Real tMax, Real speed, Real uMin, Real uMax, Real vMin, Real vMax) noexcept
{
    // 等速分离轴测试。

    IntersectInfo intersectInfo{};

    if (vMax < uMin)  // V在U的左侧
    {
        if (speed <= Math::GetValue(0))  // V从U移开
        {
            return intersectInfo;
        }

        // 查找该轴上的首次接触。
        auto t = (uMin - vMax) / speed;
        if (intersectInfo.m_TFirst < t)
        {
            intersectInfo.m_TFirst = t;
        }

        // 快速退出：在所需的时间间隔后相交。
        if (tMax < intersectInfo.m_TFirst)
        {
            return intersectInfo;
        }

        // 查找该轴上的最后一次接触时间。
        t = (uMax - vMin) / speed;
        if (t < intersectInfo.m_TLast)
        {
            intersectInfo.m_TLast = t;
        }

        // 快速退出：在所需时间间隔之前相交。
        if (intersectInfo.m_TLast < intersectInfo.m_TFirst)
        {
            return intersectInfo;
        }
    }
    else if (uMax < vMin)  // V在U的右边
    {
        if (Math::GetValue(0) <= speed)  // V从U移开
        {
            return intersectInfo;
        }

        // 查找该轴上的首次接触。
        auto t = (uMax - vMin) / speed;
        if (intersectInfo.m_TFirst < t)
        {
            intersectInfo.m_TFirst = t;
        }

        // 快速退出：在所需的时间间隔后相义。
        if (tMax < intersectInfo.m_TFirst)
        {
            return intersectInfo;
        }

        // 查找该轴上的最后一次接触时间。
        t = (uMin - vMax) / speed;
        if (t < intersectInfo.m_TLast)
        {
            intersectInfo.m_TLast = t;
        }

        // 快速退出：在所需时间间隔之前相交。
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
            auto t = (uMax - vMin) / speed;
            if (t < intersectInfo.m_TLast)
            {
                intersectInfo.m_TLast = t;
            }

            // 快速退出：在所需时间间隔之前相交。
            if (intersectInfo.m_TLast < intersectInfo.m_TFirst)
            {
                return intersectInfo;
            }
        }
        else if (speed < Math::GetValue(0))
        {
            // F查找该轴上的最后一次接触时间。
            auto t = (uMin - vMax) / speed;
            if (t < intersectInfo.m_TLast)
            {
                intersectInfo.m_TLast = t;
            }

            // 快速退出：在所需时间间隔之前相交。
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
typename Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>::IntersectInfo Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>::TestOverlap(const Vector3D& axis, Real tMax, const Vector3D& velocity)
{
    const auto intersectInfo0 = ProjectOntoAxis(m_Triangle0, axis);
    const auto intersectInfo1 = ProjectOntoAxis(m_Triangle1, axis);
    auto speed = Vector3DTools::DotProduct(velocity, axis);

    return TestOverlap(tMax, speed, intersectInfo0.m_TFirst, intersectInfo0.m_TLast, intersectInfo1.m_TFirst, intersectInfo1.m_TLast);
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE3_TRIANGLE3_ACHIEVE_H