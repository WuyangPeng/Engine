///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 16:08)

#include "QDUDecompositionValueTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/NumericalAnalysis/QDUDecompositionValueDetail.h"

#include <random>

namespace Mathematics
{
    template class QDUDecompositionValue<float>;
    template class QDUDecompositionValue<double>;
}

Mathematics::QDUDecompositionValueTesting::QDUDecompositionValueTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, QDUDecompositionValueTesting)

void Mathematics::QDUDecompositionValueTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::QDUDecompositionValueTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(QDUDecompositionValueTest);
}

void Mathematics::QDUDecompositionValueTesting::QDUDecompositionValueTest()
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

        const QDUDecompositionValueD qDUDecompositionValue(matrix);

        const Matrix3D orthogonalMatrix = qDUDecompositionValue.GeOrthogonalMatrix();
        const Matrix3D diagonalMatrix = qDUDecompositionValue.GetDiagonalMatrix();
        const Matrix3D upperTriangularMatrix = qDUDecompositionValue.GetUpperTriangularMatrix();

        Matrix3D result = orthogonalMatrix * diagonalMatrix;
        result *= upperTriangularMatrix;

        using VariableMatrixdApproximate = bool (*)(const Matrix3D& lhs, const Matrix3D& rhs, const double epsilon);

        VariableMatrixdApproximate function = Approximate<double>;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, matrix, result, 1e-5);
    }
}
