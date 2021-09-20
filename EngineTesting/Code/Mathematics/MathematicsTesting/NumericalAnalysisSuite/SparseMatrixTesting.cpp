// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 10:02)

#include "SparseMatrixTesting.h"
#include "Mathematics/NumericalAnalysis/SparseMatrixDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

namespace Mathematics
{
	template class SparseMatrix<float>;
	template class SparseMatrix<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, SparseMatrixTesting) 


void Mathematics::SparseMatrixTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(SparseMatrixTest);
}

void Mathematics::SparseMatrixTesting
	::SparseMatrixTest() 
{
	DoubleSparseMatrix firstSparseMatrix(12, 10);

	ASSERT_EQUAL(firstSparseMatrix.GetRowsNumber(), 12);
	ASSERT_EQUAL(firstSparseMatrix.GetColumnsNumber(), 10);

	ASSERT_APPROXIMATE(firstSparseMatrix(0, 0), 0.0, 1e-10);

	firstSparseMatrix(1, 2) = 3.0;

	ASSERT_APPROXIMATE(firstSparseMatrix(1, 2), 3.0, 1e-10);
}


