///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 14:41)

#include "Vector2DOrthonormalizeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector2OrthonormalizeDetail.h"
#include "Mathematics/Algebra/Vector2Tools.h"

#include <random>

namespace Mathematics
{
    template class Vector2Orthonormalize<float>;
    template class Vector2Orthonormalize<double>;
}

Mathematics::Vector2OrthonormalizeTesting::Vector2OrthonormalizeTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Vector2OrthonormalizeTesting)

void Mathematics::Vector2OrthonormalizeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Vector2OrthonormalizeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OrthonormalizeTest);
}

void Mathematics::Vector2OrthonormalizeTesting::OrthonormalizeTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };

    std::uniform_real_distribution<double> randomDistribution0{ -10.0, 10.0 };
    std::uniform_real_distribution<float> randomDistribution1{ -10.0f, 10.0f };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Vector2 vector0(randomDistribution0(generator),
                        randomDistribution0(generator));
        Vector2 vector1(randomDistribution0(generator),
                        randomDistribution0(generator));

        Vector2F vector2(randomDistribution1(generator),
                         randomDistribution1(generator));
        Vector2F vector3(randomDistribution1(generator),
                         randomDistribution1(generator));

        const Vector2OrthonormalizeD firstOrthonormalize(vector0, vector1, 1e-10);

        vector0.Normalize();
        const double dot0 = Vector2ToolsD::DotProduct(vector0, vector1);
        vector1 -= vector0 * dot0;
        vector1.Normalize();

        ASSERT_TRUE(Vector2ToolsD::Approximate(vector0, firstOrthonormalize.GetUVector(), 1e-10));

        ASSERT_TRUE(Vector2ToolsD::Approximate(vector1, firstOrthonormalize.GetVVector(), 1e-10));

        const Vector2OrthonormalizeF secondOrthonormalize(vector2, vector3, 1e-4f);

        vector2.Normalize();
        const float dot1 = Vector2ToolsF::DotProduct(vector2, vector3);
        vector3 -= vector2 * dot1;
        vector3.Normalize();

        ASSERT_TRUE(Vector2ToolsF::Approximate(vector2, secondOrthonormalize.GetUVector(), 1e-8f));

        ASSERT_TRUE(Vector2ToolsF::Approximate(vector3, secondOrthonormalize.GetVVector(), 1e-5f));
    }
}
