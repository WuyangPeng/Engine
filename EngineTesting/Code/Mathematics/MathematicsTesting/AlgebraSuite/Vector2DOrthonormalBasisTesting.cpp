///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 14:41)

#include "Vector2DOrthonormalBasisTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2OrthonormalBasisDetail.h"
#include "Mathematics/Algebra/Vector2Tools.h"

#include <random>

Mathematics::Vector2OrthonormalBasisTesting::Vector2OrthonormalBasisTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Vector2OrthonormalBasisTesting)

void Mathematics::Vector2OrthonormalBasisTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Vector2OrthonormalBasisTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OrthonormalBasisTest);
}

void Mathematics::Vector2OrthonormalBasisTesting::OrthonormalBasisTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };

    std::uniform_real_distribution<double> randomDistribution0{ -10.0, 10.0 };
    std::uniform_real_distribution<float> randomDistribution1{ -10.0f, 10.0f };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Vector2 vector0(randomDistribution0(generator), randomDistribution0(generator));

        Vector2F vector1(randomDistribution1(generator), randomDistribution1(generator));

        const Vector2OrthonormalBasisD firstOrthonormalBasis(vector0);

        vector0.Normalize();

        ASSERT_TRUE(Vector2ToolsD::Approximate(vector0, firstOrthonormalBasis.GetUVector(), 1e-10));

        ASSERT_TRUE(Vector2ToolsD::Approximate(Vector2(vector0[1], -vector0[0]), firstOrthonormalBasis.GetVVector(), 1e-10));

        const Vector2OrthonormalBasisF secondOrthonormalBasis(vector1);

        vector1.Normalize();

        ASSERT_TRUE(Vector2ToolsF::Approximate(vector1, secondOrthonormalBasis.GetUVector(), 1e-8f));

        ASSERT_TRUE(Vector2ToolsF::Approximate(Vector2(vector1[1], -vector1[0]), secondOrthonormalBasis.GetVVector(), 1e-8f));
    }
}
