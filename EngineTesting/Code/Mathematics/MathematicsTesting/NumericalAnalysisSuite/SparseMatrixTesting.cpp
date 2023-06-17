///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:09)

#include "SparseMatrixTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/NumericalAnalysis/SparseMatrixDetail.h"

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
