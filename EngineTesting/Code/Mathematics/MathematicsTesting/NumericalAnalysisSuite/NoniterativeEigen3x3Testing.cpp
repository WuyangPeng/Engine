///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:04)

#include "NoniterativeEigen3x3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/NumericalAnalysis/NoniterativeEigen3x3Detail.h"

#include <random>

namespace Mathematics
{
    template class NoniterativeEigen3x3<float>;
    template class NoniterativeEigen3x3<double>;
}

Mathematics::NoniterativeEigen3x3Testing::NoniterativeEigen3x3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, NoniterativeEigen3x3Testing)

void Mathematics::NoniterativeEigen3x3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::NoniterativeEigen3x3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EigenTest);
}

void Mathematics::NoniterativeEigen3x3Testing::EigenTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution(-1.0e2, 1.0e2);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Matrix3D matrix0(randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         0.0,
                         randomDistribution(generator),
                         randomDistribution(generator),
                         0.0,
                         0.0,
                         randomDistribution(generator));

        matrix0(1, 0) = matrix0(0, 1);
        matrix0(2, 0) = matrix0(0, 2);
        matrix0(2, 1) = matrix0(1, 2);

        const NoniterativeEigen3x3D eigenDecomposition(matrix0);

        const Matrix3D rotation(eigenDecomposition.GetEigenvector(0),
                                eigenDecomposition.GetEigenvector(1),
                                eigenDecomposition.GetEigenvector(2),
                                MatrixMajorFlags::Column);
        const Matrix3D diagonal(eigenDecomposition.GetEigenvalue(0),
                                eigenDecomposition.GetEigenvalue(1),
                                eigenDecomposition.GetEigenvalue(2));

        const auto matrix1 = rotation * diagonal * rotation.Transpose();

        ASSERT_TRUE(Approximate(matrix0, matrix1, 1e-8));
    }
}
