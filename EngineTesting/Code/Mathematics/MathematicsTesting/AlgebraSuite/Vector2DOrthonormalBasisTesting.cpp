///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 22:58)

#include "Vector2DOrthonormalBasisTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2OrthonormalBasisDetail.h"
#include "Mathematics/Algebra/Vector2Tools.h"
#include <random>
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::default_random_engine;
using std::uniform_real;

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
    default_random_engine generator{};

    const uniform_real<double> firstRandomDistribution{ -10.0, 10.0 };
    const uniform_real<float> secondRandomDistribution{ -10.0f, 10.0f };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Vector2 firstVector(firstRandomDistribution(generator), firstRandomDistribution(generator));

        Vector2F secondVector(secondRandomDistribution(generator), secondRandomDistribution(generator));

        const Vector2OrthonormalBasisD firstOrthonormalBasis(firstVector);

        firstVector.Normalize();

        ASSERT_TRUE(Vector2ToolsD::Approximate(firstVector, firstOrthonormalBasis.GetUVector(), 1e-10));

        ASSERT_TRUE(Vector2ToolsD::Approximate(Vector2(firstVector[1], -firstVector[0]), firstOrthonormalBasis.GetVVector(), 1e-10));

        const Vector2OrthonormalBasisF secondOrthonormalBasis(secondVector);

        secondVector.Normalize();

        ASSERT_TRUE(Vector2ToolsF::Approximate(secondVector, secondOrthonormalBasis.GetUVector(), 1e-8f));

        ASSERT_TRUE(Vector2ToolsF::Approximate(Vector2(secondVector[1], -secondVector[0]), secondOrthonormalBasis.GetVVector(), 1e-8f));
    }
}
