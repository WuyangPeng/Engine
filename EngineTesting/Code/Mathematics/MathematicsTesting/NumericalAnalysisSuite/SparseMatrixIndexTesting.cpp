// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 10:02)

#include "SparseMatrixIndexTesting.h"
#include "Mathematics/NumericalAnalysis/SparseMatrixIndex.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, SparseMatrixIndexTesting) 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
void Mathematics::SparseMatrixIndexTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
}

void Mathematics::SparseMatrixIndexTesting
	::OperatorTest()
{
	SparseMatrixIndex firstIndex(5,6);
	SparseMatrixIndex secondIndex(2, 6);
	SparseMatrixIndex thirdIndex(7, 6);
	SparseMatrixIndex fourthIndex(5, 4);

	ASSERT_FALSE(firstIndex < firstIndex);
	ASSERT_FALSE(secondIndex < secondIndex);
	ASSERT_FALSE(thirdIndex < thirdIndex);
	ASSERT_FALSE(fourthIndex < fourthIndex);

	ASSERT_TRUE(secondIndex < firstIndex);
	ASSERT_TRUE(firstIndex < thirdIndex);
	ASSERT_TRUE(fourthIndex < firstIndex);
}



