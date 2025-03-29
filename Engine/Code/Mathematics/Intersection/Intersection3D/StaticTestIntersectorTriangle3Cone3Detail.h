///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:29)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_CONE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_CONE3_DETAIL_H

#include "StaticTestIntersectorTriangle3Cone3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersectorTriangle3Cone3<Real>::StaticTestIntersectorTriangle3Cone3(const Triangle3Type& triangle, const Cone3Type& cone, const Real epsilon)
    : ParentType{ epsilon }, triangle{ triangle }, cone{ cone }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorTriangle3Cone3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Triangle3<Real> Mathematics::StaticTestIntersectorTriangle3Cone3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return triangle;
}

template <typename Real>
Mathematics::Cone3<Real> Mathematics::StaticTestIntersectorTriangle3Cone3<Real>::GetCone() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return cone;
}

template <typename Real>
void Mathematics::StaticTestIntersectorTriangle3Cone3<Real>::Test()
{
    auto onConeSide = 0;
    Real p0Test{};
    Real p1Test{};
    Real p2Test{};

    auto cosSqr = cone.GetCosAngle() * cone.GetCosAngle();

    auto diff0 = triangle.GetVertex(0) - cone.GetVertex();
    auto add0 = Vector3ToolsType::DotProduct(cone.GetAxis(), diff0);
    if (MathType::GetValue(0) <= add0)
    {
        p0Test = add0 * add0 - cosSqr * (Vector3ToolsType::DotProduct(diff0, diff0));
        if (MathType::GetValue(0) <= p0Test)
        {
            this->SetIntersectionType(IntersectionType::Other);
            return;
        }
        else
        {
            onConeSide |= 1;
        }
    }

    auto edge0 = triangle.GetVertex(1) - triangle.GetVertex(0);
    auto diff1 = diff0 + edge0;
    auto add1 = Vector3ToolsType::DotProduct(cone.GetAxis(), diff1);
    if (MathType::GetValue(0) <= add1)
    {
        p1Test = add1 * add1 - cosSqr * (Vector3ToolsType::DotProduct(diff1, diff1));
        if (MathType::GetValue(0) <= p1Test)
        {
            this->SetIntersectionType(IntersectionType::Other);
            return;
        }
        else
        {
            onConeSide |= 2;
        }
    }

    auto edge1 = triangle.GetVertex(2) - triangle.GetVertex(0);
    auto diff2 = diff0 + edge1;
    auto add2 = Vector3ToolsType::DotProduct(cone.GetAxis(), diff2);
    if (MathType::GetValue(0) <= add2)
    {
        p2Test = add2 * add2 - cosSqr * (Vector3ToolsType::DotProduct(diff2, diff2));
        if (MathType::GetValue(0) <= p2Test)
        {
            this->SetIntersectionType(IntersectionType::Other);
            return;
        }
        else
        {
            onConeSide |= 4;
        }
    }

    if (onConeSide & 3)
    {
        auto ade = add1 - add0;
        auto ede = Vector3ToolsType::DotProduct(edge0, edge0);
        auto c2 = ade * ade - cosSqr * ede;
        if (c2 < MathType::GetValue(0))
        {
            auto edd = Vector3ToolsType::DotProduct(edge0, diff0);
            auto c1 = ade * add0 - cosSqr * edd;
            if (onConeSide & 1)
            {
                if (onConeSide & 2)
                {
                    if (MathType::GetValue(0) <= c1 && c1 <= -c2 && p0Test * c2 <= c1 * c1)
                    {
                        this->SetIntersectionType(IntersectionType::Other);
                        return;
                    }
                }
                else
                {
                    if (MathType::GetValue(0) <= c1 && c2 * add0 <= c1 * ade && p0Test * c2 <= c1 * c1)
                    {
                        this->SetIntersectionType(IntersectionType::Other);
                        return;
                    }
                }
            }
            else
            {
                if (c1 <= -c2 && c2 * add0 <= c1 * ade)
                {
                    p0Test = add0 * add0 - cosSqr * (Vector3ToolsType::DotProduct(diff0, diff0));
                    if (p0Test * c2 <= c1 * c1)
                    {
                        this->SetIntersectionType(IntersectionType::Other);
                        return;
                    }
                }
            }
        }
    }

    if (onConeSide & 5)
    {
        auto ade = add2 - add0;
        auto ede = Vector3ToolsType::DotProduct(edge1, edge1);
        auto c2 = ade * ade - cosSqr * ede;
        if (c2 < MathType::GetValue(0))
        {
            auto edd = Vector3ToolsType::DotProduct(edge1, diff0);
            auto c1 = ade * add0 - cosSqr * edd;
            if (onConeSide & 1)
            {
                if (onConeSide & 4)
                {
                    if (MathType::GetValue(0) <= c1 && c1 <= -c2 && p0Test * c2 <= c1 * c1)
                    {
                        this->SetIntersectionType(IntersectionType::Other);
                        return;
                    }
                }
                else
                {
                    if (MathType::GetValue(0) <= c1 && c2 * add0 <= c1 * ade && p0Test * c2 <= c1 * c1)
                    {
                        this->SetIntersectionType(IntersectionType::Other);
                        return;
                    }
                }
            }
            else
            {
                if (c1 <= -c2 && c2 * add0 <= c1 * ade)
                {
                    p0Test = add0 * add0 - cosSqr * (Vector3ToolsType::DotProduct(diff0, diff0));
                    if (c1 * c1 >= p0Test * c2)
                    {
                        this->SetIntersectionType(IntersectionType::Other);
                        return;
                    }
                }
            }
        }
    }

    if (onConeSide & 6)
    {
        auto ke2 = edge1 - edge0;
        auto ade = add2 - add1;
        auto ede = Vector3ToolsType::DotProduct(ke2, ke2);
        auto c2 = ade * ade - cosSqr * ede;
        if (c2 < MathType::GetValue(0))
        {
            auto edd = Vector3ToolsType::DotProduct(ke2, diff1);
            auto c1 = ade * add1 - cosSqr * edd;
            if (onConeSide & 2)
            {
                if (onConeSide & 4)
                {
                    if (MathType::GetValue(0) <= c1 && c1 <= -c2 && p1Test * c2 <= c1 * c1)
                    {
                        this->SetIntersectionType(IntersectionType::Other);
                        return;
                    }
                }
                else
                {
                    if (MathType::GetValue(0) <= c1 && c2 * add1 <= c1 * ade && p1Test * c2 <= c1 * c1)
                    {
                        this->SetIntersectionType(IntersectionType::Other);
                        return;
                    }
                }
            }
            else
            {
                if (c1 <= -c2 && c2 * add1 <= c1 * ade)
                {
                    p1Test = add1 * add1 - cosSqr * (Vector3ToolsType::DotProduct(diff1, diff1));
                    if (p1Test * c2 <= c1 * c1)
                    {
                        this->SetIntersectionType(IntersectionType::Other);
                        return;
                    }
                }
            }
        }
    }

    if (0 < onConeSide)
    {
        const auto n = Vector3ToolsType::CrossProduct(edge0, edge1);
        const auto nda = Vector3ToolsType::DotProduct(n, cone.GetAxis());
        const auto ndd = Vector3ToolsType::DotProduct(n, diff0);
        const auto u = ndd * cone.GetAxis() - nda * diff0;
        const auto ncu = Vector3ToolsType::CrossProduct(n, u);

        const auto ncude0 = Vector3ToolsType::DotProduct(ncu, edge0);

        if (MathType::GetValue(0) <= nda)
        {
            if (ncude0 <= MathType::GetValue(0))
            {
                auto ncude1 = Vector3ToolsType::DotProduct(ncu, edge1);
                if (MathType::GetValue(0) <= ncude1)
                {
                    auto ncude2 = ncude1 - ncude0;
                    auto ndn = Vector3ToolsType::GetLengthSquared(n);
                    if (ncude2 <= nda * ndn)
                    {
                        this->SetIntersectionType(IntersectionType::Other);
                        return;
                    }
                }
            }
        }
        else
        {
            if (MathType::GetValue(0) <= ncude0)
            {
                auto ncude1 = Vector3ToolsType::DotProduct(ncu, edge1);
                if (ncude1 <= MathType::GetValue(0))
                {
                    auto ncude2 = ncude1 - ncude0;
                    auto ndn = Vector3ToolsType::GetLengthSquared(n);
                    if (ncude2 >= nda * ndn)
                    {
                        this->SetIntersectionType(IntersectionType::Other);
                        return;
                    }
                }
            }
        }
    }

    this->SetIntersectionType(IntersectionType::Empty);
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_CONE3_DETAIL_H