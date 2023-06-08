///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 22:59)

#include "Vector3DOrthonormalBasisTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3OrthonormalBasisDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3Tools.h"
#include <random>

using std::default_random_engine;
using std::uniform_real;

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
    default_random_engine generator{};

    const uniform_real<double> firstRandomDistribution{ -10.0, 10.0 };
    const uniform_real<float> secondRandomDistribution{ -10.0f, 10.0f };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Vector3D firstVector(firstRandomDistribution(generator),
                             firstRandomDistribution(generator),
                             firstRandomDistribution(generator));

        Vector3F secondVector(secondRandomDistribution(generator),
                              secondRandomDistribution(generator),
                              secondRandomDistribution(generator));

        const Vector3OrthonormalBasisD firstOrthonormalBasis(firstVector, false);

        firstVector.Normalize();

        ASSERT_TRUE(Vector3ToolsD::Approximate(firstVector, firstOrthonormalBasis.GetWVector(), 1e-10));

        const Vector3OrthonormalBasisF secondOrthonormalBasis(secondVector, false);

        secondVector.Normalize();

        ASSERT_TRUE(Vector3ToolsF::Approximate(secondVector, secondOrthonormalBasis.GetWVector(), 1e-8f));
    }
}
