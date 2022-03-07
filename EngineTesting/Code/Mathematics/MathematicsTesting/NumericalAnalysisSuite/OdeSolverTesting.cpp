// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 16:18)

#include "OdeSolverTesting.h"
#include "OdeSolverTest.h"
#include "Mathematics/NumericalAnalysis/OdeSolverDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

using std::vector;

namespace Mathematics
{
	template class OdeSolver<float,OdeSolverTesting>;
	template class OdeSolver<double,OdeSolverTesting>;	
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26429)
Mathematics::OdeSolverTesting
	::OdeSolverTesting(const OStreamShared& osPtr) 
	:ParentType{ osPtr }, m_Dimension{ 10 }
{	
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}                                 

 
 
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, OdeSolverTesting)
 
void Mathematics::OdeSolverTesting ::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::OdeSolverTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(SolverTest);
}

void Mathematics::OdeSolverTesting
	::SolverTest()
{
// 	OdeSolverTest odeSolverTest(m_Dimension, 5, OdeSolverTest::OdeSolverTestFunction, nullptr);
// 
// 	ASSERT_EQUAL(odeSolverTest.GetDimension(),m_Dimension);
// 
// 	ASSERT_EQUAL(odeSolverTest.GetStepSize(), 5);
// 	ASSERT_EQUAL_NULL_PTR(odeSolverTest.GetUserData());
// 
// 	odeSolverTest.SetStepSize(6);
// 	ASSERT_EQUAL(odeSolverTest.GetStepSize(), 6);
// 
// 	odeSolverTest.SetUserData(this);
// 	ASSERT_EQUAL(odeSolverTest.GetUserData(), this);
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
// 	odeSolverTest.Update(tIn, xIn, tOut, &xOut[0]);
// 
// 	ASSERT_APPROXIMATE(tIn,tOut,1e-10);
// 
// 	for(int i = 0;i < m_Dimension;++i)
// 	{
// 		ASSERT_APPROXIMATE(xIn[i],xOut[i],1e-10);
// 	}
}

int Mathematics::OdeSolverTesting
	::GetDimension() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Dimension;
}

