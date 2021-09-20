// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 16:14)

#include "OdeEulerTesting.h"
#include "Mathematics/NumericalAnalysis/OdeEulerDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

using std::vector;
using std::ostream;

namespace Mathematics
{
	template class OdeEuler<float,OdeEulerTesting>;
	template class OdeEuler<double,OdeEulerTesting>;	
}

Mathematics::OdeEulerTesting
	::OdeEulerTesting(const OStreamShared& osPtr) 
	:ParentType{ osPtr }, m_Dimension{ 10 }
{	
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}                                 

 
 
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, OdeEulerTesting) 

void Mathematics::OdeEulerTesting ::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::OdeEulerTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(SolverTest);
}

void Mathematics::OdeEulerTesting
	::SolverTest()
{
	OdeEuler<double,OdeEulerTesting> odeSolverTest(m_Dimension, 5,OdeEulerTesting::OdeEulerFunction, nullptr);

	ASSERT_EQUAL(odeSolverTest.GetDimension(),m_Dimension);

	ASSERT_EQUAL(odeSolverTest.GetStepSize(), 5);
	ASSERT_EQUAL_NULL_PTR(odeSolverTest.GetUserData());

	odeSolverTest.SetStepSize(6);
	ASSERT_EQUAL(odeSolverTest.GetStepSize(), 6);

	odeSolverTest.SetUserData(this);
	ASSERT_EQUAL(odeSolverTest.GetUserData(), this);
// 
// 	double tIn = 100;
// 
// 	vector<double> xIn;
// 
// 	for (int i = 0; i < m_Dimension; ++i)
// 	{
// 		xIn.push_back(i);
// 	}

// 	double tOut = 0;
// 
// 	vector<double> xOut(m_Dimension);

// 	odeSolverTest.Update(tIn, xIn, tOut, &xOut[0]);
// 
// 	vector<double> testXOut(m_Dimension);
// 	
// 
// 	vector<double> functionValue = OdeEulerFunction(tIn, xIn, this);
// 	 
// 	int dimension = GetDimension();
// 
// 	for (int i = 0; i < dimension; ++i)
// 	{
// 		testXOut[i] = xIn[i] + functionValue[i] * odeSolverTest.GetStepSize();
// 	}
// 
// 	double testTOut = tIn + odeSolverTest.GetStepSize();
// 
// 	ASSERT_APPROXIMATE(testTOut,tOut,1e-10);
// 
// 	for(int i = 0;i < m_Dimension;++i)
// 	{
// 		ASSERT_APPROXIMATE(testXOut[i],xOut[i],1e-10);
// 	}
}

const vector<double> Mathematics::OdeEulerTesting
	::OdeEulerFunction( double tIn, const vector<double>& xIn,const OdeEulerTesting* odeEulerTesting )
{
	int dimension =  odeEulerTesting->GetDimension();

	vector<double> out(dimension);

	for (int i = 0; i < dimension; i++)
	{
		out[i] = tIn * xIn[i] + dimension;
	}

	return out;
}

int Mathematics::OdeEulerTesting
	::GetDimension() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Dimension;
}


