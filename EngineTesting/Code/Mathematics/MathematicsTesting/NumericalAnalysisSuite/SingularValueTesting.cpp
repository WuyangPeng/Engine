///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/03 16:09)

#include "SingularValueTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/NumericalAnalysis/SingularValueDetail.h"

#include <random>

using std::default_random_engine;
using std::swap;
using std::uniform_int;
using std::uniform_real;

namespace Mathematics
{
    template class SingularValue<float>;
    template class SingularValue<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, SingularValueTesting)

void Mathematics::SingularValueTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SingularValueTest);
}

void Mathematics::SingularValueTesting::SingularValueTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-1.0e5, 1.0e5);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Matrix3D matrix;

        for (int m = 0; m < 3; ++m)
        {
            for (int j = 0; j < 3; ++j)
            {
                matrix(m, j) = firstRandomDistribution(generator);
            }
        }

        const SingularValueD singularValueDecomposition(matrix);

        const Matrix3D leftMatrix = singularValueDecomposition.GetLeftMatrix();
        const Matrix3D diagonalMatrix = singularValueDecomposition.GetDiagonalMatrix();
        const Matrix3D rightTransposeMatrix = singularValueDecomposition.GetRightTransposeMatrix();

        Matrix3D result = leftMatrix * diagonalMatrix;
        result *= rightTransposeMatrix;

        using VariableMatrixdApproximate = bool (*)(const Matrix3D& lhs, const Matrix3D& rhs, const double epsilon);

        VariableMatrixdApproximate function = Approximate<double>;

        ASSERT_APPROXIMATE_USE_FUNCTION(function, matrix, result, 1e-6);
    }
}
