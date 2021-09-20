// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 15:31)

#include "LinearSystemInverseTesting.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::vector;
using std::uniform_int;
using std::uniform_real;
using std::default_random_engine;

 

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, LinearSystemInverseTesting) 

void Mathematics::LinearSystemInverseTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(InverseTest);	
	ASSERT_NOT_THROW_EXCEPTION_0(SolveTest);
}
  
void Mathematics::LinearSystemInverseTesting
	::InverseTest()
{
	 
}

void Mathematics::LinearSystemInverseTesting
	::SolveTest()
{
	 
}

