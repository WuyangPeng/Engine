///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/31 11:40)

#include "Triangle3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Objects3D/Triangle3Detail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

using std::default_random_engine;
using std::uniform_real;
using std::vector;

namespace Mathematics
{
    template class Triangle3<float>;
    template class Triangle3<double>;
}

Mathematics::Triangle3Testing::Triangle3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Triangle3Testing)

void Mathematics::Triangle3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Triangle3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TriangleTest);
}

void Mathematics::Triangle3Testing::TriangleTest()
{
    default_random_engine generator{};

    const uniform_real<double> firstRandomDistribution(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D firstPoint(firstRandomDistribution(generator),
                                  firstRandomDistribution(generator),
                                  firstRandomDistribution(generator));

        const Vector3D secondPoint(firstRandomDistribution(generator),
                                   firstRandomDistribution(generator),
                                   firstRandomDistribution(generator));

        const Vector3D thirdPoint(firstRandomDistribution(generator),
                                  firstRandomDistribution(generator),
                                  firstRandomDistribution(generator));

        const Triangle3D triangle(firstPoint, secondPoint, thirdPoint);

        auto vertex = triangle.GetVertex();

        ASSERT_TRUE(Vector3ToolsD::Approximate(vertex.at(0), firstPoint));
        ASSERT_TRUE(Vector3ToolsD::Approximate(vertex.at(1), secondPoint));
        ASSERT_TRUE(Vector3ToolsD::Approximate(vertex.at(2), thirdPoint));

        const Vector3D fourthPoint(firstRandomDistribution(generator),
                                   firstRandomDistribution(generator),
                                   firstRandomDistribution(generator));

        auto diff = firstPoint - fourthPoint;
        auto edge0 = secondPoint - firstPoint;
        auto edge1 = thirdPoint - firstPoint;
        auto a00 = Vector3ToolsD::GetLengthSquared(edge0);
        auto a01 = Vector3ToolsD::DotProduct(edge0, edge1);
        auto a11 = Vector3ToolsD::GetLengthSquared(edge1);
        auto b0 = Vector3ToolsD::DotProduct(diff, edge0);
        auto b1 = Vector3ToolsD::DotProduct(diff, edge1);
        auto c = Vector3ToolsD::GetLengthSquared(diff);
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
                            ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
                                               MathD::Sqrt(MathD::FAbs(a00 + 2.0 * b0 + c)),
                                               1e-10);
                        }
                        else
                        {
                            ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
                                               MathD::Sqrt(MathD::FAbs(c - b0 * b0 / a00)),
                                               1e-10);
                        }
                    }
                    else
                    {
                        if (b1 >= 0.0)
                        {
                            ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
                                               MathD::Sqrt(MathD::FAbs(c)),
                                               1e-10);
                        }
                        else if (-b1 >= a11)
                        {
                            ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
                                               MathD::Sqrt(MathD::FAbs(a11 + 2.0 * b1 + c)),
                                               1e-10);
                        }
                        else
                        {
                            ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
                                               MathD::Sqrt(MathD::FAbs(c - b1 * b1 / a11)),
                                               1e-10);
                        }
                    }
                }
                else
                {
                    if (b1 >= 0.0)
                    {
                        ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
                                           MathD::Sqrt(MathD::FAbs(c)),
                                           1e-10);
                    }
                    else if (-b1 >= a11)
                    {
                        ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
                                           MathD::Sqrt(MathD::FAbs(a11 + 2.0 * b1 + c)),
                                           1e-10);
                    }
                    else
                    {
                        ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
                                           MathD::Sqrt(MathD::FAbs(c - b1 * b1 / a11)),
                                           1e-10);
                    }
                }
            }
            else if (t < 0.0)
            {
                if (b0 >= 0.0)
                {
                    ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
                                       MathD::Sqrt(MathD::FAbs(c)),
                                       1e-10);
                }
                else if (-b0 >= a00)
                {
                    ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
                                       MathD::Sqrt(MathD::FAbs(a00 + 2.0 * b0 + c)),
                                       1e-10);
                }
                else
                {
                    ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
                                       MathD::Sqrt(MathD::FAbs(b0 * s + c - b0 * b0 / a00)),
                                       1e-10);
                }
            }
            else
            {
                const auto invDet = 1.0 / det;
                s *= invDet;
                t *= invDet;

                ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
                                   MathD::Sqrt(MathD::FAbs(s * (a00 * s + a01 * t + 2.0 * b0) + t * (a01 * s + a11 * t + 2.0 * b1) + c)),
                                   1e-10);
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

                        ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint),
                                           MathD::Sqrt(MathD::FAbs(s * (a00 * s + a01 * t + 2.0 * b0) + t * (a01 * s + a11 * t + 2.0 * b1) + c)),
                                           1e-10);
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
                        ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), MathD::Sqrt(MathD::FAbs(c)), 1e-10);
                    }
                    else
                    {
                        ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), MathD::Sqrt(MathD::FAbs(c - b0 * b0 / a00)), 1e-10);
                    }
                }
            }
            else
            {
                auto numer = a11 + b1 - a01 - b0;
                if (numer <= 0.0)
                {
                    ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), MathD::Sqrt(MathD::FAbs(a11 + 2.0 * b1 + c)), 1e-10);
                }
                else
                {
                    auto denom = a00 - 2.0 * a01 + a11;
                    if (numer >= denom)
                    {
                        ASSERT_APPROXIMATE(triangle.DistanceTo(fourthPoint), MathD::Sqrt(MathD::FAbs(a00 + 2.0 * b0 + c)), 1e-10);
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
