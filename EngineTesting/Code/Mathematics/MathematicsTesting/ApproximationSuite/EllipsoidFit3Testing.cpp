///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:15)

#include "EllipsoidFit3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Approximation/EllipsoidFit3Detail.h"
#include "Mathematics/Objects3D/Box3Detail.h"
#include "Mathematics/Objects3D/Ellipsoid3Detail.h"

#include <random>

Mathematics::EllipsoidFit3Testing::EllipsoidFit3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, EllipsoidFit3Testing)

void Mathematics::EllipsoidFit3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::EllipsoidFit3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::EllipsoidFit3Testing::FitTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution0(0.0, 100.0);
    const std::uniform_int<> randomDistribution1(15, 20);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<Vector3D> vertices;
        const int size = randomDistribution1(generator);

        for (int i = 0; i < size; ++i)
        {
            vertices.push_back(Vector3D(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator)));
        }

        EllipsoidFit3D ellipseFit(vertices);

        const Vector3D center = ellipseFit.GetCenter();
        const Matrix3D matrix = ellipseFit.GetRotate();
        const double firstExtent = ellipseFit.GetExtent0();
        const double secondExtent = ellipseFit.GetExtent1();
        const double thirdExtent = ellipseFit.GetExtent2();

        const Ellipsoid3D ellipsoid(center, matrix * Vector3D::GetUnitX(), matrix * Vector3D::GetUnitY(), matrix * Vector3D::GetUnitZ(), firstExtent, secondExtent, thirdExtent);

        for (int i = 0; i < size; ++i)
        {
            ASSERT_LESS(ellipsoid.Evaluate(vertices.at(i)), 22.0);
        }
    }
}
