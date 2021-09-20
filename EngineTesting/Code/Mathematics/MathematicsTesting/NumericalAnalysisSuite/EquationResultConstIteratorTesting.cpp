// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 15:14)

#include "EquationResultConstIteratorTesting.h"
#include "Mathematics/NumericalAnalysis/EquationResultConstIteratorDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <vector>

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, EquationResultConstIteratorTesting) 

void Mathematics::EquationResultConstIteratorTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(DereferenceTest);
}

void Mathematics::EquationResultConstIteratorTesting
	::DereferenceTest()
{
	typedef vector<size_t> IntVector;
	typedef IntVector::const_iterator IntVectorConstIter;

	IntVector firstIntVector;

	for (size_t i = 0; i < 10; ++i)
	{
		firstIntVector.push_back(i);
	}

	EquationResultConstIterator<IntVectorConstIter> iter(firstIntVector.begin());
	EquationResultConstIterator<IntVectorConstIter> end(firstIntVector.end());

	size_t i = 0;
	for (; iter != end; ++iter)
	{
		ASSERT_EQUAL(*iter, i);
		++i;
	}
}


