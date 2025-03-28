///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:30)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_CYLINDER3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_CYLINDER3_DETAIL_H

#include "StaticTestIntersectorTriangle3Cylinder3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorTriangle3Cylinder3<Real>::StaticTestIntersectorTriangle3Cylinder3(const Triangle3& triangle, const Cylinder3& cylinder, const Real epsilon)
    : ParentType{ epsilon }, triangle{ triangle }, cylinder{ cylinder }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorTriangle3Cylinder3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Triangle3<Real> Mathematics::StaticTestIntersectorTriangle3Cylinder3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return triangle;
}

template <typename Real>
Mathematics::Cylinder3<Real> Mathematics::StaticTestIntersectorTriangle3Cylinder3<Real>::GetCylinder() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return cylinder;
}

template <typename Real>
void Mathematics::StaticTestIntersectorTriangle3Cylinder3<Real>::Test()
{
    const auto vector3OrthonormalBasis = Vector3Tools::GenerateComplementBasis(cylinder.GetAxis().GetDirection());
    const auto u = vector3OrthonormalBasis.GetUVector();
    const auto v = vector3OrthonormalBasis.GetVVector();

    std::array<Vector3, 3> temp{};

    for (auto i = 0; i < 3; ++i)
    {
        auto delta = triangle.GetVertex(i) - cylinder.GetAxis().GetOrigin();
        temp.at(i)[0] = Vector3Tools::DotProduct(u, delta);
        temp.at(i)[1] = Vector3Tools::DotProduct(v, delta);
        temp.at(i)[2] = Vector3Tools::DotProduct(cylinder.GetAxis().GetDirection(), delta);
    }

    auto j0 = 0;
    auto j1 = 0;
    auto j2 = 0;
    if (temp.at(0)[2] < temp.at(1)[2])
    {
        if (temp.at(2)[2] < temp.at(0)[2])
        {
            j0 = 2;
            j1 = 0;
            j2 = 1;
        }
        else if (temp.at(2)[2] < temp.at(1)[2])
        {
            j0 = 0;
            j1 = 2;
            j2 = 1;
        }
        else
        {
            j0 = 0;
            j1 = 1;
            j2 = 2;
        }
    }
    else
    {
        if (temp.at(2)[2] < temp.at(1)[2])
        {
            j0 = 2;
            j1 = 1;
            j2 = 0;
        }
        else if (temp.at(2)[2] < temp.at(0)[2])
        {
            j0 = 1;
            j1 = 2;
            j2 = 0;
        }
        else
        {
            j0 = 1;
            j1 = 0;
            j2 = 2;
        }
    }

    std::array<Vector2Type, 3> q{ Vector2{ temp.at(j0)[0], temp.at(j0)[1] },
                                  Vector2{ temp.at(j1)[0], temp.at(j1)[1] },
                                  Vector2{ temp.at(j2)[0], temp.at(j2)[1] } };

    std::array<Real, 3> z{ temp.at(j0)[2], temp.at(j1)[2], temp.at(j2)[2] };

    const auto hhalf = MathType::GetRational(1, 2) * cylinder.GetHeight();
    if (z.at(2) < -hhalf || hhalf < z.at(0))
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    if (-hhalf <= z.at(0) && z.at(2) <= hhalf)
    {
        if (DiskOverlapsPolygon({ q.at(0), q.at(1), q.at(2) }))
        {
            this->SetIntersectionType(IntersectionType::Other);
        }
        else
        {
            this->SetIntersectionType(IntersectionType::Empty);
        }

        return;
    }

    std::array<Vector2Type, 5> polygon{};

    if (z.at(0) < -hhalf)
    {
        if (hhalf < z.at(2))
        {
            if (hhalf <= z.at(1))
            {
                auto numer0 = -hhalf - z.at(0);
                auto numer1 = +hhalf - z.at(0);
                auto invDenom0 = MathType::GetValue(1) / (z.at(1) - z.at(0));
                auto invDenom1 = MathType::GetValue(1) / (z.at(2) - z.at(0));
                auto t = numer0 * invDenom1;
                polygon.at(0) = q.at(0) + t * (q.at(2) - q.at(0));
                t = numer0 * invDenom0;
                polygon.at(1) = q.at(0) + t * (q.at(1) - q.at(0));
                t = numer1 * invDenom0;
                polygon.at(2) = q.at(0) + t * (q.at(1) - q.at(0));
                t = numer1 * invDenom1;
                polygon.at(3) = q.at(0) + t * (q.at(2) - q.at(0));
                if (DiskOverlapsPolygon({ polygon.at(0), polygon.at(1), polygon.at(2), polygon.at(3) }))
                {
                    this->SetIntersectionType(IntersectionType::Other);
                }
                else
                {
                    this->SetIntersectionType(IntersectionType::Empty);
                }

                return;
            }
            else if (z.at(1) <= -hhalf)
            {
                auto numer0 = -hhalf - z.at(2);
                auto numer1 = +hhalf - z.at(2);
                auto invDenom0 = (MathType::GetValue(1)) / (z.at(1) - z.at(2));
                auto invDenom1 = (MathType::GetValue(1)) / (z.at(0) - z.at(2));
                auto t = numer0 * invDenom1;
                polygon.at(0) = q.at(2) + t * (q.at(0) - q.at(2));
                t = numer0 * invDenom0;
                polygon.at(1) = q.at(2) + t * (q.at(1) - q.at(2));
                t = numer1 * invDenom0;
                polygon.at(2) = q.at(2) + t * (q.at(1) - q.at(2));
                t = numer1 * invDenom1;
                polygon.at(3) = q.at(2) + t * (q.at(0) - q.at(2));
                if (DiskOverlapsPolygon({ polygon.at(0), polygon.at(1), polygon.at(2), polygon.at(3) }))
                {
                    this->SetIntersectionType(IntersectionType::Other);
                }
                else
                {
                    this->SetIntersectionType(IntersectionType::Empty);
                }

                return;
            }
            else
            {
                auto numer0 = -hhalf - z.at(0);
                auto numer1 = +hhalf - z.at(0);
                auto invDenom0 = (MathType::GetValue(1)) / (z.at(1) - z.at(0));
                auto invDenom1 = (MathType::GetValue(1)) / (z.at(2) - z.at(0));
                auto t = numer0 * invDenom1;
                polygon.at(0) = q.at(0) + t * (q.at(2) - q.at(0));
                t = numer0 * invDenom0;
                polygon.at(1) = q.at(0) + t * (q.at(1) - q.at(0));
                t = numer1 * invDenom0;
                polygon.at(2) = q.at(1);
                polygon.at(3) = q.at(0) + t * (q.at(1) - q.at(0));
                t = numer1 * invDenom1;
                polygon.at(4) = q.at(0) + t * (q.at(2) - q.at(0));
                if (DiskOverlapsPolygon({ polygon.at(0), polygon.at(1), polygon.at(2), polygon.at(3), polygon.at(4) }))
                {
                    this->SetIntersectionType(IntersectionType::Other);
                }
                else
                {
                    this->SetIntersectionType(IntersectionType::Empty);
                }

                return;
            }
        }
        else if (-hhalf < z.at(2))
        {
            if (z.at(1) <= -hhalf)
            {
                auto numer0 = -hhalf - z.at(2);
                auto invDenom0 = MathType::GetValue(1) / (z.at(1) - z.at(2));
                auto invDenom1 = MathType::GetValue(1) / (z.at(0) - z.at(2));
                auto t = numer0 * invDenom0;
                polygon.at(0) = q.at(2) + t * (q.at(1) - q.at(2));
                t = numer0 * invDenom1;
                polygon.at(1) = q.at(2) + t * (q.at(0) - q.at(2));
                polygon.at(2) = q.at(2);
                if (DiskOverlapsPolygon({ polygon.at(0), polygon.at(1), polygon.at(2) }))
                {
                    this->SetIntersectionType(IntersectionType::Other);
                }
                else
                {
                    this->SetIntersectionType(IntersectionType::Empty);
                }

                return;
            }
            else
            {
                auto numer0 = -hhalf - z.at(0);
                auto invDenom0 = (MathType::GetValue(1)) / (z.at(2) - z.at(0));
                auto invDenom1 = (MathType::GetValue(1)) / (z.at(1) - z.at(0));
                auto t = numer0 * invDenom0;
                polygon.at(0) = q.at(0) + t * (q.at(2) - q.at(0));
                t = numer0 * invDenom1;
                polygon.at(1) = q.at(0) + t * (q.at(1) - q.at(0));
                polygon.at(2) = q.at(1);
                polygon.at(3) = q.at(2);
                if (DiskOverlapsPolygon({ polygon.at(0), polygon.at(1), polygon.at(2), polygon.at(3) }))
                {
                    this->SetIntersectionType(IntersectionType::Other);
                }
                else
                {
                    this->SetIntersectionType(IntersectionType::Empty);
                }

                return;
            }
        }
        else
        {
            if (z.at(1) < -hhalf)
            {
                if (DiskOverlapsPoint(q.at(2)))
                {
                    this->SetIntersectionType(IntersectionType::Other);
                }
                else
                {
                    this->SetIntersectionType(IntersectionType::Empty);
                }

                return;
            }
            else
            {
                if (DiskOverlapsSegment(q.at(2), q.at(1)))
                {
                    this->SetIntersectionType(IntersectionType::Other);
                }
                else
                {
                    this->SetIntersectionType(IntersectionType::Empty);
                }

                return;
            }
        }
    }
    else if (z.at(0) < hhalf)
    {
        if (hhalf <= z.at(1))
        {
            auto numer0 = -hhalf - z.at(0);
            auto invDenom0 = (MathType::GetValue(1)) / (z.at(2) - z.at(0));
            auto invDenom1 = (MathType::GetValue(1)) / (z.at(1) - z.at(0));
            auto t = numer0 * invDenom0;
            polygon.at(0) = q.at(0) + t * (q.at(2) - q.at(0));
            t = numer0 * invDenom1;
            polygon.at(1) = q.at(0) + t * (q.at(1) - q.at(0));
            polygon.at(2) = q.at(0);
            if (DiskOverlapsPolygon({ polygon.at(0), polygon.at(1), polygon.at(2) }))
            {
                this->SetIntersectionType(IntersectionType::Other);
            }
            else
            {
                this->SetIntersectionType(IntersectionType::Empty);
            }

            return;
        }
        else
        {
            auto numer0 = -hhalf - z.at(2);
            auto invDenom0 = (MathType::GetValue(1)) / (z.at(1) - z.at(2));
            auto invDenom1 = (MathType::GetValue(1)) / (z.at(0) - z.at(2));
            auto t = numer0 * invDenom0;
            polygon.at(0) = q.at(2) + t * (q.at(1) - q.at(2));
            t = numer0 * invDenom1;
            polygon.at(1) = q.at(2) + t * (q.at(0) - q.at(2));
            polygon.at(2) = q.at(0);
            polygon.at(3) = q.at(1);
            if (DiskOverlapsPolygon({ polygon.at(0), polygon.at(1), polygon.at(2), polygon.at(3) }))
            {
                this->SetIntersectionType(IntersectionType::Other);
            }
            else
            {
                this->SetIntersectionType(IntersectionType::Empty);
            }

            return;
        }
    }
    else
    {
        if (hhalf < z.at(1))
        {
            if (DiskOverlapsPoint(q.at(0)))
            {
                this->SetIntersectionType(IntersectionType::Other);
            }
            else
            {
                this->SetIntersectionType(IntersectionType::Empty);
            }

            return;
        }
        else
        {
            if (DiskOverlapsSegment(q.at(0), q.at(1)))
            {
                this->SetIntersectionType(IntersectionType::Other);
            }
            else
            {
                this->SetIntersectionType(IntersectionType::Empty);
            }

            return;
        }
    }
}

template <typename Real>
bool Mathematics::StaticTestIntersectorTriangle3Cylinder3<Real>::DiskOverlapsPoint(const Vector2Type& q) const
{
    return q[0] * q[0] + q[1] * q[1] <= cylinder.GetRadius() * cylinder.GetRadius();
}

template <typename Real>
bool Mathematics::StaticTestIntersectorTriangle3Cylinder3<Real>::DiskOverlapsSegment(const Vector2Type& q0, const Vector2Type& q1) const
{
    auto rSqr = cylinder.GetRadius() * cylinder.GetRadius();
    auto D = q0 - q1;
    auto dot = Vector2Tools<Real>::DotProduct(q0, D);
    if (dot <= MathType::GetValue(0))
    {
        return Vector2Tools<Real>::DotProduct(q0, q0) <= rSqr;
    }

    auto lenSqr = Vector2Tools<Real>::DotProduct(D, D);
    if (dot >= lenSqr)
    {
        return Vector2Tools<Real>::DotProduct(q1, q1) <= rSqr;
    }

    dot = Vector2Tools<Real>::DotPerp(D, q0);
    return dot * dot <= lenSqr * rSqr;
}

template <typename Real>
bool Mathematics::StaticTestIntersectorTriangle3Cylinder3<Real>::DiskOverlapsPolygon(const std::vector<Vector2Type>& q) const
{
    auto positive = 0;
    auto negative = 0;

    auto numVertices = boost::numeric_cast<int>(q.size());
    for (auto i0 = numVertices - 1, i1 = 0; i1 < numVertices; i0 = i1++)
    {
        auto dot = Vector2Tools<Real>::DotPerp(q.at(i0), (q.at(i0) - q.at(i1)));
        if (MathType::GetValue(0) < dot)
        {
            ++positive;
        }
        else if (dot < MathType::GetValue(0))
        {
            ++negative;
        }
    }
    if (positive == 0 || negative == 0)
    {
        return true;
    }

    for (auto i0 = numVertices - 1, i1 = 0; i1 < numVertices; i0 = i1++)
    {
        if (DiskOverlapsSegment(q.at(i0), q.at(i1)))
        {
            return true;
        }
    }

    return false;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_CYLINDER3_DETAIL_H