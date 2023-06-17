///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 14:30)

#include "Matrix3EigenDecompositionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/Matrix3EigenDecompositionDetail.h"

#include <random>

namespace Mathematics
{
    template class Matrix3EigenDecomposition<float>;
    template class Matrix3EigenDecomposition<double>;
}

Mathematics::Matrix3EigenDecompositionTesting::Matrix3EigenDecompositionTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Matrix3EigenDecompositionTesting)

void Mathematics::Matrix3EigenDecompositionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Matrix3EigenDecompositionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EigenDecompositionTest);
}

void Mathematics::Matrix3EigenDecompositionTesting::EigenDecompositionTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution{ -10.0, 10.0 };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        Matrix3D matrix0{ randomDistribution(generator), randomDistribution(generator), randomDistribution(generator),
                          0.0, randomDistribution(generator), randomDistribution(generator),
                          0.0, 0.0, randomDistribution(generator) };

        matrix0(1, 0) = matrix0(0, 1);
        matrix0(2, 0) = matrix0(0, 2);
        matrix0(2, 1) = matrix0(1, 2);

        const auto eigenDecomposition = matrix0.EigenDecomposition(1e-10);

        const Matrix3D rotation = eigenDecomposition.GetRotation();
        const Matrix3D diagonal = eigenDecomposition.GetDiagonal();

        const Matrix3D matrix1 = rotation * diagonal * rotation.Transpose();

        ASSERT_TRUE(Approximate(matrix0, matrix1, 1e-10));
    }
}
