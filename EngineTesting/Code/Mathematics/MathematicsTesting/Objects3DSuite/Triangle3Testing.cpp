///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 16:21)

#include "Triangle3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Objects3D/Triangle3Detail.h"

#include <random>

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
    std::default_random_engine generator{ GetEngineRandomSeed() };

    const std::uniform_real<double> randomDistribution0(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D point0(randomDistribution0(generator),
                              randomDistribution0(generator),
                              randomDistribution0(generator));

        const Vector3D point1(randomDistribution0(generator),
                              randomDistribution0(generator),
                              randomDistribution0(generator));

        const Vector3D point2(randomDistribution0(generator),
                              randomDistribution0(generator),
                              randomDistribution0(generator));

        const Triangle3D triangle(point0, point1, point2);

        auto vertex = triangle.GetVertex();

        ASSERT_TRUE(Vector3ToolsD::Approximate(vertex.at(0), point0));
        ASSERT_TRUE(Vector3ToolsD::Approximate(vertex.at(1), point1));
        ASSERT_TRUE(Vector3ToolsD::Approximate(vertex.at(2), point2));

        const Vector3D fourthPoint(randomDistribution0(generator),
                                   randomDistribution0(generator),
                                   randomDistribution0(generator));

        auto diff = point0 - fourthPoint;
        auto edge0 = point1 - point0;
        auto edge1 = point2 - point0;
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
