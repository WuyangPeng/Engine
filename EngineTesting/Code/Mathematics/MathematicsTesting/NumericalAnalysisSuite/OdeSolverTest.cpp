// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 16:18)

#include "OdeSolverTest.h"
#include "OdeSolverTesting.h"
#include "Mathematics/NumericalAnalysis/OdeSolverDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26432)
#include SYSTEM_WARNING_DISABLE(26481)
Mathematics::OdeSolverTest
	::OdeSolverTest(int dimension, double step,Function function, const OdeSolverTesting* userData)
	:ParentType{ dimension, step, function, userData }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

Mathematics::OdeSolverTest
	::~OdeSolverTest() 
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}
 
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, OdeSolverTest) 

void Mathematics::OdeSolverTest
	::Update(double tIn, const RealVector& xIn, double& tOut, double* xOut)
{
	CalculateFunctionValue(tIn, xIn);

	tOut = tIn;

	int dimension0 = GetDimension();

	for (int i = 0; i < dimension0; i++)
	{
		xOut[i] = xIn[i];	
	}
}

const Mathematics::OdeSolverTest::RealVector Mathematics::OdeSolverTest
	::OdeSolverTestFunction(double tIn, const RealVector& xIn,const OdeSolverTesting* odeSolverTest) 
{
	int dimension =  odeSolverTest->GetDimension();

	RealVector out(dimension);

	for (int i = 0; i < dimension; i++)
	{
		out[i] = tIn * xIn[i] + dimension;
	}

	return out;
}

