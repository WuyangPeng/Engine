///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 13:18)

#include "AVectorOrthonormalizeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/AVectorOrthonormalizeDetail.h"

#include <random>

namespace Mathematics
{
    template class AVectorOrthonormalize<float>;
    template class AVectorOrthonormalize<double>;
}

Mathematics::AVectorOrthonormalizeTesting::AVectorOrthonormalizeTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, AVectorOrthonormalizeTesting)

void Mathematics::AVectorOrthonormalizeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::AVectorOrthonormalizeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OrthonormalizeTest);
}

void Mathematics::AVectorOrthonormalizeTesting::OrthonormalizeTest()
{
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0{ -10.0, 10.0 };
    std::uniform_real<float> randomDistribution1{ -10.0f, 10.0f };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        AVectorD vector0{ randomDistribution0(randomEngine), randomDistribution0(randomEngine), randomDistribution0(randomEngine) };
        AVectorD vector1{ randomDistribution0(randomEngine), randomDistribution0(randomEngine), randomDistribution0(randomEngine) };
        AVectorD vector2{ randomDistribution0(randomEngine), randomDistribution0(randomEngine), randomDistribution0(randomEngine) };

        AVectorF vector3{ randomDistribution1(randomEngine), randomDistribution1(randomEngine), randomDistribution1(randomEngine) };
        AVectorF vector4{ randomDistribution1(randomEngine), randomDistribution1(randomEngine), randomDistribution1(randomEngine) };
        AVectorF vector5{ randomDistribution1(randomEngine), randomDistribution1(randomEngine), randomDistribution1(randomEngine) };

        const AVectorOrthonormalizeD orthonormalize0{ vector0, vector1, vector2, 1e-10 };

        vector0.Normalize();
        auto dot0 = Dot(vector0, vector1);
        vector1 -= vector0 * dot0;
        vector1.Normalize();
        dot0 = Dot(vector0, vector2);
        vector2 -= vector0 * dot0;
        dot0 = Dot(vector1, vector2);
        vector2 -= vector1 * dot0;
        vector2.Normalize();

        ASSERT_TRUE(Approximate(vector0, orthonormalize0.GetUVector(), 1e-10));

        ASSERT_TRUE(Approximate(vector1, orthonormalize0.GetVVector(), 1e-10));

        ASSERT_TRUE(Approximate(vector2, orthonormalize0.GetWVector(), 1e-10));

        const AVectorOrthonormalizeF orthonormalize1{ vector3, vector4, vector5, 1e-3f };

        vector3.Normalize();
        auto dot1 = Dot(vector3, vector4);
        vector4 -= vector3 * dot1;
        vector4.Normalize();

        dot1 = Dot(vector3, vector5);
        vector5 -= vector3 * dot1;
        dot1 = Dot(vector4, vector5);
        vector5 -= vector4 * dot1;
        vector5.Normalize();

        ASSERT_TRUE(Approximate(vector3, orthonormalize1.GetUVector(), 1e-8f));

        ASSERT_TRUE(Approximate(vector4, orthonormalize1.GetVVector(), 1e-6f));

        ASSERT_TRUE(Approximate(vector5, orthonormalize1.GetWVector(), 1e-4f));
    }
}
