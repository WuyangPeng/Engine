// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.2 (2019/08/27 15:15)

#include "EquationTesting.h"
#include "Mathematics/NumericalAnalysis/Equation.h"
#include "Mathematics/NumericalAnalysis/EquationResultConstIteratorDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_int;
using std::uniform_real;
using std::default_random_engine;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, EquationTesting) 
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
void Mathematics::EquationTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(OnceTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SecondaryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ThriceTest);
	ASSERT_NOT_THROW_EXCEPTION_0(QuarticTest);
}

void Mathematics::EquationTesting
	::OnceTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-1.0e10, 1.0e10); 
	
	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Equation firstEquation(firstRandomDistribution(generator), firstRandomDistribution(generator));

		ASSERT_TRUE(firstEquation.IsRealResult());
		ASSERT_EQUAL(firstEquation.GetRealResultCount(),1);
		ASSERT_EQUAL(firstEquation.GetImaginaryResultCount(),0);

		ASSERT_EQUAL(firstEquation.GetImaginaryBegin(), firstEquation.GetImaginaryEnd());

		Equation::RealConstIterator iter = firstEquation.GetRealBegin();

		double result = *iter;

		ASSERT_EQUAL(++iter,firstEquation.GetRealEnd());

		ASSERT_APPROXIMATE(firstEquation.Substitution(result),0.0,1e-6);
	}
}

void Mathematics::EquationTesting
	::SecondaryTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-1.0e8, 1.0e8); 
	
	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Equation firstEquation(firstRandomDistribution(generator),
			                   firstRandomDistribution(generator),
							   firstRandomDistribution(generator));

		if(firstEquation.IsRealResult())
		{
			ASSERT_TRUE(firstEquation.GetRealResultCount() == 1 || firstEquation.GetRealResultCount() == 2);

			ASSERT_EQUAL(firstEquation.GetImaginaryBegin(), firstEquation.GetImaginaryEnd());

			for (Equation::RealConstIterator iter = firstEquation.GetRealBegin(),end = firstEquation.GetRealEnd();iter != end;++iter)
			{
				double result = *iter;				

				ASSERT_APPROXIMATE(firstEquation.Substitution(result),0.0,1e-5);
			}
		}
		else
		{
			ASSERT_EQUAL(firstEquation.GetImaginaryResultCount(),2);
			ASSERT_EQUAL(firstEquation.GetRealBegin(),firstEquation.GetRealEnd());

			for (Equation::ImaginaryConstIterator iter = firstEquation.GetImaginaryBegin(),
				 end = firstEquation.GetImaginaryEnd();iter != end;++iter)
			{
				Equation::Imaginary result = *iter;	
				Equation::Imaginary substitution = firstEquation.Substitution(result);

				ASSERT_APPROXIMATE(substitution.real(),0.0,1e-6);
				ASSERT_APPROXIMATE(substitution.imag(),0.0,1e-6);
			}
		}		
	}
}

void Mathematics::EquationTesting
	::ThriceTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-1.0e7, 1.0e7); 

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Equation firstEquation(firstRandomDistribution(generator),
			                   firstRandomDistribution(generator),
							   firstRandomDistribution(generator),
							   firstRandomDistribution(generator));

		ASSERT_TRUE(firstEquation.IsRealResult());

		ASSERT_TRUE(firstEquation.GetRealResultCount() == 1 ||
			        firstEquation.GetRealResultCount() == 2 ||
			        firstEquation.GetRealResultCount() == 3);

		if (firstEquation.GetRealResultCount() == 3)
		{
			ASSERT_EQUAL(firstEquation.GetImaginaryResultCount(), 0);
			ASSERT_EQUAL(firstEquation.GetImaginaryBegin(),
				         firstEquation.GetImaginaryEnd());

			for (Equation::RealConstIterator iter = firstEquation.GetRealBegin(),
				 end = firstEquation.GetRealEnd(); iter != end; ++iter)
			{
				double result = *iter;

				ASSERT_APPROXIMATE(firstEquation.Substitution(result), 0.0, 1e-5);
			}
		}
		else if (firstEquation.GetRealResultCount() == 2)
		{
			ASSERT_EQUAL(firstEquation.GetImaginaryResultCount(), 0);
			ASSERT_EQUAL(firstEquation.GetImaginaryBegin(),firstEquation.GetImaginaryEnd());

			for (Equation::RealConstIterator iter = firstEquation.GetRealBegin(),
				 end = firstEquation.GetRealEnd(); iter != end; ++iter)
			{
				double result = *iter;

				ASSERT_APPROXIMATE(firstEquation.Substitution(result), 0.0, 1e-6);
			}
		}
		else
		{
			for (Equation::RealConstIterator iter = firstEquation.GetRealBegin(),
				 end = firstEquation.GetRealEnd(); iter != end; ++iter)
			{
				double result = *iter;

				ASSERT_APPROXIMATE(firstEquation.Substitution(result), 0.0, 1e-5);
			}

			ASSERT_EQUAL(firstEquation.GetImaginaryResultCount(), 2);

			for (Equation::ImaginaryConstIterator iter = firstEquation.GetImaginaryBegin(),
				 end = firstEquation.GetImaginaryEnd(); iter != end; ++iter)
			{
				Equation::Imaginary result = *iter;
				Equation::Imaginary substitution = firstEquation.Substitution(result);

				ASSERT_APPROXIMATE(substitution.real(), 0.0, 1e-6);
				ASSERT_APPROXIMATE(substitution.imag(), 0.0, 1e-6);
			}
		}
	}

	// 构造判别式为零
	double constant = 1.0;
	double once = 3.0;
	double secondary = 3.0001;
	double thrice = 1.0;

	Equation firstEquation(constant, once, secondary, thrice);

	ASSERT_TRUE(firstEquation.IsRealResult());

	ASSERT_EQUAL(firstEquation.GetImaginaryResultCount(), 0);
	ASSERT_EQUAL(firstEquation.GetImaginaryBegin(),firstEquation.GetImaginaryEnd());
	
	for (Equation::RealConstIterator iter = firstEquation.GetRealBegin(),
		 end = firstEquation.GetRealEnd(); iter != end; ++iter)
	{
		double result = *iter;
		
		ASSERT_APPROXIMATE(firstEquation.Substitution(result), 0.0, 1e-5);
	}
}

void Mathematics::EquationTesting
	::QuarticTest() 
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-1.0e6, 1.0e6); 
	
	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Equation firstEquation(firstRandomDistribution(generator),
			                   firstRandomDistribution(generator),
							   firstRandomDistribution(generator),
							   firstRandomDistribution(generator),
							   firstRandomDistribution(generator));

		for (Equation::RealConstIterator iter = firstEquation.GetRealBegin(),
			 end = firstEquation.GetRealEnd();iter != end;++iter)
		{
			double result = *iter;				
			
			ASSERT_APPROXIMATE(firstEquation.Substitution(result),0.0,1e-2);
		}

		for (Equation::ImaginaryConstIterator iter = firstEquation.GetImaginaryBegin(),
			 end = firstEquation.GetImaginaryEnd(); iter != end; ++iter)
		{
			Equation::Imaginary result = *iter;
			Equation::Imaginary substitution = firstEquation.Substitution(result);

			ASSERT_APPROXIMATE(substitution.real(), 0.0, 1e-6);
			ASSERT_APPROXIMATE(substitution.imag(), 0.0, 1e-6);
		}
	}
}
