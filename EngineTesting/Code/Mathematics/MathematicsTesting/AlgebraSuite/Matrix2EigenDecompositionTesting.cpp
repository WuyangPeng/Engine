///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 21:47)

#include "Matrix2EigenDecompositionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix2Detail.h"
#include "Mathematics/Algebra/Matrix2EigenDecompositionDetail.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;

namespace Mathematics
{
    template class Matrix2EigenDecomposition<float>;
    template class Matrix2EigenDecomposition<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Matrix2EigenDecompositionTesting)

void Mathematics::Matrix2EigenDecompositionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EigenDecompositionTest);
}

void Mathematics::Matrix2EigenDecompositionTesting::EigenDecompositionTest()
{
    default_random_engine generator{};
    const uniform_real<double> randomDistribution{ -10.0, 10.0 };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Matrix2D firstMatrix(randomDistribution(generator), randomDistribution(generator), 0.0, randomDistribution(generator));

        firstMatrix(1, 0) = firstMatrix(0, 1);

        const auto eigenDecomposition = firstMatrix.EigenDecomposition(1e-10);

        const auto rotation = eigenDecomposition.GetRotation();
        const auto diagonal = eigenDecomposition.GetDiagonal();

        const auto secondMatrix = rotation * diagonal * rotation.Transpose();

        ASSERT_TRUE(Approximate(firstMatrix, secondMatrix, 1e-10));
    }
}
