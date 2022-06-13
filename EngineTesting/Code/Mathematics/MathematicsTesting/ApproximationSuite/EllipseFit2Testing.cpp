///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 15:45)

#include "EllipseFit2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Approximation/EllipseFit2Detail.h"
#include "Mathematics/Objects2D/Ellipse2Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, EllipseFit2Testing)

void Mathematics::EllipseFit2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::EllipseFit2Testing::FitTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(0.0, 100.0);
    const uniform_int<> secondRandomDistribution(5, 15);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<Vector2D> vertices;
        const int size = secondRandomDistribution(generator);

        for (int i = 0; i < size; ++i)
        {
            vertices.push_back(Vector2(firstRandomDistribution(generator), firstRandomDistribution(generator)));
        }

        EllipseFit2D ellipseFit(vertices);

        const Vector2 center = ellipseFit.GetCenter();
        const Matrix2D matrix = ellipseFit.GetRotate();
        const double firstExtent = ellipseFit.GetExtent0();
        const double secondExtent = ellipseFit.GetExtent1();

        const Ellipse2D ellipse(center, matrix * Vector2D::GetUnitX(), matrix * Vector2D::GetUnitY(), firstExtent, secondExtent);

        for (int i = 0; i < size; ++i)
        {
            ASSERT_LESS(ellipse.Evaluate(vertices.at(i)), 22.0);
        }
    }
}
