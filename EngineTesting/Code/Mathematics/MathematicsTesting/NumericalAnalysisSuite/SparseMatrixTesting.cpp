///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/03 16:25)

#include "SparseMatrixTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/SparseMatrixDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
namespace Mathematics
{
    template class SparseMatrix<float>;
    template class SparseMatrix<double>;
}

Mathematics::SparseMatrixTesting::SparseMatrixTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, SparseMatrixTesting)

void Mathematics::SparseMatrixTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::SparseMatrixTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SparseMatrixTest);
}

void Mathematics::SparseMatrixTesting::SparseMatrixTest()
{
    SparseMatrixD firstSparseMatrix(12, 10);

    ASSERT_EQUAL(firstSparseMatrix.GetRowsNumber(), 12);
    ASSERT_EQUAL(firstSparseMatrix.GetColumnsNumber(), 10);

    ASSERT_APPROXIMATE(firstSparseMatrix(0, 0), 0.0, 1e-10);

    firstSparseMatrix(1, 2) = 3.0;

    ASSERT_APPROXIMATE(firstSparseMatrix(1, 2), 3.0, 1e-10);
}
