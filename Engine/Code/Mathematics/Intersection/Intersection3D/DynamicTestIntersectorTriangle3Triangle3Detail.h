///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 18:18)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE3_TRIANGLE3_DETAIL_H

#include "DynamicTestIntersectorTriangle3Triangle3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>::DynamicTestIntersectorTriangle3Triangle3(const Triangle3Type& triangle0, const Triangle3Type& triangle1, Real tMax, const Vector3Type& lhsVelocity, const Vector3Type& rhsVelocity, const Real epsilon)
    : ParentType{ tMax, lhsVelocity, rhsVelocity, epsilon }, triangle0{ triangle0 }, triangle1{ triangle1 }
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
Mathematics::Triangle3<Real> Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>::GetTriangle0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle0;
}

template <typename Real>
Mathematics::Triangle3<Real> Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>::GetTriangle1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle1;
}

template <typename Real>
Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>::IntersectInfo::IntersectInfo() noexcept
    : result{}, tFirst{}, tLast{ MathType::maxReal }
{
}

template <typename Real>
Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>::IntersectInfo::IntersectInfo(bool result, Real tFirst, Real tLast) noexcept
    : result{ result }, tFirst{ tFirst }, tLast{ tLast }
{
}

template <typename Real>
void Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>::Test()
{
    auto tMax = this->GetTMax();
    const auto velocity0 = this->GetLhsVelocity();
    const auto velocity1 = this->GetRhsVelocity();
    auto tFirst = MathType::GetValue(0);

    // 相对于三角形0的速度。
    auto relVelocity = velocity1 - velocity0;

    // 计算三角形0的边缘和法线方向。
    using TriangleType = std::array<Vector3Type, 3>;
    TriangleType edge0{ triangle0.GetVertex(1) - triangle0.GetVertex(0),
                        triangle0.GetVertex(2) - triangle0.GetVertex(1),
                        triangle0.GetVertex(0) - triangle0.GetVertex(2) };

    const auto normal0 = Vector3ToolsType::UnitCrossProduct(edge0.at(0), edge0.at(1));

    auto intersectInfo = TestOverlap(normal0, tMax, relVelocity);
    tFirst = intersectInfo.tFirst;
    if (!intersectInfo.result)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // 计算三角形1的边缘和法线方向。
    TriangleType edge1{ triangle1.GetVertex(1) - triangle1.GetVertex(0),
                        triangle1.GetVertex(2) - triangle1.GetVertex(1),
                        triangle1.GetVertex(0) - triangle1.GetVertex(2) };

    const auto normal1 = Vector3ToolsType::UnitCrossProduct(edge1.at(0), edge1.at(1));

    if (MathType::FAbs(Vector3ToolsType::DotProduct(normal0, normal1)) < MathType::GetValue(1) - MathType::GetZeroTolerance())
    {
        // 三角形不平行。

        // 方向 M.

        intersectInfo = TestOverlap(normal1, tMax, relVelocity);
        tFirst = intersectInfo.tFirst;
        if (!intersectInfo.result)
        {
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }

        // 方向 E[i0]xF[i1].
        for (auto i1 = 0; i1 < 3; ++i1)
        {
            for (auto i0 = 0; i0 < 3; ++i0)
            {
                const auto dir = Vector3ToolsType::UnitCrossProduct(edge0.at(i0), edge1.at(i1));

                intersectInfo = TestOverlap(dir, tMax, relVelocity);
                tFirst = intersectInfo.tFirst;
                if (!intersectInfo.result)
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
            const auto dir = Vector3ToolsType::UnitCrossProduct(normal0, edge0.at(i));

            intersectInfo = TestOverlap(dir, tMax, relVelocity);
            tFirst = intersectInfo.tFirst;
            if (!intersectInfo.result)
            {
                this->SetIntersectionType(IntersectionType::Empty);
                return;
            }
        }

        // 方向 NxF[i1]
        for (auto i = 0; i < 3; ++i)
        {
            const auto dir = Vector3ToolsType::UnitCrossProduct(normal1, edge1.at(i));

            intersectInfo = TestOverlap(dir, tMax, relVelocity);
            tFirst = intersectInfo.tFirst;
            if (!intersectInfo.result)
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
typename Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>::IntersectInfo Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>::ProjectOntoAxis(const Triangle3Type& triangle, const Vector3Type& axis)
{
    auto dot0 = Vector3ToolsType::DotProduct(axis, triangle.GetVertex(0));
    auto dot1 = Vector3ToolsType::DotProduct(axis, triangle.GetVertex(1));
    auto dot2 = Vector3ToolsType::DotProduct(axis, triangle.GetVertex(2));

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
        if (speed <= MathType::GetValue(0))  // V从U移开
        {
            return intersectInfo;
        }

        // 查找该轴上的首次接触。
        auto t = (uMin - vMax) / speed;
        if (intersectInfo.tFirst < t)
        {
            intersectInfo.tFirst = t;
        }

        // 快速退出：在所需的时间间隔后相交。
        if (tMax < intersectInfo.tFirst)
        {
            return intersectInfo;
        }

        // 查找该轴上的最后一次接触时间。
        t = (uMax - vMin) / speed;
        if (t < intersectInfo.tLast)
        {
            intersectInfo.tLast = t;
        }

        // 快速退出：在所需时间间隔之前相交。
        if (intersectInfo.tLast < intersectInfo.tFirst)
        {
            return intersectInfo;
        }
    }
    else if (uMax < vMin)  // V在U的右边
    {
        if (MathType::GetValue(0) <= speed)  // V从U移开
        {
            return intersectInfo;
        }

        // 查找该轴上的首次接触。
        auto t = (uMax - vMin) / speed;
        if (intersectInfo.tFirst < t)
        {
            intersectInfo.tFirst = t;
        }

        // 快速退出：在所需的时间间隔后相义。
        if (tMax < intersectInfo.tFirst)
        {
            return intersectInfo;
        }

        // 查找该轴上的最后一次接触时间。
        t = (uMin - vMax) / speed;
        if (t < intersectInfo.tLast)
        {
            intersectInfo.tLast = t;
        }

        // 快速退出：在所需时间间隔之前相交。
        if (intersectInfo.tLast < intersectInfo.tFirst)
        {
            return intersectInfo;
        }
    }
    else  // 重叠间隔上的V和U
    {
        if (MathType::GetValue(0) < speed)
        {
            // 查找该轴上的最后一次接触时间。
            auto t = (uMax - vMin) / speed;
            if (t < intersectInfo.tLast)
            {
                intersectInfo.tLast = t;
            }

            // 快速退出：在所需时间间隔之前相交。
            if (intersectInfo.tLast < intersectInfo.tFirst)
            {
                return intersectInfo;
            }
        }
        else if (speed < MathType::GetValue(0))
        {
            // F查找该轴上的最后一次接触时间。
            auto t = (uMin - vMax) / speed;
            if (t < intersectInfo.tLast)
            {
                intersectInfo.tLast = t;
            }

            // 快速退出：在所需时间间隔之前相交。
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
typename Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>::IntersectInfo Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>::TestOverlap(const Vector3Type& axis, Real tMax, const Vector3Type& velocity)
{
    const auto intersectInfo0 = ProjectOntoAxis(triangle0, axis);
    const auto intersectInfo1 = ProjectOntoAxis(triangle1, axis);
    auto speed = Vector3ToolsType::DotProduct(velocity, axis);

    return TestOverlap(tMax, speed, intersectInfo0.tFirst, intersectInfo0.tLast, intersectInfo1.tFirst, intersectInfo1.tLast);
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE3_TRIANGLE3_DETAIL_H