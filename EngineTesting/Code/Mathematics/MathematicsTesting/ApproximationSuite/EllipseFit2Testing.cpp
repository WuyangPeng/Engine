///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:14)

#include "EllipseFit2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Matrix2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Approximation/EllipseFit2Detail.h"
#include "Mathematics/Objects2D/Ellipse2Detail.h"

#include <random>

Mathematics::EllipseFit2Testing::EllipseFit2Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, EllipseFit2Testing)

void Mathematics::EllipseFit2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::EllipseFit2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::EllipseFit2Testing::FitTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution0(0.0, 100.0);
    const std::uniform_int<> randomDistribution1(5, 15);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<Vector2D> vertices;
        const int size = randomDistribution1(generator);

        for (int i = 0; i < size; ++i)
        {
            vertices.push_back(Vector2(randomDistribution0(generator), randomDistribution0(generator)));
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
