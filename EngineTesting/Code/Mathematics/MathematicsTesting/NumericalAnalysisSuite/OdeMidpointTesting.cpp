// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 16:15)

#include "OdeMidpointTesting.h"
#include "Mathematics/NumericalAnalysis/OdeMidpointDetail.h"
#include "Mathematics/NumericalAnalysis/OdeSolverDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

using std::vector;
using std::ostream;

 

Mathematics::OdeMidpointTesting
	::OdeMidpointTesting(const OStreamShared& osPtr) 
	:ParentType{ osPtr }, m_Dimension{ 10 }
{	
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}                                 

 
 
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, OdeMidpointTesting) 
void Mathematics::OdeMidpointTesting ::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::OdeMidpointTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(SolverTest);
}

void Mathematics::OdeMidpointTesting
	::SolverTest()
{
// 	OdeMidpoint<double,OdeMidpointTesting> odeMidpointTest(m_Dimension, 5,OdeMidpointTesting::OdeMidpointFunction, nullptr);
// 
// 	ASSERT_EQUAL(odeMidpointTest.GetDimension(),m_Dimension);
// 
// 	ASSERT_EQUAL(odeMidpointTest.GetStepSize(), 5);
// 	ASSERT_EQUAL_NULL_PTR(odeMidpointTest.GetUserData());
// 
// 	odeMidpointTest.SetStepSize(6);
// 	ASSERT_EQUAL(odeMidpointTest.GetStepSize(), 6);
// 
// 	odeMidpointTest.SetUserData(this);
// 	ASSERT_EQUAL(odeMidpointTest.GetUserData(), this);
// 
// 	double tIn = 100;
// 
// 	vector<double> xIn;
// 
// 	for (int i = 0; i < m_Dimension; ++i)
// 	{
// 		xIn.push_back(i);
// 	}
// 
// 	double tOut = 0;
// 
// 	vector<double> xOut(m_Dimension);
// 
// 	odeMidpointTest.Update(tIn, xIn, tOut, &xOut[0]);
// 
// 	vector<double> testXOut(m_Dimension);
// 	
// 
// 	vector<double> functionValue = OdeMidpointFunction(tIn, xIn, this);
// 	 
// 	int dimension = GetDimension();
// 
// 	for (int i = 0; i < dimension; ++i)
// 	{
// 		testXOut[i] = xIn[i] + functionValue[i] * odeMidpointTest.GetStepSize() / 2;
// 	}
// 
// 	double halfT = tIn + odeMidpointTest.GetStepSize() / 2;
// 
// 	functionValue = OdeMidpointFunction(halfT, testXOut, this);
// 
// 	for (int i = 0; i < dimension; ++i)
// 	{
// 		testXOut[i] = xIn[i] + functionValue[i] * odeMidpointTest.GetStepSize();
// 	}
// 
// 	double testTOut = tIn + odeMidpointTest.GetStepSize();
// 
// 	ASSERT_APPROXIMATE(testTOut,tOut,1e-10);
// 
// 	for(int i = 0;i < m_Dimension;++i)
// 	{
// 		ASSERT_APPROXIMATE(testXOut[i],xOut[i],1e-10);
// 	}
}

const vector<double> Mathematics::OdeMidpointTesting
	::OdeMidpointFunction( double tIn, const vector<double>& xIn,const OdeMidpointTesting* odeEulerTesting)
{
	int dimension =  odeEulerTesting->GetDimension();

	vector<double> out(dimension);

	for (int i = 0; i < dimension; i++)
	{
		out[i] = tIn * xIn[i] + dimension;
	}

	return out;
}

int Mathematics::OdeMidpointTesting
	::GetDimension() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Dimension;
}





