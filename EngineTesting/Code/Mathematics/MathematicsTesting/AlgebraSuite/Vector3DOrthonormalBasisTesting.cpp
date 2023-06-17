///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 14:43)

#include "Vector3DOrthonormalBasisTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3OrthonormalBasisDetail.h"
#include "Mathematics/Algebra/Vector3Tools.h"

#include <random>

namespace Mathematics
{
    template class Vector3OrthonormalBasis<float>;
    template class Vector3OrthonormalBasis<double>;
}

Mathematics::Vector3OrthonormalBasisTesting::Vector3OrthonormalBasisTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Vector3OrthonormalBasisTesting)

void Mathematics::Vector3OrthonormalBasisTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Vector3OrthonormalBasisTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OrthonormalBasisTest);
}

void Mathematics::Vector3OrthonormalBasisTesting::OrthonormalBasisTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };

    const std::uniform_real<double> randomDistribution0{ -10.0, 10.0 };
    const std::uniform_real<float> randomDistribution1{ -10.0f, 10.0f };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Vector3D vector0(randomDistribution0(generator),
                         randomDistribution0(generator),
                         randomDistribution0(generator));

        Vector3F vector1(randomDistribution1(generator),
                         randomDistribution1(generator),
                         randomDistribution1(generator));

        const Vector3OrthonormalBasisD firstOrthonormalBasis(vector0, false);

        vector0.Normalize();

        ASSERT_TRUE(Vector3ToolsD::Approximate(vector0, firstOrthonormalBasis.GetWVector(), 1e-10));

        const Vector3OrthonormalBasisF secondOrthonormalBasis(vector1, false);

        vector1.Normalize();

        ASSERT_TRUE(Vector3ToolsF::Approximate(vector1, secondOrthonormalBasis.GetWVector(), 1e-8f));
    }
}
