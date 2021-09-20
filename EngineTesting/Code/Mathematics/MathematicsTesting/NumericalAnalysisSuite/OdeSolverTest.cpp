// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/27 16:18)

#include "OdeSolverTest.h"
#include "OdeSolverTesting.h"
#include "Mathematics/NumericalAnalysis/OdeSolverDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

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

	int dimension = GetDimension();

	for (int i = 0; i < dimension; i++)
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

