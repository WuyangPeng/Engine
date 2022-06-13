///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/03 16:25)

#include "SparseMatrixTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/SparseMatrixDetail.h"

namespace Mathematics
{
    template class SparseMatrix<float>;
    template class SparseMatrix<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, SparseMatrixTesting)

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
