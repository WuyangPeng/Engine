///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 14:25)

#include "Matrix2EigenDecompositionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Matrix2Detail.h"
#include "Mathematics/Algebra/Matrix2EigenDecompositionDetail.h"

#include <random>

namespace Mathematics
{
    template class Matrix2EigenDecomposition<float>;
    template class Matrix2EigenDecomposition<double>;
}

Mathematics::Matrix2EigenDecompositionTesting::Matrix2EigenDecompositionTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Matrix2EigenDecompositionTesting)

void Mathematics::Matrix2EigenDecompositionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Matrix2EigenDecompositionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EigenDecompositionTest);
}

void Mathematics::Matrix2EigenDecompositionTesting::EigenDecompositionTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution{ -10.0, 10.0 };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        Matrix2D matrix0(randomDistribution(generator), randomDistribution(generator), 0.0, randomDistribution(generator));

        matrix0(1, 0) = matrix0(0, 1);

        const auto eigenDecomposition = matrix0.EigenDecomposition(1e-10);

        const auto rotation = eigenDecomposition.GetRotation();
        const auto diagonal = eigenDecomposition.GetDiagonal();

        const auto matrix1 = rotation * diagonal * rotation.Transpose();

        ASSERT_TRUE(Approximate(matrix0, matrix1, 1e-10));
    }
}
