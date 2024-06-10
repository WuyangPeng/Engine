///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:12)

#include "Triangle2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Objects2D/Triangle2Detail.h"

#include <random>

namespace Mathematics
{
    template class Triangle2<float>;
    template class Triangle2<double>;
}

Mathematics::Triangle2Testing::Triangle2Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Triangle2Testing)

void Mathematics::Triangle2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Triangle2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TriangleTest);
}

void Mathematics::Triangle2Testing::TriangleTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution0{ -100.0, 100.0 };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2 point0(randomDistribution0(generator), randomDistribution0(generator));

        const Vector2 point1(randomDistribution0(generator), randomDistribution0(generator));

        const Vector2 point2(randomDistribution0(generator), randomDistribution0(generator));

        const Triangle2D triangle(point0, point1, point2);

        auto vertex = triangle.GetVertex();

        ASSERT_TRUE(Vector2ToolsD::Approximate(vertex.at(0), point0));
        ASSERT_TRUE(Vector2ToolsD::Approximate(vertex.at(1), point1));
        ASSERT_TRUE(Vector2ToolsD::Approximate(vertex.at(2), point2));

        const Vector2 fourthPoint(randomDistribution0(generator), randomDistribution0(generator));

        auto diff = point0 - fourthPoint;
        auto edge0 = point1 - point0;
        auto edge1 = point2 - point0;
        auto a00 = Vector2ToolsD::GetLengthSquared(edge0);
        auto a01 = Vector2ToolsD::DotProduct(edge0, edge1);
        auto a11 = Vector2ToolsD::GetLengthSquared(edge1);
        auto b0 = Vector2ToolsD::DotProduct(diff, edge0);
        auto b1 = Vector2ToolsD::DotProduct(diff, edge1);
        auto c = Vector2ToolsD::GetLengthSquared(diff);
        auto det = MathD::FAbs(a00 * a11 - a01 * a01);
        auto s = a01 * b1 - a11 * b0;
        auto t = a01 * b0 - a00 * b1;

        if (s + t <= det)
        {
            if (s < 0.0)
            {
                if (t < 0.0)
                {
                    if (b0 < 0.0)
                    {
                        if (-b0 >= a00)
                        {
                            ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), MathD::Sqrt(MathD::FAbs(a00 + 2.0 * b0 + c)), 1e-10);
                        }
                        else
                        {
                            ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), MathD::Sqrt(MathD::FAbs(c - b0 * b0 / a00)), 1e-10);
                        }
                    }
                    else
                    {
                        if (b1 >= 0.0)
                        {
                            ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), MathD::Sqrt(MathD::FAbs(c)), 1e-10);
                        }
                        else if (-b1 >= a11)
                        {
                            ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), MathD::Sqrt(MathD::FAbs(a11 + 2.0 * b1 + c)), 1e-10);
                        }
                        else
                        {
                            ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), MathD::Sqrt(MathD::FAbs(c - b1 * b1 / a11)), 1e-10);
                        }
                    }
                }
                else
                {
                    if (b1 >= 0.0)
                    {
                        ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), MathD::Sqrt(MathD::FAbs(c)), 1e-10);
                    }
                    else if (-b1 >= a11)
                    {
                        ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), MathD::Sqrt(MathD::FAbs(a11 + 2.0 * b1 + c)), 1e-10);
                    }
                    else
                    {
                        ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), MathD::Sqrt(MathD::FAbs(c - b1 * b1 / a11)), 1e-10);
                    }
                }
            }
            else if (t < 0.0)
            {
                if (b0 >= 0.0)
                {
                    ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), MathD::Sqrt(MathD::FAbs(c)), 1e-10);
                }
                else if (-b0 >= a00)
                {
                    ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), MathD::Sqrt(MathD::FAbs(a00 + 2.0 * b0 + c)), 1e-10);
                }
                else
                {
                    ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), MathD::Sqrt(MathD::FAbs(b0 * s + c - b0 * b0 / a00)), 1e-10);
                }
            }
            else
            {
                const auto invDet = 1.0 / det;
                s *= invDet;
                t *= invDet;

                ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), MathD::Sqrt(MathD::FAbs(s * (a00 * s + a01 * t + 2.0 * b0) + t * (a01 * s + a11 * t + 2.0 * b1) + c)), 1e-10);
            }
        }
        else
        {
            if (s < 0.0)
            {
                auto tmp0 = a01 + b0;
                auto tmp1 = a11 + b1;
                if (tmp1 > tmp0)
                {
                    auto numer = tmp1 - tmp0;
                    auto denom = a00 - 2.0 * a01 + a11;
                    if (numer >= denom)
                    {
                        ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), MathD::Sqrt(MathD::FAbs(a00 + 2.0 * b0 + c)), 1e-10);
                    }
                    else
                    {
                        s = numer / denom;
                        t = 1.0 - s;

                        ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), MathD::Sqrt(MathD::FAbs(s * (a00 * s + a01 * t + 2.0 * b0) + t * (a01 * s + a11 * t + 2.0 * b1) + c)), 1e-10);
                    }
                }
                else
                {
                    if (tmp1 <= 0.0)
                    {
                        ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), MathD::Sqrt(MathD::FAbs(a11 + 2.0 * b1 + c)), 1e-10);
                    }
                    else if (b1 >= 0.0)
                    {
                        ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), MathD::Sqrt(MathD::FAbs(c)), 1e-10);
                    }
                    else
                    {
                        ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), MathD::Sqrt(MathD::FAbs(c - b1 * b1 / a11)), 1e-10);
                    }
                }
            }
            else if (t < 0.0)
            {
                auto tmp0 = a01 + b1;
                auto tmp1 = a00 + b0;
                if (tmp1 > tmp0)
                {
                    auto numer = tmp1 - tmp0;
                    auto denom = a00 - 2.0 * a01 + a11;
                    if (numer >= denom)
                    {
                        t = 1.0;
                        s = 0.0;

                        ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), MathD::Sqrt(MathD::FAbs(a11 + 2.0 * b1 + c)), 1e-10);
                    }
                    else
                    {
                        t = numer / denom;
                        s = 1.0 - t;

                        ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
                                           MathD::Sqrt(MathD::FAbs(s * (a00 * s + a01 * t + 2.0 * b0) + t * (a01 * s + a11 * t + 2.0 * b1) + c)),
                                           1e-10);
                    }
                }
                else
                {
                    if (tmp1 <= 0.0)
                    {
                        ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
                                           MathD::Sqrt(MathD::FAbs(a00 + 2.0 * b0 + c)),
                                           1e-10);
                    }
                    else if (b0 >= 0.0)
                    {
                        ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
                                           MathD::Sqrt(MathD::FAbs(c)),
                                           1e-10);
                    }
                    else
                    {
                        ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
                                           MathD::Sqrt(MathD::FAbs(c - b0 * b0 / a00)),
                                           1e-10);
                    }
                }
            }
            else
            {
                const auto numer = a11 + b1 - a01 - b0;
                if (numer <= 0.0)
                {
                    ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
                                       MathD::Sqrt(MathD::FAbs(a11 + 2.0 * b1 + c)),
                                       1e-10);
                }
                else
                {
                    const auto denom = a00 - 2.0 * a01 + a11;
                    if (numer >= denom)
                    {
                        ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
                                           MathD::Sqrt(MathD::FAbs(a00 + 2.0 * b0 + c)),
                                           1e-10);
                    }
                    else
                    {
                        s = numer / denom;
                        t = 1.0 - s;

                        ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
                                           MathD::Sqrt(MathD::FAbs(s * (a00 * s + a01 * t + 2.0 * b0) + t * (a01 * s + a11 * t + 2.0 * b1) + c)),
                                           1e-10);
                    }
                }
            }
        }
    }
}
