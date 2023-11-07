///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 13:11)

#include "AVectorOrthonormalBasisTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/AVectorOrthonormalBasisDetail.h"

#include <random>

namespace Mathematics
{
    template class AVectorOrthonormalBasis<float>;
    template class AVectorOrthonormalBasis<double>;
}

Mathematics::AVectorOrthonormalBasisTesting::AVectorOrthonormalBasisTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, AVectorOrthonormalBasisTesting)

void Mathematics::AVectorOrthonormalBasisTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::AVectorOrthonormalBasisTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OrthonormalBasisTest);
}

void Mathematics::AVectorOrthonormalBasisTesting::OrthonormalBasisTest()
{
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0{ -10.0, 10.0 };
    std::uniform_real<float> randomDistribution1{ -10.0f, 10.0f };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        AVectorD vector0{ randomDistribution0(randomEngine), randomDistribution0(randomEngine), randomDistribution0(randomEngine) };

        AVectorF vector1{ randomDistribution1(randomEngine), randomDistribution1(randomEngine), randomDistribution1(randomEngine) };

        const AVectorOrthonormalBasisD orthonormalBasis0{ vector0, false };

        vector0.Normalize();

        ASSERT_TRUE(Approximate(vector0, orthonormalBasis0.GetWVector(), 1e-10));

        const AVectorOrthonormalBasisF orthonormalBasis1{ vector1, false };

        vector1.Normalize();

        ASSERT_TRUE(Approximate(vector1, orthonormalBasis1.GetWVector(), 1e-8f));
    }
}
