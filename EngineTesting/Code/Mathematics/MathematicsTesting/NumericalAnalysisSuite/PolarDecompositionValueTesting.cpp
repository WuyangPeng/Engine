///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:06)

#include "PolarDecompositionValueTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/NumericalAnalysis/PolarDecompositionValueDetail.h"

#include <random>

namespace Mathematics
{
    template class PolarDecompositionValue<float>;
    template class PolarDecompositionValue<double>;
}

Mathematics::PolarDecompositionValueTesting::PolarDecompositionValueTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, PolarDecompositionValueTesting)

void Mathematics::PolarDecompositionValueTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::PolarDecompositionValueTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PolarDecompositionValueTest);
}

void Mathematics::PolarDecompositionValueTesting::PolarDecompositionValueTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0(-1.0e5, 1.0e5);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Matrix3D matrix;

        for (int m = 0; m < 3; ++m)
        {
            for (int j = 0; j < 3; ++j)
            {
                matrix(m, j) = randomDistribution0(generator);
            }
        }

        const PolarDecompositionValueD polarDecompositionValue(matrix);

        const Matrix3D orthogonalMatrix = polarDecompositionValue.GeOrthogonalMatrix();
        const Matrix3D symmetryMatrix = polarDecompositionValue.GetSymmetryMatrix();

        const Matrix3D result = orthogonalMatrix * symmetryMatrix;

        typedef bool (*VariableMatrixdApproximate)(const Matrix3D& lhs, const Matrix3D& rhs, const double epsilon);

        VariableMatrixdApproximate function = Approximate<double>;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, matrix, result, 1e-6);
    }
}
